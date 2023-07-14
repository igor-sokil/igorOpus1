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
#ifndef OPENDNP3_OUTSTATIONCONTEXT_H
#define OPENDNP3_OUTSTATIONCONTEXT_H

////#include "LayerInterfaces.h"
////#include "link/LinkLayerConstants.h"
////#include "outstation/ControlState.h"
////#include "outstation/Database.h"
////#include "outstation/DeferredRequest.h"
////#include "outstation/OutstationChannelStates.h"
///#include "outstation/OutstationSeqNum.h"
////#include "outstation/OutstationStates.h"
////#include "outstation/ParsedRequest.h"
////#include "outstation/RequestHistory.h"
////#include "outstation/ResponseContext.h"
////#include "outstation/TimeSyncState.h"
////#include "outstation/event/EventBuffer.h"

////#include "opendnp3/link/Addresses.h"
////#include "opendnp3/logging/Logger.h"
////#include "opendnp3/outstation/ICommandHandler.h"
////#include "opendnp3/outstation/IOutstationApplication.h"
////#include "opendnp3/outstation/OutstationConfig.h"

////#include <ser4cpp/container/Pair.h>
////#include <ser4cpp/container/Settable.h>

////#include <exe4cpp/IExecutor.h>

#include "LayerInterfaces.h"
#include "LinkLayerConstants.h"
#include "ControlState.h"

#include "Database.h"
#include "ControlState.h"
#include "DeferredRequest.h"
#include "OutstationChannelStates.h"
#include "OutstationConfig.h"
#include "OutstationSeqNum.h"
#include "OutstationStates.h"
#include "ParsedRequest.h"

#include "RequestHistory.h"
#include "ResponseContext.h"
#include "TimeSyncState.h"
#include "EventBuffer.h"

#include "Addresses.h"
#include "ICommandHandler.h"
#include "IOutstationApplication.h"

#include "TimerExe4cpp.h"
#include "IExecutorExe4cpp.h"
#include "Settable_for_LinkBroadcastAddress.h"
#include "Pair_for_IINField_AppControlField.h"

////namespace opendnp3
////{

///
/// Represent all of the mutable state in an outstation
///
////class OContext : public IUpperLayer
typedef struct
{
  IUpperLayer iIUpperLayer;
////    friend class StateIdle;
////    friend class StateSolicitedConfirmWait;
////    friend class StateUnsolicitedConfirmWait;
////    friend class StateNullUnsolicitedConfirmWait;

////public:
////    OContext(const Addresses& addresses,
////             const OutstationConfig& config,
////             const DatabaseConfig& db_config,
////             const Logger& logger,
////             const std::shared_ptr<exe4cpp::IExecutor>& executor,
////             std::shared_ptr<ILowerLayer> lower,
////             std::shared_ptr<ICommandHandler> commandHandler,
////             std::shared_ptr<IOutstationApplication> application);

    /// ----- Implement IUpperLayer ------

////    virtual bool OnLowerLayerUp() override;
////
////    virtual bool OnLowerLayerDown() override;
////
////    virtual bool OnTxReady() override final;
////
////    virtual bool OnReceive(const Message& message) override final;
////
    /// --- Other public members ----

////    void HandleNewEvents();
////
////    IUpdateHandler& GetUpdateHandler();
////
////    void SetRestartIIN();
////
////private:
////    /// ---- Helper functions that operate on the current state, and may return a new state ----

////    OutstationState& ContinueMultiFragResponse(const Addresses& addresses, const AppSeqNum& seq);
////
////    OutstationState& RespondToReadRequest(const ParsedRequest& request);
////
////    OutstationState& ProcessNewRequest(const ParsedRequest& request);
////
////    OutstationState& OnReceiveSolRequest(const ParsedRequest& request);
////
////    OutstationState& RespondToNonReadRequest(const ParsedRequest& request);

    // ---- Processing functions --------

////    bool ProcessMessage(const Message& message);
////
////    bool ProcessObjects(const ParsedRequest& request);
////
////    bool ProcessRequest(const ParsedRequest& request);
////
////    bool ProcessBroadcastRequest(const ParsedRequest& request);
////
////    bool ProcessRequestNoAck(const ParsedRequest& request);

////    bool ProcessConfirm(const ParsedRequest& request);

    // ---- common helper methods ----

////    OutstationState& BeginResponseTx(uint16_t destination, APDUResponse& response);
////
////    void BeginRetransmitLastResponse(uint16_t destination);
////
////    void BeginRetransmitLastUnsolicitedResponse();
////
////    void BeginUnsolTx(APDUResponse& response);
////
////    void BeginTx(uint16_t destination, const ser4cpp::rseq_t& message);
////
////    void CheckForTaskStart();
////
////    void CheckForDeferredRequest();
////
////    void CheckForUnsolicitedNull();
////
////    void CheckForUnsolicited();
////
////    bool ProcessDeferredRequest(const ParsedRequest& request);
////
////    void RestartSolConfirmTimer();
////
////    void RestartUnsolConfirmTimer();
////
////    bool CanTransmit() const;
////
////    IINField GetResponseIIN();
////
////    IINField GetDynamicIIN();
////
////    void UpdateLastBroadcastMessageReceived(uint16_t destination);
////
////    void CheckForBroadcastConfirmation(APDUResponse& response);

    /// --- methods for handling app-layer functions ---

    /// Handles non-read function codes that require a response. builds the response using the supplied writer.
    /// @return An IIN field indicating the validity of the request, and to be returned in the response.
////    IINField HandleNonReadResponse(const APDUHeader& header, const ser4cpp::rseq_t& objects, HeaderWriter& writer);

    /// Handles read function codes. May trigger an unsolicited response
    /// @return an IIN field and a partial AppControlField (missing sequence info)
////    ser4cpp::Pair<IINField, AppControlField> HandleRead(const ser4cpp::rseq_t& objects, HeaderWriter& writer);

    // ------ Function Handlers ------

////    IINField HandleWrite(const ser4cpp::rseq_t& objects);
////    IINField HandleSelect(const ser4cpp::rseq_t& objects, HeaderWriter& writer);
////    IINField HandleOperate(const ser4cpp::rseq_t& objects, HeaderWriter& writer);
////    IINField HandleDirectOperate(const ser4cpp::rseq_t& objects, OperateType opType, HeaderWriter* pWriter);
////    IINField HandleDelayMeasure(const ser4cpp::rseq_t& objects, HeaderWriter& writer);
////    IINField HandleRecordCurrentTime();
////    IINField HandleRestart(const ser4cpp::rseq_t& objects, bool isWarmRestart, HeaderWriter* pWriter);
////    IINField HandleAssignClass(const ser4cpp::rseq_t& objects);
////    IINField HandleDisableUnsolicited(const ser4cpp::rseq_t& objects, HeaderWriter* writer);
////    IINField HandleEnableUnsolicited(const ser4cpp::rseq_t& objects, HeaderWriter* writer);
////    IINField HandleCommandWithConstant(const ser4cpp::rseq_t& objects, HeaderWriter& writer, CommandStatus status);
////    IINField HandleFreeze(const ser4cpp::rseq_t& objects);
////    IINField HandleFreezeAndClear(const ser4cpp::rseq_t& objects);

    // ------ resources --------
   Addresses addresses;
////    Logger logger;
////    const std::shared_ptr<exe4cpp::IExecutor> executor;
   IExecutorExe4cpp* executor;
////    const std::shared_ptr<ILowerLayer> lower;
   ILowerLayer* lower;
////    const std::shared_ptr<ICommandHandler> commandHandler;
   ICommandHandler* commandHandler;
////    const std::shared_ptr<IOutstationApplication> application;
   IOutstationApplication* application;
                   
    // ------ Database, event buffer, and response tracking
    EventBuffer eventBuffer;
    Database database;
    ResponseContext rspContext;//constructor default
////
    // ------ Static configuration -------
    OutstationParams params;

    // ------ Shared dynamic state --------
    boolean isOnline;
    boolean isTransmitting;
    IINField staticIIN;
////    exe4cpp::Timer confirmTimer;
    TimerExe4cpp confirmTimer;

    RequestHistory history;
    DeferredRequest deferred;//constructor default

    // ------ Dynamic state related to controls ------
    ControlState control;

    // ------ Dynamic state related to time synchronization ------
    TimeSyncState timeTimeSyncState;

    // ------ Dynamic state related to solicited and unsolicited modes ------
    OutstationSolState sol;
    OutstationUnsolState unsol;
    NumRetries unsolRetries;//constructor default
    boolean shouldCheckForUnsolicited;
////    OutstationState* state = &StateIdle::Inst();
    OutstationState* state;//// = &StateIdle::Inst();

    // ------ Dynamic state related to broadcast messages ------
////    ser4cpp::Settable<LinkBroadcastAddress> lastBroadcastMessageReceived;
    Settable_for_LinkBroadcastAddress lastBroadcastMessageReceived;
} OContext;

   void OContext_in_OContext(OContext *pOContext,
             Addresses* addresses,
             OutstationConfig* config,
             DatabaseConfig* db_config,
//             const Logger& logger,
             IExecutorExe4cpp* executor,
             ILowerLayer* lower,
             ICommandHandler* commandHandler,
             IOutstationApplication* application);

     boolean OnLowerLayerUp_in_OContext_override(void*);
     boolean OnLowerLayerDown_in_OContext_override(void*);
     boolean OnTxReady_in_OContext_override(void*);
     boolean OnReceive_in_OContext_override(void*, Message* message);

    OutstationState* ContinueMultiFragResponse_in_OContext(OContext *pOContext, Addresses* addresses, AppSeqNum* seq);
    OutstationState* RespondToReadRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
    OutstationState* RespondToNonReadRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
    boolean ProcessBroadcastRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
    boolean ProcessMessage_in_OContext(OContext *pOContext, Message* message);
    OutstationState* ProcessNewRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
    boolean ProcessObjects_in_OContext(OContext *pOContext, ParsedRequest* request);
    boolean ProcessRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
    boolean ProcessRequestNoAck_in_OContext(OContext *pOContext, ParsedRequest* request);
    boolean ProcessConfirm_in_OContext(OContext *pOContext, ParsedRequest* request);

    void BeginRetransmitLastResponse_in_OContext(OContext *pOContext, uint16_t destination);
    void BeginRetransmitLastUnsolicitedResponse_in_OContext(OContext *pOContext);
    void RestartSolConfirmTimer_in_OContext(OContext *pOContext);
    void RestartUnsolConfirmTimer_in_OContext(OContext *pOContext);

    void CheckForTaskStart_in_OContext(OContext *pOContext);
    IINField HandleNonReadResponse_in_OContext(OContext *pOContext, APDUHeader* header, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
    IINField GetResponseIIN_in_OContext(OContext *pOContext);
    IINField GetDynamicIIN_in_OContext(OContext *pOContext);

   void BeginTx_in_OContext(OContext *pOContext, uint16_t destination, RSeq_for_Uint16_t* message);
   OutstationState* BeginResponseTx_in_OContext(OContext *pOContext, uint16_t destination, APDUResponse* response);
   PairSer4cpp_for_IINField_AppControlField HandleRead_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter writer);
   OutstationState* OnReceiveSolRequest_in_OContext(OContext *pOContext, ParsedRequest* request);

   IINField HandleWrite_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
   IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter);
   IINField HandleFreeze_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
   IINField HandleFreezeAndClear_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
   IINField HandleAssignClass_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
   IINField HandleRecordCurrentTime_in_OContext(OContext *pOContext);
   IINField HandleDisableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
   IINField HandleEnableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
   IINField HandleSelect_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
   IINField HandleOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
   IINField HandleRestart_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, boolean isWarmRestart, HeaderWriter* pWriter);
   IINField HandleDelayMeasure_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
   IINField HandleCommandWithConstant_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer, CommandStatus_uint8_t status);

   void CheckForBroadcastConfirmation_in_OContext(OContext *pOContext, APDUResponse* response);
   void BeginUnsolTx_in_OContext(OContext *pOContext, APDUResponse* response);
   void CheckForDeferredRequest_in_OContext(OContext *pOContext);
   void CheckForUnsolicitedNull_in_OContext(OContext *pOContext);
   void CheckForUnsolicited_in_OContext(OContext *pOContext);
   boolean CanTransmit_in_OContext(OContext *pOContext);
   boolean ProcessDeferredRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////} // namespace opendnp3

#endif
