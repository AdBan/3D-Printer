/*
 * SerialDecoder.cpp
 *
 * Created: 12.11.2017 00:24:17
 *  Author: Adam
 */ 

#include "Arduino.h"
#include "..\Header files\Global.h"
#include "..\Header files\SerialDecoder.h"
#include "..\Header files\StepperMotor.h"
#include "stdlib.h"


///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void RemoveSpaces(char* source)
{
	char* i = source;
	char* j = source;

	while(*j != '\0')
	{
		*i = *j++;
		if(*i != ' ')
		i++;
	}
	*i = 0;
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
double GetNumberAfterCharacter(char* source, char character)
{
	while (*source != '\0')
	{
		if (*source++ == character)
		{
			//extract all digits after desired character
			return strtod(source, NULL);
		}
	}
	return 0; //returning '0' won't cause any movement
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void DecodeFrame(String frame, Steps *steps)
{
	//convert string to char
	char readDataChar[frame.length() + 1];
	frame.toCharArray(readDataChar, frame.length() + 1);
			
	RemoveSpaces(readDataChar);
	strlwr(readDataChar); //convert data to lowercase

	switch (GetCode(readDataChar))
	{
		case 0:		//G00
			(*steps).speed = SetSpeed((int)G00SPEED);
			break;
		case 1:		//G01
			(*steps).speed = SetSpeed((int)G01SPEED);
			break;
		case 99:	//F
			(*steps).speed = SetSpeed((int)GetNumberAfterCharacter(readDataChar, 'f'));
			return;
		default:
			break;
	}
	(*steps).x = (int)GetNumberAfterCharacter(readDataChar, 'x');
	(*steps).y = (int)GetNumberAfterCharacter(readDataChar, 'y');
	(*steps).z = (int)GetNumberAfterCharacter(readDataChar, 'z');
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
int GetCode(char* readBuffer)
{
	if (readBuffer[0] == 'g' && readBuffer[1] == '0' && readBuffer[2] == '0')
		return 0;
	if (readBuffer[0] == 'g' && readBuffer[1] == '0' && readBuffer[2] == '1')
		return 1;
	if (readBuffer[0] == 'f')
		return 99;
	
	return -1;	 
}