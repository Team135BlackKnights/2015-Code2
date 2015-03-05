#ifndef InternalCollection_H
#define InternalCollection_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalSolenoidRoller: public CommandBase
{
private:
	bool state;
public:
	InternalSolenoidRoller(bool state=InternalCollect::ROLLER_COLLECT_OPEN);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
