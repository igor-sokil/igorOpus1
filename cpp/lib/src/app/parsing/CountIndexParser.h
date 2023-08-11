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

typedef void (*HandleFun_in_CountIndexParser)(HeaderRecord *record,
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
  uint16_t requiredSize;
  NumParser numparser;
  HandleFun_in_CountIndexParser handler;

////    CountIndexParser() = delete;
} CountIndexParser;
//------------------------------------------Group2Var1------------------------------------------------
CountIndexParser From_for_Group2Var1_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, NumParser* numparser);

////template<class Descriptor> CountIndexParser CountIndexParser::From(uint16_t count, const NumParser& numparser)
CountIndexParser From_for_Group2Var1_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, NumParser* numparser)
{
// uint16_t Size_in_Group2Var1_static(void);
//    uint8_t NumBytes_in_NumParser(NumParser *pNumParser);
////    const size_t SIZE = static_cast<size_t>(count) * (Descriptor::Size() + numparser.NumBytes());
  uint16_t SIZE = count * (Size_in_Group2Var1_static() + NumBytes_in_NumParser(numparser));
//    void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOf<Descriptor>);
  CountIndexParser cCountIndexParser;
  CountIndexParser_in_CountIndexParser(&cCountIndexParser, count, SIZE, numparser, HandleFun_in_CountIndexParser handler);
  return cCountIndexParser;
}

Indexed_for_Group2Var1   read_Indexed_Group2Var1_in_CountIndexParser(/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t);

Indexed_for_Group2Var1   read_Indexed_Group2Var1_in_CountIndexParser(/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t)
{
  Indexed_for_Group2Var1 pair;
//    uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
////        pair.index = numparser.ReadNum(buffer);
  pair.index = ReadNum_in_NumParser((NumParser*)pPointerGlobal1, buffer);
// boolean Read_in_Group2Var1_static(RSeq_for_Uint16_t *, Group2Var1*);
////        Type::Read(buffer, pair.value);
  Read_in_Group2Var1_static(buffer, pair.value);
  return pair;
};

////template<class Type>
////void CountIndexParser::InvokeCountOfType(const HeaderRecord& record,
////                                         uint16_t count,
////                                         const NumParser& numparser,
////                                         const ser4cpp::rseq_t& buffer,
////                                         IAPDUHandler& handler)
void InvokeCountOfType_for_Group2Var1_in_CountIndexParser(CountIndexParser *pCountIndexParser,
    HeaderRecord* record,
    uint16_t count,
    NumParser* numparser,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler)
{
////    auto read = [&numparser](ser4cpp::rseq_t& buffer, uint32_t) -> Indexed<Type> {
////        Indexed<Type> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Type::Read(buffer, pair.value);
////        return pair;
////    };
////
////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, count, read);

  pPointerGlobal1 = numparser;

//    BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser
//   CreateBufferedCollection_Indexed_Group2Var1(
//           /*NumParser*,*/ RSeq_for_Uint16_t*, uint16_t c,
//           Indexed_for_Group2Var1 (*read)((/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t c)));
  BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser
  collection = CreateBufferedCollection_Indexed_Group2Var1(/*numparser,*/ buffer, count, read_for_Indexed_for_Group2Var1_in_CountIndexParser);

//  void PrefixHeader_in_PrefixHeader(PrefixHeader *pPrefixHeader, HeaderRecord *record, uint16_t count_);
////    handler.OnHeader(PrefixHeader(record, count), collection);
  PrefixHeader pPrefixHeader;
  PrefixHeader_in_PrefixHeader(&pPrefixHeader, record, count);

  OnHeader_PrefixHeader_for_Indexed_Group2Var1_in_IAPDUHandler(handler, &pPrefixHeader, collection);
}

//------------------------------------------Group2Var1------------------------------------------------
////template<class Type> CountIndexParser CountIndexParser::FromType(uint16_t count, const NumParser& numparser)
////{
////    const size_t SIZE = static_cast<size_t>(count) * (Type::Size() + numparser.NumBytes());
////    return CountIndexParser(count, SIZE, numparser, &InvokeCountOfType<Type>);
////}
////
////template<class Descriptor>
////void CountIndexParser::InvokeCountOf(const HeaderRecord& record,
////                                     uint16_t count,
////                                     const NumParser& numparser,
////                                     const ser4cpp::rseq_t& buffer,
////                                     IAPDUHandler& handler)
////{
////    auto read = [&numparser](ser4cpp::rseq_t & buffer, uint32_t) -> Indexed<typename Descriptor::Target>
////    {
////        Indexed<typename Descriptor::Target> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Descriptor::ReadTarget(buffer, pair.value);
////        return pair;
////    };
////
////    auto collection = CreateBufferedCollection<Indexed<typename Descriptor::Target>>(buffer, count, read);
////    handler.OnHeader(PrefixHeader(record, count), collection);
////}
////
////template<class Type>
////void CountIndexParser::InvokeCountOfType(const HeaderRecord& record,
////                                         uint16_t count,
////                                         const NumParser& numparser,
////                                         const ser4cpp::rseq_t& buffer,
////                                         IAPDUHandler& handler)
////{
////    auto read = [&numparser](ser4cpp::rseq_t& buffer, uint32_t) -> Indexed<Type> {
////        Indexed<Type> pair;
////        pair.index = numparser.ReadNum(buffer);
////        Type::Read(buffer, pair.value);
////        return pair;
////    };
////
////    auto collection = CreateBufferedCollection<Indexed<Type>>(buffer, count, read);
////    handler.OnHeader(PrefixHeader(record, count), collection);
////}

void CountIndexParser_in_CountIndexParser(CountIndexParser *pCountIndexParser, uint16_t count, uint16_t requiredSize, NumParser *numparser, HandleFun_in_CountIndexParser handler);


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
