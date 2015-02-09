#ifndef InternalCollection_H
#define InternalCollection_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalCollection: public CommandBase
{
private:
	bool engageSolenoid;
	float power;
public:
	InternalCollection(float, bool=InternalCollect::COLLECT_DISENGAGED);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
