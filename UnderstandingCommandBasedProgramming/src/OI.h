#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* stick;
	JoystickButton* buttons;
public:
	static const int MAX_JOYSTICK_BUTTONS = 12;
	OI();
	int GetStickX();
	int GetStickY();
	int GetStickZ();
};

#endif
