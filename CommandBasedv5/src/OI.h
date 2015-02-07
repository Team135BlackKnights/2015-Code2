#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
public:
	static const int MAX_JOYSTICK_BUTTONS = 20;
	Joystick* sticks[3]; //0 is Left, 1 is Right
	JoystickButton* buttons[3][MAX_JOYSTICK_BUTTONS + 1];

public:
	int LEFT = 0;
	int RIGHT = 1;
	static const int BUTTON = 2;
	bool flipped = false;

	static const int BUTTON_OPEN_CLOSE_CLAW = 15;
	static const int BUTTON_HINGE_CLAW = 13;
	static const int BUTTON_LEFTY_FLIP = 12;
	static const int BUTTON_RUN_WINCH_UNTIL_STOPPED = 9;

	OI();
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	bool GetButton(int stick, int);
	void LeftyFlip();
};

#endif
