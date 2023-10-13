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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
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
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OContext_in_OContext1"<<'\n';
  decrement_stack_info();
#endif

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
                       &(pOContext->application->iIDnpTimeSource),
                       config->params.typesAllowedInClass0);

// void ResponseContext_in_ResponseContext(ResponseContext *pResponseContext, IResponseLoader* staticLoader, IResponseLoader* eventLoader);
////      pOContext->rspContext(database, eventBuffer),
  ResponseContext_in_ResponseContext(&(pOContext->rspContext), &(pOContext->database.iIResponseLoader), &(pOContext->eventBuffer.iIResponseLoader));

////      pOContext->params(config.params),
  pOContext->params = config->params;

  pOContext->isOnline = false;
  pOContext->isTransmitting = false;
////      pOContext->staticIIN = IINBit_DEVICE_RESTART;
  IINField_in_IINFieldOver2(&(pOContext->staticIIN), IINBit_DEVICE_RESTART);

//  void DeferredRequest_in_DeferredRequest(DeferredRequest *pDeferredRequest, uint32_t maxAPDUSize);
///      pOContext->deferred(config->params.maxRxFragSize),
  DeferredRequest_in_DeferredRequest(&(pOContext->deferred), config->params.maxRxFragSize);

//  void  OutstationSolState_in_OutstationSolState(OutstationSolState *pOutstationSolState, uint32_t maxTxSize);
////      pOContext->sol(config->params.maxTxFragSize),
  OutstationSolState_in_OutstationSolState(&(pOContext->sol), config->params.maxTxFragSize);

//  void  OutstationUnsolState_in_OutstationUnsolState(OutstationUnsolState *pOutstationUnsolState, uint32_t maxTxSize);
////      pOContext->unsol(config->params.maxTxFragSize),
  OutstationUnsolState_in_OutstationUnsolState(&(pOContext->unsol), config->params.maxTxFragSize);

//   void NumRetries_in_NumRetries(NumRetries *pNumRetries, uint16_t maxNumRetries, boolean isInfinite);
////      pOContext->unsolRetries(config->params.numUnsolRetries),
  pOContext->unsolRetries = config->params.numUnsolRetries;

  pOContext->shouldCheckForUnsolicited = false;

  pPointerGlobal1 = pOContext;
//     OutstationState* Inst_in_StateIdle_static(void);
  pOContext->state = Inst_in_StateIdle_static();//// = &StateIdle::Inst();

  EventBuffer_in_EventBufferOver1(&(pOContext->eventBuffer));
  OutstationParams_in_OutstationParams(&(pOContext->params));

  RequestHistory_in_RequestHistory(&(pOContext->history));
  ControlState_in_ControlStateOver1(&(pOContext->control));
  TimeSyncState_in_TimeSyncState(&(pOContext->timeTimeSyncState));

  Settable_for_LinkBroadcastAddress_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived));

  setParentPointer_in_IUpDown(&(pOContext->iIUpperLayer.iIUpDown), pOContext);
  setParentPointer_in_IUpperLayer(&(pOContext->iIUpperLayer), pOContext);

  pOContext->iIUpperLayer.iIUpDown.pOnLowerLayerUp_in_IUpDown = OnLowerLayerUp_in_OContext_override;
  pOContext->iIUpperLayer.iIUpDown.pOnLowerLayerDown_in_IUpDown = OnLowerLayerDown_in_OContext_override;
  pOContext->iIUpperLayer.pOnReceive_in_IUpperLayer = OnReceive_in_OContext_override;
  pOContext->iIUpperLayer.pOnTxReady_in_IUpperLayer = OnTxReady_in_OContext_override;
}

boolean OnLowerLayerUp_in_OContext(OContext* pOContext)
{
  if (pOContext->isOnline)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "already online");
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'already online')"<<std::endl;
    decrement_stack_info();
#endif
    return false;
  }

  pOContext->isOnline = true;
  pOContext->shouldCheckForUnsolicited = true;
//    void CheckForTaskStart_in_OContext(OContext *pOContext);
////    this->CheckForTaskStart();
  CheckForTaskStart_in_OContext(pOContext);
  return true;
}

boolean OnLowerLayerDown_in_OContext(OContext* pOContext)
{

  if (!(pOContext->isOnline))
  {
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "already offline");
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'already offline')"<<std::endl;
    decrement_stack_info();
#endif
    return false;
  }

////    this->state = &StateIdle::Inst();
  pOContext->state = Inst_in_StateIdle_static();//// = &StateIdle::Inst();

  pOContext->isOnline = false;
  pOContext->isTransmitting = false;

//    void Reset_in_OutstationSolState(OutstationSolState *pOutstationSolState);
////    sol.Reset();
  Reset_in_OutstationSolState(&(pOContext->sol));
////    unsol.Reset();
  Reset_in_OutstationUnsolState(&(pOContext->unsol));
////    history.Reset();
  Reset_in_RequestHistory(&(pOContext->history));
////    deferred.Reset();
  Reset_in_DeferredRequest(&(pOContext->deferred));
////    eventBuffer.Unselect();
  Unselect_in_EventBuffer(&(pOContext->eventBuffer));
////    rspContext.Reset();
  Reset_in_ResponseContext(&(pOContext->rspContext));
////    confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(pOContext->confirmTimer));

  return true;
}

boolean OnTxReady_in_OContext(OContext* pOContext)
{

  if (!(pOContext->isOnline) || !(pOContext->isTransmitting))
  {
    return false;
  }

  pOContext->isTransmitting = false;
////    this->CheckForTaskStart();
  CheckForTaskStart_in_OContext(pOContext);
  return true;
}

boolean OnReceive_in_OContext(OContext* pOContext, Message* message)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnReceive_in_OContext1"<<std::endl;
#endif
  if (!(pOContext->isOnline))
  {
////        SIMPLE_LOG_BLOCK(this->logger, flags::ERR, "ignoring received data while offline");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(this->logger, flags::ERR, 'ignoring received data while offline')"<<std::endl;
    decrement_stack_info();
#endif
    return false;
  }

//pMemory_Message_1=  MEMORY_Message_1(0, message);

//    boolean ProcessMessage_in_OContext(OContext *pOContext, Message* message);
////    this->ProcessMessage(message);
  ProcessMessage_in_OContext(pOContext, message);

////    this->CheckForTaskStart();
  CheckForTaskStart_in_OContext(pOContext);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return true;
}

////bool OContext::OnLowerLayerUp()
boolean OnLowerLayerUp_in_OContext_override(void* pIUpDown)
{
  OContext *parent =
    (OContext*)getParentPointer_in_IUpDown((IUpDown*)pIUpDown);

  return OnLowerLayerUp_in_OContext(parent);
}

////bool OContext::OnLowerLayerDown()
boolean OnLowerLayerDown_in_OContext_override(void* pIUpDown)
{
  OContext *parent =
    (OContext*)getParentPointer_in_IUpDown((IUpDown*)pIUpDown);

  return OnLowerLayerDown_in_OContext(parent);
}

////bool OContext::OnTxReady()
boolean OnTxReady_in_OContext_override(void* pIUpperLayer)
{
  OContext *parent =
    (OContext*)getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);

  return OnTxReady_in_OContext(parent);
}

////bool OContext::OnReceive(const Message& message)
boolean OnReceive_in_OContext_override(void* pIUpperLayer, Message* message)
{
  OContext *parent =
    (OContext*)getParentPointer_in_IUpperLayer((IUpperLayer*)pIUpperLayer);

  return OnReceive_in_OContext(parent, message);
}

////OutstationState& OContext::OnReceiveSolRequest(const ParsedRequest& request)
OutstationState* OnReceiveSolRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
  // analyze this request to see how it compares to the last request
// анализируем этот запрос, чтобы увидеть, как он сравниваетс€ с последним запросом
//    boolean HasLastRequest_in_RequestHistory(RequestHistory *pRequestHistory);
////    if (this->history.HasLastRequest())
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"OnReceiveSolRequest_in_OContext1"<<std::endl;
#endif
  if (HasLastRequest_in_RequestHistory(&(pOContext->history)))
  {
//&(pOContext->sol.seq.num)
//boolean Equals_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t other);
////        if (this->sol.seq.num.Equals(request.header.control.SEQ))
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"OnReceiveSolRequest_in_OContext2"<<std::endl;
#endif
    if (Equals_in_SequenceNum_for_uint8_Modulus16(&(pOContext->sol.seq.num), request->header.control.SEQ))
    {
//   boolean FullyEqualsLastRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects);
////            if (this->history.FullyEqualsLastRequest(request.header, request.objects))
#ifdef  LOG_INFO
      std::cout<<getString_stack_info();
      std::cout<<"OnReceiveSolRequest_in_OContext3"<<std::endl;
#endif
      if (FullyEqualsLastRequest_in_RequestHistory(&(pOContext->history), &(request->header), &(request->objects)))
      {
////                if (request.header.function == FunctionCode::READ)
        if (request->header.function == FunctionCode_READ)
        {
//    OutstationState* OnRepeatReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////                    return this->state->OnRepeatReadRequest(*this, request);
#ifdef  LOG_INFO
          std::cout<<getString_stack_info();
          std::cout<<"OnReceiveSolRequest_in_OContext4"<<std::endl;
          decrement_stack_info();
#endif
          return OnRepeatReadRequest_in_OutstationState(pOContext->state, pOContext, request);
        }

//    OutstationState* OnRepeatNonReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////                return this->state->OnRepeatNonReadRequest(*this, request);
#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"OnReceiveSolRequest_in_OContext5"<<std::endl;
        decrement_stack_info();
#endif
        return OnRepeatNonReadRequest_in_OutstationState(pOContext->state, pOContext, request);
      }
      else // new operation with same SEQ
      {
//    OutstationState* ProcessNewRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////                return this->ProcessNewRequest(request);
#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"OnReceiveSolRequest_in_OContext6"<<std::endl;
        decrement_stack_info();
#endif
        return ProcessNewRequest_in_OContext(pOContext, request);
      }
    }
    else // completely new sequence #
    {
////            return this->ProcessNewRequest(request);
#ifdef  LOG_INFO
      std::cout<<getString_stack_info();
      std::cout<<"OnReceiveSolRequest_in_OContext7"<<std::endl;
      decrement_stack_info();
#endif
      return ProcessNewRequest_in_OContext(pOContext, request);
    }
  }
  else
  {
////        return this->ProcessNewRequest(request);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"OnReceiveSolRequest_in_OContext8"<<std::endl;
    decrement_stack_info();
#endif
    return ProcessNewRequest_in_OContext(pOContext, request);
  }
}

////OutstationState& OContext::ProcessNewRequest(const ParsedRequest& request)
OutstationState* ProcessNewRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
////    pOContext->sol.seq.num = request->header.control.SEQ;
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(&(pOContext->sol.seq.num), request->header.control.SEQ);

#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessNewRequest_in_OContext1"<<std::endl;
  decrement_stack_info();
#endif
  if (request->header.function == FunctionCode_READ)
  {
//    OutstationState* OnNewReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////        return this->state->OnNewReadRequest(*this, request);
    return OnNewReadRequest_in_OutstationState(pOContext->state, pOContext, request);
  }

//    OutstationState* OnNewNonReadRequest_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////    return this->state->OnNewNonReadRequest(*this, request);
  return OnNewNonReadRequest_in_OutstationState(pOContext->state, pOContext, request);
}

////bool OContext::ProcessObjects(const ParsedRequest& request)
boolean ProcessObjects_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessObjects_in_OContext1"<<std::endl;
#endif
//    boolean IsBroadcast_in_Addresses(Addresses *pAddresses);
////    if (request.addresses.IsBroadcast())
  if (IsBroadcast_in_Addresses(&(request->addresses)))
  {
//    OutstationState* OnBroadcastMessage_in_OutstationState(OutstationState*, void* pOContext, ParsedRequest* request);
////        this->state = &this->state->OnBroadcastMessage(*this, request);
    pOContext->state = OnBroadcastMessage_in_OutstationState(pOContext->state, pOContext, request);

#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return true;
  }

//    boolean IsNoAckFuncCode_in_Functions_static(FunctionCode_uint8_t code);
////    if (Functions::IsNoAckFuncCode(request.header.function))
  if (IsNoAckFuncCode_in_Functions_static(request->header.function))
  {
    // this is the only request we process while we are transmitting
    // because it doesn't require a response of any kind
    // это единственный запрос, который мы обрабатываем во врем€ передачи
    // потому что это не требует никакого ответа
//    boolean ProcessRequestNoAck_in_OContext(OContext *pOContext, ParsedRequest* request);
////        return this->ProcessRequestNoAck(request);
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return ProcessRequestNoAck_in_OContext(pOContext, request);
  }

  if (pOContext->isTransmitting)
  {
//  void Set_in_DeferredRequest(DeferredRequest *pDeferredRequest, ParsedRequest* request);
////        this->deferred.Set(request);
    Set_in_DeferredRequest(&(pOContext->deferred), request);
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return true;
  }

  if (request->header.function == FunctionCode_CONFIRM)
  {
//    boolean ProcessConfirm_in_OContext(OContext *pOContext, ParsedRequest* request);
////        return this->ProcessConfirm(request);
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return ProcessConfirm_in_OContext(pOContext, request);
  }

//    boolean ProcessRequest_in_OContext(OContext *pOContext, ParsedRequest* request);
////    return this->ProcessRequest(request);
  return ProcessRequest_in_OContext(pOContext, request);
}

////bool OContext::ProcessRequest(const ParsedRequest& request)
boolean ProcessRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessRequest_in_OContext1"<<std::endl;
#endif
  if (request->header.control.UNS)
  {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Ignoring unsol with invalid function code: %s",
////                         FunctionCodeSpec::to_human_string(request.header.function));
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Ignoring unsol with invalid function code: %s'"<<std::endl;
    decrement_stack_info();
#endif
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
  pOContext->state = OnConfirm_in_OutstationState(pOContext->state, pOContext, request);
  return true;
}

////OutstationState& OContext::BeginResponseTx(uint16_t destination, APDUResponse& response)
OutstationState* BeginResponseTx_in_OContext(OContext *pOContext, uint16_t destination, APDUResponse* response)
{
#ifdef  LOG_INFO
  std::cout<<"";
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"BeginResponseTx_in_OContext1"<<std::endl;
#endif
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
////    pOContext->sol.seq.confirmNum = GetControl_in_APDUWrapper(&(response->aAPDUWrapper)).SEQ;////response.GetControl().SEQ;
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(&(pOContext->sol.seq.confirmNum), GetControl_in_APDUWrapper(&(response->aAPDUWrapper)).SEQ);

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
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
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

boolean HandlerBooleanParsedRequest_in_OContext(void* pOContext, ParsedRequest* pParsedRequest);
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
//  boolean  Process_for_handlerBooleanParsedRequest_in_DeferredRequest(DeferredRequest *pDeferredRequest, void*, boolean (*pHandlerBooleanParsedRequest)(ParsedRequest*));
    Process_for_handlerBooleanParsedRequest_in_DeferredRequest(&(pOContext->deferred), pOContext, HandlerBooleanParsedRequest_in_OContext);
  }
}

void CheckForUnsolicitedNull_in_OContext(OContext *pOContext)
{
//   boolean CanTransmit_in_OContext(OContext *pOContext);
//     boolean IsIdle_in_OutstationState(OutstationState *);
////    if (this->CanTransmit() && this->state->IsIdle() && this->params.allowUnsolicited)
  if (CanTransmit_in_OContext(pOContext) && IsIdle_in_OutstationState(pOContext->state) && pOContext->params.allowUnsolicited)
  {
////        if (!this->unsol.completedNull)
    if (!pOContext->unsol.completedNull)
    {
      // send a NULL unsolcited message
//APDUResponse Start_in_TxBuffer(TxBuffer *pTxBuffer);
////            auto response = this->unsol.tx.Start();
      APDUResponse response = Start_in_TxBuffer(&(pOContext->unsol.tx));
//    void NullUnsolicited_in_APDUBuilders_static(APDUResponse* response, uint8_t seq, IINField* iin);
//    IINField GetResponseIIN_in_OContext(OContext *pOContext);
////            build::NullUnsolicited(response, this->unsol.seq.num, this->GetResponseIIN());
      IINField temp = GetResponseIIN_in_OContext(pOContext);

      NullUnsolicited_in_APDUBuilders_static(&response, pOContext->unsol.seq.num.seq, &temp);
//    void RestartUnsolConfirmTimer_in_OContext(OContext *pOContext);
////            this->RestartUnsolConfirmTimer();
      RestartUnsolConfirmTimer_in_OContext(pOContext);
//     OutstationState* Inst_in_StateNullUnsolicitedConfirmWait_static(void);
//     OutstationState* Inst_in_StateUnsolicitedConfirmWait_static(void);
////            this->state = this->params.noDefferedReadDuringUnsolicitedNullResponse
////                ? &StateNullUnsolicitedConfirmWait::Inst()
////                : &StateUnsolicitedConfirmWait::Inst();
      pOContext->state = pOContext->params.noDefferedReadDuringUnsolicitedNullResponse
                         ? Inst_in_StateNullUnsolicitedConfirmWait_static()
                         : Inst_in_StateUnsolicitedConfirmWait_static();

//   void BeginUnsolTx_in_OContext(OContext *pOContext, APDUResponse* response);
////            this->BeginUnsolTx(response);
      BeginUnsolTx_in_OContext(pOContext, &response);
    }
  }
}

////void OContext::CheckForUnsolicited()
void CheckForUnsolicited_in_OContext(OContext *pOContext)
{
//   boolean CanTransmit_in_OContext(OContext *pOContext);
////    if (this->shouldCheckForUnsolicited && this->CanTransmit() && this->state->IsIdle()
////        && this->params.allowUnsolicited)
  if (pOContext->shouldCheckForUnsolicited &&
      CanTransmit_in_OContext(pOContext) &&
      IsIdle_in_OutstationState(pOContext->state)
      && pOContext->params.allowUnsolicited)
  {
    pOContext->shouldCheckForUnsolicited = false;

////        if (this->unsol.completedNull)
    if (pOContext->unsol.completedNull)
    {
      // are there events to be reported?
//  boolean Intersects_in_ClassField(ClassField *pClassField, ClassField *other);
//    ClassField UnwrittenClassField_in_EventBuffer(EventBuffer *pEventBuffer);
////            if (this->params.unsolClassMask.Intersects(this->eventBuffer.UnwrittenClassField()))
      ClassField temp = UnwrittenClassField_in_EventBuffer(&(pOContext->eventBuffer));
      if (Intersects_in_ClassField(&(pOContext->params.unsolClassMask), &temp))
      {

//APDUResponse Start_in_TxBuffer(TxBuffer *pTxBuffer);
////                auto response = this->unsol.tx.Start();
        APDUResponse response = Start_in_TxBuffer(&(pOContext->unsol.tx));
//  HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////                auto writer = response.GetWriter();
        HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));

//   void Reset_in_NumRetries(NumRetries *pNumRetries);
////                this->unsolRetries.Reset();
        Reset_in_NumRetries(&(pOContext->unsolRetries));

//     void Unselect_in_EventBuffer(EventBuffer *pEventBuffer);
////                this->eventBuffer.Unselect();
        Unselect_in_EventBuffer(&(pOContext->eventBuffer));

//    void SelectAllByClass_in_EventBuffer(EventBuffer *pEventBuffer, ClassField* clazz);
////                this->eventBuffer.SelectAllByClass(this->params.unsolClassMask);
        SelectAllByClass_in_EventBuffer(&(pOContext->eventBuffer), &(pOContext->params.unsolClassMask));

//     boolean Load_in_EventBuffer(EventBuffer *pEventBuffer, HeaderWriter* writer);
////                this->eventBuffer.Load(writer);
        Load_in_EventBuffer(&(pOContext->eventBuffer), &writer);

//    void NullUnsolicited_in_APDUBuilders_static(APDUResponse* response, uint8_t seq, IINField* iin);
//    IINField GetResponseIIN_in_OContext(OContext *pOContext);
////                build::NullUnsolicited(response, this->unsol.seq.num, this->GetResponseIIN());
        IINField temp = GetResponseIIN_in_OContext(pOContext);
        NullUnsolicited_in_APDUBuilders_static(&response, pOContext->unsol.seq.num.seq, &temp);

//    void RestartUnsolConfirmTimer_in_OContext(OContext *pOContext);
////                this->RestartUnsolConfirmTimer();
        RestartUnsolConfirmTimer_in_OContext(pOContext);

//     OutstationState* Inst_in_StateSolicitedConfirmWait_static(void);
////                this->state = &StateUnsolicitedConfirmWait::Inst();
        pOContext->state =  Inst_in_StateSolicitedConfirmWait_static();
//   void BeginUnsolTx_in_OContext(OContext *pOContext, APDUResponse* response);
////                this->BeginUnsolTx(response);
        BeginUnsolTx_in_OContext(pOContext, &response);
      }
    }
  }
}

////bool OContext::ProcessDeferredRequest(const ParsedRequest& request)
boolean ProcessDeferredRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
  if (request->header.function == FunctionCode_CONFIRM)
  {
//    boolean ProcessConfirm_in_OContext(OContext *pOContext, ParsedRequest* request)
////        this->ProcessConfirm(request);
    ProcessConfirm_in_OContext(pOContext, request);
    return true;
  }

  if (request->header.function == FunctionCode_READ)
  {
//     boolean IsIdle_in_OutstationState(OutstationState *);
////        if (this->state->IsIdle())
    if (IsIdle_in_OutstationState(pOContext->state))
    {
//    boolean ProcessRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
////            this->ProcessRequest(request);
      ProcessRequest_in_OContext(pOContext, request);
      return true;
    }

    return false;
  }
  else
  {
////        this->ProcessRequest(request);
    ProcessRequest_in_OContext(pOContext, request);
    return true;
  }
}

void timeout_RestartSolConfirmTimer_in_OContext(void);

void timeout_RestartSolConfirmTimer_in_OContext(void)
{
//void* getParentPointer_in_OutstationState(OutstationState*);
//    OutstationState* OnConfirmTimeout_in_StateIdle_override(void* pOutstationState, void *pOContext);
////        this->state = &this->state->OnConfirmTimeout(*this);
  OutstationState* parent = (OutstationState*)getParentPointer_in_OutstationState(((OContext*)pPointerGlobal1)->state);
  ((OContext*)pPointerGlobal1)->state = (OutstationState*) OnConfirmTimeout_in_StateIdle_override((OutstationState*) parent, ((OContext*)pPointerGlobal1));
//    void CheckForTaskStart_in_OContext(OContext *pOContext);
////        this->CheckForTaskStart();
  CheckForTaskStart_in_OContext(((OContext*)pPointerGlobal1));
}

void RestartSolConfirmTimer_in_OContext(OContext *pOContext)
{
////    auto timeout = [&]() {
////        this->state = &this->state->OnConfirmTimeout(*this);
////        this->CheckForTaskStart();
////    };

////    this->confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(pOContext->confirmTimer));
////    this->confirmTimer = this->executor->start(this->params.solConfirmTimeout.value, timeout);
  pOContext->confirmTimer =  Start_in_IExecutorExe4cpp(pOContext->executor, pOContext->params.solConfirmTimeout.duration_value, timeout_RestartSolConfirmTimer_in_OContext);
}

void timeout_RestartUnsolConfirmTimer_in_OContext(void);

void timeout_RestartUnsolConfirmTimer_in_OContext(void)
{
//void* getParentPointer_in_OutstationState(OutstationState*);
//    OutstationState* OnConfirmTimeout_in_StateIdle_override(void* pOutstationState, void *pOContext);
////        this->state = &this->state->OnConfirmTimeout(*this);
  OutstationState* parent = (OutstationState*)getParentPointer_in_OutstationState(((OContext*)pPointerGlobal1)->state);
  ((OContext*)pPointerGlobal1)->state = (OutstationState*) OnConfirmTimeout_in_StateIdle_override((OutstationState*) parent, ((OContext*)pPointerGlobal1));
//    void CheckForTaskStart_in_OContext(OContext *pOContext);
////        this->CheckForTaskStart();
  CheckForTaskStart_in_OContext(((OContext*)pPointerGlobal1));
}
////void OContext::RestartUnsolConfirmTimer()
void RestartUnsolConfirmTimer_in_OContext(OContext *pOContext)
{
////    auto timeout = [&]() {
////        this->state = &this->state->OnConfirmTimeout(*this);
////        this->CheckForTaskStart();
////    };

////    this->confirmTimer.cancel();
  cancel_in_TimerExe4cpp(&(pOContext->confirmTimer));
//TimerExe4cpp Start_in_IExecutorExe4cpp(IExecutorExe4cpp *pIExecutorExe4cpp, uint32_t duration, void (*pAction)(void))
////    this->confirmTimer = this->executor->start(this->params.unsolConfirmTimeout.value, timeout);
  pOContext->confirmTimer =  Start_in_IExecutorExe4cpp(pOContext->executor, pOContext->params.unsolConfirmTimeout.duration_value, timeout_RestartUnsolConfirmTimer_in_OContext);
}

////OutstationState& OContext::RespondToNonReadRequest(const ParsedRequest& request)
OutstationState* RespondToNonReadRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RespondToNonReadRequest_in_OContext1"<<std::endl;
#endif
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

//pMemory_IINField_1 = MEMORY_IINField_1(0, &iin);

//    void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications);
//    IINField GetResponseIIN_in_OContext(OContext *pOContext);
//    IINField operatorOR_in_IINField(IINField *pIINField, IINField* aIIN);
////    response.SetIIN(iin | this->GetResponseIIN());
  IINField temp = GetResponseIIN_in_OContext(pOContext);

//pMemory_IINField_1 = MEMORY_IINField_1(0, &temp);

  IINField temp2 = operatorOR_in_IINField(&iin, &temp);

//pMemory_IINField_1 = MEMORY_IINField_1(0, &temp2);

  SetIIN_in_APDUResponse(&response, &temp2);

//   OutstationState* BeginResponseTx_in_OContext(OContext *pOContext, uint16_t destination, APDUResponse* response);
////    return this->BeginResponseTx(request.addresses.source, response);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return BeginResponseTx_in_OContext(pOContext, request->addresses.source, &response);
}

////OutstationState& OContext::RespondToReadRequest(const ParsedRequest& request)
OutstationState* RespondToReadRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RespondToReadRequest_in_OContext1"<<std::endl;
  decrement_stack_info();
#endif
//   void RecordLastProcessedRequest_in_RequestHistory(RequestHistory *pRequestHistory, APDUHeader* header, RSeq_for_Uint16_t* objects);
////    this->history.RecordLastProcessedRequest(request.header, request.objects);
  RecordLastProcessedRequest_in_RequestHistory(&(pOContext->history), &(request->header), &(request->objects));

////    auto response = this->sol.tx.Start();
  APDUResponse response = Start_in_TxBuffer(&(pOContext->sol.tx));

////    auto writer = response.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(response.aAPDUWrapper));
////    response.SetFunction(FunctionCode::RESPONSE);
  SetFunction_in_APDUWrapper(&(response.aAPDUWrapper), FunctionCode_RESPONSE);//FunctionCode_RESPONSE = 0x81,

//   PairSer4cpp_for_IINField_AppControlField HandleRead_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter writer)
////    auto result = this->HandleRead(request.objects, writer);
  PairSer4cpp_for_IINField_AppControlField result = HandleRead_in_OContext(pOContext, &(request->objects), &writer);

//pMemory_PairSer4cpp_for_IINField_AppControlField_1 = MEMORY_PairSer4cpp_for_IINField_AppControlField_1(0, &result);

  result.second.SEQ = request->header.control.SEQ;
//  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
////    response.SetControl(result.second);
  SetControl_in_APDUWrapper(&(response.aAPDUWrapper), result.second);
////    response.SetIIN(result.first | this->GetResponseIIN());
  IINField temp = GetResponseIIN_in_OContext(pOContext);

//pMemory_IINField_1 = MEMORY_IINField_1(0, &temp);

  IINField temp2 = operatorOR_in_IINField(&(result.first), &temp);

//pMemory_IINField_1 = MEMORY_IINField_1(0, &temp2);

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

////    control.SEQ = seq;
  control.SEQ = seq->seq;// *seq;
////    response.SetControl(control);
  SetControl_in_APDUWrapper(&(response.aAPDUWrapper), control);

//    void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications);
//    IINField GetResponseIIN_in_OContext(OContext *pOContext);
////    response.SetIIN(this->GetResponseIIN());
  IINField temp = GetResponseIIN_in_OContext(pOContext);
  SetIIN_in_APDUResponse(&response, &temp);

//   OutstationState* BeginResponseTx_in_OContext(OContext *pOContext, uint16_t destination, APDUResponse* response);
////    return this->BeginResponseTx(addresses.source, response);
  return BeginResponseTx_in_OContext(pOContext, addresses->source, &response);
}

boolean CanTransmit_in_OContext(OContext *pOContext)
{
  return pOContext->isOnline && !pOContext->isTransmitting;
}

////IINField OContext::GetResponseIIN()
IINField GetResponseIIN_in_OContext(OContext *pOContext)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"GetResponseIIN_in_OContext1"<<std::endl;
  decrement_stack_info();
#endif
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

void UpdateLastBroadcastMessageReceived_in_OContext(OContext *pOContext, uint16_t destination)
{
  switch (destination)
  {
  case LinkBroadcastAddress_DontConfirm:
  {
//void set_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress, uint16_t *value_);
////        lastBroadcastMessageReceived.set(LinkBroadcastAddress::DontConfirm);
    uint16_t temp = LinkBroadcastAddress_DontConfirm;
    set_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived), &temp);
  }
  break;
  case LinkBroadcastAddress_ShallConfirm:
  {
////        lastBroadcastMessageReceived.set(LinkBroadcastAddress::ShallConfirm);
    uint16_t temp = LinkBroadcastAddress_ShallConfirm;
    set_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived), &temp);
  }
  break;
  case LinkBroadcastAddress_OptionalConfirm:
  {
////        lastBroadcastMessageReceived.set(LinkBroadcastAddress::OptionalConfirm);
    uint16_t temp = LinkBroadcastAddress_OptionalConfirm;
    set_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived), &temp);
  }
  break;
  default:
//void clear_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress);
////        lastBroadcastMessageReceived.clear();
    clear_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived));
  }
}

void CheckForBroadcastConfirmation_in_OContext(OContext *pOContext, APDUResponse* response)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"CheckForBroadcastConfirmation_in_OContext1"<<std::endl;
#endif
//boolean is_set_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress);
////    if (lastBroadcastMessageReceived.is_set())
  if (is_set_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived)))
  {
//    void SetIIN_in_APDUResponse(APDUResponse *pAPDUResponse, IINField *indications);
//    IINField GetIIN_in_APDUResponse(APDUResponse *pAPDUResponse);
//   void IINField_in_IINFieldOver2(IINField *pIINField, IINBit_uint8_t bit);
//    IINField operatorOR_in_IINField(IINField *pIINField, IINField* aIIN);
////        response.SetIIN(response.GetIIN() | IINField(IINBit::BROADCAST));
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_BROADCAST);
    IINField temp2 = GetIIN_in_APDUResponse(response);

    IINField temp = operatorOR_in_IINField(&temp2, &iIINField);
    SetIIN_in_APDUResponse(response, &temp);

//uint16_t get_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress);
////        if (lastBroadcastMessageReceived.get() != LinkBroadcastAddress::ShallConfirm)
    if (get_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived)) != LinkBroadcastAddress_ShallConfirm)
    {
//void clear_in_Settable_for_LinkBroadcastAddress(Settable_for_LinkBroadcastAddress *pSettable_for_LinkBroadcastAddress);
////            lastBroadcastMessageReceived.clear();
      clear_in_Settable_for_LinkBroadcastAddress(&(pOContext->lastBroadcastMessageReceived));
    }
    else
    {
      // The broadcast address requested a confirmation
//  AppControlField GetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////            auto control = response.GetControl();
      AppControlField control = GetControl_in_APDUWrapper(&(response->aAPDUWrapper));
      control.CON = true;
//  void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
////            response.SetControl(control);
      SetControl_in_APDUWrapper(&(response->aAPDUWrapper), control);
    }
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

boolean ProcessMessage_in_OContext(OContext *pOContext, Message* message)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessMessage_in_OContext1"<<std::endl;
#endif
  // is the message addressed to this outstation
//    boolean IsBroadcast_in_Addresses(Addresses *pAddresses);
////    if (message.addresses.destination != this->addresses.source && !message.addresses.IsBroadcast())
  if (message->addresses.destination != pOContext->addresses.source && !IsBroadcast_in_Addresses(&(message->addresses)))////!message->addresses.IsBroadcast())
  {
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return false;
  }

  // is the message coming from the expected master?
  if (!pOContext->params.respondToAnyMaster && (message->addresses.source != pOContext->addresses.destination))
  {
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return false;
  }

////    FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FORMAT_HEX_BLOCK(this->logger, flags::APP_HEX_RX, message.payload, 18, 18)"<<std::endl;
#endif

////    if (message.addresses.IsBroadcast())
  if (IsBroadcast_in_Addresses(&(message->addresses)))
  {
//   void UpdateLastBroadcastMessageReceived_in_OContext(OContext *pOContext, uint16_t destination);
////        UpdateLastBroadcastMessageReceived(message.addresses.destination);
    UpdateLastBroadcastMessageReceived_in_OContext(pOContext, message->addresses.destination);
  }

//    Result_for_APDUHeader_in_APDUHeaderParser         ParseRequest_in_APDUHeaderParser_static(RSeq_for_Uint16_t *apdu);////, Logger* logger = nullptr);
////    const auto result = APDUHeaderParser::ParseRequest(message.payload, &this->logger);
  Result_for_APDUHeader_in_APDUHeaderParser result = ParseRequest_in_APDUHeaderParser_static(&(message->payload));

//pMemory_Result_for_APDUHeader_in_APDUHeaderParser_1 = MEMORY_Result_for_APDUHeader_in_APDUHeaderParser_1(0, &result);

  if (!result.success)
  {
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return false;
  }

////    logging::LogHeader(this->logger, flags::APP_HEADER_RX, result.header);

//  boolean IsFirAndFin_in_AppControlField(AppControlField *);
////    if (!result.header.control.IsFirAndFin())
  if (!IsFirAndFin_in_AppControlField(&(result.header.control)))
  {
////        SIMPLE_LOG_BLOCK(this->logger, flags::WARN, "Ignoring fragment. Requests must have FIR/FIN == 1");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(this->logger, flags::WARN, 'Ignoring fragment. Requests must have FIR/FIN == 1')"<<std::endl;
    decrement_stack_info();
#endif
    return false;
  }

  if (result.header.control.CON)
  {
////        SIMPLE_LOG_BLOCK(this->logger, flags::WARN, "Ignoring fragment. Requests cannot request confirmation");
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(this->logger, flags::WARN, 'Ignoring fragment. Requests cannot request confirmation')"<<std::endl;
    decrement_stack_info();
#endif
    return false;
  }

//    boolean ProcessObjects_in_OContext(OContext *pOContext, ParsedRequest* request);
//  void  ParsedRequest_in_ParsedRequest(ParsedRequest *pParsedRequest, Addresses* addresses, APDUHeader* header, RSeq_for_Uint16_t* objects);
////    return this->ProcessObjects(ParsedRequest(message.addresses, result.header, result.objects));
  ParsedRequest pParsedRequest;
  ParsedRequest_in_ParsedRequest(&pParsedRequest, &(message->addresses), &(result.header), &(result.objects));

  return ProcessObjects_in_OContext(pOContext, &pParsedRequest);
}

void HandleNewEvents_in_OContext(OContext *pOContext)
{
  pOContext->shouldCheckForUnsolicited = true;
////    this->CheckForTaskStart();
  CheckForTaskStart_in_OContext(pOContext);
}

void SetRestartIIN_in_OContext(OContext *pOContext)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SetRestartIIN_in_OContext1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IINBit_DEVICE_RESTART"<<std::endl;
  decrement_stack_info();
#endif
//    void SetBit_in_IINField(IINField *, IINBit_uint8_t bit);
////    this->staticIIN.SetBit(IINBit::DEVICE_RESTART);
  SetBit_in_IINField(&(pOContext->staticIIN), IINBit_DEVICE_RESTART);
}

IUpdateHandler* GetUpdateHandler_in_OContext(OContext *pOContext)
{
  return &(pOContext->database.iIUpdateHandler);
}

//// ----------------------------- function handlers -----------------------------

////bool OContext::ProcessBroadcastRequest(const ParsedRequest& request)
boolean ProcessBroadcastRequest_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessBroadcastRequest_in_OContext1"<<std::endl;
#endif

  switch (request->header.function)
  {
  case (FunctionCode_WRITE):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_WRITE"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleWrite_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        this->HandleWrite(request.objects);
    HandleWrite_in_OContext(pOContext, &(request->objects));
    return true;
  case (FunctionCode_DIRECT_OPERATE_NR):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_DIRECT_OPERATE_NR"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter);
////        this->HandleDirectOperate(request.objects, OperateType::DirectOperateNoAck, nullptr);
    HandleDirectOperate_in_OContext(pOContext, &(request->objects), OperateType_DirectOperateNoAck, NULL);
    return true;
  case (FunctionCode_IMMED_FREEZE_NR):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_IMMED_FREEZE_NR"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleFreeze_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        this->HandleFreeze(request.objects);
    HandleFreeze_in_OContext(pOContext, &(request->objects));
    return true;
  case (FunctionCode_FREEZE_CLEAR_NR):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_FREEZE_CLEAR_NR"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleFreezeAndClear_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        this->HandleFreezeAndClear(request.objects);
    HandleFreezeAndClear_in_OContext(pOContext, &(request->objects));
    return true;
  case (FunctionCode_ASSIGN_CLASS):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_ASSIGN_CLASS"<<std::endl;
    decrement_stack_info();
#endif
//     boolean SupportsAssignClass_in_IOutstationApplication(IOutstationApplication*);
////        if (this->application->SupportsAssignClass())
    if (SupportsAssignClass_in_IOutstationApplication(pOContext->application))
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
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_RECORD_CURRENT_TIME"<<std::endl;
    decrement_stack_info();
#endif
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
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_DISABLE_UNSOLICITED"<<std::endl;
    decrement_stack_info();
#endif
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
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_ENABLE_UNSOLICITED"<<std::endl;
    decrement_stack_info();
#endif
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
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Ignoring broadcast on function code: %s'"<<std::endl;
    decrement_stack_info();
#endif
    return false;
  }
}

////bool OContext::ProcessRequestNoAck(const ParsedRequest& request)
boolean ProcessRequestNoAck_in_OContext(OContext *pOContext, ParsedRequest* request)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ProcessRequestNoAck_in_OContext1"<<std::endl;
#endif

  switch (request->header.function)
  {
  case (FunctionCode_DIRECT_OPERATE_NR):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_DIRECT_OPERATE_NR"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter)
////        this->HandleDirectOperate(request.objects, OperateType::DirectOperateNoAck,
////                                  nullptr); // no object writer, this is a no ack code
    HandleDirectOperate_in_OContext(pOContext, &(request->objects), OperateType_DirectOperateNoAck, NULL);
    return true;
  case (FunctionCode_IMMED_FREEZE_NR):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_IMMED_FREEZE_NR"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleFreeze_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
////        this->HandleFreeze(request.objects);
    HandleFreeze_in_OContext(pOContext, &(request->objects));
    return true;
  case (FunctionCode_FREEZE_CLEAR_NR):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_FREEZE_CLEAR_NR"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleFreezeAndClear_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
////        this->HandleFreezeAndClear(request.objects);
    HandleFreezeAndClear_in_OContext(pOContext, &(request->objects));
    return true;
  default:
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Ignoring NR function code: %s",
////                         FunctionCodeSpec::to_human_string(request.header.function));
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Ignoring NR function code: %s'"<<std::endl;
    decrement_stack_info();
#endif
    return false;
  }
}

////IINField OContext::HandleNonReadResponse(const APDUHeader& header, const ser4cpp::rseq_t& objects, HeaderWriter& writer)
IINField HandleNonReadResponse_in_OContext(OContext *pOContext, APDUHeader* header, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleNonReadResponse_in_OContext1"<<std::endl;
#endif
  switch (header->function)
  {
  case (FunctionCode_WRITE):
//   IINField HandleWrite_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleWrite(objects);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_WRITE"<<std::endl;
    decrement_stack_info();
#endif
    return HandleWrite_in_OContext(pOContext, objects);
  case (FunctionCode_SELECT):
//   IINField HandleSelect_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////        return this->HandleSelect(objects, writer);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_SELECT"<<std::endl;
    decrement_stack_info();
#endif
    return HandleSelect_in_OContext(pOContext, objects, writer);
  case (FunctionCode_OPERATE):
//   IINField HandleOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////        return this->HandleOperate(objects, writer);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_OPERATE"<<std::endl;
    decrement_stack_info();
#endif
    return HandleOperate_in_OContext(pOContext, objects, writer);
  case (FunctionCode_DIRECT_OPERATE):
//   IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter);
////        return this->HandleDirectOperate(objects, OperateType::DirectOperate, &writer);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_DIRECT_OPERATE"<<std::endl;
    decrement_stack_info();
#endif
    return HandleDirectOperate_in_OContext(pOContext, objects, OperateType_DirectOperate, writer);
  case (FunctionCode_COLD_RESTART):
//   IINField HandleRestart_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, boolean isWarmRestart, HeaderWriter* pWriter);
////        return this->HandleRestart(objects, false, &writer);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_COLD_RESTART"<<std::endl;
    decrement_stack_info();
#endif
    return HandleRestart_in_OContext(pOContext, objects, false, writer);
  case (FunctionCode_WARM_RESTART):
////        return this->HandleRestart(objects, true, &writer);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_WARM_RESTART"<<std::endl;
    decrement_stack_info();
#endif
    return HandleRestart_in_OContext(pOContext, objects, true, writer);
  case (FunctionCode_ASSIGN_CLASS):
//   IINField HandleAssignClass_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleAssignClass(objects);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_ASSIGN_CLASS"<<std::endl;
    decrement_stack_info();
#endif
    return HandleAssignClass_in_OContext(pOContext, objects);
  case (FunctionCode_DELAY_MEASURE):
//   IINField HandleDelayMeasure_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
////        return this->HandleDelayMeasure(objects, writer);
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_DELAY_MEASURE"<<std::endl;
    decrement_stack_info();
#endif
    return HandleDelayMeasure_in_OContext(pOContext, objects, writer);
  case (FunctionCode_RECORD_CURRENT_TIME):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_RECORD_CURRENT_TIME"<<std::endl;
    decrement_stack_info();
#endif
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
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_DISABLE_UNSOLICITED"<<std::endl;

    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*IINBit_FUNC_NOT_SUPPORTED"<<std::endl;
    decrement_stack_info();
#endif

    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
//   IINField HandleDisableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
    return pOContext->params.allowUnsolicited ? ////this->HandleDisableUnsolicited(objects, &writer)
           HandleDisableUnsolicited_in_OContext(pOContext, objects, writer)
           : iIINField;////IINField(IINBit::FUNC_NOT_SUPPORTED);
  }
  case (FunctionCode_ENABLE_UNSOLICITED):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_ENABLE_UNSOLICITED"<<std::endl;

    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*IINBit_FUNC_NOT_SUPPORTED"<<std::endl;
    decrement_stack_info();
#endif

    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
//   IINField HandleEnableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer);
    return pOContext->params.allowUnsolicited ? ////this->HandleEnableUnsolicited(objects, &writer)
           HandleEnableUnsolicited_in_OContext(pOContext, objects, writer)
           : iIINField;////IINField(IINBit::FUNC_NOT_SUPPORTED);
  }
  case (FunctionCode_IMMED_FREEZE):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_IMMED_FREEZE"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleFreeze_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleFreeze(objects);
    return HandleFreeze_in_OContext(pOContext, objects);
  case (FunctionCode_FREEZE_CLEAR):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FunctionCode_FREEZE_CLEAR"<<std::endl;
    decrement_stack_info();
#endif
//   IINField HandleFreezeAndClear_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects);
////        return this->HandleFreezeAndClear(objects);
    return HandleFreezeAndClear_in_OContext(pOContext, objects);
  default:
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*IINBit_FUNC_NOT_SUPPORTED"<<std::endl;
    decrement_stack_info();
#endif
////       return IINField(IINBit::FUNC_NOT_SUPPORTED);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
  }
  }
}

////ser4cpp::Pair<IINField, AppControlField> OContext::HandleRead(const ser4cpp::rseq_t& objects, HeaderWriter& writer)
PairSer4cpp_for_IINField_AppControlField HandleRead_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleRead_in_OContext1"<<std::endl;
  inspect_RSeq(objects);
#endif

// void Reset_in_ResponseContext(ResponseContext *pResponseContext);
////    this->rspContext.Reset();
  Reset_in_ResponseContext(&(pOContext->rspContext));
//     void Unselect_in_EventBuffer(EventBuffer *pEventBuffer);
////    this->eventBuffer.Unselect(); // always un-select any previously selected points when we start a new read request
  Unselect_in_EventBuffer(&(pOContext->eventBuffer));
//    void Unselect_in_Database(Database *pDatabase);
////    this->database.Unselect();
  Unselect_in_Database(&(pOContext->database));

//void  ReadHandler_in_ReadHandler(ReadHandler *pReadHandler, IStaticSelector* staticSelector, IEventSelector* eventSelector);
////    ReadHandler handler(this->database, this->eventBuffer);
  ReadHandler handler;
  ReadHandler_in_ReadHandler(&handler, &(pOContext->database.iIStaticSelector), &(pOContext->eventBuffer.iIEventSelector));
//    ParseResult_uint8_t Parse_in_APDUParser_static(
//                             RSeq_for_Uint16_t *buffer,
//                             IAPDUHandler *handler);
////    auto result = APDUParser::Parse(objects, handler, &this->logger,
////                                    ParserSettings::NoContents()); // don't expect range/count context on a READ
//не ожидайте контекста диапазона/счета при „“≈Ќ»»

  ParseResult_uint8_t result = Parse_in_APDUParser_static(
                                 objects,
                                 &(handler.iIAPDUHandler));
  if (result == ParseResult_OK)
  {
////        auto control = pOContext->rspContext.LoadResponse(writer);
    AppControlField control = LoadResponse_in_ResponseContext(&(pOContext->rspContext), writer);
//void PairSer4cpp_for_IINField_AppControlField_in_PairSer4cpp_for_IINField_AppControlField(PairSer4cpp_for_IINField_AppControlField *pPairSer4cpp_for_IINField_AppControlField,
//                                                                           IINField *first_,
//                                                                           AppControlField *second_
//                                                                           );
//  IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
////        return ser4cpp::Pair<IINField, AppControlField>(handler.Errors(), control);
    IINField temp = Errors_in_IAPDUHandler(&(handler.iIAPDUHandler));

    PairSer4cpp_for_IINField_AppControlField pPairSer4cpp_for_IINField_AppControlField;
    PairSer4cpp_for_IINField_AppControlField_in_PairSer4cpp_for_IINField_AppControlField(&pPairSer4cpp_for_IINField_AppControlField,
        &temp,
        &control);

    return pPairSer4cpp_for_IINField_AppControlField;
  }

// void Reset_in_ResponseContext(ResponseContext *pResponseContext);
////    this->rspContext.Reset();
  Reset_in_ResponseContext(&(pOContext->rspContext));
//  void AppControlField_in_AppControlFieldOver3(AppControlField *, boolean fir, boolean fin, boolean con, boolean uns);
////    return ser4cpp::Pair<IINField, AppControlField>(IINFromParseResult(result),
////                                                    AppControlField(true, true, false, false));
  IINField temp = IINFromParseResult(result);
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver3(&aAppControlField, true, true, false, false);

  PairSer4cpp_for_IINField_AppControlField pPairSer4cpp_for_IINField_AppControlField;
  PairSer4cpp_for_IINField_AppControlField_in_PairSer4cpp_for_IINField_AppControlField(&pPairSer4cpp_for_IINField_AppControlField,
      &temp,
      &aAppControlField);

#ifdef  LOG_INFO
  decrement_stack_info();
#endif

  return pPairSer4cpp_for_IINField_AppControlField;
}

////IINField OContext::HandleWrite(const ser4cpp::rseq_t& objects)
IINField HandleWrite_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleWrite_in_OContext1"<<std::endl;
#endif
//Timestamp Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *);
//void WriteHandler_in_WriteHandler(WriteHandler *pWriteHandler,
//    IOutstationApplication* application, TimeSyncState* timeSyncState, AppSeqNum seq, Timestamp now, IINField* writeIIN)
////    WriteHandler handler(*this->application, this->time, this->sol.seq.num, Timestamp(this->executor->get_time()),
////                         &this->staticIIN);
  uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(&(pOContext->executor->iISteadyTimeSourceExe4cpp));
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, temp);

  WriteHandler handler;
  WriteHandler_in_WriteHandler(&handler,
                               pOContext->application, &(pOContext->timeTimeSyncState), pOContext->sol.seq.num, tTimestamp, &(pOContext->staticIIN));

//    ParseResult_uint8_t Parse_in_APDUParser_static(
//                             RSeq_for_Uint16_t *buffer,
//                             IAPDUHandler *handler);
////    auto result = APDUParser::Parse(objects, handler, &this->logger);
  ParseResult_uint8_t result = Parse_in_APDUParser_static(
                                 objects,
                                 &(handler.iIAPDUHandler));

#ifdef  LOG_INFO
  decrement_stack_info();
#endif

////    return (result == ParseResult::OK) ? handler.Errors() : IINFromParseResult(result);
  return (result == ParseResult_OK) ?
//  IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
         ////handler.Errors()
         Errors_in_IAPDUHandler(&(handler.iIAPDUHandler)) :
//IINField IINFromParseResult(ParseResult_uint8_t result);
////                  IINFromParseResult(result);
         IINFromParseResult(result);
}

////IINField OContext::HandleDirectOperate(const ser4cpp::rseq_t& objects, OperateType opType, HeaderWriter* pWriter)
IINField HandleDirectOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, OperateType_uint8_t opType, HeaderWriter* pWriter)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleDirectOperate_in_OContext1"<<std::endl;
#endif
  // since we're echoing, make sure there's enough size before beginning
// поскольку мы повтор€ем эхо, перед началом убедитесь, что размера достаточно
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
  CommandActionAdapter_in_CommandActionAdapter(&adapter, pOContext->commandHandler, false, &(pOContext->database.iIUpdateHandler), opType);

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
                                 &(handler.iIAPDUHandler));

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
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleSelect_in_OContext1"<<std::endl;
#endif
  // since we're echoing, make sure there's enough size before beginning
// поскольку мы повтор€ем эхо, перед началом убедитесь, что размера достаточно
////    if (objects.length() > writer.Remaining())
  if (length_in_HasLength_for_Uint16_t(&(objects->hHasLength)) > Remaining_in_HeaderWriter(writer))
  {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Igonring command request due to oversized payload size of %zu",
////                         objects.length());
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Igonring command request due to oversized payload size of %zu'"<<std::endl;
    decrement_stack_info();
#endif
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
                                 &(handler.iIAPDUHandler));

  if (result == ParseResult_OK)
  {
//    boolean AllCommandsSuccessful_in_CommandResponseHandler(CommandResponseHandle *pCommandResponseHandle);
////        if (handler.AllCommandsSuccessful())
    if (AllCommandsSuccessful_in_CommandResponseHandler(&handler))
    {
//void Select_in_ControlState(ControlState *pControlState,  AppSeqNum* currentSeqN, Timestamp* now, RSeq_for_Uint16_t* objects);
//Timestamp Get_time_in_ISteadyTimeSourceExe4cpp(ISteadyTimeSourceExe4cpp *);
// void Timestamp_in_TimestampOver2(Timestamp *pTimestamp, uint64_t value);
////            this->control.Select(this->sol.seq.num, Timestamp(this->executor->get_time()), objects);
//uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(pOContext->executor);
      uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(&(pOContext->executor->iISteadyTimeSourceExe4cpp));
      Timestamp tTimestamp;
      Timestamp_in_TimestampOver2(&tTimestamp, temp);
      Select_in_ControlState(&(pOContext->control), &(pOContext->sol.seq.num), &tTimestamp, objects);
    }

#ifdef  LOG_INFO
    decrement_stack_info();
#endif

////        return handler.Errors();
    return Errors_in_IAPDUHandler(&(handler.iIAPDUHandler));
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return IINFromParseResult(result);
}

IINField HandleOperate_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleOperate_in_OContext1"<<std::endl;
#endif
// since we're echoing, make sure there's enough size before beginning
// поскольку мы повтор€ем эхо, перед началом убедитесь, что размера достаточно
////    if (objects.length() > writer.Remaining())
  if (length_in_HasLength_for_Uint16_t(&(objects->hHasLength)) > Remaining_in_HeaderWriter(writer))
  {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Igonring command request due to oversized payload size of %zu",
////                         objects.length());
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Igonring command request due to oversized payload size of %zu'"<<std::endl;
    decrement_stack_info();
#endif
////        return IINField(IINBit::PARAM_ERROR);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

////    auto now = Timestamp(this->executor->get_time());
//uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(pOContext->executor);
  uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(&(pOContext->executor->iISteadyTimeSourceExe4cpp));
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
                                   &(handler.iIAPDUHandler));

    pOContext->shouldCheckForUnsolicited = true;

#ifdef  LOG_INFO
    decrement_stack_info();
#endif

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
  return HandleCommandWithConstant_in_OContext(pOContext, objects, writer, result);
}

////IINField OContext::HandleDelayMeasure(const ser4cpp::rseq_t& objects, HeaderWriter& writer)
IINField HandleDelayMeasure_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
  UNUSED(pOContext);
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
//uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(pOContext->executor);
  uint64_t temp = Get_time_in_ISteadyTimeSourceExe4cpp(&(pOContext->executor->iISteadyTimeSourceExe4cpp));
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, temp);
  RecordCurrentTime_in_TimeSyncState(&(pOContext->timeTimeSyncState), &(pOContext->sol.seq.num), &tTimestamp);
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////IINField OContext::HandleRestart(const ser4cpp::rseq_t& objects, bool isWarmRestart, HeaderWriter* pWriter)
IINField HandleRestart_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, boolean isWarmRestart, HeaderWriter* pWriter)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleRestart_in_OContext1"<<std::endl;
#endif
//    boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
////    if (objects.is_not_empty())
  if (is_not_empty_in_HasLength_for_Uint16_t(&(objects->hHasLength)))
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*IINBit_PARAM_ERROR"<<std::endl;
    decrement_stack_info();
#endif
////        return IINField(IINBit::PARAM_ERROR);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

//    RestartMode_uint8_t WarmRestartSupport_in_IOutstationApplication(IOutstationApplication*);
//    RestartMode_uint8_t ColdRestartSupport_in_IOutstationApplication(IOutstationApplication*);
////    auto mode = isWarmRestart ? this->application->WarmRestartSupport() : this->application->ColdRestartSupport();
  RestartMode_uint8_t mode = isWarmRestart ?
                             WarmRestartSupport_in_IOutstationApplication(pOContext->application) :
                             ColdRestartSupport_in_IOutstationApplication(pOContext->application);

  switch (mode)
  {
  case (RestartMode_UNSUPPORTED):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*IINBit_FUNC_NOT_SUPPORTED"<<std::endl;
    decrement_stack_info();
#endif
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
  }
  case (RestartMode_SUPPORTED_DELAY_COARSE):
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*RestartMode_SUPPORTED_DELAY_COARSE"<<std::endl;
#endif
//    uint16_t WarmRestart_in_IOutstationApplication(IOutstationApplication*);
//    uint16_t ColdRestart_in_IOutstationApplication(IOutstationApplication*);
////        auto delay = isWarmRestart ? this->application->WarmRestart() : this->application->ColdRestart();
    uint16_t delay = isWarmRestart ?
                     WarmRestart_in_IOutstationApplication(pOContext->application):
                     ColdRestart_in_IOutstationApplication(pOContext->application);
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

#ifdef  LOG_INFO
    decrement_stack_info();
#endif

////        return IINField::Empty();
    return Empty_in_IINField_static();
  }
  default:
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"HandleRestart_in_OContext7"<<std::endl;
#endif
////        auto delay = isWarmRestart ? this->application->WarmRestart() : this->application->ColdRestart();
    uint16_t delay = isWarmRestart ?
                     WarmRestart_in_IOutstationApplication(pOContext->application):
                     ColdRestart_in_IOutstationApplication(pOContext->application);
    if (pWriter)
    {
      Group52Var2 fine;
      Group52Var2_in_Group52Var2(&fine);
      fine.time_uint16_t = delay;
////            pWriter->WriteSingleValue<ser4cpp::UInt8>(QualifierCode::UINT8_CNT, fine);
      WriteSingleValue_for_UInt8_Group52Var2_in_HeaderWriter(pWriter,
          QualifierCode_UINT8_CNT, &fine);
    }
////        return IINField::Empty();
    return Empty_in_IINField_static();
  }
  }
}

////IINField OContext::HandleAssignClass(const ser4cpp::rseq_t& objects)
IINField HandleAssignClass_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleAssignClass_in_OContext1"<<std::endl;
#endif
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

#ifdef  LOG_INFO
    decrement_stack_info();
#endif

////        return (result == ParseResult::OK) ? handler.Errors() : IINFromParseResult(result);
    return (result == ParseResult_OK) ?
//  IINField Errors_in_IAPDUHandler(IAPDUHandler *pIAPDUHandler);
           ////handler.Errors()
           Errors_in_IAPDUHandler(&(handler.iIAPDUHandler)) :
//IINField IINFromParseResult(ParseResult_uint8_t result);
////                  IINFromParseResult(result);
           IINFromParseResult(result);
  }

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*IINBit_FUNC_NOT_SUPPORTED"<<std::endl;

  decrement_stack_info();
#endif

////    return IINField(IINBit::FUNC_NOT_SUPPORTED);
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
  return iIINField;
}

////IINField OContext::HandleDisableUnsolicited(const ser4cpp::rseq_t& objects, HeaderWriter* /*writer*/)
IINField HandleDisableUnsolicited_in_OContext(OContext *pOContext, RSeq_for_Uint16_t* objects, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleDisableUnsolicited_in_OContext1"<<std::endl;
  decrement_stack_info();
#endif
  UNUSED(writer);

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
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleEnableUnsolicited_in_OContext1"<<std::endl;
  decrement_stack_info();
#endif
  UNUSED(writer);

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
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleCommandWithConstant_in_OContext1"<<std::endl;
  decrement_stack_info();
#endif
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
#ifdef  LOG_INFO
  std::cout<<""<<std::endl;
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HandleFreezeAndClear_in_OContext1"<<std::endl;
  decrement_stack_info();
#endif
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
