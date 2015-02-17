#include "SetSafetyEnabled.h"

SetSafetyEnabled::SetSafetyEnabled(bool enabled)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->enabled = enabled;
}

// Called just before this Command runs the first time
void SetSafetyEnabled::Initialize()
{
	mecanumDrive->SetSafetyEnabled(enabled);
}

// Called repeatedly when this Command is scheduled to run
void SetSafetyEnabled::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetSafetyEnabled::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetSafetyEnabled::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetSafetyEnabled::Interrupted()
{

}
