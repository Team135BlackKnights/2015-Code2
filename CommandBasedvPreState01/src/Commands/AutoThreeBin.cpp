#include "AutoThreeBin.h"
#include "InternalSolenoidRoller.h"
#include "AutoMoveRobot.h"
#include "ExternalSolenoidClaw.h"
#include "AutoRotateRobot.h"
#include "AutoMoveBinToAutoZone.h"
#include "InternalRollers.h"

AutoThreeBin::AutoThreeBin()
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
	AddSequential(new AutoMoveRobot(0, 0, .25f, AutoMoveRobot::TIME, false));

	//Line up with other bin
	AddSequential(new AutoMoveRobot(.6f, 0, DISTANCE_CLOSE_TO_WALL, AutoMoveRobot::DISTANCE, true, .8f));
	AddSequential(new AutoMoveRobot(0,  0, .25f, AutoMoveRobot::TIME, true));
	AddSequential(new AutoMoveRobot(0, .45f, 2.2f, AutoMoveRobot::TIME, true));
	AddSequential(new AutoMoveRobot(0,  0, .25f, AutoMoveRobot::TIME, true));

	//Strafe with other bin
	AddSequential(new AutoMoveRobot(-0.9f, 0, DISTANCE_END, AutoMoveRobot::DISTANCE, true, .8f));
	//AddSequential(new AutoMoveRobot(0,  0, 2.0f, AutoMoveRobot::TIME, true));


	/* Two Bin Old code
	//ROTATE perpendicular to driver station
	AddSequential(new AutoRotateRobot(-90, .4f, 6.0f));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Move to Zone
	AddSequential(new AutoMoveRobot(0, .45, 3.28f, AutoMoveRobot::TIME, true));
	AddSequential(new AutoMoveRobot(0, 0, .5f, AutoMoveRobot::TIME, false));

	//Rotate parallel to driver wall
	AddSequential(new AutoRotateRobot(90, .4f, 7.0f));

	//Back up a bit
	AddSequential(new AutoMoveRobot(0, .35, 1.35f, AutoMoveRobot::TIME, true));
	*/
}
