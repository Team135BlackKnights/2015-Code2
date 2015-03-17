#ifndef AutoMoveBinToAutoZoneRamp_H
#define AutoMoveBinToAutoZoneRamp_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoMoveBinToAutoZoneRamp: public CommandGroup
{
private:
	static const int DISTANCE_ANALOG_LIDAR = 3000;
	static const int DISTANCE_END = 354;
	static const int DISTANCE_RAMP = 157;
	static const int DISTANCE_BIN = 65;
public:
	AutoMoveBinToAutoZoneRamp();
};

#endif
