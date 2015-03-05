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


	bool leftyMode;
	bool manipulatorControlMode = true;
	//bool fieldOriented;
	//int driveMode;

public:

	int LEFT = 0;
	int RIGHT = 1;
	int MANIPULATOR_CONTROL = 2;

	static constexpr float DEAD_BAND = .05f;

	 					//Manipulator Control Mode
	static const bool	EXTERNAL = true,
						INTERNAL = false;
	static const int 	CHANGE_MANIPULATOR_CONTROL_MODE_EXTERNAL = 11,
						CHANGE_MANIPULATOR_CONTROL_MODE_INTERNAL = 12;

						//Lefty Mode
	static const bool	RILEY = true,
						ALEX = false;
	static const int	CHANGE_LEFTY_MODE_RILEY = 11,
						CHANGE_LEFTY_MODE_ALEX = 12;

						//External
	static const int	EXTERNAL_CLAW_OPEN = 2,
						EXTERNAL_CLAW_CLOSED = 1,
						EXTERNAL_WINCH_UP = 3,
						EXTERNAL_WINCH_DOWN = 4,

						//Internal
						INTERNAL_ROLLER_IN = 1,
						INTERNAL_ROLLER_OUT = 2,
						INTERNAL_ROLLER_SOLENOID_ENGAGED = 3,
						INTERNAL_ROLLER_SOLENOID_DISENGAGED = 4,
						INTERNAL_UPPER_STACK_SOLENOID_ENGAGED = 5,
						INTERNAL_UPPER_STACK_SOLENOID_DISENGAGED = 6;


						//INTERNAL_DRIVE_UP = 5,
						//INTERNAL_DRIVE_DOWN = 6,

						//MISC_CHANGE_DRIVE_MODE_A = 7, //RIGHT
						//MISC_CHANGE_DRIVE_MODE_B = 8, //RIGHT

						//MISC_FIELD_ORIENTED_ON = 9, //RIGHT
						//MISC_FIELD_ORIENTED_OFF = 10; //RIGHT

	OI();
	float GetStickX(int);
	float GetStickY(int);
	float GetStickTwist(int);
	float GetStickSlider(int);
	bool GetButton(int stick, int);

	void LeftyFlip(bool);

	bool GetManipulatorControlMode();
	void SetManipulatorControlMode(bool);

	/*
	bool GetFieldOriented();
	void SetFieldOriented(bool);

	int GetDriveMode();
	void SetDriveMode(int);
	*/
};
#endif
