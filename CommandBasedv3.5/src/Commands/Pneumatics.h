/*
 * Pneumatics.h
 *
 *  Created on: Feb 1, 2015
 *      Author: robotics
 */

#ifndef SRC_COMMANDS_PNEUMATICS_H_
#define SRC_COMMANDS_PNEUMATICS_H_


/*
 * PneumaticAirCompressor.h
 *
 *  Created on: Feb 1, 2015
 *      Author: robotics
 */


#include "../CommandBase.h"
#include "WPILib.h"

class Pneumatics: public CommandBase
{
public:
	Pneumatics();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif /* SRC_COMMANDS_PNEUMATICS_H_ */
