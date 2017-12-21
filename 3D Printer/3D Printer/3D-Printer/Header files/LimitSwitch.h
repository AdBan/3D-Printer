/*
 * LimitSwitch.h
 *
 * Created: 09.11.2017 10:07:45
 *  Author: Adam
 */ 


#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_
#include "Arduino.h"

#define pinLimitSwitchX  2
#define pinLimitSwitchY  15
#define pinLimitSwitchZ  19

void LimitSwitchPinInit();
void ReadLimitSwitch(bool *limitSwitchX, bool *limitSwitchY, bool *limitSwitchZ);


#endif /* LIMITSWITCH_H_ */