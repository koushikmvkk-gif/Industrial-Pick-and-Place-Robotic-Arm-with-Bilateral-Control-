# 🤖 Industrial Pick-and-Place Robotic Arm with Bilateral Control

![Platform](https://img.shields.io/badge/Platform-Arduino-blue)
![Language](https://img.shields.io/badge/Language-Embedded%20C-orange)
![ESP32-CAM](https://img.shields.io/badge/ESP32--CAM-Live%20Streaming-green)
![License](https://img.shields.io/badge/License-MIT-red)

An **Industrial Pick-and-Place Robotic Arm with Bilateral Control** is a real-time teleoperation system that enables an operator to remotely manipulate a robotic arm with high precision. The system consists of a **Master Robot Arm** and a **Slave Robot Arm**, where the slave continuously mirrors the movements of the master in real time.

An **ESP32-CAM** provides live video streaming from the slave robot, allowing the operator to monitor the workspace remotely while performing accurate pick-and-place operations.

---

# 📌 Project Overview

This project demonstrates a complete **master-slave robotic manipulation system** capable of performing industrial-style pick-and-place tasks through real-time bilateral motion control.

The master robotic arm acts as the human interface. Every movement made by the operator is captured using potentiometers and immediately transmitted to the slave robotic arm, which reproduces the exact joint positions using servo motors.

To improve remote operation, an **ESP32-CAM** is integrated with the slave robot to provide live video streaming over Wi-Fi, enabling visual feedback without requiring direct line of sight.

The project combines embedded systems, robotics, motion control, servo synchronization, wireless communication, and remote vision into a compact industrial automation prototype.

---

# ✨ Features

- Real-Time Bilateral Robot Arm Control
- Master-Slave Motion Synchronization
- Industrial Pick-and-Place Operations
- Six Degrees of Freedom (6-DOF)
- Two-Finger Servo Gripper
- Smooth Servo Motion Interpolation
- ESP32-CAM Live Video Streaming
- Wireless Remote Operation
- Embedded C Programming
- Modular Hardware Design
- Real-Time Joint Position Replication
- Servo Calibration Support
- Expandable Architecture
- Low Latency Motion Control

---

# 🎯 Objectives

- Design a real-time bilateral robotic arm.
- Implement accurate joint synchronization.
- Develop an industrial pick-and-place prototype.
- Enable remote operation through live video streaming.
- Learn robotic kinematics and embedded programming.
- Explore industrial teleoperation concepts.

---

# 🏗 System Architecture

```
                MASTER ROBOT ARM

           Potentiometers + Servos
                    │
                    │
             Arduino UNO
                    │
                    │
          Wireless Communication
                    │
                    ▼
             Arduino UNO
                    │
        Controls Servo Motors
                    │
                    ▼
              SLAVE ROBOT ARM
                    │
              ESP32-CAM Module
                    │
                    ▼
          Live Video Streaming
                    │
                    ▼
             Operator Dashboard
```

---

# 🔧 Hardware Components

| Component | Quantity |
|------------|----------|
| Arduino UNO | 2 |
| Servo Motors | 12 |
| Potentiometers | 6 |
| ESP32-CAM | 1 |
| Servo Gripper | 1 |
| External 5V Power Supply | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| Mechanical Robot Arm Structure | 2 |

---

# 💻 Software Used

- Arduino IDE
- Embedded C
- ESP32 Board Package
- Servo Library
- CameraWebServer Example
- Serial Communication

---

# ⚙ Working Principle

1. Operator moves the Master Robot Arm.
2. Potentiometers measure each joint angle.
3. Arduino converts analog values into servo angles.
4. Joint data is transmitted wirelessly.
5. Slave Arduino receives the angles.
6. Slave servos replicate the exact movements.
7. ESP32-CAM streams live video.
8. Operator monitors the robot remotely while controlling the arm.

---

# 📡 Bilateral Control

The project follows a **Master-Slave Teleoperation Architecture**.

```
Operator

      │

      ▼

Master Robot Arm

      │

Joint Angle Calculation

      │

Wireless Transmission

      │

      ▼

Slave Robot Arm

      │

Real-Time Motion Replication

      │

ESP32-CAM

      │

Live Video Feedback

      │

Operator
```

---

# 🎥 Live Video Streaming

The ESP32-CAM enables:

- Live MJPEG Video Streaming
- Remote Monitoring
- Visual Feedback
- Browser-Based Access
- Low-Latency Operation

---

# 🤖 Degrees of Freedom

| Joint | Function |
|--------|----------|
| Base | Rotation |
| Shoulder | Lift |
| Elbow | Reach |
| Wrist Pitch | Vertical Rotation |
| Wrist Roll | Horizontal Rotation |
| Gripper | Object Grasping |

---

# 📂 Project Structure

```
Industrial-Pick-and-Place-Bilateral-Control/

│

├── Master_Arm/
│      └── Master_Arm.ino
│
├── Slave_Arm/
│      └── Slave_Arm.ino
│
├── ESP32_CAM/
│      └── CameraWebServer.ino
│
├── Images/
│
├── Circuit_Diagram/
│
├── README.md
│
└── LICENSE
```

---

# 🚀 Future Improvements

- Force Feedback (True Bilateral Control)
- ROS Integration
- AI-Based Object Detection
- Automatic Pick-and-Place
- Voice Control
- Mobile App Control
- Object Tracking
- Machine Vision
- Inverse Kinematics
- Path Planning
- Industrial PLC Integration
- MQTT Cloud Connectivity
- Edge AI Processing
- Autonomous Operation

---

# 📈 Applications

- Industrial Automation
- Warehouse Automation
- Hazardous Material Handling
- Chemical Industries
- Nuclear Plant Inspection
- Remote Manipulation
- Educational Robotics
- Medical Robotics
- Research Laboratories
- Manufacturing Industries
- Assembly Lines
- Defense Robotics

---

# 🎓 Learning Outcomes

This project provides practical experience in:

- Embedded Systems
- Servo Motor Control
- Bilateral Robotics
- Teleoperation
- Wireless Communication
- Industrial Automation
- Robotic Kinematics
- Motion Synchronization
- Embedded C Programming
- Remote Monitoring
- Camera Integration
- Real-Time Control Systems

---

# 📸 Project Images

```
images/
├── Master_Robot.jpg
├── Slave_Robot.jpg
├── Circuit_Diagram.png
├── ESP32_CAM.jpg
└── Working_Demo.gif
```

---

# 📽 Demo

> Add a GIF or YouTube video demonstrating:
>
> - Master Arm Movement
> - Slave Arm Replication
> - Pick-and-Place Operation
> - Live ESP32-CAM Streaming

---

# 👨‍💻 Author

**Koushik M (Nair)**

Mechatronics Engineer | Embedded Systems | Robotics | Industrial Automation | Edge AI

GitHub: https://github.com/koushikmvkk-gif

LinkedIn: https://www.linkedin.com/in/koushikmvkk

---

# 📄 License

This project is licensed under the **MIT License**.

---

## ⭐ Support

If you found this project useful, consider giving it a **⭐ Star** on GitHub. It helps others discover the project and supports future robotics and embedded systems developments.
