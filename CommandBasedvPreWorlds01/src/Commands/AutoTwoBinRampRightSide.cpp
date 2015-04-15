#include "AutoTwoBinRampRightSide.h"
#include "InternalSolenoidRoller.h"
#include "AutoMoveRobot.h"
#include "ExternalSolenoidClaw.h"
#include "AutoRotateRobot.h"
#include "AutoMoveBinToAutoZone.h"
#include "InternalRollers.h"

AutoTwoBinRampRightSide::AutoTwoBinRampRightSide()
{



	//Setup things
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_DISENGAGED));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Move to Bin
	AddSequential(new AutoMoveRobot(0, .39, 1.35f, AutoMoveRobot::TIME, true));

	//Grab Bin
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_ENGAGED));
	AddParallel(new InternalRollers(InternalCollect::COLLECT_IN_POWER, 13.0f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//ROTATE perpendicular to driver station
	AddSequential(new AutoRotateRobot(-90, .4f, 6.0f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Move to Zone
	AddSequential(new AutoMoveRobot(0, .45, 3.25f, AutoMoveRobot::TIME, true));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Rotate parallel to driver wall
	AddSequential(new AutoRotateRobot(-90, .4f, 7.0f));

	//Back up a bit
	AddSequential(new AutoMoveRobot(0, .35, 1.35f, AutoMoveRobot::TIME, true));

	//AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	//AddSequential(new AutoMoveBinToAutoZone());
}

