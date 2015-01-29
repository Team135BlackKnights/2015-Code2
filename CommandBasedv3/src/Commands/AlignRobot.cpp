#include "AlignRobot.h"

AlignRobot::AlignRobot(double angle) {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(mecanumDrive);
	desiredAngle = angle;
	power = 0;
}

// Called just before this Command runs the first time
void AlignRobot::Initialize() {
	SmartDashboard::PutString("Align Robot", "Initialized");
	power = .5;
}

// Called repeatedly when this Command is scheduled to run
void AlignRobot::Execute() {
	SmartDashboard::PutString("Align Robot", "Running");
	mecanumDrive->Rotate(power);
}

// Make this return true when this Command no longer needs to run execute()
bool AlignRobot::IsFinished() {
	double currentAngle = mecanumDrive->GetGyroAngle();
	return desiredAngle > currentAngle;
}

// Called once after isFinished returns true
void AlignRobot::End() {
	SmartDashboard::PutString("Align Robot", "Ended");
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AlignRobot::Interrupted() {
	SmartDashboard::PutString("Align Robot", "Interrupted");
}
