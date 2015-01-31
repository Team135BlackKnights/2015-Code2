#include "AlignRobot.h"

AlignRobot::AlignRobot(double angle) {
	// Use requires() here to declare subsystem dependencies

	Requires(mecanumDrive);
	desiredAngle = angle; // Sets the desired angle value to the angle
	power = 0; //power is motor rotate power
}

// Called just before this Command runs the first time
void AlignRobot::Initialize() {
	SmartDashboard::PutString("Align Robot", "Initialized");
	power = .5;
}

// Called repeatedly when this Command is scheduled to run
void AlignRobot::Execute() {
	SmartDashboard::PutString("Align Robot", "Running");
	mecanumDrive->Rotate(power); // Calls mecanumDrive to Rotate the necesseary degrees at set power

}

// Make this return true when this Command no longer needs to run execute()
bool AlignRobot::IsFinished() {
	double currentAngle = mecanumDrive->GetGyroAngle(); //Gathers the current angle from the gyro from the mecanum drive object
	return desiredAngle > currentAngle; //if the desired Angle is > than current angle
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
