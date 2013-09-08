// This is a library for the MCP23008 I2C port expander used on ControLeo
// The pin connections are as follows:
// GP0 - Buzzer
// GP1 - LCD RS
// GP2 - LCD E
// GP3 - LCD DB4
// GP4 - LCD DB5
// GP5 - LCD DB6
// GP6 - LCD DB7
// GP7 - LCD Backlight
//
// Written by Peter Easton
// Released under WTFPL license
//
// Change History:
// 6 September 2013        Initial Version

#include "Arduino.h"
#include <Wire.h>
#include "ControLeo_MCP23008.h"


void ControLeo_MCP23008::begin(void) {
    Wire.begin();

    // Set the MCP23008 defaults
    Wire.beginTransmission(MCP23008_ADDRESS);
    Wire.write((byte)MCP23008_IODIR);
    Wire.write((byte)0x00); // IODIR - All outputs
    Wire.write((byte)0x00); // IPOL - Register reflects pin polarity
    Wire.write((byte)0x00); // GPINTEN - Disable interrupts
    Wire.write((byte)0x00); // DEFVAL
    Wire.write((byte)0x00); // INTCON
    Wire.write((byte)0x00); // IOCON
    Wire.write((byte)0x00); // GPPU - No pull-up
    Wire.write((byte)0x00); // INTF - Clear interrupts
    Wire.write((byte)0x00); // INTCAP
    Wire.write((byte)0x00); // GPIO
    Wire.write((byte)0x00); // OLAT
    Wire.endTransmission();
    _gpio = 0;
}


// Write a HIGH or LOW to one of the GPIO pins
void ControLeo_MCP23008::digitalWrite(uint8_t p, uint8_t d) {
    if (p <= 7) {
        // Set the pin value
        if (d == HIGH)
            _gpio |= 1 << p;
        else
            _gpio &= ~(1 << p);

        // Write the new GPIO value
        writeGPIO(_gpio);
    }
}


// Read the current state of the pins.  Since all pins are outputs
// the stored state can be returned instead of reading the value
// from the MCP23008
uint8_t ControLeo_MCP23008::readGPIO(void) {
    return _gpio;
}


// Write the new values for all 8 GPIO pins
void ControLeo_MCP23008::writeGPIO(uint8_t gpio) {
    _gpio = gpio;
    // Write the new GPIO value
    Wire.beginTransmission(MCP23008_ADDRESS);
    Wire.write((byte) MCP23008_GPIO);
    Wire.write((byte) _gpio);
    Wire.endTransmission();
}
