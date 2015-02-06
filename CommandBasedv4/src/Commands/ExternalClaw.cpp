#include "ExternalClaw.h"

ExternalClaw::ExternalClaw(bool status)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(externalCollect);
	isOpen = status;
}

// Called just before this Command runs the first time
void ExternalClaw::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ExternalClaw::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ExternalClaw::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ExternalClaw::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExternalClaw::Interrupted()
{

}
