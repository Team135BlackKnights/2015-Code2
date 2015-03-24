#include "AutoMoveBinToAutoZoneRamp.h"
#include <Commands/ExternalSolenoidClaw.h>
#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"

#include "AutoRotateRobot.h"

AutoMoveBinToAutoZoneRamp::AutoMoveBinToAutoZoneRamp()
{
	//CLAW
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, 1.5f, AutoMoveRobot::TIME, false));
	AddSequential(new ExternalMoveWinch(-.6, 2.0f));
	AddParallel(new ExternalMoveWinch(-.1, 3));

	//TIME BASED
		AddSequential(new AutoMoveRobot(0, .65, 1.35f + .13f, AutoMoveRobot::TIME, true));
	//ANALOG DISTANCE LIDAR BASED
		//AddSequential(new AutoMoveRobot(0, .65, DISTANCE_ANALOG_LIDAR, AutoMoveRobot::DISTANCE, true));
	//I2C DISTANCE LIDAR BASED
		//AddSequential(new AutoMoveRobot(0, .65, DISTANCE_END, AutoMoveRobot::DISTANCE, true));

	//ENDING
	AddSequential(new AutoRotateRobot(90, .4f, 5.0f));
	AddSequential(new AutoMoveRobot(0, 0, 0.0f, AutoMoveRobot::TIME, false));
}
