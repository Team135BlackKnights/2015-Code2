#ifndef Winch_H
#define Winch_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Winch: public Subsystem
{
private:
	VictorSP* motor;
	//DigitalInput* lowerLimit;
	//DigitalInput* upperLimit;
	int inverted;

public:
	Winch(int,/* int, int, */bool);
	void InitDefaultCommand();

	void DriveWinch(float);
};

#endif
