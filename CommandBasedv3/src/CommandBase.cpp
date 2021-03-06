#include "CommandBase.h"
//#include "Subsystems/ExampleSubsystem.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
//ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
MecanumDrive* CommandBase::mecanumDrive = NULL;
//MecanumDrive* CommandBase::mecanumDrive2 = NULL;
InternalCollect* CommandBase::internalCollect = NULL;
SerialComs* CommandBase::serialComs = NULL;
AirCompressor* CommandBase::airCompressor = NULL;
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
	//mecanumDrive2 = mecanumDrive;

	internalCollect = new InternalCollect();

	serialComs = new SerialComs();

	airCompressor = new AirCompressor();

	lidar = new LIDAR();
}
