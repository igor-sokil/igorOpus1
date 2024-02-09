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
#include <QApplication>
#include "header.h"
#include "MasterContext.h"

#include "APDUBuilders.h"
//#include "app/APDULogging.h"
#include "APDUHeaderParser.h"
#include "Group12.h"
#include "Group41.h"
///#include "logging/LogMacros.h"
#include "CommandTask.h"
#include "EmptyResponseTask.h"
#include "MeasurementHandler.h"
#include "RestartOperationTask.h"
#include "UserPollTask.h"
#include "HeaderWriter_for_TimeAndInterval.h"

///#include "opendnp3/logging/LogLevels.h"

////#include <utility>

static MContext mMContext;

////namespace opendnp3
////{
////MContext::MContext(const Addresses& addresses,
////                   const Logger& logger,
////                   const std::shared_ptr<exe4cpp::IExecutor>& executor,
////                   std::shared_ptr<ILowerLayer> lower,
////                   const std::shared_ptr<ISOEHandler>& SOEHandler,
////                   const std::shared_ptr<IMasterApplication>& application,
////                   std::shared_ptr<IMasterScheduler> scheduler,
////                   const MasterParams& params)
void  MContext_in_MContext(MContext *pMContext,
                           Addresses* addresses,
//             const Logger& logger,
                           IExecutorExe4cpp* executor,
                           ILowerLayer* lower,
                           ISOEHandler* SOEHandler,
                           IMasterApplication* application,
                           IMasterScheduler* scheduler,
                           MasterParams* params)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{MContext_in_MContext1"<<'\n';
#endif
  pMContext->pOnParsedHeader_in_MContext = OnParsedHeader_in_MContext_override;
  pMContext->pRecordLastRequest_in_MContext = RecordLastRequest_in_MContext_override;
  setParentPointer_in_MContext(pMContext, pMContext);

  pMContext->iIMasterTaskRunner.pRun_in_IMasterTaskRunner = Run_in_MContext_override;
  setParentPointer_in_IMasterTaskRunner(&(pMContext->iIMasterTaskRunner), pMContext);


////    : logger(logger),
  pMContext->executor = executor;
  pMContext->lower = lower;
  pMContext->addresses = *addresses;
  pMContext->params = *params;
  pMContext->SOEHandler = SOEHandler;
  pMContext->application = application;
  pMContext->scheduler = scheduler;

//void MasterTasks_in_MasterTasks(MasterTasks *pMasterTasks,
//                                MasterParams* params,
///                const Logger& logger,
//                                IMasterApplication* application,
//                                ISOEHandler* SOEHandler);
////      tasks(params, logger, *application, SOEHandler),
  MasterTasks_in_MasterTasks(&(pMContext->tasks),
                             params,
///                const Logger& logger,
                             application,
                             SOEHandler);

//void BufferSer4_in_BufferSer4Over2(BufferSer4 *pBufferSer4, uint16_t length);
////      txBuffer(params.maxTxFragSize),
  BufferSer4_in_BufferSer4Over2(&(pMContext->txBuffer), params->maxTxFragSize);

  pMContext->tstate = TaskState_in_MContext_IDLE;

  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pMContext->solSeq));
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over1(&(pMContext->unsolSeq));

  TimerExe4cpp_in_TimerExe4cppOver1(&(pMContext->responseTimer));

  pMContext->isOnline = false;
  pMContext->isSending = false;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}MContext_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

////std::shared_ptr<MContext> MContext::Create(
////    const Addresses& addresses,
////    const Logger& logger,
////    const std::shared_ptr<exe4cpp::IExecutor>& executor,
////    std::shared_ptr<ILowerLayer> lower,
////    const std::shared_ptr<ISOEHandler>& SOEHandler,
////    const std::shared_ptr<IMasterApplication>& application,
////    std::shared_ptr<IMasterScheduler> scheduler,
////    const MasterParams& params)
MContext* Create_in_MContext_static(
  Addresses* addresses,
////        const Logger& logger,
  IExecutorExe4cpp* executor,
  ILowerLayer* lower,
  ISOEHandler* SOEHandler,
  IMasterApplication* application,
  IMasterScheduler* scheduler,
  MasterParams* params
)
{
////    return std::shared_ptr<MContext>(new MContext(addresses, logger, executor, lower, SOEHandler, application, scheduler, params));
  MContext_in_MContext(&mMContext,
                       addresses,
//             const Logger& logger,
                       executor,
                       lower,
                       SOEHandler,
                       application,
                       scheduler,
                       params);
  return &mMContext;
}

////bool MContext::OnLowerLayerUp()
boolean OnLowerLayerUp_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnLowerLayerUp_in_MContext1"<<'\n';
#endif

  if (pMContext->isOnline)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnLowerLayerUp_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pMContext->isOnline = true;

//void Initialize_in_MasterTasks(MasterTasks *pMasterTasks, IMasterScheduler* scheduler, IMasterTaskRunner* runner);
////    tasks.Initialize(*this->scheduler, *this);
  Initialize_in_MasterTasks(&(pMContext->tasks), pMContext->scheduler, &(pMContext->iIMasterTaskRunner));

//void OnOpen_in_IMasterApplication(IMasterApplication* pIMasterApplication);
///    this->application->OnOpen();
  OnOpen_in_IMasterApplication(pMContext->application);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnLowerLayerUp_in_MContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool MContext::OnLowerLayerDown()
boolean OnLowerLayerDown_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnLowerLayerDown_in_MContext1"<<'\n';
#endif
  if (!pMContext->isOnline)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnLowerLayerDown_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pMContext->tstate = TaskState_in_MContext_IDLE;

//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    responseTimer.cancel();
  cancel_in_TimerExe4cpp(&(pMContext->responseTimer));

//void SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16, uint8_t value)
////    solSeq = unsolSeq = 0;
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(&(pMContext->solSeq), 0);
  SequenceNum_for_uint8_Modulus16_in_SequenceNum_for_uint8_Modulus16Over2(&(pMContext->unsolSeq), 0);

  pMContext->isOnline = pMContext->isSending = false;

////    activeTask.reset();//call destructor

//void SetRunnerOffline_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTaskRunner* runner);
////    this->scheduler->SetRunnerOffline(*this);
  SetRunnerOffline_in_IMasterScheduler(pMContext->scheduler, &(pMContext->iIMasterTaskRunner));

////    this->application->OnClose();
  OnClose_in_IMasterApplication(pMContext->application);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnLowerLayerDown_in_MContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool MContext::OnReceive(const Message& message)
boolean OnReceive_in_MContext(MContext *pMContext, Message* message)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnReceive_in_MContext1"<<'\n';
#endif
  if (!pMContext->isOnline)
  {
////        SIMPLE_LOG_BLOCK(this->logger, flags::ERR, "Ignorning rx data while offline");
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(this->logger, flags::ERR, 'Ignorning rx data while offline')"<<'\n';
    std::cout<<getString_stack_info();
    std::cout<<"}OnReceive_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (message->addresses.destination != pMContext->addresses.source)
  {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Unknown destination address: %u", message.addresses.destination);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Unknown destination address: %u', message.addresses.destination)"<<'\n';
    std::cout<<getString_stack_info();
    std::cout<<"}OnReceive_in_MContext2_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  if (message->addresses.source != pMContext->addresses.destination)
  {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Unexpected message source: %u", message.addresses.source);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Unexpected message source: %u', message.addresses.source)"<<'\n';
    std::cout<<getString_stack_info();
    std::cout<<"}OnReceive_in_MContext3_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

//Result_for_APDUResponseHeader_in_APDUHeaderParser ParseResponse_in_APDUHeaderParser_static(RSeq_for_Uint16_t *apdu);////, Logger* logger = nullptr);
////    const auto result = APDUHeaderParser::ParseResponse(message.payload, &this->logger);
  Result_for_APDUResponseHeader_in_APDUHeaderParser result =
    ParseResponse_in_APDUHeaderParser_static(&(message->payload));////, Logger* logger = nullptr);
  if (!result.success)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnReceive_in_MContext4_"<<'\n';
    decrement_stack_info();
#endif
    return true;
  }

////    logging::LogHeader(this->logger, flags::APP_HEADER_RX, result.header);

//    void OnParsedHeader_in_MContext(MContext *pMContext,
//                                    RSeq_for_Uint16_t* apdu,
//                                 APDUResponseHeader* header,
//                                RSeq_for_Uint16_t* objects);
////    this->OnParsedHeader(message.payload, result.header, result.objects);
  OnParsedHeader_in_MContext(pMContext,
                             &(message->payload),
                             &(result.header),
                             &(result.objects));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnReceive_in_MContext5_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool MContext::OnTxReady()
boolean OnTxReady_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnTxReady_in_MContext1"<<'\n';
#endif
  if (!pMContext->isOnline || !pMContext->isSending)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnTxReady_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pMContext->isSending = false;

//    TaskState_in_MContext_uint8_t OnTransmitComplete_in_MContext(MContext *pMContext);
////    this->tstate = this->OnTransmitComplete();
  pMContext->tstate = OnTransmitComplete_in_MContext(pMContext);

//    boolean CheckConfirmTransmit_in_MContext(MContext *pMContext);
////    this->CheckConfirmTransmit();
  CheckConfirmTransmit_in_MContext(pMContext);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnTxReady_in_MContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////void MContext::OnResponseTimeout()
void OnResponseTimeout_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnResponseTimeout_in_MContext1"<<'\n';
#endif
  if (pMContext->isOnline)
  {
//    TaskState_in_MContext_uint8_t OnResponseTimeoutEvent_in_MContext(MContext *pMContext);
////        this->tstate = this->OnResponseTimeoutEvent();
    pMContext->tstate = OnResponseTimeoutEvent_in_MContext(pMContext);
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnResponseTimeout_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

////void MContext::CompleteActiveTask()
void CompleteActiveTask_in_MContext(MContext *pMContext)
{
  if (pMContext->activeTask)
  {
////        this->activeTask.reset();//destructor
//boolean CompleteCurrentFor_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTaskRunner* runner);
////        this->scheduler->CompleteCurrentFor(*this);
    CompleteCurrentFor_in_IMasterScheduler(pMContext->scheduler, &(pMContext->iIMasterTaskRunner));
  }
}

////void MContext::OnParsedHeader(const ser4cpp::rseq_t& /*apdu*/,
////                              const APDUResponseHeader& header,
////                              const ser4cpp::rseq_t& objects)
void OnParsedHeader_in_MContext(MContext *pMContext,
                                RSeq_for_Uint16_t* apdu,
                                APDUResponseHeader* header,
                                RSeq_for_Uint16_t* objects)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnParsedHeader_in_MContext1"<<'\n';
#endif
  UNUSED(apdu);
  // Note: this looks silly, but OnParsedHeader() is virtual and can be overriden to do SA
// Примечание: это выглядит глупо, но OnParsedHeader() является виртуальным и его можно переопределить для выполнения SA
//    void ProcessAPDU_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
////    this->ProcessAPDU(header, objects);
  ProcessAPDU_in_MContext(pMContext, header, objects);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}OnParsedHeader_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

/// --- command handlers ----

////void MContext::DirectOperate(CommandSet&& commands, const CommandResultCallbackT& callback, const TaskConfig& config)
void DirectOperate_in_MContext(MContext *pMContext, CommandSet* commands, CommandResultCallbackT callback, TaskConfig config)
{
//Timestamp operatorPLUS_in_Timestamp(Timestamp *pTimestamp, TimeDuration* duration);
//void Timestamp_in_TimestampOver2(Timestamp *pTimestamp, uint64_t value);
//uint64_t get_time_in_IExecutorExe4cpp(IExecutorExe4cpp *);
////    const auto timeout = Timestamp(this->executor->get_time()) + params.taskStartTimeout;
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
  Timestamp timeout = operatorPLUS_in_Timestamp(&tTimestamp, &(pMContext->params.taskStartTimeout));

//    IMasterTask* CreateDirectOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
//                                                            CommandSet* set,
//                                                            IndexQualifierMode_uint8_t mode,
//                                                            IMasterApplication* app,
//                                                            CommandResultCallbackT callback,
//                                                            Timestamp* startExpiration,
//                                                            TaskConfig* config);
//    void ScheduleAdhocTask_in_MContext(MContext *pMContext, IMasterTask* task);
////    this->ScheduleAdhocTask(CommandTask::CreateDirectOperate(this->tasks.context, std::move(commands),
////                                                             this->params.controlQualifierMode, *application, callback,
////                                                             timeout, config, logger));
  IMasterTask* tmp = CreateDirectOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
                       commands,
                       pMContext->params.controlQualifierMode,
                       pMContext->application,
                       callback,
                       &timeout,
                       &config);
  ScheduleAdhocTask_in_MContext(pMContext, tmp);//Запланировать специальную задачу
}

////void MContext::SelectAndOperate(CommandSet&& commands, const CommandResultCallbackT& callback, const TaskConfig& config)
void SelectAndOperate_in_MContext(MContext *pMContext, CommandSet* commands, CommandResultCallbackT callback, TaskConfig* config)
{
////    const auto timeout = Timestamp(this->executor->get_time()) + params.taskStartTimeout;
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
  Timestamp timeout = operatorPLUS_in_Timestamp(&tTimestamp, &(pMContext->params.taskStartTimeout));

//void ScheduleAdhocTask_in_MContext(MContext *pMContext, IMasterTask* task);
//    IMasterTask* CreateSelectAndOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
//                                                               CommandSet* set,
//                                                               IndexQualifierMode_uint8_t mode,
//                                                               IMasterApplication* app,
//                                                               CommandResultCallbackT callback,
//                                                               Timestamp* startExpiration,
//                                                               TaskConfig* config);
////    this->ScheduleAdhocTask(CommandTask::CreateSelectAndOperate(this->tasks.context, std::move(commands),
////                                                                this->params.controlQualifierMode, *application,
////                                                                callback, timeout, config, logger));
  IMasterTask* tmp = CreateSelectAndOperate_in_CommandTask_static(//const std::shared_ptr<TaskContext>& context,
                       commands,
                       pMContext->params.controlQualifierMode,
                       pMContext->application,
                       callback,
                       &timeout,
                       config);
  ScheduleAdhocTask_in_MContext(pMContext, tmp);//Запланировать специальную задачу
}

////void MContext::ProcessAPDU(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects)
void ProcessAPDU_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessAPDU_in_MContext1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*header->aAPDUHeader.function= "<<(uint16_t)header->aAPDUHeader.function<<'\n';
  inspect_RSeq(objects);
#endif
  switch (header->aAPDUHeader.function)
  {
  case (FunctionCode_UNSOLICITED_RESPONSE):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@@@@FunctionCode_UNSOLICITED_RESPONSE"<<'\n';
#endif
//    void ProcessUnsolicitedResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
////        this->ProcessUnsolicitedResponse(header, objects);
    ProcessUnsolicitedResponse_in_MContext(pMContext, header, objects);
    break;
  case (FunctionCode_RESPONSE):
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@@@@FunctionCode_RESPONSE"<<'\n';
#endif
//    void ProcessResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
////        this->ProcessResponse(header, objects);
    ProcessResponse_in_MContext(pMContext, header, objects);
    break;
  default:
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Ignoring unsupported function code: %s",
////                         FunctionCodeSpec::to_human_string(header.function));
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Ignoring unsupported function code: %s'"<<'\n';
#endif
    break;
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessAPDU_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

////void MContext::ProcessIIN(const IINField& iin)
void ProcessIIN_in_MContext(MContext *pMContext, IINField* iin)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessIIN_in_MContext1"<<'\n';
  inspect_IINField(iin);
#endif
//boolean IsSet_in_IINField(IINField *, IINBit_uint8_t bit);
////    if (iin.IsSet(IINBit::DEVICE_RESTART) && !this->params.ignoreRestartIIN)
  if (IsSet_in_IINField(iin, IINBit_DEVICE_RESTART)  && !pMContext->params.ignoreRestartIIN)
  {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ProcessIIN_in_MContext2"<<'\n';
#endif
//void OnRestartDetected_in_MasterTasks(MasterTasks *pMasterTasks);
////        this->tasks.OnRestartDetected();
    OnRestartDetected_in_MasterTasks(&(pMContext->tasks));
//void Evaluate_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler);
////        this->scheduler->Evaluate(); //Оценивать
    Evaluate_in_IMasterScheduler(pMContext->scheduler);
  }

////    if (iin.IsSet(IINBit::EVENT_BUFFER_OVERFLOW) && this->params.integrityOnEventOverflowIIN)
  if (IsSet_in_IINField(iin, IINBit_EVENT_BUFFER_OVERFLOW)  && pMContext->params.integrityOnEventOverflowIIN)
  {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ProcessIIN_in_MContext3"<<'\n';
#endif
//boolean DemandIntegrity_in_MasterTasks(MasterTasks *pMasterTasks);
////        if (this->tasks.DemandIntegrity())
////            this->scheduler->Evaluate();
    if (DemandIntegrity_in_MasterTasks(&(pMContext->tasks)))
      Evaluate_in_IMasterScheduler(pMContext->scheduler);
  }

////    if (iin.IsSet(IINBit::NEED_TIME))
  if (IsSet_in_IINField(iin, IINBit_NEED_TIME))
  {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ProcessIIN_in_MContext4"<<'\n';
#endif
////        if (this->tasks.DemandTimeSync())
////            this->scheduler->Evaluate();
    if (DemandTimeSync_in_MasterTasks(&(pMContext->tasks)))
      Evaluate_in_IMasterScheduler(pMContext->scheduler);
  }

//boolean HasClass1_in_ClassField(ClassField *pClassField);
////    if ((iin.IsSet(IINBit::CLASS1_EVENTS) && this->params.eventScanOnEventsAvailableClassMask.HasClass1())
////        || (iin.IsSet(IINBit::CLASS2_EVENTS) && this->params.eventScanOnEventsAvailableClassMask.HasClass2())
////        || (iin.IsSet(IINBit::CLASS3_EVENTS) && this->params.eventScanOnEventsAvailableClassMask.HasClass3()))
  if ((IsSet_in_IINField(iin, IINBit_CLASS1_EVENTS) &&
       HasClass1_in_ClassField(&(pMContext->params.eventScanOnEventsAvailableClassMask)))
      || (IsSet_in_IINField(iin, IINBit_CLASS2_EVENTS) &&
          HasClass2_in_ClassField(&(pMContext->params.eventScanOnEventsAvailableClassMask)))
      || (IsSet_in_IINField(iin, IINBit_CLASS3_EVENTS) &&
          HasClass3_in_ClassField(&(pMContext->params.eventScanOnEventsAvailableClassMask))))
  {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*ProcessIIN_in_MContext5"<<'\n';
#endif
////        if (this->tasks.DemandEventScan())
////            this->scheduler->Evaluate();
    if (DemandEventScan_in_MasterTasks(&(pMContext->tasks)))
      Evaluate_in_IMasterScheduler(pMContext->scheduler);
  }

//void OnReceiveIIN_in_IMasterApplication(IMasterApplication *pIMasterApplication, IINField* iin);
////    this->application->OnReceiveIIN(iin);
  OnReceiveIIN_in_IMasterApplication(pMContext->application, iin);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessIIN_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

////void MContext::ProcessUnsolicitedResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects)
void ProcessUnsolicitedResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  if (!header->aAPDUHeader.control.UNS)
  {
////        SIMPLE_LOG_BLOCK(logger, flags::WARN, "Ignoring unsolicited response without UNS bit set");
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::WARN, 'Ignoring unsolicited response without UNS bit set')"<<'\n';
    decrement_stack_info();
#endif
    return;
  }

//ParseResult_uint8_t ProcessMeasurements_in_MeasurementHandler_static(ResponseInfo info,
//    RSeq_for_Uint16_t* objects,
////                                           Logger& logger,
//    ISOEHandler* pHandler);
//ResponseInfo as_response_info_in_APDUResponseHeader(APDUResponseHeader *pAPDUResponseHeader);
////    auto result = MeasurementHandler::ProcessMeasurements(header.as_response_info(), objects, logger, SOEHandler.get());
  ParseResult_uint8_t result = ProcessMeasurements_in_MeasurementHandler_static(as_response_info_in_APDUResponseHeader(header),
                               objects,
////                                           Logger& logger,
                               pMContext->SOEHandler);

  if ((result == ParseResult_OK) && header->aAPDUHeader.control.CON)
  {
//APDUHeader UnsolicitedConfirm_in_APDUHeader(uint8_t seq);
//    void QueueConfirm_in_MContext(MContext *pMContext, APDUHeader* header);
////        this->QueueConfirm(APDUHeader::UnsolicitedConfirm(header.control.SEQ));
    APDUHeader tmp = UnsolicitedConfirm_in_APDUHeader(header->aAPDUHeader.control.SEQ);
    QueueConfirm_in_MContext(pMContext, &tmp);
  }

//   void ProcessIIN_in_MContext(MContext *pMContext, IINField* iin)
////    this->ProcessIIN(header.IIN);
  ProcessIIN_in_MContext(pMContext, &(header->IIN));
}

////void MContext::ProcessResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects)
void ProcessResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ProcessResponse_in_MContext1"<<'\n';
  inspect_IINField(&(header->IIN));
#endif
//    TaskState_in_MContext_uint8_t OnResponseEvent_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
////    this->tstate = this->OnResponseEvent(header, objects);
  pMContext->tstate = OnResponseEvent_in_MContext(pMContext, header, objects);
//void ProcessIIN_in_MContext(MContext *pMContext, IINField* iin);
////    this->ProcessIIN(header.IIN); // TODO - should we process IIN bits for unexpected responses?
  ProcessIIN_in_MContext(pMContext, &(header->IIN));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ProcessResponse_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

////void MContext::QueueConfirm(const APDUHeader& header)
void QueueConfirm_in_MContext(MContext *pMContext, APDUHeader* header)
{
//    std::deque<APDUHeader> confirmQueue;
  pMContext->confirmQueue.push_back(*header);
//    boolean CheckConfirmTransmit_in_MContext(MContext *pMContext);
////    this->CheckConfirmTransmit();
  CheckConfirmTransmit_in_MContext(pMContext);
}

////bool MContext::CheckConfirmTransmit()
boolean CheckConfirmTransmit_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{CheckConfirmTransmit_in_MContext1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pMContext->isSending= "<<(uint16_t)pMContext->isSending<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pMContext->confirmQueue.empty()= "<<(uint16_t)pMContext->confirmQueue.empty()<<'\n';
#endif
  if (pMContext->isSending || pMContext->confirmQueue.empty())
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}CheckConfirmTransmit_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  APDUHeader confirm = pMContext->confirmQueue.front();

//WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);
//void APDUWrapper_in_APDUWrapperOver2(APDUWrapper *pAPDUWrapper, WSeq_for_Uint16_t *buffer);
////    APDUWrapper wrapper(this->txBuffer.as_wslice());
  WSeq_for_Uint16_t wtmp = as_wslice_in_BufferSer4(&(pMContext->txBuffer));
  APDUWrapper wrapper;
  APDUWrapper_in_APDUWrapperOver2(&wrapper, &wtmp);

//void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
////    wrapper.SetFunction(confirm.function);
  SetFunction_in_APDUWrapper(&wrapper, confirm.function);

////    wrapper.SetControl(confirm.control);
  SetControl_in_APDUWrapper(&wrapper, confirm.control);

//    void Transmit_in_MContext(MContext *pMContext, RSeq_for_Uint16_t* data);
//RSeq_for_Uint16_t ToRSeq_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    this->Transmit(wrapper.ToRSeq());
  RSeq_for_Uint16_t rtmp = ToRSeq_in_APDUWrapper(&wrapper);
  Transmit_in_MContext(pMContext, &rtmp);

  pMContext->confirmQueue.pop_front();
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}CheckConfirmTransmit_in_MContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////void MContext::Transmit(const ser4cpp::rseq_t& data)
void Transmit_in_MContext(MContext *pMContext, RSeq_for_Uint16_t* data)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Transmit_in_MContext1"<<'\n';
#endif
////    logging::ParseAndLogRequestTx(this->logger, data);
////    assert(!this->isSending);
  pMContext->isSending = true;

//void  Message_in_Message(Message *pMessage, Addresses *addresses, RSeq_for_Uint16_t* payload);
//boolean BeginTransmit_in_ILowerLayer(ILowerLayer *, Message* message);
////    this->lower->BeginTransmit(Message(this->addresses, data));
  Message mMessage;
  Message_in_Message(&mMessage, &(pMContext->addresses), data);
  BeginTransmit_in_ILowerLayer(pMContext->lower, &mMessage);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Transmit_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

void timeout_in_MContext(void);
void timeout_in_MContext(void)
{
//    void OnResponseTimeout_in_MContext(MContext *pMContext);
////    auto timeout = [self = shared_from_this()]() { self->OnResponseTimeout(); };
  MContext* pMContext = (MContext*)pPointerGlobal1;
  OnResponseTimeout_in_MContext(pMContext);
}
////void MContext::StartResponseTimer()
void StartResponseTimer_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{StartResponseTimer_in_MContext1"<<'\n';
#endif
////    auto timeout = [self = shared_from_this()]() { self->OnResponseTimeout(); };
//TimerExe4cpp Start_in_IExecutorExe4cpp(IExecutorExe4cpp *, uint32_t duration, void (*pAction)(void));
////    this->responseTimer = this->executor->start(this->params.responseTimeout.value, timeout);
  pPointerGlobal1 = pMContext;
  pMContext->responseTimer = Start_in_IExecutorExe4cpp(pMContext->executor, pMContext->params.responseTimeout.duration_value, timeout_in_MContext);//void (*pAction)(void));
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}StartResponseTimer_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
}

static UserPollTask uUserPollTask;
////std::shared_ptr<IMasterTask> MContext::AddScan(TimeDuration period,
////                                               const HeaderBuilderT& builder,
////                                               std::shared_ptr<ISOEHandler> soe_handler,
////                                               TaskConfig config)
IMasterTask* AddScan_in_MContext(MContext *pMContext,
                                 TimeDuration period,
                                 HeaderBuilderT builder,
                                 ISOEHandler* soe_handler,
                                 TaskConfig config)// = TaskConfig::Default());
{
//TaskBehavior ImmediatePeriodic_in_TaskBehavior_static(TimeDuration* period,
//                                           TimeDuration* minRetryDelay,
//                                           TimeDuration* maxRetryDelay);
//void UserPollTask_in_UserPollTask(UserPollTask *pUserPollTask,
//                 TaskContext* context,
//                                  HeaderBuilderT builder,
//                                  TaskBehavior* behavior,
//                                  boolean recurring,//повторяющийся
//                                  IMasterApplication* app,
//                                  ISOEHandler* soeHandler,
////                 const Logger& logger,
//                                  TaskConfig config);
////    auto task = std::make_shared<UserPollTask>(
////        this->tasks.context, builder,
////        TaskBehavior::ImmediatePeriodic(period, params.taskRetryPeriod, params.maxTaskRetryPeriod), true, *application,
////        soe_handler, logger, config);
  TaskBehavior tmp = ImmediatePeriodic_in_TaskBehavior_static(&period,
                     &(pMContext->params.taskRetryPeriod),
                     &(pMContext->params.maxTaskRetryPeriod));
  UserPollTask_in_UserPollTask(&uUserPollTask,
//                 TaskContext* context,
                               builder,
                               &tmp,
                               true,
                               pMContext->application,
                               soe_handler,
////                 const Logger& logger,
                               config);

//   void ScheduleRecurringPollTask_in_MContext(MContext *pMContext, IMasterTask* task);
/////    this->ScheduleRecurringPollTask(task);
  ScheduleRecurringPollTask_in_MContext(pMContext, &(uUserPollTask.pPollTaskBase.iIMasterTask));
  return &(uUserPollTask.pPollTaskBase.iIMasterTask);////task;
}

//typedef boolean (*HeaderBuilderT)(HeaderWriter*);
boolean builder_in_AddClassScan(HeaderWriter*);
boolean builder_in_AddClassScan(HeaderWriter* writer)
{
  ClassField *field = (ClassField*)pPointerGlobal1;
//boolean WriteClassHeaders_in_APDUBuilders_static(HeaderWriter* writer, ClassField* classes)
////    auto build = [field](HeaderWriter& writer) -> bool { return build::WriteClassHeaders(writer, field); };
  return WriteClassHeaders_in_APDUBuilders_static(writer, field);
}
////std::shared_ptr<IMasterTask> MContext::AddClassScan(const ClassField& field,
////                                                    TimeDuration period,
////                                                    std::shared_ptr<ISOEHandler> soe_handler,
////                                                    TaskConfig config)
IMasterTask* AddClassScan_in_MContext(MContext *pMContext,
                                      ClassField* field,
                                      TimeDuration period,
                                      ISOEHandler* soe_handler,
                                      TaskConfig config)// = TaskConfig::Default());
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{AddClassScan_in_MContext1"<<'\n';
#endif
////    auto build = [field](HeaderWriter& writer) -> bool { return build::WriteClassHeaders(writer, field); };
//    IMasterTask* AddScan_in_MContext(MContext *pMContext,
//                              TimeDuration period,
//                                         HeaderBuilderT builder,
//                                         ISOEHandler* soe_handler,
//                                         TaskConfig config)// = TaskConfig::Default());
////    return this->AddScan(period, build, soe_handler, config);
  pPointerGlobal1 = field;
  IMasterTask* tmp = AddScan_in_MContext(pMContext,
                             period,
//typedef boolean (*HeaderBuilderT)(HeaderWriter*);
                             builder_in_AddClassScan,
                             soe_handler,
                             config);// = TaskConfig::Default());
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}AddClassScan_in_MContext_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

boolean builder_in_AddAllObjectsScan(HeaderWriter*);
boolean builder_in_AddAllObjectsScan(HeaderWriter* writer)
{
  GroupVariationID *gvId = (GroupVariationID*)pPointerGlobal1;
//boolean WriteHeader_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc);
////    auto build = [gvId](HeaderWriter& writer) -> bool { return writer.WriteHeader(gvId, QualifierCode::ALL_OBJECTS); };
  return WriteHeader_in_HeaderWriter(writer, *gvId, QualifierCode_ALL_OBJECTS);
}
////std::shared_ptr<IMasterTask> MContext::AddAllObjectsScan(GroupVariationID gvId,
////                                                         TimeDuration period,
////                                                         std::shared_ptr<ISOEHandler> soe_handler,
////                                                         TaskConfig config)
IMasterTask* AddAllObjectsScan_in_MContext(MContext *pMContext,
    GroupVariationID gvId,
    TimeDuration period,
    ISOEHandler* soe_handler,
    TaskConfig config)// = TaskConfig::Default());
{
////    auto build = [gvId](HeaderWriter& writer) -> bool { return writer.WriteHeader(gvId, QualifierCode::ALL_OBJECTS); };
////    return this->AddScan(period, build, soe_handler, config);
  pPointerGlobal1 = &gvId;
  return AddScan_in_MContext(pMContext,
                             period,
//typedef boolean (*HeaderBuilderT)(HeaderWriter*);
                             builder_in_AddAllObjectsScan,
                             soe_handler,
                             config);// = TaskConfig::Default());
}

boolean builder_in_AddRangeScan(HeaderWriter*);
boolean builder_in_AddRangeScan(HeaderWriter* writer)
{
  GroupVariationID *gvId = (GroupVariationID*)pPointerGlobal1;
  uint16_t *start = (uint16_t*)pPointerGlobal2;
  uint16_t *stop  = (uint16_t*)pPointerGlobal3;
//boolean WriteRangeHeader_for_UInt16_in_HeaderWriter(HeaderWriter *pHeaderWriter, QualifierCode_uint8_t qc,
//                                    GroupVariationID gvId,
//                                    int16_t start,
//                                    int16_t stop);
////    auto build = [gvId, start, stop](HeaderWriter& writer) -> bool {
////        return writer.WriteRangeHeader<ser4cpp::UInt16>(QualifierCode::UINT16_START_STOP, gvId, start, stop);
////    };
  return WriteRangeHeader_for_UInt16_in_HeaderWriter(writer, QualifierCode_UINT16_START_STOP,
         *gvId,
         *start,
         *stop);
}
////std::shared_ptr<IMasterTask> MContext::AddRangeScan(GroupVariationID gvId,
////                                                    uint16_t start,
////                                                    uint16_t stop,
////                                                    TimeDuration period,
////                                                    std::shared_ptr<ISOEHandler> soe_handler,
////                                                    TaskConfig config)
IMasterTask* AddRangeScan_in_MContext(MContext *pMContext,
                                      GroupVariationID gvId,
                                      uint16_t start,
                                      uint16_t stop,
                                      TimeDuration period,
                                      ISOEHandler* soe_handler,
                                      TaskConfig config)// = TaskConfig::Default());
{
////    auto build = [gvId, start, stop](HeaderWriter& writer) -> bool {
////        return writer.WriteRangeHeader<ser4cpp::UInt16>(QualifierCode::UINT16_START_STOP, gvId, start, stop);
////    };
////    return this->AddScan(period, build, soe_handler, config);
  pPointerGlobal1 = &gvId;
  pPointerGlobal2 = &start;
  pPointerGlobal3 = &stop;
  return AddScan_in_MContext(pMContext,
                             period,
//typedef boolean (*HeaderBuilderT)(HeaderWriter*);
                             builder_in_AddRangeScan,
                             soe_handler,
                             config);// = TaskConfig::Default());
}

////void MContext::Scan(const HeaderBuilderT& builder, std::shared_ptr<ISOEHandler> soe_handler, TaskConfig config)
void Scan_in_MContext(MContext *pMContext,
                      HeaderBuilderT builder,
                      ISOEHandler* soe_handler,
                      TaskConfig config)// = TaskConfig::Default());
{
////    const auto timeout = Timestamp(this->executor->get_time()) + params.taskStartTimeout;
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
  Timestamp timeout = operatorPLUS_in_Timestamp(&tTimestamp, &(pMContext->params.taskStartTimeout));

//TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_staticOver2(Timestamp* startExpiration);
//void UserPollTask_in_UserPollTask(UserPollTask *pUserPollTask,
//                 TaskContext* context,
//                                  HeaderBuilderT builder,
//                                  TaskBehavior* behavior,
//                                  boolean recurring,//повторяющийся
//                                  IMasterApplication* app,
//                                  ISOEHandler* soeHandler,
////                 const Logger& logger,
//                                  TaskConfig config);
////    auto task
////        = std::make_shared<UserPollTask>(this->tasks.context, builder, TaskBehavior::SingleExecutionNoRetry(timeout),
////                                         false, *application, soe_handler, logger, config);
  TaskBehavior tmp = SingleExecutionNoRetry_in_TaskBehavior_staticOver2(&timeout);
  UserPollTask_in_UserPollTask(&uUserPollTask,
//                TaskContext* context,
                               builder,
                               &tmp,
                               false,//повторяющийся
                               pMContext->application,
                               soe_handler,
////                 const Logger& logger,
                               config);

//    void ScheduleAdhocTask_in_MContext(MContext *pMContext, IMasterTask* task);
////    this->ScheduleAdhocTask(task);
  ScheduleAdhocTask_in_MContext(pMContext, &(uUserPollTask.pPollTaskBase.iIMasterTask));
}

boolean configure_in_ScanClasses(HeaderWriter*);
boolean configure_in_ScanClasses(HeaderWriter* writer)
{
  ClassField *field = (ClassField*)pPointerGlobal1;
////    auto configure = [field](HeaderWriter& writer) -> bool { return build::WriteClassHeaders(writer, field); };
  return WriteClassHeaders_in_APDUBuilders_static(writer, field);
}
GroupVariationID *gvId = (GroupVariationID*)pPointerGlobal1;
////void MContext::ScanClasses(const ClassField& field, std::shared_ptr<ISOEHandler> soe_handler, TaskConfig config)
void ScanClasses_in_MContext(MContext *pMContext,
                             ClassField* field,
                             ISOEHandler* soe_handler,
                             TaskConfig config)// = TaskConfig::Default());
{
////    auto configure = [field](HeaderWriter& writer) -> bool { return build::WriteClassHeaders(writer, field); };
  pPointerGlobal1 = field;
//    void Scan_in_MContext(MContext *pMContext,
//         HeaderBuilderT builder,
//              ISOEHandler* soe_handler,
//              TaskConfig config)// = TaskConfig::Default());
////    this->Scan(configure, soe_handler, config);
  Scan_in_MContext(pMContext,
                   configure_in_ScanClasses,
                   soe_handler,
                   config);// = TaskConfig::Default());
}

boolean configure_in_ScanAllObjects(HeaderWriter*);
boolean configure_in_ScanAllObjects(HeaderWriter* writer)
{
  GroupVariationID *gvId = (GroupVariationID*)pPointerGlobal1;
//boolean WriteHeader_in_HeaderWriter(HeaderWriter *pHeaderWriter, GroupVariationID id, QualifierCode_uint8_t qc);
////    auto configure
////        = [gvId](HeaderWriter& writer) -> bool { return writer.WriteHeader(gvId, QualifierCode::ALL_OBJECTS); };
  return WriteHeader_in_HeaderWriter(writer, *gvId, QualifierCode_ALL_OBJECTS);
}
////void MContext::ScanAllObjects(GroupVariationID gvId, std::shared_ptr<ISOEHandler> soe_handler, TaskConfig config)
void ScanAllObjects_in_MContext(MContext *pMContext,
                                GroupVariationID gvId,
                                ISOEHandler* soe_handler,
                                TaskConfig config)// = TaskConfig::Default());
{
////    auto configure
////        = [gvId](HeaderWriter& writer) -> bool { return writer.WriteHeader(gvId, QualifierCode::ALL_OBJECTS); };
  pPointerGlobal1 = &gvId;
////    this->Scan(configure, soe_handler, config);
  Scan_in_MContext(pMContext,
                   configure_in_ScanAllObjects,
                   soe_handler,
                   config);// = TaskConfig::Default());
}

boolean configure_in_ScanRange(HeaderWriter*);
boolean configure_in_ScanRange(HeaderWriter* writer)
{
  GroupVariationID *gvId = (GroupVariationID*)pPointerGlobal1;
  uint16_t *start = (uint16_t*)pPointerGlobal2;
  uint16_t *stop = (uint16_t*)pPointerGlobal3;
////    auto configure = [gvId, start, stop](HeaderWriter& writer) -> bool {
////        return writer.WriteRangeHeader<ser4cpp::UInt16>(QualifierCode::UINT16_START_STOP, gvId, start, stop);
////    };
  return WriteRangeHeader_for_UInt16_in_HeaderWriter(writer, QualifierCode_UINT16_START_STOP,
         *gvId,
         *start,
         *stop);
}
////void MContext::ScanRange(
////    GroupVariationID gvId, uint16_t start, uint16_t stop, std::shared_ptr<ISOEHandler> soe_handler, TaskConfig config)
void ScanRange_in_MContext(MContext *pMContext,
                           GroupVariationID gvId,
                           uint16_t start,
                           uint16_t stop,
                           ISOEHandler* soe_handler,
                           TaskConfig config)// = TaskConfig::Default());
{
////    auto configure = [gvId, start, stop](HeaderWriter& writer) -> bool {
////        return writer.WriteRangeHeader<ser4cpp::UInt16>(QualifierCode::UINT16_START_STOP, gvId, start, stop);
////    };
  pPointerGlobal1 = &gvId;
  pPointerGlobal2 = &start;
  pPointerGlobal3 = &stop;
////    this->Scan(configure, soe_handler, config);
  Scan_in_MContext(pMContext,
                   configure_in_ScanRange,
                   soe_handler,
                   config);// = TaskConfig::Default());
}

static EmptyResponseTask eEmptyResponseTask;

boolean builder_in_Write_in_MContext(HeaderWriter* writer);
boolean builder_in_Write_in_MContext(HeaderWriter* writer)
{
  TimeAndInterval *value = (TimeAndInterval*)pPointerGlobal1;
  uint16_t *index = (uint16_t*)pPointerGlobal2;

//DNP3Serializer_for_TimeAndInterval  Inst_in_Group50Var4_static(void);
//boolean WriteSingleIndexedValue_for_UInt16_TimeAndInterval_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc,
//    DNP3Serializer_for_TimeAndInterval* serializer,
//    TimeAndInterval* value,
//    uint16_t index);
////    auto builder = [value, index](HeaderWriter& writer) -> bool {
////        return writer.WriteSingleIndexedValue<ser4cpp::UInt16, TimeAndInterval>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                                Group50Var4::Inst(), value, index);
////    };
  DNP3Serializer_for_TimeAndInterval tmp = Inst_in_Group50Var4_static();
  return WriteSingleIndexedValue_for_UInt16_TimeAndInterval_in_HeaderWriter(writer,
         QualifierCode_UINT16_CNT_UINT16_INDEX,
         &tmp,
         value,
         *index);
}
////void MContext::Write(const TimeAndInterval& value, uint16_t index, TaskConfig config)
void Write_in_MContext(MContext *pMContext, TimeAndInterval* value, uint16_t index, TaskConfig config)// = TaskConfig::Default());
{
////    auto builder = [value, index](HeaderWriter& writer) -> bool {
////        return writer.WriteSingleIndexedValue<ser4cpp::UInt16, TimeAndInterval>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                                Group50Var4::Inst(), value, index);
////    };

////    const auto timeout = Timestamp(this->executor->get_time()) + params.taskStartTimeout;
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
  Timestamp timeout = operatorPLUS_in_Timestamp(&tTimestamp, &(pMContext->params.taskStartTimeout));

  pPointerGlobal1 = value;
  pPointerGlobal2 = &index;
////    auto task = std::make_shared<EmptyResponseTask>(this->tasks.context, *this->application, "WRITE TimeAndInterval",
////                                                    FunctionCode::WRITE, builder, timeout, this->logger, config);
  EmptyResponseTask_in_EmptyResponseTask(&eEmptyResponseTask,
                                         //const std::shared_ptr<TaskContext>& context,
                                         pMContext->application,
                                         //std::string name,
                                         FunctionCode_WRITE,
                                         builder_in_Write_in_MContext,
                                         timeout,
                                         //const Logger& logger,
                                         &config);

////    this->ScheduleAdhocTask(task);
  ScheduleAdhocTask_in_MContext(pMContext, &(eEmptyResponseTask.iIMasterTask));
}

static RestartOperationTask rRestartOperationTask;

////void MContext::Restart(RestartType op, const RestartOperationCallbackT& callback, TaskConfig config)
void Restart_in_MContext(MContext *pMContext, RestartType_uint8_t op, RestartOperationCallbackT callback, TaskConfig config)// = TaskConfig::Default())
{
////    const auto timeout = Timestamp(this->executor->get_time()) + params.taskStartTimeout;
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
  Timestamp timeout = operatorPLUS_in_Timestamp(&tTimestamp, &(pMContext->params.taskStartTimeout));

////    auto task = std::make_shared<RestartOperationTask>(this->tasks.context, *this->application, timeout, op, callback,
////                                                       this->logger, config);
  RestartOperationTask_in_RestartOperationTask(&rRestartOperationTask,
      //const std::shared_ptr<TaskContext>& context,
      pMContext->application,
      &timeout,
      op,
      callback,
      //const Logger& logger,
      &config);

////    this->ScheduleAdhocTask(task);
  ScheduleAdhocTask_in_MContext(pMContext, &(rRestartOperationTask.iIMasterTask));
}

////void MContext::PerformFunction(const std::string& name,
////                               FunctionCode func,
////                               const HeaderBuilderT& builder,
////                               TaskConfig config)
void PerformFunction_in_MContext(MContext *pMContext, //std::string& name,
                                 FunctionCode_uint8_t func,
                                 HeaderBuilderT builder,
                                 TaskConfig config)// = TaskConfig::Default());
{
////    const auto timeout = Timestamp(this->executor->get_time()) + params.taskStartTimeout;
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
  Timestamp timeout = operatorPLUS_in_Timestamp(&tTimestamp, &(pMContext->params.taskStartTimeout));

//void EmptyResponseTask_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask,
  //const std::shared_ptr<TaskContext>& context,
//    IMasterApplication* app,
  //std::string name,
//    FunctionCode_uint8_t func,
//    HeaderBuilderT format,
//    Timestamp startExpiration,
  //const Logger& logger,
//    TaskConfig* config);
////    auto task = std::make_shared<EmptyResponseTask>(this->tasks.context, *this->application, name, func, builder,
////                                                    timeout, this->logger, config);
  EmptyResponseTask_in_EmptyResponseTask(&eEmptyResponseTask,
                                         //const std::shared_ptr<TaskContext>& context,
                                         pMContext->application,
                                         //std::string name,
                                         func,
                                         builder,
                                         timeout,
                                         //const Logger& logger,
                                         &config);

////    this->ScheduleAdhocTask(task);
  ScheduleAdhocTask_in_MContext(pMContext, &(rRestartOperationTask.iIMasterTask));
}

////bool MContext::Run(const std::shared_ptr<IMasterTask>& task)
boolean Run_in_MContext(MContext *pMContext, IMasterTask* task)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Run_in_MContext1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pMContext->activeTask= "<<(uint32_t)pMContext->activeTask<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pMContext->tstate= "<<(uint32_t)pMContext->tstate<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*TaskState_in_MContext_IDLE= "<<TaskState_in_MContext_IDLE<<'\n';
#endif
  if (pMContext->activeTask || pMContext->tstate != TaskState_in_MContext_IDLE)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Run_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  pMContext->tstate = TaskState_in_MContext_TASK_READY;

  pMContext->activeTask = task;


//void OnStart_in_IMasterTask(IMasterTask *pIMasterTask);
////    this->activeTask->OnStart();
  OnStart_in_IMasterTask(pMContext->activeTask);

////    FORMAT_LOG_BLOCK(logger, flags::INFO, "Begining task: %s", this->activeTask->Name());
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::INFO, 'Begining task: %s', this->activeTask->Name())"<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Name_in_IMasterTask(pMContext->activeTask)= "<<std::string(Name_in_IMasterTask(pMContext->activeTask))<<'\n';
#endif

  if (!pMContext->isSending)
  {
//    TaskState_in_MContext_uint8_t ResumeActiveTask_in_MContext(MContext *pMContext);
////        this->tstate = this->ResumeActiveTask();
    pMContext->tstate =  ResumeActiveTask_in_MContext(pMContext);
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Run_in_MContext2_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

boolean Run_in_MContext_override(void *pIMasterTaskRunner, IMasterTask* task)
{
 MContext* parent = (MContext*) getParentPointer_in_IMasterTaskRunner((IMasterTaskRunner*)pIMasterTaskRunner);
 return Run_in_MContext(parent, task);
}

/// ------ private helpers ----------

////void MContext::ScheduleRecurringPollTask(const std::shared_ptr<IMasterTask>& task)
void ScheduleRecurringPollTask_in_MContext(MContext *pMContext, IMasterTask* task)
{
//void BindTask_in_MasterTasks(MasterTasks *pMasterTasks, IMasterTask* task);
////    this->tasks.BindTask(task);
  BindTask_in_MasterTasks(&(pMContext->tasks), task);

  if (pMContext->isOnline)
  {
//void Add_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTask* task, IMasterTaskRunner* runner);
////        this->scheduler->Add(task, *this);
    Add_in_IMasterScheduler(pMContext->scheduler, task, &(pMContext->iIMasterTaskRunner));
  }
}

////void MContext::ScheduleAdhocTask(const std::shared_ptr<IMasterTask>& task)
void ScheduleAdhocTask_in_MContext(MContext *pMContext, IMasterTask* task)
{
  if (pMContext->isOnline)
  {
////        this->scheduler->Add(task, *this);
    Add_in_IMasterScheduler(pMContext->scheduler, task, &(pMContext->iIMasterTaskRunner));
  }
  else
  {
//void OnLowerLayerClose_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
    // can't run this task since we're offline so fail it immediately
////        task->OnLowerLayerClose(Timestamp(this->executor->get_time()));
    Timestamp tTimestamp;
    Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
    OnLowerLayerClose_in_IMasterTask(task, tTimestamp);
  }
}

////MContext::TaskState MContext::ResumeActiveTask()
TaskState_in_MContext_uint8_t ResumeActiveTask_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{ResumeActiveTask_in_MContext1"<<'\n';
#endif
//void APDURequest_in_APDURequestOver2(APDURequest *pAPDURequest, WSeq_for_Uint16_t *buffer);
////    APDURequest request(this->txBuffer.as_wslice());
  WSeq_for_Uint16_t tmp = as_wslice_in_BufferSer4(&(pMContext->txBuffer));
  APDURequest request;
  APDURequest_in_APDURequestOver2(&request, &tmp);

//boolean BuildRequest_in_IMasterTask(IMasterTask *pIMasterTask, APDURequest* request, uint8_t seq);
  /// try to build a requst for the task
////    if (!this->activeTask->BuildRequest(request, this->solSeq))
  if (!BuildRequest_in_IMasterTask(pMContext->activeTask, &request, pMContext->solSeq.seq))
  {
//void OnMessageFormatError_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
////        activeTask->OnMessageFormatError(Timestamp(executor->get_time()));
    Timestamp tTimestamp;
    Timestamp_in_TimestampOver2(&tTimestamp, get_time_in_IExecutorExe4cpp(pMContext->executor));
    OnMessageFormatError_in_IMasterTask(pMContext->activeTask, tTimestamp);

//    void CompleteActiveTask_in_MContext(MContext *pMContext);
////        this->CompleteActiveTask();
    CompleteActiveTask_in_MContext(pMContext);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}ResumeActiveTask_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return TaskState_in_MContext_IDLE;
  }

//    void StartResponseTimer_in_MContext(MContext *pMContext);
////    this->StartResponseTimer();
  StartResponseTimer_in_MContext(pMContext);

////    auto apdu = request.ToRSeq();
  RSeq_for_Uint16_t apdu = ToRSeq_in_APDUWrapper(&(request.aAPDUWrapper));

//    void RecordLastRequest_in_MContext(MContext *pMContext, RSeq_for_Uint16_t* apdu);// {}
////    this->RecordLastRequest(apdu);
  RecordLastRequest_in_MContext(pMContext, &apdu);

//    void Transmit_in_MContext(MContext *pMContext, RSeq_for_Uint16_t* data);
////    this->Transmit(apdu);
  Transmit_in_MContext(pMContext, &apdu);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}ResumeActiveTask_in_MContext2_"<<'\n';
  decrement_stack_info();
#endif
  return TaskState_in_MContext_WAIT_FOR_RESPONSE;
}

//// --- State tables ---

////MContext::TaskState MContext::OnTransmitComplete()
TaskState_in_MContext_uint8_t OnTransmitComplete_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnTransmitComplete_in_MContext1"<<'\n';
#endif
  switch (pMContext->tstate)
  {
  case (TaskState_in_MContext_TASK_READY):
  {
//    TaskState_in_MContext_uint8_t ResumeActiveTask_in_MContext(MContext *pMContext);
////        return this->ResumeActiveTask();
    TaskState_in_MContext_uint8_t tmp = ResumeActiveTask_in_MContext(pMContext);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnTransmitComplete_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }

  default:
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnTransmitComplete_in_MContext2_"<<'\n';
    decrement_stack_info();
#endif
    return pMContext->tstate;
  }
  }
}

////MContext::TaskState MContext::OnResponseEvent(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects)
TaskState_in_MContext_uint8_t OnResponseEvent_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnResponseEvent_in_MContext1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pMContext->tstate= "<<(uint16_t)pMContext->tstate<<'\n';
#endif
  switch (pMContext->tstate)
  {
  case (TaskState_in_MContext_WAIT_FOR_RESPONSE):
  {
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"@@@@TaskState_in_MContext_WAIT_FOR_RESPONSE"<<'\n';
#endif
//    TaskState_in_MContext_uint8_t OnResponse_WaitForResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
////        return OnResponse_WaitForResponse(header, objects);
    TaskState_in_MContext_uint8_t tmp = OnResponse_WaitForResponse_in_MContext(pMContext, header, objects);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponseEvent_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  default:
////        FORMAT_LOG_BLOCK(logger, flags::WARN, "Not expecting a response, sequence: %u", header.control.SEQ);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::WARN, 'Not expecting a response, sequence: %u', header.control.SEQ)"<<'\n';
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponseEvent_in_MContext2_"<<'\n';
    decrement_stack_info();
#endif
    return pMContext->tstate;
  }
}

////MContext::TaskState MContext::OnResponseTimeoutEvent()
TaskState_in_MContext_uint8_t OnResponseTimeoutEvent_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
    std::cout<<'\n';
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"{OnResponseTimeoutEvent_in_MContext1"<<'\n';
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*pMContext->tstate= "<<(uint16_t)pMContext->tstate<<'\n';
#endif
  switch (pMContext->tstate)
  {
  case (TaskState_in_MContext_WAIT_FOR_RESPONSE):
  {
//    TaskState_in_MContext_uint8_t OnResponseTimeout_WaitForResponse_in_MContext(MContext *pMContext);
////        return OnResponseTimeout_WaitForResponse();
    TaskState_in_MContext_uint8_t tmp = OnResponseTimeout_WaitForResponse_in_MContext(pMContext);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponseTimeoutEvent_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
   }
  default:
////        SIMPLE_LOG_BLOCK(logger, flags::ERR, "Unexpected response timeout");
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::ERR, 'Unexpected response timeout')"<<'\n';
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponseTimeoutEvent_in_MContext2_"<<'\n';
    decrement_stack_info();
#endif
    return pMContext->tstate;
  }
}

//// --- State actions ----

////MContext::TaskState MContext::StartTask_TaskReady()
TaskState_in_MContext_uint8_t StartTask_TaskReady_in_MContext(MContext *pMContext)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{StartTask_TaskReady_in_MContext1"<<'\n';
#endif
  if (pMContext->isSending)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}StartTask_TaskReady_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return TaskState_in_MContext_TASK_READY;
  }

////    return this->ResumeActiveTask();
  TaskState_in_MContext_uint8_t tmp = ResumeActiveTask_in_MContext(pMContext);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}StartTask_TaskReady_in_MContext2_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

////MContext::TaskState MContext::OnResponse_WaitForResponse(const APDUResponseHeader& header,
////                                                         const ser4cpp::rseq_t& objects)
TaskState_in_MContext_uint8_t OnResponse_WaitForResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{OnResponse_WaitForResponse_in_MContext1"<<'\n';
#endif
  if (header->aAPDUHeader.control.SEQ != pMContext->solSeq.seq)
  {
////        FORMAT_LOG_BLOCK(this->logger, flags::WARN, "Response with bad sequence: %u", header.control.SEQ);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(this->logger, flags::WARN, 'Response with bad sequence: %u', header.control.SEQ)"<<'\n';
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponse_WaitForResponse_in_MContext1_"<<'\n';
    decrement_stack_info();
#endif
    return TaskState_in_MContext_WAIT_FOR_RESPONSE;
  }

//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    this->responseTimer.cancel();
  cancel_in_TimerExe4cpp(&(pMContext->responseTimer));

//void Increment_in_SequenceNum_for_uint8_Modulus16(SequenceNum_for_uint8_Modulus16 *pSequenceNum_for_uint8_Modulus16);
////    this->solSeq.Increment();
  Increment_in_SequenceNum_for_uint8_Modulus16(&(pMContext->solSeq));

////    auto now = Timestamp(this->executor->get_time());
  Timestamp now;
  Timestamp_in_TimestampOver2(&now, get_time_in_IExecutorExe4cpp(pMContext->executor));

//ResponseResult_in_IMasterTask_uint8_t OnResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* response, RSeq_for_Uint16_t* objects, Timestamp now);
////    auto result = this->activeTask->OnResponse(header, objects, now);
  ResponseResult_in_IMasterTask_uint8_t result = OnResponse_in_IMasterTask(pMContext->activeTask, header, objects, now);

#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*OnResponse_WaitForResponse_in_MContext3"<<'\n';
#endif

  if (header->aAPDUHeader.control.CON)
  {
//APDUHeader SolicitedConfirm_in_APDUHeader(uint8_t seq);
//    void QueueConfirm_in_MContext(MContext *pMContext, APDUHeader* header);
////        this->QueueConfirm(APDUHeader::SolicitedConfirm(header.control.SEQ));
    APDUHeader tmp = SolicitedConfirm_in_APDUHeader(header->aAPDUHeader.control.SEQ);
    QueueConfirm_in_MContext(pMContext, &tmp);
  }

  switch (result)
  {
  case (ResponseResult_in_IMasterTask_OK_CONTINUE):
  {
//    void StartResponseTimer_in_MContext(MContext *pMContext);
////        this->StartResponseTimer();
    StartResponseTimer_in_MContext(pMContext);
    TaskState_in_MContext_uint8_t tmp = TaskState_in_MContext_WAIT_FOR_RESPONSE;
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponse_WaitForResponse_in_MContext2_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  case (ResponseResult_in_IMasterTask_OK_REPEAT):
  {
//    TaskState_in_MContext_uint8_t StartTask_TaskReady_in_MContext(MContext *pMContext);
////        return StartTask_TaskReady();
    TaskState_in_MContext_uint8_t tmp = StartTask_TaskReady_in_MContext(pMContext);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponse_WaitForResponse_in_MContext3_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  default:
  {
    // task completed or failed, either way go back to idle
//    void CompleteActiveTask_in_MContext(MContext *pMContext);
////        this->CompleteActiveTask();
    CompleteActiveTask_in_MContext(pMContext);
    TaskState_in_MContext_uint8_t tmp = TaskState_in_MContext_IDLE;
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}OnResponse_WaitForResponse_in_MContext4_"<<'\n';
    decrement_stack_info();
#endif
    return tmp;
  }
  }
}

////MContext::TaskState MContext::OnResponseTimeout_WaitForResponse()
TaskState_in_MContext_uint8_t OnResponseTimeout_WaitForResponse_in_MContext(MContext *pMContext)
{
////    SIMPLE_LOG_BLOCK(logger, flags::WARN, "Timeout waiting for response");
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"*SIMPLE_LOG_BLOCK(logger, flags::WARN, 'Timeout waiting for response')"<<'\n';
  decrement_stack_info();
#endif

////    auto now = Timestamp(this->executor->get_time());
  Timestamp now;
  Timestamp_in_TimestampOver2(&now, get_time_in_IExecutorExe4cpp(pMContext->executor));

//void OnResponseTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
////    this->activeTask->OnResponseTimeout(now);
  OnResponseTimeout_in_IMasterTask(pMContext->activeTask, now);

////    this->solSeq.Increment();
  Increment_in_SequenceNum_for_uint8_Modulus16(&(pMContext->solSeq));

////    this->CompleteActiveTask();
////    return TaskState::IDLE;
  CompleteActiveTask_in_MContext(pMContext);

  return TaskState_in_MContext_IDLE;
}
////} // namespace opendnp3

void RecordLastRequest_in_MContext(MContext *pMContext, RSeq_for_Uint16_t* apdu)
{
  UNUSED(pMContext);
  UNUSED(apdu);
}
void RecordLastRequest_in_MContext_override(void *pMContext, RSeq_for_Uint16_t* apdu)
{
  MContext *parent = (MContext*) getParentPointer_in_MContext((MContext*) pMContext);
  RecordLastRequest_in_MContext(parent, apdu);
}

void OnParsedHeader_in_MContext_override(void *pMContext,
    RSeq_for_Uint16_t* apdu,
    APDUResponseHeader* header,
    RSeq_for_Uint16_t* objects)
{
  MContext *parent = (MContext*) getParentPointer_in_MContext((MContext*) pMContext);
  OnParsedHeader_in_MContext(parent, apdu, header, objects);
}

void* getParentPointer_in_MContext(MContext* pMContext)
{
  return pMContext->pParentPointer_in_MContext;
}
void  setParentPointer_in_MContext(MContext* pMContext, void* pParentPointer)
{
  pMContext->pParentPointer_in_MContext = pParentPointer;
}
