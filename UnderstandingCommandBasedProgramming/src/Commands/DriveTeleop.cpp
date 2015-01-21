#include "DriveTeleop.h"
#include "../Subsystems/MecanumDrive.h"

DriveTeleop::DriveTeleop()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(mecanumDrive);
}

// Called just before this Command runs the first time
void DriveTeleop::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DriveTeleop::Execute()
{
	mecanumDrive->DriveJoysticks(oi->GetStickX(), oi->GetStickY(), oi->GetStickZ());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTeleop::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveTeleop::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTeleop::Interrupted()
{

}
