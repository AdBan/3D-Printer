/*
 * StepperMotor.cpp
 *
 * Created: 09.11.2017 10:10:16
 *  Author: Adam
 */ 

#include "Arduino.h"
#include "..\Header files\StepperMotor.h"

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void StepperInit()
{
	//direction pins
	pinMode(pinDirX, OUTPUT);
	pinMode(pinDirY, OUTPUT);
	pinMode(pinDirZ, OUTPUT);
	
	//enable pins
	pinMode(pinEnX, OUTPUT);
	pinMode(pinEnY, OUTPUT);
	pinMode(pinEnZ, OUTPUT);

	//chip select pins
	pinMode(pinCSX, OUTPUT);
	pinMode(pinCSY, OUTPUT);
	pinMode(pinCSZ, OUTPUT);
	
	//step pins
	pinMode(pinStepX, OUTPUT);
	pinMode(pinStepY, OUTPUT);
	pinMode(pinStepZ, OUTPUT);
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void ChangeStepperXDir(bool dirX)
{
	if (dirX)
		pinMode(pinDirX, HIGH);
	else 
		pinMode(pinDirX, LOW);
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void ChangeStepperYDir(bool dirY)
{
	if (dirY)
		pinMode(pinDirY, HIGH);
	else 
		pinMode(pinDirY, LOW);
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void ChangeStepperZDir(bool dirZ)
{
	if (dirZ)
		pinMode(pinDirZ, HIGH);
	else 
		pinMode(pinDirZ, LOW);
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void MovementXYZ(int *SteppsX, int *SteppsY, int *SteppsZ, bool switchX, bool switchY, bool switchZ)
{
	if (*SteppsX > 0 && !(switchX))
		digitalWrite(pinStepX, LOW);
	if (*SteppsY > 0 && !(switchY))
		digitalWrite(pinStepY, LOW);
	if (*SteppsZ > 0 && !(switchZ))
		digitalWrite(pinStepZ, LOW);
	
	delay(1);

	if (*SteppsX > 0 && !(switchX))
	{
		digitalWrite(pinStepX, HIGH);
		(*SteppsX)--;
	}
	if (*SteppsY > 0 && !(switchY))
	{
		digitalWrite(pinStepY, HIGH);
		(*SteppsY)--;
	}
	if (*SteppsZ > 0 && !(switchZ))
	{
		digitalWrite(pinStepZ, LOW);
		(*SteppsZ)--;
	}
	delay(1);
}