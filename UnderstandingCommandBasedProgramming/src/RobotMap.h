#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;
    const int MOTOR_FRONT_LEFT	= 2;
    const int MOTOR_REAR_LEFT	= 3;
    const int MOTOR_FRONT_RIGHT	= 1;
    const int MOTOR_REAR_RIGHT	= 0;

    const int MOTOR_INTERNAL_COLLECT_LEFT = 5;
    const int MOTOR_INTERNAL_COLLECT_RIGHT = 4;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

    const int JOYSTICK_LEFT = 0;
    const int JOYSTICK_RIGHT = 1;

    const std::string SERIAL_RUNNING = "Serial Running";
    const std::string DRIVE_J_RUNNING = "DriveJ Running";
    const std::string DRIVE_INTERNAL_RUNNING = "Drive Internal Running";

    const double NO_DATA = -9642;

#endif
