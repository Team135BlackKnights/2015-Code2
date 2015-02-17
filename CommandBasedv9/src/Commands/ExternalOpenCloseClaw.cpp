#include <Commands/ExternalOpenCloseClaw.h>
#include "RobotMap.h"

ExternalOpenCloseClaw::ExternalOpenCloseClaw(bool status)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(externalCollect);
	//isOpen = status;
	this->status = status;

}

// Called just before this Command runs the first time
void ExternalOpenCloseClaw::Initialize()
{
	//SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Initialized");
	//externalCollect->SetOpenCloseClawState(status);
	SmartDashboard::PutBoolean("External Claw Open", status);
	externalCollect->SetOpenCloseClawState(status);
}

// Called repeatedly when this Command is scheduled to run
void ExternalOpenCloseClaw::Execute()
{
	//SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Running");
}

// Make this return true when this Command no longer needs to run execute()
bool ExternalOpenCloseClaw::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ExternalOpenCloseClaw::End()
{
	//SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExternalOpenCloseClaw::Interrupted()
{
	//SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Interrupted");
}
