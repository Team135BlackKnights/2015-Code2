#ifndef ExternalClaw_H
#define ExternalClaw_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExternalSolenoidClaw: public CommandBase
{
private:
	bool status;
public:
	ExternalSolenoidClaw(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
