#ifndef MechanumDrive_H
#define MechanumDrive_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Mecanum: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Mecanum();
	void InitDefaultCommand();
};

#endif
