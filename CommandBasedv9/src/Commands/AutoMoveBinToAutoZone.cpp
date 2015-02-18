#include <Commands/ExternalSolenoidClaw.h>
#include "AutoMoveBinToAutoZone.h"
#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"

AutoMoveBinToAutoZone::AutoMoveBinToAutoZone()
{

/* This is side with no ramp
	AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, 0, 1));
	AddSequential(new ExternalMoveWinch(-.5, 1));
	AddSequential(new AutoMoveRobot(0, -.5, 0, 1.65));
	AddSequential(new AutoMoveRobot(0, 0, .5, .6));
	AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
	AddSequential(new AutoMoveRobot(0, 0, 0, 0));
*/
/*This si for the two sides that have ramps both work
	AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
		AddSequential(new AutoMoveRobot(0, 0, 0, 1));
		AddSequential(new ExternalMoveWinch(-.5, 1));
		AddSequential(new AutoMoveRobot(0, -.5, 0, 2.35));
		AddSequential(new AutoMoveRobot(0, 0, .75, .6));
		AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
		AddSequential(new AutoMoveRobot(0, 0, 0, 0));
*/
/* BADBADBABD AD A DA A D aD   AABDABDBBADB
	AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, 0, 1));
	AddSequential(new ExternalMoveWinch(-.75, 1));
	AddSequential(new AutoMoveRobot(-.5, 0, 0, 1.85));
	AddSequential(new ExternalMoveWinch(.6, 1));
	AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, 0, 3));
	AddSequential(new AutoMoveRobot(.5, 0, 0, 1.85));
	//AddSequential(new AutoMoveRobot(.5, 0, .2, 1.85));
		AddSequential(new AutoMoveRobot(0, 0, 0, 0));
*/

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

/*
		AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
		AddSequential(new AutoMoveRobot(0, 0, 0, 1));
		AddSequential(new ExternalMoveWinch(-.5, .5));
		AddParallel(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));

		AddSequential(new AutoMoveRobot(0, .4, 0, .8));
		AddSequential(new AutoMoveRobot(0, 0, 0, 1));
		AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
		AddSequential(new AutoMoveRobot(0, 0, 0, 1));
		AddSequential(new AutoMoveRobot(0, -.5, 0, .7));
		AddSequential(new ExternalMoveWinch(1, .7));
		AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
		AddSequential(new AutoMoveRobot(0, 0, 0, 0));

*/


	//SmartDashboard::PutString("Auto Step", "4");
	//AddSequential(new AutoMoveRobot(-.75, 1000));
	//SmartDashboard::PutString("Auto Step", "Done");
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
