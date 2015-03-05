#ifndef InternalOpenCloseTopStack_H
#define InternalOpenCloseTopStack_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalSolenoidToteLock: public CommandBase
{
private:
	bool status;
public:
	InternalSolenoidToteLock(bool status=InternalCollect::TOTE_LOCK_OPEN);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
