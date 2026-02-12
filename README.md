# Physics for Robotics Kinematics and Mission Navigation

[cite_start]This repository explores the intersection of classical mechanics and robotics engineering[cite: 19, 21]. [cite_start]It features a series of tasks designed to study robot navigation using fundamental physics principles, developed for the Physics in Robot Technology course ว30256[cite: 14, 15].

---

## Project Objectives
[cite_start]The goal of this project is to translate mathematical models into physical movement[cite: 19]. We focus on:
* [cite_start]Linear Motion: Converting distance into motor RPM for precise travel[cite: 37, 56].
* [cite_start]Circular Motion: Implementing angular velocity and specific turning radii[cite: 39, 43].
* [cite_start]Trigonometry Application: Using vector geometry to execute complex paths like star patterns[cite: 3, 38].
* [cite_start]Mechanical Stability: Designing 3D-printed extensions to house sensors securely and minimize vibration[cite: 20, 30].

---

## 3D Design and CAD
[cite_start]The robot is built on a custom-designed differential drive chassis[cite: 36]. You can view and export the full assembly here:

> **Link: [View Project on Onshape](https://cad.onshape.com/documents/74141cf14b4e3edbccf8aeed/w/8b6afd6c8bef08f5de8eb482/e/12db100d49e5ac8ae6d900ee?renderMode=0&uiState=698dc4fa336c8f017a6a8bfc)**



---

## Repository Structure

### Software Implementation (C++)
* [cite_start]Task Exercise.ino: Fundamental logic for hardware control and calibration[cite: 55].
* [cite_start]Task Circular Motion.ino: Implements turns using differential wheel speeds[cite: 39, 75].
* [cite_start]Task Star Movement.ino: Executes precise turns to create multi-point geometric patterns[cite: 3].
* [cite_start]Task Final.ino: The complete autonomous mission logic navigating through three distinct stations[cite: 40].

### Engineering Assets
* [cite_start]3D Car Body.step: The main chassis designed for stability[cite: 19].
* [cite_start]3D Extension.step: A lightweight arm designed to house the servo and sensors[cite: 30, 31].
* [cite_start]Schematic Assembly.pdf: Technical drawings and wheel geometry[cite: 20].

---

## Final Task Mission Breakdown
[cite_start]The Task Final.ino script executes a multi-stage navigation mission across three stations[cite: 40, 41]:

| Stage | Action | Technical Logic |
| :--- | :--- | :--- |
| **Preparation** | [cite_start]Move forward 47 cm to the readiness point[cite: 63]. | [cite_start]Linear RPM conversion[cite: 56]. |
| **Station 1 and 2** | [cite_start]Reverse, rotate 90 degrees, and move 44 cm to the checkpoint[cite: 65, 68]. | [cite_start]Center-point rotation logic[cite: 38]. |
| **Station 3** | [cite_start]Execute a 180 degree semi-circular turn around the obstacle[cite: 76, 77]. | [cite_start]Differential speed for inner vs. outer wheels[cite: 39]. |
| **Final Goal** | [cite_start]Rotate 60 degrees and move 29 cm to the finish star[cite: 84]. | [cite_start]Vector-based orientation[cite: 38]. |

---

## Mathematical Foundation
[cite_start]To ensure precise movement, the code utilizes the following kinematics equation to calculate the required motor speed[cite: 56]:

$${RPM}_{1cm}=\frac{1}{2\pi r}\times\frac{60000}{t}$$

* [cite_start]r (Wheel Radius): 3.0 cm[cite: 62].
* [cite_start]t (Target Time): 3000 ms[cite: 62].
* [cite_start]Track Width: 15.0 cm (distance between wheels)[cite: 62].

---

## Setup and Deployment
1. Library Dependency: Ensure the motor controller library is included in the project directory.
2. [cite_start]Calibration: If your physical wheel radius differs from 3.0 cm, update the r constant in the source code[cite: 57, 60].
3. [cite_start]Environment: Best operated on smooth surfaces; uneven terrain can cause wheel slip and orientation drift[cite: 86].

---
[cite_start]Curriculum designed by the Institute of Field Robotics (FIBO), KMUTT[cite: 16].
