#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Stream_Receiver_data.h"
TEST_CASE("Test code")
{
  int samples=50, value =0;
value= DisplayReceivedData(samples);
}

TEST_CASE("Test code Parse")
{
  char buff[20]="96,12.80";
  CommaSeparatedData(buff,1);
}

TEST_CASE("Test code check for maximum and minimum")
{
  int samples=3, value =0;
  float expectedMaxVoltageValue=12.90,expectedMinVoltageValue=12.80;
  int expectedMaxSocValue=100,expectedMinSocValue=96;
  ReadDataFromConsole(BatterySoCRead,BatteryVoltageRead,samples);
  DisplayReceivedData(samples);
 MaxSocValue=MaxSoc(samples);
 MinSocValue=MinSoc(samples);
 MaxVoltageValue=MaxVoltage(samples);
 MinVoltageValue=MinVoltage(samples);
  printf("\nMaxSocValue:%d",MaxSocValue);
printf("\nMinSocValue:%d",MinSocValue);
printf("\nMaxVoltageValue:%f",MaxVoltageValue);
printf("\nMinVOltageValue:%f",MinVoltageValue);
 
 REQUIRE(MaxSocValue==expectedMaxSocValue);
  REQUIRE(MinSocValue==expectedMinSocValue);
  REQUIRE(MaxVoltageValue==expectedMaxVoltageValue);
  REQUIRE(MinVoltageValue==expectedMinVoltageValue);
}
