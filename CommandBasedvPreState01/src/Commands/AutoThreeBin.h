#ifndef AutoThreeBin_H
#define AutoThreeBin_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoThreeBin: public CommandGroup
{
private:
	const static int DISTANCE_CLOSE_TO_WALL = 360;
	const static int DISTANCE_END = 1650;
public:
	AutoThreeBin(bool ramp=false);
};

#endif
