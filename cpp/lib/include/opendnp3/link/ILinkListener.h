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

#ifndef OPENDNP3_ILINK_LISTENER_H
#define OPENDNP3_ILINK_LISTENER_H

////#include "opendnp3/gen/LinkStatus.h"
#include "LinkStatus.h"

////namespace opendnp3
////{

/**
 * Various optional callbacks that can be received for the link layer
 */
////class ILinkListener
typedef struct
{
////public:
    /// Called when a the reset/unreset status of the link layer changes
    void (*pOnStateChange_in_ILinkListener)(void*, LinkStatus_uint8_t value);
////    virtual void OnStateChange(LinkStatus value) {}

    /// Called when a link-layer frame is received from an unknown destination address
    void (*pOnUnknownDestinationAddress_in_ILinkListener)(void*, uint16_t destination);
////    virtual void OnUnknownDestinationAddress(uint16_t destination) {}

    /// Called when a link-layer frame is received from an unknown source address
    void (*pOnUnknownSourceAddress_in_ILinkListener)(void*, uint16_t source);
////    virtual void OnUnknownSourceAddress(uint16_t source) {}

    /// Called when the keep alive timer elapses. This doesn't denote a keep-alive failure, it's just a notification
    void (*pOnKeepAliveInitiated_in_ILinkListener)(void*);
////    virtual void OnKeepAliveInitiated() {}

    /// Called when a keep alive message (request link status) receives no response
    void (*pOnKeepAliveFailure_in_ILinkListener)(void*);
////    virtual void OnKeepAliveFailure() {}

    /// Called when a keep alive message receives a valid response
    void (*pOnKeepAliveSuccess_in_ILinkListener)(void*);
////    virtual void OnKeepAliveSuccess() {}

  void* pParentPointer_in_ILinkListener;
} ILinkListener;

void ILinkListener_in_ILinkListener(ILinkListener *pILinkListener);

    void OnStateChange_in_ILinkListener(ILinkListener*, LinkStatus_uint8_t value);
    void OnUnknownDestinationAddress_in_ILinkListener(ILinkListener*, uint16_t destination);
    void OnUnknownSourceAddress_in_ILinkListener(ILinkListener*, uint16_t source);
    void OnKeepAliveInitiated_in_ILinkListener(ILinkListener*);
    void OnKeepAliveFailure_in_ILinkListener(ILinkListener*);
    void OnKeepAliveSuccess_in_ILinkListener(ILinkListener*);

    void OnStateChange_in_ILinkListener_default(void*, LinkStatus_uint8_t value);
    void OnUnknownDestinationAddress_in_ILinkListener_default(void*, uint16_t destination);
    void OnUnknownSourceAddress_in_ILinkListener_default(void*, uint16_t source);
    void OnKeepAliveInitiated_in_ILinkListener_default(void*);
    void OnKeepAliveFailure_in_ILinkListener_default(void*);
    void OnKeepAliveSuccess_in_ILinkListener_default(void*);

void* getParentPointer_in_ILinkListener(ILinkListener*);
void  setParentPointer_in_ILinkListener(ILinkListener*, void*);

////} // namespace opendnp3

#endif
