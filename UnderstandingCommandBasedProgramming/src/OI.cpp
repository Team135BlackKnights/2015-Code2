#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	stick = new Joystick(JOYSTICK);
	Button button11 = new JoystickButton(stick, 11);
	Button button12 = new JoystickButton(stick, 12);
	button11.WhenPressed(new SendSerialData('U'));
}

int OI::GetStickX()
{
	return stick->GetX();
}

int OI::GetStickY()
{
	return stick->GetY();
}

int OI::GetStickZ()
{
	return stick->GetZ();
}
