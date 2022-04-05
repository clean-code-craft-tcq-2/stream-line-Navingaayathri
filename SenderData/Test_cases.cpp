#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-framework/catch.hpp"
#include "Stream_sender_data.h"

TEST_CASE("To check if file is successfully opened for read data access") 
{
 FILE *sensData_fp!=NULL;	
 REQUIRE(getSensorData()== OK); 
}

TEST_CASE("To check for unsuccessful attempt of opening the input file for read data access") 
{ 
 FILE *sensData_fp==NULL;
 REQUIRE(getSensorData()== NOK); 
}

TEST_CASE("To check the data read from the file is displayed on the console") 
{
  DataStreamMode startTrasmissionReq=Transmitdata;
  REQUIRE(displayReadingsOnConsole(startTrasmissionReq)== OK);
}
