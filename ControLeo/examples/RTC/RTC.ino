/*
 ControLeo Library - RTC
 
 ControLeo has an optional Real-Time Clock, connected to the microcontroller using the I2C bus.
 
 Released under WTFPL license. 
 
 17 July 2013 by Peter Easton
 
*/

// Include the library code:
#include "Wire.h"
#include <ControLeo.h>
#include "RTClib.h"

// Initialize the library
ControLeo_LiquidCrystal lcd;

RTC_DS1307 RTC;
char *months[] = {"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
char *nameOfDay[] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"}; 

void setup() {
  // Set up the LCD's number of rows and columns
  lcd.begin(16, 2);
  
  RTC.begin();
  if (! RTC.isrunning()) {
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}

void loop() {
  // Get the date & time from the RTC
  DateTime now = RTC.now();
    
  // Display the time on the top line
  lcd.setCursor(0,0);
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  if (now.minute() < 10)
    lcd.print("0");
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  if (now.second() < 10)
    lcd.print("0");
  lcd.print(now.second(), DEC);
  // Add a space to orverwite the last digit if there is time shrinkage
  lcd.print(' ');

  // Display the date on the 2nd line
  lcd.setCursor(0,1);
  lcd.print(nameOfDay[now.dayOfWeek()]);
  lcd.print(' ');
  lcd.print(now.day(), DEC);
  lcd.print(' ');
  lcd.print(months[now.month()]);
  lcd.print(' ');
  lcd.print(now.year(), DEC);
  // Add a space to orverwite the last digit if there is date shrinkage
  lcd.print(' ');

  delay(1000);
}


