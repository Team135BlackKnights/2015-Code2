#ifndef ExternalCollect_H
#define ExternalCollect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Subsystems/Winch.h"

class ExternalCollect: public Subsystem
{
private:
	Solenoid* claw;
	bool clawState;
	Winch* winch;
public:
	static const bool CLAW_OPEN = false;
	static const bool CLAW_CLOSED = !CLAW_OPEN;

	//static const int WINCH_INVERTED = -1;

	//static const bool CLAW_UP = true;
	//static const bool CLAW_DOWN = false;

	ExternalCollect();
	void InitDefaultCommand();
	void SetClawState(bool);
	void PowerClaw();

	void DriveWinch(float);
};

#endif
