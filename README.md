# CAN-based-Arduino-network

**1. Introduction to CAN protocol:**
CAN-BUS is a common industrial bus developed by Robert Bosch GmbH. It is extensively used in industries because of its long travel distance, medium communication speed and high reliability. It is commonly found on modern machine tools and as an automotive diagnostic bus. The network's  implementation cost, performance, and upgradeability provide for tremendous flexibility in system design. The data transfer rates of the network are highly dependent on the wire length as it varies between 1 Mbps for upto 40 meters to 50 Kbps for upto 1000 meters. The protocol makes use of only two wires for the data transfer, which is usually encoded on the physical medium in terms of the potential difference between the two wires.    

**2. Project Overview:**
The project illustrates an implementation of the CAN protocol using Arduino development boards. The implementation is divided into two parts: CAN node 1 and CAN node 2. The Node 1 will be programmed to work as a the Sensor/transmitter unit, while the other Node 2 will work as the Display/Reciever unit. The project aims to implement a native parking assistance system over CAN.

NODE_1
The transmitter unit uses an ultrasonic sensor which sends an ultrasonic pulse towrards the object, which upon hitting the it is reflected back to the sensor. The time duration between the outward pulse and the reflected pulse is used to calculate the distance between the sensor and the object, by the AT328p microcontroller powered developement board. The microcontroller then send this data to the reciever node via the CAN connection.

NODE_2
The reciever unit receives this distance infomation over CAN and displays the user with a prompt on the LCD screen showing the distance of the sensor(vehicle) to the user. The infomration can also be shared over SPI to another program/system to perform additional calculations.

**3. Schematics:**
![Schematic](https://user-images.githubusercontent.com/60755502/171505002-d8b7d41a-73ef-447f-8901-f51b88e7778c.jpg)

**4. Pinout Connections:**

|  **ARDUINO_T**  |  **Transmitter** |   |  **Reciever** |          **ARDUINO_R**          |
|:---------------:|:----------------:|:-:|:-------------:|:-------------------------------:|
|                 |                  |   |               |                                 |
|   **HC-SR04**   |                  |   |               |            **Beeper**           |
|       ECHO      |        D2        |   |     BLACK     |               GND               |
|       TRIG      |        D3        |   |      RED      |                8                |
|       VCC       |        +5V       |   |               |                                 |
|       GND       |        GND       |   |               |                                 |
|                 |                  |   |               |                                 |
|   **MCP2515**   |                  |   |               |           **MCP2515**           |
| MPC2515 -   VCC |        +5V       |   | MPC2515 - VCC |               +5V               |
|  MPC2515 - GND  |        GND       |   | MPC2515 - GND |               GND               |
|   MPC2515 - CS  |  D10   (SPI_SS)  |   |  MPC2515 - CS |          10   (SPI_SS)          |
|   MPC2515 - SO  | D12   (SPI_MISO) |   |  MPC2515 - SO |         12   (SPI_MISO)         |
|  MPC2515 - S I  | D11   (SPI_MOSI) |   |  MPC2515 - SI |         11   (SPI_MOSI)         |
|  MPC2515 - SCK |  D13   (SPI_SCK) |   | MPC2515 - SCK |          13   (SPI_SCK)         |
|  MPC2515 - INT  |        D8        |   | MPC2515 - INT |                2                |
|                 |                  |   |               |                                 |


**5. Requirements:**
The requirements for the successful implementation of this project are as listed below:

HARDWARE:
  
| Component                 | Count |
|---------------------------|-------|
| Arduino Uno               | 2x    |
| Ultrasonic Sensor HC-SR04 | 1x    |
| Beeper 780-0712           | 1x    |
| CAN modules MCP2515       | 2x    |
| M-F Jumper wire           | 14x   |
| M-M Jumper wire           | 14x   |
| Breadboard                | 2x    |
| USB 2.0 Cable Type A/B    | 2x    |



SOFTWARE: Arduino IDE

**6. Final:**
Final System:
![Prototype](https://user-images.githubusercontent.com/60755502/171520653-b2894668-2684-4d6a-87c1-edf801a64ab8.jpeg)

Working Video:
https://user-images.githubusercontent.com/60755502/171520833-966b87b0-16f8-4f23-b458-fb9fac9009fe.mp4
