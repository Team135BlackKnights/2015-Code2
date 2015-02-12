#ifndef RunInternalDownUntilStopped_H
#define RunInternalDownUntilStopped_H

#include "../CommandBase.h"
#include "WPILib.h"

class RunInternalDownUntilStopped: public CommandBase
{
private:

	float power;
public:
	RunInternalDownUntilStopped(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
