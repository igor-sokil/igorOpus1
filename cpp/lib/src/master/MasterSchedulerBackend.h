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
#ifndef OPENDNP3_MASTERSCHEDULERBACKEND_H
#define OPENDNP3_MASTERSCHEDULERBACKEND_H

#include "IMasterScheduler.h"
#include "IMasterTaskRunner.h"

#include "TimerExe4cpp.h"
#include "IExecutorExe4cpp.h"

////#include <memory>
#include <vector>

////namespace opendnp3
////{

// Tasks are associated with a particular runner
// Задачи связаны с конкретным бегуном
////    struct Record
typedef struct
{
////        Record() = default;

////        Record(const std::shared_ptr<IMasterTask>& task, IMasterTaskRunner& runner) : task(task), runner(&runner) {}

////        operator bool()
////        {
////            return task && runner;
////        }

////        void Clear()
////        {
////            this->task.reset();
////            this->runner = nullptr;
////        }

////        bool BelongsTo(const IMasterTaskRunner& runner) const
//Принадлежит
////        {
////            return this->runner == &runner;
////        }

  IMasterTask* task;
  IMasterTaskRunner* runner;// = nullptr;
} Record_in_MasterSchedulerBackend;

void   Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver1(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend);
void   Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend,
    IMasterTask* task, IMasterTaskRunner* runner);
void Clear_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend);
boolean BelongsTo_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend, IMasterTaskRunner* runner);


#define Comparison_in_MasterSchedulerBackend_uint8_t uint8_t
////    enum class Comparison : uint8_t
enum
{
  Comparison_in_MasterSchedulerBackend_LEFT,
  Comparison_in_MasterSchedulerBackend_RIGHT,
  Comparison_in_MasterSchedulerBackend_SAME
};

////class MasterSchedulerBackend final : public IMasterScheduler,
////                                     public std::enable_shared_from_this<MasterSchedulerBackend>
typedef struct
{
  IMasterScheduler iIMasterScheduler;

  // Tasks are associated with a particular runner
// Задачи связаны с конкретным бегуном
////    struct Record
////    {
////        Record() = default;

////        Record(const std::shared_ptr<IMasterTask>& task, IMasterTaskRunner& runner) : task(task), runner(&runner) {}

////        operator bool()
////        {
////            return task && runner;
////        }

////        void Clear()
////        {
////            this->task.reset();
////            this->runner = nullptr;
////        }

////        bool BelongsTo(const IMasterTaskRunner& runner) const
//Принадлежит
////        {
////            return this->runner == &runner;
////        }

////        std::shared_ptr<IMasterTask> task;
////        IMasterTaskRunner* runner = nullptr;
////    };

////public:
////    explicit MasterSchedulerBackend(const std::shared_ptr<exe4cpp::IExecutor>& executor);

////    virtual void Shutdown() override;

  // ------- implement IMasterScheduler --------

////    virtual void Add(const std::shared_ptr<IMasterTask>& task, IMasterTaskRunner& runner) override;

////    virtual void SetRunnerOffline(const IMasterTaskRunner& runner) override;

////    virtual bool CompleteCurrentFor(const IMasterTaskRunner& runner) override;

////    virtual void Demand(const std::shared_ptr<IMasterTask>& task) override;

////    virtual void Evaluate() override;

////private:
  boolean isShutdown;// = false;
  boolean taskCheckPending;// = false;

  Record_in_MasterSchedulerBackend current;
  std::vector<Record_in_MasterSchedulerBackend> tasks;

////    void PostCheckForTaskRun();

////    bool CheckForTaskRun();

////    void RestartTimeoutTimer();

////    void TimeoutTasks();

  IExecutorExe4cpp* executor;
  TimerExe4cpp taskTimer;
  TimerExe4cpp taskStartTimeout;

////    enum class Comparison : uint8_t
////    {
////        LEFT,
////        RIGHT,
////        SAME
////    };

////    static Comparison GetBestTaskToRun(const Timestamp& now, const Record& left, const Record& right);

////    static Comparison CompareEnabledStatus(const Record& left, const Record& right);

////    static Comparison CompareBlockedStatus(const Record& left, const Record& right);

////    static Comparison ComparePriority(const Record& left, const Record& right);

////    static Comparison CompareTime(const Timestamp& now, const Record& left, const Record& right);
  uint16_t numTask;
} MasterSchedulerBackend;

void MasterSchedulerBackend_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IExecutorExe4cpp* executor);

void Shutdown_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
void Shutdown_in_MasterSchedulerBackend_override(void *pIMasterScheduler);

void Add_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTask* task, IMasterTaskRunner* runner);
void Add_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTask* task, IMasterTaskRunner* runner);

void SetRunnerOffline_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTaskRunner* runner);
void SetRunnerOffline_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTaskRunner* runner);

boolean CompleteCurrentFor_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTaskRunner* runner);
boolean CompleteCurrentFor_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTaskRunner* runner);

void Demand_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTask* task);
void Demand_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTask* task);

void Evaluate_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
void Evaluate_in_MasterSchedulerBackend_override(void *pIMasterScheduler);

Comparison_in_MasterSchedulerBackend_uint8_t GetBestTaskToRun_in_MasterSchedulerBackend_static(Timestamp* now, Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);

Comparison_in_MasterSchedulerBackend_uint8_t CompareEnabledStatus_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);

Comparison_in_MasterSchedulerBackend_uint8_t CompareBlockedStatus_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);

Comparison_in_MasterSchedulerBackend_uint8_t ComparePriority_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);

Comparison_in_MasterSchedulerBackend_uint8_t CompareTime_in_MasterSchedulerBackend_static(Timestamp* now, Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);

void PostCheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);

boolean CheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);

void RestartTimeoutTimer_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);

void TimeoutTasks_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);

uint16_t getNumTask_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
void setNumTask_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, uint16_t num);
////} // namespace opendnp3

#endif
