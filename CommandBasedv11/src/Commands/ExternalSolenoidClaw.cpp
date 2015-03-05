#include <Commands/ExternalSolenoidClaw.h>
#include "RobotMap.h"

ExternalSolenoidClaw::ExternalSolenoidClaw(bool status)
{
	Requires(externalCollect);
	this->status = status;

}

void ExternalSolenoidClaw::Initialize()
{
	externalCollect->SetClawState(status);
}

void ExternalSolenoidClaw::Execute() {}

bool ExternalSolenoidClaw::IsFinished() {return true;}

void ExternalSolenoidClaw::End() {}

void ExternalSolenoidClaw::Interrupted() {}
