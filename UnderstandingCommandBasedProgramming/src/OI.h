#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* stick;
public:
	OI();
	int GetStickX();
	int GetStickY();
	int GetStickZ();
};

#endif
