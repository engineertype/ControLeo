// Written by Peter Easton
// Released under WTFPL license
//
// Change History:
// 6 September 2013        Initial Version

#ifndef CONTROLEO_MAX31855_H
#define CONTROLEO_MAX31855_H

#include "Arduino.h"

#define	FAULT_OPEN		10000
#define	FAULT_SHORT_GND	10001
#define	FAULT_SHORT_VCC	10002

enum	unit_t
{
	CELSIUS,
	FAHRENHEIT
};

class	ControLeo_MAX31855
{
public:
    ControLeo_MAX31855(void);
	
    double	readThermocouple(unit_t	unit);
    double	readJunction(unit_t	unit);
    
private:
    unsigned long readData();
};
#endif  // CONTROLEO_MAX31855_H