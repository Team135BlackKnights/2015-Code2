#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "Commands/ChangeDriveMode.h"
#include "Commands/AlignRobot.h"

OI::OI()
{

	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joysticks
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	sticks[BUTTON] = new Joystick(JOYSTICK_BUTTON);

	for (int i = 0; i < 3; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{
		for (int j = 0; j < MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}
	buttons[LEFT][10]->WhenPressed(new AlignRobot(45)); // When pressed Robot Aligns to 45 degrees
	buttons[BUTTON][CLAW_OPEN_CLOSE]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
	buttons[BUTTON][CLAW_OPEN_CLOSE]->WhenReleased(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));

}

float OI::GetStickX(int hand)
{
	return sticks[hand]->GetX(); //Returns X axis value of Joysticks
}

float OI::GetStickY(int hand)
{
	return sticks[hand]->GetY(); // Returns Y axis value of Joysticks
}

float OI::GetStickTwist(int hand)
{
	return sticks[hand]->GetTwist(); // Returns Twist or Z Axis of Joysticks
}
