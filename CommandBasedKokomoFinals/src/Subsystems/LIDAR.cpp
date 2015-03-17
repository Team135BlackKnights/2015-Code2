#include "LIDAR.h"
#include "../RobotMap.h"
#include "../Commands/LIDARCommunication.h"

LIDAR::LIDAR() :
		Subsystem("LIDAR")
{
	distance = new unsigned char[2];
	I2CPort = new I2C(I2C::kMXP, LIDAR_ADDR); // Opens & joins the irc bus as master
	//serialPort = new SerialPort(9600, SerialPort::kMXP);
	powerEnable = new DigitalOutput(0);
	//if (port == DIGITAL_LIDAR_ONE)
		debugOutputKey = T_LIDAR_DISTANCE_ONE;
	//else
		//debugOutputKey = T_LIDAR_DISTANCE_TWO;
}

void LIDAR::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new LIDARCommunication());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void LIDAR::Write()
{
	I2CPort->Write(LIDAR_CONFIG_REGISTER, 0x04); // Initiate measurement
}

void LIDAR::Read()
{
	I2CPort->Read(LIDAR_DISTANCE_REGISTER, 2, distance); // Read in measurement
}

int LIDAR::GetData()
{
	int value = GetDistance();
	SmartDashboard::PutNumber(debugOutputKey, value);
	return value;
}

int LIDAR::GetDistance() {
	SmartDashboard::PutBoolean("GETTING DISTANCE", true);
	SmartDashboard::PutNumber("LIDAR High", distance[0]);
	SmartDashboard::PutNumber("LIDAR Low", distance[1]);
	return (int)((unsigned long)(distance[0] << 8) + (unsigned int)(distance[1]));
}

void LIDAR::WriteToLights(const char* buffer, int32_t count)
{
	//serialPort->Write(buffer, count);
	SmartDashboard::PutString("Lights data output", buffer);
}

void LIDAR::SetPowerEnable(bool enable)
{
	powerEnable->Set(enable);
}
