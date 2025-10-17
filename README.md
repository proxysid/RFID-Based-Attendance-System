# RFID Based Attendance System with SMS Notification

## Overview

The **RFID Based Attendance System with SMS Notification** is an efficient and automated attendance management solution designed to simplify record-keeping in educational and organizational environments. This project enhances the traditional RFID-based attendance mechanism by integrating an SMS notification feature using the **SIM800L GSM module**, allowing instant alerts to be sent when attendance is marked.

## Description

This system is developed using **Arduino IDE** and incorporates hardware components such as **ESP32**, **RFID reader**, **SIM800L GSM module**, and **RTC (Real-Time Clock) module**. Each student, faculty, or staff member is assigned a unique RFID tag. When the tag is placed near the reader, it transmits its unique identification number (UIN), which is captured and processed by the ESP32 microcontroller.

The system:

* Marks attendance automatically
* Stores data in an **Excel sheet** for easy tracking and analysis
* Sends an **SMS notification** to a predefined mobile number confirming attendance
* Utilizes an **RTC module** to timestamp each attendance entry accurately

This setup ensures quick, reliable, and paperless attendance management while keeping parents or administrators informed in real time.

## Features

* **Automated Attendance Logging:** RFID tags are scanned instantly without manual roll-calls.
* **Real-Time SMS Alerts:** Uses the SIM800L module to send SMS notifications upon successful attendance marking.
* **Accurate Time Stamping:** The RTC module provides precise date and time for each attendance entry.
* **Data Storage:** Attendance data is recorded and stored in an Excel file via Arduino IDE serial communication.
* **Error Handling:** Provides user feedback for invalid tags or communication errors.

## Components Used

* ESP32 Microcontroller
* RFID Reader Module (RC522)
* RFID Tags/Cards
* SIM800L GSM Module
* RTC Module (DS3231 or similar)
* 16x2 LCD Display
* Jumper Wires and Breadboard
* Power Supply

## Tech Stack

* **Arduino IDE** – for code development and serial communication
* **SIM800L** – for GSM-based SMS notification
* **ESP32** – as the main controller for RFID and GSM communication
* **RTC Module** – for maintaining accurate date and time records
* **Excel (via PLX-DAQ)** – for attendance data storage and visualization

## Working Principle

1. Each RFID tag has a unique identification number stored in the system database.
2. When the RFID tag is brought near the reader, it sends the tag’s UIN to the ESP32 microcontroller.
3. The ESP32 verifies the ID, records attendance with a timestamp, and logs it into an Excel sheet.
4. The SIM800L module sends an SMS notification indicating successful attendance marking.
5. The LCD displays confirmation messages and real-time system updates.

## Advantages

* Fully automated and paperless attendance management
* Real-time SMS notifications for transparency
* Reliable and timestamped attendance data
* Easy report generation through Excel
* Suitable for schools, colleges, and workplaces

## Future Enhancements

* Integration with cloud databases for remote monitoring
* Development of a web-based dashboard for attendance visualization
* Implementation of biometric or face-recognition verification
* IoT-based data synchronization for centralized access

## Conclusion

The **RFID Based Attendance System with SMS Notification** provides a seamless, real-time, and automated solution for managing attendance. By leveraging **ESP32**, **SIM800L**, and **RTC modules**, the system ensures accuracy, efficiency, and instant communication—revolutionizing attendance management in academic and professional institutions.

---

**Language:** C/C++ (Arduino IDE)
