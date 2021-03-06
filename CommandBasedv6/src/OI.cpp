#include <Commands/InternalSolenoid.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "Commands/ChangeDriveMode.h"
#include "Commands/AlignRobot.h"
#include "Commands/ExternalOpenCloseClaw.h"
#include "Commands/LeftyModeJustForRiley.h"
#include "Commands/ExternalHingeClaw.h"
#include "Commands/RunWinchUntilStopped.h"
#include "Commands/BackUp.h"
#include "Subsystems/ExternalCollect.h"
#include "Commands/RunInternalDownUntilStopped.h"
#include "Commands/RunInternalUpUntilStopped.h"
#include "CommandBase.h"
#include "Commands/InternalRollers.h"
#include "Subsystems/InternalCollect.h"
#include "Commands/ChangeManipulatorControlMode.h"


OI::OI()
{

	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joysticks
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	//if (NUMBER_O_JOYSTICKS > 2)
		sticks[MANIPULATOR_CONTROL] = new Joystick(JOYSTICK_EXTERNAL_CONTROL);
	//if (NUMBER_O_JOYSTICKS > 3)
		sticks[BUTTON_BOX] = new Joystick(JOYSTICK_BUTTON_BOX);

	for (int i = 0; i < NUMBER_O_JOYSTICKS; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{
		for (int j = 1; j <= MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}

	SetManipulatorControlMode(EXTERNAL);


	//buttons[BUTTON][BUTTON_RUN_WINCH_UNTIL_STOPPED]->WhenPressed(new RunWinchUntilStopped(-1, 0));


	buttons[LEFT][MISC_LEFTY_MODE]->WhenPressed(new LeftyModeJustForRiley());

	buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_EXTERNAL]->WhenPressed(new ChangeManipulatorControlMode(EXTERNAL));
	buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_INTERNAL]->WhenPressed(new ChangeManipulatorControlMode(INTERNAL));

	buttons[LEFT][MISC_CHANGE_DRIVE_MODE_A]->WhenPressed(new ChangeDriveMode(MecanumDrive::DRIVE_MODE_A));
	buttons[LEFT][MISC_CHANGE_DRIVE_MODE_B]->WhenPressed(new ChangeDriveMode(MecanumDrive::DRIVE_MODE_B));
	buttons[LEFT][MISC_CHANGE_DRIVE_MODE_C]->WhenPressed(new ChangeDriveMode(MecanumDrive::DRIVE_MODE_C));
	buttons[LEFT][MISC_CHANGE_DRIVE_MODE_D]->WhenPressed(new ChangeDriveMode(MecanumDrive::DRIVE_MODE_D));


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

void OI::SetManipulatorControlMode(bool mode)
{
	MANIPULATOR_CONTROL_MODE = mode;
	for (int i = 1; i <= MAX_JOYSTICK_BUTTONS - 2; i++)
	{
		buttons[MANIPULATOR_CONTROL][i]->WhenPressed(NULL);
		buttons[MANIPULATOR_CONTROL][i]->WhenReleased(NULL);
	}
	switch(mode)
	{
	case EXTERNAL:
		buttons[MANIPULATOR_CONTROL][EXTERNAL_CLAW_CLOSED]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
		buttons[MANIPULATOR_CONTROL][EXTERNAL_CLAW_OPEN]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN)); //THIS IS ALL RUINED BECAUSE OF ZACH BEING A DINGALING -OVERLORD MATT

		buttons[MANIPULATOR_CONTROL][EXTERNAL_WINCH_DOWN]->WhenPressed(new RunInternalDownUntilStopped(-1));
		buttons[MANIPULATOR_CONTROL][EXTERNAL_WINCH_UP]->WhenPressed(new RunInternalUpUntilStopped(1));
		break;
	case INTERNAL:
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_IN]->WhenPressed(new InternalRollers(.6));
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_IN]->WhenReleased(new InternalRollers(0));
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_OUT]->WhenPressed(new InternalRollers(-.8));
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_OUT]->WhenReleased(new InternalRollers(0));

		buttons[MANIPULATOR_CONTROL][INTERNAL_SOLENOID_ENGAGED]->WhenPressed(new InternalSolenoid(InternalCollect::COLLECT_ENGAGED));
		buttons[MANIPULATOR_CONTROL][INTERNAL_SOLENOID_DISENGAGED]->WhenPressed(new InternalSolenoid(InternalCollect::COLLECT_DISENGAGED));
		break;
	}
}
