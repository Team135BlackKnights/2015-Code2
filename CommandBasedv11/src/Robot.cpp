#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/SerialCommunication.h"
#include "Commands/Auto/AutoMoveBinToAutoZone.h"
#include "Commands/Auto/AutoMoveRobotToZone.h"
#include "Commands/Auto/AutoMoveBinToAutoZoneRamp.h"
#include "Commands/Auto/AutoBinToteToAutoZone.h"
#include "Commands/Auto/AutoAlignToDriverWall.h"
//#include "Commands/Auto/AutoPIDTest.h"
#include "Commands/LeftyModeJustForRiley.h"

class Robot: public IterativeRobot
{
private:
	LiveWindow *lw;
	CameraServer* camera;
	CommandGroup *autonomousCommand;
	SendableChooser *chooser;
	void RobotInit()
	{
		CommandBase::init();
		lw = LiveWindow::GetInstance();
		chooser = new SendableChooser();
		//chooser->AddDefault("PID Test", new AutoPIDTest());
		chooser->AddDefault("Move Bin To Auto Zone", new AutoMoveBinToAutoZone());
		chooser->AddObject("Move Bin To Auto Zone RAMP", new AutoMoveBinToAutoZoneRamp());
		chooser ->AddObject("Move Bin and Tote to Auto Zone ", new AutoBinToteToAutoZone());
		chooser ->AddObject("Move Roboto To Zone", new AutoMoveRobotToZone);
		chooser ->AddObject("Align Robot to Driver Wall", new AutoAlignToDriverWall);
		SmartDashboard::PutData("Autonomous modes", chooser);

	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		//if (autonomousCommand != NULL)
		//autonomousCommand->Start();
		autonomousCommand = (CommandGroup *) chooser->GetSelected();
		//SmartDashboard::PutNumber("Auto Command", autonomousCommand->GetID());
		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		//if (serialCommunication != NULL)
			//serialCommunication->Start();
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
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

