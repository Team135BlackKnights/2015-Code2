#include "InternalRollers.h"

InternalRollers::InternalRollers(float power)
{
	Requires(internalCollect);
	this->power = power;
}

void InternalRollers::Initialize()
{
	internalCollect->SetCollectPower(power);
}

void InternalRollers::Execute() {}

bool InternalRollers::IsFinished() {return true;}

void InternalRollers::End() {}

void InternalRollers::Interrupted() {}
