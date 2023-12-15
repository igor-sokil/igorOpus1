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
//#include <QtWidgets>
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "APDUParser.h"

#include "GroupVariationRecord.h"
#include "MeasurementFactory.h"
#include "CountIndexParser.h"
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
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"@@@@ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler)"<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"{Parse_in_APDUParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif

//ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(
//  RSeq_for_Uint16_t *buffer,
//  IAPDUHandler* pHandler,
//  IWhiteList* pWhiteList);
  // do two state parsing process with logging and white-listing first but no handling on the first pass
// ��������� ��� �������� ������� ���������: ������� ����� �������������� � ������ � ����� ������, �� �� ������������ �� ������ �������
////    auto result = ParseSinglePass(buffer, pLogger, nullptr, &handler, settings);
  ParseResult_uint8_t result = ParseSinglePass_in_APDUParser_static(
                                 buffer,
//                                       Logger* pLogger,
                                 NULL,
                                 &(handler->iIWhiteList));
//                                       const ParserSettings& settings);

  // if the first pass was successful, do a 2nd pass with the handler but no logging or white-list
// ���� ������ ������ ��� ��������, ������ ������ ������ � ������������, �� ��� ������� ������� ��� ������ ������
////    return (result == ParseResult::OK) ? ParseSinglePass(buffer, nullptr, &handler, nullptr, settings) : result;
  ParseResult_uint8_t tmp = (result == ParseResult_OK) ? ParseSinglePass_in_APDUParser_static(buffer, handler, NULL) : result;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Parse_in_APDUParser_static_"<<std::endl;
  decrement_stack_info();
#endif
  return tmp;
}

//ParseResult_uint8_t ParseAndLogAll_in_APDUParser_static(RSeq_for_Uint16_t *buffer)//, Logger* pLogger, ParserSettings settings)
//{
////    return ParseSinglePass(buffer, pLogger, nullptr, nullptr, settings);
//  return ParseSinglePass_in_APDUParser_static(buffer, /*pLogger,*/ NULL, NULL);//, settings);
//}

ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
  //Logger* pLogger,
  IAPDUHandler* pHandler,
  IWhiteList* pWhiteList)
//const ParserSettings& settings)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"@@@@ParseResult_uint8_t ParseSinglePass_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler* pHandler, IWhiteList* pWhiteList)"<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"{ParseSinglePass_in_APDUParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IAPDUHandler* pHandler="<<(uint32_t)pHandler<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IWhiteList* pWhiteList="<<(uint32_t)pWhiteList<<std::endl;
  inspect_RSeq(buffer);
#endif

  uint32_t count = 0;
  RSeq_for_Uint16_t copy = *buffer;

////    RSeq_for_Uint16_t copy(buffer);
////    while (copy.length() > 0)
  while (length_in_HasLength_for_Uint16_t(&(copy.hHasLength)) > 0)
  {

#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*copy"<<std::endl;
    inspect_RSeq(&copy);
#endif

    ParseResult_uint8_t result = ParseHeader_in_APDUParser_static(&copy, /*pLogger,*/ count, /*settings,*/ pHandler, pWhiteList);

    ++count;

    if (result != ParseResult_OK)
    {
#ifdef  LOG_INFO
      std::cout<<getString_stack_info();
      std::cout<<"}ParseSinglePass_in_APDUParser_static1_"<<std::endl;
      decrement_stack_info();
#endif
      return result;
    }
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ParseSinglePass_in_APDUParser_static2_"<<std::endl;
  decrement_stack_info();
#endif
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
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"@@@@ParseResult_uint8_t ParseHeader_in_APDUParser_static(RSeq_for_Uint16_t *buffer, uint32_t count, IAPDUHandler* pHandler, IWhiteList* pWhiteList)"<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"{ParseHeader_in_APDUParser_static1"<<std::endl;
  inspect_RSeq(buffer);
#endif

  ObjectHeader header;
//    ParseResult_uint8_t ParseObjectHeader_in_ObjectHeaderParser_static(ObjectHeader *header, RSeq_for_Uint16_t *buffer);////, Logger* pLogger);
  ParseResult_uint8_t result = ParseObjectHeader_in_ObjectHeaderParser_static(&header, buffer);//, pLogger);

  if (result != ParseResult_OK)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseHeader_in_APDUParser_static1_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t result= "<<(uint16_t)result<<std::endl;
    decrement_stack_info();
#endif
    return result;
  }

  GroupVariationRecord GV = GetRecord_in_GroupVariationRecord_static(header.group, header.variation);

  if (GV.enumeration == GroupVariation_UNKNOWN)
  {
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unknown object %i / %i", GV.group, GV.variation);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unknown object %i / %i', GV.group, GV.variation)***"<<(uint16_t)GV.group<<","<< (uint16_t)GV.variation<<std::endl;

    std::cout<<getString_stack_info();
    std::cout<<"}ParseHeader_in_APDUParser_static2_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*return ParseResult_UNKNOWN_OBJECT"<<std::endl;
    decrement_stack_info();
#endif
    return ParseResult_UNKNOWN_OBJECT;
  }

  // if a white-list is defined and it doesn't validate, exit early
// ���� ����� ������ ��������� � �� �������� ��������, ������� ������
////    if (pWhiteList && !pWhiteList->IsAllowed(count, GV.enumeration, QualifierCodeSpec::from_type(header.qualifier)))
  if(pWhiteList && !IsAllowed_in_IWhiteList(pWhiteList, count, GV.enumeration, from_type_in_QualifierCodeSpec_static(header.qualifier)))//from_type_in_QualifierCodeSpec(header.qualifier)))
  {
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Header (%i) w/ Object (%i,%i) and qualifier (%i) failed whitelist",
////                            count, header.group, header.variation, header.qualifier);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Header (%i) w/ Object (%i,%i) and qualifier (%i) failed whitelist, count, header.group, header.variation, header.qualifier)'***"
             <<count<< (uint16_t)header.group<<","<< (uint16_t)header.variation<<","<< (uint16_t)header.qualifier<<std::endl;

    std::cout<<getString_stack_info();
    std::cout<<"}ParseHeader_in_APDUParser_static3_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*return ParseResult_NOT_ON_WHITELIST"<<std::endl;
    decrement_stack_info();
#endif

    return ParseResult_NOT_ON_WHITELIST;
  }

  HeaderRecord hHeaderRecord;
  HeaderRecord_in_HeaderRecordOver2(&hHeaderRecord,
                                    &GV,
                                    header.qualifier, count);
  ParseResult_uint8_t tmp = ParseQualifier_in_APDUParser_static(buffer, /*pLogger,*/ &hHeaderRecord/*HeaderRecord(GV, header.qualifier, count)*/, /*settings,*/ pHandler);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ParseHeader_in_APDUParser_static4_"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
  decrement_stack_info();
#endif
  return tmp;
}

ParseResult_uint8_t ParseQualifier_in_APDUParser_static(
  RSeq_for_Uint16_t *buffer,
//                                       Logger* pLogger,
  HeaderRecord *record,
//                                       const ParserSettings& settings,
  IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"@@@@ParseResult_uint8_t ParseQualifier_in_APDUParser_static(RSeq_for_Uint16_t *buffer, HeaderRecord *record, IAPDUHandler* pHandler)"<<std::endl;
  std::cout<<getString_stack_info();
  std::cout<<"{ParseQualifier_in_APDUParser_static1"<<std::endl;
#endif

//QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
//  QualifierCode_uint8_t tmp = GetQualifierCode_in_HeaderRecord(record);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*QualifierCode_uint8_t tmp ="<<(uint16_t)GetQualifierCode_in_HeaderRecord(record)<<std::endl;
#endif

  switch (GetQualifierCode_in_HeaderRecord(record))////record.GetQualifierCode())
  {
  case (QualifierCode_ALL_OBJECTS):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*QualifierCode_ALL_OBJECTS*"<<std::endl;
#endif

    ParseResult_uint8_t tmp = HandleAllObjectsHeader_in_APDUParser_static(/*pLogger,*/ record, /*settings,*/ pHandler);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static1_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

//     ParseResult_uint8_t ParseHeader_in_CountParser_static(RSeq_for_Uint16_t* buffer,
//                                   NumParser* numparser,
  ////const ParserSettings& settings,
//                                   HeaderRecord* record,
  ////Logger* pLogger,
//                                   IAPDUHandler* pHandler);
  case (QualifierCode_UINT8_CNT):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*QualifierCode_UINT8_CNT*"<<std::endl;
#endif

    NumParser temp = OneByte_in_NumParser_static();
    ParseResult_uint8_t tmp = ParseHeader_in_CountParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static2_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  case (QualifierCode_UINT16_CNT):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*QualifierCode_UINT16_CNT*"<<std::endl;
#endif

    NumParser temp = TwoByte_in_NumParser_static();
    ParseResult_uint8_t tmp = ParseHeader_in_CountParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static3_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  case (QualifierCode_UINT8_START_STOP):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*QualifierCode_UINT8_START_STOP*"<<std::endl;
#endif
    NumParser temp = OneByte_in_NumParser_static();
    ParseResult_uint8_t tmp = ParseHeader_in_RangeParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static4_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  case (QualifierCode_UINT16_START_STOP):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*QualifierCode_UINT16_START_STOP*"<<std::endl;
#endif
    NumParser temp = TwoByte_in_NumParser_static();
    ParseResult_uint8_t tmp = ParseHeader_in_RangeParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static5_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  case (QualifierCode_UINT8_CNT_UINT8_INDEX):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*QualifierCode_UINT8_CNT_UINT8_INDEX*"<<std::endl;
#endif
    NumParser temp = OneByte_in_NumParser_static();
    ParseResult_uint8_t tmp = ParseHeader_in_CountIndexParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static6_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  case (QualifierCode_UINT16_CNT_UINT16_INDEX):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*QualifierCode_UINT16_CNT_UINT16_INDEX*"<<std::endl;
#endif
    NumParser temp = TwoByte_in_NumParser_static();
    ParseResult_uint8_t tmp = ParseHeader_in_CountIndexParser_static(buffer, &temp, /*settings,*/ record, /*pLogger,*/ pHandler);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static7_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*ParseResult_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  default:
////        FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "Unknown qualifier %x", record.qualifier);
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'Unknown qualifier %x', record.qualifier)***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}ParseQualifier_in_APDUParser_static8_"<<std::endl;
    decrement_stack_info();
#endif
    return ParseResult_UNKNOWN_QUALIFIER;
  }
}

ParseResult_uint8_t HandleAllObjectsHeader_in_APDUParser_static(//Logger* pLogger,
  HeaderRecord *record,
//                                               const ParserSettings& settings,
  IAPDUHandler* pHandler)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleAllObjectsHeader_in_APDUParser_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), '%03u,%03u - %s - %s', record.group, record.variation***"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record->gGroupVariationRecord.group="<<(uint16_t)record->gGroupVariationRecord.group<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record->gGroupVariationRecord.variation="<<(uint16_t)record->gGroupVariationRecord.variation<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*record->gGroupVariationRecord.enumeration="<<std::hex<<(uint16_t)record->gGroupVariationRecord.enumeration<<std::dec<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IAPDUHandler* pHandler="<<(uint32_t)pHandler<<std::endl;
#endif

////    FORMAT_LOGGER_BLOCK(pLogger, settings.LoggingLevel(), "%03u,%03u - %s - %s", record.group, record.variation,
////                        GroupVariationSpec::to_human_string(record.enumeration),
////                        QualifierCodeSpec::to_human_string(QualifierCode::ALL_OBJECTS));

  if (pHandler)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"HandleAllObjectsHeader_in_APDUParser_static2"<<std::endl;
#endif
    AllObjectsHeader aAllObjectsHeader;
    AllObjectsHeader_in_AllObjectsHeader(&aAllObjectsHeader, record);
////        pHandler->OnHeader(AllObjectsHeader(record));
////        pHandler->OnHeader(&aAllObjectsHeader);//AllObjectsHeader(record));
    OnHeader_AllObjectsHeader_in_IAPDUHandler(pHandler, &aAllObjectsHeader);
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return ParseResult_OK;
}

////} // namespace opendnp3
