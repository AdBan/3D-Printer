#include "Arduino.h"
#include "Header files\Global.h"
#include "Header files\StepperMotor.h"
#include "Header files\SerialDecoder.h"

Steps steps = {0, 0, 0, 0};
String readBuffer;
bool flagaok = false;


///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void setup()
{
	StepperInit();
	Serial.begin(57600);
	// Serial.println("Connected.");
}


///CREDIT: Adam Baniuszewicz, Bartosz Flis, Jakub Sybidlo
void loop()
{	
	while (Serial.available())
	{
		flagaok = false;
		steps = DecodeFrame(Serial.readStringUntil('\n'));

		ChangeSteppersDir(&steps);
	}

	MovementXYZ(&steps);
	if (steps.x == 0 && steps.y == 0 && steps.z == 0 && flagaok == false)
	{
		Serial.println("q");
		flagaok = true;
	}
}

	//while (Serial.available())
	//{
		//buffer[i] = Serial.read();
		//if ( buffer[i] == '\n')
		//{
			//i = 0;
			//String readBuffer(buffer);
			//steps = DecodeFrame(readBuffer);
			//memset(buffer, 0, sizeof(buffer));
		//}
		//else
		//{
			//i++;
		//}
//
	//}
//
	//ChangeSteppersDir(&steps);
	//MovementXYZ(&steps);

