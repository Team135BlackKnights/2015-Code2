#ifndef RunWinchUntilStopped_H
#define RunWinchUntilStopped_H

#include "../CommandBase.h"
#include "WPILib.h"

class RunWinchUntilStopped: public CommandBase
{
private:
	//bool func();
	int limitPort;
	float power;
	//bool status;
public:
	RunWinchUntilStopped(float, int);//(*fptr)());
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
