#include <Commands/ExternalSolenoidClaw.h>
#include "AutoMoveBinToAutoZone.h"
#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"

AutoMoveBinToAutoZone::AutoMoveBinToAutoZone()
{
// This is side with no ramp
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, 0, 2));
	AddSequential(new ExternalMoveWinch(-.75, 2.1));
	AddSequential(new AutoMoveRobot(0, -.5, 0, 1.7));
	AddSequential(new AutoMoveRobot(0, 0, -.5, .9));
	AddSequential(new AutoMoveRobot(0, 0, 0, 1));
	//AddSequential(new AutoMoveRobot(0, 0, 0, 2));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	//AddSequential(new ExternalMoveWinch(-.5, 3));
	//AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	//AddSequential(new AutoMoveRobot(0, 0, 0, 4));
	//AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));

}
