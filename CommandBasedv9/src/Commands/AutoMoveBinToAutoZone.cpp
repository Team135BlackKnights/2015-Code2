#include "AutoMoveBinToAutoZone.h"
#include "ExternalOpenCloseClaw.h"
#include "AutoMoveRobot.h"
#include "ExternalMoveWinch.h"
//#include "DriveJ.h"
//#include "SetSafetyEnabled.h";
//#include "../CommandBase.h"

AutoMoveBinToAutoZone::AutoMoveBinToAutoZone()
{
	//AddSequential(new SetSafetyEnabled(false));
	//AddSequential( new DriveJ());
	//SmartDashboard::PutString("Auto Step", "1");
	AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_CLOSED));
	//SmartDashboard::PutString("Auto Step", "2");
	AddSequential(new AutoMoveRobot(0, 0, 0, 1));
	AddSequential(new ExternalMoveWinch(-.5, 1));
	AddSequential(new AutoMoveRobot(0, -.5, 0, 1.65));
	AddSequential(new AutoMoveRobot(0, 0, .5, .6));
	//SmartDashboard::PutString("Auto Step", "3");
	AddSequential(new ExternalOpenCloseClaw(ExternalCollect::CLAW_OPEN));
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
