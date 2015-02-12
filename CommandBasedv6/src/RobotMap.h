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

    const int MOTOR_INTERNAL_COLLECT_LEFT = 6;
    const int MOTOR_INTERNAL_COLLECT_RIGHT = 5;
    const int MOTOR_INTERNAL_WINCH = 7;

    const int MOTOR_EXTERNAL_WINCH = 8;

    const int SOLENOID_INTERNAL_COLLECT = 1;
    const int SOLENOID_EXTERNAL_OPEN_CLOSE_CLAW = 2;
    //const int SOLENOID_EXTERNAL_HINGE_CLAW = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

    const int JOYSTICK_LEFT = 0;
    const int JOYSTICK_RIGHT = 1;
    const int JOYSTICK_EXTERNAL_CONTROL = 2;
    const int JOYSTICK_BUTTON_BOX = 3;

    const int DIGITAL_LIDAR_ONE = 8;
    const int DIGITAL_LIDAR_TWO= 9;
    const int DIGITAL_EXTERNAL_LOWER_WINCH = 0;

    const int DIGITAL_INTERNAL_LOWER = 1;
    const int DIGITAL_INTERNAL_UPPER = 2;

    const std::string T_SERIAL_RUNNING = "Serial Command Status";
    const std::string T_DRIVE_J_RUNNING = "DriveJ Command Status";
    const std::string T_DRIVE_INTERNAL_RUNNING = "Drive Internal Status";
    const std::string T_LIDAR_RUNNING = "LIDAR Command Status";
    const std::string T_LIDAR_DISTANCE_ONE = "LIDAR One Distance";
    const std::string T_LIDAR_DISTANCE_TWO = "LIDAR Two Distance";
    const std::string T_LIDAR_STEP = "LIDAR Step";
    const std::string T_DRIVE_EXTERNAL_RUNNING = "Drive External Status";
    const std::string T_LEFTY_MODE = "Lefty Mode Enabled";
    const std::string T_RUN_WINCH_UNTIL_STOPPED = "Run Winch Until Stop";
    const std::string T_HINGE_CLAW = "External Hinge Status";
    const std::string T_CLAW_OPEN_CLOSE = "External Claw Status";
    const std::string T_BACK_UP_RUNNING = "Back Up Status";
    const double NO_DATA = -9642;

    //const std::string AXIS_CAMERA_IP = "192.168.0.90";

#endif
