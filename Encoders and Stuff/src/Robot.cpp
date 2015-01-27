#include "WPILib.h"




class Robot: public SampleRobot
{

    // Channels for the wheels
    const static int frontLeftChannel	= 2;
    const static int rearLeftChannel	= 3;
    const static int frontRightChannel	= 1;
    const static int rearRightChannel	= 0;

    const static int joystickChannelRight	= 0;
    const static int joystickChannelLeft	= 1;
	RobotDrive robotDrive;
	// Joystick stick;
	Joystick stickRight;
	Joystick stickLeft;

public:
	Robot() :
		//	robotDrive(frontLeftChannel, rearLeftChannel,
			//		   frontRightChannel, rearRightChannel),
					 // robotDrive(rearRightChannel, frontRightChannel,frontLeftChannel, rearLeftChannel),
			//stick(joystickChannel)
robotDrive(rearRightChannel, frontRightChannel,frontLeftChannel, rearLeftChannel),
			stickRight(joystickChannelRight),
			stickLeft(joystickChannelLeft)
	{
		robotDrive.SetExpiration(0.1);
		//robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
		//robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	}

	void RobotInit() override {
			CameraServer::GetInstance()->SetQuality(50);
			//the camera name (ex "cam0") can be found through the roborio web interface
			CameraServer::GetInstance()->StartAutomaticCapture("cam0");
		}

	void OperatorControl()
	{
		robotDrive.SetSafetyEnabled(false);
		while (IsOperatorControl() && IsEnabled())
		{
			//if(stickRight.GetRawButton(8))
			//{
			//robotDrive.MecanumDrive_Cartesian(-stickRight.GetX(), -stickRight.GetZ(), stickRight.GetY());
			//}

			//Single joystick control
			//robotDrive.MecanumDrive_Cartesian(-stickRight.GetX(), -stickRight.GetZ(), stickRight.GetY());

			//Two joystick control, left stick controls turning, right stick controls forward and back
			//robotDrive.MecanumDrive_Cartesian(-stickRight.GetX(), -stickLeft.GetZ(), stickRight.GetY());

			//forward/back and rotation on right and side to side on left
			robotDrive.MecanumDrive_Cartesian(-stickLeft.GetX(), -stickRight.GetZ(), stickRight.GetY());

			//right stick conrols forward/back, and x axis on right stick is rotation, left stick x axis is side to side
			//robotDrive.MecanumDrive_Cartesian(-stickLeft.GetX(), -stickRight.GetX(), stickRight.GetY());


		}
	}

};

START_ROBOT_CLASS(Robot);
