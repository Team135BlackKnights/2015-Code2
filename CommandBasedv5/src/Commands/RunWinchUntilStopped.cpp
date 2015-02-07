#include "RunWinchUntilStopped.h"
#include "RobotMap.h"

RunWinchUntilStopped::RunWinchUntilStopped(float power, int limitPort)//(*fptr)())
{
	// Use Requires() here to declare subsystem dependencies
	Requires(externalCollect);
	this->power = power;
	this->limitPort = limitPort;
	//this->status = status;
	//func = &fptr();
}

// Called just before this Command runs the first time
void RunWinchUntilStopped::Initialize()
{
	SmartDashboard::PutString(T_RUN_WINCH_UNTIL_STOPPED, "Initialized");
	externalCollect->GetDefaultCommand()->Cancel();
}

// Called repeatedly when this Command is scheduled to run
void RunWinchUntilStopped::Execute()
{
	SmartDashboard::PutString(T_RUN_WINCH_UNTIL_STOPPED, "Running");
	externalCollect->DriveWinch(power);
}

// Make this return true when this Command no longer needs to run execute()
bool RunWinchUntilStopped::IsFinished()
{
	return !externalCollect->GetLimitSwitchValue(limitPort);
}

// Called once after isFinished returns true
void RunWinchUntilStopped::End()
{
	SmartDashboard::PutString(T_RUN_WINCH_UNTIL_STOPPED, "Ended");
	externalCollect->DriveWinch(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RunWinchUntilStopped::Interrupted()
{
	SmartDashboard::PutString(T_RUN_WINCH_UNTIL_STOPPED, "Interrupted");
	externalCollect->DriveWinch(0);
}
