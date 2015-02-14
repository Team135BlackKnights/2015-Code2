#ifndef InternalRunUntilStopped_H
#define InternalRunUntilStopped_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalRunUntilStopped: public CommandBase
{
private:
	DigitalInput* limitSwitch;
	float power;
public:
	InternalRunUntilStopped(float, DigitalInput*);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
