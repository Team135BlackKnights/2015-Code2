#include "AutoTwoBinRAMP.h"
#include "AutoThreeBin.h"
#include "InternalSolenoidRoller.h"
#include "AutoMoveRobot.h"
#include "ExternalSolenoidClaw.h"
#include "AutoRotateRobot.h"
#include "AutoMoveBinToAutoZone.h"
#include "InternalRollers.h"
#include "ExternalMoveWinch.h"
#include "InternalMoveWinch.h"
#include "CommandBase.h"
#include "InternalSolenoidToteLock.h"
#include "../Subsystems/MecanumDrive.h"

AutoTwoBinRAMP::AutoTwoBinRAMP()
{
	bool ramp = true;
	int dirMult = ramp ? -1 : 1;
	//Setup things
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_ENGAGED));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_OPEN));
	AddParallel(new InternalRollers(InternalCollect::COLLECT_IN_POWER, 15.0f));
	AddSequential(new AutoMoveRobot(0, 0, .25f, AutoMoveRobot::TIME, false));

	//Move to Bin 2
	AddParallel(new InternalRollers(InternalCollect::COLLECT_IN_POWER, 10.0f));
	AddSequential(new AutoMoveRobot(0, -.39, 1.2f, AutoMoveRobot::TIME, true));

	//Grab Bin 2
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, .25f, AutoMoveRobot::TIME, false));

	//Strafe with allllll the bins
	AddSequential(new AutoMoveRobot(-.8f * dirMult, -.05f, AutoThreeBin::DISTANCE_END, AutoMoveRobot::MODE::DISTANCE, true, 6.0f));
	//AddSequential(new AutoMoveRobot(0,  0, 2.0f, AutoMoveRobot::TIME, true));
}
