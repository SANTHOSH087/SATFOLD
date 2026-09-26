# 📑 Key Component Datasheets & Technical References

Official manufacturer datasheets, technical application notes, and specifications for the core active and passive components in the **ORBITGUARD** system.

---

## 📚 Component Datasheet Directory

| Component Name | Manufacturer / Source | Description / Package | Official Datasheet Link |
| :--- | :--- | :--- | :--- |
| **ESP32-WROOM-32** | Espressif Systems | 32-bit Dual-Core MCU + Wi-Fi/BLE (38-pin SMD module) | [Download Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32-wroom-32_datasheet_en.pdf) |
| **INA219** | Texas Instruments | $I^2C$ Bidirectional Current/Power Monitor (SOT-23 / SOIC-8) | [Download Datasheet](https://www.ti.com/lit/ds/symlink/ina219.pdf) |
| **DS18B20** | Analog Devices / Maxim | 1-Wire Digital Temperature Sensor (TO-92 / Waterproof Probe) | [Download Datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/DS18B20.pdf) |
| **IRLZ44N** | Vishay / Infineon | Logic-Level N-Channel Power MOSFET (TO-220AB, 55V, 47A) | [Download Datasheet](https://www.vishay.com/docs/91238/irlz44n.pdf) |
| **A3144** | Allegro MicroSystems | Sensitive Unipolar Digital Hall-Effect Switch (TO-92UA) | [Download Datasheet](https://www.allegromicro.com/-/media/files/datasheets/a3141-2-3-4-datasheet.pdf) |
| **1N4007** | Vishay Semiconductors | 1.0A General Purpose Rectifier / Snubber Diode (DO-41) | [Download Datasheet](https://www.vishay.com/docs/88503/1n4001.pdf) |
| **Flexinol® / Nitinol Wire** | Dynalloy Inc. | Technical Data & Thermal Actuation Wire Characteristics | [View Technical Specs](https://www.dynalloy.com/tech_data_wire.php) |

---

## 🔍 Critical Operating Limits Summary

- **Nitinol Recommended Transition Current:** $1.0\text{ A} - 1.6\text{ A}$ for $0.25\text{ mm} - 0.38\text{ mm}$ diameter wire.
- **Nitinol Maximum Thermal Limit:** Do not exceed $110^\circ\text{C}$ to preserve crystal shape memory hysteresis.
- **ESP32 Logic Rail:** $3.0\text{V} - 3.6\text{V}$ (Nominal $3.3\text{V}$). Maximum GPIO current sink/source is $40\text{mA}$ (use external MOSFET driver).
- **INA219 Max Bus Voltage:** $26\text{V}$, with $3.2\text{A}$ max current capability using standard $0.1\,\Omega$ shunt resistor.
