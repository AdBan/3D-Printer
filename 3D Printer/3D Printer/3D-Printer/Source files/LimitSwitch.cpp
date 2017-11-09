/*
 * LimitSwitch.cpp
 *
 * Created: 09.11.2017 10:10:07
 *  Author: Adam
 */ 

#include "Arduino.h"
#include "..\Header Files\LimitSwitch.h"

void LimitSwitchPinInit()
{
	pinMode(pinLimitSwitchX, INPUT);
	pinMode(pinLimitSwitchY, INPUT);
	pinMode(pinLimitSwitchZ, INPUT);
	digitalWrite(pinLimitSwitchX, HIGH);
	digitalWrite(pinLimitSwitchY, HIGH);
	digitalWrite(pinLimitSwitchZ, HIGH);
}
