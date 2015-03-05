#include "AutoMoveRobot.h"

AutoMoveRobot::AutoMoveRobot(float x, float y, float rotate, double timePassed)
{
	Requires(mecanumDrive);
	this->x = x;
	this->y = y;
	this->rotate = rotate;
	this->timePassed = timePassed;
	timer = new Timer();
}

void AutoMoveRobot::Initialize() {timer->Start();}

void AutoMoveRobot::Execute() {mecanumDrive->Drive(x, y, rotate);}

bool AutoMoveRobot::IsFinished() {return timer->HasPeriodPassed(timePassed);}

void AutoMoveRobot::End() {}

void AutoMoveRobot::Interrupted() {}
