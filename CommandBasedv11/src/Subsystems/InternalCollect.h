#ifndef InternalCollect_H
#define InternalCollect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Subsystems/Winch.h"

class InternalCollect: public Subsystem
{
private:

	VictorSP *collectLeftMotor;
	VictorSP *collectRightMotor;

	Solenoid *rollerCollectSolenoid;
	Solenoid *toteLockSolenoid;

	bool rollerCollectState;
	bool toteLockState;

	Winch* winch;

	float collectPower;

public:
	static const int COLLECT_LEFT_INVERTED = -1;
	static const int COLLECT_RIGHT_INVERTED = -COLLECT_LEFT_INVERTED;

	static const bool ROLLER_COLLECT_CLOSED = false;
	static const bool ROLLER_COLLECT_OPEN = !ROLLER_COLLECT_CLOSED;

	static const bool TOTE_LOCK_CLOSED = false;
	static const bool TOTE_LOCK_OPEN = !TOTE_LOCK_CLOSED;

	InternalCollect();
	void InitDefaultCommand();


	void DriveLift(float);

	void DriveCollect();

	void SetRollerCollectSolenoid(bool state);
	void SetToteLockSolenoid(bool state);

	void SetCollectPower(float power);

	void PowerSolenoids();

};

#endif
