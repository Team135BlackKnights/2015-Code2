#include "SetFieldOriented.h"

SetFieldOriented::SetFieldOriented(bool mode)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->mode = mode;
}

// Called just before this Command runs the first time
void SetFieldOriented::Initialize()
{
	mecanumDrive->SetFieldOriented(mode);
}

// Called repeatedly when this Command is scheduled to run
void SetFieldOriented::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool SetFieldOriented::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SetFieldOriented::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SetFieldOriented::Interrupted()
{

}
