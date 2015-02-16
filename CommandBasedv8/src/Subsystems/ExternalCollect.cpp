#include "ExternalCollect.h"
#include "../RobotMap.h"
#include "Commands/DriveExternalCollect.h"
#include "Commands/ExternalHingeClaw.h"
#include "../CommandBase.h"

ExternalCollect::ExternalCollect() :
		Subsystem("ExternalCollect")
{
	openCloseClaw = new Solenoid(SOLENOID_EXTERNAL_OPEN_CLOSE_CLAW);
	//hingeClaw = new Solenoid(SOLENOID_EXTERNAL_HINGE_CLAW);
	winch = new VictorSP(MOTOR_EXTERNAL_WINCH);//MOTOR_EXTERNAL_WINCH);
	openCloseClawState = CLAW_OPEN;//CommandBase::oi->GetClawButtonValue();
	//hingeClawState = CLAW_UP;

	switches[0] = new DigitalInput(0);
}

void ExternalCollect::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveExternalCollect());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ExternalCollect::SetOpenCloseClawState(bool states)
{
	openCloseClawState = states;
}

void ExternalCollect::PowerClaw()
{
	openCloseClaw->Set(openCloseClawState);
	//hingeClaw->Set(hingeClawState);
}

void ExternalCollect::SetHingeClawState(bool state)
{
	//hingeClawState = state;
}

void ExternalCollect::DriveWinch(float power)
{
	winch->Set(power);
}

bool ExternalCollect::GetLimitSwitchValue(int port)
{
	return switches[port]->Get();
}
