#ifndef AutoMoveBinToAutoZone_H
#define AutoMoveBinToAutoZone_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoMoveBinToAutoZone: public CommandGroup
{
public:
	AutoMoveBinToAutoZone();
	static const int DISTANCE_END = 354;
	static const int DISTANCE_RAMP = 157;
	static const int DISTANCE_BIN = 65;
};

#endif
