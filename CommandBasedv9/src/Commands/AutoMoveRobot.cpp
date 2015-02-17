#include "AutoMoveRobot.h"

AutoMoveRobot::AutoMoveRobot(float power, double timePassed)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumDrive);
	this->power = power;
	this->timePassed = timePassed;
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutoMoveRobot::Initialize()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, S_INITIALIZED);
	mecanumDrive->GetDefaultCommand()->Cancel();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoMoveRobot::Execute()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, S_RUNNING);
	mecanumDrive->Drive(0, power, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoMoveRobot::IsFinished()
{
	return timer->HasPeriodPassed(timePassed);
}

// Called once after isFinished returns true
void AutoMoveRobot::End()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, S_ENDED);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoMoveRobot::Interrupted()
{
	SmartDashboard::PutString(T_BACK_UP_RUNNING, S_INTERRUPTED);
}
