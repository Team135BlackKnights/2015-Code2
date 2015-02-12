#ifndef BackUp_H
#define BackUp_H

#include "../CommandBase.h"
#include "WPILib.h"

class BackUp: public CommandBase
{
private:
	int i;
public:
	BackUp();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
