#include <Commands/InternalSolenoidRoller.h>
#include <Commands/InternalSolenoidToteLock.h>
#include "InternalCollect.h"
#include "../RobotMap.h"
#include "../Commands/DriveInternalCollect.h"
#include <math.h>

InternalCollect::InternalCollect() :
		Subsystem("InternalCollect")
{
	collectLeftMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_LEFT);
	collectRightMotor = new VictorSP(MOTOR_INTERNAL_COLLECT_RIGHT);

	rollerCollectSolenoid = new Solenoid(SOLENOID_INTERNAL_COLLECT);
	rollerCollectEngaged = SmartDashboard::GetBoolean(T_ROLLER_COLLECT_ENGAGED, ROLLER_COLLECT_DISENGAGED);
	toteLockSolenoid = new Solenoid(SOLENOID_INTERNAL_UPPER_STACK);
	toteLockEngaged = SmartDashboard::GetBoolean(T_TOTE_LOCK_ENGAGED, TOTE_LOCK_ENGAGED);

	winch = new Winch(MOTOR_INTERNAL_WINCH, DIGITAL_INTERNAL_LOWER, DIGITAL_INTERNAL_UPPER, INVERTED_INTERNAL_WINCH);

	collectPower = 0;
}

void InternalCollect::InitDefaultCommand()
{

	SetDefaultCommand(new DriveInternalCollect());
}

void InternalCollect::DriveLift(float power)
{
	winch->DriveWinch(power);


}

void InternalCollect::DriveCollect()
{
	collectLeftMotor->Set(collectPower * COLLECT_LEFT_INVERTED);
	collectRightMotor->Set(collectPower * COLLECT_RIGHT_INVERTED);
	rollerCollectSolenoid->Set(rollerCollectEngaged);
	toteLockSolenoid->Set(toteLockEngaged);
}

void InternalCollect::SetRollerCollectSolenoid(bool engaged)
{
	rollerCollectEngaged = engaged;
}

void InternalCollect::SetToteLockSolenoid(bool engaged)
{
	toteLockEngaged = engaged;
}

void InternalCollect::SetCollectPower(float power)
{
	collectPower = power;
}

