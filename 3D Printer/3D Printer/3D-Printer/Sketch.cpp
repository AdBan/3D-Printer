#include "Arduino.h"
#include "Header files\StepperMotor.h"
#include "Header files\LimitSwitch.h"
#include "Header files\SerialDecoder.h"

int x = 0, y = 0, z = 0;
String readDataString;

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void setup()
{
	StepperInit();
	LimitSwitchPinInit();
	Serial.begin(57600);
	Serial.println("Connected.\nPodaj ilość kroków:");
}


///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void loop()
{
	bool limitSwitchX = digitalRead(pinLimitSwitchX);
	bool limitSwitchY = digitalRead(pinLimitSwitchY);
	bool limitSwitchZ = digitalRead(pinLimitSwitchZ);
	
	if (Serial.available())
	{
		readDataString = Serial.readString();
		Serial.println(readDataString);
		
		//convert string to char
		char readDataChar[readDataString.length()];
		readDataString.toCharArray(readDataChar, readDataString.length() + 1);
		

		RemoveSpaces(readDataChar);
		strlwr(readDataChar); //convert data to lowercase

		x = (int)GetNumberAfterCharacter(readDataChar, 'x');
		y = (int)GetNumberAfterCharacter(readDataChar, 'y');
		z = (int)GetNumberAfterCharacter(readDataChar, 'z');
		

		Serial.println(x);
		Serial.println(y);
		Serial.println(z);

		// Change steper direction
		if (x > 0)
		ChangeStepperXDir(false);
		else
		ChangeStepperXDir(true);
		if (y > 0)
		ChangeStepperYDir(false);
		else
		ChangeStepperYDir(true);
		if (z > 0)
		ChangeStepperZDir(false);
		else
		ChangeStepperZDir(true);
		
		// Abs of motor steps for MovementXYZ method
		x = abs(x);
		y = abs(y);
		z = abs(z);

		Serial.flush();
	}

	MovementXYZ(&x, &y, &z, limitSwitchX, limitSwitchY, limitSwitchZ);
}


