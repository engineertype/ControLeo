/*
  ControLeo Library - setCursor
 
 Demonstrates the use a 16x2 LCD display.  
 
 This sketch prints to all the positions of the LCD using the
 setCursor(0 method:
 
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

// these constants won't change.  But you can change the size of
// your LCD using them:
const int numRows = 2;
const int numCols = 16;

void setup() {
  // set up the LCD's number of rows and columns: 
  lcd.begin(numRows, numCols);
}

void loop() {
  // loop from ASCII 'a' to ASCII 'z':
  for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
    // loop over the columns:
    for (int thisCol = 0; thisCol < numRows; thisCol++) {
      // loop over the rows:
      for (int thisRow = 0; thisRow < numCols; thisRow++) {
        // set the cursor position:
        lcd.setCursor(thisRow,thisCol);
        // print the letter:
#if ARDUINO >= 100
        lcd.write(thisLetter);
#else
        lcd.print(thisLetter, BYTE);
#endif
        delay(200);
      }
    }
  }
}


