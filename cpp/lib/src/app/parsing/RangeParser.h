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
#ifndef OPENDNP3_RANGEPARSER_H
#define OPENDNP3_RANGEPARSER_H

////#include "app/Range.h"
////#include "app/parsing/BitReader.h"
////#include "app/parsing/BufferedCollection.h"
////#include "app/parsing/IAPDUHandler.h"
////#include "app/parsing/NumParser.h"
////#include "app/parsing/ParseResult.h"
////#include "app/parsing/ParserSettings.h"

////#include "opendnp3/logging/Logger.h"

////#include <ser4cpp/container/SequenceTypes.h>

#include "Range.h"
#include "BitReader.h"
#include "BufferedCollection.h"
#include "IAPDUHandler.h"
#include "NumParser.h"
#include "ParseResult.h"
//#include "ParserSettings.h"

//#include "pendnp3/logging/Logger.h"

//#include <ser4cpp/container/SequenceTypes.h>
#include "RSeq.h"


////namespace opendnp3
////{

typedef void (*HandleFun_in_RangeParser)(
  HeaderRecord* record,
  Range* range,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);

////class RangeParser
typedef struct
{
////    typedef void (*HandleFun)(const HeaderRecord& record,
////                              const Range& range,
////                              const ser4cpp::rseq_t& buffer,
////                              IAPDUHandler& handler);

////public:
////    static ParseResult ParseHeader(ser4cpp::rseq_t& buffer,
////                                   const NumParser& numparser,
////                                   const ParserSettings& settings,
////                                   const HeaderRecord& record,
////                                   Logger* pLogger,
////                                   IAPDUHandler* pHandler);

////private:
  // Process the range against the buffer
////    ParseResult Process(const HeaderRecord& record,
////                        ser4cpp::rseq_t& buffer,
////                        IAPDUHandler* pHandler,
////                        Logger* pLogger) const;

  // Create a range parser from a fixed size descriptor
////    template<class Descriptor> static RangeParser FromFixedSize(const Range& range);

////    template<class Type> static RangeParser FromFixedSizeType(const Range& range);

  // Create a range parser from a bitfield and a function to map the bitfield to values
////    template<class Type> static RangeParser FromBitfieldType(const Range& range);

////    template<class Type> static RangeParser FromDoubleBitfieldType(const Range& range);

////    static ParseResult ParseRangeOfObjects(ser4cpp::rseq_t& buffer,
////                                           const HeaderRecord& record,
////                                           const Range& range,
////                                           Logger* pLogger,
////                                           IAPDUHandler* pHandler);

////    static ParseResult ParseRangeOfOctetData(ser4cpp::rseq_t& buffer,
////                                             const HeaderRecord& record,
////                                             const Range& range,
////                                             Logger* pLogger,
////                                             IAPDUHandler* pHandler);

////    template<class Descriptor>
////    static void InvokeRangeOf(const HeaderRecord& record,
////                              const Range& range,
////                              const ser4cpp::rseq_t& buffer,
////                              IAPDUHandler& handler);

////    template<class Type>
////    static void InvokeRangeOfType(const HeaderRecord& record,
////                                  const Range& range,
////                                  const ser4cpp::rseq_t& buffer,
////                                  IAPDUHandler& handler);

////    template<class Type>
////    static void InvokeRangeBitfieldType(const HeaderRecord& record,
////                                        const Range& range,
////                                        const ser4cpp::rseq_t& buffer,
////                                        IAPDUHandler& handler);

////    template<class Type>
////    static void InvokeRangeDoubleBitfieldType(const HeaderRecord& record,
////                                              const Range& range,
////                                              const ser4cpp::rseq_t& buffer,
////                                              IAPDUHandler& handler);

////    RangeParser(const Range& range, size_t requiredSize, HandleFun handler);

  Range range;
  uint32_t requiredSize;
//    HandleFun handler;
  HandleFun_in_RangeParser  handler;

////    RangeParser() = delete;
} RangeParser;

void RangeParser_in_RangeParser(RangeParser *pRangeParser, Range* range, uint32_t requiredSize, HandleFun_in_RangeParser handler);

ParseResult_uint8_t ParseHeader_in_RangeParser_static(
  RSeq_for_Uint16_t *buffer,
  NumParser *numparser,
//                                   ParserSettings *settings,
  HeaderRecord *record,
//                                   Logger* pLogger,
  IAPDUHandler* pHandler);

// Process the range against the buffer
ParseResult_uint8_t Process_in_RangeParser(RangeParser *pRangeParser,
    HeaderRecord *record,
    RSeq_for_Uint16_t *buffer,
    IAPDUHandler* pHandler);
//                       Logger* pLogger) const;


ParseResult_uint8_t ParseRangeOfObjects_in_RangeParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  Range *range,
//                                          Logger* pLogger,
  IAPDUHandler* pHandler);

ParseResult_uint8_t ParseRangeOfOctetData_in_RangeParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  Range *range,
//                                            Logger* pLogger,
  IAPDUHandler* pHandler);


ParseResult_uint8_t ParseHeader_in_RangeParser_static(
  RSeq_for_Uint16_t *buffer,
  NumParser* numparser,
//                                   const ParserSettings& settings,
  HeaderRecord* record,
//                                   Logger* pLogger,
  IAPDUHandler* pHandler);

////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
////{
////    const auto size = range.Count() * Descriptor::Size();
////    return RangeParser(range, size, &InvokeRangeOf<Descriptor>);
////}

////template<class Type> RangeParser RangeParser::FromFixedSizeType(const Range& range)
////{
////    const auto size = range.Count() * Type::Size();
////    return RangeParser(range, size, &InvokeRangeOfType<Type>);
////}

////template<class Descriptor>
////void RangeParser::InvokeRangeOf(const HeaderRecord& record,
////                                const Range& range,
////                                const ser4cpp::rseq_t& buffer,
////                                IAPDUHandler& handler)


//---------------------Group1Var2------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group1Var2_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group1Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group1Var2------------------------------------------------------
//---------------------Group3Var2------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group3Var2_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group3Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group3Var2------------------------------------------------------
//---------------------Group10Var2------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group10Var2_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group10Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group10Var2------------------------------------------------------
//---------------------Group20Var1------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group20Var1_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group20Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group20Var1------------------------------------------------------
//---------------------Group20Var2------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group20Var2_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group20Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group20Var2------------------------------------------------------
//---------------------Group20Var5------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group20Var5_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group20Var5_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group20Var5------------------------------------------------------
//---------------------Group20Var6------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group20Var6_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group20Var6_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group20Var6------------------------------------------------------
//---------------------Group21Var1------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group21Var1_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group21Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group21Var1------------------------------------------------------
//---------------------Group21Var2------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group21Var2_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group21Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group21Var2------------------------------------------------------
//---------------------Group21Var5------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group21Var5_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group21Var5_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group21Var5------------------------------------------------------
//---------------------Group21Var6------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group21Var6_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group21Var6_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group21Var6------------------------------------------------------
//---------------------Group21Var9------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group21Var9_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group21Var9_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group21Var9------------------------------------------------------
//---------------------Group21Var10------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group21Var10_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group21Var10_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group21Var10------------------------------------------------------
//---------------------Group30Var1------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group30Var1_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group30Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group30Var1------------------------------------------------------
//---------------------Group30Var2------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group30Var2_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group30Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group30Var2------------------------------------------------------
//---------------------Group30Var3------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group30Var3_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group30Var3_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group30Var3------------------------------------------------------
//---------------------Group30Var4------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group30Var4_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group30Var4_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group30Var4------------------------------------------------------
//---------------------Group30Var5------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group30Var5_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group30Var5_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group30Var5------------------------------------------------------

//---------------------Group40Var1------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group40Var1_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group40Var1_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group40Var1------------------------------------------------------
//---------------------Group40Var2------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group40Var2_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group40Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group40Var2------------------------------------------------------
//---------------------Group40Var3------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group40Var3_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group40Var3_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group40Var3------------------------------------------------------

//---------------------Group50Var4------------------------------------------------------
////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group50Var4_in_RangeParser_static(Range* range);

void InvokeRangeOf_for_Group50Var4_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);
//---------------------Group50Var4------------------------------------------------------

////template<class Type>
////void RangeParser::InvokeRangeOfType(const HeaderRecord& record,
////                                    const Range& range,
////                                    const ser4cpp::rseq_t& buffer,
////                                    IAPDUHandler& handler)
////{
////    const auto COUNT = range.Count();
////
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) -> Indexed<Type> {
////        Type target;
////        Type::Read(buffer, target);
////        return WithIndex(target, range.start + pos);
////    };
////
////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, COUNT, read);
////
////    handler.OnHeader(RangeHeader(record, range), collection);
////}
////
////template<class Type> RangeParser RangeParser::FromBitfieldType(const Range& range)
 RangeParser FromBitfieldType_Indexed_for_Binary_in_RangeParser_static(Range* range);
 RangeParser FromBitfieldType_Indexed_for_IINValue_in_RangeParser_static(Range* range);
 RangeParser FromBitfieldType_Indexed_for_BinaryOutputStatus_in_RangeParser_static(Range* range);

////template<class Type>
////void RangeParser::InvokeRangeBitfieldType(const HeaderRecord& record,
////                                          const Range& range,
////                                          const ser4cpp::rseq_t& buffer,
////                                          IAPDUHandler& handler)
//------------------------------Binary---------------------------------------------
void InvokeRangeBitfieldType_for_Binary_in_RangeParser_static(
                                          HeaderRecord* record,
                                          Range* range,
                                          RSeq_for_Uint16_t* buffer,
                                          IAPDUHandler* handler);
//------------------------------Binary---------------------------------------------
//------------------------------BinaryOutputStatus---------------------------------------------
void InvokeRangeBitfieldType_for_BinaryOutputStatus_in_RangeParser_static(
                                          HeaderRecord* record,
                                          Range* range,
                                          RSeq_for_Uint16_t* buffer,
                                          IAPDUHandler* handler);
//------------------------------BinaryOutputStatus---------------------------------------------
//------------------------------IINValue---------------------------------------------
void InvokeRangeBitfieldType_for_IINValue_in_RangeParser_static(
                                          HeaderRecord* record,
                                          Range* range,
                                          RSeq_for_Uint16_t* buffer,
                                          IAPDUHandler* handler);
//------------------------------IINValue---------------------------------------------

RangeParser FromDoubleBitfieldType_for_DoubleBitBinary_in_RangeParser_static(Range* range);

////template<class Type>
////void RangeParser::InvokeRangeDoubleBitfieldType(const HeaderRecord& record,
////                                                const Range& range,
////                                                const ser4cpp::rseq_t& buffer,
////                                                IAPDUHandler& handler)
void InvokeRangeDoubleBitfieldType_for_DoubleBitBinary_in_RangeParser_static(
                                                HeaderRecord* record,
                                                Range* range,
                                                RSeq_for_Uint16_t* buffer,
                                                IAPDUHandler* handler);


////} // namespace opendnp3

#endif
