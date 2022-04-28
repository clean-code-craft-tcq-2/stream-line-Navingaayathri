/*Receiver.h*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SENSOR_SAMPLES 50

void ReadDataFromConsole(int *ReadBatterySoC, float *ReadBatteryVoltage, int Size);
extern int DisplayReceivedData(int SampleToDisplay);
extern void CommaSeparatedData(char str[], int index);
extern int MaxSoc(int count);
extern int MinSoc(int count);
extern float MaxVoltage(int count);
extern float MinVoltage(int count);
extern float *MovingAverage(float *SMA,int count);
extern int BatterySoCRead[50];
extern float BatteryVoltageRead[50];
extern float SMA[2];
extern int MaxSocValue,MinSocValue;
extern float MaxVoltageValue,MinVoltageValue;
