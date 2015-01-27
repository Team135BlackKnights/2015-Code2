#include "SerialComs.h"
#include "../RobotMap.h"
#include "../Commands/SerialCommunication.h"

SerialComs::SerialComs() :
		Subsystem("ExampleSubsystem")
{
	gyroPort = new SerialPort(BAUD_RATE, SerialPort::kMXP);
	//dataToSend = 'G';
}

void SerialComs::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new SerialCommunication());
}

void SerialComs::WaitForData()
{
	SmartDashboard::PutBoolean("Trying to possibly get potential readings from the gyroscope", true);
	if (gyroPort->GetBytesReceived() > 0)
	{
		char *incomingData;
		gyroPort->Read(incomingData, 10);
		double finalData = atof(incomingData);

		SmartDashboard::PutNumber("gyro Value", finalData);
	}
}
