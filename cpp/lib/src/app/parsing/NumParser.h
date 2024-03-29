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
#ifndef OPENDNP3_NUMPARSER_H
#define OPENDNP3_NUMPARSER_H

////#include "app/Range.h"
////#include "app/parsing/ParseResult.h"

////#include "opendnp3/logging/Logger.h"

////#include <ser4cpp/container/SequenceTypes.h>

#include "Range.h"
#include "ParseResult.h"
#include "SerializationTemplates.h"
#include "RSeq.h"

//#include "opendnp3/logging/Logger.h"

//#include <ser4cpp/container/SequenceTypes.h>

////namespace opendnp3
////{

typedef uint16_t (*ReadFun_in_NumParser)(RSeq_for_Uint16_t *buffer);

// A one or two byte unsigned integer parser
////class NumParser
typedef struct
{
  // a function that consumes bytes from a buffer and returns a uint16_t count
////    typedef uint16_t (*ReadFun)(ser4cpp::rseq_t& buffer);

////public:
////    uint8_t NumBytes() const;

////    ParseResult ParseCount(ser4cpp::rseq_t& buffer, uint16_t& count, Logger* pLogger) const;
////    ParseResult ParseRange(ser4cpp::rseq_t& buffer, Range& range, Logger* pLogger) const;

////    uint16_t ReadNum(ser4cpp::rseq_t& buffer) const;

////    static NumParser OneByte();
////    static NumParser TwoByte();

////private:
  // read the number, consuming from the buffer
  // return true if there is enough bytes, false otherwise
////    bool Read(uint16_t& num, ser4cpp::rseq_t& buffer) const;

////    static uint16_t ReadOneByte(ser4cpp::rseq_t& buffer);
////    static uint16_t ReadTwoBytes(ser4cpp::rseq_t& buffer);

////    NumParser(ReadFun pReadFun, uint8_t size);

  ReadFun_in_NumParser pReadFun;
  uint8_t size;

////    NumParser() = delete;
} NumParser;

uint8_t NumBytes_in_NumParser(NumParser *pNumParser);

ParseResult_uint8_t ParseCount_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer, uint16_t *count);////, Logger* pLogger) const;
ParseResult_uint8_t ParseRange_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer, Range *range);////, Logger* pLogger) const;

uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);

NumParser OneByte_in_NumParser_static(void);
NumParser TwoByte_in_NumParser_static(void);

boolean Read_in_NumParser(NumParser *pNumParser, uint16_t *num, RSeq_for_Uint16_t *buffer);

uint16_t ReadOneByte_in_NumParser_static(RSeq_for_Uint16_t *buffer);
uint16_t ReadTwoBytes_in_NumParser_static(RSeq_for_Uint16_t *buffer);

void NumParser_in_NumParser(NumParser *pNumParser, ReadFun_in_NumParser pReadFun, uint8_t size);

//} // namespace opendnp3

#endif
