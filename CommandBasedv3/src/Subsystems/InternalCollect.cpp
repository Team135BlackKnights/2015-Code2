#include "InternalCollect.h"
#include "../RobotMap.h"
#include "../Commands/DriveInternalCollect.h"

InternalCollect::InternalCollect() :
		Subsystem("InternalCollect")
{
	liftMotor = new Talon(5);
	liftMotorInverted = -1;

	collectMotor = new Talon(4);
	collectMotorInverted = 1;

	liftSolenoid = new Solenoid(0);
	liftSolenoidEngaged = false;

	collectSolenoid = new Solenoid(1);
}

void InternalCollect::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveInternalCollect());
}

void InternalCollect::DriveLift(float power)
{
// Put methods for controlling this subsystem
// here. Call these from Commands.
	liftMotor->Set(power * liftMotorInverted);
}

void InternalCollect::DriveCollect(float power)
{
	collectMotor->Set(power);
}

void InternalCollect::DriveCollectOut()
{
	DriveCollect(COLLECT_OUT_POWER);
}

void InternalCollect::DriveCollectIn() {
	DriveCollect(COLLECT_IN_POWER);
}

void InternalCollect::SetLiftSolenoid(bool engaged)
{
	liftSolenoidEngaged = engaged;
}

void InternalCollect::ControlLiftSolenoid()
{
	liftSolenoid->Set(liftSolenoidEngaged);
}

void InternalCollect::SetControlSolenoid(bool engaged)
{
	collectSolenoid->Set(engaged);
}
