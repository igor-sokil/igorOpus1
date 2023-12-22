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
#ifndef OPENDNP3_COUNTPARSER_H
#define OPENDNP3_COUNTPARSER_H

////#include "app/parsing/BufferedCollection.h"
////#include "app/parsing/Functions.h"
////#include "app/parsing/IAPDUHandler.h"
////#include "app/parsing/NumParser.h"
////#include "app/parsing/ParseResult.h"
////#include "app/parsing/ParserSettings.h"

////#include "opendnp3/logging/Logger.h"

////#include <ser4cpp/container/SequenceTypes.h>
#include "BufferedCollection.h"
#include "Functions.h"
#include "IAPDUHandler.h"
#include "NumParser.h"
#include "ParseResult.h"
//#include "ParserSettings.h"

//#include "opendnp3/logging/Logger.h"

//#include <ser4cpp/container/SequenceTypes.h>
#include "RSeq.h"


////namespace opendnp3
////{

typedef void (*HandleFun_in_CountParser)( HeaderRecord* record,
    uint16_t count,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* handler);

////class CountParser
typedef struct
{
////    typedef void (*HandleFun)(const HeaderRecord& record,
////                              uint16_t count,
////                              const ser4cpp::rseq_t& buffer,
////                              IAPDUHandler& handler);

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
  // Create a count handler from a fixed size descriptor
////    template<class Descriptor> static CountParser From(uint16_t count);

////    static ParseResult ParseCountOfObjects(
////        ser4cpp::rseq_t& buffer, const HeaderRecord& record, uint16_t count, Logger* pLogger, IAPDUHandler* pHandler);

////    template<class Descriptor>
////    static void InvokeCountOf(const HeaderRecord& record,
////                              uint16_t count,
////                              const ser4cpp::rseq_t& buffer,
////                              IAPDUHandler& handler);

////    CountParser(uint16_t count, size_t required_size, HandleFun handler);

  uint16_t count;
  uint16_t required_size;
  HandleFun_in_CountParser handler;

////    CountParser() = delete;
} CountParser;

void  CountParser_in_CountParser(CountParser *pCountParser, uint16_t count, uint16_t required_size, HandleFun_in_CountParser handler);

ParseResult_uint8_t ParseCountOfObjects_in_CountParser_static(
  RSeq_for_Uint16_t* buffer, HeaderRecord* record, uint16_t count, /*Logger* pLogger,*/ IAPDUHandler* pHandler);

// Process the count handler against the buffer
// Обработка обработчика счетчика в буфере
ParseResult_uint8_t Process_in_CountParser(CountParser *pCountParser, HeaderRecord* record,
    RSeq_for_Uint16_t* buffer,
    IAPDUHandler* pHandler);
////                        Logger* pLogger) const;

ParseResult_uint8_t ParseHeader_in_CountParser_static(RSeq_for_Uint16_t* buffer,
    NumParser* numparser,
    ////const ParserSettings& settings,
    HeaderRecord* record,
    ////Logger* pLogger,
    IAPDUHandler* pHandler);

//-------------------Group50Var1-----------------------------
////template<class Descriptor> CountParser CountParser::From(uint16_t count)
CountParser From_for_Group50Var1_in_CountParser_static(uint16_t count);
void InvokeCountOf_for_Group50Var1_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//-------------------Group50Var1-----------------------------
//-------------------Group50Var3-----------------------------
////template<class Descriptor> CountParser CountParser::From(uint16_t count)
CountParser From_for_Group50Var3_in_CountParser_static(uint16_t count);
void InvokeCountOf_for_Group50Var3_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//-------------------Group50Var3-----------------------------
//-------------------Group51Var1-----------------------------
////template<class Descriptor> CountParser CountParser::From(uint16_t count)
CountParser From_for_Group51Var1_in_CountParser_static(uint16_t count);
void InvokeCountOf_for_Group51Var1_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//-------------------Group51Var1-----------------------------
//-------------------Group51Var2-----------------------------
////template<class Descriptor> CountParser CountParser::From(uint16_t count)
CountParser From_for_Group51Var2_in_CountParser_static(uint16_t count);
void InvokeCountOf_for_Group51Var2_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//-------------------Group51Var2-----------------------------
//-------------------Group52Var1-----------------------------
////template<class Descriptor> CountParser CountParser::From(uint16_t count)
CountParser From_for_Group52Var1_in_CountParser_static(uint16_t count);
void InvokeCountOf_for_Group52Var1_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//-------------------Group52Var1-----------------------------
//-------------------Group52Var2-----------------------------
////template<class Descriptor> CountParser CountParser::From(uint16_t count)
CountParser From_for_Group52Var2_in_CountParser_static(uint16_t count);
void InvokeCountOf_for_Group52Var2_in_CountParser_static(
  HeaderRecord* record,
  uint16_t count,
  RSeq_for_Uint16_t* buffer,
  IAPDUHandler* handler);
//-------------------Group52Var2-----------------------------


////} // namespace opendnp3

#endif
