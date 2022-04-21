/*Receiver.h*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void ReadDataFromConsole(int *ReadBatterySoC, float *ReadBatteryVoltage, int Size);
extern int DisplayReceivedData();
extern void CommaSeparatedData(char str[], int index);
extern int BatterySoCRead[50];
extern float BatteryVoltageRead[50];
