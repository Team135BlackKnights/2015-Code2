#ifndef InternalMoveWinch_H
#define InternalMoveWinch_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalMoveWinch: public CommandBase
{
private:
	float power;
	double targetTime;
	Timer* timer;
public:
	InternalMoveWinch(float, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
