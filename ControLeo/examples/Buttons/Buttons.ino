/*
 ControLeo Library - Buttons
 
 ControLeo has two buttons.  This example shows how to read the buttons
 (with debounce).  The buttons are conected to A5 and are pulled up with
 a 10K resistor (R11).
 
 When S2 is pressed A5 will read approximately 2.5V; when S3 is pressed
 A5 will read 0V.  Since Arduino has 10-bit analog-to-digital conversion
 the following values will be seen on A5:
 1. No buttons pressed = 1023
 2. S2 pressed = approx 512 (depends on resistor variance)
 3. S3 pressed = 0
 Note, if both S2 and S3 are pressed at the same time then A5 will see 0!
 
 Released under WTFPL license.
 
 17 July 2013 by Peter Easton
 
*/

// Include the library code:
#include "Wire.h"
#include <ControLeo.h>

// Initialize the library
ControLeo_LiquidCrystal lcd;

void setup() {
  // Set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  lcd.print("Top");
  lcd.setCursor(0, 1);
  lcd.print("Bottom");
  
  // The button is an input
  pinMode(CONTROLEO_BUTTON_PIN, INPUT);
}

void loop() {
  static int topCount=0, bottomCount=0;
  
  switch (getButton()) {
    case CONTROLEO_BUTTON_NONE:
      break;
    case CONTROLEO_BUTTON_TOP:
      topCount++;
      lcd.setCursor(13, 0);
      lcd.print(topCount);
      break;
    case CONTROLEO_BUTTON_BOTTOM:
      bottomCount++;
      lcd.setCursor(13, 1);
      lcd.print(bottomCount);
      break;
  }
  delay(10);
}


// Determine if a button was pressed (with debounce)
// A button can only be pressed once every 200ms. If a button is
// pressed and held, a button press will be generated every 200ms.
// Returns:
//   CONTROLEO_BUTTON_NONE if no button are pressed
//   CONTROLEO_BUTTON_S2 if the top button was pressed
//   CONTROLEO_BUTTON_S3 if the bottom button was pressed
// Note: If both buttons are pressed simultaneously, CONTROLEO_BUTTON_S3 will be returned
#define DEBOUNCE_INTERVAL  200

int getButton()
{
  static long lastChangeMillis = 0;
  long nowMillis = millis();
  int buttonValue;
  
  // If insufficient time has passed, just return none pressed
  if (lastChangeMillis + DEBOUNCE_INTERVAL > nowMillis)
    return CONTROLEO_BUTTON_NONE;
  
  // Read the current button status
  int pinValue = analogRead(CONTROLEO_BUTTON_PIN);
  
  // Interpret the value.  Allow for resistor variance
  if (pinValue < 100)
    buttonValue = CONTROLEO_BUTTON_BOTTOM;
  else if (pinValue > 900)
    buttonValue = CONTROLEO_BUTTON_NONE;
  else
    buttonValue = CONTROLEO_BUTTON_TOP;
  
  // Note the time the button was pressed
  if (buttonValue != CONTROLEO_BUTTON_NONE)
   lastChangeMillis = nowMillis;
  
  return buttonValue;
}









