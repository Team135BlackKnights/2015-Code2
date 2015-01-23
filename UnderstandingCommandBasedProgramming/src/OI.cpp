#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "Commands/ChangeDriveMode.h"

OI::OI()
{
	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT);
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}
	buttons[LEFT][9]->WhenPressed(new ChangeDriveMode(0));
	buttons[LEFT][4]->WhenPressed(new ChangeDriveMode(1));
}

float OI::GetStickX(int hand)
{
	return sticks[hand]->GetX();
}

float OI::GetStickY(int hand)
{
	return sticks[hand]->GetY();
}

float OI::GetStickTwist(int hand)
{
	return sticks[hand]->GetTwist();
}
