/*Receiver*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Stream_Receiver_data.h"

int BatterySoCRead[] = { };
float BatteryVoltageRead[] = { };

void
ReadDataFromConsole (int *SoCRead, float *VoltageRead, int Size)
{
  char ReadString[500];
  char *pt;
  for (int i = 0; i <Size ; i++)
    {
      scanf ("%[^,]", ReadString);	//1
      scanf ("%50s", ReadString);
   //     CommaSeparatedData(ReadString,i);
    }
}
void CommaSeparatedData(char str[], int index)
{
        char *pt;
        pt = strtok (str, ",");
	  BatterySoCRead[index] = atoi (pt);
//	  printf ("\nBatterySoCRead[%d]: %d", index,BatterySoCRead[index]);
	  pt = strtok (NULL, ",");
	  BatteryVoltageRead[index]= atof(pt);
//	  printf("\nBatteryVoltageRead[%d]: %f", index,BatteryVoltageRead[index]);
}
int
DisplayReceivedData (int SampleToDisplay)
{
        int result =0;
  printf ("\n Displaying the received Data from Console\n");
  for (int i = 0; i < SampleToDisplay; i++)
    {
      printf ("SoC:%d\tVoltage: %.2f\n", BatterySoCRead[i],
	      BatteryVoltageRead[i]);
	      result = 1;
    }
    return result;
}

