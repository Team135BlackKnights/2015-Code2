#include "LeftyModeJustForRiley.h"

LeftyModeJustForRiley::LeftyModeJustForRiley(bool mode)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->mode = mode;
}

// Called just before this Command runs the first time
void LeftyModeJustForRiley::Initialize()
{
	oi->LeftyFlip(mode);
}

// Called repeatedly when this Command is scheduled to run
void LeftyModeJustForRiley::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool LeftyModeJustForRiley::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void LeftyModeJustForRiley::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LeftyModeJustForRiley::Interrupted()
{

}
