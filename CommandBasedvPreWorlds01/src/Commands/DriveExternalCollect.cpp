#include "DriveExternalCollect.h"
#include "RobotMap.h"

DriveExternalCollect::DriveExternalCollect()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(externalCollect);
}

// Called just before this Command runs the first time
void DriveExternalCollect::Initialize()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, "Initialized");
}

// Called repeatedly when this Command is scheduled to run
void DriveExternalCollect::Execute()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, "Running");
	float value;

	if (oi->GetManipulatorControlMode() == oi->EXTERNAL)
	{
		value = oi->GetStickY(oi->MANIPULATOR_CONTROL);
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_CLAW_OPEN))
			externalCollect->SetClawState(externalCollect->CLAW_OPEN);
		else if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_CLAW_CLOSED))
			externalCollect->SetClawState(externalCollect->CLAW_CLOSED);
	}
	else if (oi->GetManipulatorControlMode() == oi->INTERNAL)
	{
		if (oi->GetTrigger(oi->LEFT))
			value = -.5f;
		else if (oi->GetTrigger(oi->RIGHT))
			value = .5f;
		else
			value = 0;
	}

	value = fmin(1, fmax(-1, value - oi->GetStickSlider(OI::STATIC_RIGHT) * ExternalCollect::MAX_GRAVITY_COMPENSATION));

	externalCollect->DriveWinch(value);
	//externalCollect->PowerClaw();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveExternalCollect::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveExternalCollect::End()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveExternalCollect::Interrupted()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, "Interrupted");
}
