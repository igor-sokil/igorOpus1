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
#include "TransportTx.h"

#include "TransportHeader.h"
#include "SerializationTemplates.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////#include <cassert>

////namespace opendnp3
////{

////TransportTx::TransportTx(const Logger& logger) : logger(logger) {}
void TransportTx_in_TransportTx(TransportTx *pTransportTx)
{
  Settable_for_RSeq_t_in_Settable_for_RSeq_t(&(pTransportTx->txSegment));
  Tx_Transport_in_Tx_Transport(&(pTransportTx->statistics));
  SequenceNum_for_uint8_Modulus64_in_SequenceNum_for_uint8_Modulus64Over1(&(pTransportTx->sequence));
  pTransportTx->tpduCount = 0;

  pTransportTx->iITransportSegment.pGetAddresses_in_ITransportSegment = GetAddresses_in_TransportTx_override;
  pTransportTx->iITransportSegment.pHasValue_in_ITransportSegment = HasValue_in_TransportTx_override;
  pTransportTx->iITransportSegment.pGetSegment_in_ITransportSegment = GetSegment_in_TransportTx_override;
  pTransportTx->iITransportSegment.pAdvance_in_ITransportSegment = Advance_in_TransportTx_override;
  setParentPointer_in_ITransportSegment(&(pTransportTx->iITransportSegment), pTransportTx);
}

////void TransportTx::Configure(const Message& message)
void Configure_in_TransportTx(TransportTx *pTransportTx, Message* message)
{
////    assert(message.payload.is_not_empty());
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  if(!is_not_empty_in_HasLength_for_Uint16_t(&(message->payload.hHasLength))) std::cout<<"*assert(message.payload.is_not_empty())"<<'\n';
  decrement_stack_info();
#endif

//void clear_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
///    txSegment.clear();
  clear_in_Settable_for_RSeq_t(&(pTransportTx->txSegment));

  pTransportTx->message = *message;

  pTransportTx->tpduCount = 0;
}

////bool TransportTx::HasValue() const
boolean HasValue_in_TransportTx(TransportTx *pTransportTx)
{
//uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    return this->message.payload.length() > 0;
  return length_in_HasLength_for_Uint16_t(&(pTransportTx->message.payload.hHasLength));
}

////ser4cpp::rseq_t TransportTx::GetSegment()
RSeq_for_Uint16_t GetSegment_in_TransportTx(TransportTx *pTransportTx)
{
//boolean is_set_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
////    if (txSegment.is_set())
  if (is_set_in_Settable_for_RSeq_t(&(pTransportTx->txSegment)))
  {
//RSeq_for_Uint16_t get_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
///        return txSegment.get();
    return get_in_Settable_for_RSeq_t(&(pTransportTx->txSegment));
  }

////    const size_t numToSend
////        = (this->message.payload.length() < MAX_TPDU_PAYLOAD) ? this->message.payload.length() : MAX_TPDU_PAYLOAD;
  uint16_t numToSend =
    (length_in_HasLength_for_Uint16_t(&(pTransportTx->message.payload.hHasLength)) < MAX_TPDU_PAYLOAD) ?
    length_in_HasLength_for_Uint16_t(&(pTransportTx->message.payload.hHasLength)) : MAX_TPDU_PAYLOAD;

//WSeq_for_Uint16_t skip_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, uint16_t count);
////    auto dest = tpduBuffer.as_wseq().skip(1);
  WSeq_for_Uint16_t wtemp = as_wseq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver1(&(pTransportTx->tpduBuffer));
  WSeq_for_Uint16_t dest = skip_in_WSeq_for_Uint16_t(&wtemp, 1);

//RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
//RSeq_for_Uint16_t copy_from_in_WSeq_for_Uint16_t(WSeq_for_Uint16_t *pWSeq_for_Uint16_t, RSeq_for_Uint16_t *src);
////    dest.copy_from(this->message.payload.take(numToSend));
  RSeq_for_Uint16_t rtemp = take_in_RSeq_for_Uint16_t(&(pTransportTx->message.payload), numToSend);
  copy_from_in_WSeq_for_Uint16_t(&dest, &rtemp);

////    bool fir = (tpduCount == 0);
  boolean fir = (pTransportTx->tpduCount == 0);

////    bool fin = (numToSend == this->message.payload.length());
  boolean fin = (numToSend == length_in_HasLength_for_Uint16_t(&(pTransportTx->message.payload.hHasLength)));

////    auto destHeader = tpduBuffer.as_wseq();
  WSeq_for_Uint16_t destHeader = as_wseq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver1(&(pTransportTx->tpduBuffer));

//uint8_t ToByte_in_TransportHeader_static(boolean fir, boolean fin, uint8_t seq);
//boolean write_to_in_UInt8_static(WSeq_for_Uint16_t *dest, uint8_t value);
////    ser4cpp::UInt8::write_to(destHeader, TransportHeader::ToByte(fir, fin, sequence));
  write_to_in_UInt8_static(&destHeader, ToByte_in_TransportHeader_static(fir, fin, pTransportTx->sequence.seq));

////    FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_TX, "FIR: %d FIN: %d SEQ: %u LEN: %zu", fir, fin, sequence.Get(),
////                     numToSend);
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::TRANSPORT_TX, 'FIR: %d FIN: %d SEQ: %u LEN: %zu', fir, fin, sequence.Get()"<<'\n';
  decrement_stack_info();
#endif

////    ++statistics.numTransportTx;
  ++(pTransportTx->statistics.numTransportTx);

//RSeq_for_Uint16_t as_seq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver2(StaticBuffer_for_MAX_TPDU_LENGTH *pStaticBuffer, uint16_t max_size);
////    auto segment = tpduBuffer.as_seq(numToSend + 1);
  RSeq_for_Uint16_t segment = as_seq_in_StaticBuffer_for_MAX_TPDU_LENGTHOver2(&(pTransportTx->tpduBuffer),
                              numToSend + 1);

//void set_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t, RSeq_for_Uint16_t *value_);
////    txSegment.set(segment);
  set_in_Settable_for_RSeq_t(&(pTransportTx->txSegment), &segment);

  return segment;
}

////bool TransportTx::Advance()
boolean Advance_in_TransportTx(TransportTx *pTransportTx)
{
//void clear_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
////    txSegment.clear();
  clear_in_Settable_for_RSeq_t(&(pTransportTx->txSegment));

////    size_t numToSend
////        = this->message.payload.length() < MAX_TPDU_PAYLOAD ? this->message.payload.length() : MAX_TPDU_PAYLOAD;
  uint16_t numToSend =
    (length_in_HasLength_for_Uint16_t(&(pTransportTx->message.payload.hHasLength)) < MAX_TPDU_PAYLOAD) ?
    length_in_HasLength_for_Uint16_t(&(pTransportTx->message.payload.hHasLength)) : MAX_TPDU_PAYLOAD;

//void advance_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
////    this->message.payload.advance(numToSend);
  advance_in_RSeq_for_Uint16_t(&(pTransportTx->message.payload), numToSend);

////    ++tpduCount;
  ++(pTransportTx->tpduCount);

////    sequence.Increment();
  Increment_in_SequenceNum_for_uint8_Modulus64(&(pTransportTx->sequence));

//boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    return this->message.payload.is_not_empty();
  return is_not_empty_in_HasLength_for_Uint16_t(&(pTransportTx->message.payload.hHasLength));
}

////} // namespace opendnp3
// -------  IBufferSegment ------------

Addresses* GetAddresses_in_TransportTx(TransportTx *pTransportTx)
{
  return &(pTransportTx->message.addresses);
}

Addresses* GetAddresses_in_TransportTx_override(void *pITransportSegment)
{
  TransportTx* parent = (TransportTx*)getParentPointer_in_ITransportSegment((ITransportSegment*) pITransportSegment);
  return GetAddresses_in_TransportTx(parent);
}

boolean HasValue_in_TransportTx_override(void *pITransportSegment)
{
  TransportTx* parent = (TransportTx*)getParentPointer_in_ITransportSegment((ITransportSegment*) pITransportSegment);
  return HasValue_in_TransportTx(parent);
}

RSeq_for_Uint16_t GetSegment_in_TransportTx_override(void *pITransportSegment)
{
  TransportTx* parent = (TransportTx*)getParentPointer_in_ITransportSegment((ITransportSegment*) pITransportSegment);
  return GetSegment_in_TransportTx(parent);
}

boolean Advance_in_TransportTx_override(void *pITransportSegment)
{
  TransportTx* parent = (TransportTx*)getParentPointer_in_ITransportSegment((ITransportSegment*) pITransportSegment);
  return Advance_in_TransportTx(parent);
}


Tx_Transport* Statistics_in_TransportTx(TransportTx *pTransportTx)
{
  return &(pTransportTx->statistics);
}
