#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Stream_sender_data.h"

TEST_CASE("To check if file is successfully opened for read data access") 
{
 FILE *sensData_fp=fopen("./SenderData/SensorData.txt", "r"); 
 REQUIRE_NOTHROW(getSensorData()== OK); 
}

TEST_CASE("To check the data read from the file is displayed on the console") 
{
  DataStreamMode startTrasmissionReq=Transmitdata;
  REQUIRE(displayReadingsOnConsole(startTrasmissionReq)== OK);
}

TEST_CASE("To stop transmitting the data to be displayed on the console") 
{
  DataStreamMode startTrasmissionReq=StopTransmit;
  REQUIRE(displayReadingsOnConsole(startTrasmissionReq)== NOK);
}
