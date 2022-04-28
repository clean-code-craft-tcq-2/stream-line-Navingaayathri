/*Receiver*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "Stream_Receiver_data.h"

int BatterySoCRead[] = { };
float BatteryVoltageRead[] = { };
int MaxSocValue, MinSocValue=0;
float MaxVoltageValue,MinVoltageValue=0;


void
ReadDataFromConsole (int *SoCRead, float *VoltageRead, int Size)
{
  char ReadString[500];
  char *pt;
  for (int i = 0; i <Size ; i++)
    {
      scanf ("%[^,]", ReadString);	//1
      scanf ("%50s", ReadString);
        CommaSeparatedData(ReadString,i);
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
int MaxSoc(int count)
{
        int soc=BatterySoCRead[0];
        for(int i=0;i<count;i++)
        {
                if(BatterySoCRead[i]>soc)
                {
                        soc=BatterySoCRead[i];
                }
        }
        return soc;
        
}

int MinSoc(int count)
{
        int soc=BatterySoCRead[0];
        for(int i=0;i<count;i++)
        {
                if(BatterySoCRead[i]<soc)
                {
                        soc=BatterySoCRead[i];
                }
        }
        return soc;
        
}
float MaxVoltage(int count)
{
        float VoltageMax=BatteryVoltageRead[0];
        for(int i=0;i<count;i++)
        {
                if(BatteryVoltageRead[i]>VoltageMax)
                {
                        VoltageMax=BatteryVoltageRead[i];
                }
        }
        return VoltageMax;
        
}

float MinVoltage(int count)
{
        float VoltageMin=BatteryVoltageRead[0];
        for(int i=0;i<count;i++)
        {
                if(BatteryVoltageRead[i]<VoltageMin)
                {
                        VoltageMin=BatteryVoltageRead[i];
                }
        }
        return VoltageMin;
        
}
float *MovingAverage (float *SMA, int count)
{
  float sumSoC,sumVoltage=0;
  for (int i = (count - 5); i < (count); i++)
    {
         //   printf("\nvoltage[%d]:%f,Soc[%d]:%d",i,BatteryVoltageRead[i],i,BatterySoCRead[i]);
      sumSoC += BatterySoCRead[i];
      sumVoltage += BatteryVoltageRead[i];
    }
  SMA[0] = sumSoC/5;
  SMA[1] = sumVoltage/5;
  return SMA;
}
