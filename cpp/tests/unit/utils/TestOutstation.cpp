#include <iostream>
#include <QApplication>
#include "header.h"

#include "TestOutstation.h"

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

void apply_in_TestTimeAndIntervalRead(IUpdateHandler*);
void apply_in_TestTimeAndIntervalRead(IUpdateHandler* db)
{
//void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value);
//void TimeAndInterval_in_TimeAndIntervalOver2(TimeAndInterval *pTimeAndInterval, DNPTime timeDNPTime, uint32_t interval, uint8_t units);
//boolean Update_TimeAndInterval_in_IUpdateHandler(IUpdateHandler*, TimeAndInterval* meas, uint16_t index);// = 0;
////    t.Transaction([](IUpdateHandler& db) { db.Update(TimeAndInterval(DNPTime(9), 3, IntervalUnits::Days), 0); });
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver2(&dDNPTime, 9);
  TimeAndInterval tTimeAndInterval;
  TimeAndInterval_in_TimeAndIntervalOver2(&tTimeAndInterval, dDNPTime, 3, IntervalUnits_Days);
  Update_TimeAndInterval_in_IUpdateHandler(db, &tTimeAndInterval, 0);// = EventMode::Detect) = 0;
}

void TestTimeAndIntervalRead(std::string& request)
{
  OutstationConfig config;
  OutstationConfig_in_OutstationConfig(&config);

//DatabaseConfig time_and_interval_in_DatabaseHelpers(uint16_t num);
////    OutstationTestObject t(config, configure::by_count_of::time_and_interval(1));
////    t.LowerLayerUp();
  DatabaseConfig tmp = time_and_interval_in_DatabaseHelpers(1);

  OutstationTestObject t;
  OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);

  LowerLayerUp_in_OutstationTestObject(&t);

////    t.Transaction([](IUpdateHandler& db) { db.Update(TimeAndInterval(DNPTime(9), 3, IntervalUnits::Days), 0); });
  Transaction_in_OutstationTestObject(&t, apply_in_TestTimeAndIntervalRead);//void (*apply)(IUpdateHandler*));

////    t.SendToOutstation(request);
//    std::string name("C2 01 1E 02 00 05 06");       // read 30 var 2, [05 : 06]
  SendToOutstation_in_OutstationTestObject(&t, request);

////    REQUIRE(t.lower->PopWriteAsHex() == "C0 81 80 00 32 04 00 00 00 09 00 00 00 00 00 03 00 00 00 05");
  std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

  std::cout<<"REQUIRE(t.lower->PopWriteAsHex() == 'C0 81 80 00 32 04 00 00 00 09 00 00 00 00 00 03 00 00 00 05')"<<'\n';
  std::cout << "temp= " << temp<<'\n';

}

void TestStaticAnalog(StaticAnalogVariation_uint8_t variation, double value, std::string& response)
{
////    auto database = configure::by_count_of::analog_input(1);
  DatabaseConfig database = analog_input_in_DatabaseHelpers(1);

////    database.analog_input[0].svariation = variation;
  database.analog_input[0].dDeadbandConfig_for_AnalogInfo.eEventConfig.svariation = variation;

//void OutstationConfig_in_OutstationConfig(OutstationConfig *pOutstationConfig);
  OutstationConfig oOutstationConfig;
  OutstationConfig_in_OutstationConfig(&oOutstationConfig);
////    TestStaticType<Analog>(OutstationConfig(), std::move(database), Analog(value), response);
  TestStaticType_for_Analog(&oOutstationConfig, &database, value, response);
}

static void *pPointerGlobal_in_TestStaticType_for_Analog;
void apply_in_TestStaticType_for_Analog(IUpdateHandler*);
void apply_in_TestStaticType_for_Analog(IUpdateHandler* db)
{
//boolean Update_Analog_in_IUpdateHandler(IUpdateHandler*, Analog* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////db.Update(PointType(value), 0);
  double *value = (double*) pPointerGlobal_in_TestStaticType_for_Analog;
  Analog aAnalog;
  Analog_in_AnalogOver2(&aAnalog, *value);
  Update_Analog_in_IUpdateHandler(db, &aAnalog, 0, EventMode_Detect);
}
////template<class PointType>
////void TestStaticType(const OutstationConfig& config,
////                    const DatabaseConfig& database,
////                    PointType value,
////                    const std::string& rsp)
void TestStaticType_for_Analog(OutstationConfig* config,
                               DatabaseConfig* database,
                               double value,
                               std::string& rsp)
{
////    OutstationTestObject t(config, database);
  OutstationTestObject t;
  OutstationTestObject_in_OutstationTestObject(&t, config, database);

////    t.LowerLayerUp();
  LowerLayerUp_in_OutstationTestObject(&t);

  pPointerGlobal_in_TestStaticType_for_Analog = &value;
////    t.Transaction([value](IUpdateHandler& db) { db.Update(PointType(value), 0); });
  Transaction_in_OutstationTestObject(&t, apply_in_TestStaticType_for_Analog);//void (*apply)(IUpdateHandler*));

////    t.SendToOutstation("C0 01 3C 01 06"); // Read class 0
  std::string name("C0 01 3C 01 06");       // Read class 0
  SendToOutstation_in_OutstationTestObject(&t, name);

////    REQUIRE((t.lower->PopWriteAsHex() == rsp));
  std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

  std::cout<<"REQUIRE((t.lower->PopWriteAsHex() == rsp))"<<'\n';
  std::cout << "temp= " << temp<<'\n';
  std::cout << "rsp= " << rsp<<'\n';
}

static void *pPointerGlobal_in_TestStaticBinaryOutputStatus_for_boolean;
void apply_in_TestStaticBinaryOutputStatus_for_boolean(IUpdateHandler*);
void apply_in_TestStaticBinaryOutputStatus_for_boolean(IUpdateHandler* db)
{
//boolean Update_BinaryOutputStatus_in_IUpdateHandler(IUpdateHandler*, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
////db.Update(BinaryOutputStatus(value, opendnp3::Flags(0x01)), 0);
  boolean *value = (boolean*) pPointerGlobal_in_TestStaticBinaryOutputStatus_for_boolean;

  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, 0x01);

  BinaryOutputStatus bBinaryOutputStatus;
  BinaryOutputStatus_in_BinaryOutputStatusOver5(&bBinaryOutputStatus, *value, fFlags);

  Update_BinaryOutputStatus_in_IUpdateHandler(db, &bBinaryOutputStatus, 0, EventMode_Detect);
}
void TestStaticBinaryOutputStatus_for_boolean(boolean value, std::string& response)
{
////    OutstationConfig cfg;
  OutstationConfig cfg;
  OutstationConfig_in_OutstationConfig(&cfg);

////    OutstationTestObject t(cfg, configure::by_count_of::binary_output_status(1));
  DatabaseConfig database = binary_output_status_in_DatabaseHelpers(1);

  OutstationTestObject t;
  OutstationTestObject_in_OutstationTestObject(&t, &cfg, &database);

////    t.LowerLayerUp();
  LowerLayerUp_in_OutstationTestObject(&t);

////    t.Transaction([value](IUpdateHandler& db) { db.Update(BinaryOutputStatus(value, opendnp3::Flags(0x01)), 0); });
  pPointerGlobal_in_TestStaticBinaryOutputStatus_for_boolean = &value;
  Transaction_in_OutstationTestObject(&t, apply_in_TestStaticBinaryOutputStatus_for_boolean);//void (*apply)(IUpdateHandler*));

////    t.SendToOutstation("C0 01 3C 01 06"); // Read class 0
  std::string name("C0 01 3C 01 06");       // Read class 0
  SendToOutstation_in_OutstationTestObject(&t, name);
////    REQUIRE((t.lower->PopWriteAsHex() == response));
  std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

  std::cout<<"REQUIRE((t.lower->PopWriteAsHex() == rsp))"<<'\n';
  std::cout << "temp= " << temp<<'\n';
  std::cout << "response= " << response<<'\n';
}

////template<class T>
////void TestStaticAnalogOutputStatus(StaticAnalogOutputStatusVariation variation, T value, const std::string& response)
void TestStaticAnalogOutputStatus(StaticAnalogOutputStatusVariation_uint8_t variation, double value, std::string& response)
{
////    auto database = configure::by_count_of::analog_output_status(1);
  DatabaseConfig database = analog_output_status_in_DatabaseHelpers(1);

  database.analog_output_status[0].dDeadbandConfig_for_AnalogOutputStatusInfo.eEventConfig.svariation = variation;

//void TestStaticType_for_AnalogOutputStatus(OutstationConfig* config,
//                    DatabaseConfig* database,
//                    AnalogOutputStatus value,
//                    std::string& rsp)
////    TestStaticType<AnalogOutputStatus>(OutstationConfig(), std::move(database), AnalogOutputStatus(value), response);
  OutstationConfig config;
  OutstationConfig_in_OutstationConfig(&config);
  TestStaticType_for_AnalogOutputStatus(&config,
                                        &database,
                                        value,
                                        response);
}

static void *pPointerGlobal_in_TestStaticType_for_AnalogOutputStatus;
void apply_in_TestStaticType_for_AnalogOutputStatus(IUpdateHandler*);
void apply_in_TestStaticType_for_AnalogOutputStatus(IUpdateHandler* db)
{
////db.Update(PointType(value), 0);
  double *value = (double*) pPointerGlobal_in_TestStaticType_for_AnalogOutputStatus;
  AnalogOutputStatus aAnalogOutputStatus;
  AnalogOutputStatus_in_AnalogOutputStatusOver2(&aAnalogOutputStatus, *value);

  Update_AnalogOutputStatus_in_IUpdateHandler(db, &aAnalogOutputStatus, 0, EventMode_Detect);
}
////template<class PointType>
////void TestStaticType(const OutstationConfig& config,
////                    const DatabaseConfig& database,
////                    PointType value,
////                    const std::string& rsp)
void TestStaticType_for_AnalogOutputStatus(OutstationConfig* config,
    DatabaseConfig* database,
    double value,
    std::string& rsp)
{
////    OutstationTestObject t(config, database);
  OutstationTestObject t;
  OutstationTestObject_in_OutstationTestObject(&t, config, database);

////    t.LowerLayerUp();
  LowerLayerUp_in_OutstationTestObject(&t);

  pPointerGlobal_in_TestStaticType_for_AnalogOutputStatus = &value;
////    t.Transaction([value](IUpdateHandler& db) { db.Update(PointType(value), 0); });
  Transaction_in_OutstationTestObject(&t, apply_in_TestStaticType_for_AnalogOutputStatus);//void (*apply)(IUpdateHandler*));

////    t.SendToOutstation("C0 01 3C 01 06"); // Read class 0
  std::string name("C0 01 3C 01 06");       // Read class 0
  SendToOutstation_in_OutstationTestObject(&t, name);

////    REQUIRE((t.lower->PopWriteAsHex() == rsp));
  std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

  std::cout<<"REQUIRE((t.lower->PopWriteAsHex() == rsp))"<<'\n';
  std::cout << "temp= " << temp<<'\n';
  std::cout << "rsp= " << rsp<<'\n';
}
