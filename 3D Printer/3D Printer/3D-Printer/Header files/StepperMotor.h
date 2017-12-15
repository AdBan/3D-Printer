/*
 * StepperMotor.h
 *
 * Created: 09.11.2017 10:04:36
 *  Author: Adam
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_
#include "Arduino.h"
#include "..\Header files\SerialDecoder.h"

#define pinStepX         54
#define pinDirX          55
#define pinEnX           38
#define pinCSX           53

#define pinStepY         60
#define pinDirY          61
#define pinEnY           56
#define pinCSY           49

#define pinStepZ         46
#define pinDirZ          48
#define pinEnZ           62
#define pinCSZ           40

#define G00SPEED 9
#define G01SPEED 4
#define DEFAULTSPEED 6
#define MAXSPEED 10
#define MINSPEED 0


void StepperInit();
void ChangeStepperXDir(bool dirX);
void ChangeStepperYDir(bool dirY);
void ChangeStepperZDir(bool dirZ);
void ReadLimitSwitch();
void ChangeSteppersDir(Steps *steps);
void MovementXYZ(Steps *steps);

int SetSpeed(int speed);
#endif /* STEPPERMOTOR_H_ */