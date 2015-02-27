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
		chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		gyroAngle = 0;
		lidarValueOne = 0;
		lidarValueTwo = 0;
		chassis->SetSafetyEnabled(false);

		useSetRobotAngle = SmartDashboard::GetBoolean(T_USE_SET_ROBOT_ANGLE, false);
		setRobotAngle = SmartDashboard::GetNumber(T_SET_ROBOT_ANGLE, 0);
}

void MecanumDrive::InitDefaultCommand()
{

	SetDefaultCommand(new DriveJ());

}


void MecanumDrive::Drive(float x, float y, float z, float angle)
{
	SmartDashboard::PutNumber(T_GYRO_ANGLE, gyroAngle);
	SmartDashboard::PutBoolean(T_USE_SET_ROBOT_ANGLE, useSetRobotAngle);
	SmartDashboard::PutBoolean(T_SET_ROBOT_ANGLE, setRobotAngle);

	//float angle = oi. ? gyroAngle : 0;
	SmartDashboard::PutNumber("ANGLE FIELD THING", angle);
	chassis->MecanumDrive_Cartesian(x, y, z, angle);
  std::ofstream outfile ("EncoderTest.txt",std::ofstream::out);

  outfile.write((const char*)motors[FRONT_LEFT]->GetEncVel() + '\n', 5);

  outfile.close();
}

double MecanumDrive::GetGyroAngle()
{
	return gyroAngle;
}

double MecanumDrive::SetGyroAngle(double angle)
{
	//SmartDashboard::PutNumber(T_GYRO_ANGLE, angle);
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

void MecanumDrive::SetSafetyEnabled(bool enabled)
{
	chassis->SetSafetyEnabled(enabled);
}

void MecanumDrive::GetDriveVelocties(float* velocityArray)
{
	for (int i = 0; i < NUM_MOTORS; i++)
	{
		velocityArray[i] = motors[i]->GetEncVel();
	}
}
