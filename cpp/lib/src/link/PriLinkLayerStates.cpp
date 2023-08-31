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
//#include <QtWidgets>
#include <iostream>
#include "header.h"
#include "PriLinkLayerStates.h"

#include "LinkLayer.h"
////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////////////////////////////////////////
// PriStateBase
////////////////////////////////////////
static PriStateBase instance_PriStateBase;

void PriStateBase_in_PriStateBase(PriStateBase *pPriStateBase)
{
  pPriStateBase->pOnAck_in_PriStateBase = OnAck_in_PriStateBase_override;
  pPriStateBase->pOnNack_in_PriStateBase = OnNack_in_PriStateBase_override;
  pPriStateBase->pOnLinkStatus_in_PriStateBase = OnLinkStatus_in_PriStateBase_override;
  pPriStateBase->pOnNotSupported_in_PriStateBase = OnNotSupported_in_PriStateBase_override;

  pPriStateBase->pOnTxReady_in_PriStateBase = OnTxReady_in_PriStateBase_override;

  pPriStateBase->pOnTimeout_in_PriStateBase = OnTimeout_in_PriStateBase_override;

  // transmission events to handle
  pPriStateBase->pTrySendUnconfirmed_in_PriStateBase = TrySendUnconfirmed_in_PriStateBase_override;
  pPriStateBase->pTrySendRequestLinkStatus_in_PriStateBase = TrySendRequestLinkStatus_in_PriStateBase_override;

  setParentPointer_in_PriStateBase(pPriStateBase, pPriStateBase);
}

PriStateBase* OnAck_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext, boolean receiveBuffFull)
{
  return (PriStateBase*)(pPriStateBase->pOnAck_in_PriStateBase)(pPriStateBase, pLinkContext, receiveBuffFull);
}
PriStateBase* OnNack_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext, boolean receiveBuffFull)
{
  return (PriStateBase*)(pPriStateBase->pOnNack_in_PriStateBase)(pPriStateBase, pLinkContext, receiveBuffFull);
}
PriStateBase* OnLinkStatus_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext, boolean receiveBuffFull)
{
  return (PriStateBase*)(pPriStateBase->pOnLinkStatus_in_PriStateBase)(pPriStateBase, pLinkContext, receiveBuffFull);
}
PriStateBase* OnNotSupported_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext, boolean receiveBuffFull)
{
  return (PriStateBase*)(pPriStateBase->pOnNotSupported_in_PriStateBase)(pPriStateBase, pLinkContext, receiveBuffFull);
}

PriStateBase* OnTxReady_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext)
{
  return (PriStateBase*)(pPriStateBase->pOnTxReady_in_PriStateBase)(pPriStateBase, pLinkContext);
}

PriStateBase* OnTimeout_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext)
{
  return (PriStateBase*)(pPriStateBase->pOnTimeout_in_PriStateBase)(pPriStateBase, pLinkContext);
}

PriStateBase* TrySendUnconfirmed_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext, ITransportSegment* segments)
{
  return (PriStateBase*)(pPriStateBase->pTrySendUnconfirmed_in_PriStateBase)(pPriStateBase, pLinkContext, segments);
}
PriStateBase* TrySendRequestLinkStatus_in_PriStateBase(PriStateBase* pPriStateBase, LinkContext* pLinkContext)
{
  return (PriStateBase*)(pPriStateBase->pTrySendRequestLinkStatus_in_PriStateBase)(pPriStateBase, pLinkContext);
}

void* getParentPointer_in_PriStateBase(PriStateBase* pPriStateBase)
{
  return pPriStateBase->pParentPointer_in_PriStateBase;
}
void  setParentPointer_in_PriStateBase(PriStateBase* pPriStateBase, void* pParentPointer)
{
  pPriStateBase->pParentPointer_in_PriStateBase = pParentPointer;
}

void* OnAck_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx, boolean v/*rxBuffFull*/)
{
  UNUSED(v);
  ++(ctx->statistics.numUnexpectedFrame);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Frame context not understood");
    std::cout<<"***SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Frame context not understood')***"<<std::endl;
  return pPriStateBase;
}

void* OnNack_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx, boolean v/*rxBuffFull*/)
{
  UNUSED(v);
  ++(ctx->statistics.numUnexpectedFrame);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Frame context not understood");
    std::cout<<"***SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Frame context not understood')***"<<std::endl;
  return pPriStateBase;
}

void* OnLinkStatus_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx, boolean v/*rxBuffFull*/)
{
  UNUSED(v);
  ++(ctx->statistics.numUnexpectedFrame);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Frame context not understood");
    std::cout<<"***SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Frame context not understood')***"<<std::endl;
  return pPriStateBase;
}

void* OnNotSupported_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx, boolean v/*rxBuffFull*/)
{
  UNUSED(v);
  ++(ctx->statistics.numUnexpectedFrame);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Frame context not understood");
  return pPriStateBase;
}

void* OnTxReady_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx)
{
  UNUSED(ctx);
////    FORMAT_LOG_BLOCK(ctx.logger, flags::ERR, "Invalid action for state: %s", this->Name());
  std::cout<<"***FORMAT_LOG_BLOCK(ctx.logger, flags::ERR, 'Invalid action for state: %s'***"<<std::endl;
  return pPriStateBase;
}

void* OnTimeout_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx)
{
  UNUSED(ctx);
////    FORMAT_LOG_BLOCK(ctx.logger, flags::ERR, "Invalid action for state: %s", this->Name());
  std::cout<<"***FORMAT_LOG_BLOCK(ctx.logger, flags::ERR, 'Invalid action for state: %s'***"<<std::endl;
  return pPriStateBase;
}

void* TrySendUnconfirmed_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx, ITransportSegment* v/*unused*/)
{
  UNUSED(ctx);
  UNUSED(v);
  return pPriStateBase;
}

void* TrySendRequestLinkStatus_in_PriStateBase_override(void* pPriStateBase, LinkContext* ctx)
{
  UNUSED(ctx);
  return pPriStateBase;
}

////////////////////////////////////////////////////////
// Class PLLS_SecNotResetIdle
////////////////////////////////////////////////////////
//PLLS_Idle instance_in_PLLS_Idle;
//PLLS_SendUnconfirmedTransmitWait instance_in_PLLS_SendUnconfirmedTransmitWait;
//PLLS_RequestLinkStatusWait instance_in_PLLS_RequestLinkStatusWait;

PriStateBase* Instance_in_PLLS_Idle_static(void)
{
  PLLS_Idle_in_PLLS_Idle(&instance_PriStateBase);
  return  &instance_PriStateBase;
}

void PLLS_Idle_in_PLLS_Idle(PriStateBase *pPriStateBase)
{
  PriStateBase_in_PriStateBase(pPriStateBase);

  pPriStateBase->pTrySendUnconfirmed_in_PriStateBase = TrySendUnconfirmed_in_PLLS_Idle_override;
  pPriStateBase->pTrySendRequestLinkStatus_in_PriStateBase = TrySendRequestLinkStatus_in_PLLS_Idle_override;

  setParentPointer_in_PriStateBase(pPriStateBase, pPriStateBase);
}

void* TrySendRequestLinkStatus_in_PLLS_Idle_override(void *pPriStateBase, LinkContext* ctx)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return TrySendRequestLinkStatus_in_PLLS_Idle(parent, ctx);
}
void* TrySendUnconfirmed_in_PLLS_Idle_override(void *pPriStateBase, LinkContext* ctx, ITransportSegment* segments)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return TrySendUnconfirmed_in_PLLS_Idle(parent, ctx, segments);
}

PriStateBase* TrySendUnconfirmed_in_PLLS_Idle(PriStateBase *pPriStateBase, LinkContext* ctx, ITransportSegment* segments)
{
  UNUSED(pPriStateBase);
//RSeq_for_Uint16_t GetSegment_in_ITransportSegment(ITransportSegment*);
////    auto first = segments.GetSegment();
  RSeq_for_Uint16_t first = GetSegment_in_ITransportSegment(segments);

//Addresses* GetAddresses_in_ITransportSegment(ITransportSegment*);
//    ser4cpp::rseq_t FormatPrimaryBufferWithUnconfirmed(const Addresses& addr, const ser4cpp::rseq_t& tpdu);
////    auto output = ctx.FormatPrimaryBufferWithUnconfirmed(segments.GetAddresses(), first);
  Addresses* temp = GetAddresses_in_ITransportSegment(segments);

  RSeq_for_Uint16_t output = FormatPrimaryBufferWithUnconfirmed_in_LinkContext(ctx,
                             temp, &first);

//    void QueueTransmit(const ser4cpp::rseq_t& buffer, bool primary);
////    ctx.QueueTransmit(output, true);
  QueueTransmit_in_LinkContext(ctx, &output, true);
////    return PLLS_SendUnconfirmedTransmitWait::Instance();
  PLLS_SendUnconfirmedTransmitWait_in_PLLS_SendUnconfirmedTransmitWait(&instance_PriStateBase);//&(instance_in_PLLS_SendUnconfirmedTransmitWait.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_SendUnconfirmedTransmitWait.pPriStateBase);
}

PriStateBase* TrySendRequestLinkStatus_in_PLLS_Idle(PriStateBase *pPriStateBase, LinkContext* ctx)
{
  UNUSED(pPriStateBase);
  ctx->keepAliveTimeout = false;
//    void QueueRequestLinkStatus(uint16_t destination);
////    ctx.QueueRequestLinkStatus(ctx.config.RemoteAddr);
  QueueRequestLinkStatus_in_LinkContext(ctx, ctx->config.lLinkConfig.RemoteAddr);
//    void OnKeepAliveInitiated_in_ILinkListener(ILinkListener*);
////    ctx.listener.OnKeepAliveInitiated();
  OnKeepAliveInitiated_in_ILinkListener(ctx->listener);
//    void StartResponseTimer();
////    ctx.StartResponseTimer();
  StartResponseTimer_in_LinkContext(ctx);
////    return PLLS_RequestLinkStatusWait::Instance();
  PLLS_RequestLinkStatusWait_in_PLLS_RequestLinkStatusWait(&instance_PriStateBase);//&(instance_in_PLLS_RequestLinkStatusWait.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_RequestLinkStatusWait.pPriStateBase);
}

////////////////////////////////////////////////////////
// Class SendUnconfirmedTransmitWait
////////////////////////////////////////////////////////

void PLLS_SendUnconfirmedTransmitWait_in_PLLS_SendUnconfirmedTransmitWait(PriStateBase *pPriStateBase)
{
  PriStateBase_in_PriStateBase(pPriStateBase);

  pPriStateBase->pOnTxReady_in_PriStateBase = OnTxReady_in_PLLS_SendUnconfirmedTransmitWait_override;

  setParentPointer_in_PriStateBase(pPriStateBase, pPriStateBase);
}

void* OnTxReady_in_PLLS_SendUnconfirmedTransmitWait_override(void *pPriStateBase, LinkContext* ctx)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return OnTxReady_in_PLLS_SendUnconfirmedTransmitWait(parent, ctx);
}

////PriStateBase& PLLS_SendUnconfirmedTransmitWait::OnTxReady(LinkContext& ctx)
PriStateBase* OnTxReady_in_PLLS_SendUnconfirmedTransmitWait(PriStateBase *pPriStateBase,
    LinkContext* ctx)
{
  UNUSED(pPriStateBase);
//boolean Advance_in_ITransportSegment(ITransportSegment*);
////    if (ctx.pSegments->Advance())

  if (Advance_in_ITransportSegment(ctx->pSegments))
  {
//    ser4cpp::rseq_t FormatPrimaryBufferWithUnconfirmed(const Addresses& addr, const ser4cpp::rseq_t& tpdu);
//RSeq_for_Uint16_t GetSegment_in_ITransportSegment(ITransportSegment*);
////        auto output
////            = ctx.FormatPrimaryBufferWithUnconfirmed(ctx.pSegments->GetAddresses(), ctx.pSegments->GetSegment());
    RSeq_for_Uint16_t temp = GetSegment_in_ITransportSegment(ctx->pSegments);
    RSeq_for_Uint16_t output
      = FormatPrimaryBufferWithUnconfirmed_in_LinkContext(ctx, ////const Addresses& addr, const ser4cpp::rseq_t& tpdu);
          GetAddresses_in_ITransportSegment(ctx->pSegments),
          &temp);

////        ctx.QueueTransmit(output, true);
    QueueTransmit_in_LinkContext(ctx, &output, true);
////        return *this;
    PLLS_SendUnconfirmedTransmitWait_in_PLLS_SendUnconfirmedTransmitWait(&instance_PriStateBase);//&(instance_in_PLLS_SendUnconfirmedTransmitWait.pPriStateBase));
    return &instance_PriStateBase;//&(instance_in_PLLS_SendUnconfirmedTransmitWait.pPriStateBase);
  }
  // we're done

//    void CompleteSendOperation();
////    ctx.CompleteSendOperation();
  CompleteSendOperation_in_LinkContext(ctx);
////    return PLLS_Idle::Instance();
  PLLS_Idle_in_PLLS_Idle(&instance_PriStateBase);//&(instance_in_PLLS_Idle.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_Idle.pPriStateBase);
}

////////////////////////////////////////////////////////
// Class PLLS_RequestLinkStatusWait
////////////////////////////////////////////////////////

void PLLS_RequestLinkStatusWait_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase)
{
  PriStateBase_in_PriStateBase(pPriStateBase);

  pPriStateBase->pOnAck_in_PriStateBase = OnAck_in_PLLS_RequestLinkStatusWait_override;
  pPriStateBase->pOnNack_in_PriStateBase = OnNack_in_PLLS_RequestLinkStatusWait_override;
  pPriStateBase->pOnLinkStatus_in_PriStateBase = OnLinkStatus_in_PLLS_RequestLinkStatusWait_override;
  pPriStateBase->pOnNotSupported_in_PriStateBase = OnNotSupported_in_PLLS_RequestLinkStatusWait_override;
  pPriStateBase->pOnTxReady_in_PriStateBase = OnTxReady_in_PLLS_RequestLinkStatusWait_override;
  pPriStateBase->pOnTimeout_in_PriStateBase = OnTimeout_in_PLLS_RequestLinkStatusWait_override;
  pPriStateBase->pOnTimeout_in_PriStateBase = OnTimeout_in_PLLS_RequestLinkStatusWait_override;

  setParentPointer_in_PriStateBase(pPriStateBase, pPriStateBase);
}

void* OnAck_in_PLLS_RequestLinkStatusWait_override(void *pPriStateBase, LinkContext* ctx, boolean v)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return OnAck_in_PLLS_RequestLinkStatusWait(parent, ctx, v);
}
void* OnNack_in_PLLS_RequestLinkStatusWait_override(void *pPriStateBase, LinkContext* ctx, boolean v)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return OnNack_in_PLLS_RequestLinkStatusWait(parent, ctx, v);
}
void* OnLinkStatus_in_PLLS_RequestLinkStatusWait_override(void *pPriStateBase, LinkContext* ctx, boolean v)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return OnLinkStatus_in_PLLS_RequestLinkStatusWait(parent, ctx, v);
}
void* OnNotSupported_in_PLLS_RequestLinkStatusWait_override(void *pPriStateBase, LinkContext* ctx, boolean v)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return OnNotSupported_in_PLLS_RequestLinkStatusWait(parent, ctx, v);
}
void* OnTxReady_in_PLLS_RequestLinkStatusWait_override(void *pPriStateBase, LinkContext* ctx)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return OnTxReady_in_PLLS_RequestLinkStatusWait(parent, ctx);
}
void* OnTimeout_in_PLLS_RequestLinkStatusWait_override(void *pPriStateBase, LinkContext* ctx)
{
  PriStateBase* parent = (PriStateBase*) getParentPointer_in_PriStateBase((PriStateBase*) pPriStateBase);
  return OnTimeout_in_PLLS_RequestLinkStatusWait(parent, ctx);
}

PriStateBase* OnAck_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean v/*receiveBuffFull*/)
{
  UNUSED(v);
  UNUSED(pPriStateBase);
//    void CancelTimer();
////    ctx.CancelTimer();
  CancelTimer_in_LinkContext(ctx);

//    void FailKeepAlive(bool timeout);
////    ctx.FailKeepAlive(false);
  FailKeepAlive_in_LinkContext(ctx, false);

////    return PLLS_Idle::Instance();
  PLLS_Idle_in_PLLS_Idle(&instance_PriStateBase);//&(instance_in_PLLS_Idle.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_Idle.pPriStateBase);
}

PriStateBase* OnNack_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean v /*receiveBuffFull*/)
{
  UNUSED(v);
  UNUSED(pPriStateBase);
////    ctx.CancelTimer();
  CancelTimer_in_LinkContext(ctx);

////    ctx.FailKeepAlive(false);
  FailKeepAlive_in_LinkContext(ctx, false);

////    return PLLS_Idle::Instance();
  PLLS_Idle_in_PLLS_Idle(&instance_PriStateBase);//&(instance_in_PLLS_Idle.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_Idle.pPriStateBase);
}

PriStateBase* OnLinkStatus_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean v /*receiveBuffFull*/)
{
  UNUSED(v);
  UNUSED(pPriStateBase);
////    ctx.CancelTimer();
  CancelTimer_in_LinkContext(ctx);

//    void CompleteKeepAlive();
////    ctx.CompleteKeepAlive();
  CompleteKeepAlive_in_LinkContext(ctx);

////    return PLLS_Idle::Instance();
  PLLS_Idle_in_PLLS_Idle(&instance_PriStateBase);//&(instance_in_PLLS_Idle.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_Idle.pPriStateBase);
}

PriStateBase* OnNotSupported_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx, boolean v/*receiveBuffFull*/)
{
  UNUSED(v);
  UNUSED(pPriStateBase);
////    ctx.CancelTimer();
  CancelTimer_in_LinkContext(ctx);

////    ctx.FailKeepAlive(false);
  FailKeepAlive_in_LinkContext(ctx, false);

////    return PLLS_Idle::Instance();
  PLLS_Idle_in_PLLS_Idle(&instance_PriStateBase);//&(instance_in_PLLS_Idle.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_Idle.pPriStateBase);
}

PriStateBase* OnTxReady_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx)
{
  UNUSED(pPriStateBase);
  UNUSED(ctx);
  // The request link status was successfully sent
////    return *this;
  PLLS_RequestLinkStatusWait_in_PLLS_RequestLinkStatusWait(&instance_PriStateBase);//&(instance_in_PLLS_RequestLinkStatusWait.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_RequestLinkStatusWait.pPriStateBase);
}

PriStateBase* OnTimeout_in_PLLS_RequestLinkStatusWait(PriStateBase *pPriStateBase, LinkContext* ctx)
{
  UNUSED(pPriStateBase);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "Link status request - response timeout");
////    ctx.FailKeepAlive(true);
  std::cout<<"***SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, 'Link status request - response timeout'***"<<std::endl;
  FailKeepAlive_in_LinkContext(ctx, true);

////    return PLLS_Idle::Instance();
  PLLS_Idle_in_PLLS_Idle(&instance_PriStateBase);//&(instance_in_PLLS_Idle.pPriStateBase));
  return &instance_PriStateBase;//&(instance_in_PLLS_Idle.pPriStateBase);
}

////} // namespace opendnp3
