# 📋 Bill of Materials (BOM) — ORBITGUARD

Comprehensive component list, technical specifications, quantities, approximate costs, and Indian procurement sources for the **ORBITGUARD CubeSat SMA Solar Array Deployment Demonstrator**.

---

## 📊 Complete Itemized Hardware List

| # | Component | Part / Model | Qty | Approx. Cost (₹) | Where to Buy (India) | Subsystem / Purpose |
|---|-----------|--------------|:---:|:-----------------:|----------------------|---------------------|
| 1 | **Microcontroller** | ESP32-WROOM-32 DevKit (30/38 pin) | 1 | 350–500 | Robu.in, Robocraze, ThinkRobotics | Flight logic, sensor polling, PWM driver |
| 2 | **SMA / Nitinol Wire** | 0.25 mm dia., ~20–30 cm length (90°C Transition) | 1 | 150–300 (per 1m) | Robu.in, Amazon India, Dynalloy import | Primary shape memory linear pull actuator |
| 3 | **Power MOSFET** | IRLZ44N (Logic-Level, TO-220, Low $R_{DS(on)}$) | 1–2 | 20–40 each | Robu.in, Local electronics store | High-current solid-state switch for Joule heating |
| 4 | **Snubber Diode** | 1N4007 Standard Recovery Diode | 1 | 2–5 | Any local electronics store | Flyback / inductive surge suppression across terminals |
| 5 | **Current Sensor** | INA219 High-Side $I^2C$ Breakout | 1 | 150–250 | Robu.in, Robocraze | Wire health, continuity & short-circuit detection |
| 6 | **Temperature Sensor** | DS18B20 (Waterproof probe or TO-92) | 1 | 80–150 | Robu.in | Direct thermal monitoring of Nitinol wire |
| 7 | **Pull-up Resistor** | 4.7 kΩ, 1/4W Metal Film | 1 | ~2 | Any electronics shop | 1-Wire bus pull-up for DS18B20 |
| 8 | **Hall Effect Sensor** | A3144 Digital Unipolar Hall Switch | 1 | 20–40 | Robu.in, Robocraze | End-of-stroke (90° panel lock) detection |
| 9 | **Magnet** | Neodymium Disc (N52, 5–8 mm dia.) | 1 | 10–20 | Amazon India, Robu.in | Magnetic target mounted to slider carriage |
| 10 | **Battery** | Li-Po 3.7V 2200 mAh (with protection PCB) | 1 | 400–700 | Robu.in, local RC/drone hobby shop | Main power source for MCU and heating pulse |
| 11 | **Buck Converter** | MP2307 / MT3608 / AMS1117 Step-Down | 1 | 40–100 | Robu.in, Robocraze | Regulates battery voltage to clean 3.3V / 5.0V |
| 12 | **Idler Pulley + Fittings** | Low-friction brass pulley / bearing set | 1 set | 100–300 | Local hardware / In-house 3D print | Guides SMA wire route along chassis |
| 13 | **Guide Rail + Slider** | Precision Aluminium extrusion + Delrin slider | 1 set | 200–500 | Local hardware / 3D print | Low-friction linear slide track |
| 14 | **Bias / Reset Spring** | Small stainless steel extension spring | 1 | 20–50 | Local hardware store | Smooth mechanical return upon cooling |
| 15 | **Hinge Assembly** | Aluminium custom pin + knuckles | 1 set | 100–300 | Local machining / 3D print | Rotates solar panel blank 90 degrees |
| 16 | **Status Indicator LED** | 5 mm Diffused LED (Green/Blue) + 330Ω | 1 | 2–5 | Any electronics shop | Visual power & state feedback |
| 17 | **Battery Connector** | JST-PH 2.0 mm 2-Pin Male/Female | 1 pair | 10–20 | Robu.in | Secure quick-disconnect battery lead |
| 18 | **Screw Terminals** | 2-Pin PCB Terminal Block (5.0 mm pitch) | 2–3 | 10–15 each | Any electronics shop | High-current wire clamps for Nitinol ends |
| 19 | **Hookup Wire** | 22 AWG flexible silicone wire (Red/Black) | ~2m | 100–150 | Robu.in | Low-resistance wiring for heating loop |
| 20 | **Kapton Tape** | Polyimide high-temp insulation tape | 1 roll | 80–150 | Robu.in, Amazon India | Thermal & electrical insulation for SMA/sensor |
| 21 | **Avionics Substrate** | FR4 Perfboard / Custom PCB | 1 | 50–200 (Perf) / 300–800 (PCB) | Robu.in / JLCPCB | Structural mounting for electronic components |
| 22 | **CubeSat Frame Mockup** | 3D Printed PETG / CNC 6061-T6 Chassis | 1 set | 500–1,500 | In-house 3D printing / Local workshop | 1U CubeSat structural demonstrator testbed |

---

## 💰 Total Cost Breakdown

| Configuration | Estimated Total (INR) | Estimated Total (USD) | Remarks |
| :--- | :---: | :---: | :--- |
| **Rapid Prototype (3D Printed + Perfboard)** | **₹2,500 – ₹3,500** | **$30 – $42** | Ideal for lab testing & SIH evaluation |
| **Flight-Grade Demonstrator (CNC Al + Custom PCB)** | **₹4,500 – ₹5,500** | **$54 – $66** | Rigid aerospace aluminum chassis + custom 2-layer PCB |

> [!TIP]
> **Procurement Advice for SIH Teams:**
> - Keep vendor tax invoices from Robu.in, Robocraze, or Amazon India for judges who request commercialization viability data.
> - Purchase extra Nitinol wire (at least 1–2 meters) to allow for experimentation with different wire diameters ($0.25\text{ mm}$ vs $0.375\text{ mm}$) and crimp termination styles.
