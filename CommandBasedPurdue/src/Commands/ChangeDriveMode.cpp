#include "ChangeDriveMode.h"

ChangeDriveMode::ChangeDriveMode(bool mode)
{
	//Requires(mecanumDrive);
	this->mode = mode;
}

// Called just before this Command runs the first time
void ChangeDriveMode::Initialize()
{
	//oi->SetDriveMode(driveMode);
	oi->SetDriveMode(OI::MISC_CHANGE_DRIVE_MODE_B);
	oi->LeftyFlip(this->mode);
}

// Make this return true when this Command no longer needs to run execute()
bool ChangeDriveMode::IsFinished()
{
	return true;
}

void ChangeDriveMode::Execute() {};
void ChangeDriveMode::End() {};
void ChangeDriveMode::Interrupted() {};
