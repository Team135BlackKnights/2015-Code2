#include <Commands/InternalSolenoidRoller.h>

InternalSolenoidRoller::InternalSolenoidRoller(bool state)
{
	Requires(internalCollect);
	this->state = state;
}

void InternalSolenoidRoller::Initialize()
{
	internalCollect->SetRollerCollectSolenoid(this->state);
}

void InternalSolenoidRoller::Execute() {}

bool InternalSolenoidRoller::IsFinished() {return true;}

void InternalSolenoidRoller::End() {}

void InternalSolenoidRoller::Interrupted() {}
