#include "MechanumDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveTeleop.h"

Mecanum::Mecanum() :
		Subsystem("MecanumDrive")
{

}

void Mecanum::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveTeleop());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
