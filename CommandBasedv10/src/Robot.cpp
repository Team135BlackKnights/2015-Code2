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
class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	CameraServer* camera;
	CommandGroup *autonomousCommand;
	Command *driverModeCommand;
	SendableChooser *chooser;
	SendableChooser *driverMode;
	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		chooser = new SendableChooser();
		chooser->AddDefault("Two Bin Tote", new AutoTwoBinTote());
		chooser->AddObject("PID Test", new AutoPIDTest());
		chooser->AddObject("Move Bin To Auto Zone", new AutoMoveBinToAutoZone());
		chooser->AddObject("Move Bin To Auto Zone RAMP", new AutoMoveBinToAutoZoneRamp());
		chooser ->AddObject("Move Bin and Tote to Auto Zone ", new AutoBinToteToAutoZone());
		chooser ->AddObject("Move Roboto To Zone", new AutoMoveRobotToZone);
		chooser ->AddObject("Align Robot to Driver Wall", new AutoAlignToDriverWall());
		chooser ->AddDefault("autMatt", new AUTOMATT());
		SmartDashboard::PutData("Autonomous modes", chooser);
		SmartDashboard::PutNumber("LIDAR Jump", 0);

		driverMode = new SendableChooser();
		driverMode->AddDefault("RILEY MODe", new ChangeDriveMode(OI::RILEY));
		driverMode->AddObject("ALEX MODe", new ChangeDriveMode(OI::ALEX));
		SmartDashboard::PutData("Driver Modes", driverMode);
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
		//SmartDashboard::PutNumber("Auto Command", autonomousCommand->GetID());
		//autonomousCommand = new AutoTwoBinTote();
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

