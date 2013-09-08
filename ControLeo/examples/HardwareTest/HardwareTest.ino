/*
 ControLeo Library - HardwareTest
 
 This is a very simple ControLeo hardware test.  It will display the temperature reading from the
 thermocouple, updated twice a second.  Pressing the top button will toggle the buzzer on and off.
 Pressing the bottom button will turn on the next relay output.
 
 Note:  If you connect the thermocouple probe the wrong way around, the temperature will go up
 instead of down (and vice versa).  No problem, just reverse the terminals.
 
 Released under WTFPL license.
 
 17 July 2013 by Peter Easton
 
*/

// Include the library code:
#include "Wire.h"
#include <ControLeo.h>

// Initialize the library
ControLeo_LiquidCrystal lcd;
ControLeo_MAX31855 thermocouple;


void setup() {
  // Degree symbol for LCD
  unsigned char degree[8]  = {140,146,146,140,128,128,128,128};
  
  // Set up the LCD's number of rows and columns: 
  lcd.begin(16, 2);
  
  // Write the initial message on the LCD screen
  lcd.print("Testing");
  lcd.setCursor(0, 1);
  lcd.print("Press buttons");
  
  // Create the degree symbol for the LCD
  lcd.createChar(0, degree);
  
  // Set up the relay outputs and turn them off
  // The relay outputs are on D4 to D7 (4 outputs)
  for (int i=4; i<8; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
}


void loop() {
  static int relay = 4;
  static int buzzer = LOW;
  
  // Read the temperature in Farenheit
  int currentTemperature = thermocouple.readThermocouple(FAHRENHEIT);
  // Display the temperature on the left of the screen
  displayTemperature(currentTemperature, "F");
  
  // See if a button has been pressed
  switch (getButton()) {
    case CONTROLEO_BUTTON_TOP:
      // Turn the buzzer on and off when the top button is pressed
      buzzer = 1 - buzzer;
      lcd.setBuzzer(buzzer);
      lcd.setCursor(0, 1);
      if (buzzer)
        lcd.print("Buzzer ON       ");
      else
        lcd.print("Buzzer OFF      ");
      break;
    case CONTROLEO_BUTTON_BOTTOM:
      // The bottom button turns on the next relay output
      digitalWrite(relay, LOW);
      if (++relay == 8)
        relay = 4;
      digitalWrite(relay, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Output:");
      lcd.print(relay);
      lcd.print("       ");
      break;
  }

  // Wait a bit before taking the next set of readings
  delay(50);
}


// Display the temperature at the given location on the screen
void displayTemperature(double temperature, char* scale) 
{
  lcd.setCursor(9, 0);
  if (temperature == FAULT_OPEN || temperature == FAULT_SHORT_GND || temperature == FAULT_SHORT_VCC)
    lcd.print("       ");
  else {
    // Print current temperature
    lcd.print(temperature);
    // Print degree symbol
    lcd.write((uint8_t)0);
    lcd.print(scale);
    lcd.print("  ");
  }
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

