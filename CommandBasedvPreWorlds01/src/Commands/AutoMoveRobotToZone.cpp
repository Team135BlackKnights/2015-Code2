#include "AutoMoveRobotToZone.h"
#include "AutoMoveRobot.h"
#include "AutoRotateRobot.h"

AutoMoveRobotToZone::AutoMoveRobotToZone()
{

	//Move to Zone
	AddSequential(new AutoMoveRobot(0, .45, 3.0f, AutoMoveRobot::TIME, true));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Rotate parallel to driver wall
	AddSequential(new AutoRotateRobot(90, .4f, 7.0f));

	//Back up a bit
	AddSequential(new AutoMoveRobot(0, .35, 1.35f, AutoMoveRobot::TIME, true));
}
