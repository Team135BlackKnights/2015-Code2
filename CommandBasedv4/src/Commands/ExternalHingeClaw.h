#ifndef ExternalHingeClaw_H
#define ExternalHingeClaw_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExternalHingeClaw: public CommandBase
{
private:
	bool status;
public:
	ExternalHingeClaw(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
