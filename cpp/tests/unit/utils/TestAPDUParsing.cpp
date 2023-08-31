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

std::cout<<"TestComplex1"<<std::endl;
  MockApduHeaderHandler mock;
  MockApduHeaderHandler_in_MockApduHeaderHandler(&mock);
std::cout<<"TestComplex2"<<std::endl;

////    MockLogHandler log;
//ParseResult_uint8_t Parse_in_APDUParser_static(
//  RSeq_for_Uint16_t *buffer,
//  IAPDUHandler *handler);
//RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer);

std::cout<<"TestComplex3"<<std::endl;
  RSeq_for_Uint16_t temp = ToRSeq_in_CopyableBuffer(&(buffer.bByteStr.cCopyableBuffer));
////    auto result = APDUParser::Parse(buffer.ToRSeq(), mock, &log.logger, settings);
std::cout<<"TestComplex4"<<std::endl;
  ParseResult_uint8_t result = Parse_in_APDUParser_static(
                                 &temp,
                                 &(mock.iIAPDUHandler));
std::cout<<"TestComplex5"<<std::endl;
////    REQUIRE((result == expected));
////    REQUIRE(numCalls == mock.records.size());

////    validate(mock);
//  validate(&mock);
  return result;
}

////void TestSimple(const std::string& hex, ParseResult expected, size_t numCalls)
////{
////    TestComplex(hex, expected, numCalls, [](MockApduHeaderHandler&) {});
////}
