#include <Commands/ExternalOpenCloseClaw.h>

ExternalOpenCloseClaw::ExternalOpenCloseClaw(bool status)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(externalCollect);
	isOpen = status;
}

// Called just before this Command runs the first time
void ExternalOpenCloseClaw::Initialize()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Initialized");
	externalCollect->SetOpenCloseClawState(isOpen);
}

// Called repeatedly when this Command is scheduled to run
void ExternalOpenCloseClaw::Execute()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Running");
}

// Make this return true when this Command no longer needs to run execute()
bool ExternalOpenCloseClaw::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ExternalOpenCloseClaw::End()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExternalOpenCloseClaw::Interrupted()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Interrupted");
}
