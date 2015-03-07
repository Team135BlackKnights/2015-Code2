#include "AutoBinToteToAutoZone.h"
#include <Commands/ExternalSolenoidClaw.h>
#include <Commands/InternalSolenoidRoller.h>
#include "../Subsystems/ExternalCollect.h"
#include "../Subsystems/InternalCollect.h"

#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"
AutoBinToteToAutoZone::AutoBinToteToAutoZone()
{
	//AddParallel(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddParallel(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_ENGAGED));
	AddParallel(new AutoMoveRobot(0, 0, 2.0, AutoMoveRobot::TIME, false));
	//AddSequential(new ExternalMoveWinch(-.75, 1.5));
	//AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	AddSequential(new AutoMoveRobot(.4, 0, DISTANCE_BIN, AutoMoveRobot::DISTANCE, true));
	AddSequential(new ExternalMoveWinch(.75, 1.5));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(.67, 0, DISTANCE_RAMP, AutoMoveRobot::DISTANCE, true));
	AddSequential(new AutoMoveRobot(.9, 0, DISTANCE_END, AutoMoveRobot::DISTANCE, false));
	//AddSequential(new AutoMoveRobot(.85, 0, 0, 4, false));
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
