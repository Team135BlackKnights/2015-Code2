#include <Commands/InternalSolenoid.h>
#include "InternalCollect.h"
#include "../RobotMap.h"
#include "../Commands/DriveInternalCollect.h"
#include <math.h>
#include "Commands/InternalOpenCloseTopStack.h"

InternalCollect::InternalCollect() :
		Subsystem("InternalCollect")
{
	//liftMotor = new VictorSP(MOTOR_INTERNAL_WINCH);
	collectLeftMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_LEFT);
	collectRightMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_RIGHT);

	collectSolenoid = new Solenoid(SOLENOID_INTERNAL_COLLECT);
	collectEngaged = ROLLER_COLLECT_DISENGAGED;
	upperStackSolenoid = new Solenoid(SOLENOID_INTERNAL_UPPER_STACK);
	upperStackEngaged = UPPER_STACK_DISENGAGED;

	//lowerWinchLimit = new DigitalInput(DIGITAL_INTERNAL_LOWER);
	//upperWinchLimit = new DigitalInput(DIGITAL_INTERNAL_UPPER);
	//lowerWinchLimit = NULL;

	winch = new Winch(MOTOR_INTERNAL_WINCH, DIGITAL_INTERNAL_LOWER, DIGITAL_INTERNAL_UPPER, INVERTED_INTERNAL_WINCH);

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
	//if (lowerWinchLimit->Get())
		//power = fmax(power, 0);
	//else if (upperWinchLimit->Get())
		//power = fmin(power, 0);
	//if (lowerWinchLimit != NULL && lowerWinchLimit->Get())
		//power = fmax(power, 0);
	winch->DriveWinch(power);


}

void InternalCollect::DriveCollect()
{
	collectLeftMotor->Set(collectPower * COLLECT_LEFT_INVERTED);
	collectRightMotor->Set(collectPower * COLLECT_RIGHT_INVERTED);
	collectSolenoid->Set(collectEngaged);
	upperStackSolenoid->Set(upperStackEngaged);
}

void InternalCollect::SetRollerCollectSolenoid(bool engaged)
{
	collectEngaged = engaged;
}

void InternalCollect::SetUpperStackSolenoid(bool engaged)
{
	upperStackEngaged = engaged;
}

void InternalCollect::SetCollectPower(float power)
{
	collectPower = power;
}

