/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
//#include <QtWidgets>
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "RangeParser.h"

//#include "app/parsing/BufferedCollection.h"
#include "Group1.h"
#include "Group10.h"
#include "Group20.h"
#include "Group21.h"
#include "Group3.h"
#include "Group30.h"
#include "Group40.h"
#include "Group50.h"
#include <string.h>
//#include "logging/LogMacros.h"

boolean expectsContents_in_RangeParser = false;

////namespace opendnp3
////{

////RangeParser::RangeParser(const Range& range, size_t requiredSize, HandleFun handler)
void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint32_t requiredSize, HandleFun_in_RangeParser handler)
{
////  : range(range), requiredSize(requiredSize), handler(handler)
  pRangeParser->range = *range;
  pRangeParser->requiredSize = requiredSize;
  pRangeParser->handler = handler;
}

////ParseResult RangeParser::ParseHeader(ser4cpp::rseq_t& buffer,
////                                     const NumParser& numparser,
////                                     const ParserSettings& settings,
////                                     const HeaderRecord& record,
////                                     Logger* pLogger,
////                                     IAPDUHandler* pHandler)
ParseResult_uint8_t ParseHeader_in_RangeParser_static(
  RSeq_for_Uint16_t *buffer,
  NumParser* numparser,
//                                   const ParserSettings& settings,
  HeaderRecord* record,
//                                   Logger* pLogger,
  IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseHeader_in_RangeParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif

  Range range;

//ParseResult_uint8_t ParseRange_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer, Range *range);////, Logger* pLogger) const;
////  auto res = numparser.ParseRange(buffer, range, pLogger);
  ParseResult_uint8_t res = ParseRange_in_NumParser(numparser, buffer, &range);////, Logger* pLogger) const;

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ParseResult_uint8_t res = "<<(uint16_t)res<<std::endl;
  inspect_RSeq(buffer);
#endif

  if (res != ParseResult_OK)
  {
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return res;
  }

////  FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u %s, %s [%u, %u]", record.group, record.variation,
////                      GroupVariationSpec::to_human_string(record.enumeration),
////                      QualifierCodeSpec::to_human_string(record.GetQualifierCode()), range.start, range.stop);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,*"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record.group= "<<(uint16_t)record->gGroupVariationRecord.group<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record.variation= "<<(uint16_t)record->gGroupVariationRecord.variation<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record.enumeration= "<<(uint16_t)record->gGroupVariationRecord.enumeration<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record.GetQualifierCode()= "<<(uint16_t)GetQualifierCode_in_HeaderRecord(record)<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.start= "<<(uint16_t)range.start<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*range.stop= "<<(uint16_t)range.stop<<'\n';
#endif

////  if (settings.ExpectsContents())
  if(expectsContents_in_RangeParser)
  {
//ParseResult_uint8_t ParseRangeOfObjects_in_RangeParser_static(
//  RSeq_for_Uint16_t *buffer,
//  HeaderRecord *record,
//  Range *range,
//                                          Logger* pLogger,
//  IAPDUHandler* pHandler);
////    return ParseRangeOfObjects(buffer, record, range, pLogger, pHandler);
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return ParseRangeOfObjects_in_RangeParser_static(buffer, record, &range, pHandler);
  }

  if (pHandler)
  {
//void RangeHeader_in_RangeHeader(RangeHeader *pRangeHeader, HeaderRecord *record, Range *range_);
//void OnHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header);
////    pHandler->OnHeader(RangeHeader(record, range));
    RangeHeader rRangeHeader;
    RangeHeader_in_RangeHeader(&rRangeHeader, record, &range);

    OnHeader_RangeHeader_in_IAPDUHandler(pHandler, &rRangeHeader);
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return ParseResult_OK;
}

////ParseResult RangeParser::Process(const HeaderRecord& record,
////                                 ser4cpp::rseq_t& buffer,
////                                 IAPDUHandler* pHandler,
////                                 Logger* pLogger) const
ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
    HeaderRecord *record,
    RSeq_for_Uint16_t *buffer,
    IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Process_in_RangeParser1"<<std::endl;
  inspect_RSeq(buffer);
#endif

////  if (buffer.length() < requiredSize)
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < pRangeParser->requiredSize)
  {
////    SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified objects");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for specified objects')"<<std::endl;
    decrement_stack_info();
#endif
    return ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS;
  }

  if (pHandler)
  {
//typedef void (*HandleFun_in_RangeParser)(
//  HeaderRecord* record,
//  Range* range,
//  RSeq_for_Uint16_t* buffer,
//  IAPDUHandler* handler);
    pRangeParser->handler(record, &(pRangeParser->range), buffer, pHandler);
  }
////  buffer.advance(requiredSize);
  advance_in_RSeq_for_Uint16_t(buffer, pRangeParser->requiredSize);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return ParseResult_OK;
}

////#define MACRO_PARSE_OBJECTS_WITH_RANGE(descriptor)
////    case (GroupVariation::descriptor):
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);

////ParseResult RangeParser::ParseRangeOfObjects(
////  ser4cpp::rseq_t& buffer, const HeaderRecord& record, const Range& range, Logger* pLogger, IAPDUHandler* pHandler)
ParseResult_uint8_t ParseRangeOfObjects_in_RangeParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  Range *range,
//                                          Logger* pLogger,
  IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseRangeOfObjects_in_RangeParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif

  switch (record->gGroupVariationRecord.enumeration)
  {
  case (GroupVariation_Group1Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var1"<<std::endl;
    decrement_stack_info();
#endif
// RangeParser FromBitfieldType_Indexed_for_Binary_in_RangeParser_static(Range* range);
////    return RangeParser::FromBitfieldType<Binary>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromBitfieldType_Indexed_for_Binary_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group1Var2);
  case (GroupVariation_Group1Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var2"<<std::endl;
    decrement_stack_info();
#endif
//RangeParser FromFixedSize_for_Group1Var2_in_RangeParser_static(Range* range)
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group1Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

  case (GroupVariation_Group3Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var1"<<std::endl;
    decrement_stack_info();
#endif
//RangeParser FromDoubleBitfieldType_for_DoubleBitBinary_in_RangeParser_static(Range* range)
////    return RangeParser::FromDoubleBitfieldType<DoubleBitBinary>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromDoubleBitfieldType_for_DoubleBitBinary_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

  case (GroupVariation_Group10Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group10Var1"<<std::endl;
    decrement_stack_info();
#endif
////    return RangeParser::FromBitfieldType<BinaryOutputStatus>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromBitfieldType_Indexed_for_BinaryOutputStatus_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group3Var2);
  case (GroupVariation_Group3Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var2"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group3Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group10Var2);
  case (GroupVariation_Group10Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group10Var2"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group10Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var1);
  case (GroupVariation_Group20Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var1"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group20Var1_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var2);
  case (GroupVariation_Group20Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var2"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group20Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var5);
  case (GroupVariation_Group20Var5):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var5"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group20Var5_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var6);
  case (GroupVariation_Group20Var6):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var6"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group20Var6_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var1);
  case (GroupVariation_Group21Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var1"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group21Var1_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var2);
  case (GroupVariation_Group21Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var2"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group21Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var5);
  case (GroupVariation_Group21Var5):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var5"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group21Var5_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var6);
  case (GroupVariation_Group21Var6):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var6"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group21Var6_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var9);
  case (GroupVariation_Group21Var9):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var9"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group21Var9_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var10);
  case (GroupVariation_Group21Var10):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var10"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group21Var10_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var1);
  case (GroupVariation_Group30Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var1"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group30Var1_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var2);
  case (GroupVariation_Group30Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var2"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group30Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var3);
  case (GroupVariation_Group30Var3):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var3"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group30Var3_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var4);
  case (GroupVariation_Group30Var4):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var4"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group30Var4_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var5);
  case (GroupVariation_Group30Var5):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var5"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group30Var5_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var6);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var1);
  case (GroupVariation_Group40Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var1"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group40Var1_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var2);
  case (GroupVariation_Group40Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var2"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group40Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var3);
  case (GroupVariation_Group40Var3):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var3"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group40Var3_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var4);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group50Var4);
  case (GroupVariation_Group50Var4):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group50Var4"<<std::endl;
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group50Var4_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

  case (GroupVariation_Group80Var1):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group80Var1"<<std::endl;
    decrement_stack_info();
#endif
////    return RangeParser::FromBitfieldType<IINValue>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromBitfieldType_Indexed_for_IINValue_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp, record, buffer, pHandler);
  }

  case (GroupVariation_Group110Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group110Var0"<<std::endl;
    decrement_stack_info();
#endif
    return ParseRangeOfOctetData_in_RangeParser_static(buffer, record, range, /*pLogger,*/ pHandler);

  default:
////    FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unsupported qualifier/object - %s - %i / %i",
////                        QualifierCodeSpec::to_human_string(record.GetQualifierCode()), record.group,
////                        record.variation);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unsupported qualifier/object - %s - %i / %i'"<<std::endl;
    decrement_stack_info();
#endif

    return ParseResult_INVALID_OBJECT_QUALIFIER;
  }
}

////      auto read = [range, record](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<OctetString> {
////        const auto octetData = buffer.take(record.variation);
////        OctetString octets(Buffer(octetData, octetData.length()));
////        buffer.advance(record.variation);
///        return WithIndex(octets, range.start + pos);
////      };
Indexed_for_OctetString read_for_OctetString_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_OctetString read_for_OctetString_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
  Range *range         = (Range *)pPointerGlobal1;
  HeaderRecord *record = (HeaderRecord *)pPointerGlobal2;

//RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////        const auto octetData = buffer.take(record.variation);
  RSeq_for_Uint16_t octetData = take_in_RSeq_for_Uint16_t(buffer, record->gGroupVariationRecord.variation);

//void Buffer_in_BufferOver2(Buffer *pBuffer, uint8_t* data, uint16_t length);
//void OctetString_in_OctetStringOver3(OctetString *pOctetString, Buffer *buffer);
////        OctetString octets(Buffer(octetData, octetData.length()));
  Buffer bBuffer;
  Buffer_in_BufferOver2(&bBuffer, octetData.buffer_, length_in_HasLength_for_Uint16_t(&(octetData.hHasLength)));
  OctetString octets;
  OctetString_in_OctetStringOver3(&octets, &bBuffer);

////        buffer.advance(record.variation);
  advance_in_RSeq_for_Uint16_t(buffer, record->gGroupVariationRecord.variation);

///        return WithIndex(octets, range.start + pos);
  return WithIndex_in_Indexed_for_OctetString(&octets, range->start + pos);
}

////ParseResult RangeParser::ParseRangeOfOctetData(
////  ser4cpp::rseq_t& buffer, const HeaderRecord& record, const Range& range, Logger* pLogger, IAPDUHandler* pHandler)
ParseResult_uint8_t ParseRangeOfOctetData_in_RangeParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  Range *range,
//                                            Logger* pLogger,
  IAPDUHandler* pHandler)
{
  if (record->gGroupVariationRecord.variation > 0)
  {
//uint32_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
    uint32_t COUNT = Count_in_Range(range);
    uint32_t size = record->gGroupVariationRecord.variation * COUNT;
////    if (buffer.length() < size)
    if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < size)
    {
////      SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified octet objects");
#ifdef  LOG_INFO
      increment_stack_info();
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for specified octet objects')"<<std::endl;
      decrement_stack_info();
#endif
      return ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS;
    }

    if (pHandler)
    {
////      auto read = [range, record](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<OctetString> {
////        const auto octetData = buffer.take(record.variation);
////        OctetString octets(Buffer(octetData, octetData.length()));
////        buffer.advance(record.variation);
///        return WithIndex(octets, range.start + pos);
////      };

////      auto collection = CreateBufferedCollection<Indexed<OctetString>>(buffer, COUNT, read);
      pPointerGlobal1 = range;
      pPointerGlobal2 = record;
      BufferedCollection_Indexed_for_OctetString collection = CreateBufferedCollection_Indexed_for_OctetString_static(
            buffer,
            COUNT,
            read_for_OctetString_in_RangeParser);

////      pHandler->OnHeader(RangeHeader(record, range), collection);
      RangeHeader rRangeHeader;
      RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
      OnHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler(pHandler, &rRangeHeader, &(collection.iICollection_Indexed_for_OctetString));
    }

///    buffer.advance(size);
    advance_in_RSeq_for_Uint16_t(buffer, size);
    return ParseResult_OK;
  }
  else
  {
////    SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Octet string variation 0 may only be used in requests");
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Octet string variation 0 may only be used in requests')"<<std::endl;
    decrement_stack_info();
#endif
    return ParseResult_INVALID_OBJECT;
  }
}

////} // namespace opendnp3
//---------------------Group1Var2------------------------------------------------------
//typedef Indexed_for_Binary (*ReadFunc_Indexed_for_Binary)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Binary readInvokeRangeOf_for_BinaryGroup1Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Binary readInvokeRangeOf_for_BinaryGroup1Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Binary bBinary;
  Binary_in_BinaryOver1(&bBinary);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, Binary*);
  ReadTarget_in_Group1Var2_static(buffer, &bBinary);
//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
  return WithIndex_in_Indexed_for_Binary(&bBinary, range->start + pos);
}

void InvokeRangeOf_for_Group1Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_Binary CreateBufferedCollection_Indexed_for_Binary_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_Binary readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Binary collection = CreateBufferedCollection_Indexed_for_Binary_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_BinaryGroup1Var2_in_RangeParser);

//  void OnHeader_RangeHeader_for_Binary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values);
////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Binary));
}

RangeParser FromFixedSize_for_Group1Var2_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group1Var2_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group1Var2_static()= "<<Size_in_Group1Var2_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//uint16_t Size_in_Group1Var2_static(void);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group1Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group1Var2_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group1Var2------------------------------------------------------
//---------------------Group3Var2------------------------------------------------------
//typedef Indexed_for_DoubleBitBinary (*ReadFunc_Indexed_for_DoubleBitBinary)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_DoubleBitBinary readInvokeRangeOf_for_DoubleBitBinaryGroup3Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_DoubleBitBinary readInvokeRangeOf_for_DoubleBitBinaryGroup3Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  DoubleBitBinary dDoubleBitBinary;
  DoubleBitBinary_in_DoubleBitBinaryOver1(&dDoubleBitBinary);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, Binary*);
  ReadTarget_in_Group3Var2_static(buffer, &dDoubleBitBinary);
//Indexed_for_DoubleBitBinary WithIndex_in_Indexed_for_DoubleBitBinary(DoubleBitBinary* value, uint16_t index);
  return WithIndex_in_Indexed_for_DoubleBitBinary(&dDoubleBitBinary, range->start + pos);
}

void InvokeRangeOf_for_Group3Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_Binary CreateBufferedCollection_Indexed_for_Binary_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_Binary readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_DoubleBitBinary collection = CreateBufferedCollection_Indexed_for_DoubleBitBinary_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_DoubleBitBinaryGroup3Var2_in_RangeParser);

//  void OnHeader_RangeHeader_for_Binary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values);
////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_DoubleBitBinary));
}

RangeParser FromFixedSize_for_Group3Var2_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group3Var2_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group3Var2_static()= "<<Size_in_Group3Var2_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//uint16_t Size_in_Group1Var2_static(void);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group3Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group3Var2_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group3Var2------------------------------------------------------
//---------------------Group10Var2------------------------------------------------------
//typedef Indexed_for_BinaryOutputStatus (*ReadFunc_Indexed_for_BinaryOutputStatus)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_BinaryOutputStatus readInvokeRangeOf_for_BinaryOutputStatusGroup10Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_BinaryOutputStatus readInvokeRangeOf_for_BinaryOutputStatusGroup10Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  BinaryOutputStatus bBinaryOutputStatus;
  BinaryOutputStatus_in_BinaryOutputStatusOver1(&bBinaryOutputStatus);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, BinaryOutputStatus*);
  ReadTarget_in_Group10Var2_static(buffer, &bBinaryOutputStatus);
//Indexed_for_BinaryOutputStatus WithIndex_in_Indexed_for_BinaryOutputStatus(BinaryOutputStatus* value, uint16_t index);
  return WithIndex_in_Indexed_for_BinaryOutputStatus(&bBinaryOutputStatus, range->start + pos);
}

void InvokeRangeOf_for_Group10Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_BinaryOutputStatus collection = CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_BinaryOutputStatusGroup10Var2_in_RangeParser);

//  void OnHeader_RangeHeader_for_Binary_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus* values);
////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_BinaryOutputStatus));
}

RangeParser FromFixedSize_for_Group10Var2_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group10Var2_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group10Var2_static()= "<<Size_in_Group10Var2_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//uint16_t Size_in_Group1Var2_static(void);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group10Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group10Var2_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group10Var2------------------------------------------------------
//---------------------Group20Var1------------------------------------------------------
//typedef Indexed_for_Counter (*ReadFunc_Indexed_for_Counter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Counter cCounter;
  Counter_in_CounterOver1(&cCounter);
  ReadTarget_in_Group20Var1_static(buffer, &cCounter);
  return WithIndex_in_Indexed_for_Counter(&cCounter, range->start + pos);
}

void InvokeRangeOf_for_Group20Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_CounterGroup20Var1_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Counter));
}

RangeParser FromFixedSize_for_Group20Var1_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group20Var1_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group20Var1_static()= "<<Size_in_Group20Var1_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//uint16_t Size_in_Group1Var2_static(void);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group20Var1_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group20Var1_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group20Var1------------------------------------------------------
//---------------------Group20Var2------------------------------------------------------
//typedef Indexed_for_Counter (*ReadFunc_Indexed_for_Counter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Counter cCounter;
  Counter_in_CounterOver1(&cCounter);
  ReadTarget_in_Group20Var2_static(buffer, &cCounter);
  return WithIndex_in_Indexed_for_Counter(&cCounter, range->start + pos);
}

void InvokeRangeOf_for_Group20Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_CounterGroup20Var2_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Counter));
}

RangeParser FromFixedSize_for_Group20Var2_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group20Var2_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group20Var2_static()= "<<Size_in_Group20Var2_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group20Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group20Var2_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group20Var2------------------------------------------------------
//---------------------Group20Var5------------------------------------------------------
//typedef Indexed_for_Counter (*ReadFunc_Indexed_for_Counter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var5_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var5_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Counter cCounter;
  Counter_in_CounterOver1(&cCounter);
  ReadTarget_in_Group20Var5_static(buffer, &cCounter);
  return WithIndex_in_Indexed_for_Counter(&cCounter, range->start + pos);
}

void InvokeRangeOf_for_Group20Var5_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_CounterGroup20Var5_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Counter));
}

RangeParser FromFixedSize_for_Group20Var5_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group20Var5_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group20Var5_static()= "<<Size_in_Group20Var5_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group20Var5_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group20Var5_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group20Var5------------------------------------------------------
//---------------------Group20Var6------------------------------------------------------
//typedef Indexed_for_Counter (*ReadFunc_Indexed_for_Counter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var6_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeRangeOf_for_CounterGroup20Var6_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Counter cCounter;
  Counter_in_CounterOver1(&cCounter);
  ReadTarget_in_Group20Var6_static(buffer, &cCounter);
  return WithIndex_in_Indexed_for_Counter(&cCounter, range->start + pos);
}

void InvokeRangeOf_for_Group20Var6_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_CounterGroup20Var6_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Counter));
}

RangeParser FromFixedSize_for_Group20Var6_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group20Var6_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group20Var6_static()= "<<Size_in_Group20Var6_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group20Var6_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group20Var6_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group20Var6------------------------------------------------------
//---------------------Group21Var1------------------------------------------------------
//typedef Indexed_for_FrozenCounter (*ReadFunc_Indexed_for_FrozenCounter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  FrozenCounter fFrozenCounter;
  FrozenCounter_in_FrozenCounterOver1(&fFrozenCounter);
  ReadTarget_in_Group21Var1_static(buffer, &fFrozenCounter);
  return WithIndex_in_Indexed_for_FrozenCounter(&fFrozenCounter, range->start + pos);
}

void InvokeRangeOf_for_Group21Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_FrozenCounterGroup21Var1_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}

RangeParser FromFixedSize_for_Group21Var1_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group21Var1_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group21Var1_static()= "<<Size_in_Group21Var1_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group21Var1_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group21Var1_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group21Var1------------------------------------------------------
//---------------------Group21Var2------------------------------------------------------
//typedef Indexed_for_FrozenCounter (*ReadFunc_Indexed_for_FrozenCounter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  FrozenCounter fFrozenCounter;
  FrozenCounter_in_FrozenCounterOver1(&fFrozenCounter);
  ReadTarget_in_Group21Var2_static(buffer, &fFrozenCounter);
  return WithIndex_in_Indexed_for_FrozenCounter(&fFrozenCounter, range->start + pos);
}

void InvokeRangeOf_for_Group21Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_FrozenCounterGroup21Var2_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}

RangeParser FromFixedSize_for_Group21Var2_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group21Var2_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group21Var2_static()= "<<Size_in_Group21Var2_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group21Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group21Var2_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group21Var2------------------------------------------------------
//---------------------Group21Var5------------------------------------------------------
//typedef Indexed_for_FrozenCounter (*ReadFunc_Indexed_for_FrozenCounter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var5_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var5_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  FrozenCounter fFrozenCounter;
  FrozenCounter_in_FrozenCounterOver1(&fFrozenCounter);
  ReadTarget_in_Group21Var5_static(buffer, &fFrozenCounter);
  return WithIndex_in_Indexed_for_FrozenCounter(&fFrozenCounter, range->start + pos);
}

void InvokeRangeOf_for_Group21Var5_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_FrozenCounterGroup21Var5_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}

RangeParser FromFixedSize_for_Group21Var5_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group21Var5_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group21Var5_static()= "<<Size_in_Group21Var5_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group21Var5_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group21Var5_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group21Var5------------------------------------------------------
//---------------------Group21Var6------------------------------------------------------
//typedef Indexed_for_FrozenCounter (*ReadFunc_Indexed_for_FrozenCounter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var6_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var6_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  FrozenCounter fFrozenCounter;
  FrozenCounter_in_FrozenCounterOver1(&fFrozenCounter);
  ReadTarget_in_Group21Var6_static(buffer, &fFrozenCounter);
  return WithIndex_in_Indexed_for_FrozenCounter(&fFrozenCounter, range->start + pos);
}

void InvokeRangeOf_for_Group21Var6_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_FrozenCounterGroup21Var6_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}

RangeParser FromFixedSize_for_Group21Var6_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group21Var6_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group21Var6_static()= "<<Size_in_Group21Var6_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group21Var6_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group21Var6_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group21Var6------------------------------------------------------
//---------------------Group21Var9------------------------------------------------------
//typedef Indexed_for_FrozenCounter (*ReadFunc_Indexed_for_FrozenCounter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var9_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var9_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  FrozenCounter fFrozenCounter;
  FrozenCounter_in_FrozenCounterOver1(&fFrozenCounter);
  ReadTarget_in_Group21Var9_static(buffer, &fFrozenCounter);
  return WithIndex_in_Indexed_for_FrozenCounter(&fFrozenCounter, range->start + pos);
}

void InvokeRangeOf_for_Group21Var9_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_FrozenCounterGroup21Var9_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}

RangeParser FromFixedSize_for_Group21Var9_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group21Var9_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group21Var9_static()= "<<Size_in_Group21Var9_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group21Var9_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group21Var9_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group21Var9------------------------------------------------------
//---------------------Group21Var10------------------------------------------------------
//typedef Indexed_for_FrozenCounter (*ReadFunc_Indexed_for_FrozenCounter)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var10_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeRangeOf_for_FrozenCounterGroup21Var10_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  FrozenCounter fFrozenCounter;
  FrozenCounter_in_FrozenCounterOver1(&fFrozenCounter);
  ReadTarget_in_Group21Var10_static(buffer, &fFrozenCounter);
  return WithIndex_in_Indexed_for_FrozenCounter(&fFrozenCounter, range->start + pos);
}

void InvokeRangeOf_for_Group21Var10_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_FrozenCounterGroup21Var10_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}

RangeParser FromFixedSize_for_Group21Var10_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group21Var10_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group21Var10_static()= "<<Size_in_Group21Var10_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group21Var10_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group21Var10_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group21Var10------------------------------------------------------
//---------------------Group30Var1------------------------------------------------------
//typedef Indexed_for_Analog (*ReadFunc_Indexed_for_Analog)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Analog aAnalog;
  Analog_in_AnalogOver1(&aAnalog);
  ReadTarget_in_Group30Var1_static(buffer, &aAnalog);
  return WithIndex_in_Indexed_for_Analog(&aAnalog, range->start + pos);
}

void InvokeRangeOf_for_Group30Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogGroup30Var1_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Analog));
}

RangeParser FromFixedSize_for_Group30Var1_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group30Var1_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group30Var1_static()= "<<Size_in_Group30Var1_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group30Var1_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group30Var1_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group30Var1------------------------------------------------------
//---------------------Group30Var2------------------------------------------------------
//typedef Indexed_for_Analog (*ReadFunc_Indexed_for_Analog)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Analog aAnalog;
  Analog_in_AnalogOver1(&aAnalog);
  ReadTarget_in_Group30Var2_static(buffer, &aAnalog);
  return WithIndex_in_Indexed_for_Analog(&aAnalog, range->start + pos);
}

void InvokeRangeOf_for_Group30Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogGroup30Var2_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Analog));
}

RangeParser FromFixedSize_for_Group30Var2_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group30Var2_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group30Var2_static()= "<<Size_in_Group30Var2_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group30Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group30Var2_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group30Var2------------------------------------------------------
//---------------------Group30Var3------------------------------------------------------
//typedef Indexed_for_Analog (*ReadFunc_Indexed_for_Analog)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var3_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var3_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Analog aAnalog;
  Analog_in_AnalogOver1(&aAnalog);
  ReadTarget_in_Group30Var3_static(buffer, &aAnalog);
  return WithIndex_in_Indexed_for_Analog(&aAnalog, range->start + pos);
}

void InvokeRangeOf_for_Group30Var3_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogGroup30Var3_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Analog));
}

RangeParser FromFixedSize_for_Group30Var3_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group30Var3_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group30Var3_static()= "<<Size_in_Group30Var3_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group30Var3_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group30Var3_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group30Var3------------------------------------------------------
//---------------------Group30Var4------------------------------------------------------
//typedef Indexed_for_Analog (*ReadFunc_Indexed_for_Analog)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var4_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var4_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Analog aAnalog;
  Analog_in_AnalogOver1(&aAnalog);
  ReadTarget_in_Group30Var4_static(buffer, &aAnalog);
  return WithIndex_in_Indexed_for_Analog(&aAnalog, range->start + pos);
}

void InvokeRangeOf_for_Group30Var4_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogGroup30Var4_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Analog));
}

RangeParser FromFixedSize_for_Group30Var4_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group30Var4_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group30Var4_static()= "<<Size_in_Group30Var4_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group30Var4_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group30Var4_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group30Var4------------------------------------------------------
//---------------------Group30Var5------------------------------------------------------
//typedef Indexed_for_Analog (*ReadFunc_Indexed_for_Analog)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var5_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeRangeOf_for_AnalogGroup30Var5_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Analog aAnalog;
  Analog_in_AnalogOver1(&aAnalog);
  ReadTarget_in_Group30Var5_static(buffer, &aAnalog);
  return WithIndex_in_Indexed_for_Analog(&aAnalog, range->start + pos);
}

void InvokeRangeOf_for_Group30Var5_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogGroup30Var5_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Analog));
}

RangeParser FromFixedSize_for_Group30Var5_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group30Var5_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group30Var5_static()= "<<Size_in_Group30Var5_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group30Var5_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group30Var5_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group30Var5------------------------------------------------------
//---------------------Group40Var1------------------------------------------------------
//typedef Indexed_for_AnalogOutputStatus (*ReadFunc_Indexed_for_AnalogOutputStatus)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeRangeOf_for_AnalogOutputStatusGroup40Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeRangeOf_for_AnalogOutputStatusGroup40Var1_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  AnalogOutputStatus aAnalogOutputStatus;
  AnalogOutputStatus_in_AnalogOutputStatusOver1(&aAnalogOutputStatus);
  ReadTarget_in_Group40Var1_static(buffer, &aAnalogOutputStatus);
  return WithIndex_in_Indexed_for_AnalogOutputStatus(&aAnalogOutputStatus, range->start + pos);
}

void InvokeRangeOf_for_Group40Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogOutputStatusGroup40Var1_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}

RangeParser FromFixedSize_for_Group40Var1_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group40Var1_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group40Var1_static()= "<<Size_in_Group40Var1_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group40Var1_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group40Var1_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group40Var1------------------------------------------------------
//---------------------Group40Var2------------------------------------------------------
//typedef Indexed_for_AnalogOutputStatus (*ReadFunc_Indexed_for_AnalogOutputStatus)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeRangeOf_for_AnalogOutputStatusGroup40Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeRangeOf_for_AnalogOutputStatusGroup40Var2_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  AnalogOutputStatus aAnalogOutputStatus;
  AnalogOutputStatus_in_AnalogOutputStatusOver1(&aAnalogOutputStatus);
  ReadTarget_in_Group40Var2_static(buffer, &aAnalogOutputStatus);
  return WithIndex_in_Indexed_for_AnalogOutputStatus(&aAnalogOutputStatus, range->start + pos);
}

void InvokeRangeOf_for_Group40Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogOutputStatusGroup40Var2_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}

RangeParser FromFixedSize_for_Group40Var2_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group40Var2_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group40Var2_static()= "<<Size_in_Group40Var2_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group40Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group40Var2_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group40Var2------------------------------------------------------
//---------------------Group40Var3------------------------------------------------------
//typedef Indexed_for_AnalogOutputStatus (*ReadFunc_Indexed_for_AnalogOutputStatus)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeRangeOf_for_AnalogOutputStatusGroup40Var3_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeRangeOf_for_AnalogOutputStatusGroup40Var3_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  AnalogOutputStatus aAnalogOutputStatus;
  AnalogOutputStatus_in_AnalogOutputStatusOver1(&aAnalogOutputStatus);
  ReadTarget_in_Group40Var3_static(buffer, &aAnalogOutputStatus);
  return WithIndex_in_Indexed_for_AnalogOutputStatus(&aAnalogOutputStatus, range->start + pos);
}

void InvokeRangeOf_for_Group40Var3_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_AnalogOutputStatusGroup40Var3_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}

RangeParser FromFixedSize_for_Group40Var3_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group40Var3_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group40Var3_static()= "<<Size_in_Group40Var3_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group40Var3_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group40Var3_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group40Var3------------------------------------------------------
//---------------------Group50Var4------------------------------------------------------
//typedef Indexed_for_TimeAndInterval (*ReadFunc_Indexed_for_AnalogOutputStatus)(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t pos);
Indexed_for_TimeAndInterval readInvokeRangeOf_for_TimeAndIntervalGroup50Var4_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_TimeAndInterval readInvokeRangeOf_for_TimeAndIntervalGroup50Var4_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  TimeAndInterval tTimeAndInterval;
  TimeAndInterval_in_TimeAndIntervalOver1(&tTimeAndInterval);
  ReadTarget_in_Group50Var4_static(buffer, &tTimeAndInterval);
  return WithIndex_in_Indexed_for_TimeAndInterval(&tTimeAndInterval, range->start + pos);
}

void InvokeRangeOf_for_Group50Var4_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_TimeAndInterval collection = CreateBufferedCollection_Indexed_for_TimeAndInterval_static(
        buffer,
        COUNT,
        readInvokeRangeOf_for_TimeAndIntervalGroup50Var4_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_TimeAndInterval));
}

RangeParser FromFixedSize_for_Group50Var4_in_RangeParser_static(Range* range)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FromFixedSize_for_Group50Var4_in_RangeParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Count_in_Range(range)= "<<Count_in_Range(range)<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Size_in_Group50Var4_static()= "<<Size_in_Group50Var4_static()<<std::endl;
  decrement_stack_info();
#endif
//uint32_t Count_in_Range(Range *pRange);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint32_t size = Count_in_Range(range) * Size_in_Group50Var4_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeOf_for_Group50Var4_in_RangeParser_static);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
//---------------------Group50Var4------------------------------------------------------

//------------------------------Binary---------------------------------------------
Indexed_for_Binary readInvokeRangeBitfieldType_for_Binary_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Binary readInvokeRangeBitfieldType_for_Binary_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<Type> {
////        Type value(GetBit(buffer, pos));
////        return WithIndex(value, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  Binary value;
//boolean GetBit_in_DoubleBit_static(RSeq_for_Uint16_t* buffer, uint32_t position);
  Binary_in_BinaryOver2(&value, GetBit_in_DoubleBit_static(buffer, pos));
  return WithIndex_in_Indexed_for_Binary(&value, range->start + pos);
}

void InvokeRangeBitfieldType_for_Binary_in_RangeParser_static(
  HeaderRecord* record,
  Range* range,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<Type> {
////        Type value(GetBit(buffer, pos));
////        return WithIndex(value, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_Binary collection = CreateBufferedCollection_Indexed_for_Binary_static(
        buffer,
        COUNT,
        readInvokeRangeBitfieldType_for_Binary_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_Binary));
}

RangeParser FromBitfieldType_Indexed_for_Binary_in_RangeParser_static(Range* range)
{
//uint32_t NumBytesInBits_in_DoubleBit_static(uint32_t numBits);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint32_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto SIZE = NumBytesInBits(range.Count());
  uint32_t SIZE = NumBytesInBits_in_DoubleBit_static(Count_in_Range(range));
////    return RangeParser(range, SIZE, &InvokeRangeBitfieldType<Type>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, SIZE, InvokeRangeBitfieldType_for_Binary_in_RangeParser_static);
  return rRangeParser;
}
//------------------------------Binary---------------------------------------------
//------------------------------BinaryOutputStatus---------------------------------------------
Indexed_for_BinaryOutputStatus readInvokeRangeBitfieldType_for_BinaryOutputStatus_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_BinaryOutputStatus readInvokeRangeBitfieldType_for_BinaryOutputStatus_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<Type> {
////        Type value(GetBit(buffer, pos));
////        return WithIndex(value, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  BinaryOutputStatus value;
//boolean GetBit_in_DoubleBit_static(RSeq_for_Uint16_t* buffer, uint32_t position);
  BinaryOutputStatus_in_BinaryOutputStatusOver2(&value, GetBit_in_DoubleBit_static(buffer, pos));
  return WithIndex_in_Indexed_for_BinaryOutputStatus(&value, range->start + pos);
}

void InvokeRangeBitfieldType_for_BinaryOutputStatus_in_RangeParser_static(
  HeaderRecord* record,
  Range* range,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<Type> {
////        Type value(GetBit(buffer, pos));
////        return WithIndex(value, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_BinaryOutputStatus collection = CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
        buffer,
        COUNT,
        readInvokeRangeBitfieldType_for_BinaryOutputStatus_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_BinaryOutputStatus));
}

RangeParser FromBitfieldType_Indexed_for_BinaryOutputStatus_in_RangeParser_static(Range* range)
{
//uint32_t NumBytesInBits_in_DoubleBit_static(uint32_t numBits);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint32_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto SIZE = NumBytesInBits(range.Count());
  uint32_t SIZE = NumBytesInBits_in_DoubleBit_static(Count_in_Range(range));
////    return RangeParser(range, SIZE, &InvokeRangeBitfieldType<Type>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, SIZE, InvokeRangeBitfieldType_for_BinaryOutputStatus_in_RangeParser_static);
  return rRangeParser;
}
//------------------------------BinaryOutputStatus---------------------------------------------
//------------------------------IINValue---------------------------------------------
Indexed_for_IINValue readInvokeRangeBitfieldType_for_IINValue_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_IINValue readInvokeRangeBitfieldType_for_IINValue_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<Type> {
////        Type value(GetBit(buffer, pos));
////        return WithIndex(value, range.start + pos);
  Range *range = (Range *)pPointerGlobal1;

  IINValue value;
//boolean GetBit_in_DoubleBit_static(RSeq_for_Uint16_t* buffer, uint32_t position);
  IINValue_in_IINValueOver2(&value, GetBit_in_DoubleBit_static(buffer, pos));
  return WithIndex_in_Indexed_for_IINValue(&value, range->start + pos);
}

void InvokeRangeBitfieldType_for_IINValue_in_RangeParser_static(
  HeaderRecord* record,
  Range* range,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    const auto COUNT = range.Count();
  uint32_t COUNT = Count_in_Range(range);

////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<Type> {
////        Type value(GetBit(buffer, pos));
////        return WithIndex(value, range.start + pos);
////    };

////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_IINValue collection = CreateBufferedCollection_Indexed_for_IINValue_static(
        buffer,
        COUNT,
        readInvokeRangeBitfieldType_for_IINValue_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_IINValue_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_IINValue));
}

RangeParser FromBitfieldType_Indexed_for_IINValue_in_RangeParser_static(Range* range)
{
//uint32_t NumBytesInBits_in_DoubleBit_static(uint32_t numBits);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint32_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto SIZE = NumBytesInBits(range.Count());
  uint32_t SIZE = NumBytesInBits_in_DoubleBit_static(Count_in_Range(range));
////    return RangeParser(range, SIZE, &InvokeRangeBitfieldType<Type>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, SIZE, InvokeRangeBitfieldType_for_IINValue_in_RangeParser_static);
  return rRangeParser;
}
//------------------------------IINValue---------------------------------------------
//------------------------------DoubleBitBinary---------------------------------------------
////template<class Type> RangeParser RangeParser::FromDoubleBitfieldType(const Range& range)
RangeParser FromDoubleBitfieldType_for_DoubleBitBinary_in_RangeParser_static(Range* range)
{
//uint32_t Count_in_Range(Range *pRange);
//uint32_t NumBytesInDoubleBits_in_DoubleBit_static(uint32_t numBits);
////    const auto size = NumBytesInDoubleBits(range.Count());
uint32_t size = NumBytesInDoubleBits_in_DoubleBit_static(Count_in_Range(range));

//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint32_t requiredSize, HandleFun_in_RangeParser handler);
////    return RangeParser(range, size, &InvokeRangeDoubleBitfieldType<Type>);
 RangeParser rRangeParser;
 RangeParser_in_RangeParser(&rRangeParser, range, size, InvokeRangeDoubleBitfieldType_for_DoubleBitBinary_in_RangeParser_static);
 return rRangeParser;
}

Indexed_for_DoubleBitBinary readInvokeRangeBitfieldType_for_DoubleBitBinary_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_DoubleBitBinary readInvokeRangeBitfieldType_for_DoubleBitBinary_in_RangeParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
////    auto read = [range](ser4cpp::rseq_t& buffer, size_t pos) -> Indexed<Type> {
////        Type value(GetDoubleBit(buffer, pos));
////        return WithIndex(value, static_cast<uint16_t>(range.start + pos));
  Range *range = (Range *)pPointerGlobal1;

  DoubleBitBinary value;
//DoubleBit_uint8_t GetDoubleBit_in_DoubleBit_static(RSeq_for_Uint16_t* buffer, uint32_t index);
  DoubleBitBinary_in_DoubleBitBinaryOver2(&value, GetDoubleBit_in_DoubleBit_static(buffer, pos));
  return WithIndex_in_Indexed_for_DoubleBitBinary(&value, range->start + pos);
}

void InvokeRangeDoubleBitfieldType_for_DoubleBitBinary_in_RangeParser_static(
                                                HeaderRecord* record,
                                                Range* range,
                                                RSeq_for_Uint16_t* buffer,
                                                IAPDUHandler* handler)
{
//uint32_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
uint32_t COUNT = Count_in_Range(range);

////    auto read = [range](ser4cpp::rseq_t& buffer, size_t pos) -> Indexed<Type> {
////        Type value(GetDoubleBit(buffer, pos));
////        return WithIndex(value, static_cast<uint16_t>(range.start + pos));
////    };

////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, COUNT, read);
  pPointerGlobal1 = range;
  BufferedCollection_Indexed_for_DoubleBitBinary collection = CreateBufferedCollection_Indexed_for_DoubleBitBinary_static(
        buffer,
        COUNT,
        readInvokeRangeBitfieldType_for_DoubleBitBinary_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(handler, &rRangeHeader, &(collection.iICollection_Indexed_for_DoubleBitBinary));
}
//------------------------------DoubleBitBinary---------------------------------------------
