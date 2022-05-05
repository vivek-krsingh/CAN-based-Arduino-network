# CAN-based-Arduino-network

**1. Introduction to CAN protocol**
CAN-BUS is a common industrial bus developed by Robert Bosch GmbH. It is extensively used in industries because of its long travel distance, medium communication speed and high reliability. It is commonly found on modern machine tools and as an automotive diagnostic bus. The network's  implementation cost, performance, and upgradeability provide for tremendous flexibility in system design. The data transfer rates of the network are highly dependent on the wire length as it varies between 1 Mbps for upto 40 meters to 50 Kbps for upto 1000 meters. The protocol makes use of only two wires for the data transfer, which is usually encoded on the physical medium in terms of the potential difference between the two wires.    

**2. Project Overview**
The project illustrates an implementation of the CAN protocol using Arduino development boards. The implementation is divided into two parts: CAN node 1 and CAN node 2. The Node 1 will be programmed to work as a the Sensor/transmitter unit, while the other Node 2 will work as the Display/Reciever unit. The project aims to implement a native parking assistance system over CAN.

NODE_1
The transmitter unit uses an ultrasonic sensor which sends an ultrasonic pulse towrards the object, which upon hitting the it is reflected back to the sensor. The time duration between the outward pulse and the reflected pulse is used to calculate the distance between the sensor and the object, by the AT328p microcontroller powered developement board. The microcontroller then send this data to the reciever node via the CAN connection.

NODE_2
The reciever unit receives this distance infomation over CAN and displays the user with a prompt on the LCD screen showing the distance of the sensor(vehicle) to the user. The infomration can also be shared over SPI to another program/system to perform additional calculations.

**3. Schematics**

**4. Requirements**
The requirements for the successful implementation of this project are as listed below:

HARDWARE:
2x Arduino Uno
1x 10k Potentiometer
1x Ultrasonic Sensor HC-SR04
1x Beeper 780-0712
1x LCD Display (16x2)
2x CAN modules MCP2515 

  Wires and others:
  
  Node_1: 
  11x M-F Jumper wire
  13x M-M Jumper wire
  1x Breadboard
  1x USB 2.0 Cable Type A/B
  
  Node_2: 
  12x M-F Jumper wire
  9x M-M Jumper wire
  1x Breadboard
  1x USB 2.0 Cable Type A/B
  
  Overall:
  
 | Component | Arduino Uno | 10k Potentiometer | Ultrasonic Sensor HC-SR04 | Beeper 780-0712 | LCD Display (16x2) | CAN modules MCP2515 | M-F Jumper wire | M-M Jumper wire | Breadboard | USB 2.0 Cable Type A/B |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Count | 2x | 1x | 1x | 1x | 1x | 2x | 23x | 22x | 2x | 2x |
  
| Attempt | #1 | #2 | #3 | #4 | #5 | #6 | #7 | #8 | #9 | #10 | #11 | #12 |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| Seconds | 301 | 283 | 290 | 286 | 289 | 285 | 287 | 287 | 272 | 276 | 269 | 254 |

SOFTWARE:
Arduino IDE
