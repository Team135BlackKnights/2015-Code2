#include <Commands/DriveInternalCollect.h>
#include "RobotMap.h"

DriveInternalCollect::DriveInternalCollect()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
}

// Called just before this Command runs the first time
void DriveInternalCollect::Initialize()
{
	SmartDashboard::PutString(DRIVE_INTERNAL_RUNNING, "Initialized");
}

// Called repeatedly when this Command is scheduled to run
void DriveInternalCollect::Execute()
{
	SmartDashboard::PutString(DRIVE_INTERNAL_RUNNING, "Running");
	internalCollect->DriveLift(oi->GetStickY(oi->LEFT));


	if (oi->sticks[oi->LEFT]->GetRawButton(7) == 1)
		internalCollect->DriveCollectOut();
	else if (oi->sticks[oi->LEFT]->GetRawButton(8) == 1)
		internalCollect->DriveCollectIn();
	else
		internalCollect->DriveCollect(0);

	if (oi->sticks[oi->LEFT]->GetRawButton(9))
		internalCollect->SetLiftSolenoid(true);
	if (oi->sticks[oi->LEFT]->GetRawButton(10))
		internalCollect->SetLiftSolenoid(false);

	if (oi->sticks[oi->LEFT]->GetRawButton(11) == 1)
		internalCollect->SetControlSolenoid(true);
	if (oi->sticks[oi->LEFT]->GetRawButton(12) == 1)
		internalCollect->SetControlSolenoid(false);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveInternalCollect::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveInternalCollect::End()
{
	SmartDashboard::PutBoolean(DRIVE_INTERNAL_RUNNING, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveInternalCollect::Interrupted()
{
	SmartDashboard::PutString(DRIVE_INTERNAL_RUNNING, "Interrupted");
}
