#include "AirCompressor.h"
#include "../RobotMap.h"
#include "../Commands/Pneumatics.h"

AirCompressor::AirCompressor() :
		Subsystem("AirCompressor")
{
	compressor = new Compressor();
}

void AirCompressor::InitDefaultCommand()
{

	//SetDefaultCommand(new Pneumatics());
}



void AirCompressor::StartCompressing()
{
	compressor->Start();
}
