# Class Work | Physics for Robotics

[cite_start]This repository explores the intersection of **classical mechanics** and **robotics engineering**[cite: 19]. [cite_start]It features a series of tasks designed to study robot navigation using fundamental physics principles, developed for the "Physics in Robot Technology" course (ว30256)[cite: 14, 15].

---

## 🎯 Project Objectives
[cite_start]The goal of this project is to translate mathematical models into physical movement[cite: 19, 20]. We focus on:
* [cite_start]**Linear Motion:** Calculating velocity and acceleration for precise distance control[cite: 37].
* [cite_start]**Circular Motion:** Implementing angular velocity ($$\omega$$) and specific turning radii[cite: 39, 43].
* [cite_start]**Trigonometry Application:** Using vector geometry to execute complex paths like star patterns[cite: 38].
* [cite_start]**Mechanical Stability:** Designing 3D-printed extensions to house sensors securely and minimize vibration[cite: 30, 31].

---

## 📂 Repository Structure

### 💻 Software Implementation (C++)
* [cite_start]**`Task Exercise.ino`**: Fundamental logic for hardware control and calibration[cite: 27, 55].
* [cite_start]**`Task Circular Motion.ino`**: Implements 180° turns using differential wheel speeds[cite: 75, 76].
* [cite_start]**`Task Star Movement.ino`**: Executes precise turns to create multi-point geometric patterns[cite: 27].
* [cite_start]**`Task Final.ino`**: The complete autonomous mission logic navigating through three distinct stations[cite: 40].

### 🏗️ Engineering & 3D Design
* **`3D Car Body.step`**: The main chassis designed for a differential drive system.
* [cite_start]**`3D Extension.step`**: A lightweight arm designed to house the servo and sensors with high stability[cite: 31, 33].
* [cite_start]**`Schematic Assembly.pdf`**: Technical drawings and wheel geometry[cite: 27].

---

## 🏁 Final Task: Mission Breakdown
The `Task Final.ino` script executes a multi-stage navigation mission as follows:

| Stage | Action | Physics Logic |
| :--- | :--- | :--- |
| **Start** | [cite_start]Move forward 47 cm to the readiness point[cite: 63]. | [cite_start]$RPM$ conversion based on 3.0 cm wheel radius[cite: 62]. |
| **Station 1 & 2** | [cite_start]Reverse, rotate 90°, and move 44 cm to the checkpoint[cite: 65, 68]. | [cite_start]Center-point rotation based on 15.0 cm track width[cite: 62]. |
| **Station 3** | [cite_start]Execute a 180° semi-circular turn[cite: 77]. | [cite_start]Differential speed ($\Delta RPM$) for inner vs. outer wheels[cite: 76]. |
| **Final Goal** | [cite_start]Rotate 60° and move 29 cm to the finish star[cite: 84]. | [cite_start]Vector-based orientation adjustment[cite: 84]. |

---

## 🔢 Mathematical Foundation
[cite_start]To ensure precise movement, the code utilizes the following kinematics equation to calculate the required motor speed[cite: 56, 57]:

$${RPM}_{1cm} = \frac{1}{2\pi r} \times \frac{60000}{t}$$

* [cite_start]**$r$ (Wheel Radius):** 3.0 cm [cite: 62]
* [cite_start]**$t$ (Target Time):** 3000 ms [cite: 62]
* [cite_start]**Result:** Approximately 10.6 RPM per 1 cm of travel[cite: 62].

---

## ⚠️ Setup & Deployment
1. **Library Dependency:** Ensure the motor controller library is included in the project directory.
2. [cite_start]**Calibration:** If your physical wheel radius differs from 3.0 cm, update the `r` constant in the source code[cite: 62].
3. [cite_start]**Environment:** Best operated on smooth surfaces to avoid accumulated error from wheel slip.

---
[cite_start]*Curriculum designed by the Institute of Field Robotics (FIBO), KMUTT.* [cite: 16]
