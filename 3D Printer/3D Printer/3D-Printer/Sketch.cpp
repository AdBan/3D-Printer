#include "Arduino.h"
#include "Header files\Global.h"
#include "Header files\StepperMotor.h"
#include "Header files\SerialDecoder.h"

Steps steps = {0,0,0};

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
	while (Serial.available())
	{
		steps = DecodeFrame(Serial.readString());
		Serial.println(steps.x);
		Serial.println(steps.y);
		Serial.println(steps.z);

		ChangeSteppersDir(&steps);
	}

	MovementXYZ(&steps);
}


