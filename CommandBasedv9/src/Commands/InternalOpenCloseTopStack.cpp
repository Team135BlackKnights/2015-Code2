#include "InternalOpenCloseTopStack.h"
#include "RobotMap.h"


InternalOpenCloseTopStack::InternalOpenCloseTopStack(bool status)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
		//isOpen = status;
		this->status = status;
}

// Called just before this Command runs the first time
void InternalOpenCloseTopStack::Initialize()
{
	internalCollect->SetUpperStackSolenoid(status);

}

// Called repeatedly when this Command is scheduled to run
void InternalOpenCloseTopStack::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool InternalOpenCloseTopStack::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InternalOpenCloseTopStack::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InternalOpenCloseTopStack::Interrupted()
{

}
