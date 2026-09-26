/**
 * @file main.cpp
 * @brief ORBITGUARD - Closed-Loop Nitinol SMA Solar Array Deployment Firmware
 * @author ORBITGUARD Team (Smart India Hackathon 2025)
 * @license MIT
 *
 * Pin Mapping:
 * - GPIO 25 : IRLZ44N MOSFET Gate (PWM / Digital OUT)
 * - GPIO 27 : DS18B20 1-Wire Thermal Data (with 4.7k pullup)
 * - GPIO 26 : A3144 Hall Effect Sensor OUT (Active LOW)
 * - GPIO 2  : Status Indicator LED (via 330 ohm resistor)
 * - GPIO 21 : INA219 SDA (I2C)
 * - GPIO 22 : INA219 SCL (I2C)
 */

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ==========================================
// PIN DEFINITIONS
// ==========================================
#define PIN_MOSFET_GATE       25   // Controls current to SMA wire
#define PIN_DS18B20_DATA      27   // DS18B20 1-Wire Data pin
#define PIN_HALL_SENSOR       26   // Digital Hall effect sensor (Active LOW on 90° lock)
#define PIN_STATUS_LED        2    // Visual feedback LED
#define PIN_I2C_SDA           21   // INA219 I2C Data
#define PIN_I2C_SCL           22   // INA219 I2C Clock

// ==========================================
// OPERATIONAL & SAFETY THRESHOLDS
// ==========================================
#define MAX_DEPLOY_TIME_MS    8000   // Max heating duration before timeout (8 seconds)
#define COOLING_PERIOD_MS     60000  // Cool-down duration before retry (60 seconds)
#define MAX_RETRIES           3      // Max deployment retry attempts
#define MAX_TEMP_SAFE_C       95.0f  // Overheat cutoff temperature (°C)
#define MIN_CURRENT_MA        200.0f // Wire continuity detection threshold (mA)
#define MAX_CURRENT_MA        3500.0f// Short-circuit protection threshold (mA)

// ==========================================
// STATE MACHINE STATES
// ==========================================
enum DeploymentState {
    STATE_IDLE,
    STATE_PRECHECK,
    STATE_HEATING,
    STATE_COOLING_RETRY,
    STATE_DEPLOYED_SUCCESS,
    STATE_FAULT_ABORT,
    STATE_MISSION_FAILED
};

// ==========================================
// GLOBAL OBJECTS & VARIABLES
// ==========================================
Adafruit_INA219 ina219;
OneWire oneWire(PIN_DS18B20_DATA);
DallasTemperature tempSensor(&oneWire);

DeploymentState currentState = STATE_IDLE;
uint8_t retryCount = 0;
unsigned long stateStartTime = 0;

void setMOSFET(bool active) {
    digitalWrite(PIN_MOSFET_GATE, active ? HIGH : LOW);
    digitalWrite(PIN_STATUS_LED, active ? HIGH : LOW);
}

float readTemperature() {
    tempSensor.requestTemperatures();
    return tempSensor.getTempCByIndex(0);
}

float readCurrent_mA() {
    return ina219.getCurrent_mA();
}

bool isPanelLocked() {
    // A3144 Hall effect sensor outputs LOW when magnet is detected (Panel at 90°)
    return digitalRead(PIN_HALL_SENSOR) == LOW;
}

void setup() {
    Serial.begin(115200);
    while (!Serial && millis() < 3000);

    Serial.println("\n=======================================================");
    Serial.println("🛰️ ORBITGUARD: CubeSat SMA Deployment Avionics Subsystem");
    Serial.println("=======================================================");

    pinMode(PIN_MOSFET_GATE, OUTPUT);
    pinMode(PIN_STATUS_LED, OUTPUT);
    setMOSFET(false);

    pinMode(PIN_HALL_SENSOR, INPUT_PULLUP);

    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);
    if (!ina219.begin()) {
        Serial.println("❌ ERROR: INA219 current sensor not detected on I2C bus!");
    } else {
        Serial.println("✅ INA219 Current Sensor Initialized.");
    }

    tempSensor.begin();
    Serial.println("✅ DS18B20 Temp Sensor Initialized.");

    currentState = STATE_PRECHECK;
    stateStartTime = millis();
}

void loop() {
    switch (currentState) {
        case STATE_IDLE:
            break;

        case STATE_PRECHECK: {
            Serial.println("[STATE: PRECHECK] Performing pre-deployment diagnostics...");
            float initialTemp = readTemperature();
            Serial.printf("Ambient Temp: %.2f °C\n", initialTemp);

            if (isPanelLocked()) {
                Serial.println("⚠️ Panel already locked at 90°. Deployment not required.");
                currentState = STATE_DEPLOYED_SUCCESS;
                break;
            }

            Serial.println("✅ Pre-checks passed. Commencing active Joule heating...");
            setMOSFET(true);
            stateStartTime = millis();
            currentState = STATE_HEATING;
            break;
        }

        case STATE_HEATING: {
            unsigned long elapsed = millis() - stateStartTime;
            float current_mA = readCurrent_mA();
            float temp_C = readTemperature();

            Serial.printf("[HEATING] T+%.1fs | Current: %.1fmA | Temp: %.1f°C | Hall Lock: %s\n",
                          elapsed / 1000.0f, current_mA, temp_C, isPanelLocked() ? "YES" : "NO");

            // 1. Success condition: Hall sensor triggers positive 90° lock
            if (isPanelLocked()) {
                setMOSFET(false);
                Serial.println("🎉 SUCCESS: Hall sensor confirmed 90° panel lock!");
                currentState = STATE_DEPLOYED_SUCCESS;
                break;
            }

            // 2. Overheat safety cutoff
            if (temp_C > MAX_TEMP_SAFE_C) {
                setMOSFET(false);
                Serial.printf("❌ FAULT: Overheat detected (%.1f °C > %.1f °C)! Cutting power.\n", temp_C, MAX_TEMP_SAFE_C);
                currentState = STATE_FAULT_ABORT;
                break;
            }

            // 3. Current safety bounds check
            if (elapsed > 1000) {
                if (current_mA < MIN_CURRENT_MA) {
                    setMOSFET(false);
                    Serial.println("❌ FAULT: Open circuit / wire snap detected! Cutting power.");
                    currentState = STATE_FAULT_ABORT;
                    break;
                }
                if (current_mA > MAX_CURRENT_MA) {
                    setMOSFET(false);
                    Serial.println("❌ FAULT: Short circuit / overcurrent detected! Cutting power.");
                    currentState = STATE_FAULT_ABORT;
                    break;
                }
            }

            // 4. Heating Timeout (e.g. 8 seconds without lock)
            if (elapsed >= MAX_DEPLOY_TIME_MS) {
                setMOSFET(false);
                Serial.println("⚠️ WARNING: Deployment timeout reached without 90° lock confirmation.");
                retryCount++;
                if (retryCount < MAX_RETRIES) {
                    Serial.printf("Initiating cooling period (Attempt %d/%d)...\n", retryCount, MAX_RETRIES);
                    stateStartTime = millis();
                    currentState = STATE_COOLING_RETRY;
                } else {
                    Serial.println("❌ CRITICAL: Max retry attempts exhausted. Mission failure.");
                    currentState = STATE_MISSION_FAILED;
                }
            }
            break;
        }

        case STATE_COOLING_RETRY: {
            unsigned long coolingElapsed = millis() - stateStartTime;
            if (coolingElapsed % 10000 == 0) {
                Serial.printf("[COOLING] Thermal dissipation in progress. Remaining: %lus...\n", (COOLING_PERIOD_MS - coolingElapsed) / 1000);
            }

            if (coolingElapsed >= COOLING_PERIOD_MS) {
                Serial.printf("🔄 Retrying deployment sequence (Attempt %d of %d)...\n", retryCount + 1, MAX_RETRIES);
                setMOSFET(true);
                stateStartTime = millis();
                currentState = STATE_HEATING;
            }
            break;
        }

        case STATE_DEPLOYED_SUCCESS:
            setMOSFET(false);
            // Blink LED in slow heartbeat pattern
            digitalWrite(PIN_STATUS_LED, (millis() / 500) % 2);
            break;

        case STATE_FAULT_ABORT:
        case STATE_MISSION_FAILED:
            setMOSFET(false);
            // Rapid error blink pattern
            digitalWrite(PIN_STATUS_LED, (millis() / 100) % 2);
            break;
    }

    delay(200);
}
