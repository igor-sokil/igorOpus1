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
#include <iostream>
#include "header.h"
#include "CountParser.h"

////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////CountParser::CountParser(uint16_t count, size_t required_size, HandleFun handler)
void  CountParser_in_CountParser(CountParser *pCountParser, uint16_t count, uint16_t required_size, HandleFun_in_CountParser handler)
{
////  : count(count), required_size(required_size), handler(handler)
  pCountParser->count = count;
  pCountParser->required_size = required_size;
  pCountParser->handler = handler;
}

////ParseResult CountParser::Process(const HeaderRecord& record,
////                                 ser4cpp::rseq_t& buffer,
////                                 IAPDUHandler* pHandler,
////                                 Logger* pLogger) const
ParseResult_uint8_t Process_in_CountParser(CountParser *pCountParser, HeaderRecord* record,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* pHandler)
{
////  if (buffer.length() < required_size)
  if(length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < pCountParser->required_size)
  {
////    SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified objects");
    std::cout<<"SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for specified objects')"<<std::endl;
    return ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS;
  }

  if (pHandler)
  {
    pCountParser->handler(record, pCountParser->count, buffer, *pHandler);
  }
////  buffer.advance(required_size);
////  return ParseResult::OK;
//    void advance_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
  advance_in_RSeq_for_Uint16_t(buffer, pCountParser->required_size);
  return ParseResult_OK;
}

////ParseResult CountParser::ParseHeader(ser4cpp::rseq_t& buffer,
////                                     const NumParser& numParser,
////                                     const ParserSettings& settings,
////                                     const HeaderRecord& record,
////                                     Logger* pLogger,
////                                     IAPDUHandler* pHandler)
ParseResult_uint8_t ParseHeader_in_CountParser_static(RSeq_for_Uint16_t* buffer,
    NumParser* numparser,
    ////const ParserSettings& settings,
    HeaderRecord* record,
    ////Logger* pLogger,
    IAPDUHandler* pHandler)
{
  uint16_t count;
//ParseResult_uint8_t ParseCount_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer, uint16_t *count);////, Logger* pLogger) const;
////  auto result = numParser.ParseCount(buffer, count, pLogger);
  ParseResult_uint8_t result = ParseCount_in_NumParser(numparser, buffer, &count);////, Logger* pLogger) const;

  if (result == ParseResult_OK)
  {
////    FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u %s, %s [%u]", record.group, record.variation,
////                        GroupVariationSpec::to_human_string(record.enumeration),
////                        QualifierCodeSpec::to_human_string(record.GetQualifierCode()), count);
    std::cout<<"FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u]', record.group, record.variation"
             <<std::endl;

////    if (settings.ExpectsContents())
////    {
////      return ParseCountOfObjects(buffer, record, count, pLogger, pHandler);
////    }

////    if (pHandler)
////    {
////      pHandler->OnHeader(CountHeader(record, count));
////    }

    return ParseResult_OK;
  }
  else
  {
    return result;
  }
}
/*
ParseResult CountParser::ParseCountOfObjects(
  ser4cpp::rseq_t& buffer, const HeaderRecord& record, uint16_t count, Logger* pLogger, IAPDUHandler* pHandler)
{
  switch (record.enumeration)
  {
  case (GroupVariation::Group50Var1):
    return CountParser::From<Group50Var1>(count).Process(record, buffer, pHandler, pLogger);

  case (GroupVariation::Group50Var3):
    return CountParser::From<Group50Var3>(count).Process(record, buffer, pHandler, pLogger);

  case (GroupVariation::Group51Var1):
    return CountParser::From<Group51Var1>(count).Process(record, buffer, pHandler, pLogger);

  case (GroupVariation::Group51Var2):
    return CountParser::From<Group51Var2>(count).Process(record, buffer, pHandler, pLogger);

  case (GroupVariation::Group52Var1):
    return CountParser::From<Group52Var1>(count).Process(record, buffer, pHandler, pLogger);

  case (GroupVariation::Group52Var2):
    return CountParser::From<Group52Var2>(count).Process(record, buffer, pHandler, pLogger);

  default:
    FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unsupported qualifier/object - %s - %i / %i",
                        QualifierCodeSpec::to_human_string(record.GetQualifierCode()), record.group,
                        record.variation);

    return ParseResult::INVALID_OBJECT_QUALIFIER;
  }
}
*/
////} // namespace opendnp3
