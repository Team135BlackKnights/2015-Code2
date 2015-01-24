#include "MecanumDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveJ.h"

MecanumDrive::MecanumDrive() :
	Subsystem("MecanumDrive")
{
		chassis = new RobotDrive(MOTOR_FRONT_LEFT, MOTOR_REAR_LEFT, MOTOR_FRONT_RIGHT, MOTOR_REAR_RIGHT);
		driveMode = this->SRX_SRY_SRZ;
		chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		gyroPort = new SerialPort(BAUD_RATE, SerialPort::kMXP);
		gyroAngle = 0;
}

void MecanumDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveJ());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void MecanumDrive::DriveJoysticks(float x, float y, float z)
{
	chassis->MecanumDrive_Cartesian(x, y, z, gyroAngle);
}

int MecanumDrive::GetDriveMode()
{
	return driveMode;
}

int MecanumDrive::SetDriveMode(int mode)
{
	return driveMode = mode;
}

SerialPort *MecanumDrive::GetGyroPort()
{
	return gyroPort;
}

double MecanumDrive::GetGyroAngle()
{
	return gyroAngle;
}

SerialPort* MecanumDrive::GetGryoPort()
{
	return gyroPort;
}

double MecanumDrive::SetGyroAngle(double angle)
{
	return gyroAngle = angle;
}
