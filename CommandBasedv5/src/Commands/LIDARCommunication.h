#ifndef LIDARCommunication_H
#define LIDARCommunication_H

#include "../CommandBase.h"
#include "WPILib.h"

class LIDARCommunication: public CommandBase
{
private:
	int i;
	int step;
	const int FRAMES_PER_STEP = 10;
public:
	LIDARCommunication();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
