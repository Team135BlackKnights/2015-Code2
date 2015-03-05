#include "ExternalMoveWinch.h"
#include "RobotMap.h"

ExternalMoveWinch::ExternalMoveWinch(float power, double targetTime)
{
	Requires(externalCollect);
	this->power = power;
	this->targetTime = targetTime;
	this->timer = new Timer();
}

void ExternalMoveWinch::Initialize()
{
	//externalCollect->GetDefaultCommand()->Cancel();
	timer->Start();
}

void ExternalMoveWinch::Execute()
{
	externalCollect->DriveWinch(power);
}

bool ExternalMoveWinch::IsFinished()
{
	return timer->HasPeriodPassed(targetTime);
}

void ExternalMoveWinch::End()
{
	externalCollect->DriveWinch(0);
	//externalCollect->GetDefaultCommand()->Start();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExternalMoveWinch::Interrupted()
{
}
