#ifndef SerialComs_H
#define SerialComs_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SerialComs: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	SerialPort *gyroPort;
	const int BAUD_RATE = 9600;
public:
	SerialComs();
	void InitDefaultCommand();
	void SendData(const char*);
	double WaitForData();
};

#endif
