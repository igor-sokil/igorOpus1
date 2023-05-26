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
#ifndef OPENDNP3_GROUPVARIATIONRECORD_H
#define OPENDNP3_GROUPVARIATIONRECORD_H

////#include "app/Range.h"
////
////#include "opendnp3/gen/GroupVariation.h"
////#include "opendnp3/gen/QualifierCode.h"
////#include "opendnp3/gen/TimestampQuality.h"
////#include "opendnp3/util/Uncopyable.h"

////#include <cstdint>

#include "Range.h"

#include "GroupVariation.h"
#include "QualifierCode.h"
#include "TimestampQuality.h"
//#include "Uncopyable.h"

////namespace opendnp3
////{

////enum class GroupVariationType : int
#define GroupVariationType_int32_t int32_t
enum GroupVariationType 
{
    GroupVariationType_STATIC,
    GroupVariationType_EVENT,
    GroupVariationType_OTHER
};

////struct EnumAndType
typedef struct 
{
////    GroupVariation enumeration;
   GroupVariation_uint16_t    enumeration;
////    GroupVariationType type;
   GroupVariationType_int32_t type;
} EnumAndType;

   void EnumAndType_in_EnumAndType(EnumAndType *pEnumAndType,
                                   GroupVariation_uint16_t enumeration_, GroupVariationType_int32_t type_);

////class GroupVariationRecord
typedef struct 
{

////public:
////    static EnumAndType GetEnumAndType(uint8_t group, uint8_t variation);

////    static uint16_t GetGroupVar(uint8_t group, uint8_t variation);
////
////    static GroupVariationRecord GetRecord(uint8_t group, uint8_t variation);
////
////    static GroupVariationType GetType(uint8_t group, uint8_t variation);
////
////    GroupVariationRecord(uint8_t group_, uint8_t variation_, GroupVariation enumeration_, GroupVariationType type_);
////
////    GroupVariationRecord()
////        : enumeration(GroupVariation::UNKNOWN), type(GroupVariationType::OTHER), group(0), variation(0)
////    {
////    }

    GroupVariation_uint16_t enumeration;
    GroupVariationType_int32_t type;
    uint8_t group;
    uint8_t variation;
} GroupVariationRecord;

    EnumAndType GetEnumAndType_in_GroupVariationRecord_static(uint8_t group, uint8_t variation);

    uint16_t GetGroupVar_in_GroupVariationRecord_static(uint8_t group, uint8_t variation);

    GroupVariationRecord GetRecord_in_GroupVariationRecord_static(uint8_t group, uint8_t variation);

    GroupVariationType_int32_t GetType_in_GroupVariationRecord_static(uint8_t group, uint8_t variation);

    void GroupVariationRecord_in_GroupVariationRecordOver2(GroupVariationRecord *pGroupVariationRecord,
                                                           uint8_t group_, uint8_t variation_,
                                                           GroupVariation_uint16_t enumeration_, 
                                                           GroupVariationType_int32_t type_);
    void GroupVariationRecord_in_GroupVariationRecordOver1(GroupVariationRecord *pGroupVariationRecord);

////class HeaderRecord : public GroupVariationRecord
typedef struct
{
    GroupVariationRecord gGroupVariationRecord;
////public:
////    HeaderRecord() : qualifier(0), headerIndex(0) {}
////
////    HeaderRecord(const GroupVariationRecord& gv, uint8_t qualifier, uint32_t headerIndex);
////
////    QualifierCode GetQualifierCode() const;

    uint8_t qualifier;
    uint32_t headerIndex;
} HeaderRecord;

   void HeaderRecord_in_HeaderRecordOver1(HeaderRecord *pHeaderRecord);

   void HeaderRecord_in_HeaderRecordOver2(HeaderRecord *pHeaderRecord, 
                                          GroupVariationRecord *gv,
                                          uint8_t qualifier, uint32_t headerIndex);
////
   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);

// ---- Specific header types  ---

////class AllObjectsHeader : public HeaderRecord
typedef struct
{
  HeaderRecord hHeaderRecord;
////public:
////    explicit AllObjectsHeader(const HeaderRecord& record) : HeaderRecord(record) {}
} AllObjectsHeader;
  void AllObjectsHeader_in_AllObjectsHeader(AllObjectsHeader *pAllObjectsHeader, HeaderRecord *record);

////class CountHeader : public HeaderRecord
typedef struct
{
  HeaderRecord hHeaderRecord;
////public:
////    CountHeader(const HeaderRecord& record, uint16_t count_) : HeaderRecord(record), count(count_) {}

    uint16_t count;
} CountHeader;

   void CountHeader_in_CountHeader(CountHeader *pCountHeader, HeaderRecord *record, uint16_t count_);

////class FreeFormatHeader : public HeaderRecord
typedef struct
{
  HeaderRecord hHeaderRecord;
////public:
////    FreeFormatHeader(const HeaderRecord& record, uint16_t count_) : HeaderRecord(record), count(count_) {}

    uint16_t count;
} FreeFormatHeader;

   void FreeFormatHeader_in_FreeFormatHeader(FreeFormatHeader *pFreeFormatHeader, HeaderRecord *record, uint16_t count_);

////class RangeHeader : public HeaderRecord
typedef struct
{
  HeaderRecord hHeaderRecord;
////public:
////    RangeHeader(const HeaderRecord& record, const Range& range_) : HeaderRecord(record), range(range_) {}

    Range range;
} RangeHeader;

  void RangeHeader_in_RangeHeader(RangeHeader *pRangeHeader, HeaderRecord *record, Range *range_);

////class PrefixHeader : public HeaderRecord
typedef struct
{
  HeaderRecord hHeaderRecord;
////public:
////    PrefixHeader(const HeaderRecord& record, uint16_t count_) : HeaderRecord(record), count(count_) {}

    uint16_t count;
} PrefixHeader;

  void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);

////} // namespace opendnp3

#endif
