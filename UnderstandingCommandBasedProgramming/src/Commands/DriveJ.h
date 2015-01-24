#ifndef DriveTeleop_H
#define DriveTeleop_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveJ: public CommandBase
{
private:
	const char *sentData = 'G';
	char receivedData[8];
	double finalData;
	SerialPort *dataPort;
public:
	DriveJ();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
