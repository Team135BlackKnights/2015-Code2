#include "InternalRollers.h"

InternalRollers::InternalRollers(float power)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(internalCollect);
	this->power = power;
}

// Called just before this Command runs the first time
void InternalRollers::Initialize()
{
	internalCollect->SetCollectPower(power);
}

// Called repeatedly when this Command is scheduled to run
void InternalRollers::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool InternalRollers::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InternalRollers::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InternalRollers::Interrupted()
{
}
