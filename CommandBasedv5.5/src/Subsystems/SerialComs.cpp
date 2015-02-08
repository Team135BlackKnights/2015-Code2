#include "SerialComs.h"
#include "../RobotMap.h"
#include "../Commands/SerialCommunication.h"

SerialComs::SerialComs() :
		Subsystem("SerialComs")
{
	gyroPort = new SerialPort(BAUD_RATE, SerialPort::kMXP);
	//dataToSend = 'G';
	gyroPort->EnableTermination('\n');
	//gyroPort->
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
	//gyroPort->
	SmartDashboard::PutString("Lights data output", buffer);
}

double SerialComs::WaitForData()
{
	SmartDashboard::PutBoolean("Trying to possibly get potential readings from the gyroscope", true);
	//if (gyroPort->GetBytesReceived() > 0)
	int bytes = gyroPort->GetBytesReceived();
	SmartDashboard::PutNumber("Bytes Received", bytes);
	if (bytes > 0)
	{
		//gyroPort->Reset();

		char *incomingData;
		incomingData = new char('\a');
		gyroPort->Read(incomingData, 10);
		double finalData = atof(incomingData);

		SmartDashboard::PutNumber("gyro Value", finalData);

		gyroPort->Reset();
		return finalData;

		//return NO_DATA;
	} else
	{
		return NO_DATA;
	}
}
