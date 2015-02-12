#include "RunInternalUpUntilStopped.h"
#include "RobotMap.h"

RunInternalUpUntilStopped::RunInternalUpUntilStopped(float power)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
	this->power = power;

}

// Called just before this Command runs the first time
void RunInternalUpUntilStopped::Initialize()
{
	internalCollect->GetDefaultCommand()->Cancel();
}

// Called repeatedly when this Command is scheduled to run
void RunInternalUpUntilStopped::Execute()
{
	internalCollect->DriveLift(power);
}

// Make this return true when this Command no longer needs to run execute()
bool RunInternalUpUntilStopped::IsFinished()
{
	return  !internalCollect->GetLimitSwitchValueUpper();
}

// Called once after isFinished returns true
void RunInternalUpUntilStopped::End()
{
	internalCollect->DriveLift(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunInternalUpUntilStopped::Interrupted()
{
	internalCollect->DriveLift(0);
}

