#ifndef ExternalCollect_H
#define ExternalCollect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExternalCollect: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid* clawOpenClose;
	VictorSP* winch;
	bool clawState;
public:
	static bool CLAW_OPEN = true;
	static bool CLAW_CLOSED = false;

	ExternalCollect();
	void InitDefaultCommand();
	void SetOpenCloseClawState(bool);
	void PowerOpenCloseClaw();
	void DriveWinch(float);
};

#endif
