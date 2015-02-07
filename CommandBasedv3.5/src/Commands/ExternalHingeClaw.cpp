#include "ExternalHingeClaw.h"
#include "RobotMap.h"

ExternalHingeClaw::ExternalHingeClaw(bool status)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(externalCollect);
	this->status = status;
}

// Called just before this Command runs the first time
void ExternalHingeClaw::Initialize()
{
	status = true;
	//SmartDashboard::PutString(T_EXTERNAL_HINGE_CLAW, "Initialized");
	externalCollect->SetHingeClawState(status);
}

// Called repeatedly when this Command is scheduled to run
void ExternalHingeClaw::Execute()
{
	//SmartDashboard::PutString(T_EXTERNAL_HINGE_CLAW, "Running");
}

// Make this return true when this Command no longer needs to run execute()
bool ExternalHingeClaw::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ExternalHingeClaw::End()
{
	//SmartDashboard::PutString(T_EXTERNAL_HINGE_CLAW, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExternalHingeClaw::Interrupted()
{
	//SmartDashboard::PutString(T_EXTERNAL_HINGE_CLAW, "Interrupted");
}
