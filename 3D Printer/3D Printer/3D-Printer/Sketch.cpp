#include "Arduino.h"
#include "Header files\StepperMotor.h"
#include "Header files\LimitSwitch.h"
#include "Header files\SerialDecoder.h"

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void setup()
{
	StepperInit();
	LimitSwitchPinInit();
	Serial.begin(57600);
	Serial.println("Connected");
}

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void loop()
{
	String readData;

	bool limitSwitchX = digitalRead(pinLimitSwitchX);
	bool limitSwitchY = digitalRead(pinLimitSwitchY);
	bool limitSwitchZ = digitalRead(pinLimitSwitchZ);
	
	if (Serial.available())
	{
		Serial.println("Podaj ilosc krokow:");
		String readDataString = Serial.readString();
		
		//convert string to char
		char readDataChar[readDataString.length()];
		readDataString.toCharArray(readDataChar, readDataString.length());
		
		RemoveSpaces(readDataChar);
		strlwr(readDataChar); //convert data to lowercase

		int x = (int)GetNumberAfterCharacter(readDataChar, 'x');
		int y = (int)GetNumberAfterCharacter(readDataChar, 'y');
		int z = (int)GetNumberAfterCharacter(readDataChar, 'z');
		
		MovementXYZ(&x, &y, &z, limitSwitchX, limitSwitchY, limitSwitchZ);
	}
}


