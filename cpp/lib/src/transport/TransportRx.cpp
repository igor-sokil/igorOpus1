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
#include "TransportRx.h"

#include "TransportConstants.h"
#include "TransportHeader.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <ser4cpp/util/HexConversions.h>

////#include <cstring>

////namespace opendnp3
////{

////TransportRx::TransportRx(const Logger& logger, uint32_t maxRxFragSize)
////    : logger(logger), rxBuffer(maxRxFragSize), numBytesRead(0)
void TransportRx_in_TransportRx(TransportRx *pTransportRx, uint32_t maxRxFragSize)
{
  Rx_Transport_in_Rx_Transport(&(pTransportRx->statistics));
  SequenceNum_for_uint8_Modulus64_in_SequenceNum_for_uint8_Modulus64Over1(&(pTransportRx->expectedSeq));
  Addresses_in_AddressesOver1(&(pTransportRx->lastAddresses));
//void BufferSer4_in_BufferSer4Over2(BufferSer4 *pBufferSer4, uint16_t length);
//// rxBuffer(maxRxFragSize), numBytesRead(0)
  BufferSer4_in_BufferSer4Over2(&(pTransportRx->rxBuffer), maxRxFragSize);
  pTransportRx->numBytesRead = 0;
}

////void TransportRx::Reset()
void Reset_in_TransportRx(TransportRx *pTransportRx)
{
//    void ClearRxBuffer_in_TransportRx(TransportRx *pTransportRx);
////    this->ClearRxBuffer();
  ClearRxBuffer_in_TransportRx(pTransportRx);
}

////void TransportRx::ClearRxBuffer()
void ClearRxBuffer_in_TransportRx(TransportRx *pTransportRx)
{
  pTransportRx->numBytesRead = 0;
}

////ser4cpp::wseq_t TransportRx::GetAvailable()
WSeq_for_Uint16_t GetAvailable_in_TransportRx(TransportRx *pTransportRx)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{GetAvailable_in_TransportRx1"<<'\n';
#endif
//WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////    return rxBuffer.as_wslice().skip(numBytesRead);
  WSeq_for_Uint16_t wtemp = as_wslice_in_BufferSer4(&(pTransportRx->rxBuffer));
  WSeq_for_Uint16_t tmp = skip_in_WSeq_for_Uint16_t(&wtemp, pTransportRx->numBytesRead);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}GetAvailable_in_TransportRx_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

////Message TransportRx::ProcessReceive(const Message& segment)
Message ProcessReceive_in_TransportRx(TransportRx *pTransportRx, Message* segment)
{
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessReceive_in_TransportRx1"<<'\n';
#endif
  ++(pTransportRx->statistics.numTransportRx);

////    if (segment.payload.is_empty())
  if(is_empty_in_HasLength_for_Uint16_t(&(segment->payload.hHasLength)))
  {
////        FORMAT_LOG_BLOCK(logger, flags::WARN, "Received tpdu with no header");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::WARN, 'Received tpdu with no header')"<<'\n';
    std::cout<<getString_stack_info();
    std::cout<<"}ProcessReceive_in_TransportRx1_"<<'\n';
    decrement_stack_info();
#endif

////        ++statistics.numTransportErrorRx;
    ++(pTransportRx->statistics.numTransportErrorRx);

//void  Message_in_MessageOver1(Message *pMessage)
////        return Message();
    Message mMessage;
    Message_in_MessageOver1(&mMessage);
    return mMessage;
  }

//void TransportHeader_in_TransportHeader(TransportHeader *pTransportHeader, uint8_t byte);
////    const TransportHeader header(segment.payload[0]);
  TransportHeader header;
  TransportHeader_in_TransportHeader(&header, segment->payload.buffer_[0]);

//RSeq_for_Uint16_t skip_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////    const auto payload = segment.payload.skip(1);
  RSeq_for_Uint16_t payload = skip_in_RSeq_for_Uint16_t(&(segment->payload), 1);

////    FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_RX, "FIR: %d FIN: %d SEQ: %u LEN: %zu", header.fir, header.fin,
////                     header.seq, payload.length());
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_RX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', header.fir, header.fin"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FIR: "<<(uint16_t)header.fir<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FIN: "<<(uint16_t)header.fin<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*SEQ: "<<(uint16_t)header.seq<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*LEN: "<<(uint16_t)length_in_HasLength_for_Uint16_t(&(payload.hHasLength))<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pTransportRx->numBytesRead= "<<(uint16_t)pTransportRx->numBytesRead<<'\n';
#endif

  if (header.fir && (pTransportRx->numBytesRead > 0))
  {
////        ++statistics.numTransportDiscard;
    ++(pTransportRx->statistics.numTransportDiscard);

////        SIMPLE_LOG_BLOCK(logger, flags::WARN, "FIR received mid-fragment, discarding previous bytes");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::WARN, 'FIR received mid-fragment, discarding previous bytes')"<<'\n';
//FIR получил средний фрагмент, отбросив предыдущие байты.
#endif

    pTransportRx->numBytesRead = 0;
    // continue processing
  }

  // there are special checks we must perform if it isn't the first packet
// есть специальные проверки, которые мы должны выполнить, если это не первый пакет
  if (!header.fir)
  {
    if (pTransportRx->numBytesRead == 0)
    {
      ++(pTransportRx->statistics.numTransportIgnore);

////            SIMPLE_LOG_BLOCK(logger, flags::WARN, "non-FIR packet with 0 prior bytes");
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::WARN, 'non-FIR packet with 0 prior bytes')"<<'\n';
      std::cout<<getString_stack_info();
      std::cout<<"}ProcessReceive_in_TransportRx2_"<<'\n';
      decrement_stack_info();
#endif

////            return Message(); // drop the data
      Message mMessage;
      Message_in_MessageOver1(&mMessage);
      return mMessage;
    }

    if (header.seq != pTransportRx->expectedSeq.seq)
    {
      ++(pTransportRx->statistics.numTransportIgnore);
////            FORMAT_LOG_BLOCK(logger, flags::WARN, "Received segment w/ seq: %u, expected: %u", header.seq,
///                             this->expectedSeq.Get());
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::WARN, 'Received segment w/ seq: %u, expected: %u', header.seq"<<'\n';
      std::cout<<getString_stack_info();
      std::cout<<"}ProcessReceive_in_TransportRx3_"<<'\n';
      decrement_stack_info();
#endif

////            return Message(); // drop the data
      Message mMessage;
      Message_in_MessageOver1(&mMessage);
      return mMessage;
    }

//boolean operatorNOTEQ_in_Addresses(Addresses *pAddresses, Addresses* other);
////    if (segment.addresses != pTransportRx->lastAddresses)
    if (operatorNOTEQ_in_Addresses(&(segment->addresses), &(pTransportRx->lastAddresses)))
    {
      ++(pTransportRx->statistics.numTransportIgnore);
////            FORMAT_LOG_BLOCK(logger, flags::WARN,
////                             "Bad addressing: last { src: %u, dest: %u } received { src: %u, dest: %u}",
////                             this->lastAddresses.source, this->lastAddresses.destination, segment.addresses.source,
////                             segment.addresses.destination);
#ifdef  LOG_INFO
      std::cout<<"*"<<getString_stack_info();
      std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::WARN,'Bad addressing: last { src: %u, dest: %u } received { src: %u, dest: %u}'"<<'\n';
      std::cout<<getString_stack_info();
      std::cout<<"}ProcessReceive_in_TransportRx4_"<<'\n';
      decrement_stack_info();
#endif

////            return Message(); // drop the data
      Message mMessage;
      Message_in_MessageOver1(&mMessage);
      return mMessage;
    }
  }

//WSeq_for_Uint16_t GetAvailable_in_TransportRx(TransportRx *pTransportRx);
////    auto available = this->GetAvailable();
  WSeq_for_Uint16_t available = GetAvailable_in_TransportRx(pTransportRx);

////    if (payload.length() > available.length())
  if(length_in_HasLength_for_Uint16_t(&(payload.hHasLength)) > length_in_HasLength_for_Uint16_t(&(available.hHasLength)))
  {
    // transport buffer overflow
    ++(pTransportRx->statistics.numTransportBufferOverflow);

////        SIMPLE_LOG_BLOCK(logger, flags::WARN, "Exceeded the buffer size before a complete fragment was read");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::WARN, 'Exceeded the buffer size before a complete fragment was read')"<<'\n';
//Превышен размер буфера до того, как был прочитан полный фрагмент.
    std::cout<<getString_stack_info();
    std::cout<<"}ProcessReceive_in_TransportRx5_"<<'\n';
    decrement_stack_info();
#endif

    pTransportRx->numBytesRead = 0;
////        return Message();
    Message mMessage;
    Message_in_MessageOver1(&mMessage);
    return mMessage;
  }

//RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src);
////    available.copy_from(payload);
  copy_from_in_WSeq_for_Uint16_t(&available, &payload);

////    this->numBytesRead += payload.length();
  pTransportRx->numBytesRead += length_in_HasLength_for_Uint16_t(&(payload.hHasLength));

  pTransportRx->lastAddresses = segment->addresses;
  pTransportRx->expectedSeq.seq = header.seq;
////    this->expectedSeq.Increment();
  Increment_in_SequenceNum_for_uint8_Modulus64(&(pTransportRx->expectedSeq));

  if (header.fin)
  {
//RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////        const auto ret = rxBuffer.as_rslice().take(numBytesRead);
    RSeq_for_Uint16_t tmp = as_rslice_in_BufferSer4(&(pTransportRx->rxBuffer));
    RSeq_for_Uint16_t ret = take_in_RSeq_for_Uint16_t(&tmp, pTransportRx->numBytesRead);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ProcessReceive_in_TransportRx6_"<<'\n';
    decrement_stack_info();
#endif

    pTransportRx->numBytesRead = 0;

//void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
////        return Message(segment.addresses, ret);
    Message mMessage;
    Message_in_Message(&mMessage, &(segment->addresses), &ret);
    return mMessage;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessReceive_in_TransportRx7_"<<'\n';
  decrement_stack_info();
#endif
////    return Message();
  Message mMessage;
  Message_in_MessageOver1(&mMessage);
  return mMessage;
}

////} // namespace opendnp3
Rx_Transport* Statistics_in_TransportRx(TransportRx *pTransportRx)
{
  return &pTransportRx->statistics;
}
