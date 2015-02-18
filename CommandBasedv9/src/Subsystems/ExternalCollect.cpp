#include "ExternalCollect.h"
#include "../RobotMap.h"
#include "Commands/DriveExternalCollect.h"
#include "../CommandBase.h"

ExternalCollect::ExternalCollect() :
		Subsystem("ExternalCollect")
{
	claw = new Solenoid(SOLENOID_EXTERNAL_OPEN_CLOSE_CLAW);
	clawState = SmartDashboard::GetBoolean(T_CLAW_STATE_ENGAGED, CLAW_OPEN);

	winch = new Winch(MOTOR_EXTERNAL_WINCH, DIGITAL_EXTERNAL_LOWER, DIGITAL_EXTERNAL_UPPER, INVERTED_EXTERNAL_WINCH);
}

void ExternalCollect::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveExternalCollect());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ExternalCollect::SetClawState(bool states)
{
	clawState = states;
}

void ExternalCollect::PowerClaw()
{
	claw->Set(clawState);
}

void ExternalCollect::DriveWinch(float power)
{
	winch->DriveWinch(power);
}
