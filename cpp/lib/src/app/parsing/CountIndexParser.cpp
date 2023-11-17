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

#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "CountIndexParser.h"

#include "BufferedCollection.h"
#include "Group11.h"
#include "Group12.h"
#include "Group13.h"
#include "Group2.h"
#include "Group22.h"
#include "Group23.h"
#include "Group32.h"
#include "Group4.h"
#include "Group41.h"
#include "Group42.h"
#include "Group43.h"
////#include "logging/LogMacros.h"

//boolean expectsContents_in_CountIndexParser = false;

////namespace opendnp3
///{

void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint32_t requiredSize, NumParser* numparser, HandleFun_in_CountIndexParser handler)
{
  pCountIndexParser->count = count;
  pCountIndexParser->requiredSize = requiredSize;
  pCountIndexParser->numparser = *numparser;
  pCountIndexParser->handler = handler;
}

ParseResult_uint8_t ParseHeader_in_CountIndexParser_static(
  RSeq_for_Uint16_t* buffer,
  NumParser* numparser,
  //const ParserSettings& settings,
  HeaderRecord* record,
  //Logger* pLogger,
  IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseHeader_in_CountIndexParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif

  uint16_t count;
//    ParseResult_uint8_t ParseCount_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer, uint16_t *count);////, Logger* pLogger) const;
////    auto res = numparser.ParseCount(buffer, count, pLogger);
  ParseResult_uint8_t res = ParseCount_in_NumParser(numparser, buffer, &count);////, Logger* pLogger) const;
  if (res == ParseResult_OK)
  {
////        FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u %s, %s [%u]", record.group, record.variation,
////                            GroupVariationSpec::to_human_string(record.enumeration),
////                            QualifierCodeSpec::to_human_string(record.GetQualifierCode()), count);
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
//    std::cout<<"*range.start= "<<(uint16_t)range.start<<'\n';
//    std::cout<<"*range.stop= "<<(uint16_t)range.stop<<'\n';
  decrement_stack_info();
#endif

    if (expectsContents)//_in_CountIndexParser)
    {
      return ParseCountOfObjects_in_CountIndexParser_static(buffer, record, numparser, count, /*pLogger,*/ pHandler);
    }
    else
    {
      return ParseCountOfIndices_in_CountIndexParser_static(buffer, record, numparser, count, /*pLogger,*/ pHandler);
    }
  }

  return res;
}

ParseResult_uint8_t Process_in_CountIndexParser(CountIndexParser *pCountIndexParser,
    HeaderRecord* record,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* pHandler)
////Logger* pLogger) const
{
#ifdef  LOG_INFO
   std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"Process_in_CountIndexParser1"<<std::endl;
#endif
////    if (buffer.length() < requiredSize)
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < pCountIndexParser->requiredSize)
  {
////        SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified objects");
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"***SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for specified objects')***"<<std::endl;
  decrement_stack_info();
#endif
    return ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS;
  }

  if (pHandler)
  {
//typedef void (*HandleFun_in_CountIndexParser)(HeaderRecord *record,
//    uint16_t count,
//    NumParser *numparser,
//    RSeq_for_Uint16_t *buffer,
//    IAPDUHandler *handler);
    pCountIndexParser->handler(record, pCountIndexParser->count, &(pCountIndexParser->numparser), buffer, pHandler);
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
//    void advance_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////    buffer.advance(requiredSize);
  advance_in_RSeq_for_Uint16_t(buffer, pCountIndexParser->requiredSize);
  return ParseResult_OK;
}

ParseResult_uint8_t ParseCountOfObjects_in_CountIndexParser_static(
  RSeq_for_Uint16_t* buffer,
  HeaderRecord* record,
  NumParser* numparser,
  uint16_t count,
  ////Logger* pLogger,
  IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
   std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseCountOfObjects_in_CountIndexParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record->gGroupVariationRecord.enumeration= "<<std::hex<<record->gGroupVariationRecord.enumeration<<std::dec<<std::endl;
#endif

  switch (record->gGroupVariationRecord.enumeration)
  {
  case (GroupVariation_Group2Var1):
  {
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group2Var1"<<std::endl;
  decrement_stack_info();
#endif
//CountIndexParser From_for_Group2Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser);
//ParseResult_uint8_t Process_in_CountIndexParser(CountIndexParser *pCountIndexParser,
//    HeaderRecord *record,
//    RSeq_for_Uint16_t *buffer,
//    IAPDUHandler* pHandler);//,
////       return CountIndexParser::From<Group2Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group2Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
  }

  case (GroupVariation_Group2Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group2Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group2Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group2Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group2Var3):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group2Var3"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group2Var3>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group2Var3_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group4Var1):
    {
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group4Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group4Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group4Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
    }

    case (GroupVariation_Group4Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group4Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group4Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group4Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group4Var3):
    {
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group4Var3"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group4Var3>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group4Var3_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
    }

    case (GroupVariation_Group11Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group11Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group11Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group11Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group11Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group11Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group11Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group11Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group12Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group12Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group12Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group12Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

   case (GroupVariation_Group13Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group13Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group13Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group13Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}
   case (GroupVariation_Group13Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group13Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group13Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group13Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

   case (GroupVariation_Group22Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group22Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group22Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group22Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group22Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group22Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group22Var5):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var5"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group22Var5>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group22Var5_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

   case (GroupVariation_Group22Var6):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var6"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group22Var6>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group22Var6_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group23Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group23Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group23Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group23Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group23Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group23Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group23Var5):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var5"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group23Var5>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group23Var5_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group23Var6):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var6"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group23Var6>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group23Var6_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group32Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group32Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group32Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group32Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group32Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group32Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group32Var3):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var3"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group32Var3>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group32Var3_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group32Var4):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var4"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group32Var4>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group32Var4_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group32Var5):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var5"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group32Var5>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group32Var5_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

////    case (GroupVariation::Group32Var6):
////        return CountIndexParser::From<Group32Var6>(count, numparser).Process(record, buffer, pHandler, pLogger);
    case (GroupVariation_Group32Var7):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var7"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group32Var7>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group32Var7_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

////    case (GroupVariation::Group32Var8):
////        return CountIndexParser::From<Group32Var8>(count, numparser).Process(record, buffer, pHandler, pLogger);

    case (GroupVariation_Group41Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group41Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group41Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group41Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group41Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group41Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group41Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group41Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group41Var3):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group41Var3"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group41Var3>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group41Var3_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

////    case (GroupVariation::Group41Var4):
////        return CountIndexParser::From<Group41Var4>(count, numparser).Process(record, buffer, pHandler, pLogger);

    case (GroupVariation_Group42Var1):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group42Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group42Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group42Var2):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var2"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group42Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group42Var2_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group42Var3):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var3"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group42Var3>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group42Var3_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group42Var4):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var4"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group42Var4>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group42Var4_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

    case (GroupVariation_Group42Var5):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var5"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group42Var5>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group42Var5_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

////    case (GroupVariation::Group42Var6):
////        return CountIndexParser::From<Group42Var6>(count, numparser).Process(record, buffer, pHandler, pLogger);

   case (GroupVariation_Group42Var7):
{
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var7"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group42Var7>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group42Var7_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

////    case (GroupVariation::Group42Var8):
////        return CountIndexParser::From<Group42Var8>(count, numparser).Process(record, buffer, pHandler, pLogger);

    case (GroupVariation_Group43Var1):
{
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group43Var1"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group43Var1>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group43Var1_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

////    case (GroupVariation::Group43Var2):
////        return CountIndexParser::From<Group43Var2>(count, numparser).Process(record, buffer, pHandler, pLogger);

    case (GroupVariation_Group43Var3):
{
#ifdef  LOG_INFO
    std::cout<<"*"<<"*GroupVariation_Group43Var3"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group43Var3>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group43Var3_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}

////    case (GroupVariation::Group43Var4):
////        return CountIndexParser::From<Group43Var4>(count, numparser).Process(record, buffer, pHandler, pLogger);
////    case (GroupVariation::Group43Var5):
////        return CountIndexParser::From<Group43Var5>(count, numparser).Process(record, buffer, pHandler, pLogger);
////    case (GroupVariation::Group43Var6):
////        return CountIndexParser::From<Group43Var6>(count, numparser).Process(record, buffer, pHandler, pLogger);
////    case (GroupVariation::Group43Var7):
////        return CountIndexParser::From<Group43Var7>(count, numparser).Process(record, buffer, pHandler, pLogger);
////    case (GroupVariation::Group43Var8):
////        return CountIndexParser::From<Group43Var8>(count, numparser).Process(record, buffer, pHandler, pLogger);

    case (GroupVariation_Group50Var4):
{
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group50Var4"<<std::endl;
  decrement_stack_info();
#endif
////        return CountIndexParser::From<Group50Var4>(count, numparser).Process(record, buffer, pHandler, pLogger);
    CountIndexParser temp = From_for_Group50Var4_in_CountIndexParser_static(count, numparser);
    return Process_in_CountIndexParser(&temp, record, buffer, pHandler);
}
    case (GroupVariation_Group111Var0):
    {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
     std::cout<<"*GroupVariation_Group111Var0"<<std::endl;
  decrement_stack_info();
#endif
//ParseResult_uint8_t ParseIndexPrefixedOctetData_in_CountIndexParser_static(
//  RSeq_for_Uint16_t *buffer,
//  HeaderRecord *record,
//  NumParser *numparser,
//  uint32_t count,
//                                                   Logger* pLogger,
//  IAPDUHandler* pHandler)
////        return ParseIndexPrefixedOctetData(buffer, record, numparser, count, pLogger, pHandler);
return ParseIndexPrefixedOctetData_in_CountIndexParser_static(buffer, record, numparser, count, pHandler);
   }

  default:

////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unsupported qualifier/object - %s - %i / %i",
////                            QualifierCodeSpec::to_human_string(record.GetQualifierCode()), record.group,
////                            record.variation);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
     std::cout<<"*FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unsupported qualifier/object - %s - %i / %i'"<<std::endl;
  decrement_stack_info();
#endif

    return ParseResult_INVALID_OBJECT_QUALIFIER;
  }
}

static void *pPointerGlobal1_in_ParseCountOfIndices;
static void *pPointerGlobal2_in_ParseCountOfIndices;
uint16_t ReadFunc_uint16_in_CountIndexParser(RSeq_for_Uint16_t *buffer, uint32_t pos);
////    auto read = [&numparser, record](ser4cpp::rseq_t& buffer, uint32_t pos) -> uint16_t {
uint16_t ReadFunc_uint16_in_CountIndexParser(RSeq_for_Uint16_t *buffer, uint32_t pos)
{
  UNUSED(pos);
  NumParser *numParser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;
//  HeaderRecord *record = (HeaderRecord *)pPointerGlobal2;
////      return numparser.ReadNum(buffer);
  return ReadNum_in_NumParser(numParser, buffer);
};

ParseResult_uint8_t ParseCountOfIndices_in_CountIndexParser_static(
  RSeq_for_Uint16_t* buffer,
  HeaderRecord* record,
  NumParser* numparser,
  uint16_t count,
  ////Logger* pLogger,
  IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseCountOfIndices_in_CountIndexParser_static1"<<std::endl;
#endif
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const auto SIZE = static_cast<size_t>(count) * static_cast<size_t>(numparser.NumBytes());
  const uint32_t SIZE = count * (uint32_t)(NumBytes_in_NumParser(numparser));

////    if (buffer.length() < SIZE)
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < SIZE)
  {
////        SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified sequence of indices");
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for specified sequence of indices')"<<std::endl;
  decrement_stack_info();
#endif
    return ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS;
  }

  if (pHandler)
  {
////    auto read = [&numparser, record](ser4cpp::rseq_t& buffer, uint32_t pos) -> uint16_t {
////      return numparser.ReadNum(buffer);
////    };

    pPointerGlobal1_in_ParseCountOfIndices = numparser;
    pPointerGlobal2_in_ParseCountOfIndices = record;
//BufferedCollection_uint16 CreateBufferedCollection_uint16_static(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t count,
//  ReadFunc_uint16 readFunc);
////    auto collection = CreateBufferedCollection<uint16_t>(buffer, count, read);
    BufferedCollection_uint16 collection = CreateBufferedCollection_uint16_static(buffer, count, ReadFunc_uint16_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
//   void OnHeader_PrefixHeader_for_uint16_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, PrefixHeader* header, ICollection_for_uint16* values);
////    pHandler->OnHeader(PrefixHeader(record, count), collection);
    PrefixHeader pPrefixHeader;
    PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

    OnHeader_PrefixHeader_for_uint16_in_IAPDUHandler(pHandler, &pPrefixHeader, &(collection.iICollection_for_uint16));
  }

////  buffer.advance(SIZE);
  advance_in_RSeq_for_Uint16_t(buffer, SIZE);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return ParseResult_OK;
}

Indexed_for_OctetString read_for_OctetString_in_CountIndexParser(RSeq_for_Uint16_t *buffer, uint32_t pos);
////    auto read = [&numparser, record](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<OctetString> {
Indexed_for_OctetString read_for_OctetString_in_CountIndexParser(RSeq_for_Uint16_t *buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numParser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;
  HeaderRecord *record = (HeaderRecord *)pPointerGlobal2_in_ParseCountOfIndices;
//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////      auto index = numparser.ReadNum(buffer);
  uint16_t index = ReadNum_in_NumParser(numParser, buffer);
//RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////      const auto octetStringSlice = buffer.take(record.variation);
  RSeq_for_Uint16_t octetStringSlice = take_in_RSeq_for_Uint16_t(buffer, record->gGroupVariationRecord.variation);

////      OctetString octets(Buffer(octetStringSlice, octetStringSlice.length()));
  Buffer bBuffer;
  Buffer_in_BufferOver2(&bBuffer, octetStringSlice.buffer_, length_in_HasLength_for_Uint16_t(&(octetStringSlice.hHasLength)));
  OctetString octets;
  OctetString_in_OctetStringOver3(&octets, &bBuffer);

////      buffer.advance(record.variation);
  advance_in_RSeq_for_Uint16_t(buffer, record->gGroupVariationRecord.variation);

////      return WithIndex(octets, index);
  return WithIndex_in_Indexed_for_OctetString(&octets, index);
};

////ParseResult CountIndexParser::ParseIndexPrefixedOctetData(ser4cpp::rseq_t& buffer,
////    const HeaderRecord& record,
////    const NumParser& numparser,
////    uint32_t count,
////    Logger* pLogger,
///    IAPDUHandler* pHandler)
ParseResult_uint8_t ParseIndexPrefixedOctetData_in_CountIndexParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  NumParser *numparser,
  uint32_t count,
//                                                   Logger* pLogger,
  IAPDUHandler* pHandler)
{
  if (record->gGroupVariationRecord.variation == 0)
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

////  const uint32_t TOTAL_SIZE = count * (numparser.NumBytes() + record.variation);
  const uint32_t TOTAL_SIZE = count * (NumBytes_in_NumParser(numparser) + record->gGroupVariationRecord.variation);

////  if (buffer.length() < TOTAL_SIZE)
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < TOTAL_SIZE)
  {
////    SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified bitfield objects");
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for specified bitfield objects')"<<std::endl;
  decrement_stack_info();
#endif
    return ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS;
  }

  if (pHandler)
  {
////    auto read = [&numparser, record](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<OctetString> {
////      auto index = numparser.ReadNum(buffer);
////      const auto octetStringSlice = buffer.take(record.variation);
////      OctetString octets(Buffer(octetStringSlice, octetStringSlice.length()));
////      buffer.advance(record.variation);
////      return WithIndex(octets, index);
////    };

////    auto collection = CreateBufferedCollection<Indexed<OctetString>>(buffer, count, read);
    pPointerGlobal1_in_ParseCountOfIndices = numparser;
    pPointerGlobal2_in_ParseCountOfIndices = record;
    BufferedCollection_Indexed_for_OctetString collection = CreateBufferedCollection_Indexed_for_OctetString_static(
          buffer,
          count,
          read_for_OctetString_in_CountIndexParser);

////    pHandler->OnHeader(PrefixHeader(record, count), collection);
    PrefixHeader pPrefixHeader;
    PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

    OnHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler(pHandler, &pPrefixHeader, &(collection.iICollection_Indexed_for_OctetString));
  }

////  buffer.advance(TOTAL_SIZE);
  advance_in_RSeq_for_Uint16_t(buffer, TOTAL_SIZE);
  return ParseResult_OK;
}

////} // namespace opendnp3
//------------------------------------------Group2Var1------------------------------------------------
CountIndexParser From_for_Group2Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group2Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group2Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group2Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Binary readInvokeCountOf_for_Binary_Group2Var1_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Binary readInvokeCountOf_for_Binary_Group2Var1_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);
  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Binary pair;
  Indexed_for_Binary_in_Indexed_for_BinaryOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, Binary*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group2Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group2Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Binary collection = CreateBufferedCollection_Indexed_for_Binary_static(
        buffer,
        count,
        readInvokeCountOf_for_Binary_Group2Var1_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Binary));
}
//------------------------------------------Group2Var1------------------------------------------------
//------------------------------------------Group2Var2------------------------------------------------
CountIndexParser From_for_Group2Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group2Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group2Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group2Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Binary readInvokeCountOf_for_Binary_Group2Var2_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Binary readInvokeCountOf_for_Binary_Group2Var2_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);
  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Binary pair;
  Indexed_for_Binary_in_Indexed_for_BinaryOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, Binary*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group2Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group2Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Binary collection = CreateBufferedCollection_Indexed_for_Binary_static(
        buffer,
        count,
        readInvokeCountOf_for_Binary_Group2Var2_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Binary));
}
//------------------------------------------Group2Var2------------------------------------------------
//------------------------------------------Group2Var3------------------------------------------------
CountIndexParser From_for_Group2Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group2Var3_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group2Var3_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group2Var3_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Binary readInvokeCountOf_for_Binary_Group2Var3_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Binary readInvokeCountOf_for_Binary_Group2Var3_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);
  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Binary pair;
  Indexed_for_Binary_in_Indexed_for_BinaryOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group2Var3_static(RSeq_for_Uint16_t *, Binary*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group2Var3_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group2Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Binary collection = CreateBufferedCollection_Indexed_for_Binary_static(
        buffer,
        count,
        readInvokeCountOf_for_Binary_Group2Var3_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Binary));
}
//------------------------------------------Group2Var3------------------------------------------------
//------------------------------------------Group11Var1------------------------------------------------
CountIndexParser From_for_Group11Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group11Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group11Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group11Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_BinaryOutputStatus readInvokeCountOf_for_BinaryOutputStatus_Group11Var1_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_BinaryOutputStatus readInvokeCountOf_for_BinaryOutputStatus_Group11Var1_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"readInvokeCountOf_for_BinaryOutputStatus_Group11Var1_in_CountIndexParser1"<<std::endl;
  inspect_RSeq(buffer);
  decrement_stack_info();
#endif
  UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_BinaryOutputStatus pair;
  Indexed_for_BinaryOutputStatus_in_Indexed_for_BinaryOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, ControlRelayOutputBlock*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group11Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group11Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"InvokeCountOf_for_BinaryOutputStatus_Group11Var1_in_CountIndexParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_BinaryOutputStatus collection = CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_for_BinaryOutputStatus_Group11Var1_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_BinaryOutputStatus));
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//------------------------------------------Group11Var1------------------------------------------------
//------------------------------------------Group11Var2------------------------------------------------
CountIndexParser From_for_Group11Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group11Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group11Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group11Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_BinaryOutputStatus readInvokeCountOf_for_BinaryOutputStatus_Group11Var2_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_BinaryOutputStatus readInvokeCountOf_for_BinaryOutputStatus_Group11Var2_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"readInvokeCountOf_for_BinaryOutputStatus_Group11Var2_in_CountIndexParser1"<<std::endl;
  inspect_RSeq(buffer);
  decrement_stack_info();
#endif
  UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_BinaryOutputStatus pair;
  Indexed_for_BinaryOutputStatus_in_Indexed_for_BinaryOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, ControlRelayOutputBlock*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group11Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group11Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"InvokeCountOf_for_BinaryOutputStatus_Group11Var2_in_CountIndexParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_BinaryOutputStatus collection = CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_for_BinaryOutputStatus_Group11Var2_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_BinaryOutputStatus));
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//------------------------------------------Group11Var2------------------------------------------------
//------------------------------------------Group12Var1------------------------------------------------
CountIndexParser From_for_Group12Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group12Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group12Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group12Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_ControlRelayOutputBlock readInvokeCountOf_for_ControlRelayOutputBlock_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_ControlRelayOutputBlock readInvokeCountOf_for_ControlRelayOutputBlock_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"readInvokeCountOf_for_ControlRelayOutputBlock_in_CountIndexParser1"<<std::endl;
  inspect_RSeq(buffer);
  decrement_stack_info();
#endif
  UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_ControlRelayOutputBlock pair;
  Indexed_for_ControlRelayOutputBlock_in_Indexed_for_ControlRelayOutputBlockOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t *, ControlRelayOutputBlock*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group12Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group12Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"InvokeCountOf_for_Group12Var1_in_CountIndexParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_ControlRelayOutputBlock collection = CreateBufferedCollection_Indexed_for_ControlRelayOutputBlock_static(
        buffer,
        count,
        readInvokeCountOf_for_ControlRelayOutputBlock_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_ControlRelayOutputBlock));
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
//------------------------------------------Group12Var1------------------------------------------------
//------------------------------------------Group4Var1------------------------------------------------
CountIndexParser From_for_Group4Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group4Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group4Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group4Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_DoubleBitBinary readInvokeCountOf_Group4Var1_for_DoubleBitBinary_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_DoubleBitBinary readInvokeCountOf_Group4Var1_for_DoubleBitBinary_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_DoubleBitBinary pair;
  Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group4Var1_static(RSeq_for_Uint16_t *, DoubleBitBinary*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group4Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group4Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_DoubleBitBinary collection = CreateBufferedCollection_Indexed_for_DoubleBitBinary_static(
        buffer,
        count,
        readInvokeCountOf_Group4Var1_for_DoubleBitBinary_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_DoubleBitBinary));
}
//------------------------------------------Group4Var1------------------------------------------------
//------------------------------------------Group4Var2------------------------------------------------
CountIndexParser From_for_Group4Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group4Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group4Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group4Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_DoubleBitBinary readInvokeCountOf_Group4Var2_for_DoubleBitBinary_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_DoubleBitBinary readInvokeCountOf_Group4Var2_for_DoubleBitBinary_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_DoubleBitBinary pair;
  Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group4Var2_static(RSeq_for_Uint16_t *, DoubleBitBinary*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group4Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group4Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_DoubleBitBinary collection = CreateBufferedCollection_Indexed_for_DoubleBitBinary_static(
        buffer,
        count,
        readInvokeCountOf_Group4Var2_for_DoubleBitBinary_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_DoubleBitBinary));
}
//------------------------------------------Group4Var2------------------------------------------------
//------------------------------------------Group4Var3------------------------------------------------
CountIndexParser From_for_Group4Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group4Var3_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group4Var3_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group4Var3_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_DoubleBitBinary readInvokeCountOf_Group4Var3_for_DoubleBitBinary_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_DoubleBitBinary readInvokeCountOf_Group4Var3_for_DoubleBitBinary_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_DoubleBitBinary pair;
  Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group4Var3_static(RSeq_for_Uint16_t *, DoubleBitBinary*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group4Var3_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group4Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_DoubleBitBinary collection = CreateBufferedCollection_Indexed_for_DoubleBitBinary_static(
        buffer,
        count,
        readInvokeCountOf_Group4Var3_for_DoubleBitBinary_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_DoubleBitBinary));
}
//------------------------------------------Group4Var3------------------------------------------------
//------------------------------------------Group13Var1------------------------------------------------
CountIndexParser From_for_Group13Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group13Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group13Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group13Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_BinaryCommandEvent readInvokeCountOf_Group13Var1_for_BinaryCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_BinaryCommandEvent readInvokeCountOf_Group13Var1_for_BinaryCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_BinaryCommandEvent pair;
  Indexed_for_BinaryCommandEvent_in_Indexed_for_BinaryCommandEventOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group13Var1_static(RSeq_for_Uint16_t *, BinaryCommandEvent*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group13Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group13Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_BinaryCommandEvent collection = CreateBufferedCollection_Indexed_for_BinaryCommandEvent_static(
        buffer,
        count,
        readInvokeCountOf_Group13Var1_for_BinaryCommandEvent_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_BinaryCommandEvent));
}
//------------------------------------------Group13Var1------------------------------------------------
//------------------------------------------Group13Var2------------------------------------------------
CountIndexParser From_for_Group13Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group13Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group13Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group13Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_BinaryCommandEvent readInvokeCountOf_Group13Var2_for_BinaryCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_BinaryCommandEvent readInvokeCountOf_Group13Var2_for_BinaryCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_BinaryCommandEvent pair;
  Indexed_for_BinaryCommandEvent_in_Indexed_for_BinaryCommandEventOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group13Var2_static(RSeq_for_Uint16_t *, BinaryCommandEvent*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group13Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group13Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_BinaryCommandEvent collection = CreateBufferedCollection_Indexed_for_BinaryCommandEvent_static(
        buffer,
        count,
        readInvokeCountOf_Group13Var2_for_BinaryCommandEvent_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_BinaryCommandEvent));
}
//------------------------------------------Group13Var2------------------------------------------------
//------------------------------------------Group43Var1------------------------------------------------
CountIndexParser From_for_Group43Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group43Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group43Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group43Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogCommandEvent readInvokeCountOf_Group43Var1_for_AnalogCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogCommandEvent readInvokeCountOf_Group43Var1_for_AnalogCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogCommandEvent pair;
  Indexed_for_AnalogCommandEvent_in_Indexed_for_AnalogCommandEventOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group43Var1_static(RSeq_for_Uint16_t *, AnalogCommandEvent*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group43Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group43Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogCommandEvent collection = CreateBufferedCollection_Indexed_for_AnalogCommandEvent_static(
        buffer,
        count,
        readInvokeCountOf_Group43Var1_for_AnalogCommandEvent_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogCommandEvent));
}
//------------------------------------------Group43Var1------------------------------------------------
//------------------------------------------Group43Var3------------------------------------------------
CountIndexParser From_for_Group43Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group43Var3_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group43Var3_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group43Var3_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogCommandEvent readInvokeCountOf_Group43Var3_for_AnalogCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogCommandEvent readInvokeCountOf_Group43Var3_for_AnalogCommandEvent_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogCommandEvent pair;
  Indexed_for_AnalogCommandEvent_in_Indexed_for_AnalogCommandEventOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group43Var3_static(RSeq_for_Uint16_t *, AnalogCommandEvent*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group43Var3_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group43Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogCommandEvent collection = CreateBufferedCollection_Indexed_for_AnalogCommandEvent_static(
        buffer,
        count,
        readInvokeCountOf_Group43Var3_for_AnalogCommandEvent_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogCommandEvent));
}
//------------------------------------------Group43Var3------------------------------------------------
//------------------------------------------Group50Var4------------------------------------------------
CountIndexParser From_for_Group50Var4_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group50Var4_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group50Var4_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group50Var4_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_TimeAndInterval readInvokeCountOf_Group50Var4_for_TimeAndInterval_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_TimeAndInterval readInvokeCountOf_Group50Var4_for_TimeAndInterval_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_TimeAndInterval pair;
  Indexed_for_TimeAndInterval_in_Indexed_for_TimeAndIntervalOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group50Var4_static(RSeq_for_Uint16_t *, TimeAndInterval*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group50Var4_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group50Var4_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_TimeAndInterval collection = CreateBufferedCollection_Indexed_for_TimeAndInterval_static(
        buffer,
        count,
        readInvokeCountOf_Group50Var4_for_TimeAndInterval_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_TimeAndInterval));
}
//------------------------------------------Group50Var4------------------------------------------------
//------------------------------------------Group22Var1------------------------------------------------
CountIndexParser From_for_Group22Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group22Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group22Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group22Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Counter readInvokeCountOf_Group22Var1_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeCountOf_Group22Var1_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Counter pair;
  Indexed_for_Counter_in_Indexed_for_CounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group22Var1_static(RSeq_for_Uint16_t *, Counter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group22Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group22Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        count,
        readInvokeCountOf_Group22Var1_for_Counter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Counter));
}
//------------------------------------------Group22Var1------------------------------------------------
//------------------------------------------Group22Var2------------------------------------------------
CountIndexParser From_for_Group22Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group22Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group22Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group22Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Counter readInvokeCountOf_Group22Var2_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeCountOf_Group22Var2_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Counter pair;
  Indexed_for_Counter_in_Indexed_for_CounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group22Var2_static(RSeq_for_Uint16_t *, Counter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group22Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group22Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        count,
        readInvokeCountOf_Group22Var2_for_Counter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Counter));
}
//------------------------------------------Group22Var2------------------------------------------------
//------------------------------------------Group22Var5------------------------------------------------
CountIndexParser From_for_Group22Var5_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group22Var5_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group22Var5_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group22Var5_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Counter readInvokeCountOf_Group22Var5_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeCountOf_Group22Var5_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Counter pair;
  Indexed_for_Counter_in_Indexed_for_CounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group22Var5_static(RSeq_for_Uint16_t *, Counter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group22Var5_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group22Var5_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        count,
        readInvokeCountOf_Group22Var5_for_Counter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Counter));
}
//------------------------------------------Group22Var5------------------------------------------------
//------------------------------------------Group22Var6------------------------------------------------
CountIndexParser From_for_Group22Var6_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group22Var6_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group22Var6_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group22Var6_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Counter readInvokeCountOf_Group22Var6_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Counter readInvokeCountOf_Group22Var6_for_Counter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Counter pair;
  Indexed_for_Counter_in_Indexed_for_CounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group22Var6_static(RSeq_for_Uint16_t *, Counter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group22Var6_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group22Var6_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Counter collection = CreateBufferedCollection_Indexed_for_Counter_static(
        buffer,
        count,
        readInvokeCountOf_Group22Var6_for_Counter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Counter));
}
//------------------------------------------Group22Var6------------------------------------------------
//------------------------------------------Group23Var1------------------------------------------------
CountIndexParser From_for_Group23Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group23Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group23Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group23Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var1_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var1_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_FrozenCounter pair;
  Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group23Var1_static(RSeq_for_Uint16_t *, FrozenCounter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group23Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group23Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        count,
        readInvokeCountOf_Group23Var1_for_FrozenCounter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}
//------------------------------------------Group23Var1------------------------------------------------
//------------------------------------------Group23Var2------------------------------------------------
CountIndexParser From_for_Group23Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group23Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group23Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group23Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var2_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var2_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_FrozenCounter pair;
  Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group23Var2_static(RSeq_for_Uint16_t *, FrozenCounter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group23Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group23Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        count,
        readInvokeCountOf_Group23Var2_for_FrozenCounter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}
//------------------------------------------Group23Var2------------------------------------------------
//------------------------------------------Group23Var5------------------------------------------------
CountIndexParser From_for_Group23Var5_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group23Var5_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group23Var5_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group23Var5_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var5_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var5_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_FrozenCounter pair;
  Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group23Var5_static(RSeq_for_Uint16_t *, FrozenCounter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group23Var5_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group23Var5_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        count,
        readInvokeCountOf_Group23Var5_for_FrozenCounter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}
//------------------------------------------Group23Var5------------------------------------------------
//------------------------------------------Group23Var6------------------------------------------------
CountIndexParser From_for_Group23Var6_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group23Var6_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group23Var6_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group23Var6_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var6_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_FrozenCounter readInvokeCountOf_Group23Var6_for_FrozenCounter_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_FrozenCounter pair;
  Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group23Var6_static(RSeq_for_Uint16_t *, FrozenCounter*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group23Var6_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group23Var6_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_FrozenCounter collection = CreateBufferedCollection_Indexed_for_FrozenCounter_static(
        buffer,
        count,
        readInvokeCountOf_Group23Var6_for_FrozenCounter_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_FrozenCounter));
}
//------------------------------------------Group23Var6------------------------------------------------
//------------------------------------------Group32Var1------------------------------------------------
CountIndexParser From_for_Group32Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group32Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group32Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group32Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Analog readInvokeCountOf_Group32Var1_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeCountOf_Group32Var1_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Analog pair;
  Indexed_for_Analog_in_Indexed_for_AnalogOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group32Var1_static(RSeq_for_Uint16_t *, Analog*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group32Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group32Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        count,
        readInvokeCountOf_Group32Var1_for_Analog_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Analog));
}
//------------------------------------------Group32Var1------------------------------------------------
//------------------------------------------Group32Var2------------------------------------------------
CountIndexParser From_for_Group32Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group32Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group32Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group32Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Analog readInvokeCountOf_Group32Var2_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeCountOf_Group32Var2_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Analog pair;
  Indexed_for_Analog_in_Indexed_for_AnalogOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group32Var2_static(RSeq_for_Uint16_t *, Analog*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group32Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group32Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        count,
        readInvokeCountOf_Group32Var2_for_Analog_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Analog));
}
//------------------------------------------Group32Var2------------------------------------------------
//------------------------------------------Group32Var3------------------------------------------------
CountIndexParser From_for_Group32Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group32Var3_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group32Var3_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group32Var3_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Analog readInvokeCountOf_Group32Var3_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeCountOf_Group32Var3_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Analog pair;
  Indexed_for_Analog_in_Indexed_for_AnalogOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group32Var3_static(RSeq_for_Uint16_t *, Analog*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group32Var3_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group32Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        count,
        readInvokeCountOf_Group32Var3_for_Analog_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Analog));
}
//------------------------------------------Group32Var3------------------------------------------------
//------------------------------------------Group32Var4------------------------------------------------
CountIndexParser From_for_Group32Var4_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group32Var4_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group32Var4_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group32Var4_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Analog readInvokeCountOf_Group32Var4_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeCountOf_Group32Var4_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Analog pair;
  Indexed_for_Analog_in_Indexed_for_AnalogOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group32Var4_static(RSeq_for_Uint16_t *, Analog*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group32Var4_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group32Var4_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        count,
        readInvokeCountOf_Group32Var4_for_Analog_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Analog));
}
//------------------------------------------Group32Var4------------------------------------------------
//------------------------------------------Group32Var5------------------------------------------------
CountIndexParser From_for_Group32Var5_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group32Var5_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group32Var5_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group32Var5_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Analog readInvokeCountOf_Group32Var5_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeCountOf_Group32Var5_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Analog pair;
  Indexed_for_Analog_in_Indexed_for_AnalogOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group32Var5_static(RSeq_for_Uint16_t *, Analog*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group32Var5_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group32Var5_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        count,
        readInvokeCountOf_Group32Var5_for_Analog_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Analog));
}
//------------------------------------------Group32Var5------------------------------------------------
//------------------------------------------Group32Var7------------------------------------------------
CountIndexParser From_for_Group32Var7_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group32Var7_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group32Var7_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group32Var7_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_Analog readInvokeCountOf_Group32Var7_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_Analog readInvokeCountOf_Group32Var7_for_Analog_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_Analog pair;
  Indexed_for_Analog_in_Indexed_for_AnalogOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group32Var7_static(RSeq_for_Uint16_t *, Analog*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group32Var7_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group32Var7_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_Analog collection = CreateBufferedCollection_Indexed_for_Analog_static(
        buffer,
        count,
        readInvokeCountOf_Group32Var7_for_Analog_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_Analog));
}
//------------------------------------------Group32Var7------------------------------------------------
//------------------------------------------Group41Var1------------------------------------------------
CountIndexParser From_for_Group41Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group41Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group41Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group41Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputInt32 readInvokeCountOf_Group41Var1_for_AnalogOutputInt32_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputInt32 readInvokeCountOf_Group41Var1_for_AnalogOutputInt32_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputInt32 pair;
  Indexed_for_AnalogOutputInt32_in_Indexed_for_AnalogOutputInt32Over1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group41Var1_static(RSeq_for_Uint16_t *, AnalogOutputInt32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group41Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group41Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputInt32 collection = CreateBufferedCollection_Indexed_for_AnalogOutputInt32_static(
        buffer,
        count,
        readInvokeCountOf_Group41Var1_for_AnalogOutputInt32_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputInt32));
}
//------------------------------------------Group41Var1------------------------------------------------
//------------------------------------------Group41Var2------------------------------------------------
CountIndexParser From_for_Group41Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group41Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group41Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group41Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputInt16 readInvokeCountOf_Group41Var2_for_AnalogOutputInt16_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputInt16 readInvokeCountOf_Group41Var2_for_AnalogOutputInt16_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputInt16 pair;
  Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group41Var2_static(RSeq_for_Uint16_t *, AnalogOutputInt16*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group41Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group41Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputInt16 collection = CreateBufferedCollection_Indexed_for_AnalogOutputInt16_static(
        buffer,
        count,
        readInvokeCountOf_Group41Var2_for_AnalogOutputInt16_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputInt16));
}
//------------------------------------------Group41Var2------------------------------------------------
//------------------------------------------Group41Var3------------------------------------------------
CountIndexParser From_for_Group41Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group41Var3_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group41Var3_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group41Var3_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputFloat32 readInvokeCountOf_Group41Var3_for_AnalogOutputFloat32_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputFloat32 readInvokeCountOf_Group41Var3_for_AnalogOutputFloat32_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputFloat32 pair;
  Indexed_for_AnalogOutputFloat32_in_Indexed_for_AnalogOutputFloat32Over1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group41Var3_static(RSeq_for_Uint16_t *, AnalogOutputFloat32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group41Var3_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group41Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputFloat32 collection = CreateBufferedCollection_Indexed_for_AnalogOutputFloat32_static(
        buffer,
        count,
        readInvokeCountOf_Group41Var3_for_AnalogOutputFloat32_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputFloat32));
}
//------------------------------------------Group41Var3------------------------------------------------
//------------------------------------------Group42Var1------------------------------------------------
CountIndexParser From_for_Group42Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group42Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group42Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group42Var1_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var1_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var1_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputStatus pair;
  Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group42Var1_static(RSeq_for_Uint16_t *, AnalogOutputFloat32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group42Var1_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group42Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_Group42Var1_for_AnalogOutputStatus_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}
//------------------------------------------Group42Var1------------------------------------------------
//------------------------------------------Group42Var2------------------------------------------------
CountIndexParser From_for_Group42Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group42Var2_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group42Var2_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group42Var2_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var2_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var2_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputStatus pair;
  Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group42Var2_static(RSeq_for_Uint16_t *, AnalogOutputFloat32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group42Var2_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group42Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_Group42Var2_for_AnalogOutputStatus_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}
//------------------------------------------Group42Var2------------------------------------------------
//------------------------------------------Group42Var3------------------------------------------------
CountIndexParser From_for_Group42Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group42Var3_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group42Var3_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group42Var3_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var3_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var3_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputStatus pair;
  Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group42Var3_static(RSeq_for_Uint16_t *, AnalogOutputFloat32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group42Var3_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group42Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_Group42Var3_for_AnalogOutputStatus_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}
//------------------------------------------Group42Var3------------------------------------------------
//------------------------------------------Group42Var4------------------------------------------------
CountIndexParser From_for_Group42Var4_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group42Var4_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group42Var4_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group42Var4_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var4_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var4_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputStatus pair;
  Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group42Var4_static(RSeq_for_Uint16_t *, AnalogOutputFloat32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group42Var4_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group42Var4_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_Group42Var4_for_AnalogOutputStatus_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}
//------------------------------------------Group42Var4------------------------------------------------
//------------------------------------------Group42Var5------------------------------------------------
CountIndexParser From_for_Group42Var5_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group42Var5_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group42Var5_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group42Var5_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var5_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var5_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputStatus pair;
  Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group42Var5_static(RSeq_for_Uint16_t *, AnalogOutputFloat32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group42Var5_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group42Var5_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_Group42Var5_for_AnalogOutputStatus_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}
//------------------------------------------Group42Var5------------------------------------------------
//------------------------------------------Group42Var7------------------------------------------------
CountIndexParser From_for_Group42Var7_in_CountIndexParser_static(uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group42Var7_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint32_t SIZE = count * (Size_in_Group42Var7_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, InvokeCountOf_for_Group42Var7_in_CountIndexParser_static);
  return cCountIndexParser;
}

////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var7_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Indexed_for_AnalogOutputStatus readInvokeCountOf_Group42Var7_for_AnalogOutputStatus_in_CountIndexParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
UNUSED(pos);

  NumParser *numparser = (NumParser *)pPointerGlobal1_in_ParseCountOfIndices;

////        Indexed<typename Descriptor::Target> pair;
  Indexed_for_AnalogOutputStatus pair;
  Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(&pair);

//uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser(numparser, buffer);
//boolean ReadTarget_in_Group42Var7_static(RSeq_for_Uint16_t *, AnalogOutputFloat32*);
////        Descriptor::ReadTarget(buffer, pair.value);
  ReadTarget_in_Group42Var7_static(buffer, &pair.value);
  return pair;
}

void InvokeCountOf_for_Group42Var7_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };

////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
  pPointerGlobal1_in_ParseCountOfIndices = numparser;
  BufferedCollection_Indexed_for_AnalogOutputStatus collection = CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
        buffer,
        count,
        readInvokeCountOf_Group42Var7_for_AnalogOutputStatus_in_CountIndexParser);

//void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
//  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler(handler, &pPrefixHeader, &(collection.iICollection_Indexed_for_AnalogOutputStatus));
}
//------------------------------------------Group42Var7------------------------------------------------
