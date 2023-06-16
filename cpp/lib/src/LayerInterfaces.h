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
#ifndef OPENDNP3_LAYERINTERFACES_H
#define OPENDNP3_LAYERINTERFACES_H

////#include "app/Message.h"
#include "Message.h"

////#include <cassert>

////namespace opendnp3
////{

/**
 * Describes a layer that can be opened or closed in response to the
 * availability of the layer below it.
 */
////class IUpDown
typedef struct
{

////public:
////    virtual ~IUpDown() {}

    // Called by a lower Layer when it is available to this layer
    // return false if the layer is already up
    boolean (*pOnLowerLayerUp_in_IUpDown)(void*);// = 0;

    // Called by a lower layer when it is no longer available to this layer
    // return false if the layer is already down
    boolean (*pOnLowerLayerDown_in_IUpDown)(void*);// = 0;
} IUpDown;

////class IUpperLayer : public IUpDown
typedef struct
{
    IUpDown iIUpDown;
////public:
////    virtual ~IUpperLayer() {}

    // Called by the lower layer when data arrives
    // return false if the layer is down
    boolean (*pOnReceive_in_IUpperLayer)(void*, Message* message);// = 0;

    // Called by the lower layer when it is ready to transmit more data
    boolean (*pOnTxReady_in_IUpperLayer)(void*);// = 0;
} IUpperLayer;

////class ILowerLayer
typedef struct
{

////public:
////    virtual ~ILowerLayer() {}

   boolean (*pBeginTransmit_in_ILowerLayer)(void*, Message* message);// = 0;
} ILowerLayer;

////class HasLowerLayer
typedef struct
{

////public:
////    HasLowerLayer() : pLowerLayer(nullptr) {}

    // Called by the lower layer when data arrives

////    void SetLowerLayer(ILowerLayer& lowerLayer)
////    {
////        assert(!pLowerLayer);
////        pLowerLayer = &lowerLayer;
////    }

////protected:
    ILowerLayer* pLowerLayer;
} HasLowerLayer;

  void HasLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer);
  void SetLowerLayer_in_HasLowerLayer(HasLowerLayer *pHasLowerLayer, ILowerLayer* lowerLayer);


////class HasUpperLayer
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

   void HasUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer);
    void SetUpperLayer_in_HasUpperLayer(HasUpperLayer *pHasUpperLayer, IUpperLayer* upperLayer);


///} // namespace opendnp3

#endif
