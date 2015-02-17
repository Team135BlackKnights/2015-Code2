#ifndef InternalOpenCloseTopStack_H
#define InternalOpenCloseTopStack_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalOpenCloseTopStack: public CommandBase
{
private:
	bool status;
public:

	InternalOpenCloseTopStack(bool=InternalCollect::UPPER_STACK_DISENGAGED);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
