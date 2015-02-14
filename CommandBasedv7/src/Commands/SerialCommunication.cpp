#include <Commands/SerialCommunication.h>
#include "RobotMap.h"
#include "Compressor.h"

SerialCommunication::SerialCommunication()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(serialComs);
	i = 0;
}

// Called just before this Command runs the first time
void SerialCommunication::Initialize()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, "Initialized");
	//serialComs->SendData(new char('G'));
}

// Called repeatedly when this Command is scheduled to run
void SerialCommunication::Execute()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, "Running");
	if (i % FRAMES == FRAMES - 1) {
		i = 0;
		double value = serialComs->WaitForData();
		//serialComs->SendData((const char*)mecanumDrive->GetLidarValue(), 1);
		//double value = NO_DATA;
		if (value != NO_DATA)
		{
			mecanumDrive->SetGyroAngle(value);
		}
	}
	i++;
}

// Make this return true when this Command no longer needs to run execute()
bool SerialCommunication::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SerialCommunication::End()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SerialCommunication::Interrupted()
{
	SmartDashboard::PutString(T_SERIAL_RUNNING, "Interrupted");
}
