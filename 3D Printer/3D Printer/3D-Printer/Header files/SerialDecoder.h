/*
 * SerialDecoder.h
 *
 * Created: 12.11.2017 00:06:33
 *  Author: Adam
 */ 


#ifndef SERIALDECODER_H_
#define SERIALDECODER_H_

void RemoveSpaces(char* source);
double GetNumberAfterCharacter(char* source, char character);
void DecodeFrame(String frame, Steps *steps);

int GetCode(char* readDataBuffer);
#endif /* SERIALDECODER_H_ */