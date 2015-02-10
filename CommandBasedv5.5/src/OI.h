#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
protected:
	static const int NUMBER_O_JOYSTICKS = 4;
	static const int MAX_JOYSTICK_BUTTONS = 20;
	Joystick* sticks[NUMBER_O_JOYSTICKS]; //0 is Left, 1 is Right
	JoystickButton* buttons[NUMBER_O_JOYSTICKS][MAX_JOYSTICK_BUTTONS + 1];

	//JoystickButton* clawOpen;
	//JoystickButton* clawClose;
	JoystickButton* clawControl;
	JoystickButton* leftyMode;
	JoystickButton* collectIn;
	JoystickButton* collectOut;
	JoystickButton* collectStop;

public:
	int LEFT = 0;
	int RIGHT = 1;
	//static const int BUTTON = 2;
	int EXTERNAL_CONTROL = 2;
	int BUTTON_BOX = 3;

	bool flipped = false;

	OI();
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	bool GetButton(int stick, int);
	void LeftyFlip();

	JoystickButton* GetSpecialtyButton(int, int);
	bool GetClawButtonValue();
};

#endif
