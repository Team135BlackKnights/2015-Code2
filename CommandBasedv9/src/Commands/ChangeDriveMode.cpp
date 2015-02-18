#include "ChangeDriveMode.h"

ChangeDriveMode::ChangeDriveMode(int mode)
{
	Requires(mecanumDrive);
	driveMode = mode;
}

// Called just before this Command runs the first time
void ChangeDriveMode::Initialize()
{
	mecanumDrive->SetDriveMode(driveMode);
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeDriveMode::IsFinished()
{
	return true;
}

void ChangeDriveMode::Execute() {};
void ChangeDriveMode::End() {};
void ChangeDriveMode::Interrupted() {};
