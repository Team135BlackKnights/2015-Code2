#ifndef ChangeDriveMode_H
#define ChangeDriveMode_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeDriveMode: public CommandBase
{
public:
	ChangeDriveMode(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	int driveMode;
};

#endif
