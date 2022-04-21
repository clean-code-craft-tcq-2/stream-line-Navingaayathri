#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Stream_Receiver_data.h"
TEST_CASE("Test code")
{
  int samples=50, value =0;
value= DisplayReceivedData(samples);
}

TEST_CASE("Test code Read from Console")
{
  int samples=50, value =0;
ReadDataFromConsole(BatterySoCRead,BatteryVoltageRead,samples);
}
