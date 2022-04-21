#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stream_sender_data.h"  

FileAccess ReadData, WriteData;
int buffSize=0, ReadingCount[]={};
int BatterySoC[]={};
float BatteryVoltage[]={};


/* Function to read the sensor readings from "SensorData.txt" file and store into a buffer */
   
FileAccess getSensorData()
{
  FILE *sensData_fp;
  int line=1; 
  ReadData=NOK;   	
  sensData_fp=fopen("./SenderData/SensorData.txt", "r");
  if (sensData_fp!=NULL)
  {
  int Count, ReadBatterySoC=0; 
  float ReadBatteryVoltage=0;
  //printf("File opened successfully\n"); 
  int Idx=0;
  while(line != EOF)
  {
  line=fscanf(sensData_fp,"%d %d %f",&Count, &ReadBatterySoC, &ReadBatteryVoltage);
  ReadingCount[Idx]=Count;     
  BatterySoC[Idx]=ReadBatterySoC;
  BatteryVoltage[Idx]=ReadBatteryVoltage;
  Idx++;
  }
  buffSize=Idx;
  ReadData= OK;
  }	
fclose(sensData_fp);
return ReadData;
}

/* This function reads the sensor readings of battery parameters from the buffer and writes them on to the Console window based on startTrasmissionReq*/
   
FileAccess displayReadingsOnConsole(DataStreamMode startTrasmissionReq)
{
WriteData=NOK;
  if (startTrasmissionReq)
  {
    //printf("ReadingsCount,BatterySoC in percentage,BatteryVoltage in volts\n");
    for(int i=0; i < buffSize-1; i++)
    {
    printf("%d,%d,%.2f\n", ReadingCount[i],BatterySoC[i],BatteryVoltage[i]);
    }
    WriteData= OK;
   }	
return WriteData;
}
