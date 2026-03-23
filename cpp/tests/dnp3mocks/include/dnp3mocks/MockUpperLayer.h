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
#ifndef OPENDNP3_UNITTESTS_MOCKUPPERLAYER_H
#define OPENDNP3_UNITTESTS_MOCKUPPERLAYER_H

#include "DataSink.h"

#include "LayerInterfaces.h"
#include "RSeq.h"
#include <string>

////    struct Counters_in_MockUpperLayer
typedef struct
{
  uint16_t numTxReady;// = 0;
  uint16_t numLayerUp;// = 0;
  uint16_t numLayerDown;// = 0;
} Counters_in_MockUpperLayer;

void Counters_in_MockUpperLayer_in_Counters_in_MockUpperLayer(Counters_in_MockUpperLayer *pCounters_in_MockUpperLayer);

////class MockUpperLayer final : public opendnp3::IUpperLayer, public opendnp3::HasLowerLayer
typedef struct
{
  IUpperLayer iIUpperLayer;
  HasLowerLayer hHasLowerLayer;

////public:
////    struct Counters
////    {
////        size_t numTxReady = 0;
////        size_t numLayerUp = 0;
////        size_t numLayerDown = 0;
////    };

////    MockUpperLayer();

////    bool IsOnline() const
////    {
////        return isOnline;
////    }

////    bool SendDown(const std::string& hex, const opendnp3::Addresses& addresses = opendnp3::Addresses());
////    bool SendDown(const ser4cpp::rseq_t& data, const opendnp3::Addresses& addresses = opendnp3::Addresses());

////    const Counters& GetCounters() const
////    {
////        return counters;
////    }

  // these are the NVII delegates
////    virtual bool OnReceive(const opendnp3::Message& message) override;
////    virtual bool OnTxReady() override;
////    virtual bool OnLowerLayerUp() override;
////    virtual bool OnLowerLayerDown() override;

  DataSink received;

////private:
  boolean isOnline_in_MockUpperLayer;
  Counters_in_MockUpperLayer counters;
  RSeq_for_Uint16_t rRSeqReceived;//сохр результат
} MockUpperLayer;

void MockUpperLayer_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer);

boolean OnLowerLayerDown_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer);
boolean OnLowerLayerUp_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer);
boolean OnTxReady_in_MockUpperLayer(MockUpperLayer *pMockTransportLayer);
boolean OnReceive_in_MockUpperLayer(MockUpperLayer *pMockTransportLayer, Message* message);

boolean OnLowerLayerDown_in_MockUpperLayer_override(void *pIUpDown);
boolean OnLowerLayerUp_in_MockUpperLayer_override(void *pIUpDown);
boolean OnTxReady_in_MockUpperLayer_override(void *pIUpperLayer);
boolean OnReceive_in_MockUpperLayer_override(void *pIUpperLayer, Message* message);

////    bool IsOnline() const
////    {
////        return isOnline;
////    }
boolean IsOnline_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer);
Counters_in_MockUpperLayer GetCounters_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer);

////    bool SendDown(const std::string& hex, const opendnp3::Addresses& addresses = opendnp3::Addresses());
////    bool SendDown(const ser4cpp::rseq_t& data, const opendnp3::Addresses& addresses = opendnp3::Addresses());

boolean SendDown_in_MockUpperLayerOver1(MockUpperLayer *pMockUpperLayer, std::string& hex, Addresses* addresses);//// = opendnp3::Addresses());
boolean SendDown_in_MockUpperLayerOver2(MockUpperLayer *pMockUpperLayer, RSeq_for_Uint16_t* data, Addresses* addresses);/// = opendnp3::Addresses());

////    const Counters& GetCounters() const
////    {
////        return counters;
////    }

#endif
