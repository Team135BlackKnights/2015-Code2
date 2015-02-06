#include "ExternalCollect.h"
#include "../RobotMap.h"

ExternalCollect::ExternalCollect() :
		Subsystem("ExternalCollect")
{
	claw = new Solenoid(0);
}

void ExternalCollect::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand()
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
