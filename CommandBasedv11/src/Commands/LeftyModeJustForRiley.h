#ifndef LeftyModeJustForRiley_H
#define LeftyModeJustForRiley_H

#include "../CommandBase.h"
#include "WPILib.h"

class LeftyModeJustForRiley: public CommandBase
{
private:
	bool mode;
public:
	LeftyModeJustForRiley(bool mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
