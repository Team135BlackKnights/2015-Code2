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
	// Set the default command for a subsystem here.
	SetDefaultCommand(new SerialCommunication());
}

void SerialComs::SendData(const char* buffer, int32_t count)
{
	gyroPort->Write(buffer, count);
	//SmartDashboard::PutString("Lights data output", buffer);
}

double SerialComs::WaitForData()
{
	//SmartDashboard::PutBoolean("Trying to possibly get potential readings from the gyroscope", true);
	int bytes = gyroPort->GetBytesReceived();
	//SmartDashboard::PutNumber("Bytes Received", bytes);
	if (bytes > 0)
	{
		char *incomingData;
		incomingData = new char('\a');
		gyroPort->Read(incomingData, 10);
		double finalData = atof(incomingData);

		//SmartDashboard::PutNumber("gyro Value", finalData);

		gyroPort->Reset();
		return finalData;
	} else
	{
		return NO_DATA;
	}
}
