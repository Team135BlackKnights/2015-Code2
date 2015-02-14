#include <Commands/InternalSolenoid.h>
#include "InternalCollect.h"
#include "../RobotMap.h"
#include "../Commands/DriveInternalCollect.h"
#include "Commands/RunInternalDownUntilStopped.h"
#include "Commands/RunInternalUpUntilStopped.h"
#include <math.h>

InternalCollect::InternalCollect() :
		Subsystem("InternalCollect")
{
	liftMotor = new VictorSP(MOTOR_INTERNAL_WINCH);
	collectLeftMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_LEFT);
	collectRightMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_RIGHT);

	collectSolenoid = new Solenoid(SOLENOID_INTERNAL_COLLECT);
	collectEngaged = COLLECT_DISENGAGED;

	lowerWinchLimit = new DigitalInput(DIGITAL_INTERNAL_LOWER);
	upperWinchLimit = new DigitalInput(DIGITAL_INTERNAL_UPPER);
	//lowerWinchLimit = NULL;

	collectPower = 0;

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
	power *= WINCH_INVERTED;
	if (lowerWinchLimit->Get())
		power = fmax(power, 0);
	else if (upperWinchLimit->Get())
		power = fmin(power, 0);
	//if (lowerWinchLimit != NULL && lowerWinchLimit->Get())
		//power = fmax(power, 0);
	liftMotor->Set(power);


}

void InternalCollect::DriveCollect()
{
	collectLeftMotor->Set(collectPower * COLLECT_LEFT_INVERTED);
	collectRightMotor->Set(collectPower * COLLECT_RIGHT_INVERTED);
	collectSolenoid->Set(collectEngaged);
}

void InternalCollect::SetCollectSolenoid(bool engaged)
{
	collectEngaged = engaged;
}

bool InternalCollect::GetLimitSwitchValueUpper()
{
	return upperWinchLimit->Get();
}

bool InternalCollect::GetLimitSwitchValueLower()
{
	return lowerWinchLimit->Get();
}

void InternalCollect::SetCollectPower(float power)
{
	collectPower = power;
}

