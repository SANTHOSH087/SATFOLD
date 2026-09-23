# 🚀 SATFOLD — Smart Adaptive Thermal Foldable Solar Panel Deployment System

A lightweight **Shape Memory Alloy (SMA / Nitinol)** based solar panel deployment system for **1U CubeSats**, replacing conventional motors with a compact, low-power, and reliable actuator.

---

## 🌌 About the Project

**SATFOLD** is an aerospace innovation developed for **Smart India Hackathon (SIH) 2026**.

The project addresses one of the biggest challenges in nano-satellites: deploying solar panels within the extremely limited **1U CubeSat (10 × 10 × 10 cm)** form factor.

Instead of using bulky DC motors and gear mechanisms, SATFOLD employs a **Shape Memory Alloy (Nitinol)** wire that contracts when heated by a short electrical pulse. This creates a compact, energy-efficient deployment mechanism with real-time position verification using sensors.

---

## ⚠️ The Problem

Traditional CubeSat deployment systems suffer from:

* ⚙️ Heavy motor and gearbox assemblies
* 🔋 Continuous power consumption
* 🛠️ Mechanical complexity and multiple failure points
* 📦 Limited compatibility with the 1U CubeSat volume

---

## 💡 Our Solution

SATFOLD replaces the motor with a **Nitinol SMA actuator** controlled by an **ESP32**.

### 🔄 Deployment Sequence

1. 🧠 ESP32 receives deployment command
2. ⚡ MOSFET delivers a timed electrical pulse
3. 🔥 SMA wire heats and contracts
4. 🛰️ Linkage rotates the solar panel to **90°**
5. ✅ Hall sensor confirms successful deployment and power is cut

---

## ✨ Features

* 🪶 **Lightweight Design** — Eliminates motors and gearboxes
* 🔋 **Low Power Consumption** — Single electrical pulse activation
* 📦 **Compact 1U Compatible** — Fits within the CubeSat envelope
* 📡 **Closed-Loop Verification** — Hall sensor confirms deployment
* 🛡️ **High Reliability** — Fewer moving mechanical parts
* 📈 **Scalable Architecture** — Applicable to 2U and 3U CubeSats

---

## 🛰️ Applications

* 🛰️ 1U / 2U / 3U CubeSats
* 🎓 Educational satellites
* 🇮🇳 ISRO student satellite missions
* 🌍 Nano-satellite research platforms
* 🤖 Autonomous deployable aerospace mechanisms

**Domain:** Aerospace & Space Technology ✨

---

## 🔬 Future Enhancements

* 🌌 Vacuum chamber deployment testing
* 🌡️ Thermal characterization in space conditions
* 🔁 Repeated deployment cycle validation
* 🧩 Integration into a complete 1U CubeSat prototype

---

## 👨‍🚀 Team

**SATFOLD** was developed as a **Smart India Hackathon (SIH) 2026** project in the **Aerospace & Space Technology** domain, focusing on innovative, low-power solar panel deployment for CubeSats.
