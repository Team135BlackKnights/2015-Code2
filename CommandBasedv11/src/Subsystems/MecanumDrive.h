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


	//bool useSetRobotAngle;
	//double setRobotAngle;

	double PIDValues[4][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
	};

public:

	static const int 	FRONT_LEFT = 0,
						REAR_LEFT = 1,
						FRONT_RIGHT = 2,
						REAR_RIGHT = 3;

	MecanumDrive();
	void InitDefaultCommand();
	void Drive(float x, float y, float z, float angle=0);

	double GetGyroAngle();
	double SetGyroAngle(double angle);

	void Rotate(float power);

	//void GetDriveVelocties(float*);
	//void GetMotorPIDValues(int, double*);
};

#endif
