#include "InternalCollect.h"
#include "../RobotMap.h"
#include "../Commands/DriveInternalCollect.h"

InternalCollect::InternalCollect() :
		Subsystem("InternalCollect")
{
	motors[LEFT] = new Talon(MOTOR_INTERNAL_COLLECT_LEFT);
	motors[RIGHT] = new Talon(MOTOR_INTERNAL_COLLECT_RIGHT);
	inverted = -1;
}

void InternalCollect::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveInternalCollect());
}

void InternalCollect::SetMotorPower(float power)
{
// Put methods for controlling this subsystem
// here. Call these from Commands.
	for (int i = 0; i < 2; i++)
	{
		motors[i]->Set(power * (inverted == i ? -1 : 1));
	}
}
