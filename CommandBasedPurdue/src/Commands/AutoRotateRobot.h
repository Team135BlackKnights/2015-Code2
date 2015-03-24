#ifndef AutoRotateRobot_H
#define AutoRotateRobot_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "RobotMap.h"

//#define max(a, b) a < b ? a : b
//#define min(a, b) a > b ? a : b

class AutoRotateRobot: public CommandBase
{
private:
	float targetAngle;
	float rotationTargetAngle;
	float currentAngle;
	float startingAngle;
	float bailOutTime;
	float power;
	Timer *timer;
	static constexpr float MAX_ROTATION_POWER = .4f;
	static constexpr float MIN_ROTATION_POWER = .15f;
public:
	AutoRotateRobot(float targetAngle, float power=.4f, float bailOutTime=5.0f);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
