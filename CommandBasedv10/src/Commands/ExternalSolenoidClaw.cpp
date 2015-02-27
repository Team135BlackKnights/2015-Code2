#include <Commands/ExternalSolenoidClaw.h>
#include "RobotMap.h"

ExternalSolenoidClaw::ExternalSolenoidClaw(bool status)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	//Requires(externalCollect);
	//isOpen = status;
	this->status = status;

}

// Called just before this Command runs the first time
void ExternalSolenoidClaw::Initialize()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Initialized");
	//externalCollect->SetOpenCloseClawState(status);
	SmartDashboard::PutBoolean("External Claw Open", status);
	externalCollect->SetClawState(status);
	//externalCollect->PowerClaw();
}

// Called repeatedly when this Command is scheduled to run
void ExternalSolenoidClaw::Execute()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Running");
}

// Make this return true when this Command no longer needs to run execute()
bool ExternalSolenoidClaw::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ExternalSolenoidClaw::End()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExternalSolenoidClaw::Interrupted()
{
	SmartDashboard::PutString(T_EXTERNAL_OPEN_CLOSE_CLAW, "Interrupted");
}
