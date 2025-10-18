#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

// Initialize LCD and PN532
LiquidCrystal_I2C lcd(0x27, 16, 2);
PN532_I2C pn532_i2c(Wire);
NfcAdapter nfc(pn532_i2c);

// Structure to hold student details
struct Student {
  String uid;
  String name;
  String roll;
};

// Example database (you can expand this list)
Student students[] = {
  {"04A3F27B", "Amit Sharma", "E21EC001"},
  {"93B1C45E", "Siddharth Prabhakar", "E21EC002"},
  {"7A2D915C", "Riya Patel", "E21EC003"},
  {"B86F4E2A", "Rahul Kumar", "E21EC004"}
};

int totalStudents = sizeof(students) / sizeof(students[0]);

void setup() {
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
  nfc.begin();

  lcd.setCursor(0, 0);
  lcd.print("RFID UID Reader");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");
  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Scan your card");

  if (nfc.tagPresent()) {
    NfcTag tag = nfc.read();
    String uid = tag.getUidString();
    uid.replace(" ", ""); // remove spaces if any

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("UID:");
    lcd.setCursor(4, 0);
    lcd.print(uid);
    delay(1000);

    bool found = false;

    for (int i = 0; i < totalStudents; i++) {
      if (uid.equalsIgnoreCase(students[i].uid)) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(students[i].name);
        lcd.setCursor(0, 1);
        lcd.print("Roll:");
        lcd.print(students[i].roll);

        Serial.println("UID: " + uid);
        Serial.println("Name: " + students[i].name);
        Serial.println("Roll No: " + students[i].roll);
        Serial.println("---------------------");

        found = true;
        break;
      }
    }

    if (!found) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Unknown Card");
      lcd.setCursor(0, 1);
      lcd.print("Please Register");
      Serial.println("Unregistered UID: " + uid);
      Serial.println("---------------------");
    }

    delay(3000);
    lcd.clear();
  }

  delay(500);
}
