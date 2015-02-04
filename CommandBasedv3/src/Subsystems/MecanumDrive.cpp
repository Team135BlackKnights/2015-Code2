#include "MecanumDrive.h"
#include "../RobotMap.h"
#include "../Commands/DriveJ.h"

MecanumDrive::MecanumDrive() :
	Subsystem("MecanumDrive")
{
		for (int i = 0; i < 4; i++)
		{
			motorTalons[i] = new Talon(i);
		}
		//motorSRX = new TalonSRX(10);
		motorCan = new CANTalon(10);

		chassis = new RobotDrive(MOTOR_FRONT_LEFT, MOTOR_REAR_LEFT, MOTOR_FRONT_RIGHT, MOTOR_REAR_RIGHT);//motorTalons[MOTOR_FRONT_LEFT], motorTalons[MOTOR_REAR_LEFT], motorTalons[MOTOR_FRONT_RIGHT], motorTalons[MOTOR_REAR_RIGHT]);
		driveMode = this->SRX_SRY_SRZ;
		chassis->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
		chassis->SetInvertedMotor(RobotDrive::kRearRightMotor, true);
		gyroAngle = 0;
		compressor = new Compressor(0);
}

void MecanumDrive::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new DriveJ());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void MecanumDrive::DriveJoysticks(float x, float y, float z)
{
	chassis->MecanumDrive_Cartesian(x, y, z, gyroAngle);
	//motorCan->Set(y);

}

int MecanumDrive::GetDriveMode()
{
	return driveMode;
}

int MecanumDrive::SetDriveMode(int mode)
{
	return driveMode = mode;
}


double MecanumDrive::GetGyroAngle()
{
	return gyroAngle;
}

double MecanumDrive::SetGyroAngle(double angle)
{
	SmartDashboard::PutNumber("MecanumDrive Gyro Angle", angle);
	return gyroAngle = angle;
}

void MecanumDrive::Rotate(float power)
{
	chassis->MecanumDrive_Cartesian(0, 0, power);
}
