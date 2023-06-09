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
#include "header.h"
#include "OutstationContext.h"

////#include "app/APDUBuilders.h"
////#include "app/APDULogging.h"
////#include "app/Functions.h"
////#include "app/parsing/APDUHeaderParser.h"
////#include "app/parsing/APDUParser.h"
////#include "logging/LogMacros.h"
////#include "outstation/AssignClassHandler.h"
////#include "outstation/ClassBasedRequestHandler.h"
////#include "outstation/CommandActionAdapter.h"
////#include "outstation/CommandResponseHandler.h"
////#include "outstation/ConstantCommandAction.h"
////#include "outstation/FreezeRequestHandler.h"
////#include "outstation/IINHelpers.h"
////#include "outstation/ReadHandler.h"
////#include "outstation/WriteHandler.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <utility>
MYTODO
////#include "app/APDUBuilders.h"
////#include "app/APDULogging.h"
////#include "app/Functions.h"
////#include "app/parsing/APDUHeaderParser.h"
////#include "app/parsing/APDUParser.h"
////#include "logging/LogMacros.h"
////#include "outstation/AssignClassHandler.h"
////#include "outstation/ClassBasedRequestHandler.h"
////#include "outstation/CommandActionAdapter.h"
////#include "outstation/CommandResponseHandler.h"
////#include "outstation/ConstantCommandAction.h"
////#include "outstation/FreezeRequestHandler.h"
////#include "outstation/IINHelpers.h"
////#include "outstation/ReadHandler.h"
////#include "outstation/WriteHandler.h"

#include "APDUBuilders.h"
//#include "app/APDULogging.h"
#include "Functions.h"
#include "APDUHeaderParser.h"
#include "APDUParser.h"
//#include "logging/LogMacros.h"
#include "AssignClassHandler.h"
#include "ClassBasedRequestHandler.h"
#include "CommandActionAdapter.h"
#include "CommandResponseHandler.h"
#include "ConstantCommandAction.h"
#include "FreezeRequestHandler.h"
#include "IINHelpers.h"
#include "ReadHandler.h"
#include "WriteHandler.h"

static OContext *pOContextGlobal;

////namespace opendnp3
////{

////OContext::OContext(const Addresses& addresses,
////                   const OutstationConfig& config,
////                   const DatabaseConfig& db_config,
////                   const Logger& logger,
////                   const std::shared_ptr<exe4cpp::IExecutor>& executor,
////                   std::shared_ptr<ILowerLayer> lower,
///                   std::shared_ptr<ICommandHandler> commandHandler,
///                   std::shared_ptr<IOutstationApplication> application)
void OContext_in_OContext(OContext *pOContext,
                    Addresses* addresses,
                    OutstationConfig* config,
                    DatabaseConfig* db_config,
////                   const Logger& logger,
                   IExecutorExe4cpp* executor,
                   ILowerLayer* lower,
                   ICommandHandler* commandHandler,
                   IOutstationApplication* application)
{
      pOContext->addresses = *addresses;
////      logger(logger),
      pOContext->executor = executor;
      pOContext->lower = lower;
      pOContext->commandHandler = commandHandler;
      pOContext->application = application;
////      pOContext->eventBuffer(config->eventBufferConfig),
  EventBuffer_in_EventBufferOver2(&(pOContext->eventBuffer), &(config->eventBufferConfig));

//  void  Database_in_Database(Database *pDatabase,
//             DatabaseConfig* config,
//             IEventReceiver* event_receiver,
//             IDnpTimeSource* time_source,
//             StaticTypeBitField allowed_class_zero_types);
////      pOContext->database(db_config, eventBuffer, *this->application, config.params.typesAllowedInClass0),
   Database_in_Database(&(pOContext->database),
             db_config,
             &(pOContext->eventBuffer.iIEventReceiver),
             &(pOContext->application.IDnpTimeSource),
             config->params.typesAllowedInClass0);

// void ResponseContext_in_ResponseContext(ResponseContext *pResponseContext, IResponseLoader* staticLoader, IResponseLoader* eventLoader);
////      pOContext->rspContext(database, eventBuffer),
  ResponseContext_in_ResponseContext(&(pOContext->rspContext), &(pOContext->database.iIResponseLoader), &(pOContext->eventBuffer.iIResponseLoader));

////      pOContext->params(config.params),
      pOContext->params = config->params;

      pOContext->isOnline = false;
      pOContext->isTransmitting = false;
      pOContext->staticIIN = IINBit_DEVICE_RESTART;

//  void DeferredRequest_in_DeferredRequest(DeferredRequest *pDeferredRequest, uint32_t maxAPDUSize);
///      pOContext->deferred(config->params.maxRxFragSize),
   DeferredRequest_in_DeferredRequest(&(pOContext->deferred), config->params.maxRxFragSize);

//  void  OutstationSolState_in_OutstationSolState(OutstationSolState *pOutstationSolState, uint32_t maxTxSize);
////      pOContext->sol(config->params.maxTxFragSize),
    OutstationSolState_in_OutstationSolState(&(pOContext->sol), config->params.maxTxFragSize);

   void OutstationUnsolState_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState, uint32_t maxTxSize);
////      pOContext->unsol(config->params.maxTxFragSize),
    OutstationUnsolState_in_OutstationUnsolState(&(pOContext->unsol), config->params.maxTxFragSize);

//   void NumRetries_in_NumRetries(NumRetries *pNumRetries, uint16_t maxNumRetries, boolean isInfinite);
////      pOContext->unsolRetries(config->params.numUnsolRetries),
      pOContext->unsolRetries = config->params.numUnsolRetries;

      pOContext->shouldCheckForUnsolicited = false;

  pOContextGlobal = pOContext;
//     OutstationState* Inst_in_StateIdle_static(void);
  pOContext->state = Inst_in_StateIdle_static();//// = &StateIdle::Inst();

  EventBuffer_in_EventBufferOver1(&(pOContext->eventBuffer));
  OutstationParams_in_OutstationParams(&(pOContext->params));
  IINField_in_IINFieldOver1(&(pOContext->staticIIN));
  RequestHistory_in_RequestHistory(&(pOContext->history));
  ControlState_in_ControlStateOver1(&(pOContext->control));
  TimeSyncState_in_TimeSyncState(&(pOContext->timeTimeSyncState));
  OutstationSolState_in_OutstationSolState(&(pOContext->sol),       config->params.maxTxFragSize);
  OutstationUnsolState_in_OutstationUnsolState(&(pOContext->unsol), config->params.maxTxFragSize)

  setParentPointer_in_IUpDown(&(pOContext->iIUpperLayer.iIUpDown), pOContext);
  setParentPointer_in_IUpperLayer(&(pOContext->iIUpperLayer), pOContext);

 pOContext->iIUpperLayer.iIUpDown.pOnLowerLayerUp_in_IUpDown = OnLowerLayerUp_in_OContext_override;
 pOContext->iIUpperLayer.iIUpDown.pOnLowerLayerDown_in_IUpDown = OnLowerLayerDown_in_OContext_override;
 pOContext->iIUpperLayer.pOnReceive_in_IUpperLayer = OnReceive_in_OContext_override;
 pOContext->iIUpperLayer.pOnTxReady_in_IUpperLayer = OnTxReady_in_OContext_override;

}

////bool OContext::OnLowerLayerUp()
     boolean OnLowerLayerUp_in_OContext_override(void* pIUpDown)
{
  OContext *parent = 
         (OContext*)getParentPointer_in_IUpDown((IUpDown*)pIUpDown);
    if (parent->isOnline)
    {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "already online");
        return false;
    }

    parent->isOnline = true;
    parent->shouldCheckForUnsolicited = true;
//    void CheckForTaskStart_in_OContext(OContext *pOContext);
////    this->CheckForTaskStart();
    CheckForTaskStart_in_OContext(parent);
    return true;
}

////bool OContext::OnLowerLayerDown()
     boolean OnLowerLayerDown_in_OContext_override(void* pIUpDown)
{
  OContext *parent = 
         (OContext*)getParentPointer_in_IUpDown((IUpDown*)pIUpDown);

    if (!(parent->->isOnline))
    {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "already offline");
        return false;
    }

////    this->state = &StateIdle::Inst();
  pOContext->state = Inst_in_StateIdle_static();//// = &StateIdle::Inst();

    parent->isOnline = false;
    parent->isTransmitting = false;

//    void Reset_in_OutstationSolState(OutstationSolState *pOutstationSolState);
////    sol.Reset();
    Reset_in_OutstationSolState(&(parent->sol));
////    unsol.Reset();
    Reset_in_OutstationUnsolState(&(parent->unsol));
////    history.Reset();
    Reset_in_RequestHistory(&(parent->history));
////    deferred.Reset();
    Reset_in_DeferredRequest(&(parent->deferred));
////    eventBuffer.Unselect();
    Unselect_in_EventBuffer(&(parent->eventBuffer));
////    rspContext.Reset();
    Reset_in_ResponseContext(&(parent->rspContext));
////    confirmTimer.cancel();
    cancel_in_TimerExe4cpp(&(parent->confirmTimer));

    return true;
}

////bool OContext::OnTxReady()
     boolean OnTxReady_in_OContext_override(void* pIUpperLayer)
{
  OContext *parent = 
         (OContext*)getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);

    if (!(parent->isOnline) || !(parent->isTransmitting))
    {
        return false;
    }

    parent->isTransmitting = false;
////    this->CheckForTaskStart();
    CheckForTaskStart_in_OContext(parent);
    return true;
}

////bool OContext::OnReceive(const Message& message)
     boolean OnReceive_in_OContext_override(void* pIUpperLayer, Message* message)
{
  OContext *parent = 
         (OContext*)getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);

    if (!(parent->isOnline))
    {
////        SIMPLE_LOG_BLOCK(this->logger, flags::ERR, "ignoring received data while offline");
        return false;
    }

//    boolean ProcessMessage_in_OContext(OContext *pOContext, Message* message);
////    this->ProcessMessage(message);
    ProcessMessage_in_OContext(parent, message);

////    this->CheckForTaskStart();
    CheckForTaskStart_in_OContext(parent);

    return true;
}

////OutstationState& OContext::OnReceiveSolRequest(const ParsedRequest& request)
   OutstationState* OnReceiveSolRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
    // analyze this request to see how it compares to the last request
//    boolean HasLastRequest_in_RequestHistory(RequestHistory *pRequestHistory);
////    if (this->history.HasLastRequest())
    if (HasLastRequest_in_RequestHistory(&(pOContext->history)))
    {
//&(pOContext->sol.seq.num)
//boolean Equals_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t other);
////        if (this->sol.seq.num.Equals(request.header.control.SEQ))
        if (Equals_in_SequenceNum_for_uint8_Modulus16(&(pOContext->sol.seq.num), pOContext->request.header.control.SEQ))
        {
//   boolean FullyEqualsLastRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects);
////            if (this->history.FullyEqualsLastRequest(request.header, request.objects))
            if (FullyEqualsLastRequest_in_RequestHistory(&(pOContext->history), &(pOContext->request.header), &(pOContext->request.objects)))
            {
////                if (request.header.function == FunctionCode::READ)
                if (pOContext->request.header.function == FunctionCode_READ)
                {
//    OutstationState* OnRepeatReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////                    return this->state->OnRepeatReadRequest(*this, request);
    return OnRepeatReadRequest_in_OutstationState(&(pOContext->state), pOContext, request);
                }

//    OutstationState* OnRepeatNonReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////                return this->state->OnRepeatNonReadRequest(*this, request);
    return OnRepeatNonReadRequest_in_OutstationState(&(pOContext->state), pOContext, request);
            }
            else // new operation with same SEQ
            {
//    OutstationState* ProcessNewRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////                return this->ProcessNewRequest(request);
    return ProcessNewRequest_in_OContext(pOContext, request);
            }
        }
        else // completely new sequence #
        {
////            return this->ProcessNewRequest(request);
    return ProcessNewRequest_in_OContext(pOContext, request);
        }
    }
    else
    {
////        return this->ProcessNewRequest(request);
    return ProcessNewRequest_in_OContext(pOContext, request);
    }
}

////OutstationState& OContext::ProcessNewRequest(const ParsedRequest& request)
    OutstationState* ProcessNewRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
    pOContext->sol.seq.num = request->header.control.SEQ;

    if (request->header.function == FunctionCode_READ)
    {
//    OutstationState* OnNewReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////        return this->state->OnNewReadRequest(*this, request);
    return OnNewReadRequest_in_OutstationState(&(pOContext->state), pOContext, request);
    }

//    OutstationState* OnNewNonReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////    return this->state->OnNewNonReadRequest(*this, request);
    return OnNewNonReadRequest_in_OutstationState(&(pOContext->state), pOContext, request);
}

////bool OContext::ProcessObjects(const ParsedRequest& request)
    boolean ProcessObjects_in_OContext(OContext *pOContext, ParsedRequest* request)
{
//    boolean IsBroadcast_in_Addresses(Addresses *pAddresses);
////    if (request.addresses.IsBroadcast())
       if (IsBroadcast_in_Addresses(&(request->addresses)))
    {
//    OutstationState* OnBroadcastMessage_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////        this->state = &this->state->OnBroadcastMessage(*this, request);
    pOContext->state = OnBroadcastMessage_in_OutstationState(&(pOContext->state), pOContext, request);
        return true;
    }

//    boolean IsNoAckFuncCode_in_Functions_static(FunctionCode_uint8_t code);
////    if (Functions::IsNoAckFuncCode(request.header.function))
        if (IsNoAckFuncCode_in_Functions_static(request->header.function))
    {
        // this is the only request we process while we are transmitting
        // because it doesn't require a response of any kind
//    boolean ProcessRequestNoAck_in_OContext(OContext *pOContext, ParsedRequest* request);
////        return this->ProcessRequestNoAck(request);
    return ProcessRequestNoAck_in_OContext(pOContext, request);
    }

    if (pOContext->isTransmitting)
    {
//  void Set_in_DeferredRequest(DeferredRequest *pDeferredRequest, ParsedRequest* request);
////        this->deferred.Set(request);
   Set_in_DeferredRequest(&(pOContext->deferred), request);
        return true;
    }

    if (request->header.function == FunctionCode_CONFIRM)
    {
//    boolean ProcessConfirm_in_OContext(OContext *pOContext, ParsedRequest* request);
////        return this->ProcessConfirm(request);
    return ProcessConfirm_in_OContext(pOContext, request);
    }

//    boolean ProcessRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////    return this->ProcessRequest(request);
    return ProcessRequest_in_OContext(pOContext, request);
}

////bool OContext::ProcessRequest(const ParsedRequest& request)
    boolean ProcessRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
    if (request->header.control.UNS)
    {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Ignoring unsol with invalid function code: %s",
////                         FunctionCodeSpec::to_human_string(request.header.function));
        return false;
    }

//   OutstationState* OnReceiveSolRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////    this->state = &this->OnReceiveSolRequest(request);
   pOContext->state = OnReceiveSolRequest_in_OContext(pOContext, request);
    return true;
}

////bool OContext::ProcessConfirm(const ParsedRequest& request)
    boolean ProcessConfirm_in_OContext(OContext *pOContext, ParsedRequest* request)
{
//    OutstationState* OnConfirm_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////    this->state = &this->state->OnConfirm(*this, request);
  pOContext->state = OnConfirm_in_OutstationState(&(pOContext->state), pOContext, request);
    return true;
}

////OutstationState& OContext::BeginResponseTx(uint16_t destination, APDUResponse& response)
   OutstationState* BeginResponseTx_in_OContext(OContext *pOContext, uint16_t destination, APDUResponse* response)
{
//   void CheckForBroadcastConfirmation(OContext *pOContext, APDUResponse* response);
////    CheckForBroadcastConfirmation(response);
    CheckForBroadcastConfirmation_in_OContext(pOContext, response);

//  RSeq_for_Uint16_t ToRSeq_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    const auto data = response.ToRSeq();
  RSeq_for_Uint16_t data = ToRSeq_in_APDUWrapper(&(response->aAPDUWrapper));

//void Record_in_TxBuffer(TxBuffer *pTxBuffer, AppControlField* control, RSeq_for_Uint16_t* view);
//  AppControlField GetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    this->sol.tx.Record(response.GetControl(), data);
  AppControlField temp = GetControl_in_APDUWrapper(&(response->aAPDUWrapper));
 Record_in_TxBuffer(&(pOContext->sol.tx), &temp, &data);

////    this->sol.seq.confirmNum = response.GetControl().SEQ;
    pOContext->sol.seq.confirmNum = GetControl_in_APDUWrapper(&(response->aAPDUWrapper)).SEQ;////response.GetControl().SEQ;
//   void BeginTx_in_OContext(OContext *pOContext, uint16_t destination, RSeq_for_Uint16_t* message);
////    this->BeginTx(destination, data);
    BeginTx_in_OContext(pOContext, destination, &data);

////    if (response.GetControl().CON)
    if (GetControl_in_APDUWrapper(&(response->aAPDUWrapper)).CON)
    {
//    void RestartSolConfirmTimer_in_OContext(OContext *pOContext);
////        this->RestartSolConfirmTimer();
     RestartSolConfirmTimer_in_OContext(pOContext);
////        return StateSolicitedConfirmWait::Inst();
     return Inst_in_StateSolicitedConfirmWait_static();
    }

////    return StateIdle::Inst();
     return Inst_in_StateIdle_static();
}

////void OContext::BeginRetransmitLastResponse(uint16_t destination)
    void BeginRetransmitLastResponse_in_OContext(OContext *pOContext, uint16_t destination)
{
//   void BeginTx_in_OContext(OContext *pOContext, uint16_t destination, RSeq_for_Uint16_t* message);
//RSeq_for_Uint16_t* GetLastResponse_in_TxBuffer(TxBuffer *pTxBuffer);
////    this->BeginTx(destination, this->sol.tx.GetLastResponse());
    BeginTx_in_OContext(pOContext, destination, GetLastResponse_in_TxBuffer(&(pOContext->sol.tx)));
}

////void OContext::BeginRetransmitLastUnsolicitedResponse()
    void BeginRetransmitLastUnsolicitedResponse_in_OContext(OContext *pOContext)
{
//   void BeginTx_in_OContext(OContext *pOContext, uint16_t destination, RSeq_for_Uint16_t* message);
////    this->BeginTx(this->addresses.destination, this->unsol.tx.GetLastResponse());
    BeginTx_in_OContext(pOContext, pOContext->addresses.destination, GetLastResponse_in_TxBuffer(&(pOContext->unsol.tx)));
}

////void OContext::BeginUnsolTx(APDUResponse& response)
   void BeginUnsolTx_in_OContext(OContext *pOContext, APDUResponse* response)
{
////    CheckForBroadcastConfirmation(response);
    CheckForBroadcastConfirmation_in_OContext(pOContext, response);

////    const auto data = response.ToRSeq();
  RSeq_for_Uint16_t data = ToRSeq_in_APDUWrapper(&(response->aAPDUWrapper));

////    this->unsol.tx.Record(response.GetControl(), data);
  AppControlField temp = GetControl_in_APDUWrapper(&(response->aAPDUWrapper));
 Record_in_TxBuffer(&(pOContext->unsol.tx), &temp, &data);

////    this->unsol.seq.confirmNum = this->unsol.seq.num;
    pOContext->unsol.seq.confirmNum = pOContext->unsol.seq.num;

////    this->unsol.seq.num.Increment();
 Increment_in_SequenceNum_for_uint8_Modulus16(&(pOContext->unsol.seq.num));
//   void BeginTx_in_OContext(OContext *pOContext, uint16_t destination, RSeq_for_Uint16_t* message);
////    this->BeginTx(this->addresses.destination, data);
    BeginTx_in_OContext(pOContext, pOContext->addresses.destination, &data);
}

////void OContext::BeginTx(uint16_t destination, const ser4cpp::rseq_t& message)
   void BeginTx_in_OContext(OContext *pOContext, uint16_t destination, RSeq_for_Uint16_t* message)
{
////    logging::ParseAndLogResponseTx(this->logger, message);
    pOContext->isTransmitting = true;
//void BeginTransmit_in_ILowerLayer(ILowerLayer *, Message* message);
//  void Addresses_in_AddressesOver2(Addresses *pAddresses, uint16_t source, uint16_t destination);
//  void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
////    this->lower->BeginTransmit(Message(Addresses(this->addresses.source, destination), message));
 Addresses aAddresses;
 Addresses_in_AddressesOver2(&aAddresses, pOContext->addresses.source, destination);
 Message mMessage;
 Message_in_Message(&mMessage, &aAddresses, message);
 BeginTransmit_in_ILowerLayer(pOContext->lower, &mMessage);
}

void CheckForTaskStart_in_OContext(OContext *pOContext)
{
// do these checks in order of priority
//   void CheckForDeferredRequest_in_OContext(OContext *pOContext);
////    this->CheckForDeferredRequest();
    CheckForDeferredRequest_in_OContext(pOContext);
//   void CheckForUnsolicitedNull_in_OContext(OContext *pOContext);
////    this->CheckForUnsolicitedNull();
    CheckForUnsolicitedNull_in_OContext(pOContext);
    if (pOContext->shouldCheckForUnsolicited)
    {
//   void CheckForUnsolicited_in_OContext(OContext *pOContext);
////        this->CheckForUnsolicited();
    CheckForUnsolicited_in_OContext(pOContext);
    }
}

boolean HandlerBooleanParsedRequest_in_OContext(void*, ParsedRequest*);
boolean HandlerBooleanParsedRequest_in_OContext(void* pOContext, ParsedRequest* pParsedRequest)
{
//   boolean ProcessDeferredRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////        auto handler = [this](const ParsedRequest& request) { return this->ProcessDeferredRequest(request); };
  return ProcessDeferredRequest_in_OContext((OContext *)pOContext, pParsedRequest);
}

////void OContext::CheckForDeferredRequest()
   void CheckForDeferredRequest_in_OContext(OContext *pOContext)
{
//   boolean CanTransmit_in_OContext(OContext *pOContext);
//  boolean IsSet_in_DeferredRequest(DeferredRequest *pDeferredRequest);
////    if (this->CanTransmit() && this->deferred.IsSet())
    if (CanTransmit_in_OContext(pOContext) && IsSet_in_DeferredRequest(&(pOContext->deferred)))
    {
//   boolean ProcessDeferredRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////        auto handler = [this](const ParsedRequest& request) { return this->ProcessDeferredRequest(request); };
////        this->deferred.Process(handler);
        Process_for_handlerBooleanParsedRequest_in_DeferredRequest(&(pOContext->deferred), pOContext, HandlerBooleanParsedRequest_in_OContext);
    }
}

////void OContext::CheckForUnsolicitedNull()
////{
////    if (this->CanTransmit() && this->state->IsIdle() && this->params.allowUnsolicited)
////    {
////        if (!this->unsol.completedNull)
////        {
////            // send a NULL unsolcited message
////            auto response = this->unsol.tx.Start();
////            build::NullUnsolicited(response, this->unsol.seq.num, this->GetResponseIIN());
////            this->RestartUnsolConfirmTimer();
////            this->state = this->params.noDefferedReadDuringUnsolicitedNullResponse
////                ? &StateNullUnsolicitedConfirmWait::Inst()
////                : &StateUnsolicitedConfirmWait::Inst();
////            this->BeginUnsolTx(response);
////        }
////    }
////}
////
////void OContext::CheckForUnsolicited()
////{
////    if (this->shouldCheckForUnsolicited && this->CanTransmit() && this->state->IsIdle()
////        && this->params.allowUnsolicited)
////    {
////        this->shouldCheckForUnsolicited = false;

////        if (this->unsol.completedNull)
////        {
////            // are there events to be reported?
////            if (this->params.unsolClassMask.Intersects(this->eventBuffer.UnwrittenClassField()))
////            {
////
////                auto response = this->unsol.tx.Start();
////                auto writer = response.GetWriter();

////                this->unsolRetries.Reset();
////                this->eventBuffer.Unselect();
////                this->eventBuffer.SelectAllByClass(this->params.unsolClassMask);
////                this->eventBuffer.Load(writer);

////                build::NullUnsolicited(response, this->unsol.seq.num, this->GetResponseIIN());
////                this->RestartUnsolConfirmTimer();
////                this->state = &StateUnsolicitedConfirmWait::Inst();
////                this->BeginUnsolTx(response);
////            }
////        }
////    }
////}

////bool OContext::ProcessDeferredRequest(const ParsedRequest& request)
////{
////    if (request.header.function == FunctionCode::CONFIRM)
////    {
////        this->ProcessConfirm(request);
////        return true;
////    }
////
////    if (request.header.function == FunctionCode::READ)
////    {
////        if (this->state->IsIdle())
////        {
////            this->ProcessRequest(request);
////            return true;
////        }
////
////        return false;
////    }
////    else
////    {
////        this->ProcessRequest(request);
////        return true;
////    }
////}

////void OContext::RestartSolConfirmTimer()
////{
////    auto timeout = [&]() {
////        this->state = &this->state->OnConfirmTimeout(*this);
////        this->CheckForTaskStart();
////    };
////
////    this->confirmTimer.cancel();
////    this->confirmTimer = this->executor->start(this->params.solConfirmTimeout.value, timeout);
////}

void timeout_RestartUnsolConfirmTimer_in_OContext(void);

void timeout_RestartUnsolConfirmTimer_in_OContext(void)
{
//void* getParentPointer_in_OutstationState(OutstationState*);
//    OutstationState* OnConfirmTimeout_in_StateIdle_override(void* pOutstationState, void *pOContext);
////        this->state = &this->state->OnConfirmTimeout(*this);
OutstationState* parent = (OutstationState*)getParentPointer_in_OutstationState(pOContextGlobal->state);
 pOContextGlobal->state = OnConfirmTimeout_in_StateIdle_override((OutstationState*) parent, pOContextGlobal);
//    void CheckForTaskStart_in_OContext(OContext *pOContext);
////        this->CheckForTaskStart();
    CheckForTaskStart_in_OContext(pOContextGlobal);
}
////void OContext::RestartUnsolConfirmTimer()
    void RestartUnsolConfirmTimer_in_OContext(OContext *pOContext)
{
////    auto timeout = [&]() {
////        this->state = &this->state->OnConfirmTimeout(*this);
////        this->CheckForTaskStart();
////    };

////    this->confirmTimer.cancel();
    cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
//TimerExe4cpp Start_in_IExecutorExe4cpp(IExecutorExe4cpp *pIExecutorExe4cpp, uint32_t duration, void (*pAction)(void))
////    this->confirmTimer = this->executor->start(this->params.unsolConfirmTimeout.value, timeout);
pOContext->confirmTimer =  Start_in_IExecutorExe4cpp(pOContext->executor, pOContext->params.unsolConfirmTimeout.value, timeout_RestartUnsolConfirmTimer_in_OContext)
}

////OutstationState& OContext::RespondToNonReadRequest(const ParsedRequest& request)
    OutstationState* RespondToNonReadRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
//   void RecordLastProcessedRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects);
////    this->history.RecordLastProcessedRequest(request.header, request.objects);
    RecordLastProcessedRequest_in_RequestHistory(&(pOContext->history), &(request->header), &(request->objects));

//APDUResponse Start_in_TxBuffer(TxBuffer *pTxBuffer);
////    auto response = this->sol.tx.Start();
APDUResponse response = Start_in_TxBuffer(&(pOContext->sol.tx));

//  HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    auto writer = response.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));

//  void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
////    response.SetFunction(FunctionCode::RESPONSE);
   SetFunction_in_APDUWrapper(&(response.aAPDUWrapper), FunctionCode_RESPONSE);

//  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
////    response.SetControl(AppControlField(true, true, false, false, request.header.control.SEQ));
   AppControlField aAppControlField;
   AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, request->header.control.SEQ);
   SetControl_in_APDUWrapper(&(response.aAPDUWrapper), aAppControlField);

//    IINField HandleNonReadResponse_in_OContext(OContext *pOContext, APDUHeader* header, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////    auto iin = this->HandleNonReadResponse(request.header, request.objects, writer);
    IINField iin = HandleNonReadResponse_in_OContext(pOContext, &(request->header), &(request->objects), &writer);

//    void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications);
//    IINField GetResponseIIN_in_OContext(OContext *pOContext);
//    IINField operatorOR_in_IINField(IINField *pIINField, IINField* aIIN);
////    response.SetIIN(iin | this->GetResponseIIN());
   IINField temp = GetResponseIIN_in_OContext(pOContext);
   IINField temp2 = operatorOR_in_IINField(&iin, &temp);
     SetIIN_in_APDUResponse(&response, &temp2);

//   OutstationState* BeginResponseTx_in_OContext(OContext *pOContext, uint16_t destination, APDUResponse* response);
////    return this->BeginResponseTx(request.addresses.source, response);
   return BeginResponseTx_in_OContext(pOContext, request->addresses.source, &response);
}

////OutstationState& OContext::RespondToReadRequest(const ParsedRequest& request)
    OutstationState* RespondToReadRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
//   void RecordLastProcessedRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects);
////    this->history.RecordLastProcessedRequest(request.header, request.objects);
    RecordLastProcessedRequest_in_RequestHistory(&(pOContext->history), &(request->header), &(request->objects));

////    auto response = this->sol.tx.Start();
APDUResponse response = Start_in_TxBuffer(&(pOContext->sol.tx));

////    auto writer = response.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));
////    response.SetFunction(FunctionCode::RESPONSE);
   SetFunction_in_APDUWrapper(&(response.aAPDUWrapper), FunctionCode_RESPONSE);

//   PairSer4cpp_for_IINField_AppControlField HandleRead_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter writer)
////    auto result = this->HandleRead(request.objects, writer);
   PairSer4cpp_for_IINField_AppControlField result = HandleRead_in_OContext(pOContext, &(request->objects), &writer);

    result.second.SEQ = request->header.control.SEQ;
//  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
////    response.SetControl(result.second);
   SetControl_in_APDUWrapper(&(response->aAPDUWrapper), result.second);
////    response.SetIIN(result.first | this->GetResponseIIN());
   IINField temp = GetResponseIIN_in_OContext(pOContext);
   IINField temp2 = operatorOR_in_IINField(&(result.first), &temp);
     SetIIN_in_APDUResponse(&response, &temp2);

////    return this->BeginResponseTx(request.addresses.source, response);
   return BeginResponseTx_in_OContext(pOContext, request->addresses.source, &response);
}

////OutstationState& OContext::ContinueMultiFragResponse(const Addresses& addresses, const AppSeqNum& seq)
    OutstationState* ContinueMultiFragResponse_in_OContext(OContext *pOContext, Addresses* addresses, AppSeqNum* seq)
{
////    auto response = this->sol.tx.Start();
APDUResponse response = Start_in_TxBuffer(&(pOContext->sol.tx));
////    auto writer = response.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));
////    response.SetFunction(FunctionCode::RESPONSE);
   SetFunction_in_APDUWrapper(&(response.aAPDUWrapper), FunctionCode_RESPONSE);
// AppControlField LoadResponse_in_ResponseContext(ResponseContext *pResponseContext, HeaderWriter* writer);
////    auto control = this->rspContext.LoadResponse(writer);
 AppControlField control = LoadResponse_in_ResponseContext(&(pOContext->rspContext), &writer);

    control.SEQ = *seq;
////    response.SetControl(control);
   SetControl_in_APDUWrapper(&(response.aAPDUWrapper), control);

//    void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications);
//    IINField GetResponseIIN_in_OContext(OContext *pOContext);
////    response.SetIIN(this->GetResponseIIN());
   IINField temp = GetResponseIIN_in_OContext(pOContext);
     SetIIN_in_APDUResponse(&response, &temp);

////    return this->BeginResponseTx(addresses.source, response);
   return BeginResponseTx_in_OContext(pOContext, request->addresses.source, &response);
}

////bool OContext::CanTransmit() const
////{
////    return isOnline && !isTransmitting;
////}

////IINField OContext::GetResponseIIN()
    IINField GetResponseIIN_in_OContext(OContext *pOContext)
{
//    ApplicationIIN GetApplicationIIN_in_IOutstationApplication(IOutstationApplication*);
//    IINField GetDynamicIIN_in_OContext(OContext *pOContext);
// IINField ToIIN_in_ApplicationIIN(ApplicationIIN *pApplicationIIN);
////    return this->staticIIN | this->GetDynamicIIN() | this->application->GetApplicationIIN().ToIIN();
    IINField temp1 = GetDynamicIIN_in_OContext(pOContext);
   IINField temp2 = operatorOR_in_IINField(&(pOContext->staticIIN), &temp1);
    ApplicationIIN temp = GetApplicationIIN_in_IOutstationApplication(pOContext->application);
 IINField temp3 = ToIIN_in_ApplicationIIN(&temp);
   IINField temp4 = operatorOR_in_IINField(&temp2, &temp3);
  return temp4;
}

////IINField OContext::GetDynamicIIN()
    IINField GetDynamicIIN_in_OContext(OContext *pOContext)
{
//    ClassField UnwrittenClassField_in_EventBuffer(EventBuffer *pEventBuffer);
////    auto classField = this->eventBuffer.UnwrittenClassField();
    ClassField classField = UnwrittenClassField_in_EventBuffer(&(pOContext->eventBuffer));

    IINField ret;
    IINField_in_IINFieldOver1(&ret);

//    void SetBitToValue_in_IINField(IINField *, IINBit_uint8_t bit, boolean value);
//  boolean HasClass1_in_ClassField(ClassField *pClassField);
////    ret.SetBitToValue(IINBit::CLASS1_EVENTS, classField.HasClass1());
    SetBitToValue_in_IINField(&ret, IINBit_CLASS1_EVENTS, HasClass1_in_ClassField(&classField));

////    ret.SetBitToValue(IINBit::CLASS2_EVENTS, classField.HasClass2());
    SetBitToValue_in_IINField(&ret, IINBit_CLASS2_EVENTS, HasClass2_in_ClassField(&classField));

////    ret.SetBitToValue(IINBit::CLASS3_EVENTS, classField.HasClass3());
    SetBitToValue_in_IINField(&ret, IINBit_CLASS3_EVENTS, HasClass3_in_ClassField(&classField));

//    boolean IsOverflown_in_EventBuffer(EventBuffer *pEventBuffer);
////    ret.SetBitToValue(IINBit::EVENT_BUFFER_OVERFLOW, this->eventBuffer.IsOverflown());
    SetBitToValue_in_IINField(&ret, IINBit_EVENT_BUFFER_OVERFLOW, IsOverflown_in_EventBuffer(&(pOContext->eventBuffer)));

    return ret;
}

////void OContext::UpdateLastBroadcastMessageReceived(uint16_t destination)
////{
////    switch (destination)
////    {
////    case LinkBroadcastAddress::DontConfirm:
////        lastBroadcastMessageReceived.set(LinkBroadcastAddress::DontConfirm);
////        break;
////    case LinkBroadcastAddress::ShallConfirm:
////        lastBroadcastMessageReceived.set(LinkBroadcastAddress::ShallConfirm);
////        break;
////    case LinkBroadcastAddress::OptionalConfirm:
////        lastBroadcastMessageReceived.set(LinkBroadcastAddress::OptionalConfirm);
////        break;
////    default:
////        lastBroadcastMessageReceived.clear();
////    }
////}
////
////void OContext::CheckForBroadcastConfirmation(APDUResponse& response)
////{
////    if (lastBroadcastMessageReceived.is_set())
////    {
////        response.SetIIN(response.GetIIN() | IINField(IINBit::BROADCAST));
////
////        if (lastBroadcastMessageReceived.get() != LinkBroadcastAddress::ShallConfirm)
////        {
////            lastBroadcastMessageReceived.clear();
////        }
////        else
////        {
////            // The broadcast address requested a confirmation
////            auto control = response.GetControl();
////            control.CON = true;
////            response.SetControl(control);
////        }
////    }
////}
////
////bool OContext::ProcessMessage(const Message& message)
////{
    // is the message addressed to this outstation
////    if (message.addresses.destination != this->addresses.source && !message.addresses.IsBroadcast())
////    {
////        return false;
////    }

    // is the message coming from the expected master?
////    if (!this->params.respondToAnyMaster && (message.addresses.source != this->addresses.destination))
////    {
////        return false;
////    }

////    FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18);
////
////    if (message.addresses.IsBroadcast())
////    {
////        UpdateLastBroadcastMessageReceived(message.addresses.destination);
////    }
////
////    const auto result = APDUHeaderParser::ParseRequest(message.payload, &this->logger);
////    if (!result.success)
////    {
////        return false;
////    }

////    logging::LogHeader(this->logger, flags::APP_HEADER_RX, result.header);
////
////    if (!result.header.control.IsFirAndFin())
////    {
////        SIMPLE_LOG_BLOCK(this->logger, flags::WARN, "Ignoring fragment. Requests must have FIR/FIN == 1");
////        return false;
////    }
////
////    if (result.header.control.CON)
////    {
////        SIMPLE_LOG_BLOCK(this->logger, flags::WARN, "Ignoring fragment. Requests cannot request confirmation");
////        return false;
////    }
////
////    return this->ProcessObjects(ParsedRequest(message.addresses, result.header, result.objects));
////}

////void OContext::HandleNewEvents()
////{
////    this->shouldCheckForUnsolicited = true;
////    this->CheckForTaskStart();
////}
////
////void OContext::SetRestartIIN()
////{
////    this->staticIIN.SetBit(IINBit::DEVICE_RESTART);
////}
////
////IUpdateHandler& OContext::GetUpdateHandler()
////{
////    return this->database;
////}
////
//// ----------------------------- function handlers -----------------------------

////bool OContext::ProcessBroadcastRequest(const ParsedRequest& request)
    boolean ProcessBroadcastRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
    switch (request->header.function)
    {
    case (FunctionCode_WRITE):
//   IINField HandleWrite_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        this->HandleWrite(request.objects);
    HandleWrite_in_OContext(pOContext, &(request->objects));
        return true;
    case (FunctionCode_DIRECT_OPERATE_NR):
//   IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter);
////        this->HandleDirectOperate(request.objects, OperateType::DirectOperateNoAck, nullptr);
    HandleDirectOperate_in_OContext(pOContext, &(request->objects), OperateType_DirectOperateNoAck, NULL);
        return true;
    case (FunctionCode_IMMED_FREEZE_NR):
//   IINField HandleFreeze_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        this->HandleFreeze(request.objects);
    HandleFreeze_in_OContext(pOContext, &(request->objects));
        return true;
    case (FunctionCode_FREEZE_CLEAR_NR):
//   IINField HandleFreezeAndClear_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        this->HandleFreezeAndClear(request.objects);
    HandleFreezeAndClear_in_OContext(pOContext, &(request->objects));
        return true;
    case (FunctionCode_ASSIGN_CLASS):
    {
     boolean SupportsAssignClass_in_IOutstationApplication(IOutstationApplication*);
////        if (this->application->SupportsAssignClass())
        if (SupportsAssignClass_in_IOutstationApplication(&(pOContext->application)))
        {
//   IINField HandleAssignClass_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////            this->HandleAssignClass(request.objects);
    HandleAssignClass_in_OContext(pOContext, &(request->objects));
            return true;
        }
        else
        {
            return false;
        }
    }
    case (FunctionCode_RECORD_CURRENT_TIME):
    {
//    boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////        if (request.objects.is_not_empty())
        if (is_not_empty_in_HasLength_for_Uint16_t(&((request->objects).hHasLength)))
        {
//   IINField HandleRecordCurrentTime_in_OContext(OContext *pOContext);
////            this->HandleRecordCurrentTime();
   HandleRecordCurrentTime_in_OContext(pOContext);
            return true;
        }
        else
        {
            return false;
        }
    }
    case (FunctionCode_DISABLE_UNSOLICITED):
    {
////        if (this->params.allowUnsolicited)
        if (pOContext->params.allowUnsolicited)
        {
//   IINField HandleDisableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////            this->HandleDisableUnsolicited(request.objects, nullptr);
    HandleDisableUnsolicited_in_OContext(pOContext, &(request->objects), NULL);
            return true;
        }
        else
        {
            return false;
        }
    }
    case (FunctionCode_ENABLE_UNSOLICITED):
    {
        if (pOContext->params.allowUnsolicited)
        {
//   IINField HandleEnableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////            this->HandleEnableUnsolicited(request.objects, nullptr);
    HandleEnableUnsolicited_in_OContext(pOContext, &(request->objects), NULL);
            return true;
        }
        else
        {
            return false;
        }
    }
    default:
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Ignoring broadcast on function code: %s",
////                         FunctionCodeSpec::to_string(request.header.function));
        return false;
    }
}

////bool OContext::ProcessRequestNoAck(const ParsedRequest& request)
////{
////    switch (request.header.function)
////    {
////    case (FunctionCode::DIRECT_OPERATE_NR):
////        this->HandleDirectOperate(request.objects, OperateType::DirectOperateNoAck,
////                                  nullptr); // no object writer, this is a no ack code
////        return true;
////    case (FunctionCode::IMMED_FREEZE_NR):
////        this->HandleFreeze(request.objects);
////        return true;
////    case (FunctionCode::FREEZE_CLEAR_NR):
////        this->HandleFreezeAndClear(request.objects);
////        return true;
////    default:
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Ignoring NR function code: %s",
////                         FunctionCodeSpec::to_human_string(request.header.function));
////        return false;
////    }
////}

////IINField OContext::HandleNonReadResponse(const APDUHeader& header, const ser4cpp::rseq_t& objects, HeaderWriter& writer)
    IINField HandleNonReadResponse_in_OContext(OContext *pOContext, APDUHeader* header, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
    switch (header->function)
    {
    case (FunctionCode_WRITE):
//   IINField HandleWrite_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleWrite(objects);
   return HandleWrite_in_OContext(pOContext, objects);
    case (FunctionCode_SELECT):
//   IINField HandleSelect_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////        return this->HandleSelect(objects, writer);
   return HandleSelect_in_OContext(OContext *pOContext, objects, writer);
    case (FunctionCode_OPERATE):
//   IINField HandleOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////        return this->HandleOperate(objects, writer);
   return HandleOperate_in_OContext(pOContext, objects, writer);
    case (FunctionCode_DIRECT_OPERATE):
//   IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter);
////        return this->HandleDirectOperate(objects, OperateType::DirectOperate, &writer);
   return HandleDirectOperate_in_OContext(pOContext, objects, OperateType_DirectOperate, writer);
    case (FunctionCode_COLD_RESTART):
//   IINField HandleRestart_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, boolean isWarmRestart, HeaderWriter* pWriter);
////        return this->HandleRestart(objects, false, &writer);
   return HandleRestart_in_OContext(pOContext, objects, false, writer);
    case (FunctionCode_WARM_RESTART):
////        return this->HandleRestart(objects, true, &writer);
   return HandleRestart_in_OContext(pOContext, objects, true, writer);
    case (FunctionCode_ASSIGN_CLASS):
//   IINField HandleAssignClass_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleAssignClass(objects);
   return HandleAssignClass_in_OContext(pOContext, objects);
    case (FunctionCode_DELAY_MEASURE):
//   IINField HandleDelayMeasure_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////        return this->HandleDelayMeasure(objects, writer);
   return HandleDelayMeasure_in_OContext(pOContext, objects, writer);
    case (FunctionCode_RECORD_CURRENT_TIME):
{
//    boolean is_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
//   IINField HandleRecordCurrentTime_in_OContext(OContext *pOContext);
////        return objects.is_empty() ? this->HandleRecordCurrentTime() : IINField(IINBit::PARAM_ERROR);
   IINField temp1 = HandleRecordCurrentTime_in_OContext(pOContext);
   IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
        return is_empty_in_HasLength_for_Uint16_t(&(objects->hHasLength)) ? temp1 : iIINField;
}
    case (FunctionCode_DISABLE_UNSOLICITED):
{
   IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
//   IINField HandleDisableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
        return pOContext->params.allowUnsolicited ? ////this->HandleDisableUnsolicited(objects, &writer)
                                               HandleDisableUnsolicited_in_OContext(pOContext, objects, writer)
                                             : iIINField;////IINField(IINBit::FUNC_NOT_SUPPORTED);
}
    case (FunctionCode_ENABLE_UNSOLICITED):
{
   IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
//   IINField HandleEnableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
        return this->params.allowUnsolicited ? ////this->HandleEnableUnsolicited(objects, &writer)
                                               HandleEnableUnsolicited_in_OContext(pOContext, objects, writer)
                                             : iIINField;////IINField(IINBit::FUNC_NOT_SUPPORTED);
}
    case (FunctionCode_IMMED_FREEZE):
//   IINField HandleFreeze_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleFreeze(objects);
   return HandleFreeze_in_OContext(pOContext, objects);
    case (FunctionCode_FREEZE_CLEAR):
//   IINField HandleFreezeAndClear_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleFreezeAndClear(objects);
   return HandleFreezeAndClear_in_OContext(pOContext, objects);
    default:
{
 ////       return IINField(IINBit::FUNC_NOT_SUPPORTED);
   IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
}
    }
}

////ser4cpp::Pair<IINField, AppControlField> OContext::HandleRead(const ser4cpp::rseq_t& objects, HeaderWriter& writer)
   PairSer4cpp_for_IINField_AppControlField HandleRead_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter writer)
{
// void Reset_in_ResponseContext(ResponseContext *pResponseContext);
////    this->rspContext.Reset();
  Reset_in_ResponseContext(&(pOContext->rspContext));
//     void Unselect_in_EventBuffer(EventBuffer *pEventBuffer);
////    this->eventBuffer.Unselect(); // always un-select any previously selected points when we start a new read request
      Unselect_in_EventBuffer(&(pOContext->eventBuffer));
//    void Unselect_in_Database(Database *pDatabase);
////    this->database.Unselect();
     Unselect_in_Database(&(this->database));

//void  ReadHandler_in_ReadHandler(ReadHandler *pReadHandler, IStaticSelector* staticSelector, IEventSelector* eventSelector);
////    ReadHandler handler(this->database, this->eventBuffer);
  ReadHandler handler;
  ReadHandler_in_ReadHandler(&handler, &(pOContext->database.iIStaticSelector), &(pOContext->eventBuffer.iIEventSelector));
//    ParseResult_uint8_t Parse_in_APDUParser_static(
//                             RSeq_for_Uint16_t *buffer,
//                             IAPDUHandler *handler);
////    auto result = APDUParser::Parse(objects, handler, &this->logger,
////                                    ParserSettings::NoContents()); // don't expect range/count context on a READ
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &(handler.iIAPDUHandler));
    if (result == ParseResult::OK)
    {
        auto control = this->rspContext.LoadResponse(writer);
        return ser4cpp::Pair<IINField, AppControlField>(handler.Errors(), control);
    }

    this->rspContext.Reset();
    return ser4cpp::Pair<IINField, AppControlField>(IINFromParseResult(result),
                                                    AppControlField(true, true, false, false));
}

////IINField OContext::HandleWrite(const ser4cpp::rseq_t& objects)
   IINField HandleWrite_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
{
    WriteHandler handler(*this->application, this->time, this->sol.seq.num, Timestamp(this->executor->get_time()),
                         &this->staticIIN);
    auto result = APDUParser::Parse(objects, handler, &this->logger);
    return (result == ParseResult::OK) ? handler.Errors() : IINFromParseResult(result);
}

////IINField OContext::HandleDirectOperate(const ser4cpp::rseq_t& objects, OperateType opType, HeaderWriter* pWriter)
   IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter)
{
    // since we're echoing, make sure there's enough size before beginning
//    uint16_t Remaining_in_HeaderWriter(HeaderWriter *pHeaderWriter);
////    if (pWriter && (objects.length() > pWriter->Remaining()))
    if (pWriter && (length_in_HasLength_for_Uint16_t(&(objects->hHasLength)) > Remaining_in_HeaderWriter(pWriter)))
    {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Igonring command request due to oversized payload size of %zu",
////                         objects.length());
////        return IINField(IINBit::PARAM_ERROR);
   IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
   return iIINField;
    }

// void  CommandActionAdapter_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, ICommandHandler* handler, boolean is_select, IUpdateHandler* updates, OperateType_uint8_t op_type);
////    CommandActionAdapter adapter(*this->commandHandler, false, this->database, opType);
    CommandActionAdapter adapter;
   CommandActionAdapter_in_CommandActionAdapter(&adapter, pOContext->commandHandler, false, &(pOContext->database.iiIUpdateHandler), opType);

//   void CommandResponseHandler_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, uint32_t maxCommands_, ICommandAction* pCommandAction_, HeaderWriter* pWriter_);
////    CommandResponseHandler handler(this->params.maxControlsPerRequest, &adapter, pWriter);
    CommandResponseHandler handler;
    CommandResponseHandler_in_CommandResponseHandler(&handler, pOContext->params.maxControlsPerRequest, &(adapter.iICommandAction), pWriter);

//    ParseResult_uint8_t Parse_in_APDUParser_static(
//                             RSeq_for_Uint16_t *buffer,
//                             IAPDUHandler *handler);
////    auto result = APDUParser::Parse(objects, handler, &this->logger);
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &handler);

    pOContext->shouldCheckForUnsolicited = true;
    return (result == ParseResult_OK) ? 
//  IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
                 ////handler.Errors() 
                  Errors_in_IAPDUHandler(&(handler.iIAPDUHandler)) :
//IINField IINFromParseResult(ParseResult_uint8_t result);
////                  IINFromParseResult(result);
                      IINFromParseResult(result);
}

////IINField OContext::HandleSelect(const ser4cpp::rseq_t& objects, HeaderWriter& writer)
   IINField HandleSelect_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
    // since we're echoing, make sure there's enough size before beginning
////    if (objects.length() > writer.Remaining())
    if (length_in_HasLength_for_Uint16_t(&(objects->hHasLength)) > Remaining_in_HeaderWriter(writer))
    {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Igonring command request due to oversized payload size of %zu",
////                         objects.length());
////        return IINField(IINBit::PARAM_ERROR);
   IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
   return iIINField;
    }

    // the 'OperateType' is just ignored  since it's a select
// void  CommandActionAdapter_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, ICommandHandler* handler, boolean is_select, IUpdateHandler* updates, OperateType_uint8_t op_type);
////    CommandActionAdapter adapter(*this->commandHandler, true, this->database, OperateType::DirectOperate);
    CommandActionAdapter adapter;
   CommandActionAdapter_in_CommandActionAdapter(&adapter, pOContext->commandHandler, true, &(pOContext->database.iIUpdateHandler), OperateType_DirectOperate);

////    CommandResponseHandler handler(this->params.maxControlsPerRequest, &adapter, &writer);
    CommandResponseHandler handler;
    CommandResponseHandler_in_CommandResponseHandler(&handler, pOContext->params.maxControlsPerRequest, &(adapter.iICommandAction), writer);

////    auto result = APDUParser::Parse(objects, handler, &this->logger);
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &handler);

    if (result == ParseResult_OK)
    {
//    boolean AllCommandsSuccessful_in_CommandResponseHandle(CommandResponseHandle *pCommandResponseHandle);
////        if (handler.AllCommandsSuccessful())
            if (AllCommandsSuccessful_in_CommandResponseHandle(&handler))
        {
//void Select_in_ControlState(ControlState *pControlState,  AppSeqNum* currentSeqN, Timestamp* now, RSeq_for_Uint16_t* objects);
//Timestamp Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *);
// void Timestamp_in_TimestampOver2(Timestamp *pTimestamp, uint64_t value);
////            this->control.Select(this->sol.seq.num, Timestamp(this->executor->get_time()), objects);
uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(pOContext->executor);
Timestamp tTimestamp;
 Timestamp_in_TimestampOver2(&tTimestamp, temp);
   Select_in_ControlState(&(pOContext->control), &(pOContext->sol.seq.num), &tTimestamp, objects);
        }

////        return handler.Errors();
            return Errors_in_IAPDUHandler(&(handler.iIAPDUHandler)) :
    }

    return IINFromParseResult(result);
}

IINField HandleOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
// since we're echoing, make sure there's enough size before beginning
////    if (objects.length() > writer.Remaining())
    if (length_in_HasLength_for_Uint16_t(&(objects->hHasLength)) > Remaining_in_HeaderWriter(writer))
    {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Igonring command request due to oversized payload size of %zu",
////                         objects.length());
////        return IINField(IINBit::PARAM_ERROR);
   IINField iIINField;
   IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
   return iIINField;
    }

////    auto now = Timestamp(this->executor->get_time());
uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(pOContext->executor);
Timestamp now;
 Timestamp_in_TimestampOver2(&now, temp);

//CommandStatus_uint8_t ValidateSelection_in_ControlState(ControlState *pControlState,
//    AppSeqNum* seq,
//    Timestamp* now,
//    TimeDuration* timeout,
//    RSeq_for_Uint16_t* objects);
////    auto result = this->control.ValidateSelection(this->sol.seq.num, now, this->params.selectTimeout, objects);
CommandStatus_uint8_t result = ValidateSelection_in_ControlState(&(pOContext->control),
    &(pOContext->sol.seq.num),
    &now,
    &(pOContext->params.selectTimeout),
    objects);

    if (result == CommandStatus_SUCCESS)
    {
////        CommandActionAdapter adapter(*this->commandHandler, false, this->database, OperateType::SelectBeforeOperate);
    CommandActionAdapter adapter;
   CommandActionAdapter_in_CommandActionAdapter(&adapter, pOContext->commandHandler, false, &(pOContext->database.iIUpdateHandler), OperateType_SelectBeforeOperate);

////        CommandResponseHandler handler(this->params.maxControlsPerRequest, &adapter, &writer);
    CommandResponseHandler handler;
    CommandResponseHandler_in_CommandResponseHandler(&handler, pOContext->params.maxControlsPerRequest, &(adapter.iICommandAction), writer);

////        auto result = APDUParser::Parse(objects, handler, &this->logger);
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &handler);

        pOContext->shouldCheckForUnsolicited = true;
////        return (result == ParseResult::OK) ? handler.Errors() : IINFromParseResult(result);
    return (result == ParseResult_OK) ? 
//  IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
                 ////handler.Errors() 
                  Errors_in_IAPDUHandler(&(handler.iIAPDUHandler)) :
//IINField IINFromParseResult(ParseResult_uint8_t result);
////                  IINFromParseResult(result);
                      IINFromParseResult(result);
    }
    else
    {
//void Unselect_in_ControlState(ControlState *pControlState);
////        this->control.Unselect();
 Unselect_in_ControlState(&(pOContext->control));
    }

//   IINField HandleCommandWithConstant_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer, CommandStatus_uint16_t status);
////    return this->HandleCommandWithConstant(objects, writer, result);
   return HandleCommandWithConstant_in_OContext(pOContext, objects, HeaderWriter* writer, result);
}

////IINField OContext::HandleDelayMeasure(const ser4cpp::rseq_t& objects, HeaderWriter& writer)
   IINField HandleDelayMeasure_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
//    boolean is_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    if (objects.is_empty())
    if (is_empty_in_HasLength_for_Uint16_t(&(objects->hHasLength)))
    {
        Group52Var2 value;
  Group52Var2_in_Group52Var2(&value);

        value.time_uint16_t = 0; // respond with 0 time delay
//    boolean WriteSingleValue_for_UInt8_Group52Var2_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
//                                                                    QualifierCode_uint8_t qc, Group51Var2*);
////        writer.WriteSingleValue<ser4cpp::UInt8, Group52Var2>(QualifierCode::UINT8_CNT, value);
    WriteSingleValue_for_UInt8_Group52Var2_in_HeaderWriter(writer, 
                                                                    QualifierCode_UINT8_CNT, &value);
////        return IINField::Empty();
   return Empty_in_IINField_static();
    }

// there shouldn't be any trailing headers in delay measure request, no need to even parse
////    return IINField(IINBit::PARAM_ERROR);
       IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return iIINField;
}

////IINField OContext::HandleRecordCurrentTime()
   IINField HandleRecordCurrentTime_in_OContext(OContext *pOContext)
{
//void RecordCurrentTime_in_TimeSyncState(TimeSyncState *pTimeSyncState, AppSeqNum* seq, Timestamp* now);
////    this->time.RecordCurrentTime(this->sol.seq.num, Timestamp(this->executor->get_time()));
uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(pOContext->executor);
Timestamp tTimestamp;
 Timestamp_in_TimestampOver2(&tTimestamp, temp);
 RecordCurrentTime_in_TimeSyncState(&(pOContext->timeTimeSyncState), &(pOContext->sol.seq.num), &tTimestamp);
////    return IINField::Empty();
   return Empty_in_IINField_static();
}

////IINField OContext::HandleRestart(const ser4cpp::rseq_t& objects, bool isWarmRestart, HeaderWriter* pWriter)
   IINField HandleRestart_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, boolean isWarmRestart, HeaderWriter* pWriter)
{
//    boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    if (objects.is_not_empty())
    if (is_not_empty_in_HasLength_for_Uint16_t(&(objects->hHasLength)))
{
////        return IINField(IINBit::PARAM_ERROR);
       IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return iIINField;
}

//    RestartMode_uint8_t WarmRestartSupport_in_IOutstationApplication(IOutstationApplication*);
//    RestartMode_uint8_t ColdRestartSupport_in_IOutstationApplication(IOutstationApplication*);
////    auto mode = isWarmRestart ? this->application->WarmRestartSupport() : this->application->ColdRestartSupport();
       RestartMode_uint8_t mode = isWarmRestart ? 
                                  WarmRestartSupport_in_IOutstationApplication(OContext->application) :
                                  ColdRestartSupport_in_IOutstationApplication(OContext->application);

    switch (mode)
    {
    case (RestartMode_UNSUPPORTED):
{
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
       IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
  return iIINField;
}
    case (RestartMode_SUPPORTED_DELAY_COARSE):
    {
//    uint16_t WarmRestart_in_IOutstationApplication(IOutstationApplication*);
//    uint16_t ColdRestart_in_IOutstationApplication(IOutstationApplication*);
////        auto delay = isWarmRestart ? this->application->WarmRestart() : this->application->ColdRestart();
           uint16_t delay = isWarmRestart ?
                            WarmRestart_in_IOutstationApplication(OContext->application):
                            ColdRestart_in_IOutstationApplication(OContext->application);
        if (pWriter)
        {
            Group52Var1 coarse;
  Group52Var1_in_Group52Var1(&coarse);

            coarse.time_uint16_t = delay;
//    boolean WriteSingleValue_for_UInt8_Group52Var1_in_HeaderWriter(HeaderWriter *pHeaderWriter, 
//                                                                    QualifierCode_uint8_t qc, Group51Var1*);
////            pWriter->WriteSingleValue<ser4cpp::UInt8>(QualifierCode::UINT8_CNT, coarse);
     WriteSingleValue_for_UInt8_Group52Var1_in_HeaderWriter(pWriter, 
                                                                    QualifierCode_UINT8_CNT, &coarse);
        }
////        return IINField::Empty();
   return Empty_in_IINField_static();
    }
    default:
    {
////        auto delay = isWarmRestart ? this->application->WarmRestart() : this->application->ColdRestart();
           uint16_t delay = isWarmRestart ?
                            WarmRestart_in_IOutstationApplication(OContext->application):
                            ColdRestart_in_IOutstationApplication(OContext->application);
        if (pWriter)
        {
            Group52Var2 fine;
  Group52Var2_in_Group52Var2(&fine);
            fine.time_uint16_t = delay;
////            pWriter->WriteSingleValue<ser4cpp::UInt8>(QualifierCode::UINT8_CNT, fine);
     WriteSingleValue_for_UInt8_Group52Var2_in_HeaderWriter(pWriter, 
                                                                    QualifierCode_UINT8_CNT, &coarse);
        }
////        return IINField::Empty();
   return Empty_in_IINField_static();
    }
    }
}

////IINField OContext::HandleAssignClass(const ser4cpp::rseq_t& objects)
   IINField HandleAssignClass_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
{
//     boolean SupportsAssignClass_in_IOutstationApplication(IOutstationApplication*);
////    if (this->application->SupportsAssignClass())
    if (SupportsAssignClass_in_IOutstationApplication(pOContext->application))
    {
//  void AssignClassHandler_in_AssignClassHandler(AssignClassHandler *pAssignClassHandler, IOutstationApplication* application, IClassAssigner* assigner);
////        AssignClassHandler handler(*this->application, this->database);
           AssignClassHandler handler;
   AssignClassHandler_in_AssignClassHandler(&handler, pOContext->application, &(pOContext->database.iIClassAssigner));

//    ParseResult_uint8_t Parse_in_APDUParser_static(
//                             RSeq_for_Uint16_t *buffer,
//                             IAPDUHandler *handler);
////        auto result = APDUParser::Parse(objects, handler, &this->logger, ParserSettings::NoContents());
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &(handler.iIAPDUHandler));

////        return (result == ParseResult::OK) ? handler.Errors() : IINFromParseResult(result);
    return (result == ParseResult_OK) ? 
//  IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
                 ////handler.Errors() 
                  Errors_in_IAPDUHandler(&(handler.iIAPDUHandler)) :
//IINField IINFromParseResult(ParseResult_uint8_t result);
////                  IINFromParseResult(result);
                      IINFromParseResult(result);
    }

////    return IINField(IINBit::FUNC_NOT_SUPPORTED);
       IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
  return iIINField;
}

////IINField OContext::HandleDisableUnsolicited(const ser4cpp::rseq_t& objects, HeaderWriter* /*writer*/)
   IINField HandleDisableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
    ClassBasedRequestHandler handler;
 ClassBasedRequestHandler_in_ClassBasedRequestHandler(&handler);

//    ParseResult_uint8_t Parse_in_APDUParser_static(
//                             RSeq_for_Uint16_t *buffer,
//                             IAPDUHandler *handler);
////    auto result = APDUParser::Parse(objects, handler, &this->logger);
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &(handler.iIAPDUHandler));

    if (result == ParseResult_OK)
    {
//  void Clear_in_ClassField(ClassField *pClassField, ClassField *field);
//ClassField GetClassField_in_ClassBasedRequestHandler(ClassBasedRequestHandler *pClassBasedRequestHandler);
////        this->params.unsolClassMask.Clear(handler.GetClassField());
ClassField temp = GetClassField_in_ClassBasedRequestHandler(&handler);
   Clear_in_ClassField(&(pOContext->params.unsolClassMask), &temp);
////        return handler.Errors();
          return  Errors_in_IAPDUHandler(&(handler.iIAPDUHandler));
    }

    return IINFromParseResult(result);
}

////IINField OContext::HandleEnableUnsolicited(const ser4cpp::rseq_t& objects, HeaderWriter* /*writer*/)
   IINField HandleEnableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
    ClassBasedRequestHandler handler;
 ClassBasedRequestHandler_in_ClassBasedRequestHandler(&handler);

////    auto result = APDUParser::Parse(objects, handler, &this->logger);
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &(handler.iIAPDUHandler));

    if (result == ParseResult_OK)
    {
//  void Set_in_ClassFieldOver1(ClassField *pClassField, ClassField *field);
//ClassField GetClassField_in_ClassBasedRequestHandler(ClassBasedRequestHandler *pClassBasedRequestHandler);
////        this->params.unsolClassMask.Set(handler.GetClassField());
ClassField temp = GetClassField_in_ClassBasedRequestHandler(&handler);
   Set_in_ClassFieldOver1(&(pOContext->params.unsolClassMask), &temp);

        pOContext->shouldCheckForUnsolicited = true;
////        return handler.Errors();
          return  Errors_in_IAPDUHandler(&(handler.iIAPDUHandler));
    }

    return IINFromParseResult(result);
}

////IINField OContext::HandleCommandWithConstant(const ser4cpp::rseq_t& objects, HeaderWriter& writer, CommandStatus status)
   IINField HandleCommandWithConstant_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer, CommandStatus_uint8_t status)
{
//void ConstantCommandAction_in_ConstantCommandAction(ConstantCommandAction *pConstantCommandAction, CommandStatus status_);
////    ConstantCommandAction constant(status);
     ConstantCommandAction constant;
 ConstantCommandAction_in_ConstantCommandAction(&constant, status);

//   void CommandResponseHandler_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, uint32_t maxCommands_, ICommandAction* pCommandAction_, HeaderWriter* pWriter_);
////    CommandResponseHandler handler(this->params.maxControlsPerRequest, &constant, &writer);
        CommandResponseHandler handler;
    CommandResponseHandler_in_CommandResponseHandler(&handler, pOContext->params.maxControlsPerRequest, &(constant.iICommandAction), writer);

////    auto result = APDUParser::Parse(objects, handler, &this->logger);
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &(handler.iIAPDUHandler));
    return IINFromParseResult(result);
}

////IINField OContext::HandleFreeze(const ser4cpp::rseq_t& objects)
   IINField HandleFreeze_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
{
//   void FreezeRequestHandler_in_FreezeRequestHandler(FreezeRequestHandler *pFreezeRequestHandler, boolean clear, Database* database);
////    FreezeRequestHandler handler(false, database);
   FreezeRequestHandler handler;
   FreezeRequestHandler_in_FreezeRequestHandler(&handler, false, &(pOContext->database));

////    auto result = APDUParser::Parse(objects, handler, &this->logger, ParserSettings::NoContents());
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &(handler.iIAPDUHandler));
    return IINFromParseResult(result);
}

////IINField OContext::HandleFreezeAndClear(const ser4cpp::rseq_t& objects)
   IINField HandleFreezeAndClear_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
{
////    FreezeRequestHandler handler(true, database);
   FreezeRequestHandler handler;
   FreezeRequestHandler_in_FreezeRequestHandler(&handler, true, &(pOContext->database));

////    auto result = APDUParser::Parse(objects, handler, &this->logger, ParserSettings::NoContents());
    ParseResult_uint8_t result = Parse_in_APDUParser_static(
                             objects,
                             &(handler.iIAPDUHandler));
    return IINFromParseResult(result);
}

////} // namespace opendnp3
