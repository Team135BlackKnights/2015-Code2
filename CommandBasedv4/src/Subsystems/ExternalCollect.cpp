#include "ExternalCollect.h"
#include "../RobotMap.h"

ExternalCollect::ExternalCollect() :
		Subsystem("ExternalCollect")
{
	clawOpenClose = new Solenoid(SOLENOID_EXTERNAL_OPEN_CLOSE_CLAW);
	winch = new VictorSP(MOTOR_EXTERNAL_WINCH);
	clawState = CLAW_CLOSED;
}

void ExternalCollect::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveExternalCollect());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ExternalCollect::SetOpenCloseClawState(bool state)
{
	clawState = state;
}

void ExternalCollect::PowerOpenCloseClaw()
{
	clawOpenClose->Set(clawState);
}

void ExternalCollect::DriveWinch(float power)
{
	winch->Set(power);
}
