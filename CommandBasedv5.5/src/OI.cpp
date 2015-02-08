#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "Commands/ChangeDriveMode.h"
#include "Commands/AlignRobot.h"
#include "Commands/ExternalOpenCloseClaw.h"
#include "Commands/LeftyModeJustForRiley.h"
#include "Commands/ExternalHingeClaw.h"
#include "Commands/RunWinchUntilStopped.h"
#include "Subsystems/ExternalCollect.h"
#include "CommandBase.h"


OI::OI()
{

	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joysticks
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	sticks[BUTTON] = new Joystick(JOYSTICK_BUTTON);

	for (int i = 0; i < 3; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{
		for (int j = 1; j <= MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}
	//checked

	//buttons[BUTTON][BUTTON_OPEN_CLOSE_CLAW]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
	//SmartDashboard::PutBoolean(T_CLAW_OPEN_CLOSE, true);
	//buttons[BUTTON][BUTTON_OPEN_CLOSE_CLAW]->WhenReleased(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
	//SmartDashboard::PutBoolean(T_CLAW_OPEN_CLOSE, false);

	buttons[LEFT][11]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
		//SmartDashboard::PutBoolean(T_CLAW_OPEN_CLOSE, true);
	buttons[LEFT][12]->WhenReleased(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
		//SmartDashboard::PutBoolean(T_CLAW_OPEN_CLOSE, false);



	//checked
	//buttons[BUTTON][BUTTON_HINGE_CLAW]->WhenPressed(new ExternalHingeClaw(ExternalCollect::CLAW_UP));
	//buttons[BUTTON][BUTTON_HINGE_CLAW]->WhenReleased(new ExternalHingeClaw(ExternalCollect::CLAW_DOWN));

	buttons[LEFT][11]->WhenPressed(new ExternalHingeClaw(ExternalCollect::CLAW_UP));
	buttons[LEFT][12]->WhenReleased(new ExternalHingeClaw(ExternalCollect::CLAW_DOWN));

	//checked
	//buttons[BUTTON][BUTTON_LEFTY_FLIP]->WhenPressed(new LeftyModeJustForRiley());
	//SmartDashboard::PutBoolean(T_LEFTY_MODE, flipped);

	//buttons[BUTTON][BUTTON_RUN_WINCH_UNTIL_STOPPED]->WhenPressed(new RunWinchUntilStopped(-1, 0));

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
