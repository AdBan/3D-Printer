#include "Arduino.h"
#include "Header files\StepperMotor.h"
#include "Header files\LimitSwitch.h"

void setup()
{
	StepperInit();
	LimitSwitchPinInit();
	Serial.begin(57600);
	Serial.println("Connected");
}

void loop()
{
	String readData, readDataX, readDataY, readDataZ;
	int x, y, z;
	int xSteps = 0, ySteps = 0, zSteps = 0;

	bool limitSwitchX = digitalRead(pinLimitSwitchX);
	bool limitSwitchY = digitalRead(pinLimitSwitchY);
	bool limitSwitchZ = digitalRead(pinLimitSwitchZ);
	
	if (Serial.available())
	{
		Serial.println("Podaj ilosc krokow x y z: ");
		readData = Serial.readString();
		
		int i = 0;
		while(readData[i] != '\0')
		{
			if (readData[i] == ' ')
			readData.remove(i);
			i++;
		}

		int j = 0;
		while(readData[j] != '\0')
		{
			if(readData[j] == 'X')
			{
				while(readData[j] != 'Y' || readData[j] != 'Z' || readData[j] != '\0' )
				{
					readDataX += readData[j+1];
					j++;
				}
			}
			if(readData[j] == 'X')
			{
				while(readData[j] != 'X' || readData[j] != 'Z' || readData[j] != '\0' )
				{
					readDataY += readData[j+1];
					j++;
				}
			}
			if(readData[j] == 'Z')
			{
				while(readData[j] != 'X' || readData[j] != 'Y' || readData[j] != '\0' )
				{
					readDataZ += readData[j+1];
					j++;
				}
			}
			j++;
		}

		x = readDataX.toInt();
		y = readDataY.toInt();
		z = readDataZ.toInt();
	}
	MovementXYZ(&xStepps, &yStepps, &zStepps,
	limitSwitchX, limitSwitchY, limitSwitchZ);
}


