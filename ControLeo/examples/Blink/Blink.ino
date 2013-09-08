/*
  ControLeo Library - Blink
 
 Demonstrates the use a 16x2 LCD display. 
 
 This sketch prints "Hello World!" to the LCD and makes the 
 cursor block blink.
 
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

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // Turn off the blinking cursor:
  lcd.noBlink();
  delay(3000);
   // Turn on the blinking cursor:
  lcd.blink();
  delay(3000);
}


