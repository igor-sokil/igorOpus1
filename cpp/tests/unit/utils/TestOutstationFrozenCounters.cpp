#include "TestOutstationFrozenCounters.h"

// "Go back to your oar, Forty-One."
//   - Quintus Arrius
//// int counterValue = 41;
//// std::string counterValueHex = "29";

// "Elvis has left the building!"
////const DNPTime freezeTimestamp(240607800000, TimestampQuality::SYNCHRONIZED);
//// std::string freezeTimestampHex = "C0 AA 57 05 38 00";

void loadFun_in_TestFreezeOperation1(IUpdateHandler*);
void loadFun_in_TestFreezeOperation1(IUpdateHandler* db)
{
//boolean Modify_in_IUpdateHandler(IUpdateHandler*, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags);// = 0;
////    t.Transaction([](IUpdateHandler& db) {
////        db.Modify(FlagsType::Counter, 0, 0, 0x01);
////        db.Modify(FlagsType::FrozenCounter, 0, 0, 0x01);
////    });
 Modify_in_IUpdateHandler(db, FlagsType_Counter, 0, 0, 0x01);
 Modify_in_IUpdateHandler(db, FlagsType_FrozenCounter, 0, 0, 0x01);
}

void loadFun_in_TestFreezeOperation2(IUpdateHandler*);
void loadFun_in_TestFreezeOperation2(IUpdateHandler* db)
{
//void Counter_in_CounterOver2(Counter *pCounter, uint32_t value);
//// int counterValue = 41;
////    t.Transaction([=](IUpdateHandler& db) { db.Update(Counter(counterValue), 0); });
  Counter cCounter;
  Counter_in_CounterOver2(&cCounter, 41);
  Update_Counter_in_IUpdateHandler(db, &cCounter, 0, EventMode_Detect);// = EventMode::Detect) = 0;
}

////void TestFreezeOperation(std::string func, std::function<std::string(uint8_t)> freezeResponse, bool clear)
void TestFreezeOperation(std::string func, 
                        ////std::function<std::string(uint8_t)> freezeResponse,
                         std::string (*freezeResponse)(uint8_t v),
                         boolean clear)
{
////    OutstationConfig config;
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

//DatabaseConfig counter_in_DatabaseHelpers(uint16_t num, boolean with_frozen);// = false);
////    auto database = configure::by_count_of::counter(1, true);
    DatabaseConfig database = counter_in_DatabaseHelpers(1, true);

////    database.frozen_counter[0].svariation = StaticFrozenCounterVariation::Group21Var5;
    database.frozen_counter[0].dDeadbandConfig_for_FrozenCounterInfo.eEventConfig.svariation = StaticFrozenCounterVariation_Group21Var5;

////    OutstationTestObject t(config, database);
    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &database);

////    t.Transaction([](IUpdateHandler& db) {
////        db.Modify(FlagsType::Counter, 0, 0, 0x01);
////        db.Modify(FlagsType::FrozenCounter, 0, 0, 0x01);
////    });

////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

    Transaction_in_OutstationTestObject(&t, loadFun_in_TestFreezeOperation1);//void (*apply)(IUpdateHandler*));

    // Freeze all counters
////    t.SendToOutstation("C0 " + func + " 14 00 06");
    std::string request = "C0 " + func + " 14 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request);  

////    REQUIRE(t.lower->PopWriteAsHex() == freezeResponse(0));
    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
    std::cout << "request= " << request<<'\n';
    std::cout << "response= " << freezeResponse(0)<<'\n';
    std::cout << "temp= " << temp<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // Read all frozen counters
////    t.SendToOutstation("C1 01 15 00 06");
    std::string request2 = "C1 01 15 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request2);  

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C1 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00"); // Frozen value at 0
    std::string temp2 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
    std::cout << "request2= " << request2<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex()== 'C1 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00'"<<'\n';
    std::cout << "temp2= " << temp2<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // Update the counters
////    t.Transaction([=](IUpdateHandler& db) { db.Update(Counter(counterValue), 0); });
    Transaction_in_OutstationTestObject(&t, loadFun_in_TestFreezeOperation2);//void (*apply)(IUpdateHandler*));

    // Read all frozen counters
////    t.SendToOutstation("C2 01 15 00 06");
    std::string request3 = "C2 01 15 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request3);  

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C2 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00"); // Frozen value still at 0
    std::string temp3 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
    std::cout << "request3= " << request3<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex()== 'C2 81 80 00 15 05 00 00 00 01 00 00 00 00 00 00 00 00 00 00'"<<'\n';
    std::cout << "temp3= " << temp3<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // Change time of application
////const DNPTime freezeTimestamp(240607800000, TimestampQuality::SYNCHRONIZED);
        DNPTime freezeTimestamp;
        DNPTime_in_DNPTimeOver3(&freezeTimestamp, 240607800000, TimestampQuality_SYNCHRONIZED);
//void SetTime_in_MockOutstationApplication(MockOutstationApplication *pMockOutstationApplication, DNPTime timeDNPTime);
////    t.application->SetTime(freezeTimestamp);
        SetTime_in_MockOutstationApplication(&(t.application), freezeTimestamp);

    // Freeze all counters
////    t.SendToOutstation("C3 " + func + " 14 00 06");
    std::string request4 = "C3 " + func + " 14 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request);  

////    REQUIRE(t.lower->PopWriteAsHex() == freezeResponse(3));
    std::string temp4 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
    std::cout << "request4= " << request4<<'\n';
    std::cout << "response= " << freezeResponse(3)<<'\n';
    std::cout << "temp4= " << temp4<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    // Read all frozen counters
////    t.SendToOutstation("C4 01 15 00 06");
    std::string request5 = "C4 01 15 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request5);  

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C4 81 80 00 15 05 00 00 00 01 29 00 00 00 " + freezeTimestampHex); // Frozen value now at 41
    std::string temp5 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
    std::cout << "request5= " << request5<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex()== 'C4 81 80 00 15 05 00 00 00 01 29 00 00 00 C0 AA 57 05 38 00'"<<'\n';
    std::cout << "temp3= " << temp5<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);

    std::string expectedCounterValue = clear ? "00" : "29";////counterValueHex;

    // Read all counters
////    t.SendToOutstation("C5 01 14 00 06");
    std::string request6 = "C5 01 15 00 06";
    SendToOutstation_in_OutstationTestObject(&t, request6);  

////    REQUIRE(t.lower->PopWriteAsHex()
////            == "C5 81 80 00 14 01 00 00 00 01 " + expectedCounterValue
////                + " 00 00 00"); // Check if counter value is reset (if necessary)
    std::string temp6 = PopWriteAsHex_in_MockLowerLayer(&(t.lower));
    std::cout << "request6= " << request6<<'\n';
    std::cout << "REQUIRE(t.lower->PopWriteAsHex()== 'C5 81 80 00 14 01 00 00 00 01 + expectedCounterValue + 00 00 00'"<<'\n';
    std::cout << "expectedCounterValue= " << expectedCounterValue<<'\n';
    std::cout << "temp6= " << temp6<<'\n';

////    t.OnTxReady();
    OnTxReady_in_OutstationTestObject(&t);
}
