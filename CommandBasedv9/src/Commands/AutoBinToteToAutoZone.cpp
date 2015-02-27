#include "AutoBinToteToAutoZone.h"
#include <Commands/ExternalSolenoidClaw.h>

#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"
AutoBinToteToAutoZone::AutoBinToteToAutoZone()
{
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED)); //claw closes
		AddSequential(new AutoMoveRobot(0, 0, 0, 1));//wait
		AddSequential(new ExternalMoveWinch(-.75, .5));//winch up
		AddSequential(new AutoMoveRobot(.5, 0, 0, .8));//strafe right
		AddSequential(new AutoMoveRobot(0, 0, -.5, 1));//rotate left
		AddSequential(new AutoMoveRobot(.5, 0, 0, .7));//strafe right
		AddSequential(new ExternalMoveWinch(.5, .75));//winch down
		AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));//claw open
		AddSequential(new AutoMoveRobot(0, 0, 0, 7));//wait
		AddSequential(new AutoMoveRobot(0, 0.25, 0, 1));//drive forward
		AddSequential(new AutoMoveRobot(0, 0, 0, 1));//wait
		//AddSequential(new ExternalMoveWinch(.5, .25));//winch all down
		AddSequential(new AutoMoveRobot(0, -0.3, 0, 1));//backwards
		//AddSequential(new ExternalMoveWinch(.5, .25));//
		//AddSequential(new ExternalOpenCloseClaw(false));
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
