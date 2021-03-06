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
	RobotDrive* chassis;
	int driveMode;
	double gyroAngle;
public:
	static const int 	SRX_SRY_SRZ = 0,
						SRX_SRY_SLZ = 1;
	MecanumDrive();
	void InitDefaultCommand();
	void DriveJoysticks(float, float, float);
	int GetDriveMode();
	int SetDriveMode(int);
	double GetGyroAngle();
	double SetGyroAngle(double);
};

#endif
