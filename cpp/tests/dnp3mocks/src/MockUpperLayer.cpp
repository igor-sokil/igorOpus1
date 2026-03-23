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
#include "MockUpperLayer.h"
#include "HexConversions.h"

////#include <ser4cpp/util/HexConversions.h>

////#include <memory>

////using namespace opendnp3;
////using namespace ser4cpp;

void Counters_in_MockUpperLayer_in_Counters_in_MockUpperLayer(Counters_in_MockUpperLayer *pCounters_in_MockUpperLayer)
{
  pCounters_in_MockUpperLayer->numTxReady = 0;
  pCounters_in_MockUpperLayer->numLayerUp = 0;
  pCounters_in_MockUpperLayer->numLayerDown = 0;
}

////MockUpperLayer::MockUpperLayer() : isOnline(false) {}
void MockUpperLayer_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer)
{
  pMockUpperLayer->isOnline_in_MockUpperLayer = false;
  Counters_in_MockUpperLayer_in_Counters_in_MockUpperLayer(&(pMockUpperLayer->counters));
  pMockUpperLayer->rRSeqReceived = empty_in_RSeq_for_Uint16_t_static();//сохр результат

  pMockUpperLayer->iIUpperLayer.pOnReceive_in_IUpperLayer = OnReceive_in_MockUpperLayer_override;
  pMockUpperLayer->iIUpperLayer.pOnTxReady_in_IUpperLayer = OnTxReady_in_MockUpperLayer_override;

  pMockUpperLayer->iIUpperLayer.iIUpDown.pOnLowerLayerUp_in_IUpDown = OnLowerLayerUp_in_MockUpperLayer_override;
  pMockUpperLayer->iIUpperLayer.iIUpDown.pOnLowerLayerDown_in_IUpDown = OnLowerLayerDown_in_MockUpperLayer_override;

  setParentPointer_in_IUpperLayer(&(pMockUpperLayer->iIUpperLayer), pMockUpperLayer);
  setParentPointer_in_IUpDown(&(pMockUpperLayer->iIUpperLayer.iIUpDown), pMockUpperLayer);
}

////bool MockUpperLayer::OnReceive(const Message& message)
boolean OnReceive_in_MockUpperLayer(MockUpperLayer *pMockTransportLayer, Message* message)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnReceive_in_MockUpperLayer1"<<'\n';
  std::cout<<"FinalDestination_in_MockUpperLayer:"<<'\n';
#endif
//void Write_in_DataSink(DataSink *pDataSink, RSeq_for_Uint16_t* data);
////    this->received.Write(message.payload);
  Write_in_DataSink(&(pMockTransportLayer->received), &(message->payload));
  pMockTransportLayer->rRSeqReceived = message->payload;//сохр результат

#ifdef  LOG_INFO
  std::cout<<"}OnReceive_in_MockUpperLayer_"<<'\n';
#endif
  return true;
}
boolean OnReceive_in_MockUpperLayer_override(void *pIUpperLayer, Message* message)
{
  MockUpperLayer *parent = (MockUpperLayer*) getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);
  return OnReceive_in_MockUpperLayer(parent, message);
}

////bool MockUpperLayer::OnTxReady()
boolean OnTxReady_in_MockUpperLayer(MockUpperLayer *pMockTransportLayer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnTxReady_in_MockUpperLayer1"<<'\n';
#endif
  ++(pMockTransportLayer->counters.numTxReady);

#ifdef  LOG_INFO
  std::cout<<"}OnTxReady_in_MockUpperLayer_"<<'\n';
#endif
  return true;
}
boolean OnTxReady_in_MockUpperLayer_override(void *pIUpperLayer)
{
  MockUpperLayer *parent = (MockUpperLayer*) getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);
  return OnTxReady_in_MockUpperLayer(parent);
}

////bool MockUpperLayer::OnLowerLayerUp()
boolean OnLowerLayerUp_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnLowerLayerUp_in_MockUpperLayer1"<<'\n';
#endif
  pMockUpperLayer->isOnline_in_MockUpperLayer = true;
  ++(pMockUpperLayer->counters.numLayerUp);

#ifdef  LOG_INFO
  std::cout<<"}OnLowerLayerUp_in_MockUpperLayer_"<<'\n';
#endif
  return true;
}
boolean OnLowerLayerUp_in_MockUpperLayer_override(void *pIUpDown)
{
  MockUpperLayer *parent = (MockUpperLayer*) getParentPointer_in_IUpDown((IUpDown*)pIUpDown);
  return OnLowerLayerUp_in_MockUpperLayer(parent);
}

////bool MockUpperLayer::OnLowerLayerDown()
boolean OnLowerLayerDown_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{OnLowerLayerDown_in_MockUpperLayer1"<<'\n';
#endif
  pMockUpperLayer->isOnline_in_MockUpperLayer = false;
  ++(pMockUpperLayer->counters.numLayerDown);

#ifdef  LOG_INFO
  std::cout<<"}OnLowerLayerDown_in_MockUpperLayer_"<<'\n';
#endif
  return true;
}
boolean OnLowerLayerDown_in_MockUpperLayer_override(void *pIUpDown)
{
  MockUpperLayer *parent = (MockUpperLayer*) getParentPointer_in_IUpDown((IUpDown*)pIUpDown);
  return OnLowerLayerDown_in_MockUpperLayer(parent);
}

////bool MockUpperLayer::SendDown(const rseq_t& data, const Addresses& addresses)
boolean SendDown_in_MockUpperLayerOver2(MockUpperLayer *pMockUpperLayer, RSeq_for_Uint16_t* data, Addresses* addresses)/// = opendnp3::Addresses());
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{SendDown_in_MockUpperLayerOver2_1"<<'\n';
#endif
//boolean BeginTransmit_in_ILowerLayer(ILowerLayer *, Message* message);
////    return this->pLowerLayer ? pLowerLayer->BeginTransmit(Message(addresses, data)) : false;
  Message mMessage;
  Message_in_Message(&mMessage, addresses, data);
  boolean tmp = pMockUpperLayer->hHasLowerLayer.pLowerLayer ?
                BeginTransmit_in_ILowerLayer(pMockUpperLayer->hHasLowerLayer.pLowerLayer, &mMessage) : false;

#ifdef  LOG_INFO
  std::cout<<"}SendDown_in_MockUpperLayerOver2__"<<'\n';
#endif
  return tmp;
}

////bool MockUpperLayer::SendDown(const std::string& hex, const Addresses& addresses)
boolean SendDown_in_MockUpperLayerOver1(MockUpperLayer *pMockUpperLayer, std::string& hex, Addresses* addresses)//// = opendnp3::Addresses());
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  std::cout<<"{SendDown_in_MockUpperLayerOver1_1"<<'\n';
#endif
//BufferSer4* from_hex_in_HexConversions(std::string& hex)
////    const auto buffer = HexConversions::from_hex(hex);
  BufferSer4* tmp = from_hex_in_HexConversions(hex);

//RSeq_for_Uint16_t as_rslice_in_BufferSer4(BufferSer4 *pBufferSer4);
////    return this->SendDown(buffer->as_rslice(), addresses);
  RSeq_for_Uint16_t rtmp = as_rslice_in_BufferSer4(tmp);
  boolean btmp = SendDown_in_MockUpperLayerOver2(pMockUpperLayer, &rtmp, addresses);/// = opendnp3::Addresses());
#ifdef  LOG_INFO
  std::cout<<"}SendDown_in_MockUpperLayerOver1__"<<'\n';
#endif
  return btmp;
}

Counters_in_MockUpperLayer GetCounters_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer)
{
  return pMockUpperLayer->counters;
}
boolean IsOnline_in_MockUpperLayer(MockUpperLayer *pMockUpperLayer)
{
  return pMockUpperLayer->isOnline_in_MockUpperLayer;
}
