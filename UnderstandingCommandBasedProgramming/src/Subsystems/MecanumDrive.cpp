#include "MecanumDrive.h"
#include "../RobotMap.h"


MecanumDrive::MecanumDrive() :
	Subsystem("MecanumDrive"),
	chassis(MOTOR_FRONT_LEFT, MOTOR_REAR_LEFT, MOTOR_FRONT_RIGHT, MOTOR_REAR_RIGHT)
{

}

void MecanumDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(DriveTeleop);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void MecanumDrive::DriveJoysticks(int x, int y, int z)
{

	chassis->MecanumDrive_Cartesian(x, y, z);
}
