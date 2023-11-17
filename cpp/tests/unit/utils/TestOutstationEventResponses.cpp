#include "TestOutstationEventResponses.h"

void TestEventRead(std::string& request,
                   std::string& response,
                   ////const std::function<void(IUpdateHandler& db)>& loadFun,
                   void (*loadFun)(IUpdateHandler* db),
                   ////const std::function<void(DatabaseConfig& db)>& configure = [](DatabaseConfig& view) {})
                   void (*configure)(DatabaseConfig* view))
{

////    OutstationConfig config;
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//    DatabaseConfig tmp;
//    DatabaseConfig_in_DatabaseConfig(&tmp, 0);
////    config.eventBufferConfig = EventBufferConfig::AllTypes(10);
   EventBufferConfig etemp = AllTypes_in_EventBufferConfig_static(MAX_EventRecord);
   config.eventBufferConfig = etemp;

////    DatabaseConfig database = configure::by_count_of::all_types(5);
  DatabaseConfig database = all_types_in_DatabaseHelpers(5);

////    configure(database);
  configure(&database);

////    OutstationTestObject t(config, std::move(database));
    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &database);

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

////    t.Transaction([&](IUpdateHandler& db) { loadFun(db); });
    Transaction_in_OutstationTestObject(&t, loadFun);//void (*apply)(IUpdateHandler*));

////    t.SendToOutstation(request);
    SendToOutstation_in_OutstationTestObject(&t, request);  

////    REQUIRE(t.lower->PopWriteAsHex() == response);
    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
    std::cout << "temp= " << temp<<'\n';
    std::cout << "response= " << response<<'\n';
}
