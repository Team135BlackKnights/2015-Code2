#include <Commands/InternalSolenoidToteLock.h>
#include "RobotMap.h"


InternalSolenoidToteLock::InternalSolenoidToteLock(bool status)
{
	Requires(internalCollect);
	this->status = status;
}

void InternalSolenoidToteLock::Initialize()
{
	internalCollect->SetToteLockSolenoid(this->status);
}

void InternalSolenoidToteLock::Execute() {}

bool InternalSolenoidToteLock::IsFinished() {return true;}

void InternalSolenoidToteLock::End() {}

void InternalSolenoidToteLock::Interrupted() {}
