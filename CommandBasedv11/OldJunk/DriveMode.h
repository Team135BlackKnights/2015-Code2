/*
 * DriveMode.h
 *
 *  Created on: Feb 14, 2015
 *      Author: robotics
 */

#ifndef DRIVEMODE_H_
#define DRIVEMODE_H_

typedef float (*func)(int); //Joystick axis function

class DriveMode {
private:
	int	EXTERNAL_CLAW_OPEN,
		EXTERNAL_CLAW_CLOSED,
		EXTERNAL_WINCH_UP,
		EXTERNAL_WINCH_DOWN,

		INTERNAL_ROLLER_IN,
		INTERNAL_ROLLER_OUT,
		INTERNAL_SOLENOID_ENGAGED,
		INTERNAL_SOLENOID_DISENGAGED,

		INTERNAL_DRIVE_UP,
		INTERNAL_DRIVE_DOWN;

	func MECANUM_FORWARDS;
	func MECANUM_SIDEWAYS;
	func MECANUM_ROTATE;
public:
	DriveMode(int, int, int, int, int, int, int, int, int, int, func*, func*, func*);
	virtual ~DriveMode();
};

#endif /* DRIVEMODE_H_ */
