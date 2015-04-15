#include "AutoMoveRobot.h"
#include <algorithm>
#include <cmath>
#include "../RobotMap.h"


AutoMoveRobot::AutoMoveRobot(float x, float y, double target, MODE mode, bool gyroCompensation, float maxRotation)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumDrive);
	this->x = x;
	this->y = y;
	this->targetAngle = 0;

	this->mode = mode;
	if (mode == MODE::TIME)
	{
		this->targetTime = target;
		this->targetDistance = 0;
		this->startingDistance = 0;
		this->lastDistance = 0;
	} else
	{
		this->targetTime = 0;
		this->targetDistance = target;
		this->startingDistance = 0;
		this->lastDistance = 0;
	}
	this-> gyroCompensation = gyroCompensation;
	this->maxRotation = maxRotation;
	timer = new Timer();
	this->limitSwitch = NULL;
	this->targetState = NULL;
}

AutoMoveRobot::AutoMoveRobot(float x, float y, BUMP_LIST limitSwitch, bool targetState, bool gyroCompensation, float maxRotation)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumDrive);
	this->x = x;
	this->y = y;
	this->targetAngle = 0;

	this->mode = BUMP;
	this->targetTime = 0;
	this->targetDistance = 0;
	this->startingDistance = 0;
	this->lastDistance = 0;

	this-> gyroCompensation = gyroCompensation;
	this->maxRotation = maxRotation;
	timer = new Timer();
	switch(limitSwitch)
	{
	case BUMP_LIST::MECANUM_RIGHT:
	default:
		this->limitSwitch = new DigitalInput(DIGITAL_RIGHT_BUMP);
		break;
	}
	this->targetState = targetState;
}

// Called just before this Command runs the first time
void AutoMoveRobot::Initialize()
{
	//mecanumDrive->GetDefaultCommand()->Cancel();
	this->targetAngle = mecanumDrive->GetGyroAngle();
	this->startingDistance = mecanumDrive->GetLidarValue();
	this->lastDistance = this->startingDistance;
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoMoveRobot::Execute()
{
	float newRotate = 0;
	if (gyroCompensation)
	{
		float angle = mecanumDrive->GetGyroAngle();
		//float offset = angle - targetAngle;
		newRotate = -fmax(-MAX_ROTATION_POWER, fmin(MAX_ROTATION_POWER, MAX_ROTATION_POWER * (targetAngle - angle) / 90));
		SmartDashboard::PutNumber("Rotation fix thing", newRotate);
	}
	mecanumDrive->Drive(x, y, newRotate);
	if (this->mode == MODE::BUMP)
		SmartDashboard::PutBoolean("Bump Switch Value", this->limitSwitch->Get());
}

// Make this return true when this Command no longer needs to run execute()
bool AutoMoveRobot::IsFinished()
{
	this->lastDistance = mecanumDrive->GetLidarValue();
	if (this->mode == MODE::TIME)
		return timer->HasPeriodPassed(targetTime);
	else if (this->mode == MODE::DISTANCE)
		return this->targetDistance - this->startingDistance < 0 ? lastDistance <= targetDistance : lastDistance > targetDistance;
	else
		return (this->targetState == this->limitSwitch->Get());
}

// Called once after isFinished returns true
void AutoMoveRobot::End()
{
	mecanumDrive->Drive(0, 0, 0, 0);
	delete this->limitSwitch;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMoveRobot::Interrupted()
{
}
