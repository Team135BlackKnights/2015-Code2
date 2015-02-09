#include "InternalCollection.h"

InternalCollection::InternalCollection(float power, bool engageSolenoid)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(internalCollect);
	this->engageSolenoid = engageSolenoid;
	this->power = power;
}

// Called just before this Command runs the first time
void InternalCollection::Initialize()
{
	internalCollect->SetCollectSolenoid(engageSolenoid);
	internalCollect->DriveCollect(power);
}

// Called repeatedly when this Command is scheduled to run
void InternalCollection::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool InternalCollection::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InternalCollection::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InternalCollection::Interrupted()
{

}
