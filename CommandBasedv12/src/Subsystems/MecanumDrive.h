#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../OI.h"
#include <fstream>

class MecanumDrive: public Subsystem
{
public:
	static const int NUM_MOTORS = 4;
private:
	CANTalon* motors[NUM_MOTORS];

	RobotDrive* chassis;
	double gyroAngle;
	int lidarValueOne;
	int lidarValueTwo;

	Gyro* gyro;


	bool useSetRobotAngle;
	float setRobotAngle;


	double PIDValues[4][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
	};

	Accelerometer *accel;
	Timer *timer;
	double lastVelocityX;
	double distanceX;
	AnalogInput *lidar;

public:

	static const int 	FRONT_LEFT = 0,
						REAR_LEFT = 1,
						FRONT_RIGHT = 2,
						REAR_RIGHT = 3;

	MecanumDrive();
	void InitDefaultCommand();
	void Drive(float, float, float, float=0);

	float GetGyroAngle();
	float SetGyroAngle(float);

	int GetLidarValue();
	void SetLidarValue(int);

	void Rotate(float);

	void SetSafetyEnabled(bool);

	void GetDriveVelocties(float*);

	void GetMotorPIDValues(int, double*);

	void SynthesizeAccel();

	void GetSensorValues();
};

#endif
