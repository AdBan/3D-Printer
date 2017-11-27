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
		digitalWrite(pinDirX, HIGH);	//down
	else 
		digitalWrite(pinDirX, LOW);		//up
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void ChangeStepperYDir(bool dirY)
{
	if (dirY)
		digitalWrite(pinDirY, HIGH);	//down
	else 
		digitalWrite(pinDirY, LOW);		//up
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void ChangeStepperZDir(bool dirZ)
{
	if (dirZ)
		digitalWrite(pinDirZ, HIGH);	//down
	else 
		digitalWrite(pinDirZ, LOW);		//up
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void MovementXYZ(int *StepsX, int *StepsY, int *StepsZ, bool switchX, bool switchY, bool switchZ)
{
	//going up
	if (*StepsX > 0 && !(switchX))
		digitalWrite(pinStepX, LOW);
	if (*StepsY > 0 && !(switchY))
		digitalWrite(pinStepY, LOW);
	if (*StepsZ > 0 && !(switchZ))
		digitalWrite(pinStepZ, LOW);
	delay(1);

	if (*StepsX > 0 && !(switchX))
	{
		digitalWrite(pinStepX, HIGH);
		(*StepsX)--;
	}
	if (*StepsY > 0 && !(switchY))
	{
		digitalWrite(pinStepY, HIGH);
		(*StepsY)--;
	}
	if (*StepsZ > 0 && !(switchZ))
	{
		digitalWrite(pinStepZ, HIGH);
		(*StepsZ)--;
	}
	delay(1);
}