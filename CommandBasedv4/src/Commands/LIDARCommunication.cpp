#include "LIDARCommunication.h"
#include "RobotMap.h"

LIDARCommunication::LIDARCommunication()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(lidar);
	i = 0;
	step = 1;
}

// Called just before this Command runs the first time
void LIDARCommunication::Initialize()
{
	SmartDashboard::PutString(T_LIDAR_RUNNING, "Initialized");
}

// Called repeatedly when this Command is scheduled to run
void LIDARCommunication::Execute()
{
	SmartDashboard::PutString(T_LIDAR_RUNNING, "Running");
	if (i % FRAMES_PER_STEP == FRAMES_PER_STEP - 1)
	{
		i = 0;
		switch(step)
		{
		case 1:
			lidar->StepOne_Write();
			break;
		case 2:
			lidar->StepTwo_Read();
			break;
		case 3:
			int value = lidar->StepThree_GetData();
			step = 0;
			//lidar->WriteToLights((const char*)value, 2);
			mecanumDrive->SetLidarValue(value);
			break;
		}
		step++;
		//double value = NO_DATA;
		//if (value != NO_DATA)
		//{
		//	mecanumDrive->SetGyroAngle(value);
		//}
	}
	i++;
}

// Make this return true when this Command no longer needs to run execute()
bool LIDARCommunication::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LIDARCommunication::End()
{
	SmartDashboard::PutString(T_LIDAR_RUNNING, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LIDARCommunication::Interrupted()
{
	SmartDashboard::PutString(T_LIDAR_RUNNING, "Interrupted");
	SmartDashboard::PutNumber(T_LIDAR_DISTANCE, 0);
	SmartDashboard::PutNumber(T_LIDAR_STEP, 0);
}
