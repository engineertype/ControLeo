/*
  ControLeo Library - Serial Input
 
 Demonstrates the use a 16x2 LCD display.  
 
 This sketch displays text sent over the serial port 
 (e.g. from the Serial Monitor) on an attached LCD.
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
modified 25 July 2009
 by David A. Mellis
 modified 17 July 2013 to work with ControLeo
 by Peter Easton
 
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// Include the library code
#include "Wire.h"
#include "ControLeo.h"

// Initialize the lcd
ControLeo_LiquidCrystal lcd;

void setup(){
    // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      lcd.write(Serial.read());
    }
  }
}
