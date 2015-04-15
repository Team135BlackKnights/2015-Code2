#include "AutoThreeTote.h"
#include "ExternalSolenoidClaw.h"
#include "AutoMoveRobot.h"
#include "AutoRotateRobot.h"

AutoThreeTote::AutoThreeTote()
{
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	AddSequential(new AutoMoveRobot(0, -.1, .5f, AutoMoveRobot::TIME, true));
	AddSequential(new AutoRotateRobot(-30.0f, .2f, 3.0f));
	AddSequential(new AutoMoveRobot(0, -.1, .5f, AutoMoveRobot::TIME, true));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
}
