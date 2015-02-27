#ifndef AutoPIDTest_H
#define AutoPIDTest_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include "../CommandBase.h"
#include "WPILib.h"

#define FILE_PATH  "C:\\Users\\robotics\\Desktop\\PIDTuningData\\"

class AutoPIDTest: public CommandBase
{
private:
	Timer* timer;
	std::fstream file;
	std::string fileName;
	float* velocities;

	static constexpr double END_TIME = 2;
public:
	AutoPIDTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
