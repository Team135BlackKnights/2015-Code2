#include "LeftyModeJustForRiley.h"

LeftyModeJustForRiley::LeftyModeJustForRiley(bool mode) {this->mode = mode;}

void LeftyModeJustForRiley::Initialize() {oi->LeftyFlip(mode);}

void LeftyModeJustForRiley::Execute() {}

bool LeftyModeJustForRiley::IsFinished() {return true;}

void LeftyModeJustForRiley::End() {}

void LeftyModeJustForRiley::Interrupted() {}
