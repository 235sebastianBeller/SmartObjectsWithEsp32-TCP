 # Project SmartObjects_TCP

In this project we developed a system integrated by two intelligent devices (an ESP32 integrated with an ultrasonic sensor, controlled by an algorithm for measuring distances in intervals of 7 centimeters, and another ESP32 equipped with LEDs and an I2C LCD display, controlled by an algorithm for activating a sequence of LEDs and displaying three types of messages on the LCD) and a server that establishes communication with both devices through the TCP protocol, using an IEEE 802.11 network for the connection.

## Considerations:
 1. Install the arduino IDE 
 2. Install intelliJ IDE or other but with the java compiler included
 3. In the arduino IDE install the library  LCD-I2C by Frank Hafele https://github.com/hasenradball/LCD-I2C

## Changes:

1. In the class Main.java:
	- put your "YOUR_PORT_NUMBER"

2. The constants files in SmartObjects folder :
	- put your "WIFI_SSID" 
	- put your "WIFI_PASS"
	- put your "SERVER_ADDRESS" 