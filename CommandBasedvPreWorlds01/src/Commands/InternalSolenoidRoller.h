#ifndef InternalCollection_H
#define InternalCollection_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalSolenoidRoller: public CommandBase
{
private:
	bool engageSolenoid;
public:
	InternalSolenoidRoller(bool=InternalCollect::ROLLER_COLLECT_DISENGAGED);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
