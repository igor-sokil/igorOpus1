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
#ifndef OPENDNP3_LINKFRAME_H
#define OPENDNP3_LINKFRAME_H

////#include "opendnp3/gen/FunctionCode.h"
////#include "opendnp3/gen/LinkFunction.h"
////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/util/StaticOnly.h"

////#include <ser4cpp/container/SequenceTypes.h>

#include "FunctionCode.h"
#include "LinkFunction.h"
#include "RSeq.h"
#include "WSeq.h"
//#include "opendnp3/logging/Logger.h"
//#include "opendnp3/util/StaticOnly.h"

//#include <ser4cpp/container/SequenceTypes.h>

////namespace opendnp3
////{

////class LinkFrame : private StaticOnly
////typedef struct
////{

////public:
////////////////////////////////////////////////
//	Functions for formatting outgoing Sec to Pri frames
////////////////////////////////////////////////

////    static ser4cpp::rseq_t FormatAck(
////        ser4cpp::wseq_t& buffer, bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc, Logger* pLogger);
////    static ser4cpp::rseq_t FormatNack(
////        ser4cpp::wseq_t& buffer, bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc, Logger* pLogger);
////    static ser4cpp::rseq_t FormatLinkStatus(
////        ser4cpp::wseq_t& buffer, bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc, Logger* pLogger);
////    static ser4cpp::rseq_t FormatNotSupported(
////        ser4cpp::wseq_t& buffer, bool aIsMaster, bool aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc, Logger* pLogger);

////////////////////////////////////////////////
//	Functions for formatting outgoing Pri to Sec frames
////////////////////////////////////////////////

////    static ser4cpp::rseq_t FormatTestLinkStatus(
////        ser4cpp::wseq_t& buffer, bool aIsMaster, bool aFcb, uint16_t aDest, uint16_t aSrc, Logger* pLogger);
////    static ser4cpp::rseq_t FormatResetLinkStates(
////        ser4cpp::wseq_t& buffer, bool aIsMaster, uint16_t aDest, uint16_t aSrc, Logger* pLogger);
////    static ser4cpp::rseq_t FormatRequestLinkStatus(
////        ser4cpp::wseq_t& buffer, bool aIsMaster, uint16_t aDest, uint16_t aSrc, Logger* pLogger);
////    static ser4cpp::rseq_t FormatConfirmedUserData(ser4cpp::wseq_t& buffer,
////                                                   bool aIsMaster,
////                                                   bool aFcb,
////                                                   uint16_t aDest,
////                                                   uint16_t aSrc,
////                                                   ser4cpp::rseq_t user_data,
////                                                   Logger* pLogger);
////    static ser4cpp::rseq_t FormatUnconfirmedUserData(ser4cpp::wseq_t& buffer,
////                                                     bool aIsMaster,
////                                                     uint16_t aDest,
////                                                     uint16_t aSrc,
////                                                     ser4cpp::rseq_t user_data,
////                                                     Logger* pLogger);
////
////////////////////////////////////////////////
//	Reusable static formatting functions to any buffer
////////////////////////////////////////////////

/** Reads data from src to dest removing 2 byte CRC checks every 16 data bytes
@param apSrc Source buffer with crc checks. Must begin at data, not header
@param apDest Destination buffer to which the data is extracted
@param aLength Length of user data to read to the dest buffer. The source buffer must be larger b/c of crc bytes.

��������� ������ �� src � dest, ������ 2 ����� CRC, ��������� ������ 16 ������ ������
 @param apSrc �������� ����� � ��������� crc. ������ ���������� � ������, � �� � ���������
 @param apDest ������� �����, � ������� ����������� ������
 @param aLength ����� ���������������� ������ ��� ������ � ������� �����. �������� ����� ������ ���� ������ b/c ������ crc.
*/
////    static void ReadUserData(const uint8_t* apSrc, uint8_t* apDest, size_t len);

/** Validates FT3 user data integriry
@param apBody Beginning of the FT3 user data
@param aLength Number of user bytes to verify, not user + crc.
@return True if the body CRC is correct */
/** ��������� ����������� ���������������� ������ FT3
     @param apBody ������ ���������������� ������ FT3
     @param aLength ���������� ���������������� ������ ��� ��������, � �� user + crc.
     @return True, ���� CRC ���� ���������� */
////    static bool ValidateBodyCRC(const uint8_t* apBody, size_t aLength);

// @return Total frame size based on user data length
////    static size_t CalcFrameSize(size_t dataLength);

////private:
////    static size_t CalcUserDataSize(size_t dataLength);

/** Writes data from src to dest interlacing 2 byte CRC checks every 16 data bytes
    @param apSrc Source buffer full of user data
    @param apDest Destination buffer where the data + CRC is written
    @param length Number of user data bytes
*/
/** ���������� ������ �� src � dest � ������������ 2 ���� CRC ��������� ������ 16 ������ ������
         @param apSrc �������� ����� �������� ����������������� �������
         @param apDest ������� �����, ���� ������������ ������ + CRC
         @param length ���������� ������ ���������������� ������
     */
////    static void WriteUserData(const uint8_t* pSrc, uint8_t* pDest, size_t length);

/** Write 10 header bytes to to buffer including 0x0564, all fields, and CRC */
////    static ser4cpp::rseq_t FormatHeader(ser4cpp::wseq_t& buffer,
////                                        uint8_t aDataLength,
////                                        bool aIsMaster,
////                                        bool aFcb,
////                                        bool aFcvDfc,
////                                        LinkFunction aFuncCode,
////                                        uint16_t aDest,
////                                        uint16_t aSrc,
////                                        Logger* pLogger);
////};
////
////////} // namespace opendnp3

////////////////////////////////////////////////
//	Functions for formatting outgoing Sec to Pri frames
////////////////////////////////////////////////
RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
RSeq_for_Uint16_t FormatNack_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
RSeq_for_Uint16_t FormatLinkStatus_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
RSeq_for_Uint16_t FormatNotSupported_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);

////////////////////////////////////////////////
//	Functions for formatting outgoing Pri to Sec frames
////////////////////////////////////////////////

RSeq_for_Uint16_t FormatTestLinkStatus_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aFcb, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
RSeq_for_Uint16_t FormatResetLinkStates_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
RSeq_for_Uint16_t FormatRequestLinkStatus_in_LinkFrame_static(
  WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
RSeq_for_Uint16_t FormatConfirmedUserData_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
    boolean aIsMaster,
    boolean aFcb,
    uint16_t aDest,
    uint16_t aSrc,
    RSeq_for_Uint16_t user_data);//,
//Logger* pLogger);
RSeq_for_Uint16_t FormatUnconfirmedUserData_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
    boolean aIsMaster,
    uint16_t aDest,
    uint16_t aSrc,
    RSeq_for_Uint16_t user_data);//,
//Logger* pLogger);

////////////////////////////////////////////////
//	Reusable static formatting functions to any buffer
////////////////////////////////////////////////

/** Reads data from src to dest removing 2 byte CRC checks every 16 data bytes
@param apSrc Source buffer with crc checks. Must begin at data, not header
@param apDest Destination buffer to which the data is extracted
@param aLength Length of user data to read to the dest buffer. The source buffer must be larger b/c of crc bytes.
*/
void ReadUserData_in_LinkFrame_static(uint8_t* apSrc, uint8_t* apDest, uint16_t len);

/** Validates FT3 user data integriry
@param apBody Beginning of the FT3 user data
@param aLength Number of user bytes to verify, not user + crc.
@return True if the body CRC is correct */
boolean ValidateBodyCRC_in_LinkFrame_static(uint8_t* apBody, uint16_t aLength);

// @return Total frame size based on user data length
uint16_t CalcFrameSize_in_LinkFrame_static(uint16_t dataLength);

////private:
uint16_t CalcUserDataSize_in_LinkFrame_static(uint16_t dataLength);

/** Writes data from src to dest interlacing 2 byte CRC checks every 16 data bytes
    @param apSrc Source buffer full of user data
    @param apDest Destination buffer where the data + CRC is written
    @param length Number of user data bytes
*/
void WriteUserData_in_LinkFrame_static(uint8_t* pSrc, uint8_t* pDest, uint16_t length);

/** Write 10 header bytes to to buffer including 0x0564, all fields, and CRC */
RSeq_for_Uint16_t FormatHeader_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
    uint8_t aDataLength,
    boolean aIsMaster,
    boolean aFcb,
    boolean aFcvDfc,
    LinkFunction_uint8_t aFuncCode,
    uint16_t aDest,
    uint16_t aSrc);//,
////                                        Logger* pLogger);

#endif
