#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
//ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
MecanumDrive* CommandBase::mecanumDrive = NULL;
InternalCollect* CommandBase::internalCollect = NULL;
SerialComs* CommandBase::serialComs = NULL;
//LIDAR* CommandBase::lidarOne = NULL;
//LIDAR* CommandBase::lidarTwo = NULL;
ExternalCollect* CommandBase::externalCollect = NULL;
LIDAR* CommandBase::lidar = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	//examplesubsystem = new ExampleSubsystem();

	oi = new OI();

	mecanumDrive = new MecanumDrive();

	internalCollect = new InternalCollect();

	serialComs = new SerialComs();

	//lidarOne = new LIDAR(DIGITAL_LIDAR_ONE);
	//lidarTwo = new LIDAR(DIGITAL_LIDAR_TWO);

	externalCollect = new ExternalCollect();

	lidar = new LIDAR();
}
