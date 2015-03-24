#include "AutoTwoBin.h"
#include "InternalSolenoidRoller.h"
#include "AutoMoveRobot.h"
#include "ExternalSolenoidClaw.h"
#include "AutoRotateRobot.h"
#include "AutoMoveBinToAutoZone.h"
#include "InternalRollers.h"

AutoTwoBin::AutoTwoBin()
{
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_ENGAGED));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	AddParallel(new InternalRollers(InternalCollect::COLLECT_IN_POWER, 13.0f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));
	AddSequential(new AutoMoveRobot(0, -.30, 1.5f, AutoMoveRobot::TIME, true));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//STRAFE METHOD
	//AddSequential(new AutoMoveRobot(.45, 0, 5.5f, AutoMoveRobot::TIME, true));

	//OLD ROTATIION METHOD
	AddSequential(new AutoRotateRobot(90, .35f, 5.23461632f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));
	AddSequential(new AutoMoveRobot(0, .45, 3.4f, AutoMoveRobot::TIME, true, .6f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));
	AddSequential(new AutoRotateRobot(90, .45f, 6.0f));

	AddSequential(new AutoMoveRobot(0, .3f, 2.0f, AutoMoveRobot::TIME, true, .6f));
	//AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	//AddSequential(new AutoMoveBinToAutoZone());
}
