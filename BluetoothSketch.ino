#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>

String readString;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
  Serial.begin(9600);
  Serial.println("serial delimit test 1.0");
 
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
   lcd.print("Привет всем");

}
void loop()
{
   if (Serial.available())  {
    char c = Serial.read();  //gets one byte from serial buffer
    if (c == ',') {
      if (readString.length() >1) {
         lcd.clear();
        Serial.print(readString); //prints string to serial port out
        //do stuff with the captured readString 
        lcd.print(readString);
        readString=""; //clears variable for new input
      }
    }  
    else {     
      readString += c; //makes the string readString
    }
  }
}