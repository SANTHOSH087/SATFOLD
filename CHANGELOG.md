# 📜 Changelog — ORBITGUARD

All notable changes to the **ORBITGUARD** project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

---

## [1.0.0] - 2026-09-26 (SIH 2025 Release)
### Added
- **Core Architecture:** Complete end-to-end Nitinol SMA actuation kinematics for 90° CubeSat solar panel unfolding.
- **Avionics Subsystem:** ESP32-WROOM-32 closed-loop state machine with autonomous 3-stage retry routines.
- **Sensor Telemetry Network:**
  - INA219 current monitoring for open-circuit (wire snap) and short-circuit protection.
  - DS18B20 digital 1-Wire thermal envelope monitoring to prevent wire annealing.
  - A3144 Hall-effect sensor for positive 90° mechanical latch verification.
- **Hardware Documentation:**
  - Complete 22-item Bill of Materials (BOM) with Indian procurement sources and pricing.
  - Detailed Electrical Wiring & Pinout Guide.
  - Vector SVG Electrical Schematic (`ORBITGUARD_Schematic.svg`).
  - 11-Step Assembly & Testing Manual.
  - Component datasheets directory.
- **3D Mechanics:** Blender 3D CAD modeling structure and kinematic stroke amplification calculations.

---

## [0.2.0] - 2026-08-15
### Added
- Breadboard proof-of-concept testing with IRLZ44N MOSFET power stage.
- Initial bench characterization of 0.25mm Nitinol wire contraction stroke (7–8 mm at 1.2A).
- Prototype 3D-printed slider track and hinge lever arm.

---

## [0.1.0] - 2026-07-01
### Added
- Initial conceptual study on replacing legacy CubeSat burn-wire mechanisms with Shape Memory Alloys.
- Trade study comparing thermal expansion vs. phase-change alloys.
