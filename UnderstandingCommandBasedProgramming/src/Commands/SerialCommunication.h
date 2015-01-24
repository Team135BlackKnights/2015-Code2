#ifndef SendSerialData_H
#define SendSerialData_H

#include "../CommandBase.h"
#include "WPILib.h"
#include <string.h>

class SerialCommunication: public CommandBase
{
private:
	const char *sentData;
	const static int MAX_CHARS = 8;
	char receivedData[MAX_CHARS];
	double finalData;
	SerialPort *dataPort;
	bool needToWrite;
public:
	SerialCommunication();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
