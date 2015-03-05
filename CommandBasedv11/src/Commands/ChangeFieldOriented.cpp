#include <Commands/ChangeFieldOriented.h>

ChangeFieldOriented::ChangeFieldOriented(bool mode)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->mode = mode;
}

// Called just before this Command runs the first time
void ChangeFieldOriented::Initialize()
{
	oi->SetFieldOriented(mode);
}

// Called repeatedly when this Command is scheduled to run
void ChangeFieldOriented::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ChangeFieldOriented::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ChangeFieldOriented::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChangeFieldOriented::Interrupted()
{

}
