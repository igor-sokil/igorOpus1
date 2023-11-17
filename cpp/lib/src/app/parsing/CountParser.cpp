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
#include "CountParser.h"

////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"
//boolean expectsContents_in_CountParser = false;

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
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Process_in_CountParser1"<<std::endl;
#endif
////  if (buffer.length() < required_size)
  if(length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < pCountParser->required_size)
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
    pCountParser->handler(record, pCountParser->count, buffer, pHandler);
  }
////  buffer.advance(required_size);
////  return ParseResult::OK;
//    void advance_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
  advance_in_RSeq_for_Uint16_t(buffer, pCountParser->required_size);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
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
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseHeader_in_CountParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif
  uint16_t count;
//ParseResult_uint8_t ParseCount_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer, uint16_t *count);////, Logger* pLogger) const;
////  auto result = numParser.ParseCount(buffer, count, pLogger);
  ParseResult_uint8_t result = ParseCount_in_NumParser(numparser, buffer, &count);////, Logger* pLogger) const;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"ParseHeader_in_CountParser_static2"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ParseResult_uint8_t result ="<<(uint16_t)result<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t count ="<<(uint16_t)count<<std::endl;
#endif

  if (result == ParseResult_OK)
  {
////    FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u %s, %s [%u]", record.group, record.variation,
////                        GroupVariationSpec::to_human_string(record.enumeration),
////                        QualifierCodeSpec::to_human_string(record.GetQualifierCode()), count);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u %s, %s [%u]', record.group, record.variation"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*record.group= "<<(uint16_t)record->gGroupVariationRecord.group<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*record.variation= "<<(uint16_t)record->gGroupVariationRecord.variation<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*IAPDUHandler* pHandler ="<<(uint32_t)pHandler<<std::endl;
#endif

    if (expectsContents)//_in_CountParser)
    {
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
////      return ParseCountOfObjects(buffer, record, count, pLogger, pHandler);
      ParseResult_uint8_t temp = ParseCountOfObjects_in_CountParser_static(buffer, record, count, pHandler);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"ParseHeader_in_CountParser_static3"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ParseResult_uint8_t temp ="<<(uint16_t)temp<<std::endl;
#endif
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
      return temp;
    }

    if (pHandler)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"ParseHeader_in_CountParser_static4"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t count ="<<(uint16_t)count<<std::endl;
#endif
//void OnHeader_CountHeader_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header);
//void CountHeader_in_CountHeader(CountHeader *pCountHeader, HeaderRecord *record, uint16_t count_);
////      pHandler->OnHeader(CountHeader(record, count));
      CountHeader cCountHeader;
      CountHeader_in_CountHeader(&cCountHeader, record, count);
      OnHeader_CountHeader_in_IAPDUHandler(pHandler, &cCountHeader);
    }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
    return ParseResult_OK;
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
//  else
//  {
  return result;
//  }
}

////ParseResult CountParser::ParseCountOfObjects(
////  ser4cpp::rseq_t& buffer, const HeaderRecord& record, uint16_t count, Logger* pLogger, IAPDUHandler* pHandler)
ParseResult_uint8_t ParseCountOfObjects_in_CountParser_static(
  RSeq_for_Uint16_t* buffer, HeaderRecord* record, uint16_t count, /*Logger* pLogger,*/ IAPDUHandler* pHandler)
{
  switch (record->gGroupVariationRecord.enumeration)
  {
  case (GroupVariation_Group50Var1):
  {
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group50Var1"<<'\n';
    decrement_stack_info();
#endif
//ParseResult_uint8_t Process_in_CountParser(CountParser *pCountParser, HeaderRecord* record,
//    RSeq_for_Uint16_t* buffer,
//    IAPDUHandler* pHandler);
////    return CountParser::From<Group50Var1>(count).Process(record, buffer, pHandler, pLogger);
    CountParser temp = From_for_Group50Var1_in_CountParser_static(count);
    return Process_in_CountParser(&temp, record, buffer, pHandler);
  }

  case (GroupVariation_Group50Var3):
  {
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group50Var3"<<'\n';
    decrement_stack_info();
#endif
////    return CountParser::From<Group50Var3>(count).Process(record, buffer, pHandler, pLogger);
    CountParser temp = From_for_Group50Var3_in_CountParser_static(count);
    return Process_in_CountParser(&temp, record, buffer, pHandler);
  }

////  case (GroupVariation::Group51Var1):
////    return CountParser::From<Group51Var1>(count).Process(record, buffer, pHandler, pLogger);

////  case (GroupVariation::Group51Var2):
////    return CountParser::From<Group51Var2>(count).Process(record, buffer, pHandler, pLogger);

////  case (GroupVariation::Group52Var1):
////    return CountParser::From<Group52Var1>(count).Process(record, buffer, pHandler, pLogger);

////  case (GroupVariation::Group52Var2):
////    return CountParser::From<Group52Var2>(count).Process(record, buffer, pHandler, pLogger);

  default:
////    FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unsupported qualifier/object - %s - %i / %i",
////                        QualifierCodeSpec::to_human_string(record.GetQualifierCode()), record.group,
///                        record.variation);
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unsupported qualifier/object - %s - %i / %i',"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*record.group= "<<(uint16_t)record->gGroupVariationRecord.group<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*record.variation= "<<(uint16_t)record->gGroupVariationRecord.variation<<'\n';
    decrement_stack_info();
#endif

    return ParseResult_INVALID_OBJECT_QUALIFIER;
  }
}

////} // namespace opendnp3
//-------------------Group50Var1-----------------------------
CountParser From_for_Group50Var1_in_CountParser_static(uint16_t count)
{
////    const auto size = static_cast<size_t>(count) * Descriptor::Size();
//uint16_t Size_in_Group50Var1_static(void);
  uint32_t size = count * Size_in_Group50Var1_static();
//void  CountParser_in_CountParser(CountParser *pCountParser, uint16_t count, uint16_t required_size, HandleFun_in_CountParser handler);
////    return CountParser(count, size, &InvokeCountOf<Descriptor>);
  CountParser cCountParser;
  CountParser_in_CountParser(&cCountParser, count, size, InvokeCountOf_for_Group50Var1_in_CountParser_static);
  return cCountParser;
}

Group50Var1 read_Group50Var1_in_CountParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Group50Var1 read_Group50Var1_in_CountParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
  UNUSED(pos);
////        T value;
  Group50Var1 value;
  Group50Var1_in_Group50Var1(&value);
//boolean Read_in_Group50Var1_static(RSeq_for_Uint16_t *, Group50Var1*);
////        T::Read(buffer, value);
  Read_in_Group50Var1_static(buffer, &value);
  return value;
}
////template<class T>
////void CountParser::InvokeCountOf(const HeaderRecord& record,
////                                uint16_t count,
////                                const ser4cpp::rseq_t& buffer,
////                                IAPDUHandler& handler)
void InvokeCountOf_for_Group50Var1_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [](ser4cpp::rseq_t& buffer, uint32_t) -> T {
////        T value;
////        T::Read(buffer, value);
////        return value;
////    };

//BufferedCollection_Group50Var1 CreateBufferedCollection_Group50Var1_static(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t count,
//  ReadFunc_Group50Var1 readFunc);
////    auto collection = CreateBufferedCollection<T>(buffer, count, read);
  BufferedCollection_Group50Var1 collection = CreateBufferedCollection_Group50Var1_static(
        buffer,
        count,
        read_Group50Var1_in_CountParser);

//void OnHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values);
////    handler.OnHeader(CountHeader(record, count), collection);
  CountHeader cCountHeader;
  CountHeader_in_CountHeader(&cCountHeader, record, count);
  OnHeader_CountHeader_for_Group50Var1_in_IAPDUHandler(handler, &cCountHeader, &(collection.iICollection_for_Group50Var1));
}
//-------------------Group50Var1-----------------------------
//-------------------Group50Var3-----------------------------
CountParser From_for_Group50Var3_in_CountParser_static(uint16_t count)
{
////    const auto size = static_cast<size_t>(count) * Descriptor::Size();
//uint16_t Size_in_Group50Var3_static(void);
  uint32_t size = count * Size_in_Group50Var3_static();
//void  CountParser_in_CountParser(CountParser *pCountParser, uint16_t count, uint16_t required_size, HandleFun_in_CountParser handler);
////    return CountParser(count, size, &InvokeCountOf<Descriptor>);
  CountParser cCountParser;
  CountParser_in_CountParser(&cCountParser, count, size, InvokeCountOf_for_Group50Var3_in_CountParser_static);
  return cCountParser;
}

Group50Var3 read_Group50Var3_in_CountParser(RSeq_for_Uint16_t* buffer, uint32_t pos);
Group50Var3 read_Group50Var3_in_CountParser(RSeq_for_Uint16_t* buffer, uint32_t pos)
{
  UNUSED(pos);
////        T value;
  Group50Var3 value;
  Group50Var3_in_Group50Var3(&value);
//boolean Read_in_Group50Var3_static(RSeq_for_Uint16_t *, Group50Var3*);
////        T::Read(buffer, value);
  Read_in_Group50Var3_static(buffer, &value);
  return value;
}
////template<class T>
////void CountParser::InvokeCountOf(const HeaderRecord& record,
////                                uint16_t count,
////                                const ser4cpp::rseq_t& buffer,
////                                IAPDUHandler& handler)
void InvokeCountOf_for_Group50Var3_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler)
{
////    auto read = [](ser4cpp::rseq_t& buffer, uint32_t) -> T {
////        T value;
////        T::Read(buffer, value);
////        return value;
////    };

//BufferedCollection_Group50Var3 CreateBufferedCollection_Group50Var3_static(
//  RSeq_for_Uint16_t* buffer,
//  uint32_t count,
//  ReadFunc_Group50Var3 readFunc);
////    auto collection = CreateBufferedCollection<T>(buffer, count, read);
  BufferedCollection_Group50Var3 collection = CreateBufferedCollection_Group50Var3_static(
        buffer,
        count,
        read_Group50Var3_in_CountParser);

//void OnHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var3* values);
////    handler.OnHeader(CountHeader(record, count), collection);
  CountHeader cCountHeader;
  CountHeader_in_CountHeader(&cCountHeader, record, count);
  OnHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(handler, &cCountHeader, &(collection.iICollection_for_Group50Var3));
}
//-------------------Group50Var3-----------------------------
