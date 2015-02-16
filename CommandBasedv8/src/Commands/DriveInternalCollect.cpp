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
	float value = oi->MANIPULATOR_CONTROL_MODE == OI::INTERNAL ? oi->GetStickY(oi->MANIPULATOR_CONTROL) : 0;

//	if (oi->MANIPULATOR_CONTROL_MODE == OI::INTERNAL)
	//{
		/*
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, OI::INTERNAL_ROLLER_IN))
			internalCollect->SetCollectPower(InternalCollect::COLLECT_IN_POWER);
		else if (oi->GetButton(oi->MANIPULATOR_CONTROL, OI::INTERNAL_ROLLER_OUT))
			internalCollect->SetCollectPower(InternalCollect::COLLECT_OUT_POWER);
		else
			internalCollect->SetCollectPower(0);

		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_SOLENOID_ENGAGED))
			internalCollect->SetCollectSolenoid(InternalCollect::COLLECT_ENGAGED);
		if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->INTERNAL_SOLENOID_DISENGAGED))
			internalCollect->SetCollectSolenoid(InternalCollect::COLLECT_DISENGAGED);
		*/
	//	if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_WINCH_UP))
		//	value = .5;
		//else if (oi->GetButton(oi->MANIPULATOR_CONTROL, oi->EXTERNAL_WINCH_UP))
		//	value = -.5;
//	}

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
