#ifndef InternalCollect_H
#define InternalCollect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class InternalCollect: public Subsystem
{
private:

	VictorSP *liftMotor;

	VictorSP *collectLeftMotor;
	VictorSP *collectRightMotor;

	Solenoid *collectSolenoid;
	Solenoid *upperStackSolenoid;
	bool collectEngaged;
	bool upperstackEngaged;

	DigitalInput* lowerWinchLimit;
	DigitalInput* upperWinchLimit;

	float collectPower;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	static const int COLLECT_LEFT_INVERTED = -1;
	static const int COLLECT_RIGHT_INVERTED = -COLLECT_LEFT_INVERTED;

	static const int WINCH_INVERTED = -1;

	static constexpr float COLLECT_OUT_POWER = -1.0f;
	static constexpr float COLLECT_IN_POWER = .6f;

	static const bool COLLECT_ENGAGED = true;
	static const bool COLLECT_DISENGAGED = !COLLECT_ENGAGED;

	static const bool UPPER_STACK_ENGAGED = true;
	static const bool UPPER_STACK_DISENGAGED = !UPPER_STACK_ENGAGED;

	InternalCollect();
	void InitDefaultCommand();


	void DriveLift(float);

	void DriveCollect();

	//void SetLiftSolenoid(bool);
	//void ControlLiftSolenoid();

	void SetCollectSolenoid(bool);
	void SetOpenCloseTopStack(bool);
	bool GetLimitSwitchValueUpper();
	bool GetLimitSwitchValueLower();

	void SetCollectPower(float);



};

#endif
