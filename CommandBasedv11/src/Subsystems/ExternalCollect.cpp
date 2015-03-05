#include "ExternalCollect.h"
#include "../RobotMap.h"
#include "Commands/DriveExternalCollect.h"
#include "../CommandBase.h"

ExternalCollect::ExternalCollect() :
		Subsystem("ExternalCollect")
{
	claw = new Solenoid(SOLENOID_EXTERNAL_OPEN_CLOSE_CLAW);
	SetClawState(CLAW_OPEN);

	winch = new Winch(MOTOR_EXTERNAL_WINCH,/* DIGITAL_EXTERNAL_LOWER, DIGITAL_EXTERNAL_UPPER, */INVERTED_EXTERNAL_WINCH);
}

void ExternalCollect::InitDefaultCommand()
{
	SetDefaultCommand(new DriveExternalCollect());
}

void ExternalCollect::SetClawState(bool state)
{
	clawState = state;
	PowerClaw();
}

void ExternalCollect::PowerClaw()
{
	SmartDashboard::PutString(T_EXTERNAL_CLAW_STATE, clawState == CLAW_OPEN ? S_OPEN : S_CLOSED);
	claw->Set(clawState);
}

void ExternalCollect::DriveWinch(float power)
{
	winch->DriveWinch(power);
}
