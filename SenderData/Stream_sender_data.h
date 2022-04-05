#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SENSOR_READINGS 100  

typedef enum {
  OK,
  NOK
} FileAccess;

typedef enum {
  StopTransmit,
  Transmitdata
} DataStreamMode;

extern int buffSize;
extern FileAccess getSensorData();
extern FileAccess displayReadingsOnConsole(DataStreamMode startTrasmissionReq);
extern int BatterySoC[MAX_SENSOR_READINGS]; //buffer to store BMS SoC value
extern float BatteryVoltage[MAX_SENSOR_READINGS];  //buffer to store BMS Voltage value
