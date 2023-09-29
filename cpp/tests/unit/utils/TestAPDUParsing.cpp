//#include <QtWidgets>
#include <iostream>
#include <QApplication>
#include "header.h"
#include "BufferHelpers.h"
//#include "utils/MeasurementComparisons.h"

#include "ControlRelayOutputBlock.h"
#include "Indexed.h"
//#include <opendnp3/logging/LogLevels.h>

#include "HexConversions.h"

#include "MockAPDUHeaderHandler.h"
//#include "dnp3mocks/MockLogHandler.h"

#include "APDUHeaderParser.h"
#include "APDUParser.h"

#include "TestAPDUParsing.h"

////#include <catch.hpp>

////#include <functional>

////using namespace std;
////using namespace opendnp3;
////using namespace ser4cpp;

ParseResult_uint8_t TestComplex(std::string& hx, void (*validate)(MockApduHeaderHandler*))
//                 ParseResult expected,
//                 size_t numCalls,
//                 const std::function<void(MockApduHeaderHandler&)>& validate,
//                 ParserSettings settings = ParserSettings::Default())
{
////    HexSequence buffer(hex);
  HexSequence buffer;
  HexSequence_in_HexSequence(&buffer, hx);

//qDebug()<<"TestComplex1";
  MockApduHeaderHandler mock;
  MockApduHeaderHandler_in_MockApduHeaderHandler(&mock);
//qDebug()<<"TestComplex2";

////    MockLogHandler log;
//ParseResult_uint8_t Parse_in_APDUParser_static(
//  RSeq_for_Uint16_t *buffer,
//  IAPDUHandler *handler);
//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);

//qDebug()<<"TestComplex3";
  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(buffer.bByteStr.cCopyableBuffer));
////    auto result = APDUParser::Parse(buffer.ToRSeq(), mock, &log.logger, settings);
//qDebug()<<"TestComplex4";
  ParseResult_uint8_t result = Parse_in_APDUParser_static(
                                 &temp,
                                 &(mock.iIAPDUHandler));
////    REQUIRE((result == expected));
////    REQUIRE(numCalls == mock.records.size());
//std::cout<<"ParseResult_uint8_t result ="<<result<<std::endl;
std::cout<<"mock.records.size()="<<mock.records.size()<<std::endl;

////    validate(mock);
  if(validate) validate(&mock);

  return result;
}

////void TestSimple(const std::string& hex, ParseResult expected, size_t numCalls)
////{
////    TestComplex(hex, expected, numCalls, [](MockApduHeaderHandler&) {});
////}
