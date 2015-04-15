#ifndef DriveInternalCollect_H
#define DriveInternalCollect_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveInternalCollect: public CommandBase
{
public:
	DriveInternalCollect();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
