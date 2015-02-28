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


	bool useSetRobotAngle;
	double setRobotAngle;

	static const int 	FRONT_LEFT = 0,
						REAR_LEFT = 1,
						FRONT_RIGHT = 2,
						REAR_RIGHT = 3;

	int PIDValues[4][3] = {
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0}
	};

public:
	MecanumDrive();
	void InitDefaultCommand();
	void Drive(float, float, float, float=0);

	double GetGyroAngle();
	double SetGyroAngle(double);

	int GetLidarValueOne();
	int GetLidarValueTwo();
	void SetLidarValues(int, int);

	void Rotate(float);

	void SetSafetyEnabled(bool);

	void GetDriveVelocties(float*);

};

#endif
