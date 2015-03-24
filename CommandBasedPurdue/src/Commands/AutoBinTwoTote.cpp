#include "AutoBinTwoTote.h"
#include "InternalSolenoidRoller.h"
#include "AutoMoveRobot.h"
#include "ExternalSolenoidClaw.h"
#include "AutoRotateRobot.h"
#include "AutoMoveBinToAutoZone.h"
#include "InternalRollers.h"
#include "ExternalMoveWinch.h"

AutoBinTwoTote::AutoBinTwoTote()
{
	//Setup
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_ENGAGED));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	AddParallel(new InternalRollers(InternalCollect::COLLECT_IN_POWER, 15.0f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Move and grab first tote
	AddSequential(new AutoMoveRobot(0, -.30, .5f, AutoMoveRobot::TIME, true));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Turn around
	AddSequential(new AutoRotateRobot(180, .35f, 6.0f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Lift up winch
	AddSequential(new ExternalMoveWinch(-.4, 1.0f));

	//Move over other tote
	AddSequential(new AutoMoveRobot(0, -.45, .75f, AutoMoveRobot::TIME, true, .6f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Put down Winch and grab tote 2
	AddSequential(new ExternalMoveWinch(.4, .5f));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	AddSequential(new ExternalMoveWinch(.4, .5f));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));

	//Back up and turn
	AddSequential(new AutoMoveRobot(0, -.45, .75f, AutoMoveRobot::TIME, true, .6f));
	AddSequential(new AutoRotateRobot(-90, .35f, 4.0f));

	//Move into zone
	AddSequential(new AutoMoveRobot(0, .45, 3.28f, AutoMoveRobot::TIME, true));
}
