#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>
#include <SoftwareSerial.h>
#include <RTClib.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc(pn532_i2c);
RTC_DS1307 rtc;
SoftwareSerial sim800L(10, 11);  // RX, TX
int buzzer = 8;

void setup() {
  Serial.begin(9600);
  sim800L.begin(9600);
  lcd.begin();
  lcd.backlight();
  nfc.begin();
  rtc.begin();
  pinMode(buzzer, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("RFID Attendance");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Scan Your Card");
  
  if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    String uid = tag.getUidString();

    DateTime now = rtc.now();
    String date = String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
    String time = String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());

    lcd.clear();
    lcd.print("ID: ");
    lcd.print(uid);
    lcd.setCursor(0, 1);
    lcd.print("Access Granted");
    tone(buzzer, 1000, 300);

    Serial.println(uid + "," + date + "," + time + ",Present");
    
    // Send SMS
    sim800L.println("AT+CMGF=1");
    delay(1000);
    sim800L.println("AT+CMGS=\"+91XXXXXXXXXX\"");
    delay(1000);
    sim800L.print("Attendance marked for ID: " + uid + " on " + date + " at " + time);
    sim800L.write(26);
    delay(1000);
  }
  delay(1000);
}
