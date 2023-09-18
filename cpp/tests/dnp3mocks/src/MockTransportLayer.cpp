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
#include <QApplication>
#include <QtWidgets>
#include "header.h"
#include "MockTransportLayer.h"
#include "HexConversions.h"

////#include <ser4cpp/util/HexConversions.h>

////using namespace opendnp3;
////using namespace ser4cpp;

////MockTransportLayer::MockTransportLayer() : pLinkLayer(nullptr), isOnline(false) {}
void MockTransportLayer_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer)
{
  pMockTransportLayer->pLinkLayer = NULL;
  pMockTransportLayer->isOnline = false;

  pMockTransportLayer->iIUpperLayer.pOnReceive_in_IUpperLayer = OnReceive_in_MockTransportLayer_override;
  pMockTransportLayer->iIUpperLayer.pOnTxReady_in_IUpperLayer = OnTxReady_in_MockTransportLayer_override;

  pMockTransportLayer->iIUpperLayer.iIUpDown.pOnLowerLayerUp_in_IUpDown = OnLowerLayerUp_in_MockTransportLayer_override;
  pMockTransportLayer->iIUpperLayer.iIUpDown.pOnLowerLayerDown_in_IUpDown = OnLowerLayerDown_in_MockTransportLayer_override;

  setParentPointer_in_IUpperLayer(&(pMockTransportLayer->iIUpperLayer), pMockTransportLayer);
  setParentPointer_in_IUpDown(&(pMockTransportLayer->iIUpperLayer.iIUpDown), pMockTransportLayer);
}

void SetLinkLayer_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer, ILinkLayer* linkLayer)
{
  pMockTransportLayer->pLinkLayer = linkLayer;
}

////bool MockTransportLayer::SendDown(ITransportSegment& segments)
boolean SendDown_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer, ITransportSegment* segments)
{
//boolean Send_in_ILinkLayer(ILinkLayer* pILinkLayer, ITransportSegment* segment);
////    return pLinkLayer->Send(segments);
  return  Send_in_ILinkLayer(pMockTransportLayer->pLinkLayer, segments);
}

boolean OnReceive_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer, Message* message)
{
qDebug()<<"";
qDebug()<<"OnReceive_in_MockTransportLayer1";
  pMockTransportLayer->receivedQueue.push_back(to_hex_in_HexConversionsOver2(&(message->payload)));
  return true;
}

boolean OnTxReady_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer)
{
  ++(pMockTransportLayer->counters.numTxReady);
  return true;
}

boolean OnLowerLayerUp_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer)
{
////    assert(!isOnline);
  pMockTransportLayer->isOnline = true;
  ++(pMockTransportLayer->counters.numLayerUp);
  return true;
}

boolean OnLowerLayerDown_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer)
{
////    assert(isOnline);
  pMockTransportLayer->isOnline = false;
  ++(pMockTransportLayer->counters.numLayerDown);
  return true;
}

boolean IsOnline_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer)
{
  return pMockTransportLayer->isOnline;
}

boolean CountersEquals_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer, Counters_in_MockTransportLayer* other)
{
  return (pMockTransportLayer->counters.numTxReady == other->numTxReady) && (pMockTransportLayer->counters.numLayerUp == other->numLayerUp)
         && (pMockTransportLayer->counters.numLayerDown == other->numLayerDown);
}

Counters_in_MockTransportLayer GetCounters_in_MockTransportLayer(MockTransportLayer *pMockTransportLayer)
{
  return pMockTransportLayer->counters;
}

boolean OnLowerLayerDown_in_MockTransportLayer_override(void *pIUpDown)
{
  MockTransportLayer *parent = (MockTransportLayer*)getParentPointer_in_IUpDown((IUpDown*) pIUpDown);
  return OnLowerLayerDown_in_MockTransportLayer(parent);
}

boolean OnLowerLayerUp_in_MockTransportLayer_override(void *pIUpDown)
{
  MockTransportLayer *parent = (MockTransportLayer*)getParentPointer_in_IUpDown((IUpDown*) pIUpDown);
  return OnLowerLayerUp_in_MockTransportLayer(parent);
}

boolean OnTxReady_in_MockTransportLayer_override(void *pIUpperLayer)
{
  MockTransportLayer *parent = (MockTransportLayer*)getParentPointer_in_IUpperLayer((IUpperLayer*) pIUpperLayer);
  return OnTxReady_in_MockTransportLayer(parent);
}

boolean OnReceive_in_MockTransportLayer_override(void *pIUpperLayer, Message* message)
{
  MockTransportLayer *parent = (MockTransportLayer*)getParentPointer_in_IUpperLayer((IUpperLayer*) pIUpperLayer);
  return OnReceive_in_MockTransportLayer(parent, message);
}
