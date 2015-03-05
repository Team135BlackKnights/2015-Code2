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
	rollerCollectState = ROLLER_COLLECT_OPEN;
	toteLockSolenoid = new Solenoid(SOLENOID_INTERNAL_TOTE_LOCK);
	toteLockState = TOTE_LOCK_OPEN;

	winch = new Winch(MOTOR_INTERNAL_WINCH,/* DIGITAL_INTERNAL_LOWER, DIGITAL_INTERNAL_UPPER, */INVERTED_INTERNAL_WINCH);

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
	SmartDashboard::PutNumber(T_INTERNAL_ROLLER_POWER, collectPower);
	collectLeftMotor->Set(collectPower * COLLECT_LEFT_INVERTED);
	collectRightMotor->Set(collectPower * COLLECT_RIGHT_INVERTED);
}

void InternalCollect::PowerSolenoids()
{
	SmartDashboard::PutString(T_INTERNAL_ROLLER_COLLECT_STATE, rollerCollectState == ROLLER_COLLECT_OPEN ? S_OPEN : S_CLOSED);
	SmartDashboard::PutString(T_INTERNAL_TOTE_LOCK_STATE, toteLockState == TOTE_LOCK_OPEN ? S_OPEN: S_CLOSED);
	rollerCollectSolenoid->Set(rollerCollectState);
	toteLockSolenoid->Set(toteLockState);
}

void InternalCollect::SetRollerCollectSolenoid(bool state)
{
	rollerCollectState = state;
	PowerSolenoids();
}

void InternalCollect::SetToteLockSolenoid(bool state)
{
	toteLockState = state;
	PowerSolenoids();
}

void InternalCollect::SetCollectPower(float power)
{
	collectPower = power;
}

