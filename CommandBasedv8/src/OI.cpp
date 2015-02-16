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
#include "Commands/InternalOpenCloseTopStack.h"
//HIIII

OI::OI()
{

	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joysticks
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	sticks[MANIPULATOR_CONTROL] = new Joystick(JOYSTICK_MANIPULATOR_CONTROL);
	sticks[BUTTON_BOX] = new Joystick(JOYSTICK_BUTTON_BOX);

	for (int i = 0; i < NUMBER_O_JOYSTICKS; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{
		for (int j = 1; j <= MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}
	SetManipulatorControlMode(EXTERNAL);

	buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_EXTERNAL]->WhenPressed(new ChangeManipulatorControlMode(EXTERNAL));
		buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_INTERNAL]->WhenPressed(new ChangeManipulatorControlMode(INTERNAL));

	buttons[LEFT][MISC_LEFTY_MODE]->WhenPressed(new LeftyModeJustForRiley());

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
	/*
	sticks[MANIPULATOR_CONTROL] = new Joystick(JOYSTICK_MANIPULATOR_CONTROL);
	for (int j = 1; j <= MAX_JOYSTICK_BUTTONS; j++)
	{
		buttons[MANIPULATOR_CONTROL][j] = new JoystickButton(sticks[MANIPULATOR_CONTROL], j);
	}
	switch (mode)
	{
	case EXTERNAL:
	//	buttons[MANIPULATOR_CONTROL][EXTERNAL_CLAW_OPEN]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
	//	buttons[MANIPULATOR_CONTROL][EXTERNAL_CLAW_CLOSED]->WhenPressed(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
		break;
	case INTERNAL:
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_IN]->WhenPressed(new InternalRollers(InternalCollect::COLLECT_IN_POWER));
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_IN]->WhenReleased(new InternalRollers(0));
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_OUT]->WhenPressed(new InternalRollers(InternalCollect::COLLECT_OUT_POWER));
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_OUT]->WhenReleased(new InternalRollers(0));

		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_SOLENOID_ENGAGED]->WhenPressed(new InternalSolenoid(InternalCollect::COLLECT_ENGAGED));
		buttons[MANIPULATOR_CONTROL][INTERNAL_ROLLER_SOLENOID_DISENGAGED]->WhenPressed(new InternalSolenoid(InternalCollect::COLLECT_DISENGAGED));
		buttons[MANIPULATOR_CONTROL][INTERNAL_UPPER_STACK_SOLENOID_DISENGAGED]->WhenPressed(new InternalOpenCloseTopStack(InternalCollect::UPPER_STACK_DISENGAGED));
		buttons[MANIPULATOR_CONTROL][INTERNAL_UPPER_STACK_SOLENOID_ENGAGED]->WhenPressed(new InternalOpenCloseTopStack(InternalCollect::UPPER_STACK_ENGAGED));

		break;
	}

	buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_EXTERNAL]->WhenPressed(new ChangeManipulatorControlMode(EXTERNAL));
	buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_INTERNAL]->WhenPressed(new ChangeManipulatorControlMode(INTERNAL));
	*/
}
