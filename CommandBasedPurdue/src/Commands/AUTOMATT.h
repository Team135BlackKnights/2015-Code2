#ifndef AUTOMATT_H
#define AUTOMATT_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AUTOMATT: public CommandGroup
{
public:
	AUTOMATT();
	static const int DISTANCE_END = 330;//354
	static const int DISTANCE_RAMP = 157;
	static const int DISTANCE_BIN = 65;
	//Distance in Centimeters
};

#endif
