#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/SerialCommunication.h"

class Robot: public IterativeRobot
{
private:
	//Command *autonomousCommand;
	LiveWindow *lw;
	Command *serialCommunication;
	CameraServer* camera;

	void RobotInit()
	{
		CommandBase::init();
		//autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		//serialCommunication = new SerialCommunication();
		SmartDashboard::PutString("test", "IT WORKDS");

		//camera = CameraServer::GetInstance();

		//camera->SetQuality(50);
		//camera->StartAutomaticCapture("cam0");
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (serialCommunication != NULL)
			serialCommunication->Start();
		//if (autonomousCommand != NULL)
		//autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		if (serialCommunication != NULL)
			serialCommunication->Start();
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

