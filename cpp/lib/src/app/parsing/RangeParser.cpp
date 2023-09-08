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
#include <QtWidgets>
#include <iostream>
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

////namespace opendnp3
////{

////RangeParser::RangeParser(const Range& range, size_t requiredSize, HandleFun handler)
void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler)
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
  std::cout<<""<<std::endl;
  std::cout<<"ParseHeader_in_RangeParser_static1"<<std::endl;

  Range range;

//ParseResult_uint8_t ParseRange_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer, Range *range);////, Logger* pLogger) const;
////  auto res = numparser.ParseRange(buffer, range, pLogger);
  ParseResult_uint8_t res = ParseRange_in_NumParser(numparser, buffer, &range);////, Logger* pLogger) const;

  qDebug()<<"ParseResult_uint8_t res = ParseRange_in_NumParser"<<res;

  pMemory_HeaderRecord_1=  MEMORY_HeaderRecord_1(0, record);

  if (res != ParseResult_OK)
  {
    return res;
  }

////  FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u %s, %s [%u, %u]", record.group, record.variation,
////                      GroupVariationSpec::to_human_string(record.enumeration),
////                      QualifierCodeSpec::to_human_string(record.GetQualifierCode()), range.start, range.stop);
  std::cout<<"FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u, %u]', record.group, record.variation,"<<std::endl;

////  if (settings.ExpectsContents())
////  {
//ParseResult_uint8_t ParseRangeOfObjects_in_RangeParser_static(
//  RSeq_for_Uint16_t *buffer,
//  HeaderRecord *record,
//  Range *range,
//                                          Logger* pLogger,
//  IAPDUHandler* pHandler);
////    return ParseRangeOfObjects(buffer, record, range, pLogger, pHandler);
  return ParseRangeOfObjects_in_RangeParser_static(
           buffer,
           record,
           &range,
//                                          Logger* pLogger,
           pHandler);
////  }

////  if (pHandler)
////  {
//void RangeHeader_in_RangeHeader(RangeHeader *pRangeHeader, HeaderRecord *record, Range *range_);
//void OnHeader_RangeHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, RangeHeader* header);
////    pHandler->OnHeader(RangeHeader(record, range));
// RangeHeader rRangeHeader;
// RangeHeader_in_RangeHeader(&rRangeHeader, record, &range);
// OnHeader_RangeHeader_in_IAPDUHandler(pHandler, RangeHeader* header);
////  }
////  return ParseResult_OK;
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
  UNUSED(record);
qDebug()<<"(length_in_HasLength_for_Uint16_t(&(buffer->hHasLength))="<<hex<<(length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)));
qDebug()<<"buffer->buffer_[0]="<<hex<<buffer->buffer_[0];
qDebug()<<"buffer->buffer_[1]="<<hex<<buffer->buffer_[1];
qDebug()<<"buffer->buffer_[2]="<<hex<<buffer->buffer_[2];
qDebug()<<"pRangeParser->requiredSize="<<hex<<pRangeParser->requiredSize;

////  if (buffer.length() < requiredSize)
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < pRangeParser->requiredSize)
  {
////    SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified objects");
    std::cout<<"SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for specified objects')"<<std::endl;
    return ParseResult_NOT_ENOUGH_DATA_FOR_OBJECTS;
  }

  if (pHandler)
  {
////    handler(record, range, buffer, *pHandler);
  }
////  buffer.advance(requiredSize);
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
  switch (record->gGroupVariationRecord.enumeration)
  {
////  case (GroupVariation::Group1Var1):
////    return RangeParser::FromBitfieldType<Binary>(range).Process(record, buffer, pHandler, pLogger);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group1Var2);
  case (GroupVariation_Group1Var2):
  {
//RangeParser FromFixedSize_for_Group1Var2_in_RangeParser_static(Range* range)
//ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
//                                   HeaderRecord *record,
//                                   RSeq_for_Uint16_t *buffer,
//                                   IAPDUHandler* pHandler)
////        return RangeParser::FromFixedSize<descriptor>(range).Process(record, buffer, pHandler, pLogger);
    RangeParser temp = FromFixedSize_for_Group1Var2_in_RangeParser_static(range);
    return Process_in_RangeParser(&temp,
                                  record,
                                  buffer,
                                  pHandler);
  }

////  case (GroupVariation::Group3Var1):
////    return RangeParser::FromDoubleBitfieldType<DoubleBitBinary>(range).Process(record, buffer, pHandler, pLogger);
////  case (GroupVariation::Group10Var1):
////    return RangeParser::FromBitfieldType<BinaryOutputStatus>(range).Process(record, buffer, pHandler, pLogger);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group3Var2);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group10Var2);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var1);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var2);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var5);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group20Var6);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var1);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var2);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var5);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var6);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var9);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group21Var10);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var1);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var2);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var3);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var4);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var5);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group30Var6);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var1);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var2);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var3);
////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group40Var4);

////    MACRO_PARSE_OBJECTS_WITH_RANGE(Group50Var4);

////  case (GroupVariation::Group80Var1):
////    return RangeParser::FromBitfieldType<IINValue>(range).Process(record, buffer, pHandler, pLogger);

////  case (GroupVariation::Group110Var0):
////    return ParseRangeOfOctetData(buffer, record, range, pLogger, pHandler);

  default:
////    FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unsupported qualifier/object - %s - %i / %i",
////                        QualifierCodeSpec::to_human_string(record.GetQualifierCode()), record.group,
////                        record.variation);
    std::cout<<"FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unsupported qualifier/object - %s - %i / %i'"<<std::endl;

    return ParseResult_INVALID_OBJECT_QUALIFIER;
  }
}
/*
ParseResult RangeParser::ParseRangeOfOctetData(
  ser4cpp::rseq_t& buffer, const HeaderRecord& record, const Range& range, Logger* pLogger, IAPDUHandler* pHandler)
{
  if (record.variation > 0)
  {
    const auto COUNT = range.Count();
    auto size = record.variation * COUNT;
    if (buffer.length() < size)
    {
      SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for specified octet objects");
      return ParseResult::NOT_ENOUGH_DATA_FOR_OBJECTS;
    }

    if (pHandler)
    {
      auto read = [range, record](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<OctetString> {
        const auto octetData = buffer.take(record.variation);
        OctetString octets(Buffer(octetData, octetData.length()));
        buffer.advance(record.variation);
        return WithIndex(octets, range.start + pos);
      };

      auto collection = CreateBufferedCollection<Indexed<OctetString>>(buffer, COUNT, read);

      pHandler->OnHeader(RangeHeader(record, range), collection);
    }

    buffer.advance(size);
    return ParseResult::OK;
  }
  else
  {
    SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Octet string variation 0 may only be used in requests");
    return ParseResult::INVALID_OBJECT;
  }
}
*/

////} // namespace opendnp3


void InvokeRangeOf_for_Group1Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
  UNUSED(buffer);
//uint16_t Count_in_Range(Range *pRange);
////    const auto COUNT = range.Count();
//uint16_t COUNT = Count_in_Range(range);

//Indexed_for_Group1Var2 WithIndex_in_Indexed_for_Group1Var2(
//  Group1Var2* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////        typename Descriptor::Target target;
////        Descriptor::ReadTarget(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };

//BufferedCollection_Indexed_for_Group1Var2 CreateBufferedCollection_Indexed_for_Group1Var2_static(
//  RSeq_for_Uint16_t* buffer,
//  uint16_t count,
//  ReadFunc_Indexed_for_Group1Var2 readFunc);
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, COUNT, read);

//BufferedCollection_Indexed_for_Group1Var2 collection = CreateBufferedCollection_Indexed_for_Group1Var2_static(
//  buffer,
//  COUNT,
//  read_for_Group1Var2_in_RangeParser);

////    handler.OnHeader(RangeHeader(record, range), collection);
  RangeHeader rRangeHeader;
  RangeHeader_in_RangeHeader(&rRangeHeader, record, range);
  OnHeader_RangeHeader_in_IAPDUHandler(handler, &rRangeHeader);
}

RangeParser FromFixedSize_for_Group1Var2_in_RangeParser_static(Range* range)
{
//uint16_t Count_in_Range(Range *pRange);
//uint16_t Size_in_Group1Var2_static(void);
//void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint16_t requiredSize, HandleFun_in_RangeParser handler);
////    const auto size = range.Count() * Descriptor::Size();
  uint16_t size = Count_in_Range(range) * Size_in_Group1Var2_static();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
  RangeParser rRangeParser;
  RangeParser_in_RangeParser(&rRangeParser, range, size, NULL);//HandleFun_in_RangeParser handler);
  return rRangeParser;
}
