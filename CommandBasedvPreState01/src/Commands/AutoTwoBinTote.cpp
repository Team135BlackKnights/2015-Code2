#include "AutoTwoBinTote.h"
#include "ExternalSolenoidClaw.h"
#include "../Subsystems/ExternalCollect.h"
#include "AutoMoveRobot.h"
#include "AutoRotateRobot.h"
#include "../Subsystems/InternalCollect.h"
#include "InternalSolenoidRoller.h"
#include "ExternalMoveWinch.h"

AutoTwoBinTote::AutoTwoBinTote()
{
	AddParallel(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddParallel(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_DISENGAGED));
	AddSequential(new AutoMoveRobot(0, 0, 1.0f, false));
	AddSequential(new ExternalMoveWinch(-.75, .8));
	AddSequential(new AutoMoveRobot(0, 0, 1.0f, false));
	//AddSequential(new AutoMoveRobot(0, .4, .75, false));
	AddSequential(new AutoRotateRobot(-180));
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
