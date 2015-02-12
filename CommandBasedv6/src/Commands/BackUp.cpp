#include "BackUp.h"
#include "RobotMap.h"

BackUp::BackUp()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumDrive);
	i = 0;
}

// Called just before this Command runs the first time
void BackUp::Initialize()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, "Initialized");
	mecanumDrive->GetDefaultCommand()->Cancel();
}

// Called repeatedly when this Command is scheduled to run
void BackUp::Execute()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, "Running: " + i);
	mecanumDrive->DriveJoysticks(0, .7, 0);
	i++;
}

// Make this return true when this Command no longer needs to run execute()
bool BackUp::IsFinished()
{
	return i > 50000;
}

// Called once after isFinished returns true
void BackUp::End()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, "Ended");
	mecanumDrive->DriveJoysticks(0, 0, 0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void BackUp::Interrupted()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, "Interrupted");
	mecanumDrive->DriveJoysticks(0, 0, 0);
}
