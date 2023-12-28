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
#ifndef OPENDNP3_TRANSPORTRX_H
#define OPENDNP3_TRANSPORTRX_H

#include "Message.h"
#include "TransportConstants.h"
#include "TransportSeqNum.h"

#include "StackStatistics.h"
////#include "opendnp3/logging/Logger.h"

#include <BufferSer4.h>
////#include <ser4cpp/container/SequenceTypes.h>

////namespace opendnp3
////{

/**
State/validation for the DNP3 transport layer's receive channel.
Состояние/проверка канала приема транспортного уровня DNP3.
*/
////class TransportRx
typedef struct
{

////public:
////    TransportRx(const Logger&, uint32_t maxRxFragSize);

////    Message ProcessReceive(const Message& segment);

////    void Reset();

////    const StackStatistics::Transport::Rx& Statistics() const
////    {
////        return statistics;
////    }

////private:
////    ser4cpp::wseq_t GetAvailable();

////    void ClearRxBuffer();

////    Logger logger;
////    StackStatistics::Transport::Rx statistics;
  Rx_Transport statistics;

////    ser4cpp::Buffer rxBuffer;
  BufferSer4 rxBuffer;

  uint16_t numBytesRead;
  Addresses lastAddresses;

  TransportSeqNum expectedSeq;
} TransportRx;

void TransportRx_in_TransportRx(TransportRx *pTransportRx, uint32_t maxRxFragSize);

Message ProcessReceive_in_TransportRx(TransportRx *pTransportRx, Message* segment);

void Reset_in_TransportRx(TransportRx *pTransportRx);

Rx_Transport* Statistics_in_TransportRx(TransportRx *pTransportRx);
WSeq_for_Uint16_t GetAvailable_in_TransportRx(TransportRx *pTransportRx);

void ClearRxBuffer_in_TransportRx(TransportRx *pTransportRx);



////} // namespace opendnp3

#endif
