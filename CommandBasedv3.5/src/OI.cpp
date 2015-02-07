#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "Commands/ChangeDriveMode.h"
#include "Commands/AlignRobot.h"
#include "Commands/ExternalOpenCloseClaw.h"
//#include "Commands/ExternalHingeClaw.h"
//#include "Commands/LeftyModeJustForRiley.h"
#include "Commands/ExternalHingeClaw.h"



OI::OI()
{

	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joysticks
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	sticks[BUTTON] = new Joystick(JOYSTICK_BUTTON);

	for (int i = 0; i < 2; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{
		for (int j = 0; j < MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}
	//buttons[LEFT][10]->WhenPressed(new AlignRobot(45)); // When pressed Robot Aligns to 45 degrees
	//buttons[LEFT][BUTTON_OPEN_CLOSE_CLAW]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
	//buttons[BUTTON][BUTTON_OPEN_CLOSE_CLAW]->WhenReleased(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
	//buttons[LEFT][10]->WhenPressed(new ExternalHingeClaw(ExternalCollect::CLAW_UP));
	//buttons[LEFT][10]->WhenReleased(new ExternalHingeClaw(ExternalCollect::CLAW_DOWN));
	buttons[LEFT][10]->WhenPressed(new ExternalHingeClaw(false));
	buttons[LEFT][10]->WhenReleased(new ExternalHingeClaw(true));


	buttons[RIGHT][10]->WhenPressed(new ExternalOpenCloseClaw(false));
	buttons[RIGHT][11]->WhenReleased(new ExternalOpenCloseClaw(true));
	//buttons[RIGHT][10]->WhenPressed(new ExternalOpenCloseClaw(false));
	//buttons[RIGHT][10]->WhenReleased(new ExternalOpenCloseClaw(true));
	//buttons[BUTTON][BUTTON_LEFTY_FLIP]->WhenPressed(new LeftyModeJustForRiley());

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

void OI::LeftyFlip()
{
	int temp = LEFT;
	LEFT = RIGHT;
	RIGHT = temp;
}
