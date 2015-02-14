#ifndef ExternalCollect_H
#define ExternalCollect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExternalCollect: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid* openCloseClaw;
	//Solenoid* hingeClaw;
	VictorSP* winch;
	bool openCloseClawState;
	//bool hingeClawState;
	DigitalInput* switches[1];
public:
	static const bool CLAW_OPEN = false;
	static const bool CLAW_CLOSED = true;

	//static const bool CLAW_UP = true;
	//static const bool CLAW_DOWN = false;

	ExternalCollect();
	void InitDefaultCommand();
	void SetOpenCloseClawState(bool);
	void SetHingeClawState(bool);
	void PowerClaw();

	void DriveWinch(float);

	bool GetLimitSwitchValue(int port);
};

#endif
