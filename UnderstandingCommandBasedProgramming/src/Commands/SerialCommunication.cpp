#include <Commands/SerialCommunication.h>
#include <stdlib.h>

SerialCommunication::SerialCommunication()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(mecanumDrive2);
	dataPort = mecanumDrive2->GetGryoPort();
	receivedData = NULL;
	finalData = NULL;
}

// Called just before this Command runs the first time
void SerialCommunication::Initialize()
{
	dataPort->Write(sentData, 1);
}

// Called repeatedly when this Command is scheduled to run
void SerialCommunication::Execute()
{
	while (dataPort->GetBytesReceived() > 0)
	{
		int i = 0;
		char *incomingData;
		dataPort->Read(incomingData, 1);
		if (incomingData == '/n')
			return;
		else
		{
			receivedData[i] = incomingData;
			i++;
		}
	}
	if (receivedData != NULL)
	{
		finalData = atof(receivedData);
		mecanumDrive2->SetGyroAngle(finalData);
		smartDashboard->PutNumber("gyro Value", finalData);
		finalData = NULL;
		receivedData = NULL;
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

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SerialCommunication::Interrupted()
{

}
