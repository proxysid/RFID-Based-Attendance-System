# RFID-Based-Attendance-System
This project aims to develop an RFID-based attendance system integrated with a GSM module (SIM800L) to send SMS notifications to predefined numbers. The system uses an RFID reader to scan RFID cards or tags. Each card has a unique ID associated with a particular person (e.g., a student or employee). When an RFID tag is scanned, the system records the attendance and automatically sends an SMS to a specified phone number (e.g., the parent's or manager's number) using the SIM800L GSM module. The system is based on the Arduino UNO, which serves as the central controller for handling RFID data and communicating with the GSM module.

Components Required:

Arduino UNO

RC522 RFID Module

SIM800L GSM Module


16x2 LCD Display (Optional for displaying status)

Buzzer (Optional for sound alerts)

LEDs (Optional for indicating status)

RFID Tags or Cards

Breadboard and jumper wires


Power supply for SIM800L (can be powered via a separate 4V source)


Working:

RFID Module: When the RFID card/tag is placed near the RFID reader (RC522), the reader scans the card and sends the unique ID to the Arduino.

Attendance Logging: Arduino checks the scanned RFID tag and marks the attendance by matching the card ID with stored IDs.


SMS Notification: Once attendance is marked, the Arduino sends a message via the SIM800L GSM module to notify a predefined phone number that the cardholder has been marked present.

LCD Display & Buzzer: An optional LCD can display messages such as "Attendance marked" and the name associated with the RFID card, and the buzzer can give an audible signal when attendance is successfully recorded.
