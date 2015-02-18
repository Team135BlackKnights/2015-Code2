#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/SerialCommunication.h"
#include "Commands/AutoMoveBinToAutoZone.h"
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
		chooser->AddDefault("Move Bin To Auto Zone", new AutoMoveBinToAutoZone());
		SmartDashboard::PutData("Autonomous modes", chooser);

		//SmartDashboard::PutBoolean(T_SET_ROBOT_ANGLE, false);
		//SmartDashboard::PutNumber(T_ROBOT_ANGLE, 0);

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

