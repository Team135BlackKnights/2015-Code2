#ifndef ExternalClaw_H
#define ExternalClaw_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExternalClaw: public CommandBase
{
private:
	bool isOpen;
public:
	ExternalClaw(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
