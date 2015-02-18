#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../OI.h"

class MecanumDrive: public Subsystem
{
private:
	CANTalon* motors[4];
	RobotDrive* chassis;
	int driveMode;
	bool fieldOriented;
	double gyroAngle;
	int lidarValueOne;
	int lidarValueTwo;

	bool useSetRobotAngle;
	double setRobotAngle;

	static const int 	FRONT_LEFT = 0,
						REAR_LEFT = 1,
						FRONT_RIGHT = 2,
						REAR_RIGHT = 3;
public:
	static const int 	DRIVE_MODE_A = OI::MISC_CHANGE_DRIVE_MODE_A,
						DRIVE_MODE_B = OI::MISC_CHANGE_DRIVE_MODE_B;

	static const bool 	FIELD_ORIENTED_ENABLED = true,
						FIELD_ORIENTED_DISABLED = !FIELD_ORIENTED_ENABLED;
	MecanumDrive();
	void InitDefaultCommand();
	void Drive(float, float, float);
	int GetDriveMode();
	int SetDriveMode(int);

	double GetGyroAngle();
	double SetGyroAngle(double);

	int GetLidarValueOne();
	int GetLidarValueTwo();
	void SetLidarValues(int, int);

	void Rotate(float);
	void SetFieldOriented(bool);

	void SetSafetyEnabled(bool);

};

#endif
