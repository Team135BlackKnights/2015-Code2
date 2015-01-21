#include "MecanumDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveJ.h"

MecanumDrive::MecanumDrive() :
	Subsystem("MecanumDrive")
{
		chassis = new RobotDrive(MOTOR_FRONT_LEFT, MOTOR_REAR_LEFT, MOTOR_FRONT_RIGHT, MOTOR_REAR_RIGHT);
}

void MecanumDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveJ());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void MecanumDrive::DriveJoysticks(float x, float y, float z)
{

	chassis->MecanumDrive_Cartesian(-x, -z, y);
}
