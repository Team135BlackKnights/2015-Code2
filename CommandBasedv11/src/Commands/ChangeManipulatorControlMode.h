#ifndef ChangeManipulatorControlMode_H
#define ChangeManipulatorControlMode_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChangeManipulatorControlMode: public CommandBase
{
private:
	bool mode;
public:
	ChangeManipulatorControlMode(bool mode);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
