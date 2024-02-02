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
#ifndef OPENDNP3_MASTERTASKS_H
#define OPENDNP3_MASTERTASKS_H

#include "header.h"
#include "IMasterScheduler.h"

#include "IMasterApplication.h"
#include "ISOEHandler.h"
#include "MasterParams.h"

////#include <vector>

////namespace opendnp3
////{

////class MasterTasks
typedef struct
{

////public:
////    MasterTasks(const MasterParams& params,
////                const Logger& logger,
////                IMasterApplication& application,
////                std::shared_ptr<ISOEHandler> SOEHandler);

////    void Initialize(IMasterScheduler& scheduler, IMasterTaskRunner& runner);

////    bool DemandTimeSync();
////    bool DemandEventScan();
////    bool DemandIntegrity();
////
////    void OnRestartDetected();

////    void BindTask(const std::shared_ptr<IMasterTask>& task);

////    const std::shared_ptr<TaskContext> context;

////private:
////    bool Demand(const std::shared_ptr<IMasterTask>& task)
////    {
////        if (task)
////        {
////            task->SetMinExpiration();
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }

////    inline static TaskBehavior RetryBehavior(const MasterParams& params)
////    {
////        return TaskBehavior::SingleImmediateExecutionWithRetry(params.taskRetryPeriod, params.maxTaskRetryPeriod);
////    }

////    const std::shared_ptr<IMasterTask> clearRestart;
////    const std::shared_ptr<IMasterTask> assignClass;
////    const std::shared_ptr<IMasterTask> startupIntegrity;
////    const std::shared_ptr<IMasterTask> eventScan;
////    const std::shared_ptr<IMasterTask> disableUnsol;
////    const std::shared_ptr<IMasterTask> enableUnsol;
////    const std::shared_ptr<IMasterTask> timeSynchronization;
////

  IMasterTask* clearRestart;
  IMasterTask* assignClass;
  IMasterTask* startupIntegrity;
  IMasterTask* eventScan;
  IMasterTask* disableUnsol;
  IMasterTask* enableUnsol;
  IMasterTask* timeSynchronization;

////    static std::shared_ptr<IMasterTask> GetTimeSyncTask(const std::shared_ptr<TaskContext>& context,
////                                                        TimeSyncMode mode,
////                                                        const Logger& logger,
////                                                        IMasterApplication& application);
////    static std::shared_ptr<IMasterTask> GetEnableUnsolTask(const std::shared_ptr<TaskContext>& context,
////                                                           const MasterParams& params,
////                                                           const Logger& logger,
////                                                           IMasterApplication& application);
////    static std::shared_ptr<IMasterTask> GetDisableUnsolTask(const std::shared_ptr<TaskContext>& context,
////                                                            const MasterParams& params,
////                                                            const Logger& logger,
////                                                            IMasterApplication& application);

  std::vector<IMasterTask> boundTasks;
} MasterTasks;

void MasterTasks_in_MasterTasks(MasterTasks *pMasterTasks,
                                MasterParams* params,
///                const Logger& logger,
                                IMasterApplication* application,
                                ISOEHandler* SOEHandler);

TaskBehavior RetryBehavior_in_MasterTasks_static(MasterParams* params);

void Initialize_in_MasterTasks(MasterTasks *pMasterTasks, IMasterScheduler* scheduler, IMasterTaskRunner* runner);

boolean DemandTimeSync_in_MasterTasks(MasterTasks *pMasterTasks);
boolean DemandEventScan_in_MasterTasks(MasterTasks *pMasterTasks);
boolean DemandIntegrity_in_MasterTasks(MasterTasks *pMasterTasks);

boolean Demand_in_MasterTasks(MasterTasks *pMasterTasks, IMasterTask* task);

void OnRestartDetected_in_MasterTasks(MasterTasks *pMasterTasks);

void BindTask_in_MasterTasks(MasterTasks *pMasterTasks, IMasterTask* task);


IMasterTask* GetTimeSyncTask_in_MasterTasks_static(////const std::shared_ptr<TaskContext>& context,
  TimeSyncMode_uint8_t mode,
///                                                        const Logger& logger,
  IMasterApplication* application);
IMasterTask* GetEnableUnsolTask_in_MasterTasks_static(////const std::shared_ptr<TaskContext>& context,
  MasterParams* params,
////                                                           const Logger& logger,
  IMasterApplication* application);
IMasterTask* GetDisableUnsolTask_in_MasterTasks_static(////const std::shared_ptr<TaskContext>& context,
  MasterParams* params,
////                                                            const Logger& logger,
  IMasterApplication* application);

////} // namespace opendnp3

#endif
