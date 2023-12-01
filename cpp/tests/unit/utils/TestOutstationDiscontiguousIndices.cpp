#include "TestOutstationDiscontiguousIndices.h"

void update_in_TestOutstationDiscontiguousIndices(IUpdateHandler*);
void update_in_TestOutstationDiscontiguousIndices(IUpdateHandler* db)
{
    std::cout << "update_in_TestOutstationDiscontiguousIndices" <<'\n';
////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Binary(true, Flags(0x01)), 2, EventMode::Suppress);
////        db.Update(Binary(false, Flags(0x01)), 4, EventMode::Suppress);
////    });

 Flags fFlags;
 Flags_In_FlagsOver2(&fFlags, 1);

//void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
 Binary bBinary1;
 Binary_in_BinaryOver5(&bBinary1, true, fFlags);
 Binary bBinary2;
 Binary_in_BinaryOver5(&bBinary2, false, fFlags);

//boolean Update_Binary_in_IUpdateHandler(IUpdateHandler*, Binary* meas, uint16_t index, EventMode_uint8_t mode);// = EventMode::Detect) = 0;
         Update_Binary_in_IUpdateHandler(db, &bBinary1, 2, EventMode_Suppress);// = EventMode::Detect) = 0;
         Update_Binary_in_IUpdateHandler(db, &bBinary2, 4, EventMode_Suppress);// = EventMode::Detect) = 0;
}

std::string QueryDiscontiguousBinary( std::string& request)
{
////    OutstationTestObject t(OutstationConfig(),
////                           configure::from({{2, BinaryConfig{}}, {4, BinaryConfig{}}, {5, BinaryConfig{}}
////
////                           }));
    OutstationConfig config;
    OutstationConfig_in_OutstationConfig(&config);

    BinaryConfig bBinaryConfig;
    BinaryConfig_in_BinaryConfig(&bBinaryConfig);
//DatabaseConfig from_AnalogConfig_in_DatabaseHelpers(std::map<uint16_t, AnalogConfig> map);
    DatabaseConfig tmp = from_BinaryConfig_in_DatabaseHelpers(
                                           {{2, bBinaryConfig},
                                            {4, bBinaryConfig},
                                            {5, bBinaryConfig}}
                                                          );
    OutstationTestObject t;
    OutstationTestObject_in_OutstationTestObject(&t, &config, &tmp);


////    t.LowerLayerUp();
    LowerLayerUp_in_OutstationTestObject(&t);

////    t.Transaction([](IUpdateHandler& db) {
////        db.Update(Binary(true, Flags(0x01)), 2, EventMode::Suppress);
////        db.Update(Binary(false, Flags(0x01)), 4, EventMode::Suppress);
////    });
    Transaction_in_OutstationTestObject(&t, update_in_TestOutstationDiscontiguousIndices);//void (*apply)(IUpdateHandler*));

////    t.SendToOutstation(request);
    SendToOutstation_in_OutstationTestObject(&t, request);  

////    return t.lower->PopWriteAsHex();
    std::string temp = PopWriteAsHex_in_MockLowerLayer(&(t.lower));

std::cout << "request= " << request<<'\n';
std::cout << "temp= " << temp<<'\n';
   return temp;
}
