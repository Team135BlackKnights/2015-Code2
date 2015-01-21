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
public:
	MecanumDrive();
	void InitDefaultCommand();
	void DriveJoysticks(float, float, float);
};

#endif
