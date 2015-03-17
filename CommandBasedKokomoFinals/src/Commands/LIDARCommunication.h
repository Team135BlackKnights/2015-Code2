#ifndef LIDARCommunication_H
#define LIDARCommunication_H

#include "../CommandBase.h"
#include "WPILib.h"

class LIDARCommunication: public CommandBase
{
private:
	int i;
	int step;
	int valueOne;
	int valueTwo;
	const int FRAMES_PER_STEP = 6;
public:
	LIDARCommunication();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
