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
	bool collectEngaged;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	static const int COLLECT_LEFT_INVERTED = 1;
	static const int COLLECT_RIGHT_INVERTED = -1;

	//static const float COLLECT_OUT_POWER = .4f;
	//static const float COLLECT_IN_POWER = .6f;

	static const bool COLLECT_ENGAGED = true;
	static const bool COLLECT_DISENGAGED = !COLLECT_ENGAGED;

	InternalCollect();
	void InitDefaultCommand();


	void DriveLift(float);

	void DriveCollect(float);
	void DriveCollectOut();
	void DriveCollectIn();

	//void SetLiftSolenoid(bool);
	//void ControlLiftSolenoid();

	void SetCollectSolenoid(bool);




};

#endif
