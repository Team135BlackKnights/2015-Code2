#ifndef AutoThreeBin_H
#define AutoThreeBin_H

#include "Commands/CommandGroup.h"
#include "WPILib.h"

class AutoThreeBin: public CommandGroup
{
private:
	const static int DISTANCE_CLOSE_TO_WALL = 475;
	const static int DISTANCE_END = 1600;
public:
	AutoThreeBin();
};

#endif
