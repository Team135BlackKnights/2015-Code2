#include <Commands/DriveJ.h>
#include "RobotMap.h"

DriveJ::DriveJ()
{
	Requires(mecanumDrive);
	//SmartDashboard::PutString(T_DRIVE_J_RUNNING, S_CONSTRUCTED);
}

void DriveJ::Initialize()
{
	SmartDashboard::PutString(T_DRIVE_J_RUNNING, S_INITIALIZED);
}

void DriveJ::Execute()
{
	SmartDashboard::PutString(T_DRIVE_J_RUNNING, S_RUNNING);

	float x = 0, y = 0, rotation = 0;

	//FORWARDS: Right Y
	//SIDEWAYS: Left X
	//ROTATION: RIGHT Twist
	x = oi->GetStickX(oi->LEFT);
	y = oi->GetStickY(oi->RIGHT);
	rotation = oi->GetStickTwist(oi->RIGHT);

	//float angle = oi->GetFieldOriented() ? mecanumDrive->GetGyroAngle() : 0;
	mecanumDrive->Drive(x, y, rotation * ROTATION_MULTIPLICATION_CONSTANT); //Drives the Robot depending on x-y-z speed values
}

bool DriveJ::IsFinished() {return false;}

void DriveJ::End()
{
	SmartDashboard::PutString(T_DRIVE_J_RUNNING, S_ENDED);
}

void DriveJ::Interrupted()
{
	SmartDashboard::PutString(T_DRIVE_J_RUNNING, S_INTERRUPTED);
}
