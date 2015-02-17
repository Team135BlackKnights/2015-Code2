#ifndef SetFieldOriented_H
#define SetFieldOriented_H

#include "../CommandBase.h"
#include "WPILib.h"

class SetFieldOriented: public CommandBase
{
private:
	bool mode;
public:
	SetFieldOriented(bool);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
