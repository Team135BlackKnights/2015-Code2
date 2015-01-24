#ifndef SendSerialData_H
#define SendSerialData_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <string.h>

class SerialCommunication: public CommandBase
{
private:
	const char *sentData = 'G';
	char receivedData[8];
	double finalData;
	SerialPort *dataPort;
public:
	SerialCommunication();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
