#ifndef ALIGNROBOT_H
#define ALIGNROBOT_H

#include "../CommandBase.h"

class AlignRobot: public CommandBase {
private:
	double desiredAngle;
	float power;
	const float TOLERANCE = 2;
public:
	AlignRobot(double);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};

#endif
