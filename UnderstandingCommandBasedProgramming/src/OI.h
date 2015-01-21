#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* stick;
	JoystickButton* buttons[12];
public:
	static const int MAX_JOYSTICK_BUTTONS = 12;
	OI();
	float GetStickX();
	float GetStickY();
	float GetStickZ();
};

#endif
