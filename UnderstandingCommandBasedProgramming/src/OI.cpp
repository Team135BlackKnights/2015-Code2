#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"

OI::OI()
{
	// Process operator interface input here.
	stick = new Joystick(JOYSTICK);

	for (int i = 0; i < MAX_JOYSTICK_BUTTONS; i++)
	{
		buttons[i] = new JoystickButton(stick, i);
	}
	//buttons[11]->WhenPressed(new DriveJ());

}

float OI::GetStickX()
{
	return stick->GetX();
}

float OI::GetStickY()
{
	return stick->GetY();
}

float OI::GetStickZ()
{
	return stick->GetZ();
}
