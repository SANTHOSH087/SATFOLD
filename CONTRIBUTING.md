# 🤝 Contributing to ORBITGUARD

Thank you for your interest in contributing to **ORBITGUARD**! We welcome contributions from aerospace engineers, embedded firmware developers, CAD designers, and students participating in the Smart India Hackathon (SIH).

---

## 🛠️ Areas for Contribution

1. **Mechanical & CAD Design:**
   - Optimizing slider-crank linkages and reducing mechanical backlash.
   - Designing lightweight 3D-printable brackets and aluminium CNC structural files (`.step`, `.stl`, `.blend`).
2. **Embedded Avionics & Firmware:**
   - Implementing PID or adaptive PWM thermal control for precise Nitinol temperature regulation.
   - Enhancing fault-logging to EEPROM/Flash storage.
   - Integrating CAN-bus, $I^2C$, or UART telemetry bridges for standard CubeSat OBCs (On-Board Computers).
3. **PCB & Hardware Engineering:**
   - Routing and testing 2-layer and 4-layer PC104-compatible CubeSat avionics boards in KiCad.
   - Adding ESD protection and TVS diodes for harsh aerospace environments.
4. **Testing & Simulation:**
   - Thermal-vacuum (TVAC) simulation data.
   - Multi-cycle mechanical fatigue testing and lifespan characterization of Nitinol wire.

---

## 🚀 Contribution Workflow

1. **Fork the Repository** on GitHub.
2. **Create a Feature Branch:**
   ```bash
   git checkout -b feature/adaptive-thermal-pwm
   ```
3. **Make Your Changes:**
   - Follow clean code practices (C++ Arduino/ESP-IDF conventions).
   - Document all hardware modifications, pin changes, or CAD dimensions.
4. **Commit Your Work:**
   ```bash
   git commit -m "feat(firmware): implement adaptive PWM heating loop for DS18B20"
   ```
5. **Push and Open a Pull Request (PR):**
   - Provide a concise summary of the improvements, hardware test logs, and screenshots where applicable.

---

## 📜 Code of Conduct
Please maintain a respectful, collaborative, and inclusive environment. All contributions are subject to review under the project's [MIT License](LICENSE).
