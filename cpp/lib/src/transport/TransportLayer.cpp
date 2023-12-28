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
#include "TransportLayer.h"

#include "TransportConstants.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <cassert>

////namespace opendnp3
////{

void TransportLayer_in_TransportLayer(TransportLayer *pTransportLayer, uint32_t maxRxFragSize)
{
////    : logger(logger), receiver(logger, maxRxFragSize), transmitter(logger)
  pTransportLayer->upper = NULL;
  pTransportLayer->lower = NULL;

  // ---- state ----
  pTransportLayer->isOnline = false;
  pTransportLayer->isSending = false;

  TransportTx_in_TransportTx(&(pTransportLayer->transmitter));
  TransportRx_in_TransportRx(&(pTransportLayer->receiver), maxRxFragSize);

  // ------ ILowerLayer ------

  pTransportLayer->iILowerLayer.pBeginTransmit_in_ILowerLayer = BeginTransmit_in_TransportLayer_override;

  // ------ IUpperLayer ------

  pTransportLayer->iIUpperLayer.pOnReceive_in_IUpperLayer = OnReceive_in_TransportLayer_override;

  pTransportLayer->iIUpperLayer.iIUpDown.pOnLowerLayerUp_in_IUpDown = OnLowerLayerUp_in_TransportLayer_override;

  pTransportLayer->iIUpperLayer.iIUpDown.pOnLowerLayerDown_in_IUpDown = OnLowerLayerDown_in_TransportLayer_override;

  pTransportLayer->iIUpperLayer.pOnTxReady_in_IUpperLayer = OnTxReady_in_TransportLayer_override;

  setParentPointer_in_ILowerLayer(&(pTransportLayer->iILowerLayer), pTransportLayer);
  setParentPointer_in_IUpperLayer(&(pTransportLayer->iIUpperLayer), pTransportLayer);
}

///////////////////////////////////////
// Actions
///////////////////////////////////////

////bool TransportLayer::BeginTransmit(const Message& message)
boolean BeginTransmit_in_TransportLayer(TransportLayer *pTransportLayer, Message* message)
{
  if (!pTransportLayer->isOnline)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer offline");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer offline')"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

////    if (message.payload.is_empty())
  if(is_empty_in_HasLength_for_Uint16_t(&(message->payload.hHasLength)))
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "APDU cannot be empty");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'APDU cannot be empty')"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (pTransportLayer->isSending)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Invalid BeginTransmit call, already transmitting");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Invalid BeginTransmit call, already transmitting')"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (!pTransportLayer->lower)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Can't send without an attached link layer");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Can't send without an attached link layer')"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pTransportLayer->isSending = true;

//void Configure_in_TransportTx(TransportTx *pTransportTx, Message* message);
////    transmitter.Configure(message);
  Configure_in_TransportTx(&(pTransportLayer->transmitter), message);

//boolean Send_in_ILinkLayer(ILinkLayer* pILinkLayer, ITransportSegment* segment);
////    lower->Send(transmitter);
  Send_in_ILinkLayer(pTransportLayer->lower, &(pTransportLayer->transmitter.iITransportSegment));

  return true;
}
boolean BeginTransmit_in_TransportLayer_override(void *pILowerLayer, Message* message)
{
  TransportLayer *parent = (TransportLayer*) getParentPointer_in_ILowerLayer((ILowerLayer*)pILowerLayer);
  return BeginTransmit_in_TransportLayer(parent, message);
}

///////////////////////////////////////
// IUpperLayer
///////////////////////////////////////

////bool TransportLayer::OnReceive(const Message& message)
boolean OnReceive_in_TransportLayer(TransportLayer *pTransportLayer, Message* message)
{
  if (pTransportLayer->isOnline)
  {
//Message ProcessReceive_in_TransportRx(TransportRx *pTransportRx, Message* segment);
////        const auto asdu = receiver.ProcessReceive(message);
    Message asdu = ProcessReceive_in_TransportRx(&(pTransportLayer->receiver), message);

////        if (upper && asdu.payload.is_not_empty())
    if(pTransportLayer->upper && is_not_empty_in_HasLength_for_Uint16_t(&(asdu.payload.hHasLength)))
    {
//boolean OnReceive_in_IUpperLayer(IUpperLayer *, Message* message);
////            upper->OnReceive(asdu);
      OnReceive_in_IUpperLayer(pTransportLayer->upper, &asdu);
    }
    return true;
  }

////    SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer offline");
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer offline')"<<'\n';
  decrement_stack_info();
#endif
  return false;
}
boolean OnReceive_in_TransportLayer_override(void *pIUpperLayer, Message* message)
{
  TransportLayer *parent = (TransportLayer*) getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);
  return OnReceive_in_TransportLayer(parent, message);
}

////bool TransportLayer::OnTxReady()
boolean OnTxReady_in_TransportLayer(TransportLayer *pTransportLayer)
{
  if (!pTransportLayer->isOnline)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer offline");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer offline')"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (!pTransportLayer->isSending)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Invalid send callback");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Invalid send callback')"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pTransportLayer->isSending = false;

  if (pTransportLayer->upper)
  {
//boolean OnTxReady_in_IUpperLayer(IUpperLayer *);
////        upper->OnTxReady();
    OnTxReady_in_IUpperLayer(pTransportLayer->upper);
  }

  return true;
}
boolean OnTxReady_in_TransportLayer_override(void *pIUpperLayer)
{
  TransportLayer *parent = (TransportLayer*) getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);
  return OnTxReady_in_TransportLayer(parent);
}

////void TransportLayer::SetAppLayer(IUpperLayer& upperLayer)
void SetAppLayer_in_TransportLayer(TransportLayer *pTransportLayer, IUpperLayer* upperLayer)
{
////    assert(!upper);
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  if(!pTransportLayer->upper) std::cout<<"*assert(!upper)"<<'\n';
  decrement_stack_info();
#endif

  pTransportLayer->upper = upperLayer;
}

////void TransportLayer::SetLinkLayer(ILinkLayer& linkLayer)
void SetLinkLayer_in_TransportLayer(TransportLayer *pTransportLayer, ILinkLayer* linkLayer)
{
////    assert(!lower);
#ifdef  LOG_INFO
  std::cout<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  if(!pTransportLayer->lower) std::cout<<"*assert(!lower)"<<'\n';
  decrement_stack_info();
#endif

  pTransportLayer->lower = linkLayer;
}

////StackStatistics::Transport TransportLayer::GetStatistics() const
Transport_StackStatistics GetStatistics_in_TransportLayer(TransportLayer *pTransportLayer)
{
//Rx_Transport* Statistics_in_TransportRx(TransportRx *pTransportRx);
//void Transport_StackStatistics_in_Transport_StackStatisticsOver2(Transport_StackStatistics *pTransport_StackStatistics,
//    Rx_Transport* rx, Tx_Transport* tx);
////    return StackStatistics::Transport(this->receiver.Statistics(), this->transmitter.Statistics());
  Transport_StackStatistics tTransport_StackStatistics;
  Transport_StackStatistics_in_Transport_StackStatisticsOver2(&tTransport_StackStatistics,
      Statistics_in_TransportRx(&(pTransportLayer->receiver)), Statistics_in_TransportTx(&(pTransportLayer->transmitter)));
  return tTransport_StackStatistics;
}

////bool TransportLayer::OnLowerLayerUp()
boolean OnLowerLayerUp_in_TransportLayer(TransportLayer *pTransportLayer)
{
  if (pTransportLayer->isOnline)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer already online");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already online')"<<'\n';
    decrement_stack_info();
#endif

    return false;
  }

  pTransportLayer->isOnline = true;
  if (pTransportLayer->upper)
  {
//boolean OnLowerLayerUp_in_IUpDown(IUpDown *);
////        upper->OnLowerLayerUp();
    OnLowerLayerUp_in_IUpDown(&(pTransportLayer->upper->iIUpDown));
  }
  return true;
}

boolean OnLowerLayerUp_in_TransportLayer_override(void *pIUpDown)
{
  TransportLayer *parent = (TransportLayer*) getParentPointer_in_IUpDown((IUpDown*)pIUpDown);
  return OnLowerLayerUp_in_TransportLayer(parent);
}

////bool TransportLayer::OnLowerLayerDown()
boolean OnLowerLayerDown_in_TransportLayer(TransportLayer *pTransportLayer)
{
  if (!pTransportLayer->isOnline)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer already offline");
#ifdef  LOG_INFO
    std::cout<<std::endl;
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already offline')"<<'\n';
    decrement_stack_info();
#endif

    return false;
  }

  pTransportLayer->isOnline = false;
  pTransportLayer->isSending = false;
////    receiver.Reset();
  Reset_in_TransportRx(&(pTransportLayer->receiver));

  if (pTransportLayer->upper)
  {
////        upper->OnLowerLayerDown();
    OnLowerLayerDown_in_IUpDown(&(pTransportLayer->upper->iIUpDown));
  }

  return true;
}

boolean OnLowerLayerDown_in_TransportLayer_override(void *pIUpDown)
{
  TransportLayer *parent = (TransportLayer*) getParentPointer_in_IUpDown((IUpDown*)pIUpDown);
  return OnLowerLayerDown_in_TransportLayer(parent);
}

////} // namespace opendnp3
