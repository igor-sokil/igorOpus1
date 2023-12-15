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
#include <QApplication>
#include "header.h"
#include "MockLowerLayer.h"

//uint8_t Message_in_MockLowerLayer[100];
////#include <ser4cpp/util/HexConversions.h>

////#include <cassert>

////using namespace opendnp3;
////using namespace ser4cpp;

void MockLowerLayer_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
{
  HasUpperLayer_in_HasUpperLayer(&(pMockLowerLayer->hHasUpperLayer));

  pMockLowerLayer->iILowerLayer.pBeginTransmit_in_ILowerLayer = BeginTransmit_in_MockLowerLayer_override;
  setParentPointer_in_ILowerLayer(&(pMockLowerLayer->iILowerLayer), pMockLowerLayer);
}

////bool MockLowerLayer::HasNoData() const
boolean HasNoData_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{HasNoData_in_MockLowerLayer1"<<'\n';

  std::cout<<"}HasNoData_in_MockLowerLayer_"<<'\n';
#endif
  return pMockLowerLayer->sendQueue.empty();
}

////size_t MockLowerLayer::NumWrites() const
uint16_t NumWrites_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
{
  return pMockLowerLayer->sendQueue.size();
}

//Message mMessage1_global_in_MockLowerLayer;
////std::string MockLowerLayer::PopWriteAsHex()
std::string  PopWriteAsHex_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{PopWriteAsHex_in_MockLowerLayer1"<<'\n';
#endif

  if (pMockLowerLayer->sendQueue.empty())
  {
#ifdef  LOG_INFO
  std::cout<<"}PopWriteAsHex_in_MockLowerLayer1_"<<'\n';
#endif
        return "";
  }

  Message ret = pMockLowerLayer->sendQueue.front();
//inspect_RSeq(&(ret.payload));

  pMockLowerLayer->sendQueue.pop();

#ifdef  LOG_INFO
  std::cout<<"}PopWriteAsHex_in_MockLowerLayer2_"<<'\n';
#endif
//std::string to_hex_in_HexConversionsOver2(RSeq_for_Uint16_t* buffer, bool spaced = true);
////    return HexConversions::to_hex(ret.payload);
  return to_hex_in_HexConversionsOver2(&(ret.payload), true);
}

////bool MockLowerLayer::BeginTransmit(const Message& message)
boolean BeginTransmit_in_MockLowerLayer_override(void* pILowerLayer, Message* message)
{
  MockLowerLayer* parent = (MockLowerLayer*) getParentPointer_in_ILowerLayer((ILowerLayer*)pILowerLayer);
  return BeginTransmit_in_MockLowerLayer(parent, message);
}

boolean BeginTransmit_in_MockLowerLayer(MockLowerLayer* pMockLowerLayer, Message* message)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{BeginTransmit_in_MockLowerLayer1"<<'\n';
#endif

  Message temp = *message;
inspect_RSeq(&(temp.payload));

  pMockLowerLayer->sendQueue.push(temp);////message);
#ifdef  LOG_INFO
  std::cout<<"}BeginTransmit_in_MockLowerLayer_"<<'\n';
#endif
  return true;
}

////void MockLowerLayer::SendUp(const rseq_t& data, const Addresses& addresses)
void SendUp_in_MockLowerLayerOver1(MockLowerLayer *pMockLowerLayer, RSeq_for_Uint16_t* data, Addresses* addresses)//// = opendnp3::Addresses());
{
////    if (pUpperLayer)
  if(pMockLowerLayer->hHasUpperLayer.pUpperLayer)
  {
//boolean OnReceive_in_IUpperLayer(IUpperLayer *, Message* message);
//  void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
////        pUpperLayer->OnReceive(Message(addresses, data));
    Message mMessage;
    Message_in_Message(&mMessage, addresses, data);
    OnReceive_in_IUpperLayer(pMockLowerLayer->hHasUpperLayer.pUpperLayer, &mMessage);
  }
}

////void MockLowerLayer::SendUp(const std::string& arHexData, const Addresses& addresses)
////{
////    const auto buffer = HexConversions::from_hex(arHexData);
////    this->SendUp(buffer->as_rslice(), addresses);
////}

////void MockLowerLayer::SendComplete()
void SendComplete_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
{
////    if (pUpperLayer)
  if(pMockLowerLayer->hHasUpperLayer.pUpperLayer)
  {
//boolean OnTxReady_in_IUpperLayer(IUpperLayer *);
////        pUpperLayer->OnTxReady();
    OnTxReady_in_IUpperLayer(pMockLowerLayer->hHasUpperLayer.pUpperLayer);
  }
}

////void MockLowerLayer::ThisLayerUp()
void ThisLayerUp_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
{
////    if (pUpperLayer)
  if(pMockLowerLayer->hHasUpperLayer.pUpperLayer)
  {
//boolean OnLowerLayerDown_in_IUpDown(IUpDown *);
////        pUpperLayer->OnLowerLayerUp();
    OnLowerLayerUp_in_IUpDown(&(pMockLowerLayer->hHasUpperLayer.pUpperLayer->iIUpDown));
  }
}

////void MockLowerLayer::ThisLayerDown()
void ThisLayerDown_in_MockLowerLayer(MockLowerLayer *pMockLowerLayer)
{
////    if (pUpperLayer)
  if(pMockLowerLayer->hHasUpperLayer.pUpperLayer)
  {
//boolean OnLowerLayerDown_in_IUpDown(IUpDown *);
////        pUpperLayer->OnLowerLayerDown();
    OnLowerLayerDown_in_IUpDown(&(pMockLowerLayer->hHasUpperLayer.pUpperLayer->iIUpDown));
  }
}
