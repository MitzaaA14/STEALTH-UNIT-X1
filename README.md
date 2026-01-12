# Final Project: Disc-Delivery Ecosystem 

This repository contains the Final Project created for the **Introduction to Robotics** course during the 2025-2026 academic year at the Faculty of Mathematics and Informatics, University of Bucharest, Computer Science domain. 


## Team Members: 
- https://github.com/iulia1603
- https://github.com/MitzaaA14

## Project General Description

The **Disc-Delivery Ecosystem** is an advanced robotic system designed for precision projectile deployment and automated scoring. The architecture is **modular**, consisting of three interconnected components that communicate:

1.  **The Rover:** A mobile platform with a dual-flywheel propulsion system. It features an **internal ammunition monitoring system** (ultrasonic) and a camera for target recognition.
2.  **The Scoring Gate:** An autonomous target that detects successful hits via IR sensors and provides immediate visual feedback.
3.  **The Control Hub (Hybrid Interface):**
    * **Option A:**  A **PS5 DualSense Controller** for high-precision driving, paired with a stationary monitoring station.
    * **Option B:** A **Custom-Built ESP32 Controller/Station** featuring physical joysticks and a built-in LCD.
    * **Option C:** **Smartphone Control** via a web interface or app, displaying all live telemetry (ammo, score, sensor data) directly on the screen.

## B. Bill Of Materials (BOM)

### 1. The Rover (Action Node)
- **Microcontroller:** ESP32 (Main Intelligence Hub).
- **Locomotion:** 2x DC Motors + L293D Motor Driver.
- **Propulsion:** 2x High-Speed DC Motors (Flywheels).
- **Feeding Actuator:** 1x Servo Motor (Piston mechanism).
- **Sensors:** - 1x Ultrasonic Sensor (Ammunition height measurement).
               - 1x Ultrasonic Sensor (Distance feedback).
- **Power Supply:** 2x LiPo Batteries (7.4V).

### 2. The Scoring Gate (Target Node)
- **Microcontroller:** ESP32.
- **Sensor:** IR Beam Break Sensor / Infrared Proximity Sensor.
- **Visual Feedback:** LED indicators for goal confirmation.

### 3. The Command Node (Controller/Station)
OPTION A:
- **Microcontroller:** ESP32 (for Custom Station).
- **Inputs:** 2x Analog Joysticks + Buttons.
- **Visual Dashboard:** I2C LCD 16x2 (Score, Ammo Level, Status).
- **Acoustic Feedback:** Piezo Buzzer (Low ammo/Goal alerts).

OPTION B:
- **Mobile Control:** Smartphone (iOS/Android) via WebServer/Bluetooth.

## Q1 - What is the system boundary? 

The boundary is defined by the **Wireless Command Link**. It includes the input interfaces (Phone, Custom or PS5 Controller), the Rover's internal sensors (Ammo, Camera, Distance), the Scoring Gate's detection logic, and the real-time data visualization on the chosen display.

## Q2 - Where does intelligence live? 

Intelligence is centralized in the **Rover ESP32 Firmware**. It acts as the "Central Brain," processing asynchronous inputs, calculating PWM for locomotion, managing the servo-feeder timing, and running the target recognition logic. It also pushes telemetry data (ammo count, scoring updates) to the connected control interface.

## Q3 - What is the hardest technical problem? 

**Signal Integrity and Resource Monitoring.** Balancing high-current DC motor operation (which generates electrical noise) with stable wireless communication (Bluetooth/Wi-Fi) while simultaneously processing data from multiple sensors in real-time.

## Q4 - What is the minimum demo? 

Navigating the rover via a smartphone or controller, checking live ammo levels on the screen, successfully firing a disc into the gate, and seeing the score update instantly on the mobile/LCD dashboard.

## Q5 - Why is this not just a tutorial? 

This project demonstrates **Advanced System Integration**. It involves building a coordinated wireless network, implementing a custom telemetry protocol for resource management (Ammunition tracking).


## Technical Requirement: Why ESP32?

**YES.** The ESP32 is mandatory because: 
1. **Dual-Core Architecture:** One core handles the wireless stacks (Web Server/Bluetooth) while the other manages motor control and sensor polling.
2. **Connectivity:** Built-in Wi-Fi and Bluetooth are essential for the multi-interface control system (Phone/PS5).
