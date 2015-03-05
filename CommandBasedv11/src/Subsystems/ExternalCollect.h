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

	ExternalCollect();
	void InitDefaultCommand();
	void SetClawState(bool state);
	void PowerClaw();

	void DriveWinch(float power);
};

#endif
