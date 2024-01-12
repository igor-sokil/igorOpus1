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
#include "LinkContext.h"

#include "ILinkTx.h"
#include "LinkFrame.h"
#include "PriLinkLayerStates.h"
#include "SecLinkLayerStates.h"
#include <string.h>

////namespace opendnp3
////{

void LinkContext_in_LinkContext(LinkContext *pLinkContext,
//                         const Logger& logger,
                                IExecutorExe4cpp* executor,
                                IUpperLayer* upper,
                                ILinkListener* listener,
                                ILinkSession* session,
                                LinkLayerConfig* config)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{LinkContext_in_LinkContext1"<<'\n';
#endif
  pLinkContext->linktx = NULL;
////    : logger(logger),
  pLinkContext->config = *config;
  pLinkContext->pSegments = NULL;
  pLinkContext->txMode = LinkTransmitMode_Idle;
  pLinkContext->executor = executor;
  pLinkContext->nextReadFCB = false;
  pLinkContext->isOnline = false;
  pLinkContext->keepAliveTimeout = false;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"LinkContext_in_LinkContext2"<<'\n';
#endif
//uint64_t Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *);
// void Timestamp_in_TimestampOver2(Timestamp *pTimestamp, uint64_t value);
////      pLinkContext->lastMessageTimestamp = ///executor->get_time()),
  uint64_t value = Get_time_in_ISteadyTimeSourceExe4cpp(&(executor->iISteadyTimeSourceExe4cpp));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"LinkContext_in_LinkContext2.1"<<'\n';
#endif
  Timestamp_in_TimestampOver2(&(pLinkContext->lastMessageTimestamp), value);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"LinkContext_in_LinkContext3"<<'\n';
#endif

////      pPriState(&PLLS_Idle::Instance()),
  pLinkContext->pPriState = Instance_in_PLLS_Idle_static();
////      pSecState(&SLLS_NotReset::Instance()),
  pLinkContext->pSecState = Instance_in_SLLS_NotReset_static();
  pLinkContext->listener = listener;
  pLinkContext->upper = upper;
  pLinkContext->pSession = session;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"LinkContext_in_LinkContext4"<<'\n';
#endif
//   void TimerExe4cpp_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp, ITimer* tim);
//  TimerExe4cpp rspTimeoutTimer;
//  TimerExe4cpp keepAliveTimer;
//  Link_StackStatistics statistics;
  Link_StackStatistics_in_Link_StackStatistics(&(pLinkContext->statistics));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}LinkContext_in_LinkContext_"<<'\n';
  decrement_stack_info();
#endif
}

static  LinkContext lLinkContext;

LinkContext* Create_in_LinkContext_static(//const Logger& logger,
  IExecutorExe4cpp* executor,
  IUpperLayer* upper,
  ILinkListener* listener,
  ILinkSession* session,
  LinkLayerConfig* config)
{
////    return std::shared_ptr<LinkContext>(new LinkContext(logger, executor, upper, listener, session, config));
  LinkContext_in_LinkContext(&lLinkContext,
//                         const Logger& logger,
                             executor,
                             upper,
                             listener,
                             session,
                             config);
  return &lLinkContext;
}

boolean OnLowerLayerUp_in_LinkContext(LinkContext *pLinkContext)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{OnLowerLayerUp_in_LinkContext1"<<'\n';
#endif
  if (pLinkContext->isOnline)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer already online");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already online')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}OnLowerLayerUp_in_LinkContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pLinkContext->isOnline = true;

  RestartKeepAliveTimer_in_LinkContext(pLinkContext);

//    void OnStateChange_in_ILinkListener(ILinkListener*, LinkStatus_uint8_t value);
////    listener->OnStateChange(LinkStatus::UNRESET);
  OnStateChange_in_ILinkListener(pLinkContext->listener, LinkStatus_UNRESET);

//boolean OnLowerLayerUp_in_IUpDown(IUpDown *);
////    upper->OnLowerLayerUp();
  OnLowerLayerUp_in_IUpDown(&(pLinkContext->upper->iIUpDown));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnLowerLayerUp_in_LinkContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

boolean OnLowerLayerDown_in_LinkContext(LinkContext *pLinkContext)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{OnLowerLayerDown_in_LinkContext1"<<'\n';
#endif
  if (!pLinkContext->isOnline)
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer already online')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}OnLowerLayerDown_in_LinkContext1_"<<'\n';
    decrement_stack_info();
#endif
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer is not online");
    return false;
  }

  pLinkContext->isOnline = false;
  pLinkContext->keepAliveTimeout = false;
  pLinkContext->pSegments = NULL;
  pLinkContext->txMode = LinkTransmitMode_Idle;
//void clear_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
////    pendingPriTx.clear();
  clear_in_Settable_for_RSeq_t(&(pLinkContext->pendingPriTx));
////    pendingSecTx.clear();
  clear_in_Settable_for_RSeq_t(&(pLinkContext->pendingSecTx));

//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    rspTimeoutTimer.cancel();
  cancel_in_TimerExe4cpp(&(pLinkContext->rspTimeoutTimer));
////    keepAliveTimer.cancel();
  cancel_in_TimerExe4cpp(&(pLinkContext->keepAliveTimer));

//PriStateBase* Instance_in_PLLS_Idle_static(void)
////    pPriState = &PLLS_Idle::Instance();
  pLinkContext->pPriState = Instance_in_PLLS_Idle_static();
//SecStateBase* Instance_in_SLLS_NotReset_static(void)
////    pSecState = &SLLS_NotReset::Instance();
  pLinkContext->pSecState = Instance_in_SLLS_NotReset_static();

////    listener->OnStateChange(LinkStatus::UNRESET);
  OnStateChange_in_ILinkListener(pLinkContext->listener, LinkStatus_UNRESET);
////    upper->OnLowerLayerDown();
  OnLowerLayerUp_in_IUpDown(&(pLinkContext->upper->iIUpDown));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnLowerLayerDown_in_LinkContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool LinkContext::SetTxSegment(ITransportSegment& segments)
boolean SetTxSegment_in_LinkContext(LinkContext *pLinkContext, ITransportSegment* segments)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{SetTxSegment_in_LinkContext1"<<'\n';
#endif
  if (!pLinkContext->isOnline)
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer is not online')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}SetTxSegment_in_LinkContext1_"<<'\n';
    decrement_stack_info();
#endif
////        SIMPLE_LOG_BLOCK(this->logger, flags::ERR, "Layer is not online");
    return false;
  }

  if (pLinkContext->pSegments)
  {
////        SIMPLE_LOG_BLOCK(this->logger, flags::ERR, "Already transmitting a segment");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Already transmitting a segment')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}SetTxSegment_in_LinkContext2_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pLinkContext->pSegments = segments;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}SetTxSegment_in_LinkContext3_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool LinkContext::OnTxReady()
boolean OnTxReady_in_LinkContext(LinkContext *pLinkContext)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{OnTxReady_in_LinkContext1"<<'\n';
#endif
  if (pLinkContext->txMode == LinkTransmitMode_Idle)
  {
////        SIMPLE_LOG_BLOCK(this->logger, flags::ERR, "Unknown transmission callback");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Unknown transmission callback')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}OnTxReady_in_LinkContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  boolean isPrimary = (pLinkContext->txMode == LinkTransmitMode_Primary);
  pLinkContext->txMode = LinkTransmitMode_Idle;

  // before we dispatch the transmit result, give any pending transmissions access first
// прежде чем мы отправим результат передачи, сначала предоставьте доступ к любым ожидающим передачам
//    boolean TryPendingTx_in_LinkContext(LinkContext *pLinkContext, Settable_for_RSeq_t* pending, boolean primary);
////    this->TryPendingTx(this->pendingSecTx, false);
  TryPendingTx_in_LinkContext(pLinkContext, &(pLinkContext->pendingSecTx), false);
////    this->TryPendingTx(this->pendingPriTx, true);
  TryPendingTx_in_LinkContext(pLinkContext, &(pLinkContext->pendingSecTx), true);

  // now dispatch the completion event to the correct state handler
// теперь отправляем событие завершения правильному обработчику состояния
  if (isPrimary)
  {
//PriStateBase* OnTxReady_in_PriStateBase(PriStateBase*, LinkContext*);
////        this->pPriState = &this->pPriState->OnTxReady(*this);
    pLinkContext->pPriState = OnTxReady_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext);
  }
  else
  {
    SecStateBase* OnTxReady_in_SecStateBase(SecStateBase*, LinkContext* ctx);
////        this->pSecState = &this->pSecState->OnTxReady(*this);
    pLinkContext->pSecState = OnTxReady_in_SecStateBase((SecStateBase*)pLinkContext->pSecState, pLinkContext);
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnTxReady_in_LinkContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////ser4cpp::rseq_t LinkContext::FormatPrimaryBufferWithUnconfirmed(const Addresses& addr, const ser4cpp::rseq_t& tpdu)
RSeq_for_Uint16_t FormatPrimaryBufferWithUnconfirmed_in_LinkContext(LinkContext *pLinkContext, Addresses* addr, RSeq_for_Uint16_t* tpdu)
{
//WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(StaticBuffer_for_LPDU_MAX_FRAME_SIZE *pStaticBuffer);
////    auto buffer = this->priTxBuffer.as_wseq();
  WSeq_for_Uint16_t  buffer = as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(&(pLinkContext->priTxBuffer));
//    RSeq_for_Uint16_t FormatUnconfirmedUserData_in_LinkFrame_static(WSeq_for_Uint16_t* buffer,
//                                                     boolean aIsMaster,
//                                                     uint16_t aDest,
//                                                     uint16_t aSrc,
//                                                     RSeq_for_Uint16_t user_data);//,
////    auto output
////        = LinkFrame::FormatUnconfirmedUserData(buffer, config.IsMaster, addr.destination, addr.source, tpdu, &logger);
  RSeq_for_Uint16_t output
    = FormatUnconfirmedUserData_in_LinkFrame_static(&buffer,
        pLinkContext->config.lLinkConfig.IsMaster,
        addr->destination,
        addr->source,
        *tpdu);//,
////    FORMAT_HEX_BLOCK(logger, flags::LINK_TX_HEX, output, 10, 18);
  return output;
}

////void LinkContext::QueueTransmit(const ser4cpp::rseq_t& buffer, bool primary)
void QueueTransmit_in_LinkContext(LinkContext *pLinkContext, RSeq_for_Uint16_t* buffer, boolean primary)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{QueueTransmit_in_LinkContext1"<<'\n';
#endif
  if (pLinkContext->txMode == LinkTransmitMode_Idle)
  {
    pLinkContext->txMode = primary ? LinkTransmitMode_Primary : LinkTransmitMode_Secondary;
//void BeginTransmit_in_ILinkTx(ILinkTx*, RSeq_for_Uint16_t* buffer, ILinkSession* context);
////        linktx->BeginTransmit(buffer, *pSession);
    BeginTransmit_in_ILinkTx(pLinkContext->linktx, buffer, pLinkContext->pSession);
  }
  else
  {
    if (primary)
    {
//void set_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t, RSeq_for_Uint16_t *value_);
////            pendingPriTx.set(buffer);
      set_in_Settable_for_RSeq_t(&(pLinkContext->pendingPriTx), buffer);
    }
    else
    {
////            pendingSecTx.set(buffer);
      set_in_Settable_for_RSeq_t(&(pLinkContext->pendingSecTx), buffer);
    }
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}QueueTransmit_in_LinkContext_"<<'\n';
  decrement_stack_info();
#endif
}

void QueueAck_in_LinkContext(LinkContext *pLinkContext, uint16_t destination)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{QueueAck_in_LinkContext1"<<'\n';
#endif
//WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver1(StaticBuffer_for_LPDU_HEADER_SIZE *pStaticBuffer);
////    auto dest = secTxBuffer.as_wseq();
  WSeq_for_Uint16_t  dest =  as_wseq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver1(&(pLinkContext->secTxBuffer));

//    RSeq_for_Uint16_t FormatAck_in_LinkFrame_static(
//        WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    auto buffer = LinkFrame::FormatAck(dest, config.IsMaster, false, destination, this->config.LocalAddr, &logger);
  RSeq_for_Uint16_t buffer = FormatAck_in_LinkFrame_static(
                               &dest, pLinkContext->config.lLinkConfig.IsMaster, false, destination, pLinkContext->config.lLinkConfig.LocalAddr);//, Logger* pLogger);

////    FORMAT_HEX_BLOCK(logger, flags::LINK_TX_HEX, buffer, 10, 18);
//    void QueueTransmit_in_LinkContext(LinkContext *pLinkContext, RSeq_for_Uint16_t* buffer, boolean primary)
////    this->QueueTransmit(buffer, false);
  QueueTransmit_in_LinkContext(pLinkContext, &buffer, false);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}QueueAck_in_LinkContext_"<<'\n';
  decrement_stack_info();
#endif
}

void QueueLinkStatus_in_LinkContext(LinkContext *pLinkContext, uint16_t destination)
{
////    auto dest = secTxBuffer.as_wseq();
  WSeq_for_Uint16_t  dest =  as_wseq_in_StaticBuffer_for_LPDU_HEADER_SIZEOver1(&(pLinkContext->secTxBuffer));
//    RSeq_for_Uint16_t FormatLinkStatus_in_LinkFrame_static(
//        WSeq_for_Uint16_t* buffer, boolean aIsMaster, boolean aIsRcvBuffFull, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    auto buffer
////        = LinkFrame::FormatLinkStatus(dest, config.IsMaster, false, destination, this->config.LocalAddr, &logger);
  RSeq_for_Uint16_t buffer
    = FormatLinkStatus_in_LinkFrame_static(
        &dest, pLinkContext->config.lLinkConfig.IsMaster, false, destination, pLinkContext->config.lLinkConfig.LocalAddr);//, Logger* pLogger);
////    FORMAT_HEX_BLOCK(logger, flags::LINK_TX_HEX, buffer, 10, 18);
////    this->QueueTransmit(buffer, false);
  QueueTransmit_in_LinkContext(pLinkContext, &buffer, false);
}

void QueueRequestLinkStatus_in_LinkContext(LinkContext *pLinkContext, uint16_t destination)
{
//    StaticBuffer_for_LPDU_MAX_FRAME_SIZE priTxBuffer;
//WSeq_for_Uint16_t  as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(StaticBuffer_for_LPDU_MAX_FRAME_SIZE *pStaticBuffer);
////    auto dest = priTxBuffer.as_wseq();
  WSeq_for_Uint16_t  dest =  as_wseq_in_StaticBuffer_for_LPDU_MAX_FRAME_SIZEOver1(&(pLinkContext->priTxBuffer));

//    RSeq_for_Uint16_t FormatRequestLinkStatus_in_LinkFrame_static(
//        WSeq_for_Uint16_t* buffer, boolean aIsMaster, uint16_t aDest, uint16_t aSrc);//, Logger* pLogger);
////    auto buffer
////        = LinkFrame::FormatRequestLinkStatus(dest, config.IsMaster, destination, this->config.LocalAddr, &logger);
  RSeq_for_Uint16_t buffer
    = FormatRequestLinkStatus_in_LinkFrame_static(
        &dest, pLinkContext->config.lLinkConfig.IsMaster, destination, pLinkContext->config.lLinkConfig.LocalAddr);//, Logger* pLogger);

////    FORMAT_HEX_BLOCK(logger, flags::LINK_TX_HEX, buffer, 10, 18);
////    this->QueueTransmit(buffer, true);
  QueueTransmit_in_LinkContext(pLinkContext, &buffer, true);
}

void PushDataUp_in_LinkContext(LinkContext *pLinkContext, Message* message)
{
//boolean OnReceive_in_IUpperLayer(IUpperLayer *, Message* message);
////    upper->OnReceive(message);
  OnReceive_in_IUpperLayer(pLinkContext->upper, message);
}

void callback_in_LinkContext(void);
void callback_in_LinkContext(void)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{callback_in_LinkContext1"<<'\n';
#endif
  IUpperLayer* upper = (IUpperLayer*) pPointerGlobal1;
  OnTxReady_in_IUpperLayer(upper);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}callback_in_LinkContext_"<<'\n';
  decrement_stack_info();
#endif
}

void CompleteSendOperation_in_LinkContext(LinkContext *pLinkContext)
{
  pLinkContext->pSegments = NULL;
  pPointerGlobal1 = pLinkContext->upper;
////    auto callback = [upper = upper]() { upper->OnTxReady(); };

//void Post_in_IExecutorExe4cpp(IExecutorExe4cpp *, void (*pAction)(void));
////    this->executor->post(callback);
  Post_in_IExecutorExe4cpp(pLinkContext->executor, callback_in_LinkContext);
}

void TryStartTransmission_in_LinkContext(LinkContext *pLinkContext)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{TryStartTransmission_in_LinkContext1"<<'\n';
#endif
  if (pLinkContext->keepAliveTimeout)
  {
//PriStateBase* TrySendRequestLinkStatus_in_PriStateBase(PriStateBase*, LinkContext*);
////        this->pPriState = &pPriState->TrySendRequestLinkStatus(*this);
    pLinkContext->pPriState = TrySendRequestLinkStatus_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext);
  }

  if (pLinkContext->pSegments)
  {
//PriStateBase* TrySendUnconfirmed_in_PriStateBase(PriStateBase*, LinkContext*, ITransportSegment* segments);
////        this->pPriState = &pPriState->TrySendUnconfirmed(*this, *pSegments);
    pLinkContext->pPriState = TrySendUnconfirmed_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext, pLinkContext->pSegments);
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}TryStartTransmission_in_LinkContext_"<<'\n';
  decrement_stack_info();
#endif
}

void OnKeepAliveTimeout_in_LinkContext(LinkContext *pLinkContext)
{
// void Timestamp_in_TimestampOver2(Timestamp *pTimestamp, uint64_t value);
//uint64_t Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *);
////    const auto now = Timestamp(this->executor->get_time());
  Timestamp now;
  Timestamp_in_TimestampOver2(&now, Get_time_in_ISteadyTimeSourceExe4cpp(&(pLinkContext->executor->iISteadyTimeSourceExe4cpp)));

//    uint64_t time_point_value;
//    Timestamp lastMessageTimestamp;
///    const auto elapsed = now - this->lastMessageTimestamp;
//истекший
  int64_t elapsed = now.time_point_value - pLinkContext->lastMessageTimestamp.time_point_value;

//    uint64_t duration_value;
//    TimeDuration KeepAliveTimeout;
  if (elapsed >= pLinkContext->config.lLinkConfig.KeepAliveTimeout.duration_value)
  {
    pLinkContext->keepAliveTimeout = true;
  }

//    void RestartKeepAliveTimer_in_LinkContext(LinkContext *pLinkContext);
////    this->RestartKeepAliveTimer();
  RestartKeepAliveTimer_in_LinkContext(pLinkContext);

//    void TryStartTransmission_in_LinkContext(LinkContext *pLinkContext);
////    this->TryStartTransmission();
  TryStartTransmission_in_LinkContext(pLinkContext);
}

void OnResponseTimeout_in_LinkContext(LinkContext *pLinkContext)
{
//PriStateBase* OnTimeout_in_PriStateBase(PriStateBase*, LinkContext*);
////    this->pPriState = &(this->pPriState->OnTimeout(*this));
  pLinkContext->pPriState =  OnTimeout_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext);

////    this->TryStartTransmission();
  TryStartTransmission_in_LinkContext(pLinkContext);
}

void callback2_in_LinkContext(void);
void callback2_in_LinkContext(void)
{
  LinkContext *pLinkContext = (LinkContext*) pPointerGlobal1;
  if (pLinkContext->isOnline)
  {
//    void OnResponseTimeout_in_LinkContext(LinkContext *pLinkContext);
////            self->OnResponseTimeout();
    OnResponseTimeout_in_LinkContext(pLinkContext);
  }
}
void StartResponseTimer_in_LinkContext(LinkContext *pLinkContext)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{StartResponseTimer_in_LinkContext1"<<'\n';
#endif
////    this->rspTimeoutTimer = executor->start(config.Timeout.value, [self = shared_from_this()]() {
////        if (self->isOnline)
////        {
////            self->OnResponseTimeout();
////        }
////    });
  pPointerGlobal1 = pLinkContext;
//TimerExe4cpp Start_in_IExecutorExe4cpp(IExecutorExe4cpp *, uint32_t duration, void (*pAction)(void));
//    TimeDuration Timeout;
  pLinkContext->rspTimeoutTimer =  Start_in_IExecutorExe4cpp(pLinkContext->executor, pLinkContext->config.lLinkConfig.Timeout.duration_value, callback2_in_LinkContext);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}StartResponseTimer_in_LinkContext_"<<'\n';
  decrement_stack_info();
#endif
}

void callback3_in_LinkContext(void);
void callback3_in_LinkContext(void)
{
  LinkContext *pLinkContext = (LinkContext*) pPointerGlobal1;
  if (pLinkContext->isOnline)
  {
//    void OnKeepAliveTimeout_in_LinkContext(LinkContext *pLinkContext);
////            self->OnKeepAliveTimeout();
    OnKeepAliveTimeout_in_LinkContext(pLinkContext);
  }
}
void RestartKeepAliveTimer_in_LinkContext(LinkContext *pLinkContext)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{RestartKeepAliveTimer_in_LinkContext1"<<'\n';
#endif
//    TimerExe4cpp keepAliveTimer;
//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    this->keepAliveTimer.cancel();
  cancel_in_TimerExe4cpp(&(pLinkContext->keepAliveTimer));

//uint64_t Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *);
////    this->lastMessageTimestamp = Timestamp(this->executor->get_time());
  uint64_t temp = get_time_in_IExecutorExe4cpp(pLinkContext->executor);//Get_time_in_ISteadyTimeSourceExe4cpp(&(pLinkContext->executor->iISteadyTimeSourceExe4cpp));
  Timestamp_in_TimestampOver2(&(pLinkContext->lastMessageTimestamp), temp);

//истечение срока
////    const auto expiration = this->lastMessageTimestamp + this->config.KeepAliveTimeout;
  uint64_t expiration = pLinkContext->lastMessageTimestamp.time_point_value + pLinkContext->config.lLinkConfig.KeepAliveTimeout.duration_value;

//qDebug()<<"RestartKeepAliveTimer_in_LinkContext1.3";

////    this->keepAliveTimer = executor->start(expiration.value, [self = shared_from_this()]() {
////        if (self->isOnline)
////        {
////            self->OnKeepAliveTimeout();
////        }
////    });
  pPointerGlobal1 = pLinkContext;
  pLinkContext->keepAliveTimer =  Start_in_IExecutorExe4cpp(pLinkContext->executor, expiration, callback3_in_LinkContext);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}RestartKeepAliveTimer_in_LinkContext_"<<'\n';
  decrement_stack_info();
#endif
}

void CancelTimer_in_LinkContext(LinkContext *pLinkContext)
{
//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    rspTimeoutTimer.cancel();
  cancel_in_TimerExe4cpp(&(pLinkContext->rspTimeoutTimer));
}

void FailKeepAlive_in_LinkContext(LinkContext *pLinkContext, boolean timeout)
{
  if (timeout)
  {
//    void OnKeepAliveFailure_in_ILinkListener(ILinkListener*);
////        this->listener->OnKeepAliveFailure();
    OnKeepAliveFailure_in_ILinkListener(pLinkContext->listener);
  }
}

void CompleteKeepAlive_in_LinkContext(LinkContext *pLinkContext)
{
//    void OnKeepAliveSuccess_in_ILinkListener(ILinkListener*);
////    this->listener->OnKeepAliveSuccess();
  OnKeepAliveSuccess_in_ILinkListener(pLinkContext->listener);
}

boolean OnFrame_in_LinkContext(LinkContext *pLinkContext, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{OnFrame_in_LinkContext1"<<'\n';
#endif

  if (!pLinkContext->isOnline)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Layer is not online");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Layer is not online')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}OnFrame_in_LinkContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (header->isFromMaster == pLinkContext->config.lLinkConfig.IsMaster)
  {
    ++(pLinkContext->statistics.numBadMasterBit);
////        SIMPLE_LOG_BLOCK(
////            logger, flags::WARN,
////            (header.isFromMaster ? "Master frame received for master" : "Outstation frame received for outstation"));
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Outstation frame received for outstation')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}OnFrame_in_LinkContext2_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

//    boolean IsBroadcast_in_Addresses(Addresses *pAddresses);
  if (header->addresses.destination != pLinkContext->config.lLinkConfig.LocalAddr && !IsBroadcast_in_Addresses(&(header->addresses)))////header.addresses.IsBroadcast())
  {
    ++(pLinkContext->statistics.numUnknownDestination);
//    void OnUnknownDestinationAddress_in_ILinkListener(ILinkListener*, uint16_t destination);
////        this->listener->OnUnknownDestinationAddress(header.addresses.destination);
    OnUnknownDestinationAddress_in_ILinkListener(pLinkContext->listener, header->addresses.destination);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnFrame_in_LinkContext3_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (header->addresses.source != pLinkContext->config.lLinkConfig.RemoteAddr && !pLinkContext->config.respondToAnySource)
  {
    ++(pLinkContext->statistics.numUnknownSource);
//    void OnUnknownSourceAddress_in_ILinkListener(ILinkListener*, uint16_t source);
////        this->listener->OnUnknownSourceAddress(header.addresses.source);
    OnUnknownSourceAddress_in_ILinkListener(pLinkContext->listener, header->addresses.source);

#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Outstation frame received for outstation')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}OnFrame_in_LinkContext4_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  // Broadcast addresses can only be used for sending data.
  // If confirmed data is used, no response is sent back.
// Широковещательные адреса можно использовать только для отправки данных.
  // Если используются подтвержденные данные, ответ не отправляется.
////    if (header.addresses.IsBroadcast() &&
  if (IsBroadcast_in_Addresses(&(header->addresses)) &&
      !(header->func == LinkFunction_PRI_UNCONFIRMED_USER_DATA || header->func == LinkFunction_PRI_CONFIRMED_USER_DATA))
  {
////        FORMAT_LOG_BLOCK(logger, flags::WARN, "Received invalid function (%s) with broadcast destination address",
////                            LinkFunctionSpec::to_string(header.func));
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"***FORMAT_LOG_BLOCK(logger, flags::WARN, 'Received invalid function (%s) with broadcast destination address')***"<<std::endl;
    std::cout<<getString_stack_info();
    std::cout<<"}OnFrame_in_LinkContext5_"<<'\n';
    decrement_stack_info();
#endif
    ++(pLinkContext->statistics.numUnexpectedFrame);

    return false;
  }

  // reset the keep-alive timestamp
////    this->RestartKeepAliveTimer();
  RestartKeepAliveTimer_in_LinkContext(pLinkContext);

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*header->func= "<<(uint16_t)header->func<<std::endl;
#endif

  switch (header->func)
  {
  case (LinkFunction_SEC_ACK):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_SEC_ACK"<<std::endl;
#endif
//PriStateBase* OnAck_in_PriStateBase(PriStateBase*, LinkContext*, boolean receiveBuffFull);
////        pPriState = &pPriState->OnAck(*this, header.fcvdfc);
    pLinkContext->pPriState =  OnAck_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext, header->fcvdfc);
    break;
  case (LinkFunction_SEC_NACK):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_SEC_NACK"<<std::endl;
#endif
////        pPriState = &pPriState->OnNack(*this, header.fcvdfc);
    pLinkContext->pPriState =  OnNack_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext, header->fcvdfc);
    break;
  case (LinkFunction_SEC_LINK_STATUS):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_SEC_LINK_STATUS"<<std::endl;
#endif
////        pPriState = &pPriState->OnLinkStatus(*this, header.fcvdfc);
    pLinkContext->pPriState =  OnLinkStatus_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext, header->fcvdfc);
    break;
  case (LinkFunction_SEC_NOT_SUPPORTED):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_SEC_NOT_SUPPORTED"<<std::endl;
#endif
////        pPriState = &pPriState->OnNotSupported(*this, header.fcvdfc);
    pLinkContext->pPriState =  OnNotSupported_in_PriStateBase((PriStateBase*)pLinkContext->pPriState, pLinkContext, header->fcvdfc);
    break;
  case (LinkFunction_PRI_TEST_LINK_STATES):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_PRI_TEST_LINK_STATES"<<std::endl;
#endif
//SecStateBase* OnTestLinkStatus_in_SecStateBase(SecStateBase*, LinkContext*, uint16_t source, boolean fcb);
////        pSecState = &pSecState->OnTestLinkStatus(*this, header.addresses.source, header.fcb);
    pLinkContext->pSecState =  OnTestLinkStatus_in_SecStateBase((SecStateBase*)pLinkContext->pSecState, pLinkContext, header->addresses.source, header->fcb);
    break;
  case (LinkFunction_PRI_RESET_LINK_STATES):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_PRI_RESET_LINK_STATES"<<std::endl;
#endif
////        pSecState = &pSecState->OnResetLinkStates(*this, header.addresses.source);
    pLinkContext->pSecState =  OnResetLinkStates_in_SecStateBase((SecStateBase*)pLinkContext->pSecState, pLinkContext, header->addresses.source);
    break;
  case (LinkFunction_PRI_REQUEST_LINK_STATUS):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_PRI_REQUEST_LINK_STATUS"<<std::endl;
#endif
////        pSecState = &pSecState->OnRequestLinkStatus(*this, header.addresses.source);
    pLinkContext->pSecState =  OnRequestLinkStatus_in_SecStateBase((SecStateBase*)pLinkContext->pSecState, pLinkContext, header->addresses.source);
    break;
  case (LinkFunction_PRI_CONFIRMED_USER_DATA):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_PRI_CONFIRMED_USER_DATA"<<std::endl;
#endif
//SecStateBase* OnConfirmedUserData_in_SecStateBase(SecStateBase*,
//    LinkContext*, uint16_t source, boolean fcb, boolean isBroadcast, Message* message);
//  void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
////        pSecState = &pSecState->OnConfirmedUserData(*this, header.addresses.source, header.fcb, header.addresses.IsBroadcast(),
////                                                    Message(header.addresses, userdata));
    Message mMessage;
    Message_in_Message(&mMessage, &(header->addresses), userdata);
    pLinkContext->pSecState =  OnConfirmedUserData_in_SecStateBase((SecStateBase*)pLinkContext->pSecState, pLinkContext,
                               header->addresses.source, header->fcb, IsBroadcast_in_Addresses(&(header->addresses)), &mMessage);
  }
  break;
  case (LinkFunction_PRI_UNCONFIRMED_USER_DATA):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*LinkFunction_PRI_UNCONFIRMED_USER_DATA"<<std::endl;
#endif
//    void PushDataUp_in_LinkContext(LinkContext *pLinkContext, Message* message);
////        this->PushDataUp(Message(header.addresses, userdata));
    Message mMessage;
    Message_in_Message(&mMessage, &(header->addresses), userdata);
    PushDataUp_in_LinkContext(pLinkContext, &mMessage);
  }
  break;
  default:
    break;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnFrame_in_LinkContext6_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool TryPendingTx_in_LinkContext(LinkContext *pLinkContext, ser4cpp::Settable<ser4cpp::rseq_t>& pending, bool primary)
boolean TryPendingTx_in_LinkContext(LinkContext *pLinkContext, Settable_for_RSeq_t* pending, boolean primary)
{
//boolean is_set_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
  if (pLinkContext->txMode == LinkTransmitMode_Idle && is_set_in_Settable_for_RSeq_t(pending))////pending.is_set())
  {
//void BeginTransmit_in_ILinkTx(ILinkTx*, RSeq_for_Uint16_t* buffer, ILinkSession* context);
//RSeq_for_Uint16_t get_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
////        this->linktx->BeginTransmit(pending.get(), *pSession);
    RSeq_for_Uint16_t buffer = get_in_Settable_for_RSeq_t(pending);
    BeginTransmit_in_ILinkTx(pLinkContext->linktx, &buffer, pLinkContext->pSession);

//void clear_in_Settable_for_RSeq_t(Settable_for_RSeq_t *pSettable_for_RSeq_t);
////        pending.clear();
    clear_in_Settable_for_RSeq_t(pending);

    pLinkContext->txMode = primary ? LinkTransmitMode_Primary : LinkTransmitMode_Secondary;
    return true;
  }

  return false;
}

////} // namespace opendnp3
void ResetReadFCB_in_LinkContext(LinkContext *pLinkContext)
{
  pLinkContext->nextReadFCB = true;
}
void ToggleReadFCB_in_LinkContext(LinkContext *pLinkContext)
{
  pLinkContext->nextReadFCB = !pLinkContext->nextReadFCB;
}

