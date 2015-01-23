#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:
	Joystick* sticks[2]; //0 is Left, 1 is Right
	JoystickButton* buttons[2][12];
public:
	static const int LEFT = 0;
	static const int RIGHT = 1;
	static const int MAX_JOYSTICK_BUTTONS = 12;
	OI();
	float GetStickX(int=RIGHT);
	float GetStickY(int=RIGHT);
	float GetStickTwist(int=RIGHT);
};

#endif
