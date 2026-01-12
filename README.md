# Final Project: Disc-Delivery Rover

This repository contains the Final Project created for the Introduction to Robotics course during the 2025-2026 academic year at the Faculty of Mathematics and Informatics, University of Bucharest, Computer Science domain. Code, implementation, explanations, and extra resources (pictures, test results, videos) are all included in each checkpoint to document the complete development cycle of the robotic system.

## Project General Description

The "Disc-Delivery Rover" is an advanced mobile mechatronic platform designed for precision projectile deployment via wireless remote control. 
The system utilizes an ESP32 microcontroller to manage Bluetooth communication and real-time hardware control.
The robot features a differential drive chassis for high maneuverability and a dual-flywheel propulsion system for consistent projectile velocity. 
A dedicated servo-driven "piston" mechanism handles the sequential feeding of ammunition.
The robot is equipped with an on-board I2C LCD acting as a real-time diagnostic dashboard and a Piezo Buzzer for status notifications.

## B. Bill Of Materials (BOM)

- Microcontroller: ESP32.
- Locomotion: 2x DC Motors.
- Propulsion: 2x DC High-Speed Motors (Flywheels).
- Motor Interface: 1x L293D. 
- Feeding Actuator: 1x Servo. 
- Telemetry: 1x Ultrasonic Distance Sensor.
- Visual Dashboard: LCD 16x2 with I2C Module (Mounted on robot for real-time telemetry).
- Acoustic Feedback: Piezo Buzzer (Provides audio alerts for system states).
- Power Supply: 2x LiPo Batteries (7.4V).
- Control Interface: Any Bluetooth compatible Controller.

## Q1 - What is the system boundary? 

The boundary is defined by the Bluetooth wireless link (input) and the projectile's kinetic exit (output). It encompasses the entire physical chassis, the electrical power management system, and the feedback interface (LCD/Buzzer).

## Q2 - Where does intelligence live? 

Intelligence is embedded in the ESP32 Firmware. It processes asynchronous input, calculates PWM duty cycles for the L293D, manages the servo-feeder timing, and updates the diagnostic data on the LCD.

## Q3 - What is the hardest technical problem? 

The primary challenge is Power Rail Stability and Signal Integrity. DC motors create significant electrical noise and voltage drops that can cause the LCD to display corrupt characters or reset the I2C bus. Solving this requires hardware-level filtering (capacitors) and software-level error handling for the I2C communication.

## Q4 - What is the minimum demo? 

Navigating the robot wirelessly, viewing live distance data on the robot's LCD, hearing a confirmation from the buzzer, and launching a projectile successfully via the remote-controlled feeder.

## Q5 - Why is this not just a tutorial? 

This project requires the integration of real-time telemetry and multimodal feedback into a single system. Unlike a simple tutorial, this project involves building a system that monitors itself and reports critical data to the user via a physical dashboard and audio cues in real-time.


## Do you need an ESP32?

YES. You cannot use an Arduino Uno. The ESP32 is required for its dual-core processing (handling Bluetooth and sensors on separate cores) and its on-board Bluetooth hardware.
