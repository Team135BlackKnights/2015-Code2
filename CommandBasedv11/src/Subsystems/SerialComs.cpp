#include "SerialComs.h"
#include "../RobotMap.h"
#include "../Commands/SerialCommunication.h"

SerialComs::SerialComs() :
		Subsystem("SerialComs")
{
	gyroPort = new SerialPort(BAUD_RATE, SerialPort::kMXP);
	gyroPort->EnableTermination('\n');
	gyroPort->SetTimeout(20);
}

void SerialComs::InitDefaultCommand()
{
	SetDefaultCommand(new SerialCommunication());
}

void SerialComs::SendData(const char* buffer, int32_t count)
{
	gyroPort->Write(buffer, count);
}

double SerialComs::WaitForData()
{
	int bytes = gyroPort->GetBytesReceived();
	if (bytes > 0)
	{
		char *incomingData;
		incomingData = new char('\a');
		gyroPort->Read(incomingData, 10);
		double finalData = atof(incomingData);

		gyroPort->Reset();
		return finalData;
	} else
	{
		return NO_DATA;
	}
}
