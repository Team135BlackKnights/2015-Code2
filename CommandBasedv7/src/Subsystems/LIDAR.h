#ifndef LIDAR_H
#define LIDAR_H

#include "Commands/Subsystem.h"
#include "WPILib.h"


#include <I2C.h>

class LIDAR: public Subsystem
{
private:
	const int LIDAR_ADDR = 0x62;
	const int LIDAR_CONFIG_REGISTER = 0x00;
	const int LIDAR_DISTANCE_REGISTER = 0x8f;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	//unsigned char LIDARLite_ADDRESS = 0x62;
	I2C *I2CPort;
	//SerialPort *serialPort;
	unsigned char *distance;
	DigitalOutput* powerEnable;
	std::string debugOutputKey;
public:
	LIDAR(int port);
	void InitDefaultCommand();
	void Write();
	void Read();
	int GetData();
	//int ReadDistance();
	int GetDistance();
	void WriteToLights(const char*, int32_t);
	void SetPowerEnable(bool enable);
};

#endif
/*
http://pulsedlight3d.com
This sketch demonstrates getting distance with the LIDAR-Lite Sensor
It utilizes the 'Arduino I2C Master Library' from DSS Circuits:
http://www.dsscircuits.com/index.php/articles/66-arduino-i2c-master-library
You can find more information about installing libraries here:
http://arduino.cc/en/Guide/Libraries

#include <I2C.h>
#define    LIDARLite_ADDRESS   0x62          // Default I2C Address of LIDAR-Lite.
#define    RegisterMeasure     0x00          // Register to write to initiate ranging.
#define    MeasureValue        0x04          // Value to initiate ranging.
#define    RegisterHighLowB    0x8f          // Register to get both High and Low bytes in 1 call.


void setup(){
  Serial.begin(9600); //Opens serial connection at 9600bps.
  I2c.begin(); // Opens & joins the irc bus as master
  delay(100); // Waits to make sure everything is powered up before sending or receiving data
  I2c.timeOut(50); // Sets a timeout to ensure no locking up of sketch if I2C communication fails
}

void loop(){
  // Write 0x04 to register 0x00
  uint8_t nackack = 100; // Setup variable to hold ACK/NACK resopnses
  while (nackack != 0){ // While NACK keep going (i.e. continue polling until sucess message (ACK) is received )
    nackack = I2c.write(LIDARLite_ADDRESS,RegisterMeasure, MeasureValue); // Write 0x04 to 0x00
    delay(1); // Wait 1 ms to prevent overpolling
  }

  byte distanceArray[2]; // array to store distance bytes from read function

  // Read 2byte distance from register 0x8f
  nackack = 100; // Setup variable to hold ACK/NACK resopnses
  while (nackack != 0){ // While NACK keep going (i.e. continue polling until sucess message (ACK) is received )
    nackack = I2c.read(LIDARLite_ADDRESS,RegisterHighLowB, 2, distanceArray); // Read 2 Bytes from LIDAR-Lite Address and store in array
    delay(1); // Wait 1 ms to prevent overpolling
  }
  int distance = (distanceArray[0] << 8) + distanceArray[1];  // Shift high byte [0] 8 to the left and add low byte [1] to create 16-bit int

  // Print Distance
  Serial.println(distance);
}

Status API Training Shop Blog About
� 2015 GitHub, Inc. Terms Privacy Security Contact
 */
