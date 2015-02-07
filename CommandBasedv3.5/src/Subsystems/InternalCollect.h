#ifndef InternalCollect_H
#define InternalCollect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class InternalCollect: public Subsystem
{
private:
	Talon *liftMotor;
	int liftMotorInverted;

	Talon *collectMotor;
	int collectMotorInverted;

	Solenoid *liftSolenoid;
	bool liftSolenoidEngaged;

	Solenoid *collectSolenoid;

	const float COLLECT_OUT_POWER = -.4f;
	const float COLLECT_IN_POWER = .6f;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	InternalCollect();
	void InitDefaultCommand();

	void DriveLift(float);

	void DriveCollect(float);
	void DriveCollectOut();
	void DriveCollectIn();

	void SetLiftSolenoid(bool);
	void ControlLiftSolenoid();

	void SetControlSolenoid(bool);
};

#endif
