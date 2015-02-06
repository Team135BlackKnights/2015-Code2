/*
 * Pneumatics.cpp
 *
 *  Created on: Feb 1, 2015
 *      Author: robotics
 */


#include <Commands/Pneumatics.h>
#include "RobotMap.h"
//#include "../Subsystems/MecanumDrive.h"

Pneumatics::Pneumatics()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(airCompressor);
	//Requires(internalCollect);
}

// Called just before this Command runs the first time
void Pneumatics::Initialize()
{
	//SmartDashboard::PutString(PNEUMATICAIR_COMPRESSOR_RUNNING, "Initialized");
}

// Called repeatedly when this Command is scheduled to run
void Pneumatics::Execute()
{
	//SmartDashboard::PutString(DRIVE_J_RUNNING, "Running");



/*
	if (oi->sticks[oi->LEFT]->GetRawButton(9))
			internalCollect->SetLiftSolenoid(true);
		if (oi->sticks[oi->LEFT]->GetRawButton(10))
			internalCollect->SetLiftSolenoid(false);

		if (oi->sticks[oi->LEFT]->GetRawButton(11) == 1)
			internalCollect->SetControlSolenoid(true);
			SmartDashboard::PutString(PNEUMATICS_LIFTSOLENOID_RUNNING, "InternalSolenoid Engaged");
		if (oi->sticks[oi->LEFT]->GetRawButton(12) == 1)
			internalCollect->SetControlSolenoid(false);
			SmartDashboard::PutString(PNEUMATICS_LIFTSOLENOID_RUNNING, "InternalSolenoid Disengaged");
*/



}

// Make this return true when this Command no longer needs to run execute()
bool Pneumatics::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Pneumatics::End()
{
	//SmartDashboard::PutString(DRIVE_J_RUNNING, "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Pneumatics::Interrupted()
{

}






