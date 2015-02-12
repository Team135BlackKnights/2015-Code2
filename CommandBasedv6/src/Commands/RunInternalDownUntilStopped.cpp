#include "RunInternalDownUntilStopped.h"
#include "RobotMap.h"

RunInternalDownUntilStopped::RunInternalDownUntilStopped(float power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
	this->power = power;

}

// Called just before this Command runs the first time
void RunInternalDownUntilStopped::Initialize()
{
	internalCollect->GetDefaultCommand()->Cancel();
}

// Called repeatedly when this Command is scheduled to run
void RunInternalDownUntilStopped::Execute()
{
	internalCollect->DriveLift(power);
}

// Make this return true when this Command no longer needs to run execute()
bool RunInternalDownUntilStopped::IsFinished()
{
	return  !internalCollect->GetLimitSwitchValueLower();
}

// Called once after isFinished returns true
void RunInternalDownUntilStopped::End()
{
	internalCollect->DriveLift(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunInternalDownUntilStopped::Interrupted()
{
	internalCollect->DriveLift(0);
}

