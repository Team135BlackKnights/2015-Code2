#include <Commands/SerialCommunication.h>
#include "RobotMap.h"
#include "Compressor.h"

SerialCommunication::SerialCommunication()
{
	Requires(serialComs);
	i = 0;
}

void SerialCommunication::Initialize()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, S_INITIALIZED);
}

void SerialCommunication::Execute()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, S_RUNNING);
	if (i % FRAMES == FRAMES - 1) {
		i = 0;
		double value = serialComs->WaitForData();
		if (value == NO_DATA)
			value = 0;
		mecanumDrive->SetGyroAngle(value);
	}
	i++;
}

bool SerialCommunication::IsFinished() {return false;}

void SerialCommunication::End()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, S_ENDED);
}

void SerialCommunication::Interrupted()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, S_INTERRUPTED);
}
