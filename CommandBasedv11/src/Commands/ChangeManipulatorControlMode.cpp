#include "ChangeManipulatorControlMode.h"

ChangeManipulatorControlMode::ChangeManipulatorControlMode(bool mode) {this->mode = mode;}

void ChangeManipulatorControlMode::Initialize() {oi->SetManipulatorControlMode(mode);}

bool ChangeManipulatorControlMode::IsFinished() {return true;}

void ChangeManipulatorControlMode::Execute() {};

void ChangeManipulatorControlMode::End() {};

void ChangeManipulatorControlMode::Interrupted() {};
