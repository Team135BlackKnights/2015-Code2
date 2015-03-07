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

	//constexpr bool ROBOT_MAIN = false;

    const int MOTOR_FRONT_LEFT	= 10;
    const int MOTOR_REAR_LEFT	= 11;
    const int MOTOR_FRONT_RIGHT	= 12;
    const int MOTOR_REAR_RIGHT	= 13;

    const int MOTOR_INTERNAL_COLLECT_LEFT = 6;
    const int MOTOR_INTERNAL_COLLECT_RIGHT = 5;
    const int MOTOR_INTERNAL_WINCH = 7;
    const bool INVERTED_INTERNAL_WINCH = false;

    const int MOTOR_EXTERNAL_WINCH = 8;
    const int INVERTED_EXTERNAL_WINCH = false;

    const int SOLENOID_INTERNAL_COLLECT = 1;
    const int SOLENOID_EXTERNAL_OPEN_CLOSE_CLAW = 0;
    const int SOLENOID_INTERNAL_TOTE_LOCK = 2;
    //const int SOLENOID_EXTERNAL_HINGE_CLAW = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:

    const int JOYSTICK_LEFT = 0;
    const int JOYSTICK_RIGHT = 1;
    const int JOYSTICK_MANIPULATOR_CONTROL = 2;
    const int JOYSTICK_BUTTON_BOX = 3;

    const int DIGITAL_LIDAR_ONE = 8;
    const int DIGITAL_LIDAR_TWO= 9;

    const int DIGITAL_EXTERNAL_LOWER = 0;
    const int DIGITAL_EXTERNAL_UPPER = 8;

    const int DIGITAL_INTERNAL_LOWER = 2;
    const int DIGITAL_INTERNAL_UPPER = 3;

    const int ANALOG_GYRO_A = 0;
    const int ANALOG_GYRO_B = 1;

    const std::string 	T_SERIAL_RUNNING = "Serial Command Status",
    					T_DRIVE_J_RUNNING = "DriveJ Command Status",
						T_DRIVE_INTERNAL_RUNNING = "Drive Internal Status",
						T_DRIVE_EXTERNAL_RUNNING = "Drive External Status",

						T_LIDAR_RUNNING = "LIDAR Command Status",
						T_LIDAR_DISTANCE_ONE = "LIDAR One Distance",
						T_LIDAR_DISTANCE_TWO = "LIDAR Two Distance",
						T_LIDAR_STEP = "LIDAR Step",
						T_GYRO_ANGLE = "Gyro Angle",

						T_CLAW_STATE_ENGAGED = "External Claw Engaged",
						T_TOTE_LOCK_ENGAGED = "External Tote Lock Engaged",
						T_ROLLER_COLLECT_ENGAGED = "Internal Roller Collect Engaged",

    					T_USE_SET_ROBOT_ANGLE = "Use Set Robot Angle",
						T_SET_ROBOT_ANGLE = "Set Robot Angle",

						T_FIELD_ORIENTED = "Field Oriented Enabled",
						T_LEFTY_MODE = "Lefty Mode Enabled",
    					T_DRIVE_MODE = "Drive Mode",

    					T_EXTERNAL_OPEN_CLOSE_CLAW = "Claw Status",
    					T_EXTERNAL_MOVE_WINCH = "External Winch Status",
    					T_AUTO_ROTATE_ROBOT = "Auto Rotate Robot";

    const std::string 	S_INITIALIZED = "Initialized",
    					S_RUNNING = "Running",
						S_ENDED = "Ended",
						S_INTERRUPTED = "Interrupted";



    const double NO_DATA = -9642;

#endif
