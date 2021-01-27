# Simple Automatic Door

A simple automatic door project created for an architectural robotics class I am taking. Will open a physical (scale model) door when the user is 5 cm from the door. A light is turned on to illuminate the front of our building when a user is within 15 cm. 

## Hardware

**Arduino mega 2560**: Not my microcontroller of choice. The mega is relatively large for the limited amount of GPIO needed here, and has no wireless capabilities for possible IoT implementation,  but the class requires we use it. 

**HC-SR04 Ultrasonic Sensor**: This is the sensor we used for calculating distance.

**5mm LED**: Classic simple LEDs you use with breadboarding.
