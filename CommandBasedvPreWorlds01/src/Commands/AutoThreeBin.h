#ifndef AutoThreeBin_H
#define AutoThreeBin_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoThreeBin: public CommandGroup
{
public:
	const static int DISTANCE_CLOSE_TO_WALL = 450;
	const static int DISTANCE_END = 1575;//1600;//1650;
public:
	AutoThreeBin(bool ramp=false);
};

#endif
