#ifndef InternalCollection_H
#define InternalCollection_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalSolenoid: public CommandBase
{
private:
	bool engageSolenoid;
public:
	InternalSolenoid(bool=InternalCollect::COLLECT_DISENGAGED);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
