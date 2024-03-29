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
#include "GroupVariationRecord.h"

////namespace opendnp3
////{

void GroupVariationRecord_in_GroupVariationRecordOver2(GroupVariationRecord *pGroupVariationRecord,
    uint8_t group_,
    uint8_t variation_,
    GroupVariation_uint16_t enumeration_,
    GroupVariationType_int32_t type_)
{
  pGroupVariationRecord->enumeration = enumeration_;
  pGroupVariationRecord->type = type_;
  pGroupVariationRecord->group = group_;
  pGroupVariationRecord->variation = variation_;
}

void HeaderRecord_in_HeaderRecordOver2(HeaderRecord *pHeaderRecord, GroupVariationRecord *gv, uint8_t qualifier_, uint32_t headerIndex_)
{
  pHeaderRecord->gGroupVariationRecord = *gv;
  pHeaderRecord->qualifier = qualifier_;
  pHeaderRecord->headerIndex = headerIndex_;
}

QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord)
{
////    return QualifierCodeSpec::from_type(qualifier);
  return from_type_in_QualifierCodeSpec_static(pHeaderRecord->qualifier);
}

GroupVariationRecord GetRecord_in_GroupVariationRecord_static(uint8_t group, uint8_t variation)
{
#ifdef  LOG_INFO
   std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
   std::cout<<"GetRecord_in_GroupVariationRecord_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
   std::cout<<"*uint8_t group= "<<(uint16_t)group<<std::endl;
  std::cout<<"*"<<getString_stack_info();
   std::cout<<"*uint8_t variation= "<<(uint16_t)variation<<std::endl;
#endif
  GroupVariationRecord gGroupVariationRecord;
  GroupVariationRecord_in_GroupVariationRecordOver1(&gGroupVariationRecord);

  EnumAndType pair = GetEnumAndType_in_GroupVariationRecord_static(group, variation);
  GroupVariationRecord_in_GroupVariationRecordOver2(&gGroupVariationRecord, group, variation, pair.enumeration, pair.type);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return gGroupVariationRecord;
}

uint16_t GetGroupVar_in_GroupVariationRecord_static(uint8_t group, uint8_t variation)
{
  return (group << 8) | variation;
}

EnumAndType GetEnumAndType_in_GroupVariationRecord_static(uint8_t group, uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"GetEnumAndType_in_GroupVariationRecord_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t group= "<<(uint16_t)group<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t variation= "<<(uint16_t)variation<<std::endl;
#endif

  GroupVariationType_int32_t type = GetType_in_GroupVariationRecord_static(group, variation);

////    auto enumeration = GroupVariationSpec::from_type(GetGroupVar(group, variation));
  GroupVariation_uint16_t enumeration = from_type_in_GroupVariationSpec_static(GetGroupVar_in_GroupVariationRecord_static(group, variation));
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_uint16_t enumeration= "<<std::hex<<(uint16_t)enumeration<<std::dec<<std::endl;
  decrement_stack_info();
#endif

  if (enumeration == GroupVariation_UNKNOWN)
  {
    switch (group)
    {
    case (110):
      enumeration = GroupVariation_Group110Var0;
      break;
    case (111):
      enumeration = GroupVariation_Group111Var0;
      break;
    case (112):
      enumeration = GroupVariation_Group112Var0;
      break;
    case (113):
      enumeration = GroupVariation_Group113Var0;
      break;
    default:
      break;
    }
  }

  EnumAndType eEnumAndType;
  EnumAndType_in_EnumAndType(&eEnumAndType, enumeration, type);
  return eEnumAndType;
}

GroupVariationType_int32_t GetType_in_GroupVariationRecord_static(uint8_t group, uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"GetType_in_GroupVariationRecord_static1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t group= "<<(uint16_t)group<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint8_t variation= "<<(uint16_t)variation<<std::endl;
#endif
  switch (group)
  {
  case (1):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (2):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (3):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (4):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (10):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (11):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (13):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (20):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (21):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (22):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (23):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (30):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (32):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (40):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (41):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (42):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (43):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (50):
    switch (variation)
    {
    case (4):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
      return GroupVariationType_STATIC;
    default:
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_OTHER"<<std::endl;
  decrement_stack_info();
#endif
      return GroupVariationType_OTHER;
    }

  case (60):
    switch (variation)
    {
    case (1):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
      return GroupVariationType_STATIC;
    default:
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
      return GroupVariationType_EVENT;
    }

  case (110):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;

  case (111):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  case (121):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_STATIC"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_STATIC;
  case (122):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_EVENT"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_EVENT;

  default:
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariationType_OTHER"<<std::endl;
  decrement_stack_info();
#endif
    return GroupVariationType_OTHER;
  }
}

////} // namespace opendnp3
void EnumAndType_in_EnumAndType(EnumAndType *pEnumAndType,
                                GroupVariation_uint16_t enumeration_, GroupVariationType_int32_t type_)
{
  pEnumAndType->enumeration = enumeration_;
  pEnumAndType->type = type_;
}
void GroupVariationRecord_in_GroupVariationRecordOver1(GroupVariationRecord *pGroupVariationRecord)
{
  pGroupVariationRecord->enumeration = GroupVariation_UNKNOWN;
  pGroupVariationRecord->type = GroupVariationType_OTHER;
  pGroupVariationRecord->group = 0;
  pGroupVariationRecord->variation = 0;
}

void HeaderRecord_in_HeaderRecordOver1(HeaderRecord *pHeaderRecord)
{
  GroupVariationRecord_in_GroupVariationRecordOver1(&(pHeaderRecord->gGroupVariationRecord));
  pHeaderRecord->qualifier = 0;
  pHeaderRecord->headerIndex = 0;
}

void AllObjectsHeader_in_AllObjectsHeader(AllObjectsHeader *pAllObjectsHeader, HeaderRecord *record)
{
  pAllObjectsHeader->hHeaderRecord = *record;
}

void CountHeader_in_CountHeader(CountHeader *pCountHeader, HeaderRecord *record, uint16_t count_)
{
  pCountHeader->hHeaderRecord = *record;
  pCountHeader->count = count_;
}

void FreeFormatHeader_in_FreeFormatHeader(FreeFormatHeader *pFreeFormatHeader, HeaderRecord *record, uint16_t count_)
{
  pFreeFormatHeader->hHeaderRecord = *record;
  pFreeFormatHeader->count = count_;
}

void RangeHeader_in_RangeHeader(RangeHeader *pRangeHeader, HeaderRecord *record, Range *range_)
{
  pRangeHeader->hHeaderRecord = *record;
  pRangeHeader->range = *range_;
}

void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_)
{
  pPrefixHeader->hHeaderRecord = *record;
  pPrefixHeader->count = count_;
}
