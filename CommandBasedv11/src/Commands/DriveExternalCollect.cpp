#include "DriveExternalCollect.h"
#include "RobotMap.h"

DriveExternalCollect::DriveExternalCollect()
{
	Requires(externalCollect);
	//SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, S_CONSTRUCTED);
}

void DriveExternalCollect::Initialize()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, S_INITIALIZED);
}

void DriveExternalCollect::Execute()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, S_RUNNING);
	float value = oi->GetManipulatorControlMode() == OI::EXTERNAL ? oi->GetStickY(oi->MANIPULATOR_CONTROL) : 0;

	if (oi->GetManipulatorControlMode() == oi->EXTERNAL)
	{
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_CLAW_OPEN))
			externalCollect->SetClawState(externalCollect->CLAW_OPEN);
		else if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_CLAW_CLOSED))
			externalCollect->SetClawState(externalCollect->CLAW_CLOSED);
	}
	externalCollect->DriveWinch(value);
}

bool DriveExternalCollect::IsFinished() {return false;}

void DriveExternalCollect::End()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, S_ENDED);
}

void DriveExternalCollect::Interrupted()
{
	SmartDashboard::PutString(T_DRIVE_EXTERNAL_RUNNING, S_INTERRUPTED);
}
