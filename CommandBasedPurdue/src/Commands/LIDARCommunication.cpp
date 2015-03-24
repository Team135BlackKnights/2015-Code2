#include "LIDARCommunication.h"
#include "RobotMap.h"

LIDARCommunication::LIDARCommunication()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(lidar);
	//Requires(lidarTwo);
	i = 0;
	step = 1;
	valueOne = 0;
	valueTwo = 0;
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
		switch (step) {
		case 1:
			lidar->Write();
			step++;
			break;
		case 2:
			lidar->Read();
			step++;
			break;
		case 3:
			mecanumDrive->SetLidarValue(lidar->GetData());
			step = 1;
			break;
		}
		SmartDashboard::PutNumber(T_LIDAR_STEP, step);
		/*
		switch(step)
		{
		case 1:	// enable the LIDAR
			//dio->Write(ON, ..);
			lidarOne->SetPowerEnable(true);
			SmartDashboard::PutNumber(T_LIDAR_STEP, 1);
			break;
		case 2:
			lidarOne->Write();
			SmartDashboard::PutNumber(T_LIDAR_STEP, 2);
			break;
		case 3:
			lidarOne->Read();
			SmartDashboard::PutNumber(T_LIDAR_STEP, 3);
			break;
		case 4:
			valueOne = lidarOne->GetData();
			SmartDashboard::PutNumber(T_LIDAR_STEP, 4);
			break;
		case 5:	// disable the LIDAR
			//dio->Write(OFF, ..);
			lidarOne->SetPowerEnable(false);
			//lidarTwo->SetPowerEnable(true);
			SmartDashboard::PutNumber(T_LIDAR_STEP, 5);
			break;
		case 6:
			//lidarTwo->Write();
			SmartDashboard::PutNumber(T_LIDAR_STEP, 6);
			break;
		case 7:
			//lidarTwo->Read();
			SmartDashboard::PutNumber(T_LIDAR_STEP, 7);
			break;
		case 8:
			//valueTwo = lidarTwo->GetData();
			SmartDashboard::PutNumber(T_LIDAR_STEP, 8);
			break;
		case 9:
			step = 0;
			//lidarTwo->SetPowerEnable(false);
			//lidar->WriteToLights((const char*)value, 2);
			mecanumDrive->SetLidarValues(valueOne, valueTwo);
			SmartDashboard::PutNumber(T_LIDAR_STEP, 9);
			break;
		}
		*/
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
	SmartDashboard::PutNumber(T_LIDAR_DISTANCE_VALUE, 0);
	SmartDashboard::PutNumber(T_LIDAR_DISTANCE_VOLTAGE, 0);
	SmartDashboard::PutNumber(T_LIDAR_STEP, 0);
}
