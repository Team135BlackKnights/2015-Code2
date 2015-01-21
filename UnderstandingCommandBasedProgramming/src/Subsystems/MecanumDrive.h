#ifndef MecanumDrive_H
#define MecanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "../Commands/DriveTeleop.h"
#include "../CommandBase.h"

class MecanumDrive: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive* chassis;
public:
	MecanumDrive();
	void InitDefaultCommand();
	void DriveJoysticks(int, int, int);
};

#endif
