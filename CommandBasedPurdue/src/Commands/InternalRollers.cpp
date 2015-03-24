#include "InternalRollers.h"

InternalRollers::InternalRollers(float power, float targetTime)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(internalCollect);
	this->power = power;
	this->targetTime = targetTime;
	this->timer = new Timer();
}

// Called just before this Command runs the first time
void InternalRollers::Initialize()
{
	this->timer->Start();
	internalCollect->SetCollectPower(power);
}

// Called repeatedly when this Command is scheduled to run
void InternalRollers::Execute()
{
	internalCollect->DriveCollect();
}

// Make this return true when this Command no longer needs to run execute()
bool InternalRollers::IsFinished()
{
	return this->timer->HasPeriodPassed(targetTime);
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
