#include <iostream>
#include <QApplication>
#include "header.h"

#include "TestOutstation.h"

#include "OutstationConfig.h"
#include "OutstationTestObject.h"
#include "DatabaseHelpers.h"

void NewTestStaticRead(std::string& request, std::string& response)
{
////    OutstationConfig config;
////    OutstationTestObject t(config, configure::by_count_of::all_types(1));
////    t.LowerLayerUp();

////    t.SendToOutstation(request);
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//    DatabaseConfig tmp;
//    DatabaseConfig_in_DatabaseConfig(&tmp, 0);
    DatabaseConfig tmp = all_types_in_DatabaseHelpers(1);

    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

    LowerLayerUp_in_OutstationTestObject(&t);

    SendToOutstation_in_OutstationTestObject(&t, request);  

    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

////    REQUIRE(t.lower->PopWriteAsHex() == response);
std::cout<<"REQUIRE(t.lower->PopWriteAsHex() == response)"<<'\n';
std::cout << "response= " << response<<'\n';
std::cout << "temp= " << temp<<'\n';

}
