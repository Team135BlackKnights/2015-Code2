#include <Commands/DriveInternalCollect.h>
#include "RobotMap.h"

DriveInternalCollect::DriveInternalCollect()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(internalCollect);
}

// Called just before this Command runs the first time
void DriveInternalCollect::Initialize()
{
	SmartDashboard::PutString(T_DRIVE_INTERNAL_RUNNING, "Initialized");
}

// Called repeatedly when this Command is scheduled to run
void DriveInternalCollect::Execute()
{
	SmartDashboard::PutString(T_DRIVE_INTERNAL_RUNNING, "Running");
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
			internalCollect->SetRollerCollectSolenoid(InternalCollect::ROLLER_COLLECT_ENGAGED);
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_ROLLER_SOLENOID_DISENGAGED))
			internalCollect->SetRollerCollectSolenoid(InternalCollect::ROLLER_COLLECT_DISENGAGED);

		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_UPPER_STACK_SOLENOID_ENGAGED))
			internalCollect->SetToteLockSolenoid(InternalCollect::TOTE_LOCK_ENGAGED);
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_UPPER_STACK_SOLENOID_DISENGAGED))
			internalCollect->SetToteLockSolenoid(InternalCollect::TOTE_LOCK_DISENGAGED);

	//	if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_WINCH_UP))
		//	value = .5;
		//else if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_WINCH_UP))
		//	value = -.5;
	}

	internalCollect->DriveLift(value); //THIS NEEDS TO BE CHANGED
	internalCollect->DriveCollect();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveInternalCollect::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DriveInternalCollect::End()
{
	SmartDashboard::PutBoolean(T_DRIVE_INTERNAL_RUNNING, false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveInternalCollect::Interrupted()
{
	SmartDashboard::PutString(T_DRIVE_INTERNAL_RUNNING, "Interrupted");
}
