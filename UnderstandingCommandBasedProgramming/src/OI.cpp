#include "OI.h"
#include "RobotMap.h"

OI::OI():
	stick(JOYSTICK)
{
	// Process operator interface input here.
	for (int i = 0; i < MAX_JOYSTICK_BUTTONS; i++) {
		buttons[i] = new JoystickButton(stick, i);
	}

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
