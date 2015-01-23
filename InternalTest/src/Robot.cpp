/*
 *External Collection System using Limit Switches
 */

#include "WPILib.h"
class Robot: public SampleRobot
{

    // Channels for the wheels
    const static int frontLeftChannel	= 2;
    const static int rearLeftChannel	= 3;
    const static int frontRightChannel	= 1;
    const static int rearRightChannel	= 0;

    const static int joystickChannel = 0;
    const static int joystickChannel2 = 1;
    const static int TalonChannel1 = 4;
    const static int TalonChannel2 = 5;

	RobotDrive robotDrive;



	Talon Window1;
	Talon Window2;

	Joystick stick;
	Joystick stick2;

public:
	Robot() :
			robotDrive(frontLeftChannel, rearLeftChannel, frontRightChannel, rearRightChannel),
			Window1(TalonChannel1),
			Window2(TalonChannel2),

			stick(joystickChannel),
			stick2(joystickChannel2)
	{
		robotDrive.SetExpiration(0.1);
	}
	void OperatorControl()
	{
		robotDrive.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{

//--------------------------------Drive--------------------------------------------
			robotDrive.MecanumDrive_Cartesian(-stick.GetX(), -stick.GetZ(), stick.GetY());
//---------------------------------End Drive---------------------------------------



			Window1.Set(stick2.GetY());
			Window2.Set(stick2.GetY());

			/*
			if(stick2.GetRawButton(10))
				{
					Window1.Set(-1);
					Window2.Set(-1);


				}
			if (stick2.GetRawButton(8))
			{
				Window1.Set(1);
				Window2.Set(1);
			}

*/

		}
	}

};

START_ROBOT_CLASS(Robot);
