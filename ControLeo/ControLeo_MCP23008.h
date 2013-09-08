// Written by Peter Easton
// Released under WTFPL license
//
// Change History:
// 6 September 2013        Initial Version

#ifndef CONTROLEO_MCP23008_H
#define CONTROLEO_MCP23008_H

class ControLeo_MCP23008 {
public:
    void begin(void);
    void digitalWrite(uint8_t p, uint8_t d);
    uint8_t readGPIO(void);
    void writeGPIO(uint8_t gpio);

    private:
        uint8_t _gpio;
};

#define MCP23008_ADDRESS 0x20

// Registers
#define MCP23008_IODIR 0x00
#define MCP23008_GPIO  0x09

#endif // CONTROLEO_MCP23008_H
