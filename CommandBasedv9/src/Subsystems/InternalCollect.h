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
	bool rollerCollectEngaged;
	bool toteLockEngaged;

	Winch* winch;

	float collectPower;
public:
	static const int COLLECT_LEFT_INVERTED = -1;
	static const int COLLECT_RIGHT_INVERTED = -COLLECT_LEFT_INVERTED;

	static constexpr float COLLECT_OUT_POWER = -1.0f;
	static constexpr float COLLECT_IN_POWER = .6f;

	static const bool ROLLER_COLLECT_ENGAGED = false;
	static const bool ROLLER_COLLECT_DISENGAGED = !ROLLER_COLLECT_ENGAGED;

	static const bool TOTE_LOCK_ENGAGED = true;
	static const bool TOTE_LOCK_DISENGAGED = !TOTE_LOCK_ENGAGED;

	InternalCollect();
	void InitDefaultCommand();


	void DriveLift(float);

	void DriveCollect();

	//void SetLiftSolenoid(bool);
	//void ControlLiftSolenoid();

	void SetRollerCollectSolenoid(bool);
	void SetToteLockSolenoid(bool);

	void SetCollectPower(float);



};

#endif
