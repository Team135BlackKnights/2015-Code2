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

AutoThreeBin::AutoThreeBin(bool ramp)
{
	int dirMult = ramp ? -1 : 1;
	//Setup things
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_DISENGAGED));
	AddSequential(new ExternalSolenoidClaw(ExternalCollect::CLAW_CLOSED));
	AddSequential(new AutoMoveRobot(0, 0, .25f, AutoMoveRobot::TIME, false));

	//Lift Up Bin 1
	AddSequential(new ExternalMoveWinch(-.6, 0.5f));
	AddParallel(new ExternalMoveWinch(-.2, 15.0f));

	//Move to Bin 2
	AddParallel(new InternalRollers(InternalCollect::COLLECT_IN_POWER, 15.0f));
	AddSequential(new AutoMoveRobot(0, .39, 1.2f, AutoMoveRobot::TIME, true));

	//Grab Bin 2
	AddSequential(new InternalSolenoidRoller(InternalCollect::ROLLER_COLLECT_ENGAGED));
	//AddSequential(new AutoMoveRobot(0, 0, .25f, AutoMoveRobot::TIME, false));

	//Lift up Bin 2
	AddSequential(new InternalMoveWinch(-.45f, .6f));
	AddParallel(new InternalMoveWinch(-.2, 15.0f));

	//Open Tote locks
	//AddSequential(new InternalSolenoidToteLock(InternalCollect::TOTE_LOCK_DISENGAGED));

	//Line up with Bin 3
	//OLD
	//AddSequential(new AutoMoveRobot(.6f * dirMult, 0, DISTANCE_CLOSE_TO_WALL, AutoMoveRobot::DISTANCE, true, 1.0f));
	//AddSequential(new AutoMoveRobot(.6f * dirMult, AutoMoveRobot::MECANUM_RIGHT, true, AutoMoveRobot::BUMP, true, 1.0f));
	//AddSequential(new AutoMoveRobot(0, .45f, 1.65f, AutoMoveRobot::TIME, true, 0.8f));
	//NEW TEST
	AddSequential(new AutoMoveRobot(0, 0, .1f, AutoMoveRobot::TIME, false));
	AddSequential(new AutoMoveRobot(.8f * dirMult, 0, DISTANCE_CLOSE_TO_WALL, AutoMoveRobot::MODE::DISTANCE, true, 3.0f));
	AddSequential(new AutoMoveRobot(.1f, .75f, 1.35f, AutoMoveRobot::MODE::TIME, true, 1.0f));

	//Moar Sutble Bin 3 alignment
	//AddSequential(new AutoMoveRobot(.5f * dirMult, 0, DISTANCE_CLOSE_TO_WALL, AutoMoveRobot::MODE::DISTANCE, true, 2.0f));
	//AddSequential(new AutoMoveRobot(.15f, .4f, .5f, AutoMoveRobot::MODE::TIME, true, 1.0f));

	//Grab Bin 3 with the Tote Lock solenoid
	//AddSequential(new InternalSolenoidToteLock(InternalCollect::TOTE_LOCK_ENGAGED));
	//AddSequential(new AutoMoveRobot(0, 0, 0.25f, AutoMoveRobot::MODE::TIME, true, 0));
	//AddSequential(new AutoMoveRobot(-.15f, .3f, .5f, AutoMoveRobot::MODE::TIME, true, 1.0f));

	//Strafe with allllll the bins
	AddSequential(new AutoMoveRobot(-1 * dirMult, -.05f, DISTANCE_END, AutoMoveRobot::MODE::DISTANCE, true, 6.0f));
	//AddSequential(new AutoMoveRobot(0,  0, 2.0f, AutoMoveRobot::TIME, true));

	//Drop Internal
	//AddSequential(new InternalMoveWinch(.1f, .3f));
}
