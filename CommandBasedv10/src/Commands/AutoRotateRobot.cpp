#include "AutoRotateRobot.h"
#include <algorithm>
#include <cmath>


AutoRotateRobot::AutoRotateRobot(float targetAngle)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumDrive);
	this->targetAngle = targetAngle;
	this->startingAngle = 0;
	this->currentAngle = 0;
}

// Called just before this Command runs the first time
void AutoRotateRobot::Initialize()
{
	SmartDashboard::PutString(T_AUTO_ROTATE_ROBOT, S_INITIALIZED);
	mecanumDrive->GetDefaultCommand()->Cancel();
	this->startingAngle = mecanumDrive->GetGyroAngle();
	this->targetAngle += this->startingAngle;
}

// Called repeatedly when this Command is scheduled to run
void AutoRotateRobot::Execute()
{
	SmartDashboard::PutString(T_AUTO_ROTATE_ROBOT, S_RUNNING);
	float newRotate = 0;
	currentAngle = mecanumDrive->GetGyroAngle();
	//float offset = angle - targetAngle;
	newRotate = fmax(-MAX_ROTATION_POWER, fmin(MAX_ROTATION_POWER, (targetAngle - currentAngle) / 90));
	newRotate = fmax(-MIN_ROTATION_POWER, fmin(MIN_ROTATION_POWER, newRotate));
	SmartDashboard::PutNumber("Rotation fix thing", newRotate);
	mecanumDrive->Drive(0, 0, newRotate);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoRotateRobot::IsFinished()
{
	if (targetAngle - startingAngle <= 0)
		return currentAngle <= targetAngle;
	else
		return currentAngle >= targetAngle;
	//return abs(currentAngle) >= abs(targetAngle);
}

// Called once after isFinished returns true
void AutoRotateRobot::End()
{
	SmartDashboard::PutString(T_AUTO_ROTATE_ROBOT, S_ENDED);
	mecanumDrive->Drive(0, 0, 0, 0);
	//mecanumDrive->GetDefaultCommand()->Start();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoRotateRobot::Interrupted()
{
	SmartDashboard::PutString(T_AUTO_ROTATE_ROBOT, S_INTERRUPTED);
}
