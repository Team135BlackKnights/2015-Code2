#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	Joystick* sticks[2]; //0 is Left, 1 is Right
	JoystickButton* buttons[2][12];
public:
	static int LEFT = 0;
	static int RIGHT = 1;
	static const int BUTTON = 2;
	static const int MAX_JOYSTICK_BUTTONS = 17;
	static const int BUTTON_CLAW_OPEN_CLOSE = 15;
	static const int BUTTON_LEFTY_FLIP = 12;

	OI();
	float GetStickX(int=RIGHT);
	float GetStickY(int=RIGHT);
	float GetStickTwist(int=RIGHT);
	void LeftyFlip();
};

#endif
