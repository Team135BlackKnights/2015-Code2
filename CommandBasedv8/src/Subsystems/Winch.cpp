#include "Winch.h"
#include "../RobotMap.h"

Winch::Winch(int motorPort, int lowerLimitPort, int upperLimitPort, bool isInverted) :
		Subsystem("ExampleSubsystem")
{
	this->motor = new VictorSP(motorPort);
	this->lowerLimit = new DigitalInput(lowerLimitPort);
	this->upperLimit = new DigitalInput(upperLimitPort);
	this->inverted = isInverted ? -1 : 1;
}

void Winch::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Winch::DriveWinch(float power)
{
	/*
	if (lowerLimit != NULL && lowerLimit->Get())
		power = fmin(power, 0);
	else if (upperLimit != NULL && upperLimit->Get())
		power = fmax(power, 0);
	 */

	motor->Set(power * inverted);
}
