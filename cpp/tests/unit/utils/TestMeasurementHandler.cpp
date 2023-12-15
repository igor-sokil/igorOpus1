
//#include "log_info.h"
//#ifdef  LOG_INFO
#include <iostream>
//#endif
#include <QApplication>
#include "header.h"
#include "TestMeasurementHandler.h"
////ParseResult TestObjectHeaders(const std::string& objects,
////                              ParseResult expectedResult,
////                              const std::function<void(MockSOEHandler&)>& verify)
ParseResult_uint8_t TestObjectHeaders(std::string& objects,
                              ParseResult_uint8_t expectedResult,
                              void (*verify)(MockSOEHandler*))
{
    MockSOEHandler soe;
    MockSOEHandler_in_MockSOEHandler(&soe);
////    MockLogHandler log;

////    HexSequence hex(objects);
    HexSequence hex;
    HexSequence_in_HexSequence(&hex, objects);

//ParseResult_uint8_t ProcessMeasurements_in_MeasurementHandler_static(ResponseInfo info,
//    RSeq_for_Uint16_t* objects,
//    ISOEHandler* pHandler);
////    auto result
////        = MeasurementHandler::ProcessMeasurements(ResponseInfo(true, true, true), hex.ToRSeq(), log.logger, &soe);
 ResponseInfo rResponseInfo;
 ResponseInfo_in_ResponseInfo(&rResponseInfo, true, true, true);

 RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(hex.bByteStr.cCopyableBuffer));

ParseResult_uint8_t result = ProcessMeasurements_in_MeasurementHandler_static(rResponseInfo,
    &temp,
    &(soe.iISOEHandler));

////    REQUIRE(result == expectedResult);
  std::cout<<"REQUIRE(result == expectedResult)"<<'\n';
  std::cout<<"result= "<<(uint16_t)result<<'\n';
  std::cout<<"expectedResult= "<<(uint16_t)expectedResult<<'\n';

    verify(&soe);
    return result;
}
