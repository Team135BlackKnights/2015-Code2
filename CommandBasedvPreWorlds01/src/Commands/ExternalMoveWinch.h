#ifndef ExternalMoveWinch_H
#define ExternalMoveWinch_H

#include "../CommandBase.h"
#include "WPILib.h"

class ExternalMoveWinch: public CommandBase
{
private:
	float power;
	double targetTime;
	Timer* timer;
public:
	ExternalMoveWinch(float, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
