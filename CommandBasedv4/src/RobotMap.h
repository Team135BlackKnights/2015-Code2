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
    const int MOTOR_FRONT_LEFT	= 10;
    const int MOTOR_REAR_LEFT	= 11;
    const int MOTOR_FRONT_RIGHT	= 12;
    const int MOTOR_REAR_RIGHT	= 13;

    const int MOTOR_INTERNAL_LEFT = 5;
    const int MOTOR_INTERNAL_RIGHT = 4;

    const int MOTOR_EXTERNAL_WINCH = 5;
    const int SOLENOID_EXTERNAL_CLAW = 0;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

    const int JOYSTICK_LEFT = 0;
    const int JOYSTICK_RIGHT = 1;
    const int JOYSTICK_BUTTON = 2;

    const std::string T_SERIAL_RUNNING = "Serial Command Status";
    const std::string T_DRIVE_J_RUNNING = "DriveJ Command Status";
    const std::string T_DRIVE_INTERNAL_RUNNING = "Drive Internal Status";
    const std::string T_LIDAR_RUNNING = "LIDAR Command Status";
    const std::string T_LIDAR_DISTANCE = "LIDAR Distance";
    const std::string T_LIDAR_STEP = "LIDAR Step";

    const double NO_DATA = -9642;

    const std::string AXIS_CAMERA_IP = "192.168.0.90";

#endif
