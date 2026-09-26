# 🛠️ Step-by-Step Assembly & Testing Guide — ORBITGUARD

This guide provides exhaustive, phase-by-phase instructions to assemble, wire, calibrate, and test the **ORBITGUARD** CubeSat SMA solar array deployment demonstrator.

---

## 📋 Required Tools & Consumables
- Soldering iron (temperature-controlled, $350^\circ\text{C}$) & lead-free solder
- Wire strippers (20–28 AWG) & flush cutters
- Multimeter with DC voltage, resistance, and continuity modes
- Kapton polyimide tape ($10\text{mm} - 20\text{mm}$ width)
- M2 and M3 hex screwdrivers & Allen keys
- Benchtop DC power supply or protected 1S Li-Po battery
- USB-C / Micro-USB cable for ESP32 firmware flashing

---

## 🔩 11-Step Assembly Procedure

### Step 1: Battery Preparation & Safety Verification
1. Inspect the 3.7V Li-Po battery pack. Ensure it contains an integrated PCM/BMS protection circuit to prevent over-discharge below $3.0\text{V}$ or short-circuit overcurrents.
2. Solder a male JST-PH 2.0mm connector to the battery leads, shielding positive and negative joints with heat-shrink tubing.

### Step 2: Power Stage & Voltage Regulation Wiring
1. Connect the Battery (+) terminal to the Buck Converter `VIN+` and Battery (−) to `VIN−`.
2. Power on the buck converter and use a multimeter to adjust the potentiometer until the output reads precisely **$3.30\text{V} \pm 0.05\text{V}$** (or $5.0\text{V}$ if connecting to the ESP32 `VIN` pin).
3. Connect the buck converter output to the ESP32 `3V3` / `VIN` and `GND` power rails.

### Step 3: High-Current SMA Actuator Circuit
1. Connect the Battery (+) rail to the `VIN+` terminal of the INA219 current sensor board.
2. Connect `VIN−` of the INA219 to the primary positive terminal of the Nitinol wire clamp.
3. Connect the negative terminal of the Nitinol wire clamp to the **Drain (Pin 2)** of the IRLZ44N MOSFET.
4. Connect the **Source (Pin 3)** of the IRLZ44N MOSFET directly to the common system ground bus.
5. Solder the **1N4007 snubber diode** across the SMA wire terminals, ensuring the cathode (marked with a silver band) connects to the positive terminal.

### Step 4: MOSFET Gate Drive Circuit
1. Connect ESP32 `GPIO 25` to the **Gate (Pin 1)** of the IRLZ44N MOSFET via a $220\,\Omega$ series resistor.
2. Add a $10\text{k}\Omega$ pull-down resistor between the Gate and Source (GND) to guarantee that the MOSFET remains completely turned off during microcontroller bootloader execution.

### Step 5: Sensor Array Integration
1. **INA219 Current Sensor:** Connect `VCC` to $3.3\text{V}$, `GND` to GND, `SDA` to `GPIO 21` (or 34), and `SCL` to `GPIO 22` (or 35).
2. **DS18B20 Temperature Sensor:** Connect `VCC` to $3.3\text{V}$, `GND` to GND, and `DATA` to `GPIO 27`. Solder a $4.7\text{k}\Omega$ pull-up resistor between `DATA` and `3.3V`. Fasten the sensor probe directly against the Nitinol wire using 2–3 wraps of high-temperature Kapton tape.
3. **A3144 Hall Effect Sensor:** Connect `VCC` to $3.3\text{V}$, `GND` to GND, and `OUT` to `GPIO 26`. Position the sensor at the terminal end of the slider rail.

### Step 6: Visual Status Indicator
1. Connect `GPIO 2` of the ESP32 to the Anode (longer leg) of a 5mm LED through a $330\,\Omega$ current-limiting resistor. Connect the Cathode to Ground.

### Step 7: Mechanical Assembly & Kinematics Mounting
1. Secure the linear guide rails and brass idler pulley onto the CubeSat chassis plate using M2.5 screws.
2. Slide the Delrin carriage onto the guide rail and verify silky-smooth translation without binding.
3. Fasten the neodymium disc magnet onto the slider carriage directly aligned with the A3144 Hall sensor's face.
4. Install the rigid linkage rod between the slider and the 90° hinge crank arm.
5. Attach the stainless steel bias reset spring between the chassis anchor and the slider carriage.
6. Route the 0.25mm Nitinol wire from the positive terminal clamp, over the idler pulley, and clamp it securely to the slider block.

### Step 8: Polarity & Continuity Double-Check
- [ ] Multimeter test: Check that Battery (+) and Ground have no direct short-circuit ($R > 10\text{k}\Omega$).
- [ ] Verify diode orientation (Cathode to `VIN+`).
- [ ] Verify MOSFET pinout (Gate-Drain-Source from left to right on TO-220 package).

### Step 9: Benchtop Diagnostics & Cold Boot
1. Connect the ESP32 to your PC via USB with the battery disconnected.
2. Open the Serial Monitor at **115200 baud**.
3. Verify that the ESP32 boots cleanly, initializes the INA219 ($I^2C$), and reads ambient temperature ($22^\circ\text{C} - 28^\circ\text{C}$) from the DS18B20.
4. Bring a magnet near the Hall sensor and verify the pin transition from HIGH to LOW on `GPIO 26`.

### Step 10: First Actuation & Pulse Calibration
1. Connect the 3.7V battery.
2. Trigger an initial low-duty actuation test pulse ($1\text{--}2\text{ seconds}$).
3. Observe the serial log: current should jump to approximately $1.0\text{A} - 1.5\text{A}$, and the wire temperature will rise to $50^\circ\text{C} - 70^\circ\text{C}$.
4. Verify the slider begins contracting and moving smoothly along the rail.

### Step 11: Full Cycle Endurance Testing
1. Execute full autonomous deployment: the ESP32 heats the wire until the Hall sensor triggers (approx. $4\text{ to }6\text{ seconds}$).
2. Upon reaching $90^\circ$, confirm that power cuts immediately and the panel latches into its over-center detent.
3. Allow the assembly to cool for 60 seconds. Confirm that the bias spring gently resets the slider to its initial position once the Nitinol reverts to its Martensite phase.
4. Record 10 consecutive deployment cycles to log repeatability and reliability metrics for your SIH presentation.
