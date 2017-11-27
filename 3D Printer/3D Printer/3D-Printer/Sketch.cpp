#include "Arduino.h"
#include "Header files\StepperMotor.h"
#include "Header files\SerialDecoder.h"

Steps steps;
String readDataString;

///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void setup()
{
	StepperInit();
	Serial.begin(57600);
	Serial.println("Connected.");
}


///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void loop()
{	
	Serial.println("lololol");
	if (Serial.available())
	{
		steps = DecodeFrame(Serial.readString());

		Serial.println(steps.x);
		Serial.println(steps.y);
		Serial.println(steps.z);

		ChangeSteppersDir(&steps);
	}

	MovementXYZ(&steps);
}


