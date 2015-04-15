#include "InternalMoveWinch.h"
#include "RobotMap.h"

InternalMoveWinch::InternalMoveWinch(float power, double targetTime)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
	this->power = power;
	this->targetTime = targetTime;
	this->timer = new Timer();
}

// Called just before this Command runs the first time
void InternalMoveWinch::Initialize()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_INITIALIZED);
	//externalCollect->GetDefaultCommand()->Cancel();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void InternalMoveWinch::Execute()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_RUNNING);
	internalCollect->DriveLift(power);
}

// Make this return true when this Command no longer needs to run execute()
bool InternalMoveWinch::IsFinished()
{
	return timer->HasPeriodPassed(targetTime);
}

// Called once after isFinished returns true
void InternalMoveWinch::End()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_ENDED);
	internalCollect->DriveLift(0);
	//externalCollect->GetDefaultCommand()->Start();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InternalMoveWinch::Interrupted()
{
	SmartDashboard::PutString(T_EXTERNAL_MOVE_WINCH, S_INTERRUPTED);
}
