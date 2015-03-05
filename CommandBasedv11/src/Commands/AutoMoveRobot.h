#ifndef AutoMoveRobot_H
#define AutoMoveRobot_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

class AutoMoveRobot: public CommandBase
{
private:
	float x;
	float y;
	float rotate;
	double timePassed;
	Timer* timer;
public:
	AutoMoveRobot(float, float, float, double time);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
