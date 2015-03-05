#include <Commands/DriveInternalCollect.h>
#include "RobotMap.h"

DriveInternalCollect::DriveInternalCollect() {Requires(internalCollect);}

void DriveInternalCollect::Initialize()
{
	SmartDashboard::PutString(T_DRIVE_INTERNAL_RUNNING, S_INITIALIZED);
}

void DriveInternalCollect::Execute()
{
	SmartDashboard::PutString(T_DRIVE_INTERNAL_RUNNING, S_RUNNING);
	float value = oi->GetManipulatorControlMode() == OI::INTERNAL ? oi->GetStickY(oi->MANIPULATOR_CONTROL) : 0;

	if (oi->GetManipulatorControlMode() == OI::INTERNAL)
	{
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, OI::INTERNAL_ROLLER_IN))
			internalCollect->SetCollectPower(oi->GetStickSlider(oi->MANIPULATOR_CONTROL));//InternalCollect::COLLECT_IN_POWER);
		else if (oi->GetButton(oi->MANIPULATOR_CONTROL, OI::INTERNAL_ROLLER_OUT))
			internalCollect->SetCollectPower(-oi->GetStickSlider(oi->MANIPULATOR_CONTROL));//InternalCollect::COLLECT_OUT_POWER);
		else
			internalCollect->SetCollectPower(0);

		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_ROLLER_SOLENOID_ENGAGED))
			internalCollect->SetRollerCollectSolenoid(InternalCollect::ROLLER_COLLECT_CLOSED);
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_ROLLER_SOLENOID_DISENGAGED))
			internalCollect->SetRollerCollectSolenoid(InternalCollect::ROLLER_COLLECT_OPEN);

		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_UPPER_STACK_SOLENOID_ENGAGED))
			internalCollect->SetToteLockSolenoid(InternalCollect::TOTE_LOCK_CLOSED);
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_UPPER_STACK_SOLENOID_DISENGAGED))
			internalCollect->SetToteLockSolenoid(InternalCollect::TOTE_LOCK_OPEN);
	}

	internalCollect->DriveLift(value);
	internalCollect->DriveCollect();
}

bool DriveInternalCollect::IsFinished() {return false;}

void DriveInternalCollect::End()
{
	SmartDashboard::PutString(T_DRIVE_INTERNAL_RUNNING, S_ENDED);
}

void DriveInternalCollect::Interrupted()
{
	SmartDashboard::PutString(T_DRIVE_INTERNAL_RUNNING, S_INTERRUPTED);
}
