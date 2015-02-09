#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "Commands/ChangeDriveMode.h"
#include "Commands/AlignRobot.h"
#include "Commands/ExternalOpenCloseClaw.h"
#include "Commands/LeftyModeJustForRiley.h"
#include "Commands/ExternalHingeClaw.h"
#include "Commands/RunWinchUntilStopped.h"
#include "Commands/InternalCollection.h"
#include "Subsystems/ExternalCollect.h"
#include "CommandBase.h"


OI::OI()
{

	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joysticks
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	if (NUMBER_O_JOYSTICKS > 2)
		sticks[EXTERNAL_CONTROL] = new Joystick(JOYSTICK_EXTERNAL_CONTROL);
	if (NUMBER_O_JOYSTICKS > 3)
		sticks[BUTTON_BOX] = new Joystick(JOYSTICK_BUTTON_BOX);

	for (int i = 0; i < NUMBER_O_JOYSTICKS; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{
		for (int j = 1; j <= MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}

///////////////////////////////////INITIALIZE SPECAILTY BUTTONS//////
	clawOpen = GetSpecialtyButton(EXTERNAL_CONTROL, 11);/////////////
	clawClose = GetSpecialtyButton(EXTERNAL_CONTROL, 12);////////////
	leftyMode = GetSpecialtyButton(LEFT, 12);////////////////////////
	collectIn = GetSpecialtyButton(EXTERNAL_CONTROL, 1);/////////////
	collectOut = GetSpecialtyButton(EXTERNAL_CONTROL, 2);////////////
	collectStop = GetSpecialtyButton(EXTERNAL_CONTROL, 3);///////////
/////////////////////////////////////////////////////////////////////

	clawOpen->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
	clawClose->WhenReleased(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));

	collectIn->WhenPressed(new InternalCollection(InternalCollect::COLLECT_ENGAGED, .6));
	collectOut->WhenPressed(new InternalCollection(InternalCollect::COLLECT_DISENGAGED, .8));
	collectStop->WhenPressed(new InternalCollection(InternalCollect::COLLECT_DISENGAGED, 0));

	leftyMode->WhenPressed(new LeftyModeJustForRiley());


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

bool OI::GetButton(int stick, int button)
{
	return buttons[stick][button]->Get();
}

void OI::LeftyFlip()
{
	flipped = !flipped;
	SmartDashboard::PutBoolean(T_LEFTY_MODE, flipped);
	int temp = LEFT;
	LEFT = RIGHT;
	RIGHT = temp;
}

JoystickButton* OI::GetSpecialtyButton(int stick, int button)
{
	return this->buttons[stick][button];
}
