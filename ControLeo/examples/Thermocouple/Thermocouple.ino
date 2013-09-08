/*
 ControLeo Library - Thermocouple
 
 The thermocouple uses MAX31855 to read the temperature of the probe attached
 to ControLeo using the screw terminals.  
 
 Note:  If you connect the thermocouple probe the wrong way around, the
 temperature will go up instead of down (and vice versa).  No problem, just
 reverse the terminals.
 
 ControLeo uses SCK, MISO and D8 to communicate with the MAX31855 IC.
 
 The thermocouple is able to read temperatures over a large range: -270°C to +1372°C
 Datasheet:
 http://datasheets.maximintegrated.com/en/ds/MAX31855.pdf
 
 Credit goes to RocketScream.com for developing the initial version of the
 MAX31855 library.
 http://www.rocketscream.com/blog/2012/07/24/updated-max31855-library-for-arduino/
 
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
  
  lcd.print("Temperature:");
  
  // Create the degree symbol for the LCD
  lcd.createChar(0, degree);
}


void loop() {
  // Read the temperature in Celcius
  double currentTemperature = thermocouple.readThermocouple(CELSIUS);
  // Display the temperature on the left of the screen
  displayTemperature(currentTemperature, "C", 0);
  
  // Read the temperature in Farenheit
  currentTemperature = thermocouple.readThermocouple(FAHRENHEIT);
  // Display the temperature on the left of the screen
  displayTemperature(currentTemperature, "F", 8);
  
  // Wait a bit before taking the next reading
  delay(250);
}


// Display the temperature at the given location on the screen
void displayTemperature(double temperature, char* scale, int column) 
{
  if (temperature == FAULT_OPEN || temperature == FAULT_SHORT_GND || temperature == FAULT_SHORT_VCC) {
    lcd.setCursor(0, 1);
    if (temperature == FAULT_OPEN)
      lcd.print("Fault: Open     ");
    else if (temperature == FAULT_SHORT_GND)
      lcd.print("Fault: Short GND");
    else if (temperature == FAULT_SHORT_VCC)
      lcd.print("Fault: Short VCC");
  } else {
    // Print current temperature
    lcd.setCursor(column, 1);
    lcd.print(temperature);
    // Print degree symbol
    lcd.write((uint8_t)0);
    lcd.print(scale);
    lcd.print(" ");
  }
}


