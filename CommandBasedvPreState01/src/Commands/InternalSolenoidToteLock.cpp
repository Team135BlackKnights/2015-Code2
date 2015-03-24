#include <Commands/InternalSolenoidToteLock.h>
#include "RobotMap.h"


InternalSolenoidToteLock::InternalSolenoidToteLock(bool status)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
		//isOpen = status;
		this->status = status;
}

// Called just before this Command runs the first time
void InternalSolenoidToteLock::Initialize()
{
	internalCollect->SetToteLockSolenoid(status);

}

// Called repeatedly when this Command is scheduled to run
void InternalSolenoidToteLock::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool InternalSolenoidToteLock::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InternalSolenoidToteLock::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InternalSolenoidToteLock::Interrupted()
{

}
