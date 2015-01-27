#include <Commands/DriveInternalCollect.h>

DriveInternalCollect::DriveInternalCollect()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
}

// Called just before this Command runs the first time
void DriveInternalCollect::Initialize()
{
	SmartDashboard::PutBoolean(DRIVE_INTERNAL_RUNNING, true);
}

// Called repeatedly when this Command is scheduled to run
void DriveInternalCollect::Execute()
{
	internalCollect->SetMotorPower(oi->GetStickY(oi->LEFT));
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
	SmartDashboard::PutBoolean(DRIVE_INTERNAL_RUNNING, false);
}
