#ifndef SendSerialData_H
#define SendSerialData_H

#include "../CommandBase.h"
#include "WPILib.h"

class SendSerialData: public CommandBase
{
public:
	SendSerialData();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
