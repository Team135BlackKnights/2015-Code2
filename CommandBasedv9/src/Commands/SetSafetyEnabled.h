#ifndef SetSafetyEnabled_H
#define SetSafetyEnabled_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetSafetyEnabled: public CommandBase
{
private:
	bool enabled;
public:
	SetSafetyEnabled(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
