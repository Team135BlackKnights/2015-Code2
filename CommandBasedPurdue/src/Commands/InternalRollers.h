#ifndef InternalRollers_H
#define InternalRollers_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalRollers: public CommandBase
{
private:
	float power;
	float targetTime;
	Timer* timer;
public:
	InternalRollers(float power, float targetTime=0);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
