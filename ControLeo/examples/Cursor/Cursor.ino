/*
  ControLeo Library - Cursor
 
 Demonstrates the use a 16x2 LCD display.  
 
 This sketch prints "Hello World!" to the LCD and
 uses the cursor()  and noCursor() methods to turn
 on and off the cursor.
 
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
  // Turn off the cursor:
  lcd.noCursor();
  delay(500);
   // Turn on the cursor:
  lcd.cursor();
  delay(500);
}

