#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "RobotMap.h"

// Initialize a single static instance of all of your subsystems to NULL
//ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi = NULL;
MecanumDrive* CommandBase::mecanumDrive = NULL;
InternalCollect* CommandBase::internalCollect = NULL;
//SerialComs* CommandBase::serialComs = NULL;
ExternalCollect* CommandBase::externalCollect = NULL;

CommandBase::CommandBase(char const *name) : Command(name) {}

CommandBase::CommandBase() : Command() {}

void CommandBase::init()
{
	oi = new OI();

	mecanumDrive = new MecanumDrive();

	internalCollect = new InternalCollect();

	//serialComs = new SerialComs();

	externalCollect = new ExternalCollect();
}
