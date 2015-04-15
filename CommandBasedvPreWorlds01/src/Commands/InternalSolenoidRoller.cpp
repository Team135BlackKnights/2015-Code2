#include <Commands/InternalSolenoidRoller.h>

InternalSolenoidRoller::InternalSolenoidRoller(bool engageSolenoid)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(internalCollect);
	this->engageSolenoid = engageSolenoid;
}

// Called just before this Command runs the first time
void InternalSolenoidRoller::Initialize()
{
	internalCollect->SetRollerCollectSolenoid(engageSolenoid);
}

// Called repeatedly when this Command is scheduled to run
void InternalSolenoidRoller::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool InternalSolenoidRoller::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InternalSolenoidRoller::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InternalSolenoidRoller::Interrupted()
{

}
