# 📐 3D Models & Mechanical CAD Assets — ORBITGUARD

This directory contains the CAD models, 3D printing STL files, and visual rendering assets for the **ORBITGUARD** CubeSat deployment mechanism.

---

## 📂 Directory Layout

```
models/
├── README.md                     # CAD & 3D printing guide
├── orbitguard_assembly.blend     # Full Blender 3D CubeSat model & animation
├── step_cad/                     # STEP CAD neutral exchange format files
│   ├── chassis_bracket.step
│   ├── linear_slider_block.step
│   ├── linkage_rod.step
│   └── 90deg_crank_arm.step
└── stl_parts/                    # 3D Printable Mesh Files
    ├── cubesat_side_panel.stl    # 1U CubeSat solar array blank
    ├── linear_guide_rail.stl     # Low-friction guide rail
    ├── slider_carriage.stl       # SMA wire clamp & magnet pocket
    ├── crank_lever_90deg.stl     # Amplification crank
    └── hinge_knuckle_pair.stl    # Solar panel hinge brackets
```

---

## 🖨️ Recommended 3D Printing Parameters

| Parameter | Recommended Setting | Reason |
| :--- | :--- | :--- |
| **Filament Material** | **PETG / ABS / Nylon (PA-CF)** | High thermal resistance near heated Nitinol wire ($>85^\circ\text{C}$) |
| **Layer Height** | $0.16\text{ mm} - 0.20\text{ mm}$ | Smooth linear rail sliding tolerances |
| **Infill Density** | $40\% - 60\%$ (Gyroid or Grid) | Rigidity under linkage lever loads |
| **Wall Perimeters** | 4 to 5 perimeters | Prevents pin screw strip-out |
| **Nozzle Temperature** | $240^\circ\text{C} - 255^\circ\text{C}$ (for PETG) | Maximum interlayer adhesion |
| **Support** | Tree supports enabled | Clean overhangs on hinge knuckles |

---

## 🎬 Blender 3D Demonstration Assets
- The Blender project `orbitguard_assembly.blend` includes a fully rigged kinematic constraint chain.
- Moving the slider by $-7.5\text{mm}$ automatically rotates the solar panel hinge by precisely $90.0^\circ$, demonstrating the exact stroke amplification used for the SIH presentation video.
