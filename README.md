# Classwork | Physics for Robotics

A series of Arduino-based robotics exercises exploring the intersection of **classical mechanics and embedded systems**, developed for the FIBO-KMUTT Physics in Robot Technology course (ว30256).

---

## Overview

This project translates mathematical physics models into physical robot movement. Using a custom-built differential-drive robot with an ESP32 microcontroller, the exercises progressively build from basic motor control and kinematics calculations to executing complex autonomous navigation missions with precise turns and curved paths.

---

## Project Objectives

- **Linear Motion:** Convert distance (cm) into motor RPM for precise straight-line travel.
- **Circular Motion:** Implement angular velocity and differential wheel speeds for specific turning radii.
- **Trigonometric Navigation:** Use vector geometry to execute complex paths (star patterns, multi-point routes).
- **Mechanical Design:** Design 3D-printed extensions to house servo motors and sensors securely.

---

## Repository Structure

### Software Tasks (C++ / Arduino)

| File | Description |
| :--- | :--- |
| `Task Exercise.ino` | Fundamental exercises — serial output, variable calculations (date sums, currency conversion, circumference, acceleration), motor control basics, for/while loops, and conditional direction control. |
| `Task Circular Motion.ino` | Implements a full 360° circle around a 30 cm radius track using differential steering — inner wheel at lower RPM, outer wheel at higher RPM, calculated from angular velocity formulas. |
| `Task Star Movement.ino` | Navigates a 5-pointed star pattern by alternating forward movement with precise 72° right turns and 144° left turns, using calculated RPM values for pivot-on-wheel rotation. |
| `Task Final.ino` | The complete autonomous mission — a 14-stage navigation sequence through multiple stations with 90° pivots, 180° semi-circular arcs (differential steering), 60° orientation adjustments, and precise linear segments (47 cm, 44 cm, 34 cm, 29 cm, etc.). |

### Motor Library (`src/`)

| File | Description |
| :--- | :--- |
| `Motor.h` / `Motor.cpp` | RS485 motor controller library for dual-motor differential drive communication. |
| `MotorV2.h` | Updated motor library version with expanded functionality. |

### Engineering / CAD Assets

| File | Description |
| :--- | :--- |
| `3D Car Body.step` | Main chassis designed for stability on a differential-drive platform. |
| `3D Extension.step` | Lightweight arm designed to house servo motors and sensors. |
| `3D Wheel.step` | Custom wheel geometry. |
| `Schematic Assembly.pdf` | Technical drawing of the full robot assembly. |
| `Schematic Extension(1-2).pdf` | Engineering drawings for the sensor extension arm. |
| `Schematic Wheel.pdf` | Detailed wheel dimensions and geometry. |
| `Report Final Task (TH).pdf` | Final project report (Thai language). |

### 3D Model (Onshape)

> **[View Full Assembly on Onshape](https://cad.onshape.com/documents/74141cf14b4e3edbccf8aeed/w/8b6afd6c8bef08f5de8eb482/e/12db100d49e5ac8ae6d900ee?renderMode=0&uiState=698dc4fa336c8f017a6a8bfc)**

---

## Final Mission Breakdown (`Task Final.ino`)

The robot executes a 14-stage autonomous mission navigating through 5 checkpoints:

| Stage | Action | Technical Logic |
| :--- | :--- | :--- |
| 1 | Forward 47 cm to Box 1 | Linear RPM conversion: `distance × rpm_unit` |
| 2–3 | Reverse 7 cm + 90° pivot turn | Arc length: `(2π × track) × 0.25` for quarter-turn |
| 4–5 | Backward 44 cm to Box 2, then return | Same RPM formula, reversed motor direction |
| 6–7 | 90° right turn + 5 cm approach to Box 3 | Pivot-on-wheel rotation |
| 8–9 | Forward 22 cm to Box 4, then reverse to Box 5 | Orientation adjustment with double 90° maneuver |
| 10–11 | 90° left pivot + forward 34 cm | Left-wheel pivot using outer wheel |
| 12 | 180° semi-circular arc around obstacle | Differential steering: inner=11 cm, outer=27 cm radius over 10 seconds |
| 13 | 60° precise turn | Arc length: `(2π × track) × (60/360)` |
| 14 | Final dash 29 cm to finish | Linear drive to goal |

---

## Mathematical Foundation

### RPM Calculation

$$RPM_{1cm} = \frac{1}{2\pi r} \times \frac{60000}{t}$$

| Parameter | Value |
| :--- | :--- |
| Wheel Radius (r) | 3.0 cm |
| Execution Time (t) | 3000 ms |
| Track Width | 15.0 cm |

### Differential Steering (Circular Motion)

$$RPM = \frac{\theta \times radius \times 60000}{wheelCircumference \times time \times 360}$$

The inner wheel travels a shorter arc than the outer wheel, creating a curved path. The ratio of inner to outer RPM determines the turn radius.

---

## How It Was Built

- **Microcontroller:** ESP32 with RS485 serial communication to motor controllers.
- **Motors:** Dual DC motors in a differential-drive configuration, controlled via the custom `Motor.h` library.
- **Servo:** ESP32Servo library for auxiliary servo motor control.
- **CAD:** All chassis and extension parts designed in **Onshape** and 3D-printed.
- **Development Process:** Iterative — starting with motor calibration exercises, then circular motion validation, then star-pattern geometry, building up to the full multi-station final mission.

---

## Setup & Deployment

1. **Library:** Ensure `src/Motor.h` and `Motor.cpp` are in the project directory.
2. **Calibration:** Update the `wheelr` constant (default: 3.0 cm) if your wheel radius differs.
3. **Environment:** Best operated on smooth, flat surfaces — uneven terrain causes wheel slip and orientation drift.
4. **Upload:** Flash via Arduino IDE with ESP32 board support installed.

---

Curriculum designed by the **Institute of Field Robotics (FIBO), KMUTT**.
