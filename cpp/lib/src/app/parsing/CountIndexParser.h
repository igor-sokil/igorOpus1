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
#ifndef OPENDNP3_COUNTINDEXPARSER_H
#define OPENDNP3_COUNTINDEXPARSER_H

////#include "app/parsing/BufferedCollection.h"
////#include "app/parsing/IAPDUHandler.h"
////#include "app/parsing/NumParser.h"
////#include "app/parsing/ParseResult.h"
////#include "app/parsing/ParserSettings.h"
////
////#include "opendnp3/logging/Logger.h"

////#include <ser4cpp/container/SequenceTypes.h>

//#include "BufferedCollection.h"
#include "IAPDUHandler.h"
#include "NumParser.h"
#include "ParseResult.h"
//#include "ParserSettings.h"

//#include "opendnp3/logging/Logger.h"

//#include <ser4cpp/container/SequenceTypes.h>
#include "RSeq.h"
//#include "WSeq.h"

////namespace opendnp3
////{

typedef void (*HandleFun_in_CountIndexParser)(
  HeaderRecord *record,
  uint16_t count,
  NumParser *numparser,
  RSeq_for_Uint16_t *buffer,
  IAPDUHandler *handler);

////class CountIndexParser
typedef struct
{

////public:
////    static ParseResult ParseHeader(ser4cpp::rseq_t& buffer,
////                                   const NumParser& numparser,
////                                   const ParserSettings& settings,
////                                   const HeaderRecord& record,
////                                   Logger* pLogger,
////                                   IAPDUHandler* pHandler);
////
////private:
////    // Process the count handler against the buffer
////    ParseResult Process(const HeaderRecord& record,
////                        ser4cpp::rseq_t& buffer,
////                        IAPDUHandler* pHandler,
////                        Logger* pLogger) const;
////
////    // Create a count handler from a fixed size descriptor
////    template<class Descriptor> static CountIndexParser From(uint16_t count, const NumParser& numparser);
////
////    // Create a count handler from a fixed size descriptor
////    template<class Type> static CountIndexParser FromType(uint16_t count, const NumParser& numparser);
////
////    static ParseResult ParseCountOfObjects(ser4cpp::rseq_t& buffer,
////                                           const HeaderRecord& record,
////                                           const NumParser& numparser,
////                                           uint16_t count,
////                                           Logger* pLogger,
////                                           IAPDUHandler* pHandler);
////
////    static ParseResult ParseCountOfIndices(ser4cpp::rseq_t& buffer,
////                                           const HeaderRecord& record,
////                                           const NumParser& numparser,
////                                           uint16_t count,
////                                           Logger* pLogger,
////                                           IAPDUHandler* pHandler);
////
////    static ParseResult ParseIndexPrefixedOctetData(ser4cpp::rseq_t& buffer,
////                                                   const HeaderRecord& record,
////                                                   const NumParser& numParser,
////                                                   uint32_t count,
////                                                   Logger* pLogger,
////                                                   IAPDUHandler* pHandler);
////
////    template<class Descriptor>
////    static void InvokeCountOf(const HeaderRecord& record,
////                              uint16_t count,
////                              const NumParser& numparser,
////                              const ser4cpp::rseq_t& buffer,
////                              IAPDUHandler& handler);
////
////    template<class Type>
////    static void InvokeCountOfType(const HeaderRecord& record,
////                                  uint16_t count,
////                                  const NumParser& numparser,
////                                  const ser4cpp::rseq_t& buffer,
////                                  IAPDUHandler& handler);
////
////    CountIndexParser(uint16_t count, size_t requiredSize, const NumParser& numparser, HandleFun handler);

  uint16_t count;
  uint32_t requiredSize;
  NumParser numparser;
  HandleFun_in_CountIndexParser handler;

////    CountIndexParser() = delete;
} CountIndexParser;

void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint32_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);

//------------------------------------------Group2Var1------------------------------------------------

CountIndexParser From_for_Group2Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group2Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);

//------------------------------------------Group2Var1------------------------------------------------
//------------------------------------------Group12Var1------------------------------------------------

CountIndexParser From_for_Group12Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group12Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);

//------------------------------------------Group12Var1------------------------------------------------
//------------------------------------------Group4Var1------------------------------------------------

CountIndexParser From_for_Group4Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group4Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//------------------------------------------Group4Var1------------------------------------------------
//------------------------------------------Group4Var3------------------------------------------------

CountIndexParser From_for_Group4Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group4Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//------------------------------------------Group4Var3------------------------------------------------
//------------------------------------------Group13Var1------------------------------------------------

CountIndexParser From_for_Group13Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group13Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//------------------------------------------Group13Var1------------------------------------------------
//------------------------------------------Group13Var2------------------------------------------------

CountIndexParser From_for_Group13Var2_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group13Var2_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//------------------------------------------Group13Var2------------------------------------------------
//------------------------------------------Group43Var1------------------------------------------------

CountIndexParser From_for_Group43Var1_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group43Var1_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//------------------------------------------Group43Var1------------------------------------------------
//------------------------------------------Group43Var3------------------------------------------------

CountIndexParser From_for_Group43Var3_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group43Var3_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//------------------------------------------Group43Var3------------------------------------------------
//------------------------------------------Group50Var4------------------------------------------------

CountIndexParser From_for_Group50Var4_in_CountIndexParser_static(uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)

////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}

////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
void InvokeCountOf_for_Group50Var4_in_CountIndexParser_static(
  HeaderRecord* record,
  uint16_t count,
  NumParser* numparser,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//------------------------------------------Group50Var4------------------------------------------------

ParseResult_uint8_t ParseHeader_in_CountIndexParser_static(
  RSeq_for_Uint16_t *buffer,
  NumParser *numparser,
//                                   const ParserSettings& settings,
  HeaderRecord *record,
//                                   Logger* pLogger,
  IAPDUHandler* pHandler);

// Process the count handler against the buffer
ParseResult_uint8_t Process_in_CountIndexParser(CountIndexParser *pCountIndexParser,
    HeaderRecord *record,
    RSeq_for_Uint16_t *buffer,
    IAPDUHandler* pHandler);//,
//                        Logger* pLogger) const;

ParseResult_uint8_t ParseCountOfObjects_in_CountIndexParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  NumParser *numparser,
  uint16_t count,
//                                           Logger* pLogger,
  IAPDUHandler* pHandler);

ParseResult_uint8_t ParseCountOfIndices_in_CountIndexParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  NumParser *numparser,
  uint16_t count,
//                                           Logger* pLogger,
  IAPDUHandler* pHandler);

ParseResult_uint8_t ParseIndexPrefixedOctetData_in_CountIndexParser_static(
  RSeq_for_Uint16_t *buffer,
  HeaderRecord *record,
  NumParser *numParser,
  uint32_t count,
//                                                   Logger* pLogger,
  IAPDUHandler* pHandler);


////} // namespace opendnp3

#endif
