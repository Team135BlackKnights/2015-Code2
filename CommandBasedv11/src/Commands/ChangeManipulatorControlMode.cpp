#include "ChangeManipulatorControlMode.h"

ChangeManipulatorControlMode::ChangeManipulatorControlMode(bool mode)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	this->mode = mode;
}

// Called just before this Command runs the first time
void ChangeManipulatorControlMode::Initialize()
{
	oi->SetManipulatorControlMode(mode);
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeManipulatorControlMode::IsFinished()
{
	return true;
}

void ChangeManipulatorControlMode::Execute() {};
void ChangeManipulatorControlMode::End() {};
void ChangeManipulatorControlMode::Interrupted() {};
