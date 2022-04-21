#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Stream_Receiver_data.h"
TEST_CASE("Test code")
{
  int samples=50, value =0;
value= DisplayReceivedData(samples);
}

TEST_CASE("Test code Read 3 samples from Console")
{
  int samples=3, value =0;
  printf("1,100,12.90\n");
  ReadDataFromConsole(BatterySoCRead,BatteryVoltageRead,samples);
  DisplayReceivedData(samples);
}

TEST_CASE("Test code Parse")
{
  char buff[20]="96,12.80";
  CommaSeparatedData(buff,1);
}
