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

////template<class Descriptor> RangeParser RangeParser::FromFixedSize(const Range& range)
RangeParser FromFixedSize_for_Group1Var2_in_RangeParser_static(Range* range);

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

void InvokeRangeOf_for_Group1Var2_in_RangeParser_static(HeaderRecord* record,
    Range* range,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);


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

////template<class Type> RangeParser RangeParser::FromDoubleBitfieldType(const Range& range)
////{
////    const auto size = NumBytesInDoubleBits(range.Count());
////    return RangeParser(range, size, &InvokeRangeDoubleBitfieldType<Type>);
////}
////
////template<class Type>
////void RangeParser::InvokeRangeDoubleBitfieldType(const HeaderRecord& record,
////                                                const Range& range,
////                                                const ser4cpp::rseq_t& buffer,
////                                                IAPDUHandler& handler)
////{
////    const auto COUNT = range.Count();

////    auto read = [range](ser4cpp::rseq_t& buffer, size_t pos) -> Indexed<Type> {
////        Type value(GetDoubleBit(buffer, pos));
////        return WithIndex(value, static_cast<uint16_t>(range.start + pos));
////    };
////
////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, COUNT, read);
////
////    handler.OnHeader(RangeHeader(record, range), collection);
////}
////
////} // namespace opendnp3

#endif
