#ifndef InternalCollect_H
#define InternalCollect_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class InternalCollect: public Subsystem
{
private:
	Talon *motors[2];
	int inverted;
	const int LEFT = 0, RIGHT = 1;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	InternalCollect();
	void InitDefaultCommand();
	void SetMotorPower(float);
};

#endif
