# RFID Based Attendance System with SMS Notification

## Overview
The **RFID Based Attendance System with SMS Notification and Excel Logging** is a smart, automated IoT project designed to simplify attendance tracking. Using **RFID/NFC**, **SIM800L GSM**, and **Excel integration**, it not only records attendance automatically but also sends an **instant SMS notification** and **logs the data into an Excel sheet** via serial communication.

This system is built using the **ESP8266 NodeMCU**, **PN532 NFC module**, **16x2 I2C LCD**, **SIM800L GSM module**, **LM2596 step-down converter**, and a **buzzer** for feedback.

---

## Features
- Automatic attendance using RFID/NFC tags  
- Real-time SMS notification via GSM module  
- Live data logging to Excel using PLX-DAQ  
- LCD display showing attendance status  
- Buzzer indication for successful scans  
- Stable power regulation using LM2596  
- Compact, efficient, and low-cost system  

---

## Components and Connections

| Component | Description | Connected To (ESP8266 NodeMCU) |
|------------|--------------|--------------------------------|
| **PN532 NFC RFID Module** | Reads tag UID | SDA → D2, SCL → D1, VCC → 3.3V, GND → GND |
| **LCD Display (16x2 with I2C)** | Displays messages | SDA → D2, SCL → D1, VCC → 3.3V, GND → GND |
| **SIM800L GSM Module** | Sends SMS notifications | TX → D7 (RX), RX → D8 (TX), VCC → LM2596 output (~4V), GND → Common GND |
| **LM2596 Step-Down Converter** | Powers GSM module | Input → 5V source, Output → 4V to SIM800L |
| **Buzzer** | Feedback indicator | Positive → D6, Negative → GND |
| **RFID Tags** | Used for user identification | Communicates with PN532 wirelessly |

---

## Tech Stack
- **Microcontroller:** ESP8266 NodeMCU  
- **Programming IDE:** Arduino IDE  
- **Modules:** PN532, SIM800L GSM, LM2596  
- **Display:** 16x2 I2C LCD  
- **Data Logging:** Excel via PLX-DAQ  
- **Feedback:** Buzzer tone  

---

## Working Principle
1. The user scans their RFID tag on the PN532 reader.  
2. The ESP8266 identifies the tag and displays the user’s ID on the LCD.  
3. A buzzer beeps to confirm attendance.  
4. The SIM800L sends an SMS alert indicating the attendance status.  
5. Data (ID, Date, Time) is simultaneously sent to **Excel via PLX-DAQ** for storage.  

---

## Excel Logging Setup (PLX-DAQ)
1. Download **PLX-DAQ v2** (Excel plugin for serial data logging).  
2. Open Excel → Enable Macros → Open `PLX-DAQ Spreadsheet.xlsm`.  
3. Set your COM port (same as Arduino Serial Port).  
4. Start Data → Real-time attendance data will appear with **Name**, **Card ID**, **Date**, and **Time**.  

---

## Required Arduino Libraries
Install the following libraries via **Library Manager**:
- `Wire.h`
- `LiquidCrystal_I2C.h`
- `Adafruit_PN532.h`
- `SoftwareSerial.h`

---

## How to Run
1. Connect all components as per the circuit diagram below.  
2. Open Arduino IDE → Select **NodeMCU 1.0 (ESP-12E Module)**.  
3. Upload the code provided below.  
4. Open PLX-DAQ in Excel and connect it to the correct COM port.  
5. Scan RFID tags → Attendance will be displayed, logged in Excel, and SMS sent instantly.


---

## Future Enhancements
- Integration with online cloud storage (Firebase, Google Sheets)  
- Web dashboard for centralized attendance viewing  
- Face recognition for enhanced verification  
- Battery backup integration  

---

## Developed By
**Siddharth Chandra Prabhakar** <br>  
Final Year Undergraduate <br>
National Institute of Technology Sikkim <br>
**Tech Stack:** Arduino IDE, ESP8266, SIM800L, PN532, LCD (I2C), LM2596, Buzzer, Excel <br>  
**Language:** C/C++ (Arduino IDE)
