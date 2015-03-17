#include "AUTOMATT.h"
#include <Commands/ExternalSolenoidClaw.h>
#include <Commands/InternalSolenoidRoller.h>
#include "AutoMoveRobot.h"
#include "../Subsystems/ExternalCollect.h"
#include "../Subsystems/InternalCollect.h"

#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"
AUTOMATT::AUTOMATT()
{
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	//AddParallel(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_DISENGAGED));
	AddSequential(new AutoMoveRobot(0, -.5, .75f, AutoMoveRobot::TIME, true));
	//AddParallel(new AutoMoveRobot(0, 0, 2.0, AutoMoveRobot::TIME, false));

	//AddSequential (new AutoMoveRobot(.6,.1, DISTANCE_END, 5, true));
	//AddSequential(new ExternalMoveWinch(.75, 1.5));
	//AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	//AddSequential(new AutoMoveRobot(.67, 0, DISTANCE_RAMP, AutoMoveRobot::DISTANCE, true));
	//AddSequential(new AutoMoveRobot(.9, 0, DISTANCE_END, AutoMoveRobot::DISTANCE, false));

}
