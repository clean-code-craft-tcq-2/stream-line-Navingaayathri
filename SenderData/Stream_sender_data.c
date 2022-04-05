#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Stream_sender_data.h"
  

FileAccess ReadData, WriteData;
int buffSize=0;
int BatterySoC[]={};
float BatteryVoltage[]={};


/* Function to read the sensor readings from "SensorData.csv" file and store into a buffer */
   
FileAccess getSensorData()
{
  FILE *sensData_fp;
  ReadData=NOK;
  int line=1;  	
  sensData_fp=fopen("./SenderData/SensorData.txt", "r");
  	if (sensData_fp==NULL)	{
		printf("Unable to open the file\n");
		
	}	
	else
	{
		int Idx=0, ReadBatterySoC=0; 
		float ReadBatteryVoltage=0.0;
		printf("File opened successfully\n");
		while(line != EOF)
		{
			line=fscanf(sensData_fp,"%d %f",&ReadBatterySoC,&ReadBatteryVoltage);
			BatterySoC[Idx]=ReadBatterySoC;
			BatteryVoltage[Idx]=ReadBatteryVoltage;
			Idx++;
		}
		buffSize=Idx;
		ReadData= OK;
	}
	
	fclose(sensData_fp);
	return OK;
}

/* This function reads the sensor readings of battery parameters from the buffer and writes them on to the Console window based on startTrasmissionReq*/
   
FileAccess displayReadingsOnConsole(DataStreamMode startTrasmissionReq)
{
	WriteData=NOK;
	if (startTrasmissionReq)
	{
		printf("BatterySoC in percentage \t\t BatteryVoltage in volts)\n");
		for(int i=0; i < buffSize; i++)
		{
			printf("%d \t\t %.2f\n", BatterySoC[i],BatteryVoltage[i]);
		}
		WriteData= OK;
	}	
	return WriteData;
}
