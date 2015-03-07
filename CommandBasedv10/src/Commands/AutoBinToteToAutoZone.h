#ifndef AutoBinToteToAutoZone_H
#define AutoBinToteToAutoZone_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoBinToteToAutoZone: public CommandGroup
{
public:
	AutoBinToteToAutoZone();
	static const int DISTANCE_END = 354;
	static const int DISTANCE_RAMP = 157;
	static const int DISTANCE_BIN = 65;
};

#endif
