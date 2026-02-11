## Final Project: Stealth Unit X1 

This repository contains the Final Project created for the **Introduction to Robotics** course during the 2025-2026 academic year at the Faculty of Mathematics and Informatics, University of Bucharest, Computer Science domain. 


### Team Members: 
- https://github.com/iulia1603
- https://github.com/MitzaaA14

<details>
<summary><h3>Project Description</summary></h3>

### Project General Description

 - STEALTH UNIT X1 is a modular robotic ecosystem designed for tactical movement and projectile deployment -> A disc
  <img width="643" height="449" alt="Screenshot 2026-02-11 at 23 21 17" src="https://github.com/user-attachments/assets/e7bd9b36-a01a-4870-b87e-0042eafd5ee8" />
 - The system utilizes a Master-Slave architecture, where a mobile Rover (Master) hosts a Web Server for user control and communicates via the low-latency ESP-NOW protocol with a secondary Launcher unit (Slave).

### System Architecture
    
 - The robot is divided into two intelligent nodes to optimize power distribution and processing:

    1. Master Node (The Rover): 
        - Creates a Wi-Fi Access Point and hosts an interactive Web Dashboard.

        - Manages locomotion using dual DC motors.

        - Controls a Servo-based feeding mechanism.

        - Relays firing commands to the Slave unit.

    2. Slave Node (The Cannon): 
        - Listens for encrypted ESP-NOW packets.

        - Controls the high-speed dual-flywheel propulsion system for disc launching.

### B. Bill Of Materials (BOM)

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

### Mechanical Design & Fabrication

The robot features a Tri-Hybrid Construction approach:

1. The Base: A standard 2WD Smart Car Chassis provides the structural integrity for the wheels and primary gearmotors.

2. The Hull: Custom-cut panels from Hobbycolor (Black PVC) were used to build the vertical structure. This allowed for a lightweight yet rigid "stealth" aesthetic.

3. The Modules: 3D-printed modular housings were bolted to the PVC walls to securely hold the ESP32 boards and the complex flywheel launcher mechanism.

### Q1 - What is the system boundary? 

The boundary includes the user's mobile interface, the Wi-Fi control link, and the internal ESP-NOW telemetry between the Rover's chassis and the Cannon's firing logic.

### Q2 - Where does intelligence live? 

Intelligence is distributed. The Master node handles the UI and navigation logic, while the Slave node handles the high-speed execution timing for the launcher flywheels.

### Q3 - What is the hardest technical problem? 

Ensuring the 3D-printed launcher remained stable when mounted to the PVC walls, especially during the high-RPM spin-up of the flywheels.

### Q4 - What is the minimum demo? 

Powering the unit, connecting to the "STEALTH_UNIT_X1" network, and successfully navigating a course to fire a disc into a target using only the web dashboard.

### Q5 - Why is this not just a tutorial? 

It combines pre-built robotics hardware (2WD Chassis) with custom fabrication (PVC cutting) and advanced wireless networking (ESP-NOW + WebServer) into a unique, integrated tactical system.

### Power Distribution & Electronics
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

### Power Evolution: From AA to Li-Po

During the initial prototyping phase, the system was powered by standard AA batteries. However, we quickly encountered significant performance issues that led to a complete redesign of the power delivery system:

The Problem with AA Batteries:
    
    - Voltage Sag: When the flywheel motors started, the voltage would drop significantly (voltage sag), causing the ESP32 to brown out and reset.

    - Low Discharge Rate: AA batteries could not provide the high instantaneous current (Amperage) required by the high-RPM launcher motors.

    - Weight vs. Power: The weight of 6-8 AA batteries hindered the rover's agility without providing sufficient runtime.

The Li-Po Solution:

    - We switched to a triple Li-Po configuration (as detailed in the Power Distribution section). This provided:

        - High C-Rating: Li-Po batteries handle high current bursts effortlessly, allowing the flywheels to reach maximum RPM in seconds.

        - Consistent Voltage: With dedicated batteries for logic and motors, the ESP32 remains stable even during heavy combat sequences.

Weight Efficiency: A significant reduction in weight while doubling the power output.

### Implementation Details
Master-Slave Synchronization
- The two ESP32 units communicate using the ESP-NOW protocol. This is a connectionless communication developed by Espressif that allows for near-instantaneous triggers.

Latency: <10ms (Ideal for a firing mechanism).

Reliability: The Slave unit is hardcoded to respond only to the Master's unique MAC address.

Software Steering Calibration

- Standard DC motors rarely spin at the exact same RPM. To ensure 
STEALTH UNIT X1 moves in a straight line, we implemented a 
software-side correction in the PWM mapping.


### Technical Requirement: Why ESP32?

**YES.** The ESP32 is mandatory because: 
1. **Dual-Core Architecture:** One core handles the wireless stacks 
(Web Server/Bluetooth) while the other manages motor control and 
sensor polling.
2. **Connectivity:** Built-in Wi-Fi and Bluetooth are essential for the multi-interface control system (Phone/PS5).

</details>

<details>
<summary><h3>Setup & Control</summary></h3>

### Setup Phase

    1. Power on the Rover and the Cannon modules.

    2. On your smartphone/tablet, connect to the Wi-Fi network: 
    "STEALTH_UNIT_X1" (Password: 12345678).

    3. Open a web browser and navigate to 192.168.4.1.

### Controls
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

<details>
<summary><h4>Motor Driver:</h4></summary> 
<img width="667" height="637" alt="Screenshot 2026-02-11 at 23 14 59" src="https://github.com/user-attachments/assets/9a6342b0-9bc0-471e-9706-5ca1bd02c78a" />
</details>

<details>
<summary><h4>Robot Chassis:</h4></summary> 
 
<img width="388" height="329" alt="Screenshot 2026-02-11 at 23 15 16" src="https://github.com/user-attachments/assets/1a84e039-d43f-40c0-9e2e-9024f8faa732" />
<img width="426" height="383" alt="Screenshot 2026-02-11 at 23 15 32" src="https://github.com/user-attachments/assets/993d65f7-b931-4613-8cf4-ba5f570d0e37" />

</details>

<details>
 <summary><h4>Robot with 20AA Batteries:</h4></summary> 
 <img width="426" height="402" alt="Screenshot 2026-02-11 at 23 15 46" src="https://github.com/user-attachments/assets/b09ebccf-06f1-4b39-9022-749727509304" />
 
</details>

<details>
<summary><h4>Final Robot</h4></summary>
<img width="404" height="458" alt="Screenshot 2026-02-11 at 23 03 02" src="https://github.com/user-attachments/assets/ecfce34c-dbc9-43a7-acc9-4e40e634e771" />
<img width="427" height="618" alt="Screenshot 2026-02-11 at 23 03 35" src="https://github.com/user-attachments/assets/459b3833-aa36-4b44-91fc-4d0cb227b001" />
<img width="427" height="618" alt="Screenshot 2026-02-11 at 23 03 28" src="https://github.com/user-attachments/assets/87b75462-936d-4a8f-9bac-9a2e041fc9b1" />
<img width="427" height="525" alt="Screenshot 2026-02-11 at 23 03 20" src="https://github.com/user-attachments/assets/276bc0dd-7d9d-4c8a-aa74-1bd4d53d5143" />
<img width="404" height="496" alt="Screenshot 2026-02-11 at 23 03 11" src="https://github.com/user-attachments/assets/8e6732bf-0838-4282-958c-3e0c35b7aec3" />
</details>
</details>

<details>
<summary><h3>Videos</summary></h3>
 YouTube videos :

 1. https://youtu.be/38yWScA7Rz4?si=H7MG9lgyABFWA_h6
 2. https://youtu.be/lW564rpEUHY?si=BtgbWGYXQlxbuAaB
    
</details>
