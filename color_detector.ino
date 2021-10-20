#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);
String val;     // Data received from serial port

void setup() {
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Color Detector");
  lcd.setCursor(0,1);
  lcd.print("Color:");
}

void loop() {
  if (Serial.available()) {
    // If data is available to read,
    val = Serial.readStringUntil('\n');
    val.trim();
    Serial.println(val);
  }
  else if (val == "red"){
    lcd.setCursor(6,1);
    lcd.print("red     ");
    
  }
  else if (val == "green"){
    lcd.setCursor(6,1);
    lcd.print("green     ");
  }
  else if (val == "blue"){
    lcd.setCursor(6,1);
    lcd.print("blue     ");
  }
  
}
