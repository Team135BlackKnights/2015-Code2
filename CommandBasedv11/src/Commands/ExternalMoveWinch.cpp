#include "ExternalMoveWinch.h"
#include "RobotMap.h"

ExternalMoveWinch::ExternalMoveWinch(float power, double targetTime)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(externalCollect);
	this->power = power;
	this->targetTime = targetTime;
	this->timer = new Timer();
}

// Called just before this Command runs the first time
void ExternalMoveWinch::Initialize()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_INITIALIZED);
	//externalCollect->GetDefaultCommand()->Cancel();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void ExternalMoveWinch::Execute()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_RUNNING);
	externalCollect->DriveWinch(power);
}

// Make this return true when this Command no longer needs to run execute()
bool ExternalMoveWinch::IsFinished()
{
	return timer->HasPeriodPassed(targetTime);
}

// Called once after isFinished returns true
void ExternalMoveWinch::End()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_ENDED);
	externalCollect->DriveWinch(0);
	//externalCollect->GetDefaultCommand()->Start();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExternalMoveWinch::Interrupted()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_INTERRUPTED);
}
