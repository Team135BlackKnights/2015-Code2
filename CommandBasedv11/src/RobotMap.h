#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

	//Drive Train
    const int MOTOR_FRONT_LEFT	= 10;
    const int MOTOR_REAR_LEFT	= 11;
    const int MOTOR_FRONT_RIGHT	= 12;
    const int MOTOR_REAR_RIGHT	= 13;

    //Internal
    const bool INVERTED_INTERNAL_WINCH = false;
    const int MOTOR_INTERNAL_COLLECT_LEFT = 6;
    const int MOTOR_INTERNAL_COLLECT_RIGHT = 5;
    const int MOTOR_INTERNAL_WINCH = 7;

    const int SOLENOID_INTERNAL_COLLECT = 1;
    const int DIGITAL_INTERNAL_LOWER = 2;
    const int DIGITAL_INTERNAL_UPPER = 3;

    //External
    const bool INVERTED_EXTERNAL_WINCH = false;
    const int MOTOR_EXTERNAL_WINCH = 8;
    const int SOLENOID_EXTERNAL_OPEN_CLOSE_CLAW = 0;
    const int SOLENOID_INTERNAL_TOTE_LOCK = 2;
    const int DIGITAL_EXTERNAL_LOWER = 0;
    const int DIGITAL_EXTERNAL_UPPER = 8;

    //Joysticks
    const int JOYSTICK_LEFT = 0;
    const int JOYSTICK_RIGHT = 1;
    const int JOYSTICK_MANIPULATOR_CONTROL = 2;
    const int JOYSTICK_BUTTON_BOX = 3;

//SMART DASHBOARD
    					//Default Commands
    const std::string 	T_SERIAL_RUNNING = "Serial Command Status",
    					T_DRIVE_J_RUNNING = "DriveJ Command Status",
						T_DRIVE_INTERNAL_RUNNING = "Drive Internal Status",
						T_DRIVE_EXTERNAL_RUNNING = "Drive External Status",

						//AUTO COMMANDS
						T_EXTERNAL_MOVE_WINCH = "External Move Winch Status",

						//Sensors
						T_GYRO_ANGLE = "Gyro Angle",

						//Internal
						T_INTERNAL_ROLLER_COLLECT_STATE = "Internal Roller Collect State",
						T_INTERNAL_ROLLER_POWER = "Internal Roller Speed",
						T_INTERNAL_TOTE_LOCK_STATE = "Internal Tote Lock State",

						//External
						T_EXTERNAL_CLAW_STATE = "External Claw State",


						//Lefty Mode
						T_LEFTY_MODE = "Lefty Mode",
						S_RILEY = "RILEY",
						S_ALEX = "ALEX",

						//Manipulator Control Mode
    					T_MANIPULATOR_CONTROL_MODE = "Manipulator Control Mode",
    					S_INTERNAL = "INTERNAL",
    					S_EXTERNAL = "EXTERNAL",

    					//Status constants
						S_INITIALIZED = "Initialized",
    					S_RUNNING = "Running",
						S_ENDED = "Ended",
						S_INTERRUPTED = "Interrupted",
						S_CONSTRUCTED = "Constructed",

						//Solenoid Values
    					S_OPEN = "OPEN",
						S_CLOSED = "CLOSED";



    					//T_LIDAR_RUNNING = "LIDAR Command Status",
						//T_LIDAR_DISTANCE_ONE = "LIDAR One Distance",
						//T_LIDAR_DISTANCE_TWO = "LIDAR Two Distance",
						//T_LIDAR_STEP = "LIDAR Step",

    					//T_USE_SET_ROBOT_ANGLE = "Use Set Robot Angle",
						//T_SET_ROBOT_ANGLE = "Set Robot Angle",

						//T_FIELD_ORIENTED = "Field Oriented Enabled",
    					//T_DRIVE_MODE = "Drive Mode",

    const double NO_DATA = -9642;

#endif
