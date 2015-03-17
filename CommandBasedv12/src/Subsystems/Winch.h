#ifndef Winch_H
#define Winch_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Winch: public Subsystem
{
private:
	VictorSP* motor;
	DigitalInput* lowerLimit;
	DigitalInput* upperLimit;
	int inverted;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Winch(int, int, int, bool);
	void InitDefaultCommand();

	void DriveWinch(float);
};

#endif
