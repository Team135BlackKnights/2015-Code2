#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
//#include "../Commands/DriveJ.h"

class MecanumDrive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	//TalonSRX* motorSRX;
	CANTalon* motors[4];
	RobotDrive* chassis;
	int driveMode;
	double gyroAngle;
	int lidarValueOne;
	int lidarValueTwo;
	Compressor *compressor;
	static const int 	FRONT_LEFT = 0,
						REAR_LEFT = 1,
						FRONT_RIGHT = 2,
						REAR_RIGHT = 3;
public:
	static const int 	DRIVE_MODE_A = 0,
						DRIVE_MODE_B = 1,
						DRIVE_MODE_C = 2;
	MecanumDrive();
	void InitDefaultCommand();
	void DriveJoysticks(float, float, float);
	int GetDriveMode();
	int SetDriveMode(int);

	double GetGyroAngle();
	double SetGyroAngle(double);

	int GetLidarValueOne();
	int GetLidarValueTwo();
	void SetLidarValues(int, int);

	void Rotate(float);


};

#endif
