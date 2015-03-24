#include "AutoTwoBin.h"
#include "InternalSolenoidRoller.h"
#include "AutoMoveRobot.h"
#include "ExternalSolenoidClaw.h"
#include "AutoRotateRobot.h"
#include "AutoMoveBinToAutoZone.h"
#include "InternalRollers.h"
/*
AutoTwoBinV2::AutoTwoBinV2()
{
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_DISENGAGED));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	//AddParallel(new InternalRollers(InternalCollect::COLLECT_IN_POWER, 13.0f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));
	AddSequential(new AutoMoveRobot(0, .35, 1.35f, AutoMoveRobot::TIME, true));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, 1.0f, AutoMoveRobot::TIME, false));

	//OLD ROTATIION METHOD
	AddSequential(new AutoRotateRobot(-90, .35f, 5.0f));
	AddSequential(new AutoMoveRobot(0, 0, 1.0f, AutoMoveRobot::TIME, false));
	AddSequential(new AutoMoveRobot(0, -.45, 2.8f, AutoMoveRobot::TIME, true));
	AddSequential(new AutoMoveRobot(0, 0, 1.35f, AutoMoveRobot::TIME, false));
	AddSequential(new AutoRotateRobot(90, .4f, 3.0f));
	//AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	//AddSequential(new AutoMoveBinToAutoZone());
}
*/
