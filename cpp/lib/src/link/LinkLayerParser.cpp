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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "LinkLayerParser.h"

#include "CRC.h"
#include "IFrameSink.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

void LinkLayerParser_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)//const Logger& logger)
////    : logger(logger), state(State::FindSync), frameSize(0), buffer(rxBuffer, LPDU_MAX_FRAME_SIZE)
{
  LinkHeader_in_LinkHeaderOver1(&(pLinkLayerParser->header));
  Parser_in_LinkStatistics__in__Parser_in_LinkStatistics(&(pLinkLayerParser->statistics));

////    : logger(logger),
  pLinkLayerParser->state = FindSync_State_LinkLayerParser;
  pLinkLayerParser->frameSize = 0;
//void ShiftableBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint8_t* pBuffer_, uint16_t size);
//// buffer(rxBuffer, LPDU_MAX_FRAME_SIZE)
  ShiftableBuffer_in_ShiftableBuffer(&(pLinkLayerParser->buffer), pLinkLayerParser->rxBuffer, LPDU_MAX_FRAME_SIZE);
}

void Reset_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
  pLinkLayerParser->state = FindSync_State_LinkLayerParser;
  pLinkLayerParser->frameSize = 0;
//void Reset_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    buffer.Reset();
  Reset_in_ShiftableBuffer(&(pLinkLayerParser->buffer));
}

WSeq_for_Uint16_t WriteBuff_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{WriteBuff_in_LinkLayerParser1"<<std::endl;
#endif
//uint16_t NumWriteBytes_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
//uint8_t* WriteBuff_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    return ser4cpp::wseq_t(buffer.WriteBuff(), buffer.NumWriteBytes());
  WSeq_for_Uint16_t wWSeq_for_Uint16_t;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&wWSeq_for_Uint16_t,
      WriteBuff_in_ShiftableBuffer(&(pLinkLayerParser->buffer)),
      NumWriteBytes_in_ShiftableBuffer(&(pLinkLayerParser->buffer)));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}WriteBuff_in_LinkLayerParser_"<<std::endl;
  decrement_stack_info();
#endif
  return wWSeq_for_Uint16_t;
}

void OnRead_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, uint16_t numBytes, IFrameSink* sink)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnRead_in_LinkLayerParser1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t numBytes= "<<numBytes<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Complete_State_LinkLayerParser= "<<(uint16_t)Complete_State_LinkLayerParser<<std::endl;
#endif
//void AdvanceWrite_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t numBytes);
////    buffer.AdvanceWrite(numBytes);
  AdvanceWrite_in_ShiftableBuffer(&(pLinkLayerParser->buffer), numBytes);

//    State_LinkLayerParser_uint8_t ParseUntilComplete_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////    while (ParseUntilComplete() == State::Complete)
  while (ParseUntilComplete_in_LinkLayerParser(pLinkLayerParser) == Complete_State_LinkLayerParser)
  {
    ++(pLinkLayerParser->statistics.numLinkFrameRx);
//    void PushFrame_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, IFrameSink* sink);
////        this->PushFrame(sink);
    PushFrame_in_LinkLayerParser(pLinkLayerParser, sink);
////        state = State::FindSync;
    pLinkLayerParser->state = FindSync_State_LinkLayerParser;
  }

//void Shift_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    buffer.Shift();
  Shift_in_ShiftableBuffer(&(pLinkLayerParser->buffer));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnRead_in_LinkLayerParser_"<<std::endl;
  decrement_stack_info();
#endif
}

////LinkLayerParser::State LinkLayerParser::ParseUntilComplete()
State_LinkLayerParser_uint8_t ParseUntilComplete_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
  State_LinkLayerParser_uint8_t lastState = pLinkLayerParser->state;
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ParseUntilComplete_in_LinkLayerParser1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*State_LinkLayerParser_uint8_t lastState ="<<(uint16_t)lastState<<std::endl;
#endif

  // continue as long as we're making progress, i.e. a state change
// продолжаем до тех пор, пока мы добиваемся прогресса, т.е. изменения состояния
//    State_LinkLayerParser_uint8_t ParseOneStep_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////    while ((this->state = ParseOneStep()) != lastState)
  while ((pLinkLayerParser->state = ParseOneStep_in_LinkLayerParser(pLinkLayerParser)) != lastState)
  {
    lastState = pLinkLayerParser->state;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ParseUntilComplete_in_LinkLayerParser_"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pLinkLayerParser->state ="<<(uint16_t)pLinkLayerParser->state<<std::endl;
  decrement_stack_info();
#endif
  return pLinkLayerParser->state;
}

////LinkLayerParser::State LinkLayerParser::ParseOneStep()
State_LinkLayerParser_uint8_t ParseOneStep_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ParseOneStep_in_LinkLayerParser1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pLinkLayerParser->state= "<<(uint16_t)pLinkLayerParser->state<<std::endl;
#endif
  switch (pLinkLayerParser->state)
  {
  case (FindSync_State_LinkLayerParser):
  {
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*FindSync_State_LinkLayerParser"<<std::endl;
#endif
////        return ParseSync();
    State_LinkLayerParser_uint8_t tmp = ParseSync_in_LinkLayerParser(pLinkLayerParser);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseOneStep_in_LinkLayerParser1_"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*State_LinkLayerParser_uint8_t tmp= "<<(uint16_t)tmp<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  case (ReadHeader_State_LinkLayerParser):
  {
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*ReadHeader_State_LinkLayerParser"<<std::endl;
#endif
////        return ParseHeader();
    State_LinkLayerParser_uint8_t tmp = ParseHeader_in_LinkLayerParser(pLinkLayerParser);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseOneStep_in_LinkLayerParser2_"<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  case (ReadBody_State_LinkLayerParser):
  {
#ifdef  LOG_INFO
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*ReadBody_State_LinkLayerParser"<<std::endl;
#endif
////        return ParseBody();
    State_LinkLayerParser_uint8_t tmp = ParseBody_in_LinkLayerParser(pLinkLayerParser);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseOneStep_in_LinkLayerParser3_"<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

  default:
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseOneStep_in_LinkLayerParser4_"<<std::endl;
    decrement_stack_info();
#endif
    return pLinkLayerParser->state;
  }
}

////LinkLayerParser::State LinkLayerParser::ParseSync()
State_LinkLayerParser_uint8_t ParseSync_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ParseSync_in_LinkLayerParser1"<<std::endl;
#endif
//uint16_t NumBytesRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    if (this->buffer.NumBytesRead() >= 10) // && buffer.Sync())
  if (NumBytesRead_in_ShiftableBuffer(&(pLinkLayerParser->buffer)) >= 10)
  {
    uint16_t skipCount = 0;
//boolean Sync_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t* skipCount);
////        const auto synced = buffer.Sync(skipCount);
    boolean synced = Sync_in_ShiftableBuffer(&(pLinkLayerParser->buffer), &skipCount);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*ParseSync_in_LinkLayerParser2"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*boolean synced= "<<(uint16_t)synced<<std::endl;
#endif

    if (skipCount > 0)
    {
////            FORMAT_LOG_BLOCK(logger, flags::WARN, "Skipped %zu bytes seaching for start bytes", skipCount);
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::WARN, 'Skipped %zu bytes seaching for start bytes', skipCount)***"<<std::endl;
#endif
    }

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseSync_in_LinkLayerParser1_"<<std::endl;
    decrement_stack_info();
#endif
////        return synced ? State::ReadHeader : State::FindSync;
    return synced ? ReadHeader_State_LinkLayerParser : FindSync_State_LinkLayerParser;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ParseSync_in_LinkLayerParser2_"<<std::endl;
  decrement_stack_info();
#endif
  return FindSync_State_LinkLayerParser;
}

////LinkLayerParser::State LinkLayerParser::ParseHeader()
State_LinkLayerParser_uint8_t ParseHeader_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ParseHeader_in_LinkLayerParser1"<<std::endl;
#endif
////    if (this->buffer.NumBytesRead() >= 10)
  if (NumBytesRead_in_ShiftableBuffer(&(pLinkLayerParser->buffer)) >= 10)
  {
//    boolean ReadHeader_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////        if (this->ReadHeader())
    if (ReadHeader_in_LinkLayerParser(pLinkLayerParser))
    {
      State_LinkLayerParser_uint8_t tmp = ReadBody_State_LinkLayerParser;////State::ReadBody;
#ifdef  LOG_INFO
      std::cout<<getString_stack_info();
      std::cout<<"}ParseHeader_in_LinkLayerParser1_"<<std::endl;
      decrement_stack_info();
#endif
      return tmp;
    }

//    void FailFrame_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////        this->FailFrame();
    FailFrame_in_LinkLayerParser(pLinkLayerParser);
    State_LinkLayerParser_uint8_t tmp = FindSync_State_LinkLayerParser;////State::FindSync;
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseHeader_in_LinkLayerParser2_"<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
    State_LinkLayerParser_uint8_t tmp = ReadHeader_State_LinkLayerParser;////State::ReadHeader;
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseHeader_in_LinkLayerParser3_"<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }
}

////LinkLayerParser::State LinkLayerParser::ParseBody()
State_LinkLayerParser_uint8_t ParseBody_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ParseBody_in_LinkLayerParser1"<<std::endl;
#endif
//uint16_t NumBytesRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    if (buffer.NumBytesRead() < this->frameSize)
  if (NumBytesRead_in_ShiftableBuffer(&(pLinkLayerParser->buffer)) < pLinkLayerParser->frameSize)
  {
    State_LinkLayerParser_uint8_t tmp = ReadBody_State_LinkLayerParser;////State::ReadBody;
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseBody_in_LinkLayerParser1_"<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

//    boolean ValidateBody_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////    if (this->ValidateBody())
  if (ValidateBody_in_LinkLayerParser(pLinkLayerParser))
  {
//    void TransferUserData_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////        this->TransferUserData();
    TransferUserData_in_LinkLayerParser(pLinkLayerParser);
    State_LinkLayerParser_uint8_t tmp = Complete_State_LinkLayerParser;////State::Complete;
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ParseBody_in_LinkLayerParser2_"<<std::endl;
    decrement_stack_info();
#endif
    return tmp;
  }

//    void FailFrame_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////    this->FailFrame();
  FailFrame_in_LinkLayerParser(pLinkLayerParser);
  State_LinkLayerParser_uint8_t tmp = FindSync_State_LinkLayerParser;////State::FindSync;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ParseBody_in_LinkLayerParser3_"<<std::endl;
  decrement_stack_info();
#endif
  return tmp;
}

////void LinkLayerParser::PushFrame(IFrameSink& sink)
void PushFrame_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser, IFrameSink* sink)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{PushFrame_in_LinkLayerParser1"<<std::endl;
#endif

//  void LinkHeaderFields_in_LinkHeaderFieldsOver2(LinkHeaderFields *pLinkHeaderFields, LinkFunction_uint8_t func, boolean isMaster, boolean fcb, boolean fcvdfc, Addresses addresses);
//    LinkFunction_uint8_t GetFuncEnum_in_LinkHeader(LinkHeader *pLinkHeader);
//   boolean IsFromMaster_in_LinkHeader(LinkHeader *pLinkHeader);
//   boolean IsFcbSet_in_LinkHeader(LinkHeader *pLinkHeader);
//    boolean IsFcvDfcSet_in_LinkHeader(LinkHeader *pLinkHeader);
//   uint16_t GetSrc_in_LinkHeader(LinkHeader *pLinkHeader);
//   uint16_t GetDest_in_LinkHeader(LinkHeader *pLinkHeader);
////    LinkHeaderFields fields(header.GetFuncEnum(), header.IsFromMaster(), header.IsFcbSet(), header.IsFcvDfcSet(),
////                            Addresses(header.GetSrc(), header.GetDest()));
  Addresses aAddresses;
  Addresses_in_AddressesOver2(&aAddresses, GetSrc_in_LinkHeader(&(pLinkLayerParser->header)), GetDest_in_LinkHeader(&(pLinkLayerParser->header)));

  LinkHeaderFields fields;
  LinkHeaderFields_in_LinkHeaderFieldsOver2(&fields,
      GetFuncEnum_in_LinkHeader(&(pLinkLayerParser->header)),
      IsFromMaster_in_LinkHeader(&(pLinkLayerParser->header)),
      IsFcbSet_in_LinkHeader(&(pLinkLayerParser->header)),
      IsFcvDfcSet_in_LinkHeader(&(pLinkLayerParser->header)),
      aAddresses);

//    void OnFrame_in_IFrameSink(IFrameSink*, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);
////    sink.OnFrame(fields, userData);
  OnFrame_in_IFrameSink(sink, &fields, &(pLinkLayerParser->userData));

//void AdvanceRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t aNumBytes);
////    buffer.AdvanceRead(frameSize);
  AdvanceRead_in_ShiftableBuffer(&(pLinkLayerParser->buffer), pLinkLayerParser->frameSize);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}PushFrame_in_LinkLayerParser_"<<std::endl;
  decrement_stack_info();
#endif
}

void TransferUserData_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
//   uint8_t GetLength_in_LinkHeader(LinkHeader *pLinkHeader);
////    uint32_t len = header.GetLength() - LPDU_MIN_LENGTH;
  uint32_t len = GetLength_in_LinkHeader(&(pLinkLayerParser->header)) - LPDU_MIN_LENGTH;

// void ReadUserData_in_LinkFrame_static(uint8_t* apSrc, uint8_t* apDest, uint16_t len);
//RSeq_for_Uint16_t ReadBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    LinkFrame::ReadUserData(buffer.ReadBuffer() + LPDU_HEADER_SIZE, rxBuffer, len);
  RSeq_for_Uint16_t temp = ReadBuffer_in_ShiftableBuffer(&(pLinkLayerParser->buffer));

  ReadUserData_in_LinkFrame_static(temp.buffer_ + LPDU_HEADER_SIZE,
                                   pLinkLayerParser->rxBuffer, len);

//    void RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(RSeq_for_Uint16_t *pRSeq, uint8_t * buffer, uint16_t length);
////    userData = ser4cpp::rseq_t(rxBuffer, len);
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&(pLinkLayerParser->userData), pLinkLayerParser->rxBuffer, len);
}

boolean ReadHeader_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{ReadHeader_in_LinkLayerParser1"<<'\n';
#endif
//    void Read_in_LinkHeader(LinkHeader *pLinkHeader, uint8_t* apBuff);
//RSeq_for_Uint16_t ReadBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    header.Read(buffer.ReadBuffer());
  RSeq_for_Uint16_t temp = ReadBuffer_in_ShiftableBuffer(&(pLinkLayerParser->buffer));
  Read_in_LinkHeader(&(pLinkLayerParser->header), temp.buffer_);

// boolean IsCorrectCRC_in_CRC_static(uint8_t* input, uint16_t length);
////    if (CRC::IsCorrectCRC(buffer.ReadBuffer(), LI_CRC))
  temp = ReadBuffer_in_ShiftableBuffer(&(pLinkLayerParser->buffer));
  if (IsCorrectCRC_in_CRC_static(temp.buffer_, LinkHeaderIndex_LI_CRC))
  {
//    boolean ValidateHeaderParameters_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////        return ValidateHeaderParameters();
    boolean tmp = ValidateHeaderParameters_in_LinkLayerParser(pLinkLayerParser);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ReadHeader_in_LinkLayerParser1_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  else
  {
////        ++statistics.numHeaderCrcError;
    ++(pLinkLayerParser->statistics.numHeaderCrcError);
////        SIMPLE_LOG_BLOCK(logger, flags::WARN, "CRC failure in header");
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::WARN, 'CRC failure in header')***"<<std::endl;

    std::cout<<getString_stack_info();
    std::cout<<"}ReadHeader_in_LinkLayerParser2_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }
}

boolean ValidateBody_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{ValidateBody_in_LinkLayerParser1"<<'\n';
#endif
////    uint32_t len = header.GetLength() - LPDU_MIN_LENGTH;
  uint32_t len = GetLength_in_LinkHeader(&(pLinkLayerParser->header)) - LPDU_MIN_LENGTH;

//    boolean ValidateBodyCRC_in_LinkFrame_static(uint8_t* apBody, uint16_t aLength);
////    if (LinkFrame::ValidateBodyCRC(buffer.ReadBuffer() + LPDU_HEADER_SIZE, len))
  RSeq_for_Uint16_t temp = ReadBuffer_in_ShiftableBuffer(&(pLinkLayerParser->buffer));
#ifdef  LOG_INFO
  inspect_RSeq(&temp);
#endif

  if (ValidateBodyCRC_in_LinkFrame_static(temp.buffer_ + LPDU_HEADER_SIZE, len))
  {
////        FORMAT_LOG_BLOCK(logger, flags::LINK_RX, "Function: %s Dest: %u Source: %u Length: %u",
////                         LinkFunctionSpec::to_human_string(header.GetFuncEnum()), header.GetDest(), header.GetSrc(),
////                         header.GetLength());

////        FORMAT_HEX_BLOCK(logger, flags::LINK_RX_HEX, buffer.ReadBuffer().take(frameSize), 10, 18);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***FORMAT_HEX_BLOCK(logger, flags::LINK_RX_HEX, buffer.ReadBuffer().take(frameSize), 10, 18)***"<<std::endl;
#endif

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ValidateBody_in_LinkLayerParser1_"<<'\n';
  decrement_stack_info();
#endif
    return true;
  }

////    ++this->statistics.numBodyCrcError;
  ++(pLinkLayerParser->statistics.numBodyCrcError);
////    SIMPLE_LOG_BLOCK(logger, flags::ERR, "CRC failure in body");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'CRC failure in body')***"<<std::endl;
#endif


#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ValidateBody_in_LinkLayerParser2_"<<'\n';
  decrement_stack_info();
#endif
  return false;
}

boolean ValidateHeaderParameters_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{ValidateHeaderParameters_in_LinkLayerParser1"<<'\n';
#endif
//    boolean ValidLength_in_LinkHeader(LinkHeader *pLinkHeader);
////    if (!header.ValidLength())
  if (!ValidLength_in_LinkHeader(&(pLinkLayerParser->header)))
  {
////        ++statistics.numBadLength;
    ++(pLinkLayerParser->statistics.numBadLength);
////        FORMAT_LOG_BLOCK(logger, flags::ERR, "LENGTH out of range [5,255]: %i", header.GetLength());
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::ERR, 'LENGTH out of range [5,255]: %i', header.GetLength())"<<'\n';
#endif

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ValidateHeaderParameters_in_LinkLayerParser1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  // Now make sure that the function code is known and that the FCV is appropriate
// Теперь убедитесь, что код функции известен и что FCV подходит
//    boolean ValidateFunctionCode_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser);
////    if (!this->ValidateFunctionCode())
  if (!ValidateFunctionCode_in_LinkLayerParser(pLinkLayerParser))
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ValidateHeaderParameters_in_LinkLayerParser2_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

//   uint8_t GetLength_in_LinkHeader(LinkHeader *pLinkHeader);
////    uint8_t user_data_length = header.GetLength() - LPDU_MIN_LENGTH;
  uint8_t user_data_length = GetLength_in_LinkHeader(&(pLinkLayerParser->header)) - LPDU_MIN_LENGTH;

// uint16_t CalcFrameSize_in_LinkFrame_static(uint16_t dataLength);
////    frameSize = LinkFrame::CalcFrameSize(user_data_length);
  pLinkLayerParser->frameSize = CalcFrameSize_in_LinkFrame_static(user_data_length);

//    LinkFunction_uint8_t GetFuncEnum_in_LinkHeader(LinkHeader *pLinkHeader);
////    LinkFunction func = header.GetFuncEnum();
  LinkFunction_uint8_t func = GetFuncEnum_in_LinkHeader(&(pLinkLayerParser->header));

  boolean has_payload = user_data_length > 0;
  boolean should_have_payload
    = (func == LinkFunction_PRI_CONFIRMED_USER_DATA || func == LinkFunction_PRI_UNCONFIRMED_USER_DATA);

  // make sure that the presence/absence of user data matches the function code
  if (should_have_payload && !has_payload)
  {
////        ++statistics.numBadLength;
    ++(pLinkLayerParser->statistics.numBadLength);

////        FORMAT_LOG_BLOCK(logger, flags::ERR, "User data with no payload. FUNCTION: %s",
////                         LinkFunctionSpec::to_human_string(func));
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::ERR, 'User data with no payload. FUNCTION: %s',***"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*LinkFunction_uint8_t func= "<<(uint16_t)func<<'\n';

    std::cout<<getString_stack_info();
    std::cout<<"}ValidateHeaderParameters_in_LinkLayerParser3_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (!should_have_payload && has_payload)
  {
////        ++statistics.numBadLength;
    ++(pLinkLayerParser->statistics.numBadLength);

////        FORMAT_LOG_BLOCK(logger, flags::ERR, "Unexpected LENGTH in frame: %i with FUNCTION: %s", user_data_length,
////                         LinkFunctionSpec::to_human_string(func));
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::ERR, 'Unexpected LENGTH in frame: %i with FUNCTION: %s',***"<<std::endl;
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*LinkFunction_uint8_t func= "<<(uint16_t)func<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*uint8_t user_data_length= "<<(uint16_t)user_data_length<<'\n';

    std::cout<<getString_stack_info();
    std::cout<<"}ValidateHeaderParameters_in_LinkLayerParser4_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  // calculate the total frame size
// uint16_t CalcFrameSize_in_LinkFrame_static(uint16_t dataLength);
////    pLinkLayerParser->frameSize = LinkFrame::CalcFrameSize(user_data_length);
  pLinkLayerParser->frameSize = CalcFrameSize_in_LinkFrame_static(user_data_length);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ValidateHeaderParameters_in_LinkLayerParser5_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

void FailFrame_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
  // All you have to do is advance the reader by one, when the resync happens the data will disappear
//void AdvanceRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t aNumBytes);
////    buffer.AdvanceRead(1);
  AdvanceRead_in_ShiftableBuffer(&(pLinkLayerParser->buffer), 1);
}

boolean ValidateFunctionCode_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{ValidateFunctionCode_in_LinkLayerParser1"<<'\n';
#endif
  // Now make sure that the function code is known and that the FCV is appropriate
// Теперь убедитесь, что код функции известен и что FCV подходит
//   boolean IsPriToSec_in_LinkHeader(LinkHeader *pLinkHeader);
////    if (header.IsPriToSec())
  if (IsPriToSec_in_LinkHeader(&(pLinkLayerParser->header)))
  {
    boolean fcv_set = false;

//    LinkFunction_uint8_t GetFuncEnum_in_LinkHeader(LinkHeader *pLinkHeader);
////        switch (header.GetFuncEnum())
    switch (GetFuncEnum_in_LinkHeader(&(pLinkLayerParser->header)))
    {
    case (LinkFunction_PRI_CONFIRMED_USER_DATA):
    case (LinkFunction_PRI_TEST_LINK_STATES):
      fcv_set = true;
      break;
    case (LinkFunction_PRI_REQUEST_LINK_STATUS):
    case (LinkFunction_PRI_RESET_LINK_STATES):
    case (LinkFunction_PRI_UNCONFIRMED_USER_DATA):
      break;
    default:
    {
////            ++statistics.numBadFunctionCode;
      ++(pLinkLayerParser->statistics.numBadFunctionCode);
////            FORMAT_LOG_BLOCK(logger, flags::WARN, "Unknown PriToSec FUNCTION: %s",
////                             LinkFunctionSpec::to_human_string(header.GetFuncEnum()));
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::WARN, 'Unknown PriToSec FUNCTION: %s',***"<<std::endl;

      std::cout<<getString_stack_info();
      std::cout<<"}ValidateFunctionCode_in_LinkLayerParser1_"<<'\n';
      decrement_stack_info();
#endif
      return false;
    }
    }

    // now check the fcv
//    boolean IsFcvDfcSet_in_LinkHeader(LinkHeader *pLinkHeader);
////        if (fcv_set != header.IsFcvDfcSet())
    if (fcv_set != IsFcvDfcSet_in_LinkHeader(&(pLinkLayerParser->header)))
    {
////            ++statistics.numBadFCV;
      ++(pLinkLayerParser->statistics.numBadFCV);
////            FORMAT_LOG_BLOCK(logger, flags::WARN, "Bad FCV for FUNCTION: %s",
////                             LinkFunctionSpec::to_human_string(header.GetFuncEnum()));
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::WARN, 'Bad FCV for FUNCTION: %s',***"<<std::endl;

      std::cout<<getString_stack_info();
      std::cout<<"}ValidateFunctionCode_in_LinkLayerParser2_"<<'\n';
      decrement_stack_info();
#endif
      return false;
    }

    // if fcv isn't expected to be set, fcb can be either 1 or 0, doesn't matter
// если fcv не ожидается, fcb может быть либо 1, либо 0, не имеет значения
  }
  else // SecToPri - just validate the function codes and that FCB is 0
//SecToPri - просто проверьте коды функций и убедитесь, что FCB равен 0
  {
////        switch (header.GetFuncEnum())
    switch (GetFuncEnum_in_LinkHeader(&(pLinkLayerParser->header)))
    {
    case (LinkFunction_SEC_ACK):
    case (LinkFunction_SEC_NACK):
    case (LinkFunction_SEC_LINK_STATUS):
    case (LinkFunction_SEC_NOT_SUPPORTED):
      break;
    default:
    {
////            ++statistics.numBadFunctionCode;
      ++(pLinkLayerParser->statistics.numBadFunctionCode);
////            FORMAT_LOG_BLOCK(logger, flags::ERR, "Unknown SecToPri FUNCTION: %s",
////                             LinkFunctionSpec::to_human_string(header.GetFuncEnum()));
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::ERR, 'Unknown SecToPri FUNCTION: %s',***"<<std::endl;

      std::cout<<getString_stack_info();
      std::cout<<"}ValidateFunctionCode_in_LinkLayerParser3_"<<'\n';
      decrement_stack_info();
#endif
      return false;
    }
    }

    // now check the fcb, it should always be zero
// теперь проверяем fcb, он всегда должен быть равен нулю
//   boolean IsFcbSet_in_LinkHeader(LinkHeader *pLinkHeader);
////        if (header.IsFcbSet())
    if (IsFcbSet_in_LinkHeader(&(pLinkLayerParser->header)))
    {
////            ++statistics.numBadFCB;
      ++(pLinkLayerParser->statistics.numBadFCB);
////            FORMAT_LOG_BLOCK(logger, flags::ERR, "FCB set for SecToPri FUNCTION: %s",
////                             LinkFunctionSpec::to_human_string(header.GetFuncEnum()));
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::ERR, 'FCB set for SecToPri FUNCTION: %s',***"<<std::endl;

      std::cout<<getString_stack_info();
      std::cout<<"}ValidateFunctionCode_in_LinkLayerParser4_"<<'\n';
      decrement_stack_info();
#endif
      return false;
    }
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ValidateFunctionCode_in_LinkLayerParser5_"<<'\n';
  decrement_stack_info();
#endif
  return true; // valid!
}

////} // namespace opendnp3
Parser_in_LinkStatistics* Statistics_in_LinkLayerParser(LinkLayerParser *pLinkLayerParser)
{
  return &(pLinkLayerParser->statistics);
}
