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
#include "MasterTasks.h"

#include "AssignClassTask.h"
#include "ClearRestartTask.h"
#include "DisableUnsolicitedTask.h"
#include "EnableUnsolicitedTask.h"
#include "EventScanTask.h"
#include "LANTimeSyncTask.h"
#include "SerialTimeSyncTask.h"
#include "StartupIntegrityPoll.h"

////namespace opendnp3
////{

static ClearRestartTask     cClearRestartTask;
static AssignClassTask      aAssignClassTask;
static StartupIntegrityPoll sStartupIntegrityPoll;
static EventScanTask        eEventScanTask;
static DisableUnsolicitedTask     dDisableUnsolTask;
static EnableUnsolicitedTask      eEnableUnsolTask;
static SerialTimeSyncTask   sSerialTimeSyncTask;
static LANTimeSyncTask      lLANTimeSyncTask;

////MasterTasks::MasterTasks(const MasterParams& params,
////                         const Logger& logger,
////                         IMasterApplication& app,
////                         std::shared_ptr<ISOEHandler> SOEHandler)
void MasterTasks_in_MasterTasks(MasterTasks *pMasterTasks,
                                MasterParams* params,
///                const Logger& logger,
                                IMasterApplication* app,
                                ISOEHandler* SOEHandler)
{
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"{MasterTasks_in_MasterTasks1"<<'\n';
#endif
////    : context(std::make_shared<TaskContext>()),
////      clearRestart(std::make_shared<ClearRestartTask>(context, app, logger)),
  ClearRestartTask_in_ClearRestartTask(&cClearRestartTask, app);
  pMasterTasks->clearRestart = &cClearRestartTask.iIMasterTask;

//    TaskBehavior RetryBehavior_in_MasterTasks_static(MasterParams* params)
////      assignClass(std::make_shared<AssignClassTask>(context, app, RetryBehavior(params), logger)),
  TaskBehavior ttmp = RetryBehavior_in_MasterTasks_static(params);
  AssignClassTask_in_AssignClassTask(&aAssignClassTask,
//                       const std::shared_ptr<TaskContext>& context,
                                     app,
                                     &ttmp);
  pMasterTasks->assignClass = &cClearRestartTask.iIMasterTask;

////      startupIntegrity(std::make_shared<StartupIntegrityPoll>(
////          context, app, SOEHandler, params.startupIntegrityClassMask, RetryBehavior(params), logger)),
  StartupIntegrityPoll_in_StartupIntegrityPoll(&sStartupIntegrityPoll,
//                       const std::shared_ptr<TaskContext>& context,
      app,
      SOEHandler,
      params->startupIntegrityClassMask,
      &ttmp);
  pMasterTasks->startupIntegrity = &sStartupIntegrityPoll.pPollTaskBase.iIMasterTask;

////      eventScan(std::make_shared<EventScanTask>(
////          context, app, SOEHandler, params.eventScanOnEventsAvailableClassMask, logger)),
  EventScanTask_in_EventScanTask(&eEventScanTask,
//                       const std::shared_ptr<TaskContext>& context,
                                 app,
                                 SOEHandler,
                                 params->eventScanOnEventsAvailableClassMask);
  pMasterTasks->eventScan = &eEventScanTask.pPollTaskBase.iIMasterTask;

  // optional tasks
////      disableUnsol(GetDisableUnsolTask(context, params, logger, app)),
////      enableUnsol(GetEnableUnsolTask(context, params, logger, app)),
////      timeSynchronization(GetTimeSyncTask(context, params.timeSyncMode, logger, app))
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}MasterTasks_in_MasterTasks_"<<'\n';
    decrement_stack_info();
#endif
}

////void MasterTasks::Initialize(IMasterScheduler& scheduler, IMasterTaskRunner& runner)
void Initialize_in_MasterTasks(MasterTasks *pMasterTasks, IMasterScheduler* scheduler, IMasterTaskRunner* runner)
{
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"{Initialize_in_MasterTasks1"<<'\n';
#endif
  for (auto& task :
       { pMasterTasks->clearRestart, pMasterTasks->assignClass, pMasterTasks->startupIntegrity,
         pMasterTasks->eventScan,    pMasterTasks->enableUnsol, pMasterTasks->disableUnsol,
         pMasterTasks->timeSynchronization
     })
  {
    if (task)
    {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*Initialize_in_MasterTasks2"<<'\n';
#endif
////            scheduler.Add(task, runner);
      Add_in_IMasterScheduler(scheduler, task, runner);
    }
  }

  for (auto& task : pMasterTasks->boundTasks)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"*Initialize_in_MasterTasks3"<<'\n';
#endif
////        scheduler.Add(task, runner);
    Add_in_IMasterScheduler(scheduler, &task, runner);
  }
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Initialize_in_MasterTasks_"<<'\n';
    decrement_stack_info();
#endif
}

void BindTask_in_MasterTasks(MasterTasks *pMasterTasks, IMasterTask* task)
{
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"{BindTask_in_MasterTasks1"<<'\n';
#endif
  pMasterTasks->boundTasks.push_back(*task);
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}BindTask_in_MasterTasks_"<<'\n';
    decrement_stack_info();
#endif
}

boolean DemandTimeSync_in_MasterTasks(MasterTasks *pMasterTasks)
{
//    boolean Demand_in_MasterTasks(MasterTasks *pMasterTasks, IMasterTask* task)
////    return this->Demand(this->timeSynchronization);
  return Demand_in_MasterTasks(pMasterTasks, pMasterTasks->timeSynchronization);
}

boolean DemandEventScan_in_MasterTasks(MasterTasks *pMasterTasks)
{
////    return this->Demand(this->eventScan);
  return Demand_in_MasterTasks(pMasterTasks, pMasterTasks->eventScan);
}

boolean DemandIntegrity_in_MasterTasks(MasterTasks *pMasterTasks)
{
////    return this->Demand(this->startupIntegrity);
  return Demand_in_MasterTasks(pMasterTasks, pMasterTasks->startupIntegrity);
}

void OnRestartDetected_in_MasterTasks(MasterTasks *pMasterTasks)
{
////    this->Demand(this->clearRestart);
  Demand_in_MasterTasks(pMasterTasks, pMasterTasks->clearRestart);
////    this->Demand(this->assignClass);
  Demand_in_MasterTasks(pMasterTasks, pMasterTasks->assignClass);
////    this->Demand(this->startupIntegrity);
  Demand_in_MasterTasks(pMasterTasks, pMasterTasks->startupIntegrity);
////    this->Demand(this->enableUnsol);
  Demand_in_MasterTasks(pMasterTasks, pMasterTasks->enableUnsol);
}

////IMasterTask* MasterTasks::GetTimeSyncTask(const std::shared_ptr<TaskContext>& context,
////                                                          TimeSyncMode mode,
////                                                          const Logger& logger,
////                                                          IMasterApplication& application)
IMasterTask* GetTimeSyncTask_in_MasterTasks_static(////const std::shared_ptr<TaskContext>& context,
  TimeSyncMode_uint8_t mode,
///                                                        const Logger& logger,
  IMasterApplication* application)
{
  switch (mode)
  {
  case (TimeSyncMode_NonLAN):
////        return std::make_shared<SerialTimeSyncTask>(context, application, logger);
    SerialTimeSyncTask_in_SerialTimeSyncTask(&sSerialTimeSyncTask,
//                       const std::shared_ptr<TaskContext>& context,
        application);
    return &sSerialTimeSyncTask.iIMasterTask;
  case (TimeSyncMode_LAN):
////        return std::make_shared<LANTimeSyncTask>(context, application, logger);
    LANTimeSyncTask_in_LANTimeSyncTask(&lLANTimeSyncTask,
//                       const std::shared_ptr<TaskContext>& context,
                                       application);
    return &sSerialTimeSyncTask.iIMasterTask;
  default:
    return NULL;////nullptr;
  }
}

////std::shared_ptr<IMasterTask> MasterTasks::GetEnableUnsolTask(const std::shared_ptr<TaskContext>& context,
////                                                             const MasterParams& params,
///                                                             const Logger& logger,
///                                                             IMasterApplication& application)
IMasterTask* GetEnableUnsolTask_in_MasterTasks_static(////const std::shared_ptr<TaskContext>& context,
  MasterParams* params,
////                                                           const Logger& logger,
  IMasterApplication* application)
{
//boolean HasEventClass_in_ClassField(ClassField *pClassField);
////    return params.unsolClassMask.HasEventClass()
  if(HasEventClass_in_ClassField(&(params->unsolClassMask)))
  {
    TaskBehavior ttmp = RetryBehavior_in_MasterTasks_static(params);

    EnableUnsolicitedTask_in_EnableUnsolicitedTask(&eEnableUnsolTask,
//                       const std::shared_ptr<TaskContext>& context,
        application,
        &ttmp,
        params->unsolClassMask);
    return &eEnableUnsolTask.iIMasterTask;
  }
  return NULL;
////        ? std::make_shared<EnableUnsolicitedTask>(context, application, RetryBehavior(params), params.unsolClassMask,
////                                                  logger)
////        : nullptr;
}

////std::shared_ptr<IMasterTask> MasterTasks::GetDisableUnsolTask(const std::shared_ptr<TaskContext>& context,
////                                                              const MasterParams& params,
////                                                              const Logger& logger,
////                                                              IMasterApplication& application)
IMasterTask* GetDisableUnsolTask_in_MasterTasks_static(////const std::shared_ptr<TaskContext>& context,
  MasterParams* params,
////                                                            const Logger& logger,
  IMasterApplication* application)
{
//TaskBehavior SingleImmediateExecutionWithRetry_in_TaskBehavior_static(TimeDuration* minRetryDelay,
//    TimeDuration* maxRetryDelay);
////    return params.disableUnsolOnStartup
////        ? std::make_shared<DisableUnsolicitedTask>(
////              context, application,
////              TaskBehavior::SingleImmediateExecutionWithRetry(params.taskRetryPeriod, params.maxTaskRetryPeriod),
////              logger)
////        : nullptr;
  if(params->disableUnsolOnStartup)
  {
    TaskBehavior tmp = SingleImmediateExecutionWithRetry_in_TaskBehavior_static(&(params->taskRetryPeriod), &(params->maxTaskRetryPeriod));

    DisableUnsolicitedTask_in_DisableUnsolicitedTask(&dDisableUnsolTask,
//                       const std::shared_ptr<TaskContext>& context,
        application, &tmp);
    return &dDisableUnsolTask.iIMasterTask;
  }
  return NULL;
}

////} // namespace opendnp3
TaskBehavior RetryBehavior_in_MasterTasks_static(MasterParams* params)
{
//TaskBehavior SingleImmediateExecutionWithRetry_in_TaskBehavior_static(TimeDuration* minRetryDelay,
//    TimeDuration* maxRetryDelay);
////        return TaskBehavior::SingleImmediateExecutionWithRetry(params.taskRetryPeriod, params.maxTaskRetryPeriod);
  return SingleImmediateExecutionWithRetry_in_TaskBehavior_static(&(params->taskRetryPeriod), &(params->maxTaskRetryPeriod));
}

boolean Demand_in_MasterTasks(MasterTasks *pMasterTasks, IMasterTask* task)
{
  UNUSED(pMasterTasks);
  if (task)
  {
////            task->SetMinExpiration();
    SetMinExpiration_in_IMasterTask(task);
    return true;
  }
  else
  {
    return false;
  }
}
