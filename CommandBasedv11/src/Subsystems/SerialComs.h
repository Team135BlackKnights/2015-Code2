#ifndef SerialComs_H
#define SerialComs_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SerialComs: public Subsystem
{
private:
	SerialPort *gyroPort;
	const int BAUD_RATE = 9600;
public:
	SerialComs();
	void InitDefaultCommand();
	void SendData(const char* buffer, int32_t count);
	double WaitForData();
};

#endif
