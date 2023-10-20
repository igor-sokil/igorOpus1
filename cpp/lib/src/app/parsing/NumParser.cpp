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
#include "NumParser.h"
#include "RSeq.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

void NumParser_in_NumParser(NumParser *pNumParser, ReadFun_in_NumParser pReadFun, uint8_t size)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"NumParser_in_NumParser1"<<std::endl;
  decrement_stack_info();
#endif
  pNumParser->pReadFun = pReadFun;
  pNumParser->size = size;
}

uint8_t NumBytes_in_NumParser(NumParser *pNumParser)
{
  return pNumParser->size;
}

ParseResult_uint8_t ParseCount_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t* buffer, uint16_t *count)///, Logger* pLogger) const
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseCount_in_NumParser1"<<std::endl;
#endif
//    boolean Read_in_NumParser(NumParser *pNumParser, uint16_t *num, RSeq_for_Uint16_t *buffer);
////    if (this->Read(count, buffer))
  if (Read_in_NumParser(pNumParser, count, buffer))
  {
    if (*count == 0)
    {
////            SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "count of 0");
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"***SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'count of 0')***"<<std::endl;
      decrement_stack_info();
#endif
      return ParseResult_COUNT_OF_ZERO;
    }

#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return ParseResult_OK;
  }
  else
  {
////        SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for count");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for count')***"<<std::endl;
    decrement_stack_info();
#endif
    return ParseResult_NOT_ENOUGH_DATA_FOR_RANGE;
  }
}

ParseResult_uint8_t ParseRange_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t* buffer, Range* range)////, Logger* pLogger) const
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ParseRange_in_NumParser1"<<std::endl;
#endif

////    if (buffer.length() < (2 * static_cast<size_t>(size)))
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < (2 * (uint16_t)(pNumParser->size)))
  {
////        SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, "Not enough data for start / stop");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOGGER_BLOCK(pLogger, flags::WARN, 'Not enough data for start / stop')***"<<std::endl;
    decrement_stack_info();
#endif
    return ParseResult_NOT_ENOUGH_DATA_FOR_RANGE;
  }

//    uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t *buffer);
  range->start = ReadNum_in_NumParser(pNumParser, buffer);////this->ReadNum(buffer);
  range->stop = ReadNum_in_NumParser(pNumParser, buffer);////this->ReadNum(buffer);

//    boolean IsValid_in_Range(Range *pRange);
////    if (range.IsValid())
  if (IsValid_in_Range(range))
  {
    return ParseResult_OK;
  }

////    FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, "start (%u) > stop (%u)", range.start, range.stop);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::WARN, 'start (%u) > stop (%u)', range.start, range.stop)***"<<std::endl;
  decrement_stack_info();
#endif
  return ParseResult_BAD_START_STOP;
}

uint16_t ReadNum_in_NumParser(NumParser *pNumParser, RSeq_for_Uint16_t* buffer)
{
  return pNumParser->pReadFun(buffer);
}

boolean Read_in_NumParser(NumParser *pNumParser, uint16_t *num, RSeq_for_Uint16_t* buffer)
{
////    if (buffer.length() < size)
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < pNumParser->size)
  {
    return false;
  }

////    num = pReadFun(buffer);
  *num = pNumParser->pReadFun(buffer);
  return true;
}

////uint16_t NumParser::ReadOneByte(ser4cpp::rseq_t& buffer)
uint16_t ReadOneByte_in_NumParser_static(RSeq_for_Uint16_t *buffer)
{
  uint8_t result = 0;
////    ser4cpp::UInt8::read_from(buffer, result);
  read_from_in_UInt8_static(buffer, &result);
  return result;
}

////uint16_t NumParser::ReadTwoBytes(ser4cpp::rseq_t& buffer)
uint16_t ReadTwoByte_in_NumParser_static(RSeq_for_Uint16_t *buffer)
{
  uint16_t result = 0;
////    ser4cpp::UInt16::read_from(buffer, result);
  read_from_in_UInt16_static(buffer, &result);
  return result;
}

////NumParser NumParser::OneByte()
NumParser OneByte_in_NumParser_static(void)
{
//    void NumParser_in_NumParser(NumParser *pNumParser, ReadFun_in_NumParser pReadFun, uint8_t size);
////    return NumParser(&ReadOneByte, 1);
  NumParser nNumParser;
  NumParser_in_NumParser(&nNumParser, ReadOneByte_in_NumParser_static, 1);
  return nNumParser;
}

NumParser TwoByte_in_NumParser_static(void)
{
////    return NumParser(&ReadTwoBytes, 2);
  NumParser nNumParser;
  NumParser_in_NumParser(&nNumParser, ReadTwoByte_in_NumParser_static, 2);
  return nNumParser;
}

////} // namespace opendnp3
