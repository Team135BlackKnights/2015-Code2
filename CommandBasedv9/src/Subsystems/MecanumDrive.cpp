#include "MecanumDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveJ.h"

MecanumDrive::MecanumDrive() :
	Subsystem("MecanumDrive")
{
		motors[FRONT_LEFT] = new CANTalon(MOTOR_FRONT_LEFT);
		motors[REAR_LEFT] = new CANTalon(MOTOR_REAR_LEFT);
		motors[FRONT_RIGHT] = new CANTalon(MOTOR_FRONT_RIGHT);
		motors[REAR_RIGHT] = new CANTalon(MOTOR_REAR_RIGHT);

		chassis = new RobotDrive(motors[FRONT_LEFT], motors[REAR_LEFT], motors[FRONT_RIGHT], motors[REAR_RIGHT]);
		driveMode = DRIVE_MODE_B;
		chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		gyroAngle = 0;
		lidarValueOne = 0;
		lidarValueTwo = 0;
		chassis->SetSafetyEnabled(false);
		fieldOriented = FIELD_ORIENTED_DISENABLED;
}

void MecanumDrive::InitDefaultCommand()
{

	SetDefaultCommand(new DriveJ());

}


void MecanumDrive::Drive(float x, float y, float z)
{
	float angle = fieldOriented ? gyroAngle : 0;
	chassis->MecanumDrive_Cartesian(x, -y, z, angle);
}

int MecanumDrive::GetDriveMode()
{
	return driveMode;
}

int MecanumDrive::SetDriveMode(int mode)
{
	return driveMode = mode;
}

double MecanumDrive::GetGyroAngle()
{
	return gyroAngle;
}

double MecanumDrive::SetGyroAngle(double angle)
{
	SmartDashboard::PutNumber("MecanumDrive Gyro Angle", angle);
	return gyroAngle = angle;
}

int MecanumDrive::GetLidarValueOne()
{
	return lidarValueOne;
}

int MecanumDrive::GetLidarValueTwo()
{
	return lidarValueTwo;
}

void MecanumDrive::SetLidarValues(int valueOne, int valueTwo)
{
	lidarValueOne = valueOne;
	lidarValueTwo = valueTwo;
}

void MecanumDrive::Rotate(float power)
{
	chassis->MecanumDrive_Cartesian(0, 0, power);
}

void MecanumDrive::SetFieldOriented(bool mode)
{
	fieldOriented = mode;
}

void MecanumDrive::SetSafetyEnabled(bool enabled)
{
	chassis->SetSafetyEnabled(enabled);
}
