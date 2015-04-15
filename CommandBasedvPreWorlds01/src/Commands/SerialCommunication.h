#ifndef SendSerialData_H
#define SendSerialData_H

#include "../CommandBase.h"
#include "WPILib.h"
//#include <string.h>

class SerialCommunication: public CommandBase
{
private:
	int i;
	const int FRAMES = 75;
public:
	SerialCommunication();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
