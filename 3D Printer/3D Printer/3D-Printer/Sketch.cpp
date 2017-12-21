#include "Arduino.h"
#include "Header files\Global.h"
#include "Header files\StepperMotor.h"
#include "Header files\SerialDecoder.h"

Steps steps = {0, 0, 0, SetSpeed((int)DEFAULTSPEED)};
bool okFlag = true;


///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void setup()
{
	StepperInit();
	Serial.begin(57600);
	//Serial.println("Connected.");
}


///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void loop()
{	
	while (Serial.available() && okFlag == true)
	{
		okFlag = false;
		DecodeFrame(Serial.readStringUntil('\n'), &steps);
		ChangeSteppersDir(&steps);
	}

	if (steps.x == 0 && steps.y == 0 && steps.z == 0 && okFlag == false)
	{
		okFlag = true;
		Serial.println("q");	//ask MATLAB for another frame
	}
	
	MovementXYZ(&steps);
}
