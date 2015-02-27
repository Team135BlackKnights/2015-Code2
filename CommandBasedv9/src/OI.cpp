#include <Commands/ExternalSolenoidClaw.h>
#include <Commands/InternalSolenoidRoller.h>
#include <Commands/InternalSolenoidToteLock.h>
#include "OI.h"
#include "RobotMap.h"
#include "Commands/DriveJ.h"
#include "Commands/ChangeDriveMode.h"
#include "Commands/LeftyModeJustForRiley.h"
#include "Subsystems/ExternalCollect.h"
#include "CommandBase.h"
#include "Commands/InternalRollers.h"
#include "Subsystems/InternalCollect.h"
#include "Commands/ChangeManipulatorControlMode.h"
#include "Commands/SetFieldOriented.h"

OI::OI()
{

	// Process operator interface input here.
	sticks[LEFT] = new Joystick(JOYSTICK_LEFT); //Declares new Joysticks
	sticks[RIGHT] = new Joystick(JOYSTICK_RIGHT);
	sticks[MANIPULATOR_CONTROL] = new Joystick(JOYSTICK_MANIPULATOR_CONTROL);
	//sticks[BUTTON_BOX] = new Joystick(JOYSTICK_BUTTON_BOX);

	for (int i = 0; i < NUMBER_O_JOYSTICKS; i++) //Declares new buttons for Joysticks max # of buttons is 12
	{
		for (int j = 1; j <= MAX_JOYSTICK_BUTTONS; j++)
		{
			buttons[i][j] = new JoystickButton(sticks[i], j);
		}
	}

	SetDriveMode(MISC_CHANGE_DRIVE_MODE_A);
	LeftyFlip(SmartDashboard::GetBoolean(T_LEFTY_MODE, false));

	SetManipulatorControlMode(EXTERNAL);

	buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_EXTERNAL]->WhenPressed(new ChangeManipulatorControlMode(EXTERNAL));
	buttons[MANIPULATOR_CONTROL][MISC_CHANGE_MANIPULATOR_CONTROL_MODE_INTERNAL]->WhenPressed(new ChangeManipulatorControlMode(INTERNAL));

	buttons[RIGHT][MISC_LEFTY_MODE_ENABLED]->WhenPressed(new LeftyModeJustForRiley(true));
	buttons[RIGHT][MISC_LEFTY_MODE_DISABLED]->WhenPressed(new LeftyModeJustForRiley(false));

	buttons[RIGHT][MISC_CHANGE_DRIVE_MODE_A]->WhenPressed(new ChangeDriveMode(OI::MISC_CHANGE_DRIVE_MODE_A));
	buttons[RIGHT][MISC_CHANGE_DRIVE_MODE_B]->WhenPressed(new ChangeDriveMode(OI::MISC_CHANGE_DRIVE_MODE_B));
	//buttons[RIGHT][MISC_CHANGE_DRIVE_MODE_C]->WhenPressed(new ChangeDriveMode(MecanumDrive::DRIVE_MODE_C));
	//buttons[RIGHT][MISC_CHANGE_DRIVE_MODE_D]->WhenPressed(new ChangeDriveMode(MecanumDrive::DRIVE_MODE_D));

	buttons[RIGHT][MISC_FIELD_ORIENTED_ON]->WhenPressed(new SetFieldOriented(MecanumDrive::FIELD_ORIENTED_ENABLED));
	buttons[RIGHT][MISC_FIELD_ORIENTED_OFF]->WhenPressed(new SetFieldOriented(MecanumDrive::FIELD_ORIENTED_DISABLED));
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

float OI::GetStickSlider(int hand)
{
	return 1 - sticks[hand]->GetThrottle();
}

bool OI::GetButton(int stick, int button)
{
	return buttons[stick][button]->Get();
}

void OI::LeftyFlip(bool mode)
{
	leftyMode = mode;
	SmartDashboard::PutBoolean(T_LEFTY_MODE, leftyMode);
	switch (mode)
	{
	case true:
		LEFT = 1;
		RIGHT = 0;
		break;
	case false:
		LEFT = 0;
		RIGHT = 1;
		break;
	}
}

void OI::SetManipulatorControlMode(bool mode)
{
	SmartDashboard::PutBoolean(T_LEFTY_MODE, mode);
	MANIPULATOR_CONTROL_MODE = mode;
}

int OI::GetDriveMode()
{
	return this->driveMode;
}

void OI::SetDriveMode(int mode)
{
	SmartDashboard::PutNumber(T_DRIVE_MODE, mode);
	driveMode = mode;
}
