#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

//#include <Commands/DriveJ.h>
#include <string>
#include "Commands/Command.h"
//#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/MecanumDrive.h"
#include "Subsystems/InternalCollect.h"
#include "Subsystems/SerialComs.h"
#include "Subsystems/AirCompressor.h"
#include "Subsystems/LIDAR.h"
#include "Subsystems/ExternalCollect.h"
#include "OI.h"
#include "WPILib.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	//static ExampleSubsystem *examplesubsystem;
	static OI *oi;
	static MecanumDrive *mecanumDrive;
	//static MecanumDrive *mecanumDrive2;
	static InternalCollect *internalCollect;
	static SerialComs *serialComs;
	static AirCompressor *airCompressor;
	static LIDAR *lidar;
	static ExternalCollect *externalCollect;
};

#endif
