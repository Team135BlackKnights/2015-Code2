#ifndef DriveTeleop_H
#define DriveTeleop_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveTeleop: public CommandBase
{
public:
	DriveTeleop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
