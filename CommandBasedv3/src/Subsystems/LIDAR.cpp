#include "LIDAR.h"
#include "../RobotMap.h"
#include "../Commands/LIDARCommunication.h"

LIDAR::LIDAR() :
		Subsystem("LIDAR")
{
	distance = new unsigned char();
	I2CPort = new I2C(I2C::kMXP, LIDAR_ADDR);; // Opens & joins the irc bus as master
	//serialPort = new SerialPort(9600, SerialPort::kMXP);
}

void LIDAR::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new LIDARCommunication());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LIDAR::StepOne_Write()
{
	I2CPort->Write(LIDAR_CONFIG_REGISTER, 0x04); // Initiate measurement
	SmartDashboard::PutNumber(T_LIDAR_STEP, 1);
}

void LIDAR::StepTwo_Read()
{
	I2CPort->Read(LIDAR_DISTANCE_REGISTER, 2, distance); // Read in measurement
	SmartDashboard::PutNumber(T_LIDAR_STEP, 2);
}

int LIDAR::StepThree_GetData()
{
	SmartDashboard::PutNumber(T_LIDAR_STEP, 3);
	//SmartDashboard::PutNumber(T_LIDAR_DISTANCE, GetDistance());
	return GetDistance();
}

int LIDAR::GetDistance() {
	return (int)((unsigned long)(distance[0] << 8) + (unsigned int)(distance[1]));
}

void LIDAR::WriteToLights(const char* buffer, int32_t count)
{
	//serialPort->Write(buffer, count);
	SmartDashboard::PutString("Lights data output", buffer);
}
