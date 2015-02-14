#ifndef RunInternalUpUntilStopped_H
#define RunInternalUpUntilStopped_H

#include "../CommandBase.h"
#include "WPILib.h"

class RunInternalUpUntilStopped: public CommandBase
{
private:

	float power;
public:
	RunInternalUpUntilStopped(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
