#include <Commands/DriveJ.h>
#include "RobotMap.h"
//#include "../Subsystems/MecanumDrive.h"

DriveJ::DriveJ()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(mecanumDrive);
}

// Called just before this Command runs the first time
void DriveJ::Initialize()
{
	SmartDashboard::PutString(DRIVE_J_RUNNING, "Initialized");
}

// Called repeatedly when this Command is scheduled to run
void DriveJ::Execute()
{
	SmartDashboard::PutString(DRIVE_J_RUNNING, "Running");
	float x = 0, y = 0, rotation = 0;
	switch (mecanumDrive->GetDriveMode())
	{
	case mecanumDrive->SRX_SRY_SRZ:
		x = oi->GetStickX(oi->RIGHT);
		y = oi->GetStickY(oi->RIGHT);
		rotation = oi->GetStickTwist(oi->RIGHT);
		break;
	case mecanumDrive->SRX_SRY_SLZ:
		x = oi->GetStickX(oi->RIGHT);
		y = oi->GetStickY(oi->RIGHT);
		rotation = oi->GetStickTwist(oi->LEFT);
	break;
	default:
		x = oi->GetStickX(oi->RIGHT);
		y = oi->GetStickY(oi->RIGHT);
		rotation = oi->GetStickTwist(oi->RIGHT);
		break;
	}
	mecanumDrive->DriveJoysticks(x, y, rotation);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveJ::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveJ::End()
{
	SmartDashboard::PutString(DRIVE_J_RUNNING, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveJ::Interrupted()
{
	SmartDashboard::PutString(DRIVE_J_RUNNING, "Interrupted");
}
