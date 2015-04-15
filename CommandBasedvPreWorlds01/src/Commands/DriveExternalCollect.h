#ifndef DriveExternalCollect_H
#define DriveExternalCollect_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveExternalCollect: public CommandBase
{
public:
	DriveExternalCollect();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
