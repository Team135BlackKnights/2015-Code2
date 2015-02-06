#include "DriveExternalCollect.h"

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
