#ifndef InternalRollers_H
#define InternalRollers_H

#include "../CommandBase.h"
#include "WPILib.h"

class InternalRollers: public CommandBase
{
private:
	float power;
public:
	InternalRollers(float power);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
