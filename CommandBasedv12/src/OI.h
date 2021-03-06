#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
protected:
	static const int NUMBER_O_JOYSTICKS = 3;
	static const int MAX_JOYSTICK_BUTTONS = 12;
	Joystick* sticks[NUMBER_O_JOYSTICKS]; //0 is Left, 1 is Right
	JoystickButton* buttons[NUMBER_O_JOYSTICKS][MAX_JOYSTICK_BUTTONS + 1];

	int driveMode;
	bool leftyMode;
	bool manipulatorControlMode = true;
	bool fieldOriented;

	//DriveMode

public:
	int LEFT = 0;
	int RIGHT = 1;
	static const int MANIPULATOR_CONTROL = 2;

	static const int STATIC_LEFT = 0;
	static const int STATIC_RIGHT = 1;

	static constexpr float DEAD_BAND = .05f;

	static const bool 	EXTERNAL = true,
						INTERNAL = false,

						RILEY = true,
						ALEX = false;


	static const int	EXTERNAL_CLAW_OPEN = 2,
						EXTERNAL_CLAW_CLOSED = 1,
						EXTERNAL_WINCH_UP = 3,
						EXTERNAL_WINCH_DOWN = 4,

						INTERNAL_ROLLER_IN = 1,
						INTERNAL_ROLLER_OUT = 2,
						INTERNAL_ROLLER_SOLENOID_ENGAGED = 3,
						INTERNAL_ROLLER_SOLENOID_DISENGAGED = 4,
						INTERNAL_UPPER_STACK_SOLENOID_ENGAGED = 5,
						INTERNAL_UPPER_STACK_SOLENOID_DISENGAGED = 6,

						INTERNAL_ROLLER_SOLENOID_ENGAGED_ALEX = 9,
						INTERNAL_ROLLER_SOLENOID_DISENGAGED_ALEX = 10,


						INTERNAL_DRIVE_UP = 5,
						INTERNAL_DRIVE_DOWN = 6,

						MISC_LEFTY_MODE_DISABLED = 11, //RIGHT
						MISC_LEFTY_MODE_ENABLED = 12, //RIGHT

						MISC_CHANGE_MANIPULATOR_CONTROL_MODE_EXTERNAL = 11, //MANIPULATOR_CONTROL
						MISC_CHANGE_MANIPULATOR_CONTROL_MODE_INTERNAL = 12, //MANIPULATOR_CONTROL

						MISC_CHANGE_DRIVE_MODE_A = 7, //RIGHT
						MISC_CHANGE_DRIVE_MODE_B = 8, //RIGHT
						MISC_CHANGE_DRIVE_MODE_C = 9;

						//MISC_FIELD_ORIENTED_ON = 9, //RIGHT
						//MISC_FIELD_ORIENTED_OFF = 10; //RIGHT

	OI();
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	float GetStickSlider(int);
	bool GetButton(int stick, int);
	void LeftyFlip(bool);

	int GetDriveMode();
	void SetDriveMode(int);

	bool GetManipulatorControlMode();
	void SetManipulatorControlMode(bool);

	bool GetFieldOriented();
	void SetFieldOriented(bool);
};

#endif
