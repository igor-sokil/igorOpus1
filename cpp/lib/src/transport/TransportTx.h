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
#ifndef OPENDNP3_TRANSPORTTX_H
#define OPENDNP3_TRANSPORTTX_H

#include "Message.h"
#include "ITransportSegment.h"
#include "TransportConstants.h"
#include "TransportSeqNum.h"

#include "StackStatistics.h"
///#include "opendnp3/logging/Logger.h"

#include "Settable_for_RSeq.h"
#include "StaticBuffer_for_MAX_TPDU_LENGTH.h"

////namespace opendnp3
////{

/**
State/validation for the DNP3 transport layer's send channel.
*/
////class TransportTx final : public ITransportSegment
typedef struct
{
  ITransportSegment iITransportSegment;
////public:
////    TransportTx(const Logger& logger);

////    void Configure(const Message& message);

  // -------  IBufferSegment ------------

////    virtual const Addresses& GetAddresses() const override
////    {
////        return this->message.addresses;
////    }

////    virtual bool HasValue() const override;

////    virtual ser4cpp::rseq_t GetSegment() override;

////    virtual bool Advance() override;

////    const StackStatistics::Transport::Tx& Statistics() const
////    {
////        return statistics;
////    }

////private:
  Message message;

////   ser4cpp::Settable<ser4cpp::rseq_t> txSegment;
  Settable_for_RSeq_t  txSegment;

  // Static buffer where we store tpdus that are being transmitted
  ////ser4cpp::StaticBuffer<MAX_TPDU_LENGTH> tpduBuffer;
  StaticBuffer_for_MAX_TPDU_LENGTH  tpduBuffer;

///    Logger logger;
//    StackStatistics::Transport::Tx statistics;
  Tx_Transport  statistics;

  TransportSeqNum sequence;
  uint32_t tpduCount;// = 0;
} TransportTx;

void TransportTx_in_TransportTx(TransportTx *pTransportTx);
void Configure_in_TransportTx(TransportTx *pTransportTx, Message* message);

Addresses* GetAddresses_in_TransportTx(TransportTx *pTransportTx);
Addresses* GetAddresses_in_TransportTx_override(void *pITransportSegment);

boolean HasValue_in_TransportTx(TransportTx *pTransportTx);
boolean HasValue_in_TransportTx_override(void *pITransportSegment);

RSeq_for_Uint16_t GetSegment_in_TransportTx(TransportTx *pTransportTx);
RSeq_for_Uint16_t GetSegment_in_TransportTx_override(void *pITransportSegment);

boolean Advance_in_TransportTx(TransportTx *pTransportTx);
boolean Advance_in_TransportTx_override(void *pITransportSegment);

Tx_Transport* Statistics_in_TransportTx(TransportTx *pTransportTx);


////} // namespace opendnp3

#endif
