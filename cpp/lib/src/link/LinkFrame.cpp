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
////#include "LinkFrame.h"

////#include "link/CRC.h"
////#include "link/LinkHeader.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <ser4cpp/serialization/LittleEndian.h>

#include <iostream>
#include "header.h"
#include "LinkFrame.h"

#include "CRC.h"
#include "LinkHeader.h"
#include <string.h>
//#include "logging/LogMacros.h"

//#include "opendnp3/logging/LogLevels.h"

//#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

void ReadUserData_in_LinkFrame_static(uint8_t* pSrc, uint8_t* pDest, uint16_t len)
{
  uint16_t length = len;
  uint8_t * pRead = pSrc;
  uint8_t* pWrite = pDest;

  while (length > 0)
  {
    uint16_t max = LPDU_DATA_BLOCK_SIZE;
    uint16_t num = (length <= max) ? length : max;
    uint16_t num_with_crc = num + 2;
    memmove(pWrite, pRead, num);
    pRead += num_with_crc;
    pWrite += num;
    length -= num;
  }
}

boolean ValidateBodyCRC_in_LinkFrame_static(uint8_t* pBody, uint16_t length)
{
  while (length > 0)
  {
    uint16_t max = LPDU_DATA_BLOCK_SIZE;
    uint16_t num = (length <= max) ? length : max;

    if (IsCorrectCRC_in_CRC_static(pBody, num))
    {
      pBody += (num + 2);
      length -= num;
    }
    else
    {
      return false;
    }
  }
  return true;
}

uint16_t  CalcFrameSize_in_LinkFrame_static(uint16_t dataLength)
{
  return LPDU_HEADER_SIZE + CalcUserDataSize_in_LinkFrame_static(dataLength);
}

uint16_t CalcUserDataSize_in_LinkFrame_static(uint16_t dataLength)
{
  if (dataLength > 0)
  {
    uint16_t mod16 = dataLength % LPDU_DATA_BLOCK_SIZE;
    uint16_t size = (dataLength / LPDU_DATA_BLOCK_SIZE) * LPDU_DATA_PLUS_CRC_SIZE; // complete blocks
    return (mod16 > 0) ? (size + mod16 + LPDU_CRC_SIZE) : size;                  // possible partial block
  }

  return 0;
}

////////////////////////////////////////////////
//
//	Outgoing frame formatting functions for Sec to Pri transactions
//
////////////////////////////////////////////////

RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)//, Logger* pLogger)
{
  return FormatHeader_in_LinkFrame_static(buffer, 0, aIsMaster, false, aIsRcvBuffFull, LinkFunction_SEC_ACK, aDest, aSrc);//, pLogger);
}

RSeq_for_Uint16_t FormatNack_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)//, Logger* pLogger)
{
  return FormatHeader_in_LinkFrame_static(buffer, 0, aIsMaster, false, aIsRcvBuffFull, LinkFunction_SEC_NACK, aDest, aSrc);//, pLogger);
}

RSeq_for_Uint16_t FormatLinkStatus_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)//, Logger* pLogger)
{
  return FormatHeader_in_LinkFrame_static(buffer, 0, aIsMaster, false, aIsRcvBuffFull, LinkFunction_SEC_LINK_STATUS, aDest, aSrc);//,
  //pLogger);
}

RSeq_for_Uint16_t FormatNotSupported_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc)//, Logger* pLogger)
{
  return FormatHeader_in_LinkFrame_static(buffer, 0, aIsMaster, false, aIsRcvBuffFull, LinkFunction_SEC_NOT_SUPPORTED, aDest, aSrc);//,
  //pLogger);
}

////////////////////////////////////////////////
//
//	Outgoing frame formatting functions for Pri to Sec transactions
//
////////////////////////////////////////////////

RSeq_for_Uint16_t FormatResetLinkStates_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc)//, Logger* pLogger)
{
  return FormatHeader_in_LinkFrame_static(buffer, 0, aIsMaster, false, false, LinkFunction_PRI_RESET_LINK_STATES, aDest, aSrc);//, pLogger);
}

RSeq_for_Uint16_t FormatRequestLinkStatus_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc)//, Logger* pLogger)
{
  return FormatHeader_in_LinkFrame_static(buffer, 0, aIsMaster, false, false, LinkFunction_PRI_REQUEST_LINK_STATUS, aDest, aSrc);//,
  //pLogger);
}

RSeq_for_Uint16_t FormatTestLinkStatus_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aFcb, uint16_t aDest, uint16_t aSrc)//, Logger* pLogger)
{
  return FormatHeader_in_LinkFrame_static(buffer, 0, aIsMaster, aFcb, true, LinkFunction_PRI_TEST_LINK_STATES, aDest, aSrc);//, pLogger);
}

RSeq_for_Uint16_t FormatConfirmedUserData_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
    boolean aIsMaster,
    boolean aFcb,
    uint16_t aDest,
    uint16_t aSrc,
    RSeq_for_Uint16_t user_data)//,
// Logger* pLogger)
{
//    if (user_data.length() > LPDU_MAX_USER_DATA_SIZE)
  if (length_in_HasLength_for_Uint16_t(&(user_data.hHasLength)) > LPDU_MAX_USER_DATA_SIZE)
  {
    return empty_in_RSeq_for_Uint16_t_static();////ser4cpp::rseq_t::empty();
  }

  uint16_t userDataSize = CalcUserDataSize_in_LinkFrame_static(length_in_HasLength_for_Uint16_t(&(user_data.hHasLength)));////user_data.length());
////    auto ret = buffer.readonly().take(userDataSize + LPDU_HEADER_SIZE);
  RSeq_for_Uint16_t tmp1 = readonly_in_WSeq_for_Uint16_t(buffer);
  RSeq_for_Uint16_t ret = take_in_RSeq_for_Uint16_t(&tmp1, userDataSize + LPDU_HEADER_SIZE);
////    FormatHeader_in_LinkFrame_static(buffer, static_cast<uint8_t>(user_data.length()), aIsMaster, aFcb, true,
////                 LinkFunction::PRI_CONFIRMED_USER_DATA, aDest, aSrc, pLogger);
  FormatHeader_in_LinkFrame_static(buffer, (uint8_t)(length_in_HasLength_for_Uint16_t(&(user_data.hHasLength))),////user_data.length()),
                                   aIsMaster, aFcb, true,
                                   LinkFunction_PRI_CONFIRMED_USER_DATA, aDest, aSrc);//, pLogger);
  WriteUserData_in_LinkFrame_static(user_data.buffer_, buffer->buffer_, length_in_HasLength_for_Uint16_t(&(user_data.hHasLength)));//user_data.length());
////    buffer.advance(userDataSize);
  advance_in_WSeq_for_Uint16_t(buffer, userDataSize);
  return ret;
}

RSeq_for_Uint16_t FormatUnconfirmedUserData_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc, RSeq_for_Uint16_t user_data)//, Logger* pLogger)
{
  if (length_in_HasLength_for_Uint16_t(&(user_data.hHasLength)) > LPDU_MAX_USER_DATA_SIZE)
  {
    return empty_in_RSeq_for_Uint16_t_static();////return ser4cpp::rseq_t::empty();
  }

  uint16_t userDataSize = CalcUserDataSize_in_LinkFrame_static(length_in_HasLength_for_Uint16_t(&(user_data.hHasLength)));//user_data.length());
////    auto ret = buffer.readonly().take(userDataSize + LPDU_HEADER_SIZE);
  RSeq_for_Uint16_t tmp1 = readonly_in_WSeq_for_Uint16_t(buffer);
  RSeq_for_Uint16_t ret = take_in_RSeq_for_Uint16_t(&tmp1, userDataSize + LPDU_HEADER_SIZE);

  FormatHeader_in_LinkFrame_static(buffer, (uint8_t)(length_in_HasLength_for_Uint16_t(&(user_data.hHasLength))),//user_data.length()),
                                   aIsMaster, false, false,
                                   LinkFunction_PRI_UNCONFIRMED_USER_DATA, aDest, aSrc);//, pLogger);
  WriteUserData_in_LinkFrame_static(user_data.buffer_, buffer->buffer_, length_in_HasLength_for_Uint16_t(&(user_data.hHasLength)));//user_data.length());
////    buffer.advance(userDataSize);
  advance_in_WSeq_for_Uint16_t(buffer, userDataSize);
  return ret;
}

RSeq_for_Uint16_t FormatHeader_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
    uint8_t aDataLength,
    boolean aIsMaster,
    boolean aFcb,
    boolean aFcvDfc,
    LinkFunction_uint8_t aFuncCode,
    uint16_t aDest,
    uint16_t aSrc)//,
//Logger* pLogger)
{
  if (length_in_HasLength_for_Uint16_t(&(buffer->hHasLength)) < LPDU_HEADER_SIZE)
  {
    return empty_in_RSeq_for_Uint16_t_static();////return ser4cpp::rseq_t::empty();
  }

//   void LinkHeader_in_LinkHeaderOver2(LinkHeader *pLinkHeader, uint8_t len, uint16_t src, uint16_t dest, boolean aFromMaster, boolean fcvdfc, boolean fcb, LinkFunction_uint8_t aCode);
////    LinkHeader header(aDataLength + LPDU_MIN_LENGTH, aSrc, aDest, aIsMaster, aFcvDfc, aFcb, aFuncCode);
  LinkHeader header;
  LinkHeader_in_LinkHeaderOver2(&header, aDataLength + LPDU_MIN_LENGTH, aSrc, aDest, aIsMaster, aFcvDfc, aFcb, aFuncCode);

////    FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, "Function: %s Dest: %u Source: %u Length: %u",
////                        LinkFunctionSpec::to_human_string(aFuncCode), aDest, aSrc, aDataLength);
  std::cout<<"***FORMAT_LOGGER_BLOCK(pLogger, flags::LINK_TX, 'Function: %s Dest: %u Source: %u Length: %u')***"<<std::endl;

//pMemory_LinkHeader_1=  MEMORY_LinkHeader_1(0, &header);

//    void Write_in_LinkHeader(LinkHeader *pLinkHeader, uint8_t* apBuff);
////    header.Write(buffer);
  Write_in_LinkHeader(&header, buffer->buffer_);

////    auto ret = buffer.readonly().take(10);
  RSeq_for_Uint16_t tmp1 = readonly_in_WSeq_for_Uint16_t(buffer);
  RSeq_for_Uint16_t ret = take_in_RSeq_for_Uint16_t(&tmp1, 10);
////    buffer.advance(10);
  advance_in_WSeq_for_Uint16_t(buffer, 10);
  return ret;
}

void WriteUserData_in_LinkFrame_static(uint8_t* pSrc, uint8_t* pDest, uint16_t length)
{
  while (length > 0)
  {
    uint8_t max = LPDU_DATA_BLOCK_SIZE;
    uint16_t num = length > max ? max : length;
    memcpy(pDest, pSrc, num);
    AddCrc_in_CRC_static(pDest, num);
    pSrc += num;
    pDest += (num + 2);
    length -= num;
  }
}

////} // namespace opendnp3
