#include <Commands/InternalSolenoid.h>

InternalSolenoid::InternalSolenoid(bool engageSolenoid)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(internalCollect);
	this->engageSolenoid = engageSolenoid;
}

// Called just before this Command runs the first time
void InternalSolenoid::Initialize()
{
	internalCollect->SetCollectSolenoid(engageSolenoid);
}

// Called repeatedly when this Command is scheduled to run
void InternalSolenoid::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool InternalSolenoid::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InternalSolenoid::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InternalSolenoid::Interrupted()
{

}
