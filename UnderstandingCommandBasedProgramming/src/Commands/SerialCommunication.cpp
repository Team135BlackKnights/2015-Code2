#include <Commands/SerialCommunication.h>
#include "RobotMap.h"

SerialCommunication::SerialCommunication()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(mecanumDrive);
	dataPort = mecanumDrive->GetGyroPort();
	sentData = new char('G');
	finalData = 0;
	needToWrite = true;
}

// Called just before this Command runs the first time
void SerialCommunication::Initialize()
{
	needToWrite = false;
	dataPort->Write(sentData, 1);
	SmartDashboard::PutBoolean(SERIAL_RUNNING, true);
}

// Called repeatedly when this Command is scheduled to run
void SerialCommunication::Execute()
{
	while (dataPort->GetBytesReceived() > 0)
	{
		needToWrite = true;
		int i = 0;
		char *incomingData;
		char *newLine;
		dataPort->Read(incomingData, 1);
		if (incomingData == newLine)
			return;
		else
		{
			receivedData[i] = *incomingData;
			i++;
		}
	}

	//dataPort->Read(receivedData, 8);
	if (needToWrite == true)
	{
		finalData = atof(receivedData);
		mecanumDrive2->SetGyroAngle(finalData);
		SmartDashboard::PutNumber("gyro Value", finalData);
		finalData = 0;
		for(int i = 0; i < MAX_CHARS; i++)
		{
			receivedData[i] = NULL;
		}
		dataPort->Write(sentData, 1);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SerialCommunication::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SerialCommunication::End()
{
	SmartDashboard::PutBoolean(SERIAL_RUNNING, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SerialCommunication::Interrupted()
{
	SmartDashboard::PutBoolean(SERIAL_RUNNING, false);
}
