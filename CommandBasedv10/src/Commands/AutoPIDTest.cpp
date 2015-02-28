#include "AutoPIDTest.h"

AutoPIDTest::AutoPIDTest()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(mecanumDrive);
	timer = new Timer();
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	char formattedTime[80];
	//std::string formattedTime;//(std::string)asctime(now) + ".csv";
	//formattedTime = std::string::
	sprintf(formattedTime, "%s%d_%d_%d_%d_%d.csv", FILE_PATH, now->tm_mon, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
	fileName = (std::string)formattedTime;
	SmartDashboard::PutString("Data File name", fileName);
	velocities = new float[4];

}

// Called just before this Command runs the first time
void AutoPIDTest::Initialize()
{
	file.open(fileName.c_str(), std::ios_base::out | std::ios_base::trunc);
	file << HEADER << std::endl;
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutoPIDTest::Execute()
{
	mecanumDrive->Drive(0, 1, 0, 0);
	mecanumDrive->GetDriveVelocties(velocities);
	for (int i = 0; i < MecanumDrive::NUM_MOTORS; i++)
	{
		//char vel[40];
		//sprintf(vel, "%f", velocities[i]);
		//SmartDashboard::SetGlobalWPIError(vel, "test1", __FILE__, __FUNCTION__, __LINE__);
		if (i!=0)
			file << ",";
		file << velocities[i];// << ((i == (MecanumDrive::NUM_MOTORS - 1)) ? (std::endl) : ",");
	}
	file << std::endl << std::flush;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoPIDTest::IsFinished()
{
	return timer->HasPeriodPassed(END_TIME);
}

// Called once after isFinished returns true
void AutoPIDTest::End()
{
	if (file.is_open())
		file.close();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoPIDTest::Interrupted()
{
	if (file.is_open())
		file.close();
}
