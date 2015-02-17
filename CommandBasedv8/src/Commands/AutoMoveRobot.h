#ifndef AutoMoveRobot_H
#define AutoMoveRobot_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class AutoMoveRobot: public CommandBase
{
private:
	float power;
	double timePassed;
	Timer* timer;
public:
	AutoMoveRobot(float power, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
