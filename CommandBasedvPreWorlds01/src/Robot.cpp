#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/SerialCommunication.h"
#include "Commands/AutoMoveBinToAutoZone.h"
#include "Commands/AutoMoveRobotToZone.h"
#include "Commands/AutoMoveBinToAutoZoneRamp.h"
#include "Commands/AutoBinToteToAutoZone.h"
#include "Commands/AutoAlignToDriverWall.h"
#include "Commands/LeftyModeJustForRiley.h"
#include "Commands/AutoPIDTest.h"
#include "Commands/AutoTwoBinTote.h"
#include "Commands/AUTOMATT.h"
#include "Commands/ChangeDriveMode.h"
#include "Commands/AutoTwoBin.h"
#include "Commands/AutoThreeTote.h"
#include "Commands/AutoDoNothing.h"
#include "Commands/AutoTwoBinV2.h"
#include "Commands/AutoBinTwoTote.h"
#include "Commands/AutoThreeBin.h"
#include "Commands/AutoBinPurdueFinals.h"
#include "Commands/AutoTwoBinRAMP.h"
#include "Commands/AutoTwoBinRampRightSide.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	CameraServer* camera;
	CommandGroup *autonomousCommand;
	Command *driverModeCommand;
	SendableChooser *chooser;
	SendableChooser *driverMode;

	//NamedSendable *testChooser;
	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();

		driverMode = new SendableChooser();
		driverMode->AddDefault("RILEY MODe", new ChangeDriveMode(OI::RILEY));
		driverMode->AddObject("ALEX MODe", new ChangeDriveMode(OI::ALEX));
		SmartDashboard::PutData("Driver Modes", driverMode);

		chooser = new SendableChooser();
		//testChooser = new NamedSendable();

		chooser->AddDefault("0 Bin DO NOTHING", new AutoDoNothing());
		chooser ->AddObject("0 Bin Move Robot To Zone", new AutoMoveRobotToZone());
		chooser->AddObject("1 Bin To Auto Zone", new AutoMoveBinToAutoZone());
		chooser->AddObject("1 Bin To Auto Zone RAMP", new AutoMoveBinToAutoZoneRamp());
		chooser->AddObject("2 Bin", new AutoTwoBinV2(false));
		chooser->AddObject("2 Bin RAMP", new AutoTwoBinV2(true));
		chooser->AddObject("3 Bin", new AutoThreeBin());

		//chooser->AddObject("Auto Two Bin RAMP UNTESTED", new AutoTwoBinRAMP());
		//chooser->AddObject("Auto Two Bin Ramp Right Side", new AutoTwoBinRampRightSide());
		//chooser->AddObject("Auto Three Bin YES RAMP UNTESTED", new AutoThreeBin(true));

		//chooser->AddDefault("Two Bin Tote", new AutoTwoBinTote());
		//chooser->AddObject("PID Test", new AutoPIDTest());
		//chooser ->AddObject("Move Bin and Tote to Auto Zone ", new AutoBinToteToAutoZone());
		//chooser ->AddObject("Align Robot to Driver Wall", new AutoAlignToDriverWall());
		//chooser ->AddObject("autMatt", new AUTOMATT());
		//chooser ->AddObject("Auto Two Bin", new AutoTwoBin());
		//chooser->AddObject("Auto Three Tote", new AutoThreeTote());
		//chooser->AddObject("Auto Bin Two Tote UNTESTED", new AutoBinTwoTote());
		//chooser->AddObject("Auto Bin Purdue Finals", new AutoBinPurdueFinals());


		SmartDashboard::PutData("Autonomous modes", chooser);
		SmartDashboard::PutNumber("LIDAR Jump", 0);
		//SmartDashboard::PutBoolean(T_SET_ROBOT_ANGLE, false);
		//SmartDashboard::PutNumber(T_ROBOT_ANGLE, 0);

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (CommandGroup*) chooser->GetSelected();
		//autonomousCommand = new AutoThreeBin();
		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		//lw->Run();
	}

	void TeleopInit()
	{
		driverModeCommand = (Command*)driverMode->GetSelected();
		driverModeCommand->Start();
		//if (serialCommunication != NULL)
			//serialCommunication->Start();
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		//if (autonomousCommand != NULL)
			//autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

