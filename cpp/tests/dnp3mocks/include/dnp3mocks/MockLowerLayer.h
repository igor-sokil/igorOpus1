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
#ifndef OPENDNP3_UNITTESTS_MOCKLOWERLAYER_H
#define OPENDNP3_UNITTESTS_MOCKLOWERLAYER_H

#include "LayerInterfaces.h"
#include "RSeq.h"
#include "HexConversions.h"

#include <queue>
////#include <string>

/*
typedef struct
{

////public:
////    virtual ~ILowerLayer() {}

   boolean (*pBeginTransmit_in_ILowerLayer)(void*, Message* message);// = 0;

  void* pParentPointer_in_ILowerLayer;
} ILowerLayer;
*/
/*
typedef struct
{

////public:
////    HasUpperLayer() : pUpperLayer(nullptr) {}

    // Called by the lower layer when data arrives

////    void SetUpperLayer(IUpperLayer& upperLayer)
////    {
////        assert(!pUpperLayer);
////        pUpperLayer = &upperLayer;
////    }

////protected:
    IUpperLayer* pUpperLayer;
} HasUpperLayer;
*/
////class MockLowerLayer : public opendnp3::ILowerLayer, public opendnp3::HasUpperLayer
typedef struct
{
  ILowerLayer iILowerLayer;
  HasUpperLayer hHasUpperLayer;

////public:
////    void SendUp(const ser4cpp::rseq_t& data, const opendnp3::Addresses& addresses = opendnp3::Addresses());
////    void SendUp(const std::string& arHexData, const opendnp3::Addresses& addresses = opendnp3::Addresses());

////    void SendComplete();
////    void ThisLayerUp();
////    void ThisLayerDown();

////    bool HasNoData() const;

////    size_t NumWrites() const;
////    std::string PopWriteAsHex();

////    virtual bool BeginTransmit(const opendnp3::Message& message) override final;

////private:
////    std::queue<opendnp3::Message> sendQueue;
  std::queue<Message> sendQueue;
} MockLowerLayer;

void MockLowerLayer_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer);

////    void SendUp(const ser4cpp::rseq_t& data, const opendnp3::Addresses& addresses = opendnp3::Addresses());
void SendUp_in_MockLowerLayerOver1(MockLowerLayer *pMockLowerLayer, RSeq_for_Uint16_t* data, Addresses* addresses);//// = opendnp3::Addresses());
////    void SendUp(const std::string& arHexData, const opendnp3::Addresses& addresses = opendnp3::Addresses());
void SendUp_in_MockLowerLayerOver2(MockLowerLayer *pMockLowerLayer, const std::string& arHexData, Addresses* addresses);//// = opendnp3::Addresses());

////    void SendComplete();
void SendComplete_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer);
////    void ThisLayerUp();
void ThisLayerUp_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer);
////    void ThisLayerDown();
void ThisLayerDown_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer);

////    bool HasNoData() const;
boolean HasNoData_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer);

////    size_t NumWrites() const;
uint16_t NumWrites_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer);
////    std::string PopWriteAsHex();
std::string  PopWriteAsHex_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer);

////    virtual bool BeginTransmit(const opendnp3::Message& message) override final;
boolean BeginTransmit_in_MockLowerLayer_override(void*, Message* message);
boolean BeginTransmit_in_MockLowerLayer(MockLowerLayer* pMockLowerLayer, Message* message);

#endif
