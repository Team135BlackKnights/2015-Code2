#include "AutoAlignToDriverWall.h"
#include <Commands/ExternalSolenoidClaw.h>
#include "AutoMoveBinToAutoZone.h"
#include "AutoMoveRobot.h"
#include "../InternalSolenoidRoller.h"
#include "../InternalSolenoidToteLock.h"

AutoAlignToDriverWall::AutoAlignToDriverWall()
{
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED)); //claw closes
	AddSequential( new InternalSolenoidRoller(true));
	AddParallel (new InternalSolenoidToteLock(InternalCollect::TOTE_LOCK_OPEN));
	AddSequential(new AutoMoveRobot(0, 0, 0, 1));//wait
	AddSequential(new AutoMoveRobot(0, -.5,0,.16));
	AddSequential(new AutoMoveRobot(0, 0,-.5,1.5));
	AddSequential(new AutoMoveRobot(0, .5,0,.35));
	AddSequential(new AutoMoveRobot(.5,0,0,1.3));




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
