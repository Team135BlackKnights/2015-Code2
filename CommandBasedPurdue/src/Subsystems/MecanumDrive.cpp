#include "MecanumDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveJ.h"
#include <cmath>

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
		lidarValue = 0;
		lidarVoltage = 0;
		chassis->SetSafetyEnabled(false);

		useSetRobotAngle = false;//SmartDashboard::GetBoolean(T_USE_SET_ROBOT_ANGLE, false);
		setRobotAngle = 0;//SmartDashboard::GetNumber(T_SET_ROBOT_ANGLE, 0);

		/*
		for (int i = 0; i < NUM_MOTORS; i++)
		{
			motors[i]->SetPID(PIDValues[i][0], PIDValues[i][1], PIDValues[i][2]);

		}
		*/
		gyro = new Gyro(ANALOG_GYRO_A);
		gyro->Reset();

		accel = new BuiltInAccelerometer(Accelerometer::kRange_8G);
		timer = new Timer();
		lastVelocityX = 0;
		distanceX = 0;

		lidar = new AnalogInput(ANALOG_LIDAR);
}

void MecanumDrive::InitDefaultCommand()
{

	SetDefaultCommand(new DriveJ());
	timer->Start();
	gyro->Reset();
	lidar->ResetAccumulator();
	lidarValue = lidar->GetValue();
	lidarVoltage = lidar->GetVoltage();
}


void MecanumDrive::Drive(float x, float y, float z, float angle)
{
	GetSensorValues();
	//SynthesizeAccel();
	SmartDashboard::PutNumber(T_GYRO_ANGLE, gyroAngle);
	SmartDashboard::PutBoolean(T_USE_SET_ROBOT_ANGLE, useSetRobotAngle);
	SmartDashboard::PutBoolean(T_SET_ROBOT_ANGLE, setRobotAngle);
	SmartDashboard::PutNumber(T_LIDAR_DISTANCE_VALUE, lidarValue);
	SmartDashboard::PutNumber(T_LIDAR_DISTANCE_VOLTAGE, lidarVoltage);

	//float angle = oi. ? gyroAngle : 0;
	SmartDashboard::PutNumber("ANGLE FIELD THING", angle);
	chassis->MecanumDrive_Cartesian(x, y, z, angle);
  //std::ofstream outfile ("EncoderTest.txt",std::ofstream::out);

  //outfile.write((const char*)motors[FRONT_LEFT]->GetEncVel() + '\n', 5);

  //outfile.close();
	SmartDashboard::PutNumber("Delta Time Max", 0);
}

void MecanumDrive::GetSensorValues()
{
	gyroAngle = gyro->GetAngle();

	int oldValue = lidarValue;
	lidarValue = lidar->GetValue();
	lidarVoltage = lidar->GetAverageValue();


	SmartDashboard::PutNumber("LIDAR Jump", fmax(SmartDashboard::GetNumber("LIDAR Jump", 0), lidarValue - oldValue));
}

void MecanumDrive::SynthesizeAccel()
{
	double currentVelocityX, accelerationX;
	double deltaTime;

	//X DISTANCE
	deltaTime = timer->Get();
	SmartDashboard::PutNumber("Delta Time Max", fmax(SmartDashboard::GetNumber("Delta Time Max", 0), deltaTime));
	timer->Stop();
	timer->Reset();
	timer->Start();
	accelerationX = accel->GetX();
	//distanceX = (lastVelocityX * deltaTime) + (.5 * accelerationX * deltaTime * deltaTime);
	currentVelocityX = lastVelocityX + accelerationX * deltaTime;
	distanceX = (currentVelocityX + lastVelocityX) * deltaTime / 2;
	SmartDashboard::PutNumber("Distance X", distanceX);
	lastVelocityX = currentVelocityX;
}

float MecanumDrive::GetGyroAngle()
{
	gyroAngle = gyro->GetAngle();
	return gyroAngle;
}

float MecanumDrive::SetGyroAngle(float angle)
{
	//SmartDashboard::PutNumber(T_GYRO_ANGLE, angle);
	return 0;
	//gyroAngle = angle;
}

int MecanumDrive::GetLidarValue()
{
	return lidarValue;
}
void MecanumDrive::SetLidarValue(int valueOne)
{
	int jump = valueOne - lidarValue;
	SmartDashboard::PutNumber("LIDAR Jump", fmax(SmartDashboard::GetNumber("LIDAR Jump", 0), jump));
	lidarValue = valueOne;
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
		velocityArray[i] = abs(motors[i]->GetEncVel());
	}
}

void MecanumDrive::GetMotorPIDValues(int index, double* values)
{
		values[0] = motors[index]->GetP();
		values[1] = motors[index]->GetI();
		values[2] = motors[index]->GetD();
}
