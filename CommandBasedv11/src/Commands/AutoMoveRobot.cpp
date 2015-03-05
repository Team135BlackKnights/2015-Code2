#include "AutoMoveRobot.h"

AutoMoveRobot::AutoMoveRobot(float x, float y, float rotate, double timePassed)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumDrive);
	this->x = x;
	this->y = y;
	this->rotate = rotate;
	this->timePassed = timePassed;
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutoMoveRobot::Initialize()
{
	//mecanumDrive->GetDefaultCommand()->Cancel();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoMoveRobot::Execute()
{
	mecanumDrive->Drive(x, y, rotate);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoMoveRobot::IsFinished()
{
	return timer->HasPeriodPassed(timePassed);
}

// Called once after isFinished returns true
void AutoMoveRobot::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMoveRobot::Interrupted()
{
}
