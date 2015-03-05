#include "AutoMoveBinToAutoZoneRamp.h"
#include <Commands/ExternalSolenoidClaw.h>
#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"
AutoMoveBinToAutoZoneRamp::AutoMoveBinToAutoZoneRamp()
{

	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
			AddSequential(new AutoMoveRobot(0, 0, 0, 1));
			AddSequential(new ExternalMoveWinch(-.5, 1));
			AddSequential(new AutoMoveRobot(0, .5, 0, 2.35));
			AddSequential(new AutoMoveRobot(0, 0, .75, .6));
			AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
			AddSequential(new AutoMoveRobot(0, 0, 0, 0));
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
