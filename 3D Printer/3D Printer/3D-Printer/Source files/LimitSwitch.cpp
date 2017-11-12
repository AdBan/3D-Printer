/*
 * LimitSwitch.cpp
 *
 * Created: 09.11.2017 10:10:07
 *  Author: Adam
 */ 

#include "Arduino.h"
#include "..\Header Files\LimitSwitch.h"

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void LimitSwitchPinInit()
{
	pinMode(pinLimitSwitchX, INPUT);
	pinMode(pinLimitSwitchY, INPUT);
	pinMode(pinLimitSwitchZ, INPUT);
	digitalWrite(pinLimitSwitchX, HIGH);
	digitalWrite(pinLimitSwitchY, HIGH);
	digitalWrite(pinLimitSwitchZ, HIGH);
}
