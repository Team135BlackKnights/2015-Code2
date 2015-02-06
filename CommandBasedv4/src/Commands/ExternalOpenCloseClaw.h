#ifndef ExternalClaw_H
#define ExternalClaw_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExternalOpenCloseClaw: public CommandBase
{
private:
	bool isOpen;
public:
	ExternalOpenCloseClaw(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
