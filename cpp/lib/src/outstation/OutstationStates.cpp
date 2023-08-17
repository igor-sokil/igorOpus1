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

////#include "outstation/OutstationStates.h"

////#include "logging/LogMacros.h"
////#include "outstation/OutstationContext.h"

////#include "opendnp3/logging/LogLevels.h"

#include <QtWidgets>
#include <QApplication>
#include "header.h"
#include "OutstationStates.h"

#include "OutstationContext.h"

////namespace opendnp3
////{

void* getParentPointer_in_OutstationState(OutstationState* pOutstationState)
{
  return pOutstationState->pParentPointer_in_OutstationState;
}

void  setParentPointer_in_OutstationState(OutstationState* pOutstationState, void* pParentPointer)
{
  pOutstationState->pParentPointer_in_OutstationState = pParentPointer;
}

void OutstationState_in_OutstationState(OutstationState *pOutstationState)
{
  pOutstationState->pIsIdle_in_OutstationState = IsIdle_in_OutstationState_override;
}

boolean IsIdle_in_OutstationState_override(void *pOutstationState)
{
  UNUSED(pOutstationState);
  return false;
}

boolean IsIdle_in_OutstationState(OutstationState *pOutstationState)
{
  return (pOutstationState->pIsIdle_in_OutstationState)(pOutstationState);
}
char* Name_in_OutstationState(OutstationState *pOutstationState)
{
  return (pOutstationState->pName_in_OutstationState)(pOutstationState);
}

OutstationState* OnConfirm_in_OutstationState(OutstationState* pOutstationState, void* pOContext, ParsedRequest* request)
{
  return (OutstationState*)(pOutstationState->pOnConfirm_in_OutstationState)(pOutstationState, pOContext, request);
}
OutstationState* OnConfirmTimeout_in_OutstationState(OutstationState* pOutstationState, void* pOContext)
{
  return (OutstationState*)(pOutstationState->pOnConfirmTimeout_in_OutstationState)(pOutstationState, pOContext);
}
OutstationState* OnNewReadRequest_in_OutstationState(OutstationState* pOutstationState, void* pOContext, ParsedRequest* request)
{
  return (OutstationState*)(pOutstationState->pOnNewReadRequest_in_OutstationState)(pOutstationState, pOContext, request);
}
OutstationState* OnNewNonReadRequest_in_OutstationState(OutstationState* pOutstationState, void* pOContext, ParsedRequest* request)
{
  return (OutstationState*)(pOutstationState->pOnNewNonReadRequest_in_OutstationState)(pOutstationState, pOContext, request);
}
OutstationState* OnRepeatNonReadRequest_in_OutstationState(OutstationState* pOutstationState, void* pOContext, ParsedRequest* request)
{
  return (OutstationState*)(pOutstationState->pOnRepeatNonReadRequest_in_OutstationState)(pOutstationState, pOContext, request);
}
OutstationState* OnRepeatReadRequest_in_OutstationState(OutstationState* pOutstationState, void* pOContext, ParsedRequest* request)
{
  return (OutstationState*)(pOutstationState->pOnRepeatReadRequest_in_OutstationState)(pOutstationState, pOContext, request);
}
OutstationState* OnBroadcastMessage_in_OutstationState(OutstationState* pOutstationState, void* pOContext, ParsedRequest* request)
{
  return (OutstationState*)(pOutstationState->pOnBroadcastMessage_in_OutstationState)(pOutstationState, pOContext, request);
}
// ------------- StateIdle ----------------

static StateIdle instance_in_StateIdle;

void StateIdle_in_StateIdle(StateIdle *pStateIdle)
{
  qDebug()<<"StateIdle_in_StateIdle1";
  OutstationState_in_OutstationState(&(pStateIdle->oOutstationState));

  (pStateIdle->oOutstationState).pIsIdle_in_OutstationState = IsIdle_in_StateIdle_override;
  (pStateIdle->oOutstationState).pName_in_OutstationState = Name_in_StateIdle_override;

  (pStateIdle->oOutstationState).pOnConfirm_in_OutstationState = OnConfirm_in_StateIdle_override;
  (pStateIdle->oOutstationState).pOnConfirmTimeout_in_OutstationState = OnConfirmTimeout_in_StateIdle_override;
//  /*
  (pStateIdle->oOutstationState).pOnNewReadRequest_in_OutstationState = OnNewReadRequest_in_StateIdle_override;
//  */
  (pStateIdle->oOutstationState).pOnNewNonReadRequest_in_OutstationState = OnNewNonReadRequest_in_StateIdle_override;
  (pStateIdle->oOutstationState).pOnRepeatNonReadRequest_in_OutstationState = OnRepeatNonReadRequest_in_StateIdle_override;
  (pStateIdle->oOutstationState).pOnRepeatReadRequest_in_OutstationState = OnRepeatReadRequest_in_StateIdle_override;
  (pStateIdle->oOutstationState).pOnBroadcastMessage_in_OutstationState = OnBroadcastMessage_in_StateIdle_override;

  setParentPointer_in_OutstationState(&(pStateIdle->oOutstationState), pStateIdle);
}

////OutstationState& StateIdle::OnConfirm(OContext& ctx, const ParsedRequest& request)
void* OnConfirm_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request)
{
  UNUSED(pOutstationState);
  UNUSED(pOContext);
  UNUSED(request);
////    FORMAT_LOG_BLOCK(ctx.logger, flags::WARN, "unexpected confirm while IDLE with sequence: %u",
////                     request.header.control.SEQ);
  return Inst_in_StateIdle_static();////StateIdle::Inst();
}

////OutstationState& StateIdle::OnConfirmTimeout(OContext& ctx)
void* OnConfirmTimeout_in_StateIdle_override(void* pOutstationState, void *pOContext)
{
  UNUSED(pOutstationState);
  UNUSED(pOContext);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "unexpected confirm timeout");
  return Inst_in_StateIdle_static();////StateIdle::Inst();
}

///*
////OutstationState& StateIdle::OnNewReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnNewReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request)
{
  UNUSED(pOutstationState);
  return RespondToReadRequest_in_OContext((OContext *)pOContext, request);
////    return ctx.RespondToReadRequest(request);
}
//*/

////OutstationState& StateIdle::OnNewNonReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnNewNonReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request)
{
qDebug()<<"";
qDebug()<<"OnNewNonReadRequest_in_StateIdle_override1";
  UNUSED(pOutstationState);
  return RespondToNonReadRequest_in_OContext((OContext *)pOContext, request);
////    return ctx.RespondToNonReadRequest(request);
}

////OutstationState& StateIdle::OnRepeatNonReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnRepeatNonReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request)
{
  StateIdle *parent =
    (StateIdle*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
//    void BeginRetransmitLastResponse_in_OContext(OContext *pOContext, uint16_t destination);
////    ctx.BeginRetransmitLastResponse(request.addresses.source);
  BeginRetransmitLastResponse_in_OContext((OContext *)pOContext, (request->addresses).source);
////    return *this;
  return &(parent->oOutstationState);
}

////OutstationState& StateIdle::OnRepeatReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnRepeatReadRequest_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request)
{
  StateIdle *parent =
    (StateIdle*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
////    ctx.BeginRetransmitLastResponse(request.addresses.source);
////    return *this;
  BeginRetransmitLastResponse_in_OContext((OContext *)pOContext, (request->addresses).source);
  return &(parent->oOutstationState);
}

////OutstationState& StateIdle::OnBroadcastMessage(OContext& ctx, const ParsedRequest& request)
void* OnBroadcastMessage_in_StateIdle_override(void* pOutstationState, void *pOContext, ParsedRequest* request)
{
  StateIdle *parent =
    (StateIdle*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
//    boolean ProcessBroadcastRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////    ctx.ProcessBroadcastRequest(request);
  ProcessBroadcastRequest_in_OContext((OContext *)pOContext, request);
////    return *this;
  return &(parent->oOutstationState);
}

// ------------- StateSolicitedConfirmWait ----------------

static StateSolicitedConfirmWait instance_in_StateSolicitedConfirmWait;
////StateSolicitedConfirmWait StateSolicitedConfirmWait::instance;

void StateSolicitedConfirmWait_in_StateSolicitedConfirmWait(StateSolicitedConfirmWait *pStateSolicitedConfirmWait)
{
  qDebug()<<"StateSolicitedConfirmWait_in_StateSolicitedConfirmWait1";

  OutstationState_in_OutstationState(&(pStateSolicitedConfirmWait->oOutstationState));

  (pStateSolicitedConfirmWait->oOutstationState).pName_in_OutstationState = Name_in_StateSolicitedConfirmWait_override;

  (pStateSolicitedConfirmWait->oOutstationState).pOnConfirm_in_OutstationState = OnConfirm_in_StateSolicitedConfirmWait_override;
  (pStateSolicitedConfirmWait->oOutstationState).pOnConfirmTimeout_in_OutstationState = OnConfirmTimeout_in_StateSolicitedConfirmWait_override;

//  /*
  (pStateSolicitedConfirmWait->oOutstationState).pOnNewReadRequest_in_OutstationState = OnNewReadRequest_in_StateSolicitedConfirmWait_override;
//  */

  (pStateSolicitedConfirmWait->oOutstationState).pOnNewNonReadRequest_in_OutstationState = OnNewNonReadRequest_in_StateSolicitedConfirmWait_override;
  (pStateSolicitedConfirmWait->oOutstationState).pOnRepeatNonReadRequest_in_OutstationState = OnRepeatNonReadRequest_in_StateSolicitedConfirmWait_override;
  (pStateSolicitedConfirmWait->oOutstationState).pOnRepeatReadRequest_in_OutstationState = OnRepeatReadRequest_in_StateSolicitedConfirmWait_override;
  (pStateSolicitedConfirmWait->oOutstationState).pOnBroadcastMessage_in_OutstationState = OnBroadcastMessage_in_StateSolicitedConfirmWait_override;

  setParentPointer_in_OutstationState(&(pStateSolicitedConfirmWait->oOutstationState), pStateSolicitedConfirmWait);
}

////OutstationState& StateSolicitedConfirmWait::OnConfirm(OContext& ctx, const ParsedRequest& request)
void* OnConfirm_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateSolicitedConfirmWait *parent =
    (StateSolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);

////    if (request.header.control.UNS)
  if ((request->header).control.UNS)
  {
////        FORMAT_LOG_BLOCK(ctx.logger, flags::WARN,
////                         "received unsolicited confirm while waiting for solicited confirm (seq: %u)",
////                         request.header.control.SEQ);
////        return *this;
    return &(parent->oOutstationState);
  }

//boolean Equals_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t other);
////    if (!((OContext*)ctx)->sol.seq.confirmNum.Equals(request.header.control.SEQ))
  if (!Equals_in_SequenceNum_for_uint8_Modulus16(&(((OContext*)ctx)->sol.seq.confirmNum), (request->header).control.SEQ))
  {
////        FORMAT_LOG_BLOCK(ctx.logger, flags::WARN, "solicited confirm with wrong seq: %u, expected: %u",
////                         request.header.control.SEQ, ctx.sol.seq.confirmNum.Get());
////        return *this;
    return &(parent->oOutstationState);
  }

//   void Reset_in_RequestHistory(RequestHistory *pRequestHistory);
////    ctx.history.Reset(); // any time we get a confirm we can treat any request as a new request
  Reset_in_RequestHistory(&(((OContext*)ctx)->history));
//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    ctx.confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(((OContext*)ctx)->confirmTimer));
////    ctx.eventBuffer.ClearWritten();
  ClearWritten_in_EventBuffer(&(((OContext*)ctx)->eventBuffer)); // called when a transmission succeeds
////    ctx.lastBroadcastMessageReceived.clear();
  clear_in_Settable_for_LinkBroadcastAddress(&(((OContext*)ctx)->lastBroadcastMessageReceived));

  // information the application about the confirm
//    void OnConfirmProcessed_in_IOutstationApplication(IOutstationApplication*, boolean is_unsolicited, uint32_t num_class1, uint32_t num_class2, uint32_t num_class3);
//    uint32_t NumEvents_in_EventBuffer(EventBuffer *pEventBuffer, EventClass_uint8_t ec);
////    ctx.application->OnConfirmProcessed(
////        false,
////        ctx.eventBuffer.NumEvents(EventClass::EC1),
////        ctx.eventBuffer.NumEvents(EventClass::EC2),
////        ctx.eventBuffer.NumEvents(EventClass::EC3)
////    );
  OnConfirmProcessed_in_IOutstationApplication((((OContext*)ctx)->application), false,
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer), EventClass_EC1),
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer), EventClass_EC2),
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer), EventClass_EC3));

// boolean HasSelection_in_ResponseContext(ResponseContext *pResponseContext);
////    if (ctx.rspContext.HasSelection())
  if (HasSelection_in_ResponseContext(&(((OContext*)ctx)->rspContext)))
  {
//    OutstationState* ContinueMultiFragResponse_in_OContext(OContext *pOContext, Addresses* addresses, AppSeqNum* seq);
//void SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t value);
//uint8_t Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(uint8_t seq);
////        return ctx.ContinueMultiFragResponse(request.addresses, AppSeqNum(request.header.control.SEQ).Next());
    SequenceNum_for_uint8_Modulus16  sSequenceNum_for_uint8_Modulus16;
    SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(&sSequenceNum_for_uint8_Modulus16, (request->header).control.SEQ);
    sSequenceNum_for_uint8_Modulus16.seq = Next_in_SequenceNum_for_uint8_Modulus16_staticOver2(sSequenceNum_for_uint8_Modulus16.seq);
    return ContinueMultiFragResponse_in_OContext((OContext*)ctx, &(request->addresses), &sSequenceNum_for_uint8_Modulus16);
  }

//     OutstationState* Inst_in_StateIdle_static(void);
////    return StateIdle::Inst();
  return Inst_in_StateIdle_static();
}

////OutstationState& StateSolicitedConfirmWait::OnConfirmTimeout(OContext& ctx)
void* OnConfirmTimeout_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *pOContext)
{
  UNUSED(pOutstationState);
  UNUSED(pOContext);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "solicited confirm timeout");
////    return StateIdle::Inst();
  return Inst_in_StateIdle_static();
}

///*
////OutstationState& StateSolicitedConfirmWait::OnNewReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnNewReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  UNUSED(pOutstationState);
////    ctx.confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(((OContext*)ctx)->confirmTimer));
////    return ctx.RespondToReadRequest(request);
  return RespondToReadRequest_in_OContext((OContext *)ctx, request);
}
//*/

////OutstationState& StateSolicitedConfirmWait::OnNewNonReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnNewNonReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  UNUSED(pOutstationState);
//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    ctx.confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(((OContext*)ctx)->confirmTimer));
////    return ctx.RespondToNonReadRequest(request);
  return RespondToNonReadRequest_in_OContext((OContext *)ctx, request);
}

////OutstationState& StateSolicitedConfirmWait::OnRepeatNonReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnRepeatNonReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateSolicitedConfirmWait *parent =
    (StateSolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
////    ctx.confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(((OContext*)ctx)->confirmTimer));
////    ctx.BeginRetransmitLastResponse(request.addresses.source);
////    return *this;
  BeginRetransmitLastResponse_in_OContext((OContext *)ctx, (request->addresses).source);
  return &(parent->oOutstationState);
}

////OutstationState& StateSolicitedConfirmWait::OnRepeatReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnRepeatReadRequest_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateSolicitedConfirmWait *parent =
    (StateSolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
//    void RestartSolConfirmTimer_in_OContext(OContext *pOContext);
////    ctx.RestartSolConfirmTimer();
  RestartSolConfirmTimer_in_OContext((OContext *)ctx);
////    ctx.BeginRetransmitLastResponse(request.addresses.source);
////    return *this;
  BeginRetransmitLastResponse_in_OContext((OContext *)ctx, (request->addresses).source);
  return &(parent->oOutstationState);
}

////OutstationState& StateSolicitedConfirmWait::OnBroadcastMessage(OContext& ctx, const ParsedRequest& request)
void* OnBroadcastMessage_in_StateSolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  UNUSED(pOutstationState);
////    ctx.ProcessBroadcastRequest(request);
  ProcessBroadcastRequest_in_OContext((OContext *)ctx, request);
////    return StateIdle::Inst();
  return Inst_in_StateIdle_static();
}

// ------------- StateUnsolicitedConfirmWait ----------------

////StateUnsolicitedConfirmWait StateUnsolicitedConfirmWait::instance;
static StateUnsolicitedConfirmWait instance_in_StateUnsolicitedConfirmWait;

void StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait(StateUnsolicitedConfirmWait *pStateUnsolicitedConfirmWait)
{
  qDebug()<<"StateUnsolicitedConfirmWait_in_StateUnsolicitedConfirmWait1";

  OutstationState_in_OutstationState(&(pStateUnsolicitedConfirmWait->oOutstationState));

  (pStateUnsolicitedConfirmWait->oOutstationState).pName_in_OutstationState = Name_in_StateUnsolicitedConfirmWait_override;

  (pStateUnsolicitedConfirmWait->oOutstationState).pOnConfirm_in_OutstationState = OnConfirm_in_StateUnsolicitedConfirmWait_override;
  (pStateUnsolicitedConfirmWait->oOutstationState).pOnConfirmTimeout_in_OutstationState = OnConfirmTimeout_in_StateUnsolicitedConfirmWait_override;
  (pStateUnsolicitedConfirmWait->oOutstationState).pOnNewReadRequest_in_OutstationState = OnNewReadRequest_in_StateUnsolicitedConfirmWait_override;
  (pStateUnsolicitedConfirmWait->oOutstationState).pOnNewNonReadRequest_in_OutstationState = OnNewNonReadRequest_in_StateUnsolicitedConfirmWait_override;
  (pStateUnsolicitedConfirmWait->oOutstationState).pOnRepeatNonReadRequest_in_OutstationState = OnRepeatNonReadRequest_in_StateUnsolicitedConfirmWait_override;
  (pStateUnsolicitedConfirmWait->oOutstationState).pOnRepeatReadRequest_in_OutstationState = OnRepeatReadRequest_in_StateUnsolicitedConfirmWait_override;
  (pStateUnsolicitedConfirmWait->oOutstationState).pOnBroadcastMessage_in_OutstationState = OnBroadcastMessage_in_StateUnsolicitedConfirmWait_override;

  setParentPointer_in_OutstationState(&(pStateUnsolicitedConfirmWait->oOutstationState), pStateUnsolicitedConfirmWait);
}

//OutstationState& StateUnsolicitedConfirmWait::OnConfirm(OContext& ctx, const ParsedRequest& request)
void* OnConfirm_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateUnsolicitedConfirmWait *parent =
    (StateUnsolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
////    if (!request.header.control.UNS)
  if (!(request->header).control.UNS)
  {
////        FORMAT_LOG_BLOCK(ctx.logger, flags::WARN,
////                         "received solicited confirm while waiting for unsolicited confirm (seq: %u)",
////                         request.header.control.SEQ);
////        return *this;
    return &(parent->oOutstationState);
  }

////    if (!ctx.unsol.seq.confirmNum.Equals(request.header.control.SEQ))
  if (!Equals_in_SequenceNum_for_uint8_Modulus16(&(((OContext*)ctx)->unsol.seq.confirmNum), (request->header).control.SEQ))
  {
////        FORMAT_LOG_BLOCK(ctx.logger, flags::WARN, "unsolicited confirm with wrong seq: %u, expected: %u",
////                         request.header.control.SEQ, ctx.unsol.seq.confirmNum.Get());
////        return *this;
    return &(parent->oOutstationState);
  }

////    ctx.history.Reset(); // any time we get a confirm we can treat any request as a new request
  Reset_in_RequestHistory(&(((OContext*)ctx)->history));
////    ctx.confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(((OContext*)ctx)->confirmTimer));
////    ctx.lastBroadcastMessageReceived.clear();
  clear_in_Settable_for_LinkBroadcastAddress(&(((OContext*)ctx)->lastBroadcastMessageReceived));

  // information the application about the confirm
////    ctx.application->OnConfirmProcessed(
////        true,
////        ctx.eventBuffer.NumEvents(EventClass::EC1),
////        ctx.eventBuffer.NumEvents(EventClass::EC2),
////        ctx.eventBuffer.NumEvents(EventClass::EC3)
////    );
  OnConfirmProcessed_in_IOutstationApplication((((OContext*)ctx)->application), true,
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer), EventClass_EC1),
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer), EventClass_EC2),
      NumEvents_in_EventBuffer(&(((OContext*)ctx)->eventBuffer), EventClass_EC3));

  if (((OContext*)ctx)->unsol.completedNull)
  {
////        ctx.eventBuffer.ClearWritten();
    ClearWritten_in_EventBuffer(&(((OContext*)ctx)->eventBuffer)); // called when a transmission succeeds
  }
  else
  {
////        ctx.unsol.completedNull = true;
    ((OContext*)ctx)->unsol.completedNull = true;
  }

////    ctx.shouldCheckForUnsolicited = true;
  ((OContext*)ctx)->shouldCheckForUnsolicited = true;

////    return StateIdle::Inst();
  return Inst_in_StateIdle_static();
}

////OutstationState& StateUnsolicitedConfirmWait::OnConfirmTimeout(OContext& ctx)
void* OnConfirmTimeout_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx)
{
  StateUnsolicitedConfirmWait *parent =
    (StateUnsolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
////    SIMPLE_LOG_BLOCK(ctx.logger, flags::WARN, "unsolicited confirm timeout");

////    if (ctx.unsol.completedNull)
  if (((OContext*)ctx)->unsol.completedNull)
  {
//   boolean Retry_in_NumRetries(NumRetries *pNumRetries);
////        auto shouldRetry = ctx.unsolRetries.Retry();
    boolean shouldRetry = Retry_in_NumRetries(&(((OContext*)ctx)->unsolRetries));
//  boolean IsSet_in_DeferredRequest(DeferredRequest *pDeferredRequest);
////        if (shouldRetry && !ctx.deferred.IsSet())
    if (shouldRetry && !IsSet_in_DeferredRequest(&(((OContext*)ctx)->deferred)))
    {
//    void RestartUnsolConfirmTimer_in_OContext(OContext *pOContext);
////            ctx.RestartUnsolConfirmTimer();
      RestartUnsolConfirmTimer_in_OContext((OContext *)ctx);
////            ctx.BeginRetransmitLastUnsolicitedResponse();
      BeginRetransmitLastUnsolicitedResponse_in_OContext((OContext *)ctx);
////            return *this;
      return &(parent->oOutstationState);
    }
    else
    {
////            ctx.eventBuffer.Unselect();
      Unselect_in_EventBuffer(&(((OContext*)ctx)->eventBuffer));
    }
  }

////    return StateIdle::Inst();
  return Inst_in_StateIdle_static();
}

////OutstationState& StateUnsolicitedConfirmWait::OnNewReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnNewReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateUnsolicitedConfirmWait *parent =
    (StateUnsolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
//  void Set_in_DeferredRequest(DeferredRequest *pDeferredRequest, ParsedRequest* request);
////    ctx.deferred.Set(request);
  Set_in_DeferredRequest(&(((OContext*)ctx)->deferred), request);
////    return *this;
  return &(parent->oOutstationState);
}

////OutstationState& StateUnsolicitedConfirmWait::OnNewNonReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnNewNonReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateUnsolicitedConfirmWait *parent =
    (StateUnsolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
//  void Reset_in_DeferredRequest(DeferredRequest *pDeferredRequest);
////    ctx.deferred.Reset();
  Reset_in_DeferredRequest(&(((OContext*)ctx)->deferred));
//    OutstationState* RespondToNonReadRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////    ctx.RespondToNonReadRequest(request);
  RespondToNonReadRequest_in_OContext((OContext *)ctx, request);
////    return *this;
  return &(parent->oOutstationState);
}

////OutstationState& StateUnsolicitedConfirmWait::OnRepeatNonReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnRepeatNonReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateUnsolicitedConfirmWait *parent =
    (StateUnsolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
////    ctx.BeginRetransmitLastResponse(request.addresses.source);
  BeginRetransmitLastResponse_in_OContext((OContext *)ctx, (request->addresses).source);
////    return *this;
  return &(parent->oOutstationState);
}

////OutstationState& StateUnsolicitedConfirmWait::OnRepeatReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnRepeatReadRequest_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  StateUnsolicitedConfirmWait *parent =
    (StateUnsolicitedConfirmWait*)getParentPointer_in_OutstationState((OutstationState*)pOutstationState);
//  void Set_in_DeferredRequest(DeferredRequest *pDeferredRequest, ParsedRequest* request);
////    ctx.deferred.Set(request);
  Set_in_DeferredRequest(&(((OContext *)ctx)->deferred), request);
////    return *this;
  return &(parent->oOutstationState);
}

////OutstationState& StateUnsolicitedConfirmWait::OnBroadcastMessage(OContext& ctx, const ParsedRequest& request)
void* OnBroadcastMessage_in_StateUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  UNUSED(pOutstationState);
////    ctx.ProcessBroadcastRequest(request);
  ProcessBroadcastRequest_in_OContext((OContext *)ctx, request);
////    return StateIdle::Inst();
  return Inst_in_StateIdle_static();
}

// ------------- StateNullUnsolicitedConfirmWait ----------------

////StateNullUnsolicitedConfirmWait StateNullUnsolicitedConfirmWait::instance;
static StateNullUnsolicitedConfirmWait instance_in_StateNullUnsolicitedConfirmWait;

void StateNullUnsolicitedConfirmWait_in_StateNullUnsolicitedConfirmWait(StateNullUnsolicitedConfirmWait *pStateNullUnsolicitedConfirmWait)
{
  qDebug()<<"StateNullUnsolicitedConfirmWait_in_StateNullUnsolicitedConfirmWait1";

  OutstationState_in_OutstationState(&(pStateNullUnsolicitedConfirmWait->sStateUnsolicitedConfirmWait.oOutstationState));

  (pStateNullUnsolicitedConfirmWait->sStateUnsolicitedConfirmWait.oOutstationState).pName_in_OutstationState = Name_in_StateNullUnsolicitedConfirmWait_override;

//  /*
  (pStateNullUnsolicitedConfirmWait->sStateUnsolicitedConfirmWait.oOutstationState).pOnNewReadRequest_in_OutstationState = OnNewReadRequest_in_StateNullUnsolicitedConfirmWait_override;
//  */

  setParentPointer_in_OutstationState(&(pStateNullUnsolicitedConfirmWait->sStateUnsolicitedConfirmWait.oOutstationState), pStateNullUnsolicitedConfirmWait);
}

///*
////OutstationState& StateNullUnsolicitedConfirmWait::OnNewReadRequest(OContext& ctx, const ParsedRequest& request)
void* OnNewReadRequest_in_StateNullUnsolicitedConfirmWait_override(void* pOutstationState, void *ctx, ParsedRequest* request)
{
  UNUSED(pOutstationState);
////    ctx.confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(((OContext*)ctx)->confirmTimer));
////    return ctx.RespondToReadRequest(request);
  return RespondToReadRequest_in_OContext((OContext *)ctx, request);
}
//*/

////} // namespace opendnp3

boolean IsIdle_in_StateIdle_override(void* pOutstationState)
{
  UNUSED(pOutstationState);
  return true;
}

char* Name_in_StateIdle_override(void* pOutstationState)
{
  UNUSED(pOutstationState);
  return (char*)"Idle";
}

OutstationState* Inst_in_StateIdle_static(void)
{
  StateIdle_in_StateIdle(&instance_in_StateIdle);
  return &(instance_in_StateIdle.oOutstationState);
}

char* Name_in_StateSolicitedConfirmWait_override(void* pOutstationState)
{
  UNUSED(pOutstationState);
  return (char*)"SolicitedConfirmWait";
}

OutstationState* Inst_in_StateSolicitedConfirmWait_static(void)
{
  return &(instance_in_StateSolicitedConfirmWait.oOutstationState);
}

char* Name_in_StateUnsolicitedConfirmWait_override(void* pOutstationState)
{
  UNUSED(pOutstationState);
  return (char*)"UnsolicitedConfirmWait";
}

OutstationState* Inst_in_StateUnsolicitedConfirmWait_static(void)
{
  return &(instance_in_StateUnsolicitedConfirmWait.oOutstationState);
}

char* Name_in_StateNullUnsolicitedConfirmWait_override(void* pOutstationState)
{
  UNUSED(pOutstationState);
  return (char*)"NullUnsolicitedConfirmWait";
}

OutstationState* Inst_in_StateNullUnsolicitedConfirmWait_static(void)
{
  return &(instance_in_StateNullUnsolicitedConfirmWait.sStateUnsolicitedConfirmWait.oOutstationState);
}
