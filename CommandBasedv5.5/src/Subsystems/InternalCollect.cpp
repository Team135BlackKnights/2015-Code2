#include "InternalCollect.h"
#include "../RobotMap.h"
#include "../Commands/DriveInternalCollect.h"

InternalCollect::InternalCollect() :
		Subsystem("InternalCollect")
{
	liftMotor = new VictorSP(MOTOR_INTERNAL_WINCH);
	collectLeftMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_LEFT);
	collectRightMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_RIGHT);

	collectSolenoid = new Solenoid(SOLENOID_INTERNAL_COLLECT);
	collectEngaged = COLLECT_DISENGAGED;

	//liftSolenoid = new Solenoid(0);
	//liftSolenoidEngaged = false;

	//collectSolenoid = new Solenoid(1);
}

void InternalCollect::InitDefaultCommand()
{

	SetDefaultCommand(new DriveInternalCollect());
}

void InternalCollect::DriveLift(float power)
{

	liftMotor->Set(power);
}

void InternalCollect::DriveCollect(float power)
{
	collectLeftMotor->Set(power * COLLECT_LEFT_INVERTED);
	collectRightMotor->Set(power * COLLECT_RIGHT_INVERTED);
}

void InternalCollect::DriveCollectOut()
{
	DriveCollect(.8);
}

void InternalCollect::DriveCollectIn() {
	DriveCollect(.6);
}

void InternalCollect::SetCollectSolenoid(bool engaged)
{
	collectEngaged = engaged;
	collectSolenoid->Set(engaged);
}
