/*
 * SerialDecoder.cpp
 *
 * Created: 12.11.2017 00:24:17
 *  Author: Adam
 */ 

#include "..\Header files\SerialDecoder.h"
#include "stdlib.h"
#include "Arduino.h"

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