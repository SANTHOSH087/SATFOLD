# 🔌 Electrical Wiring & Pinout Guide — ORBITGUARD

This document provides the complete wiring map, pinout assignments, power rails, and signal descriptions for the **ORBITGUARD** CubeSat deployment mechanism.

---

## 📌 Master Pinout & Interconnect Table

| Source Device | Source Pin | Target Device | Target Pin | Signal Type | Description & Notes |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Li-Po Battery (+)** | `VBAT+` | **Buck Converter** | `VIN+` | Power (+3.7V - 4.2V) | Raw battery positive input |
| **Li-Po Battery (−)** | `VBAT−` | **Common Ground** | `GND` | Power (0V) | System reference ground bus |
| **Buck Converter** | `VOUT+` | **ESP32 DevKit** | `VIN / 3V3` | Power (+3.3V or +5.0V) | Clean regulated power for MCU |
| **Buck Converter** | `VOUT−` | **Common Ground** | `GND` | Ground | Ground return |
| **ESP32** | `GPIO 25` | **IRLZ44N MOSFET** | `Gate` | Digital OUT / PWM | Gate trigger with $220\,\Omega$ series resistor & $10\text{k}\Omega$ pulldown |
| **Li-Po Battery (+)** | `VBAT+` | **INA219 Module** | `VIN+` | Power (High Current) | High-side current measurement feed |
| **INA219 Module** | `VIN−` | **Nitinol SMA Wire**| `(+) Terminal` | Switched Power | Current delivery to Nitinol wire |
| **Nitinol SMA Wire**| `(−) Terminal`| **IRLZ44N MOSFET** | `Drain` | Switched Ground | Low-side power switching |
| **1N4007 Diode** | `Cathode (Line)`| **Nitinol SMA Wire**| `(+) Terminal` | Protection | Reverse spike suppression (across SMA terminals) |
| **1N4007 Diode** | `Anode` | **Nitinol SMA Wire**| `(−) Terminal` | Protection | Connected across load |
| **IRLZ44N MOSFET** | `Source` | **Common Ground** | `GND` | Ground | Returns Joule heating current to battery |
| **INA219 Module** | `SDA` | **ESP32** | `GPIO 21` (or 34) | $I^2C$ Data | Bus data line ($3.3\text{V}$ logic) |
| **INA219 Module** | `SCL` | **ESP32** | `GPIO 22` (or 35) | $I^2C$ Clock | Bus clock line ($3.3\text{V}$ logic) |
| **INA219 Module** | `VCC` / `GND` | **Power Bus** | `3.3V` / `GND` | Power | Logic supply |
| **DS18B20 Sensor** | `DATA` | **ESP32** | `GPIO 27` | 1-Wire Digital | Thermal data line (requires $4.7\text{k}\Omega$ pull-up to $3.3\text{V}$) |
| **DS18B20 Sensor** | `VDD` / `GND` | **Power Bus** | `3.3V` / `GND` | Power | Logic supply |
| **A3144 Hall Sensor**| `OUT` | **ESP32** | `GPIO 26` | Digital IN | Active-LOW deployment confirmation ($10\text{k}\Omega$ internal/external pull-up) |
| **A3144 Hall Sensor**| `VCC` / `GND` | **Power Bus** | `3.3V` / `GND` | Power | Logic supply |
| **Status Indicator**| `GPIO 2` | **LED Anode** | Via $330\,\Omega$ Resistor | Digital OUT | Visual health, heating, and lock state indicator |
| **Status Indicator**| `LED Cathode` | **Common Ground** | `GND` | Ground | Ground return |

---

## ⚡ Grounding & Noise Suppression Guidelines

> [!IMPORTANT]
> 1. **Star-Ground Topology:** Always route the high-current loop (Battery $\rightarrow$ INA219 $\rightarrow$ Nitinol $\rightarrow$ MOSFET Source $\rightarrow$ Battery Negative) through thick 22 AWG wire directly to the battery ground. Do not route the heating current through breadboard tracks or thin PCB logic traces.
> 2. **Pull-Up Resistors:** Ensure the $4.7\text{k}\Omega$ pull-up resistor on the DS18B20 data line is located as close to the microcontroller pin (`GPIO 27`) as possible to minimize signal reflection and interference during Joule heating.
> 3. **Gate Protection:** A $10\text{k}\Omega$ pulldown resistor from the MOSFET Gate to Source ensures the MOSFET stays firmly OFF during ESP32 bootup and reset cycles.
