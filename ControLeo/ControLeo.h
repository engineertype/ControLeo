// This library controls the functions of ControLeo
//  - LCD display and backlight
//  - Buzzer
//  - Thermocouple

// Written by Peter Easton
// Released under WTFPL license
//
// Change History:
// 6 September 2013        Initial Version

#ifndef CONTROLEO_H
#define CONTROLEO_H

#include "ControLeo_MCP23008.h"
#include "ControLeo_LiquidCrystal.h"
#include "ControLeo_MAX31855.h"


// Defines
#define CONTROLEO_BUTTON_PIN    A5
#define CONTROLEO_BUTTON_NONE   0
#define CONTROLEO_BUTTON_TOP    2   // S2
#define CONTROLEO_BUTTON_BOTTOM 3   // S3

#endif // CONTROLEO_H
