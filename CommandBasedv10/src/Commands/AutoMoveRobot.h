#ifndef AutoMoveRobot_H
#define AutoMoveRobot_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

//#define max(a, b) a < b ? a : b
//#define min(a, b) a > b ? a : b

class AutoMoveRobot: public CommandBase
{
private:
	float x;
	float y;
	double targetTime;
	double targetDistance;
	Timer* timer;
	float targetAngle;
	bool gyroCompensation;
	bool mode;

	static constexpr float MAX_ROTATION_POWER = .4f;
public:
	static const bool TIME = true;
	static const bool DISTANCE = false;

	AutoMoveRobot(float x, float y, double target, bool mode, bool gyroCompensation=false);
	//AutoMoveRobot(float x, float y, int targetDistance, bool gyroCompensation=false);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
