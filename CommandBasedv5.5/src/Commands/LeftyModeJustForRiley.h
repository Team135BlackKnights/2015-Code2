#ifndef LeftyModeJustForRiley_H
#define LeftyModeJustForRiley_H

#include "../CommandBase.h"
#include "WPILib.h"

class LeftyModeJustForRiley: public CommandBase
{
public:
	LeftyModeJustForRiley();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
