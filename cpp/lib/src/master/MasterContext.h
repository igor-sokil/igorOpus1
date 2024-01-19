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
#ifndef OPENDNP3_MASTERCONTEXT_H
#define OPENDNP3_MASTERCONTEXT_H

#include "LayerInterfaces.h"
#include "AppSeqNum.h"
#include "HeaderBuilder.h"
#include "IMasterScheduler.h"
#include "MasterTasks.h"

#include "MeasurementTypes.h"
#include "RestartType.h"
////#include "opendnp3/logging/Logger.h"
#include "CommandResultCallbackT.h"
#include "CommandSet.h"
#include "IMasterApplication.h"
#include "RestartOperationResult.h"

#include "BufferSer4.h"

#include "TimerExe4cpp.h"
///#include <exe4cpp/asio/StrandExecutor.h>

#include <deque>
////#include <memory>

////namespace opendnp3
////{

#define TaskState_in_MContext_uint8_t uint8_t

    enum ///class TaskState
    {
        TaskState_in_MContext_IDLE,
        TaskState_in_MContext_TASK_READY,
        TaskState_in_MContext_WAIT_FOR_RESPONSE
    };

/*
    All of the mutable state and configuration for a master
*/
////class MContext final : public IUpperLayer, public std::enable_shared_from_this<MContext>, private IMasterTaskRunner, private Uncopyable
typedef struct
{
  IUpperLayer iIUpperLayer;
  IMasterTaskRunner iIMasterTaskRunner;

////private:
////    MContext(const Addresses& addresses,
////             const Logger& logger,
////             const std::shared_ptr<exe4cpp::IExecutor>& executor,
////             std::shared_ptr<ILowerLayer> lower,
////             const std::shared_ptr<ISOEHandler>& SOEHandler,
////             const std::shared_ptr<IMasterApplication>& application,
////             std::shared_ptr<IMasterScheduler> scheduler,
////             const MasterParams& params);

////public:

////    static std::shared_ptr<MContext> Create(
////        const Addresses& addresses,
////        const Logger& logger,
////        const std::shared_ptr<exe4cpp::IExecutor>& executor,
////        std::shared_ptr<ILowerLayer> lower,
////        const std::shared_ptr<ISOEHandler>& SOEHandler,
////        const std::shared_ptr<IMasterApplication>& application,
////        std::shared_ptr<IMasterScheduler> scheduler,
////        const MasterParams& params
////    );

////    Logger logger;
    IExecutor* executor;
    ILowerLayer* lower;

    // ------- configuration --------
    Addresses addresses;
    MasterParams params;
    ISOEHandler* SOEHandler;
    IMasterApplication* application;
    IMasterScheduler* scheduler;

    // ------- dynamic state ---------
    boolean isOnline;// = false;
    boolean isSending;// = false;
    AppSeqNum solSeq;
    AppSeqNum unsolSeq;
    IMasterTask* activeTask;
    TimerExe4cpp responseTimer;

    MasterTasks tasks;
    std::deque<APDUHeader> confirmQueue;
    BufferSer4 txBuffer;
    TaskState_in_MContext_uint8_t tstate;

    // --- implement  IUpperLayer ------

    ////bool OnLowerLayerUp() final;

////    bool OnLowerLayerDown() final;

///    bool OnReceive(const Message& message) final;

////    bool OnTxReady() final;

    // additional virtual methods that can be overriden to implement secure authentication
// дополнительные виртуальные методы, которые можно переопределить для реализации безопасной аутентификации

////    virtual void OnParsedHeader(const ser4cpp::rseq_t& apdu,
////                                const APDUResponseHeader& header,
////                                const ser4cpp::rseq_t& objects);

////    virtual void RecordLastRequest(const ser4cpp::rseq_t& apdu) {}

    // methods for initiating command sequences
// методы для запуска последовательности команд

////    void DirectOperate(CommandSet&& commands, const CommandResultCallbackT& callback, const TaskConfig& config);

////    void SelectAndOperate(CommandSet&& commands, const CommandResultCallbackT& callback, const TaskConfig& config);

    // -----  public methods used to add tasks -----

////    std::shared_ptr<IMasterTask> AddScan(TimeDuration period,
////                                         const HeaderBuilderT& builder,
////                                         std::shared_ptr<ISOEHandler> soe_handler,
////                                         TaskConfig config = TaskConfig::Default());

////    std::shared_ptr<IMasterTask> AddAllObjectsScan(GroupVariationID gvId,
////                                                   TimeDuration period,
////                                                   std::shared_ptr<ISOEHandler> soe_handler,
////                                                   TaskConfig config = TaskConfig::Default());

////    std::shared_ptr<IMasterTask> AddClassScan(const ClassField& field,
////                                              TimeDuration period,
////                                              std::shared_ptr<ISOEHandler> soe_handler,
////                                              TaskConfig config = TaskConfig::Default());

////    std::shared_ptr<IMasterTask> AddRangeScan(GroupVariationID gvId,
////                                              uint16_t start,
////                                              uint16_t stop,
////                                              TimeDuration period,
////                                              std::shared_ptr<ISOEHandler> soe_handler,
////                                              TaskConfig config = TaskConfig::Default());

    // ---- Single shot immediate scans ----
// ---- Однократное немедленное сканирование ----

////    void Scan(const HeaderBuilderT& builder,
////              std::shared_ptr<ISOEHandler> soe_handler,
////              TaskConfig config = TaskConfig::Default());

////    void ScanAllObjects(GroupVariationID gvId,
////                        std::shared_ptr<ISOEHandler> soe_handler,
////                        TaskConfig config = TaskConfig::Default());

////    void ScanClasses(const ClassField& field,
////                     std::shared_ptr<ISOEHandler> soe_handler,
////                     TaskConfig config = TaskConfig::Default());

////    void ScanRange(GroupVariationID gvId,
////                   uint16_t start,
////                   uint16_t stop,
////                   std::shared_ptr<ISOEHandler> soe_handler,
////                   TaskConfig config = TaskConfig::Default());

    /// ---- Write tasks -----

////    void Write(const TimeAndInterval& value, uint16_t index, TaskConfig config = TaskConfig::Default());

////    void Restart(RestartType op, const RestartOperationCallbackT& callback, TaskConfig config = TaskConfig::Default());

////    void PerformFunction(const std::string& name,
////                         FunctionCode func,
////                         const HeaderBuilderT& builder,
////                         TaskConfig config = TaskConfig::Default());

    /// public state manipulation actions

////    TaskState ResumeActiveTask();

////    void CompleteActiveTask();

////    void QueueConfirm(const APDUHeader& header);

////    void StartResponseTimer();

////    void ProcessAPDU(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);

////    bool CheckConfirmTransmit();

////    void ProcessResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);

////    void ProcessUnsolicitedResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);

////    void Transmit(const ser4cpp::rseq_t& data);

////private:
    // --- implement  IMasterTaskRunner ------

////    virtual bool Run(const std::shared_ptr<IMasterTask>& task) override;

////    void ScheduleRecurringPollTask(const std::shared_ptr<IMasterTask>& task);

////    void ProcessIIN(const IINField& iin);

////    void OnResponseTimeout();

////protected:
////    void ScheduleAdhocTask(const std::shared_ptr<IMasterTask>& task);

    // state switch lookups

////    TaskState OnTransmitComplete();
////    TaskState OnResponseEvent(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);
////    TaskState OnResponseTimeoutEvent();

    // --- state handling functions ----
////    TaskState StartTask_TaskReady();
////    TaskState OnResponse_WaitForResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);
////    TaskState OnResponseTimeout_WaitForResponse();
} MContext;

  void  MContext_in_MContext(MContext *pMContext,
             Addresses* addresses,
//             const Logger& logger,
             IExecutor* executor,
             ILowerLayer* lower,
             ISOEHandler* SOEHandler,
             IMasterApplication* application,
             IMasterScheduler* scheduler,
             MasterParams* params);

    // --- implement  IUpperLayer ------

    boolean OnLowerLayerUp_in_IUpDown(IUpDown *pIUpDown);

    boolean OnLowerLayerDown_in_IUpDown(IUpDown *pIUpDown);

    boolean OnReceive_in_IUpperLayer(IUpperLayer *pIUpperLayer, Message* message);

    boolean OnTxReady_in_IUpperLayer(IUpperLayer *pIUpperLayer);

    // additional virtual methods that can be overriden to implement secure authentication
// дополнительные виртуальные методы, которые можно переопределить для реализации безопасной аутентификации

    void OnParsedHeader_in_MContext(MContext *pMContext,
                                    RSeq_for_Uint16_t* apdu,
                                 APDUResponseHeader* header,
                                RSeq_for_Uint16_t* objects);

    void RecordLastRequest_in_MContext(MContext *pMContext, RSeq_for_Uint16_t* apdu);// {}

    // methods for initiating command sequences
// методы для запуска последовательности команд

    void DirectOperate_in_MContext(MContext *pMContext, CommandSet* commands, CommandResultCallbackT* callback, TaskConfig config);

    void SelectAndOperate_in_MContext(MContext *pMContext, CommandSet* commands, CommandResultCallbackT* callback, TaskConfig* config);

    // -----  public methods used to add tasks -----

    IMasterTask* AddScan_in_MContext(MContext *pMContext,
                              TimeDuration period,
                                         HeaderBuilderT* builder,
                                         ISOEHandler* soe_handler,
                                         TaskConfig config);// = TaskConfig::Default());

   IMasterTask* AddAllObjectsScan_in_MContext(MContext *pMContext,
                GroupVariationID gvId,
                                                   TimeDuration period,
                                                   ISOEHandler* soe_handler,
                                                   TaskConfig config);// = TaskConfig::Default());

    IMasterTask* AddClassScan_in_MContext(MContext *pMContext,
              ClassField* field,
                                              TimeDuration period,
                                              ISOEHandler* soe_handler,
                                              TaskConfig config);// = TaskConfig::Default());

    IMasterTask* AddRangeScan_in_MContext(MContext *pMContext,
               GroupVariationID gvId,
                                              uint16_t start,
                                              uint16_t stop,
                                              TimeDuration period,
                                              ISOEHandler* soe_handler,
                                              TaskConfig config);// = TaskConfig::Default());

    // ---- Single shot immediate scans ----
// ---- Однократное немедленное сканирование ----

    void Scan_in_MContext(MContext *pMContext,
         HeaderBuilderT builder,
              ISOEHandler* soe_handler,
              TaskConfig config);// = TaskConfig::Default());

    void ScanAllObjects_in_MContext(MContext *pMContext,
                GroupVariationID gvId,
                        ISOEHandler* soe_handler,
                        TaskConfig config);// = TaskConfig::Default());

    void ScanClasses_in_MContext(MContext *pMContext,
         ClassField* field,
                     ISOEHandler* soe_handler,
                     TaskConfig config);// = TaskConfig::Default());

    void ScanRange_in_MContext(MContext *pMContext,
            GroupVariationID gvId,
                   uint16_t start,
                   uint16_t stop,
                   ISOEHandler* soe_handler,
                   TaskConfig config);// = TaskConfig::Default());

    /// ---- Write tasks -----

    void Write_in_MContext(MContext *pMContext, TimeAndInterval* value, uint16_t index, TaskConfig config);// = TaskConfig::Default());

   void Restart_in_MContext(MContext *pMContext, RestartType_uint8_t op, RestartOperationCallbackT callback, TaskConfig config);// = TaskConfig::Default());

   void PerformFunction_in_MContext(MContext *pMContext, std::string& name,
                         FunctionCode func,
                         HeaderBuilderT* builder,
                         TaskConfig config);// = TaskConfig::Default());

    /// public state manipulation actions

    TaskState ResumeActiveTask_in_MContext(MContext *pMContext);

    void CompleteActiveTask_in_MContext(MContext *pMContext);

    void QueueConfirm_in_MContext(MContext *pMContext, APDUHeader* header);

    void StartResponseTimer_in_MContext(MContext *pMContext);

    void ProcessAPDU_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

    boolean CheckConfirmTransmit_in_MContext(MContext *pMContext);

    void ProcessResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

    void ProcessUnsolicitedResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

    void Transmit_in_MContext(MContext *pMContext, RSeq_for_Uint16_t* data);

    // --- implement  IMasterTaskRunner ------

    boolean Run_in_MContext(MContext *pMContext, IMasterTask* task);

   void ScheduleRecurringPollTask_in_MContext(MContext *pMContext, IMasterTask* task);

   void ProcessIIN_in_MContext(MContext *pMContext, IINField* iin);

    void OnResponseTimeout_in_MContext(MContext *pMContext);

    void ScheduleAdhocTask_in_MContext(MContext *pMContext, IMasterTask* task);

    // state switch lookups

    TaskState OnTransmitComplete_in_MContext(MContext *pMContext);
    TaskState OnResponseEvent_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
    TaskState OnResponseTimeoutEvent_in_MContext(MContext *pMContext);

    // --- state handling functions ----
    TaskState StartTask_TaskReady_in_MContext(MContext *pMContext);
    TaskState OnResponse_WaitForResponse_in_MContext(MContext *pMContext, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
    TaskState OnResponseTimeout_WaitForResponse_in_MContext(MContext *pMContext);

////} // namespace opendnp3

#endif
