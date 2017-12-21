/*
 * StepperMotor.cpp
 *
 * Created: 09.11.2017 10:10:16
 *  Author: Adam
 */ 

#include "Arduino.h"
#include "..\Header files\Global.h"
#include "..\Header files\StepperMotor.h"
#include "..\Header files\LimitSwitch.h"

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void StepperInit()
{
	//Initialize limit switches
	LimitSwitchPinInit();

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
void ChangeSteppersDir(Steps *steps)
{
	if ((*steps).x > 0)
		ChangeStepperXDir(false);
	else
	{
		ChangeStepperXDir(true);
		(*steps).x = abs((*steps).x);
	}		
		
	if ((*steps).y > 0)
		ChangeStepperYDir(false);
	else
	{
		ChangeStepperYDir(true);
		(*steps).y = abs((*steps).y);
	}
	
	if ((*steps).z > 0)
		ChangeStepperZDir(false);
	else
	{
		ChangeStepperZDir(true);
		(*steps).z = abs((*steps).z);
	}
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void MovementXYZ(Steps *steps)
{
	bool switchX, switchY, switchZ;
	ReadLimitSwitch(&switchX, &switchY, &switchZ);

	if ((*steps).x > 0 && (!(switchX) || digitalRead(pinDirX)))
		digitalWrite(pinStepX, LOW);
	if ((*steps).y > 0 && (!(switchY) || digitalRead(pinDirY)))
		digitalWrite(pinStepY, LOW);
	if ((*steps).z > 0 && (!(switchZ) || digitalRead(pinDirZ)))
		digitalWrite(pinStepZ, LOW);
	delayMicroseconds((*steps).speed);

	if ((*steps).x > 0 && (!(switchX) || digitalRead(pinDirX)))
	{
		digitalWrite(pinStepX, HIGH);
		(*steps).x--;
	}
	if ((*steps).y > 0 && (!(switchY) || digitalRead(pinDirY)))
	{
		digitalWrite(pinStepY, HIGH);
		(*steps).y--;
	}
	if ((*steps).z > 0 && (!(switchZ) || digitalRead(pinDirZ)))
	{
		digitalWrite(pinStepZ, HIGH);
		(*steps).z--;
	}
	delayMicroseconds((*steps).speed);
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
int SetSpeed(int speed)
{
	if (speed < 0)
		speed = 0;
	else if (speed > 10)
		speed = 10;
	
	return (int)(1000 - map(speed, MINSPEED, MAXSPEED, 0, 999));
}