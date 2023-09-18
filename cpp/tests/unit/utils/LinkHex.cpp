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
////#include "utils/LinkHex.h"

////#include "utils/BufferHelpers.h"

////#include <ser4cpp/container/StaticBuffer.h>
////#include <ser4cpp/util/HexConversions.h>

////#include <link/LinkFrame.h>
#include <QApplication>
#include "header.h"
#include "LinkHex.h"
#include "StaticBuffer_for_LPDU_MAX_FRAME_SIZE.h"

////#include "BufferHelpers.h"

////#include <ser4cpp/container/StaticBuffer.h>
#include "HexConversions.h"

#include "LinkFrame.h"

////using namespace opendnp3;
////using namespace ser4cpp;

////std::string LinkHex::Ack(bool master, bool isRxBuffFull, uint16_t dest, uint16_t src)
std::string Ack_in_LinkHex_static(boolean master, boolean isRxBuffFull, uint16_t dest, uint16_t src)
{
////    StaticBuffer<292> buffer;
  StaticBuffer_for_LPDU_MAX_FRAME_SIZE buffer;

//WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(StaticBuffer_for_LPDU_MAX_FRAME_SIZE *pStaticBuffer);
////    auto output = buffer.as_wseq();
  WSeq_for_Uint16_t  output = as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(&buffer);

//    RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
//        WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
//    std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
////    return HexConversions::to_hex(LinkFrame::FormatAck(output, master, isRxBuffFull, dest, src, nullptr));
  RSeq_for_Uint16_t temp = FormatAck_in_LinkFrame_static(
                             &output, master, isRxBuffFull, dest, src);//, Logger* pLogger);
  return to_hex_in_HexConversionsOver2(&temp, true);
}

////std::string LinkHex::Nack(bool master, bool isRxBuffFull, uint16_t dest, uint16_t src)
////{
////    StaticBuffer<292> buffer;
////    auto output = buffer.as_wseq();
////    return HexConversions::to_hex(LinkFrame::FormatNack(output, master, isRxBuffFull, dest, src, nullptr));
////}

////std::string LinkHex::LinkStatus(bool master, bool isRxBuffFull, uint16_t dest, uint16_t src)
std::string LinkStatus_in_LinkHex_static(boolean master, boolean isRxBuffFull, uint16_t dest, uint16_t src)
{
////    StaticBuffer<292> buffer;
  StaticBuffer_for_LPDU_MAX_FRAME_SIZE buffer;
////    auto output = buffer.as_wseq();
  WSeq_for_Uint16_t  output = as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(&buffer);
//RSeq_for_Uint16_t FormatLinkStatus_in_LinkFrame_static(
//  WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    return HexConversions::to_hex(LinkFrame::FormatLinkStatus(output, master, isRxBuffFull, dest, src, nullptr));
  RSeq_for_Uint16_t rseq = FormatLinkStatus_in_LinkFrame_static(
             &output, master, isRxBuffFull, dest, src);//, Logger* pLogger);
  return to_hex_in_HexConversionsOver2(&rseq, true);
}

////std::string LinkHex::NotSupported(bool master, bool isRxBuffFull, uint16_t dest, uint16_t src)
////{
////    StaticBuffer<292> buffer;
////    auto output = buffer.as_wseq();
////    return HexConversions::to_hex(LinkFrame::FormatNotSupported(output, master, isRxBuffFull, dest, src, nullptr));
////}

////std::string LinkHex::TestLinkStatus(bool master, bool fcb, uint16_t dest, uint16_t src)
////{
////    StaticBuffer<292> buffer;
////    auto output = buffer.as_wseq();
////    return HexConversions::to_hex(LinkFrame::FormatTestLinkStatus(output, master, fcb, dest, src, nullptr));
////}

////std::string LinkHex::ResetLinkStates(bool master, uint16_t dest, uint16_t src)
////{
////    StaticBuffer<292> buffer;
////    auto output = buffer.as_wseq();
////    return HexConversions::to_hex(LinkFrame::FormatResetLinkStates(output, master, dest, src, nullptr));
////}

////std::string LinkHex::RequestLinkStatus(bool master, uint16_t dest, uint16_t src)
////{
////    StaticBuffer<292> buffer;
////    auto output = buffer.as_wseq();
////    return HexConversions::to_hex(LinkFrame::FormatRequestLinkStatus(output, master, dest, src, nullptr));
////}

////std::string LinkHex::ConfirmedUserData(
////    bool master, bool fcb, uint16_t dest, uint16_t src, const std::string& userDataHex)
////{
////    HexSequence hs(userDataHex);
////    auto data = hs.ToRSeq();
////
////    StaticBuffer<292> buffer;
////    auto output = buffer.as_wseq();
////    return HexConversions::to_hex(LinkFrame::FormatConfirmedUserData(output, master, fcb, dest, src, data, nullptr));
////}

////std::string LinkHex::UnconfirmedUserData(bool master, uint16_t dest, uint16_t src, const std::string& userDataHex)
////{
////    HexSequence hs(userDataHex);
////    auto data = hs.ToRSeq();
////
////    StaticBuffer<292> buffer;
////    auto output = buffer.as_wseq();
////    return HexConversions::to_hex(LinkFrame::FormatUnconfirmedUserData(output, master, dest, src, data, nullptr));
////}
