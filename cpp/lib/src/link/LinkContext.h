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

#ifndef OPENDNP3_LINK_CONTEXT_H
#define OPENDNP3_LINK_CONTEXT_H

////#include "link/ILinkLayer.h"
////#include "link/ILinkSession.h"
////#include "link/ILinkTx.h"
////#include "link/LinkLayerConfig.h"
////#include "link/LinkLayerConstants.h"

////#include "opendnp3/StackStatistics.h"
////#include "opendnp3/gen/LinkStatus.h"
////#include "opendnp3/link/ILinkListener.h"
////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/util/Timestamp.h"

////#include <ser4cpp/container/Settable.h>
////#include <ser4cpp/container/StaticBuffer.h>

////#include <exe4cpp/IExecutor.h>

////#include <memory>

#include "ILinkLayer.h"
#include "ILinkSession.h"
#include "ILinkTx.h"
#include "LinkLayerConfig.h"
#include "LinkLayerConstants.h"

#include "StackStatistics.h"
#include "LinkStatus.h"
#include "ILinkListener.h"
///#include "logging/Logger.h"
#include "Timestamp.h"

#include "Settable_for_RSeq_t.h"
#include "StaticBuffer_for_LPDU_HEADER_SIZE.h"
#include "StaticBuffer_for_LPDU_MAX_FRAME_SIZE.h"

#include "IExecutorExe4cpp.h"
#include "RSeq.h"

////namespace opendnp3
////{

////class PriStateBase;
////class SecStateBase;

#define LinkTransmitMode_uint8_t  uint8_t
////enum class LinkTransmitMode : uint8_t
enum LinkTransmitMode
{
    LinkTransmitMode_Idle,
    LinkTransmitMode_Primary,
    LinkTransmitMode_Secondary
};

//	@section desc Implements the contextual state of DNP3 Data Link Layer
////class LinkContext : public std::enable_shared_from_this<LinkContext>
typedef struct
{
////    LinkContext(const Logger& logger,
////                const std::shared_ptr<exe4cpp::IExecutor>&,
////                std::shared_ptr<IUpperLayer>,
////                std::shared_ptr<ILinkListener>,
////                ILinkSession& session,
////                const LinkLayerConfig&);

////public:
////    static std::shared_ptr<LinkContext> Create(const Logger& logger,
////                                               const std::shared_ptr<exe4cpp::IExecutor>&,
////                                               std::shared_ptr<IUpperLayer>,
////                                               std::shared_ptr<ILinkListener>,
////                                               ILinkSession& session,
////                                               const LinkLayerConfig&);
////
    // ---- helpers for dealing with the FCB bits ----

////    void ResetReadFCB()
////    {
////        nextReadFCB = true;
////    }
////    void ToggleReadFCB()
////    {
////        nextReadFCB = !nextReadFCB;
////    }

    // --- helpers for dealing with layer state transitations ---
////    bool OnLowerLayerUp();
////    bool OnLowerLayerDown();
////    bool OnTxReady();
////    bool SetTxSegment(ITransportSegment& segments);

    // --- helpers for formatting user data messages ---
////    ser4cpp::rseq_t FormatPrimaryBufferWithUnconfirmed(const Addresses& addr, const ser4cpp::rseq_t& tpdu);

    // --- Helpers for queueing frames ---
////    void QueueAck(uint16_t destination);
////    void QueueLinkStatus(uint16_t destination);
////    void QueueRequestLinkStatus(uint16_t destination);
////
////    void QueueTransmit(const ser4cpp::rseq_t& buffer, bool primary);

    // --- public members ----

////    void PushDataUp(const Message& message);
////    void CompleteSendOperation();
////    void TryStartTransmission();
////    void OnKeepAliveTimeout();
////    void OnResponseTimeout();
////    void StartResponseTimer();
////    void RestartKeepAliveTimer();
////    void CancelTimer();
////    void FailKeepAlive(bool timeout);
////    void CompleteKeepAlive();
////    bool OnFrame(const LinkHeaderFields& header, const ser4cpp::rseq_t& userdata);
////    bool TryPendingTx(ser4cpp::Settable<ser4cpp::rseq_t>& pending, bool primary);

    // buffers used for primary and secondary requests
////    ser4cpp::StaticBuffer<LPDU_MAX_FRAME_SIZE> priTxBuffer;
////    ser4cpp::StaticBuffer<LPDU_HEADER_SIZE> secTxBuffer;
    StaticBuffer_for_LPDU_MAX_FRAME_SIZE priTxBuffer;

    StaticBuffer_for_LPDU_HEADER_SIZE secTxBuffer;

    Settable_for_RSeq_t pendingPriTx;
    Settable_for_RSeq_t pendingSecTx;

////    Logger logger;
    LinkLayerConfig config;
    ITransportSegment* pSegments;
    LinkTransmitMode_uint8_t txMode;

////    const std::shared_ptr<exe4cpp::IExecutor> executor;
   IExecutor* executor;

////    exe4cpp::Timer rspTimeoutTimer;
    TimerExe4cpp rspTimeoutTimer;
////    exe4cpp::Timer keepAliveTimer;
    TimerExe4cpp keepAliveTimer;
    boolean nextReadFCB;
    boolean isOnline;
    boolean keepAliveTimeout;
    Timestamp lastMessageTimestamp;
////    StackStatistics::Link statistics;
    Link_in_StackStatistics statistics;

    ILinkTx* linktx;// = nullptr;

////    PriStateBase* pPriState;
////    SecStateBase* pSecState;
    void* pPriState;
    void* pSecState;

////    const std::shared_ptr<ILinkListener> listener;
     ILinkListener* listener;
///    const std::shared_ptr<IUpperLayer> upper;
     IUpperLayer* upper;

    ILinkSession* pSession;
} LinkContext;

  void  LinkContext_in_LinkContext(LinkContext *pLinkContext, 
                //const Logger& logger,
                IExecutor*,
                IUpperLayer*,
                ILinkListener*,
                ILinkSession*,
                LinkLayerConfig*);

////public:
    LinkContext* Create_in_LinkContext_static( // const Logger& logger,
                                               IExecutor*,
                                               IUpperLayer*,
                                               ILinkListener*,
                                               ILinkSession* session,
                                               LinkLayerConfig*);

    // ---- helpers for dealing with the FCB bits ----

    void ResetReadFCB_in_LinkContext(LinkContext *pLinkContext);
    void ToggleReadFCB_in_LinkContext(LinkContext *pLinkContext);

    // --- helpers for dealing with layer state transitations ---
    boolean OnLowerLayerUp_in_LinkContext(LinkContext *pLinkContext);
    boolean OnLowerLayerDown_in_LinkContext(LinkContext *pLinkContext);
    boolean OnTxReady_in_LinkContext(LinkContext *pLinkContext);
    boolean SetTxSegment_in_LinkContext(LinkContext *pLinkContext, ITransportSegment* segments);

    // --- helpers for formatting user data messages ---
RSeq_for_Uint16_t FormatPrimaryBufferWithUnconfirmed_in_LinkContext(LinkContext *pLinkContext, Addresses* addr, RSeq_for_Uint16_t* tpdu);

    // --- Helpers for queueing frames ---
    void QueueAck_in_LinkContext(LinkContext *pLinkContext, uint16_t destination);
    void QueueLinkStatus_in_LinkContext(LinkContext *pLinkContext, uint16_t destination);
    void QueueRequestLinkStatus_in_LinkContext(LinkContext *pLinkContext, uint16_t destination);

    void QueueTransmit_in_LinkContext(LinkContext *pLinkContext, RSeq_for_Uint16_t* buffer, boolean primary);

    // --- public members ----

    void PushDataUp_in_LinkContext(LinkContext *pLinkContext, Message* message);
    void CompleteSendOperation_in_LinkContext(LinkContext *pLinkContext);
    void TryStartTransmission_in_LinkContext(LinkContext *pLinkContext);
    void OnKeepAliveTimeout_in_LinkContext(LinkContext *pLinkContext);
    void OnResponseTimeout_in_LinkContext(LinkContext *pLinkContext);
    void StartResponseTimer_in_LinkContext(LinkContext *pLinkContext);
    void RestartKeepAliveTimer_in_LinkContext(LinkContext *pLinkContext);
    void CancelTimer_in_LinkContext(LinkContext *pLinkContext);
    void FailKeepAlive_in_LinkContext(LinkContext *pLinkContext, boolean timeout);
    void CompleteKeepAlive_in_LinkContext(LinkContext *pLinkContext);
    boolean OnFrame_in_LinkContext(LinkContext *pLinkContext, LinkHeaderFields* header, RSeq_for_Uint16_t* userdata);
    boolean TryPendingTx_in_LinkContext(LinkContext *pLinkContext, Settable_for_RSeq* pending, boolean primary);

////} // namespace opendnp3

#endif
