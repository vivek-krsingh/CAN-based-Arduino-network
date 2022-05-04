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

1x HC-SR04 Ultrasonic Sensor
1x LCD Display
2x MCP2515 CAN modules
