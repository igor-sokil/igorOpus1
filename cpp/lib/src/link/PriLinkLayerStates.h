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
#ifndef OPENDNP3_PRILINKLAYERSTATES_H
#define OPENDNP3_PRILINKLAYERSTATES_H

////#include "link/Singleton.h"

////namespace opendnp3
////{

////class LinkContext;
////class ITransportSegment;

#include "LinkContext.h"
#include "ITransportSegment.h"

////class PriStateBase
typedef struct
{
////public:
  // Incoming messages for primary station
  void* (*pOnAck_in_PriStateBase)(void*, LinkContext*, boolean receiveBuffFull);//=0
  void* (*pOnNack_in_PriStateBase)(void*, LinkContext*, boolean receiveBuffFull);//=0
  void* (*pOnLinkStatus_in_PriStateBase)(void*, LinkContext*, boolean receiveBuffFull);//=0
  void* (*pOnNotSupported_in_PriStateBase)(void*, LinkContext*, boolean receiveBuffFull);//=0

  void* (*pOnTxReady_in_PriStateBase)(void*, LinkContext*);//=0

  void* (*pOnTimeout_in_PriStateBase)(void*, LinkContext*);//=0

  // transmission events to handle
  void* (*pTrySendUnconfirmed_in_PriStateBase)(void*, LinkContext*, ITransportSegment* segments);//=0
  void* (*pTrySendRequestLinkStatus_in_PriStateBase)(void*, LinkContext*);//=0

  // every concrete state implements this for logging purposes
////    virtual char const* Name() const = 0;

  void* pParentPointer_in_PriStateBase;
} PriStateBase;

void PriStateBase_in_PriStateBase(PriStateBase *pPriStateBase);

void* OnAck_in_PriStateBase_override(void*, LinkContext*, boolean receiveBuffFull);
void* OnNack_in_PriStateBase_override(void*, LinkContext*, boolean receiveBuffFull);
void* OnLinkStatus_in_PriStateBase_override(void*, LinkContext*, boolean receiveBuffFull);
void* OnNotSupported_in_PriStateBase_override(void*, LinkContext*, boolean receiveBuffFull);

void* OnTxReady_in_PriStateBase_override(void*, LinkContext*);

void* OnTimeout_in_PriStateBase_override(void*, LinkContext*);

void* TrySendUnconfirmed_in_PriStateBase_override(void*, LinkContext*, ITransportSegment* segments);
void* TrySendRequestLinkStatus_in_PriStateBase_override(void*, LinkContext*);


PriStateBase* OnAck_in_PriStateBase(PriStateBase*, LinkContext*, boolean receiveBuffFull);
PriStateBase* OnNack_in_PriStateBase(PriStateBase*, LinkContext*, boolean receiveBuffFull);
PriStateBase* OnLinkStatus_in_PriStateBase(PriStateBase*, LinkContext*, boolean receiveBuffFull);
PriStateBase* OnNotSupported_in_PriStateBase(PriStateBase*, LinkContext*, boolean receiveBuffFull);

PriStateBase* OnTxReady_in_PriStateBase(PriStateBase*, LinkContext*);

PriStateBase* OnTimeout_in_PriStateBase(PriStateBase*, LinkContext*);

PriStateBase* TrySendUnconfirmed_in_PriStateBase(PriStateBase*, LinkContext*, ITransportSegment* segments);
PriStateBase* TrySendRequestLinkStatus_in_PriStateBase(PriStateBase*, LinkContext*);

void* getParentPointer_in_PriStateBase(PriStateBase*);
void  setParentPointer_in_PriStateBase(PriStateBase*, void*);

//	@section desc Entry state for primary station
////class PLLS_Idle final : public PriStateBase
//typedef struct
//{
////    MACRO_STATE_SINGLETON_INSTANCE(PLLS_Idle);
//  PriStateBase pPriStateBase;

////    PriStateBase& TrySendUnconfirmed(LinkContext&, ITransportSegment& segments) override;
////    PriStateBase& TrySendRequestLinkStatus(LinkContext&) override;
//} PLLS_Idle;

PriStateBase* Instance_in_PLLS_Idle_static(void);
void PLLS_Idle_in_PLLS_Idle(PriStateBase *pPriStateBase);

void* TrySendUnconfirmed_in_PLLS_Idle_override(void*, LinkContext*, ITransportSegment* segments);
void* TrySendRequestLinkStatus_in_PLLS_Idle_override(void*, LinkContext*);
PriStateBase* TrySendUnconfirmed_in_PLLS_Idle(PriStateBase*, LinkContext*, ITransportSegment* segments);
PriStateBase* TrySendRequestLinkStatus_in_PLLS_Idle(PriStateBase*, LinkContext*);

/////////////////////////////////////////////////////////////////////////////
// Wait state for send unconfirmed data
/////////////////////////////////////////////////////////////////////////////

////class PLLS_SendUnconfirmedTransmitWait final : public PriStateBase
//typedef struct
//{
//  PriStateBase pPriStateBase;
////    MACRO_STATE_SINGLETON_INSTANCE(PLLS_SendUnconfirmedTransmitWait);

////    virtual PriStateBase& OnTxReady(LinkContext& ctx) override;
//} PLLS_SendUnconfirmedTransmitWait;

void PLLS_SendUnconfirmedTransmitWait_in_PLLS_SendUnconfirmedTransmitWait(PriStateBase *pPriStateBase);

void* OnTxReady_in_PLLS_SendUnconfirmedTransmitWait_override(void *, LinkContext* ctx);
PriStateBase* OnTxReady_in_PLLS_SendUnconfirmedTransmitWait(PriStateBase *pPriStateBase,
    LinkContext* ctx);

/////////////////////////////////////////////////////////////////////////////
// Waiting for a link status response
/////////////////////////////////////////////////////////////////////////////

//	@section desc As soon as we get an ACK, send the delayed pri frame
////class PLLS_RequestLinkStatusWait final : public PriStateBase
//typedef struct
//{
//  PriStateBase pPriStateBase;
////    MACRO_STATE_SINGLETON_INSTANCE(PLLS_RequestLinkStatusWait);

////    PriStateBase& OnAck(LinkContext& ctx, bool) override;
////    PriStateBase& OnNack(LinkContext& ctx, bool) override;
////    PriStateBase& OnLinkStatus(LinkContext& ctx, bool) override;
////    PriStateBase& OnNotSupported(LinkContext& ctx, bool) override;
////    PriStateBase& OnTxReady(LinkContext&) override;
////    PriStateBase& OnTimeout(LinkContext&) override;
//} PLLS_RequestLinkStatusWait;

void PLLS_RequestLinkStatusWait_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase);

void* OnAck_in_PLLS_RequestLinkStatusWait_override(void *, LinkContext* ctx, boolean);
void* OnNack_in_PLLS_RequestLinkStatusWait_override(void *, LinkContext* ctx, boolean);
void* OnLinkStatus_in_PLLS_RequestLinkStatusWait_override(void *, LinkContext* ctx, boolean);
void* OnNotSupported_in_PLLS_RequestLinkStatusWait_override(void *, LinkContext* ctx, boolean);
void* OnTxReady_in_PLLS_RequestLinkStatusWait_override(void *, LinkContext*);
void* OnTimeout_in_PLLS_RequestLinkStatusWait_override(void *, LinkContext*);

PriStateBase* OnAck_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean);
PriStateBase* OnNack_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean);
PriStateBase* OnLinkStatus_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean);
PriStateBase* OnNotSupported_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean);
PriStateBase* OnTxReady_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext*);
PriStateBase* OnTimeout_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext*);

////} // namespace opendnp3

#endif
