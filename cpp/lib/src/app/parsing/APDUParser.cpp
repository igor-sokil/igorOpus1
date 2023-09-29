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
////#include "APDUParser.h"

////#include "app/GroupVariationRecord.h"
////#include "app/MeasurementFactory.h"
////#include "app/parsing/CountIndexParser.h"
////#include "app/parsing/CountParser.h"
////#include "app/parsing/ObjectHeaderParser.h"
////#include "app/parsing/RangeParser.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/gen/QualifierCode.h"
////#include "opendnp3/logging/LogLevels.h"
#include <QtWidgets>
#include <iostream>
#include "header.h"
#include "APDUParser.h"

#include "GroupVariationRecord.h"
#include "MeasurementFactory.h"
//#include "CountIndexParser.h"
#include "CountParser.h"
#include "ObjectHeaderParser.h"
#include "RangeParser.h"
//#include "ing/LogMacros.h"

#include "QualifierCode.h"
//#include "opendnp3/logging/LogLevels.h"
#include <string.h>

////namespace opendnp3
////{

//ParseResult_uint8_t Parse_in_APDUParser_static(
//                              RSeq_for_Uint16_t *buffer,
//                              IAPDUHandler *handler)
//                              Logger& logger,
//                              ParserSettings settings)
//{
//    return Parse(buffer, handler, &logger, settings);
//}

ParseResult_uint8_t Parse_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
  IAPDUHandler *handler)
//                              Logger* pLogger,
//                              ParserSettings settings)
{
std::cout<<""<<std::endl;
std::cout<<"Parse_in_APDUParser_static1"<<std::endl;

  inspect_RSeq(buffer);
//ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(
//  RSeq_for_Uint16_t *buffer,
//  IAPDUHandler* pHandler,
//  IWhiteList* pWhiteList);
  // do two state parsing process with logging and white-listing first but no handling on the first pass
// выполняем два процесса анализа состояний: сначала ведем журналирование и вносим в белый список, но не обрабатываем на первом проходе
////    auto result = ParseSinglePass(buffer, pLogger, nullptr, &handler, settings);
  ParseResult_uint8_t result = ParseSinglePass_in_APDUParser_static(
                                 buffer,
//                                       Logger* pLogger,
                                 NULL,
                                 &(handler->iIWhiteList));
//                                       const ParserSettings& settings);

std::cout<<"Parse_in_APDUParser_static2"<<std::endl;
std::cout<<"*ParseResult_uint8_t result ="<<(uint16_t)result<<std::endl;

  // if the first pass was successful, do a 2nd pass with the handler but no logging or white-list
// если первый проход был успешным, делаем второй проход с обработчиком, но без ведения журнала или белого списка
////    return (result == ParseResult::OK) ? ParseSinglePass(buffer, nullptr, &handler, nullptr, settings) : result;
  return (result == ParseResult_OK) ? ParseSinglePass_in_APDUParser_static(buffer, handler, NULL) : result;
}

ParseResult_uint8_t ParseAndLogAll_in_APDUParser_static(RSeq_for_Uint16_t *buffer)//, Logger* pLogger, ParserSettings settings)
{
////    return ParseSinglePass(buffer, pLogger, nullptr, nullptr, settings);
  return ParseSinglePass_in_APDUParser_static(buffer, /*pLogger,*/ NULL, NULL);//, settings);
}

ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
  //Logger* pLogger,
  IAPDUHandler* pHandler,
  IWhiteList* pWhiteList)
//const ParserSettings& settings)
{
std::cout<<""<<std::endl;
std::cout<<"ParseSinglePass_in_APDUParser_static1"<<std::endl;
std::cout<<"*IAPDUHandler* pHandler="<<(uint32_t)pHandler<<std::endl;
std::cout<<"*IWhiteList* pWhiteList="<<(uint32_t)pWhiteList<<std::endl;

  inspect_RSeq(buffer);

  uint32_t count = 0;
  RSeq_for_Uint16_t copy = *buffer;

//    RSeq_for_Uint16_t copy(buffer);
//    while (copy.length() > 0)

  while (length_in_HasLength_for_Uint16_t(&(copy.hHasLength)) > 0)
  {

std::cout<<"ParseSinglePass_in_APDUParser_static2"<<std::endl;
    inspect_RSeq(&copy);

    ParseResult_uint8_t result = ParseHeader_in_APDUParser_static(&copy, /*pLogger,*/ count, /*settings,*/ pHandler, pWhiteList);

std::cout<<"ParseSinglePass_in_APDUParser_static3"<<std::endl;
std::cout<<"*ParseResult_uint8_t result ="<<(uint16_t)result<<std::endl;

    ++count;

    if (result != ParseResult_OK)
    {
      return result;
    }
  }
  return ParseResult_OK;
}

ParseResult_uint8_t ParseHeader_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
//                                    Logger* pLogger,
  uint32_t count,
//                                    const ParserSettings& settings,
  IAPDUHandler* pHandler,
  IWhiteList* pWhiteList)
{
std::cout<<""<<std::endl;
std::cout<<"ParseHeader_in_APDUParser_static1"<<std::endl;
inspect_RSeq(buffer);

  ObjectHeader header;
//    ParseResult_uint8_t ParseObjectHeader_in_ObjectHeaderParser_static(ObjectHeader *header, RSeq_for_Uint16_t *buffer);////, Logger* pLogger);
  ParseResult_uint8_t result = ParseObjectHeader_in_ObjectHeaderParser_static(&header, buffer);//, pLogger);

//pMemory_ObjectHeader_1=  MEMORY_ObjectHeader_1(0, &header);

  if (result != ParseResult_OK)
  {
    return result;
  }

std::cout<<"ParseHeader_in_APDUParser_static2"<<std::endl;
  GroupVariationRecord GV = GetRecord_in_GroupVariationRecord_static(header.group, header.variation);

//pMemory_GroupVariationRecord_1=  MEMORY_GroupVariationRecord_1(0, &GV);

  if (GV.enumeration == GroupVariation_UNKNOWN)
  {
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unknown object %i / %i", GV.group, GV.variation);
    std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unknown object %i / %i', GV.group, GV.variation)***"<<(uint16_t)GV.group<<","<< (uint16_t)GV.variation<<std::endl;
    return ParseResult_UNKNOWN_OBJECT;
  }

  // if a white-list is defined and it doesn't validate, exit early
// если белый список определен и не проходит проверку, выходим раньше
////    if (pWhiteList && !pWhiteList->IsAllowed(count, GV.enumeration, QualifierCodeSpec::from_type(header.qualifier)))
std::cout<<"ParseHeader_in_APDUParser_static3"<<std::endl;
  if(pWhiteList && !IsAllowed_in_IWhiteList(pWhiteList, count, GV.enumeration, from_type_in_QualifierCodeSpec_static(header.qualifier)))//from_type_in_QualifierCodeSpec(header.qualifier)))
  {
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Header (%i) w/ Object (%i,%i) and qualifier (%i) failed whitelist",
////                            count, header.group, header.variation, header.qualifier);
    std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Header (%i) w/ Object (%i,%i) and qualifier (%i) failed whitelist, count, header.group, header.variation, header.qualifier)'***"
               <<count<< (uint16_t)header.group<<","<< (uint16_t)header.variation<<","<< (uint16_t)header.qualifier<<std::endl;

    return ParseResult_NOT_ON_WHITELIST;
  }

  HeaderRecord hHeaderRecord;
  HeaderRecord_in_HeaderRecordOver2(&hHeaderRecord,
                                    &GV,
                                    header.qualifier, count);
std::cout<<"ParseHeader_in_APDUParser_static4"<<std::endl;
  return  ParseQualifier_in_APDUParser_static(buffer, /*pLogger,*/ &hHeaderRecord/*HeaderRecord(GV, header.qualifier, count)*/, /*settings,*/ pHandler);
}

ParseResult_uint8_t ParseQualifier_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
//                                       Logger* pLogger,
  HeaderRecord *record,
//                                       const ParserSettings& settings,
  IAPDUHandler* pHandler)
{
  std::cout<<""<<std::endl;
  std::cout<<"ParseQualifier_in_APDUParser_static1"<<std::endl;

  std::cout<<"IAPDUHandler* pHandler= "<<(uint32_t)pHandler<<std::endl;

//QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
QualifierCode_uint8_t tmp = GetQualifierCode_in_HeaderRecord(record);
  std::cout<<"QualifierCode_uint8_t tmp ="<<(uint16_t)tmp<<std::endl;

  switch (tmp)//(GetQualifierCode_in_HeaderRecord(record))////record.GetQualifierCode())
  {
  case (QualifierCode_ALL_OBJECTS):
    std::cout<<"*QualifierCode_ALL_OBJECTS*"<<std::endl;
    return HandleAllObjectsHeader_in_APDUParser_static(/*pLogger,*/ record, /*settings,*/ pHandler);

//     ParseResult_uint8_t ParseHeader_in_CountParser_static(RSeq_for_Uint16_t* buffer,
//                                   NumParser* numparser,
  ////const ParserSettings& settings,
//                                   HeaderRecord* record,
  ////Logger* pLogger,
//                                   IAPDUHandler* pHandler);
    case (QualifierCode_UINT8_CNT):
{
    std::cout<<"*QualifierCode_UINT8_CNT*"<<std::endl;
    NumParser temp = OneByte_in_NumParser_static();
    return ParseHeader_in_CountParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
}

////    case (QualifierCode_UINT16_CNT):
////{
////NumParser temp = TwoByte_in_NumParser_static();
////        return ParseHeader_in_CountParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
////}

    case (QualifierCode_UINT8_START_STOP):
{
    std::cout<<"*QualifierCode_UINT8_START_STOP*"<<std::endl;
    NumParser temp = OneByte_in_NumParser_static();
    return ParseHeader_in_RangeParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
}

    case (QualifierCode_UINT16_START_STOP):
{
    std::cout<<"*QualifierCode_UINT16_START_STOP*"<<std::endl;
    NumParser temp = TwoByte_in_NumParser_static();
    return ParseHeader_in_RangeParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
}

////   case (QualifierCode_UINT8_CNT_UINT8_INDEX):
////{
////NumParser temp = OneByte_in_NumParser_static();
////      return ParseHeader_in_CountIndexParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
////}

////    case (QualifierCode_UINT16_CNT_UINT16_INDEX):
////{
////NumParser temp = TwoByte_in_NumParser_static();
////        return ParseHeader_in_CountIndexParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
////}

  default:
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unknown qualifier %x", record.qualifier);
    std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unknown qualifier %x', record.qualifier)***"
               <<std::endl;
    return ParseResult_UNKNOWN_QUALIFIER;
  }
}

ParseResult_uint8_t HandleAllObjectsHeader_in_APDUParser_static(//Logger* pLogger,
  HeaderRecord *record,
//                                               const ParserSettings& settings,
  IAPDUHandler* pHandler)
{
std::cout<<""<<std::endl;
std::cout<<"HandleAllObjectsHeader_in_APDUParser_static1"<<std::endl;

//pMemory_HeaderRecord_1=  MEMORY_HeaderRecord_1(0, record);

std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***"<<std::endl;
//qDebug()<<"record->gGroupVariationRecord.group="<<record->gGroupVariationRecord.group;
//qDebug()<<"record->gGroupVariationRecord.variation="<<record->gGroupVariationRecord.variation;
//qDebug()<<"record->gGroupVariationRecord.enumeration="<<record->gGroupVariationRecord.enumeration;

////    FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u - %s - %s", record.group, record.variation,
////                        GroupVariationSpec::to_human_string(record.enumeration),
////                        QualifierCodeSpec::to_human_string(QualifierCode::ALL_OBJECTS));

  if (pHandler)
  {
std::cout<<"HandleAllObjectsHeader_in_APDUParser_static2"<<std::endl;
    AllObjectsHeader aAllObjectsHeader;
    AllObjectsHeader_in_AllObjectsHeader(&aAllObjectsHeader, record);
////        pHandler->OnHeader(AllObjectsHeader(record));
////        pHandler->OnHeader(&aAllObjectsHeader);//AllObjectsHeader(record));
    OnHeader_AllObjectsHeader_in_IAPDUHandler(pHandler, &aAllObjectsHeader);
  }

  return ParseResult_OK;
}

////} // namespace opendnp3
 