#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	Joystick* sticks[2]; //0 is Left, 1 is Right
	JoystickButton* buttons[2][12];
public:
	int LEFT = 0;
	int RIGHT = 1;
	static const int BUTTON = 2;
	static const int MAX_JOYSTICK_BUTTONS = 17;

	static const int BUTTON_OPEN_CLOSE_CLAW = 15;
	static const int BUTTON_HINGE_CLAW = 14;
	static const int BUTTON_LEFTY_FLIP = 12;

	OI();
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	void LeftyFlip();
};

#endif
