# Final Project: Stealth Unit X1 

This repository contains the Final Project created for the **Introduction to Robotics** course during the 2025-2026 academic year at the Faculty of Mathematics and Informatics, University of Bucharest, Computer Science domain. 


## Team Members: 
- https://github.com/iulia1603
- https://github.com/MitzaaA14

<details>
<summary><h3>Project Description</summary></h3>

## Project General Description

 - STEALTH UNIT X1 is a modular robotic ecosystem designed for tactical movement and projectile deployment. 
 - The system utilizes a Master-Slave architecture, where a mobile Rover (Master) hosts a Web Server for user control and communicates via the low-latency ESP-NOW protocol with a secondary Launcher unit (Slave).

## System Architecture
    
 - The robot is divided into two intelligent nodes to optimize power distribution and processing:

    1. Master Node (The Rover): 
        - Creates a Wi-Fi Access Point and hosts an interactive Web Dashboard.

        - Manages locomotion using dual DC motors.

        - Controls a Servo-based feeding mechanism.

        - Relays firing commands to the Slave unit.

    2. Slave Node (The Cannon): 
        - Listens for encrypted ESP-NOW packets.

        - Controls the high-speed dual-flywheel propulsion system for disc launching.

## B. Bill Of Materials (BOM)

- 2 x ESP32 DevKit V1 : Main Logic & Wireless Communication
- 2 x L298N Motor Driver : Direction and speed control (H-Bridge)
- 2 x DC Motors : Primary movement (Locomotion)
- 2 x DC Motors : Flywheel propulsion for disc launching
- 1 x Servo Motor : Magazine feeding piston (90° toggle)
- 1 x Buck Converter : Voltage regulation for Servo
- 3 x 7.4V Li-Po Battery : High-current power source
- 1 x Smart Car Chassis 2WD : Modular housing
- Hobbycolor (PVC) Plate - 1000x500x3mm - Custom-cut upper structural walls and mounting panels
- Multiple 3D Printed Parts

## Mechanical Design & Fabrication

The robot features a Tri-Hybrid Construction approach:

1. The Base: A standard 2WD Smart Car Chassis provides the structural integrity for the wheels and primary gearmotors.

2. The Hull: Custom-cut panels from Hobbycolor (Black PVC) were used to build the vertical structure. This allowed for a lightweight yet rigid "stealth" aesthetic.

3. The Modules: 3D-printed modular housings were bolted to the PVC walls to securely hold the ESP32 boards and the complex flywheel launcher mechanism.

## Q1 - What is the system boundary? 

The boundary includes the user's mobile interface, the Wi-Fi control link, and the internal ESP-NOW telemetry between the Rover's chassis and the Cannon's firing logic.

## Q2 - Where does intelligence live? 

Intelligence is distributed. The Master node handles the UI and navigation logic, while the Slave node handles the high-speed execution timing for the launcher flywheels.

## Q3 - What is the hardest technical problem? 

Ensuring the 3D-printed launcher remained stable when mounted to the PVC walls, especially during the high-RPM spin-up of the flywheels.

## Q4 - What is the minimum demo? 

Powering the unit, connecting to the "STEALTH_UNIT_X1" network, and successfully navigating a course to fire a disc into a target using only the web dashboard.

## Q5 - Why is this not just a tutorial? 

It combines pre-built robotics hardware (2WD Chassis) with custom fabrication (PVC cutting) and advanced wireless networking (ESP-NOW + WebServer) into a unique, integrated tactical system.

## Power Distribution & Electronics
The electrical architecture is designed to prevent voltage spikes 
from the motors from interfering with the microcontrollers.

Power Logic:

- The system is powered by independent Li-Po sources to isolate 
high-current draws:

    a. Locomotion Loop: 7.4V Li-Po Battery -> L298N Motor Driver.

        - The Driver's internal regulator provides 5V back to the Master ESP32.

    b. Combat Loop (Cannon): 7.4V Li-Po Battery -> L298N Motor Driver.

        - The Driver's internal regulator provides 5V back to the Slave ESP32.

    c. A Buck Converter is dedicated exclusively to the Servo Motor, ensuring it receives a stable voltage. Servo has an Li-Po Battery for itself.

## Implementation Details
Master-Slave Synchronization
- The two ESP32 units communicate using the ESP-NOW protocol. This is a connectionless communication developed by Espressif that allows for near-instantaneous triggers.

Latency: <10ms (Ideal for a firing mechanism).

Reliability: The Slave unit is hardcoded to respond only to the Master's unique MAC address.

Software Steering Calibration

- Standard DC motors rarely spin at the exact same RPM. To ensure 
STEALTH UNIT X1 moves in a straight line, we implemented a 
software-side correction in the PWM mapping.

## Technical Requirement: Why ESP32?

**YES.** The ESP32 is mandatory because: 
1. **Dual-Core Architecture:** One core handles the wireless stacks 
(Web Server/Bluetooth) while the other manages motor control and 
sensor polling.
2. **Connectivity:** Built-in Wi-Fi and Bluetooth are essential for the multi-interface control system (Phone/PS5).

</details>

<details>
<summary><h3>Setup & Control</summary></h3>
## Setup Phase

    1. Power on the Rover and the Cannon modules.

    2. On your smartphone/tablet, connect to the Wi-Fi network: 
    "STEALTH_UNIT_X1" (Password: 12345678).

    3. Open a web browser and navigate to 192.168.4.1.

## Controls
| Action | Web Interface Button |
|:---|:---|
| **Move Forward/Back** | `Front` / `Down` |
| **Steer Left/Right** | `Left` / `Right` |
| **Load/Reset Piston** | `Toggle Servo (90°)` |
| **Launch Disc** | **`ENGAGE CANNON`** |
| **Stop/Safety** | `Disarm / Stop Fire` |
</details>

<details>
<summary><h3>Photos</summary></h3>
</details>

<details>
<summary><h3>Videos</summary></h3>
</details>
