#include "ChangeDriveMode.h"

ChangeDriveMode::ChangeDriveMode(int mode)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	//Requires(mecanumDrive);
	driveMode = mode;
}

// Called just before this Command runs the first time
void ChangeDriveMode::Initialize()
{
	SmartDashboard::PutNumber("DriveMode", driveMode);
	mecanumDrive->SetDriveMode(driveMode);
}

// Called repeatedly when this Command is scheduled to run
void ChangeDriveMode::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeDriveMode::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChangeDriveMode::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeDriveMode::Interrupted()
{

}
