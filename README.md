# Physics for Robotics: Kinematics & Movement Study 🤖

This repository explores the intersection of **classical mechanics** and **robotics engineering**. It features a series of tasks designed to study robot navigation using fundamental physics principles, supported by full 3D design and technical schematics.


## 🎯 Project Objectives
The goal of this project is to translate mathematical models into physical movement. We focus on:
* **Linear Motion:** Calculating velocity and acceleration for precise distance control.
* **Circular Motion:** Implementing angular velocity ($$\omega$$) and turning radii.
* **Trigonometry Application:** Using sine and cosine functions to execute complex pathing.

---

## 📂 Repository Structure

### 💻 Software (Arduino/C++)
| File | Description | Key Physics Concept |
| :--- | :--- | :--- |
| `Task Exercise.ino` | Fundamental logic for hardware control. | Logic & Data Flow |
| `Task Circular Motion.ino`| Driving the robot in a precise rounded path. | Centripetal Kinematics |
| `Task Star Movement.ino` | Complex pathing involving sharp turns. | Vector Geometry |
| `Task Final.ino` | Integrated movement logic. | Applied Kinematics |

### 🏗️ Engineering & Design
* **3D Models (`.step`):** Includes the Car Body, Wheels, and Extension components for 3D printing or CAD assembly.
* **Schematics (`.pdf`):** Detailed technical drawings for the assembly and wheel geometry.


---

## ⚙️ System Design
The project is built around a **Differential Drive** robot platform:
* **Dual Drive Wheels:** Independent motor control for differential steering.
* **Caster Ball:** Low-friction support for 360-degree rotation.
* **Path Precision:** Utilizing trigonometric calculations to minimize physical drift.

---

## ⚠️ Setup & Deployment

1.  **Library Dependency:** Ensure you have the required motor libraries installed in your IDE.
2.  **File Location:** Keep the `.ino` files and their respective headers in the same folder.
3.  **Hardware Check:** Verify motor pinouts against the **Schematic Assembly.pdf** before powering the system.

---

## 🎓 Academic Context
* **Level:** M.4 (Grade 10) Semester 2
* **Curriculum Design:** Institute of Field Robotics (**FIBO**), KMUTT.

---
*Created as part of a specialized study in robotics and applied physics.*
