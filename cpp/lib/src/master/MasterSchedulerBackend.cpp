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
#include "MasterSchedulerBackend.h"

///#include <algorithm>

////namespace opendnp3
////{

////MasterSchedulerBackend::MasterSchedulerBackend(const std::shared_ptr<exe4cpp::IExecutor>& executor) : executor(executor)
void MasterSchedulerBackend_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IExecutorExe4cpp* executor)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{MasterSchedulerBackend_in_MasterSchedulerBackend1"<<'\n';
#endif
  pMasterSchedulerBackend->iIMasterScheduler.pShutdown_in_IMasterScheduler = Shutdown_in_MasterSchedulerBackend_override;
  pMasterSchedulerBackend->iIMasterScheduler.pAdd_in_IMasterScheduler = Add_in_MasterSchedulerBackend_override;
  pMasterSchedulerBackend->iIMasterScheduler.pSetRunnerOffline_in_IMasterScheduler = SetRunnerOffline_in_MasterSchedulerBackend_override;
  pMasterSchedulerBackend->iIMasterScheduler.pCompleteCurrentFor_in_IMasterScheduler = CompleteCurrentFor_in_MasterSchedulerBackend_override;
  pMasterSchedulerBackend->iIMasterScheduler.pDemand_in_IMasterScheduler = Demand_in_MasterSchedulerBackend_override;
  pMasterSchedulerBackend->iIMasterScheduler.pEvaluate_in_IMasterScheduler = Evaluate_in_MasterSchedulerBackend_override;

  setParentPointer_in_IMasterScheduler(&(pMasterSchedulerBackend->iIMasterScheduler), pMasterSchedulerBackend);

  pMasterSchedulerBackend->executor = executor;
  pMasterSchedulerBackend->isShutdown = false;
  pMasterSchedulerBackend->taskCheckPending = false;

  pMasterSchedulerBackend->numTask = 0;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}MasterSchedulerBackend_in_MasterSchedulerBackend_"<<'\n';
  decrement_stack_info();
#endif
}

////void MasterSchedulerBackend::Shutdown()
void Shutdown_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend)
{
  pMasterSchedulerBackend->isShutdown = true;
  pMasterSchedulerBackend->tasks.clear();
//       void Clear_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend)
////    this->current.Clear();
  Clear_in_Record_in_MasterSchedulerBackend(&(pMasterSchedulerBackend->current));

//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////    this->taskTimer.cancel();
  cancel_in_TimerExe4cpp(&(pMasterSchedulerBackend->taskTimer));

////    this->taskStartTimeout.cancel();
  cancel_in_TimerExe4cpp(&(pMasterSchedulerBackend->taskStartTimeout));

////    this->executor.reset();
}
void Shutdown_in_MasterSchedulerBackend_override(void *pIMasterScheduler)
{
  MasterSchedulerBackend *parent = (MasterSchedulerBackend*) getParentPointer_in_IMasterScheduler((IMasterScheduler*) pIMasterScheduler);
  Shutdown_in_MasterSchedulerBackend(parent);
}

////void MasterSchedulerBackend::Add(const std::shared_ptr<IMasterTask>& task, IMasterTaskRunner& runner)
void Add_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTask* task, IMasterTaskRunner* runner)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Add_in_MasterSchedulerBackend1"<<'\n';
#endif
  if (pMasterSchedulerBackend->isShutdown)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Add_in_MasterSchedulerBackend1_"<<'\n';
    decrement_stack_info();
#endif
    return;
  }

////    this->tasks.emplace_back(task, runner);
  Record_in_MasterSchedulerBackend rRecord_in_MasterSchedulerBackend;
  Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2(&rRecord_in_MasterSchedulerBackend,
      task, runner);
  pMasterSchedulerBackend->tasks.push_back(rRecord_in_MasterSchedulerBackend);

//   void PostCheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
////    this->PostCheckForTaskRun();
  PostCheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Add_in_MasterSchedulerBackend2_"<<'\n';
  decrement_stack_info();
#endif
}
void Add_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTask* task, IMasterTaskRunner* runner)
{
  MasterSchedulerBackend *parent = (MasterSchedulerBackend*) getParentPointer_in_IMasterScheduler((IMasterScheduler*) pIMasterScheduler);
  Add_in_MasterSchedulerBackend(parent, task, runner);
}

boolean checkForOwnership_in_SetRunnerOffline(Record_in_MasterSchedulerBackend *record);
boolean checkForOwnership_in_SetRunnerOffline(Record_in_MasterSchedulerBackend *record)
{
  Timestamp *now = (Timestamp*)pPointerGlobal1;
  IMasterTaskRunner *runner = (IMasterTaskRunner*)pPointerGlobal2;
////    auto checkForOwnership = [now, &runner](const Record& record) -> bool {
//        boolean BelongsTo_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend, IMasterTaskRunner* runner);
////        if (record.BelongsTo(runner))
////        {
////            if (!record.task->IsRecurring())
////            {
////                record.task->OnLowerLayerClose(now);
////            }

////            return true;
////        }

////        return false;
////    };
  if (BelongsTo_in_Record_in_MasterSchedulerBackend(record, runner))
  {
//boolean IsRecurring_in_IMasterTask(IMasterTask *pIMasterTask);
////            if (!record.task->IsRecurring())
    if (!IsRecurring_in_IMasterTask(record->task))
    {
//void OnLowerLayerClose_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
////                record.task->OnLowerLayerClose(now);
      OnLowerLayerClose_in_IMasterTask(record->task, *now);
    }
    return true;
  }
  return false;
}

////void MasterSchedulerBackend::SetRunnerOffline(const IMasterTaskRunner& runner)
void SetRunnerOffline_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTaskRunner* runner)
{
  if (pMasterSchedulerBackend->isShutdown)
    return;

////    const auto now = Timestamp(this->executor->get_time());
  Timestamp now;
  Timestamp_in_TimestampOver2(&now, get_time_in_IExecutorExe4cpp(pMasterSchedulerBackend->executor));

////    auto checkForOwnership = [now, &runner](const Record& record) -> bool {
////        if (record.BelongsTo(runner))
////        {
////            if (!record.task->IsRecurring())
////            {
////                record.task->OnLowerLayerClose(now);
////            }

////            return true;
////        }

////        return false;
////    };

  pPointerGlobal1 = &now;
  pPointerGlobal2 = runner;
////    if (this->current && checkForOwnership(this->current))
  if (checkForOwnership_in_SetRunnerOffline(&(pMasterSchedulerBackend->current)))
//       void Clear_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend);
////        this->current.Clear();
    Clear_in_Record_in_MasterSchedulerBackend(&(pMasterSchedulerBackend->current));

  // move erase idiom
////    this->tasks.erase(std::remove_if(this->tasks.begin(), this->tasks.end(), checkForOwnership), this->tasks.end());
//    pMasterSchedulerBackend->tasks.erase(std::remove_if(pMasterSchedulerBackend->tasks.begin(), pMasterSchedulerBackend->tasks.end(),
//                checkForOwnership_in_SetRunnerOffline), pMasterSchedulerBackend->tasks.end());
  auto current = pMasterSchedulerBackend->tasks.begin();
  while (current != pMasterSchedulerBackend->tasks.end())
  {
    Record_in_MasterSchedulerBackend tmp = *current;
    if(checkForOwnership_in_SetRunnerOffline(&tmp)) pMasterSchedulerBackend->tasks.erase(current);
    current++;
  }

//   void PostCheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
////    this->PostCheckForTaskRun();
  PostCheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);
}

void SetRunnerOffline_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTaskRunner* runner)
{
  MasterSchedulerBackend *parent = (MasterSchedulerBackend*) getParentPointer_in_IMasterScheduler((IMasterScheduler*) pIMasterScheduler);
  SetRunnerOffline_in_MasterSchedulerBackend(parent, runner);
}

////bool MasterSchedulerBackend::CompleteCurrentFor(const IMasterTaskRunner& runner)
boolean CompleteCurrentFor_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTaskRunner* runner)
{
  // no active task
////    if (!this->current)
////        return false;

  // active task not for this runner
////    if (!this->current.BelongsTo(runner))
  if (!BelongsTo_in_Record_in_MasterSchedulerBackend(&(pMasterSchedulerBackend->current), runner))
    return false;

////    if (this->current.task->IsRecurring())
  if (IsRecurring_in_IMasterTask(pMasterSchedulerBackend->current.task))
  {
//    void Add_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTask* task, IMasterTaskRunner* runner);
////        this->Add(this->current.task, *this->current.runner);
    Add_in_MasterSchedulerBackend(pMasterSchedulerBackend, pMasterSchedulerBackend->current.task, pMasterSchedulerBackend->current.runner);
  }

//       void Clear_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend);
////    this->current.Clear();
  Clear_in_Record_in_MasterSchedulerBackend(&(pMasterSchedulerBackend->current));

////    this->PostCheckForTaskRun();
  PostCheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);

  return true;
}
boolean CompleteCurrentFor_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTaskRunner* runner)
{
  MasterSchedulerBackend *parent = (MasterSchedulerBackend*) getParentPointer_in_IMasterScheduler((IMasterScheduler*) pIMasterScheduler);
  return CompleteCurrentFor_in_MasterSchedulerBackend(parent, runner);
}

void callback_in_Demand(void);
void callback_in_Demand(void)
{
  MasterSchedulerBackend *pMasterSchedulerBackend = (MasterSchedulerBackend*)pPointerGlobal1;
  IMasterTask *task = (IMasterTask*)pPointerGlobal2;
////    auto callback = [this, task, self = shared_from_this()]() {
//void SetMinExpiration_in_IMasterTask(IMasterTask *pIMasterTask);
////        task->SetMinExpiration();
//   boolean CheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
////        this->CheckForTaskRun();
////    };
  SetMinExpiration_in_IMasterTask(task);
  CheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);
}
////void MasterSchedulerBackend::Demand(const std::shared_ptr<IMasterTask>& task)
void Demand_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, IMasterTask* task)
{
////    auto callback = [this, task, self = shared_from_this()]() {
////        task->SetMinExpiration();
////        this->CheckForTaskRun();
////    };

  pPointerGlobal1 = pMasterSchedulerBackend;
  pPointerGlobal2 = task;
//void Post_in_IExecutorExe4cpp(IExecutorExe4cpp *, void (*pAction)(void));
////    this->executor->post(callback);
  Post_in_IExecutorExe4cpp(pMasterSchedulerBackend->executor, callback_in_Demand);
}
void Demand_in_MasterSchedulerBackend_override(void *pIMasterScheduler, IMasterTask* task)
{
  MasterSchedulerBackend *parent = (MasterSchedulerBackend*) getParentPointer_in_IMasterScheduler((IMasterScheduler*) pIMasterScheduler);
  Demand_in_MasterSchedulerBackend(parent, task);
}

////void MasterSchedulerBackend::Evaluate() //Оценивать
void Evaluate_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend)
{
//   void PostCheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
////    this->PostCheckForTaskRun();
  PostCheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);
}
void Evaluate_in_MasterSchedulerBackend_override(void *pIMasterScheduler)
{
  MasterSchedulerBackend *parent = (MasterSchedulerBackend*) getParentPointer_in_IMasterScheduler((IMasterScheduler*) pIMasterScheduler);
  Evaluate_in_MasterSchedulerBackend(parent);
}

void callback_in_PostCheckForTaskRun(void);
void callback_in_PostCheckForTaskRun(void)
{
  MasterSchedulerBackend* pMasterSchedulerBackend = (MasterSchedulerBackend*)pPointerGlobal1;
////        this->executor->post([this, self = shared_from_this()]() { this->CheckForTaskRun(); });
  CheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);
}
////void MasterSchedulerBackend::PostCheckForTaskRun()
void PostCheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{PostCheckForTaskRun_in_MasterSchedulerBackend1"<<'\n';
#endif
  pPointerGlobal1 = pMasterSchedulerBackend;
  if (!pMasterSchedulerBackend->taskCheckPending)//В ожидании
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*PostCheckForTaskRun_in_MasterSchedulerBackend2"<<'\n';
#endif
    pMasterSchedulerBackend->taskCheckPending = true;
////        this->executor->post([this, self = shared_from_this()]() { this->CheckForTaskRun(); });
    Post_in_IExecutorExe4cpp(pMasterSchedulerBackend->executor, callback_in_PostCheckForTaskRun);
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}PostCheckForTaskRun_in_MasterSchedulerBackend_"<<'\n';
  decrement_stack_info();
#endif
}

void callback_in_CheckForTaskRun(void);
void callback_in_CheckForTaskRun(void)
{
  MasterSchedulerBackend* pMasterSchedulerBackend = (MasterSchedulerBackend*)pPointerGlobal1;
////    auto callback = [this, self = shared_from_this()]() { this->CheckForTaskRun(); };
  CheckForTaskRun_in_MasterSchedulerBackend(pMasterSchedulerBackend);
}
////bool MasterSchedulerBackend::CheckForTaskRun()
boolean CheckForTaskRun_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{CheckForTaskRun_in_MasterSchedulerBackend1"<<'\n';
#endif
  if (pMasterSchedulerBackend->isShutdown)
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}CheckForTaskRun_in_MasterSchedulerBackend1_"<<'\n';
  decrement_stack_info();
#endif
    return false;
}

  pMasterSchedulerBackend->taskCheckPending = false;

//    void RestartTimeoutTimer_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
////    this->RestartTimeoutTimer();
  RestartTimeoutTimer_in_MasterSchedulerBackend(pMasterSchedulerBackend);

////    if (this->current)
////        return false;

////    const auto now = Timestamp(this->executor->get_time());
  Timestamp now;
  Timestamp_in_TimestampOver2(&now, get_time_in_IExecutorExe4cpp(pMasterSchedulerBackend->executor));

  // try to find a task that can run
  auto current = pMasterSchedulerBackend->tasks.begin();

  ++current;
  ++current;
//  ++current;

  auto best_task = current;

  uint16_t numTask = getNumTask_in_MasterSchedulerBackend(pMasterSchedulerBackend);

  Record_in_MasterSchedulerBackend best_rec = pMasterSchedulerBackend->tasks[numTask];

  if (current == pMasterSchedulerBackend->tasks.end())
{
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}CheckForTaskRun_in_MasterSchedulerBackend2_"<<'\n';
  decrement_stack_info();
#endif
    return false;
}
  ++current;
/*
  while (current != pMasterSchedulerBackend->tasks.end())
  {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*CheckForTaskRun_in_MasterSchedulerBackend2"<<'\n';
#endif
//   Comparison_in_MasterSchedulerBackend_uint8_t GetBestTaskToRun_in_MasterSchedulerBackend_static(Timestamp* now, Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);
////        if (GetBestTaskToRun(now, *best_task, *current) == Comparison::RIGHT)
    Record_in_MasterSchedulerBackend crt = *current;
    Record_in_MasterSchedulerBackend bst = *best_task;
    if (GetBestTaskToRun_in_MasterSchedulerBackend_static(&now, &bst, &crt)
        == Comparison_in_MasterSchedulerBackend_RIGHT)
    {
      best_task = current;
    }

    ++current;
  }
*/
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*CheckForTaskRun_in_MasterSchedulerBackend3"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pMasterSchedulerBackend->tasks.size()= "<<(uint16_t)pMasterSchedulerBackend->tasks.size()<<'\n';
#endif
  // is the task runnable now?
//Timestamp ExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
///    const auto is_expired = now >= best_task->task->ExpirationTime();
  Timestamp tmp = ExpirationTime_in_IMasterTask(best_task->task);
  boolean is_expired = true;//operatorGTEQ_in_Timestamp(&now, &tmp);
  if (is_expired)
  {
    pMasterSchedulerBackend->current = best_rec;////*best_task;
////    pMasterSchedulerBackend->tasks.erase(best_task);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*CheckForTaskRun_in_MasterSchedulerBackend4"<<'\n';
#endif

//boolean Run_in_IMasterTaskRunner(IMasterTaskRunner *pIMasterTaskRunner, IMasterTask* task);
////        this->current.runner->Run(this->current.task);
    Run_in_IMasterTaskRunner(pMasterSchedulerBackend->current.runner, pMasterSchedulerBackend->current.task);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}CheckForTaskRun_in_MasterSchedulerBackend3_"<<'\n';
  decrement_stack_info();
#endif
    return true;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*CheckForTaskRun_in_MasterSchedulerBackend5"<<'\n';
#endif

////    auto callback = [this, self = shared_from_this()]() { this->CheckForTaskRun(); };

////    this->taskTimer.cancel();
  cancel_in_TimerExe4cpp(&(pMasterSchedulerBackend->taskTimer));

  pPointerGlobal1 = pMasterSchedulerBackend;

//TimerExe4cpp Start_in_IExecutorExe4cpp(IExecutorExe4cpp *, uint32_t duration, void (*pAction)(void));
////    this->taskTimer = this->executor->start(best_task->task->ExpirationTime().value, callback);
//Timestamp ExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
  uint32_t duration = ExpirationTime_in_IMasterTask(best_task->task).time_point_value;
  pMasterSchedulerBackend->taskTimer = Start_in_IExecutorExe4cpp(pMasterSchedulerBackend->executor,
                                       duration, callback_in_CheckForTaskRun);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}CheckForTaskRun_in_MasterSchedulerBackend4_"<<'\n';
  decrement_stack_info();
#endif
  return false;
}

void callback_in_RestartTimeoutTimer(void);
void callback_in_RestartTimeoutTimer(void)
{
////            = this->executor->start(min.value, [this, self = shared_from_this()]() { this->TimeoutTasks(); });
  MasterSchedulerBackend* pMasterSchedulerBackend = (MasterSchedulerBackend*)pPointerGlobal1;
  TimeoutTasks_in_MasterSchedulerBackend(pMasterSchedulerBackend);
}
////void MasterSchedulerBackend::RestartTimeoutTimer()
void RestartTimeoutTimer_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend)
{
  if (pMasterSchedulerBackend->isShutdown)
    return;

//Timestamp Max_in_Timestamp_static(void);
////    auto min = Timestamp::Max();
  Timestamp mint = Max_in_Timestamp_static();

  for (auto& record : pMasterSchedulerBackend->tasks)
  {
//Timestamp StartExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
//boolean IsRecurring_in_IMasterTask(IMasterTask *pIMasterTask);
////        if (!record.task->IsRecurring() && (record.task->StartExpirationTime() < min))
    Timestamp tmp = StartExpirationTime_in_IMasterTask(record.task);
//boolean  operatorLT_in_Timestamp(Timestamp* pTimestamp, Timestamp* other);
    if (!IsRecurring_in_IMasterTask(record.task) && (operatorLT_in_Timestamp(&tmp, &mint)))
    {
////            min = record.task->StartExpirationTime();
      mint = StartExpirationTime_in_IMasterTask(record.task);
    }
  }

////    this->taskStartTimeout.cancel();
  cancel_in_TimerExe4cpp(&(pMasterSchedulerBackend->taskStartTimeout));

//boolean  operatorEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other);
////    if (min != Timestamp::Max())
  Timestamp tmp = Max_in_Timestamp_static();
  if (!operatorEQ_in_Timestamp(&mint, &tmp))
  {
//boolean cancel_in_TimerExe4cpp(TimerExe4cpp *pTimerExe4cpp);
////        this->taskStartTimeout.cancel();
    cancel_in_TimerExe4cpp(&(pMasterSchedulerBackend->taskStartTimeout));

    pPointerGlobal1 = pMasterSchedulerBackend;
//TimerExe4cpp Start_in_IExecutorExe4cpp(IExecutorExe4cpp *, uint32_t duration, void (*pAction)(void));
////        this->taskStartTimeout
////            = this->executor->start(min.value, [this, self = shared_from_this()]() { this->TimeoutTasks(); });
    pMasterSchedulerBackend->taskStartTimeout =
      Start_in_IExecutorExe4cpp(pMasterSchedulerBackend->executor, mint.time_point_value, callback_in_RestartTimeoutTimer);
  }
}

boolean isTimedOut_in_TimeoutTasks(Record_in_MasterSchedulerBackend *record);
boolean isTimedOut_in_TimeoutTasks(Record_in_MasterSchedulerBackend *record)
{
  MasterSchedulerBackend* pMasterSchedulerBackend = (MasterSchedulerBackend*)pPointerGlobal1;
////    auto isTimedOut = [now = Timestamp(this->executor->get_time())](const Record& record) -> bool {
////        if (record.task->IsRecurring() || record.task->StartExpirationTime() > now)
////        {
////            return false;
////        }

//void OnStartTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
////        record.task->OnStartTimeout(now);

////        return true;
////    };
  Timestamp now;
  Timestamp_in_TimestampOver2(&now, get_time_in_IExecutorExe4cpp(pMasterSchedulerBackend->executor));
  Timestamp tmpt = StartExpirationTime_in_IMasterTask(record->task);
  boolean tmpb = operatorGTEQ_in_Timestamp(&now, &tmpt);
  if (IsRecurring_in_IMasterTask(record->task) || tmpb)
  {
    return false;
  }
  OnStartTimeout_in_IMasterTask(record->task, now);
  return true;
}
////void MasterSchedulerBackend::TimeoutTasks()
void TimeoutTasks_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend)
{
  if (pMasterSchedulerBackend->isShutdown)
    return;

  // find the minimum start timeout value
////    auto isTimedOut = [now = Timestamp(this->executor->get_time())](const Record& record) -> bool {
////        if (record.task->IsRecurring() || record.task->StartExpirationTime() > now)
////        {
////            return false;
////        }

////        record.task->OnStartTimeout(now);

////        return true;
////    };

  pPointerGlobal1 = pMasterSchedulerBackend;
  // erase-remove idion (https://en.wikipedia.org/wiki/Erase-remove_idiom)
////    this->tasks.erase(std::remove_if(this->tasks.begin(), this->tasks.end(), isTimedOut), this->tasks.end());
//    pMasterSchedulerBackend->tasks.erase(std::remove_if(pMasterSchedulerBackend->tasks.begin(),
//                  pMasterSchedulerBackend->tasks.end(), isTimedOut_in_TimeoutTasks), pMasterSchedulerBackend->tasks.end());
  auto current = pMasterSchedulerBackend->tasks.begin();
  while (current != pMasterSchedulerBackend->tasks.end())
  {
    Record_in_MasterSchedulerBackend tmp = *current;
    if(isTimedOut_in_TimeoutTasks(&tmp)) pMasterSchedulerBackend->tasks.erase(current);
    current++;
  }

//    void RestartTimeoutTimer_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend);
////    this->RestartTimeoutTimer();
  RestartTimeoutTimer_in_MasterSchedulerBackend(pMasterSchedulerBackend);
}

////MasterSchedulerBackend::Comparison MasterSchedulerBackend::GetBestTaskToRun(const Timestamp& now,
////                                                                            const Record& left,
////                                                                            const Record& right)
Comparison_in_MasterSchedulerBackend_uint8_t GetBestTaskToRun_in_MasterSchedulerBackend_static(Timestamp* now,
    Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right)
{
//   Comparison_in_MasterSchedulerBackend_uint8_t CompareEnabledStatus_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);
////    const auto BEST_ENABLED_STATUS = CompareEnabledStatus(left, right);
  Comparison_in_MasterSchedulerBackend_uint8_t BEST_ENABLED_STATUS = CompareEnabledStatus_in_MasterSchedulerBackend_static(left, right);

  if (BEST_ENABLED_STATUS != Comparison_in_MasterSchedulerBackend_SAME)
  {
    // if one task is disabled, return the other task
// если одна задача отключена, возвращаем другую задачу
    return BEST_ENABLED_STATUS;
  }
  /*
  //   Comparison_in_MasterSchedulerBackend_uint8_t CompareBlockedStatus_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);
  ////    const auto BEST_BLOCKED_STATUS = CompareBlockedStatus(left, right);
    Comparison_in_MasterSchedulerBackend_uint8_t BEST_BLOCKED_STATUS = CompareBlockedStatus_in_MasterSchedulerBackend_static(left, right);

    if (BEST_BLOCKED_STATUS != Comparison_in_MasterSchedulerBackend_SAME)
    {
      // if one task is blocked and the other isn't, return the unblocked task
  // если одна задача заблокирована, а другая нет, возвращаем разблокированную задачу
      return BEST_BLOCKED_STATUS;
    }
  */
//   Comparison_in_MasterSchedulerBackend_uint8_t CompareTime_in_MasterSchedulerBackend_static(Timestamp* now, Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);
////    const auto EARLIEST_EXPIRATION = CompareTime(now, left, right);
  Comparison_in_MasterSchedulerBackend_uint8_t EARLIEST_EXPIRATION = CompareTime_in_MasterSchedulerBackend_static(now, left, right);

//   Comparison_in_MasterSchedulerBackend_uint8_t ComparePriority_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right);
////    const auto BEST_PRIORITY = ComparePriority(left, right);
  Comparison_in_MasterSchedulerBackend_uint8_t BEST_PRIORITY = ComparePriority_in_MasterSchedulerBackend_static(left, right);

  // if the expiration times are the same, break based on priority, otherwise go with the expiration time
// если время истечения одинаковое, прерываем в зависимости от приоритета, в противном случае продолжаем использовать время истечения
  return (EARLIEST_EXPIRATION == Comparison_in_MasterSchedulerBackend_SAME) ? BEST_PRIORITY : EARLIEST_EXPIRATION;
}

////MasterSchedulerBackend::Comparison MasterSchedulerBackend::CompareTime(const Timestamp& now,
////                                                                       const Record& left,
////                                                                       const Record& right)
Comparison_in_MasterSchedulerBackend_uint8_t CompareTime_in_MasterSchedulerBackend_static(Timestamp* now, Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right)
{
  // if tasks are already expired, the effective expiration time is NOW
// если срок действия задач уже истек, эффективное время истечения СЕЙЧАС
//Timestamp StartExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
//boolean IsExpired_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp* now);
////    const auto leftTime = left.task->IsExpired(now) ? now : left.task->ExpirationTime();
  Timestamp leftTime = IsExpired_in_IMasterTask(left->task, now) ? *now : StartExpirationTime_in_IMasterTask(left->task);

////  const auto rightTime = right.task->IsExpired(now) ? now : right.task->ExpirationTime();
  Timestamp rightTime = IsExpired_in_IMasterTask(right->task, now) ? *now : StartExpirationTime_in_IMasterTask(right->task);

//boolean  operatorLT_in_Timestamp(Timestamp* pTimestamp, Timestamp* other);
////    if (leftTime < rightTime)
  if (operatorLT_in_Timestamp(&leftTime, &rightTime))
  {
    return Comparison_in_MasterSchedulerBackend_LEFT;
  }
////    if (rightTime < leftTime)
  if (operatorLT_in_Timestamp(&rightTime, &leftTime))
  {
    return Comparison_in_MasterSchedulerBackend_RIGHT;
  }
  else
  {
    return Comparison_in_MasterSchedulerBackend_SAME;
  }
}

////MasterSchedulerBackend::Comparison MasterSchedulerBackend::CompareEnabledStatus(const Record& left, const Record& right)
Comparison_in_MasterSchedulerBackend_uint8_t CompareEnabledStatus_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right)
{
//Timestamp ExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
////    if (left.task->ExpirationTime() == Timestamp::Max()) // left is disabled, check the right
  Timestamp tmp1 = ExpirationTime_in_IMasterTask(left->task);
  Timestamp tmp2 = Max_in_Timestamp_static();
  if (operatorEQ_in_Timestamp(&tmp1, &tmp2))
  {
////        return right.task->ExpirationTime() == Timestamp::Max() ? Comparison::SAME : Comparison::RIGHT;
    tmp1 = ExpirationTime_in_IMasterTask(right->task);
    return operatorEQ_in_Timestamp(&tmp1, &tmp2) ? Comparison_in_MasterSchedulerBackend_SAME : Comparison_in_MasterSchedulerBackend_RIGHT;
  }

////    if (right.task->ExpirationTime() == Timestamp::Max()) // left is enabled, right is disabled
  tmp1 = ExpirationTime_in_IMasterTask(right->task);
  if (operatorEQ_in_Timestamp(&tmp1, &tmp2))
  {
////        return Comparison::LEFT;
    return Comparison_in_MasterSchedulerBackend_LEFT;
  }
  else
  {
    // both tasks are enabled
///        return Comparison::SAME;
    return Comparison_in_MasterSchedulerBackend_SAME;
  }
}
/*
////MasterSchedulerBackend::Comparison MasterSchedulerBackend::CompareBlockedStatus(const Record& left, const Record& right)
Comparison_in_MasterSchedulerBackend_uint8_t CompareBlockedStatus_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right)
{
//boolean IsBlocked_in_IMasterTask(IMasterTask *pIMasterTask);
////    if (left.task->IsBlocked())
  if (IsBlocked_in_IMasterTask(left->task))
  {
////        return right.task->IsBlocked() ? Comparison::SAME : Comparison::RIGHT;
    return IsBlocked_in_IMasterTask(right->task) ? Comparison_in_MasterSchedulerBackend_SAME : Comparison_in_MasterSchedulerBackend_RIGHT;
  }

////    return right.task->IsBlocked() ? Comparison::LEFT : Comparison::SAME;
  return IsBlocked_in_IMasterTask(right->task) ? Comparison_in_MasterSchedulerBackend_LEFT : Comparison_in_MasterSchedulerBackend_SAME;
}
*/
/////MasterSchedulerBackend::Comparison MasterSchedulerBackend::ComparePriority(const Record& left, const Record& right)
Comparison_in_MasterSchedulerBackend_uint8_t ComparePriority_in_MasterSchedulerBackend_static(Record_in_MasterSchedulerBackend* left, Record_in_MasterSchedulerBackend* right)
{
//int Priority_in_IMasterTask(IMasterTask *pIMasterTask);
////    if (left.task->Priority() < right.task->Priority())
  int tmp1 = Priority_in_IMasterTask(left->task);
  int tmp2 = Priority_in_IMasterTask(right->task);
  if(tmp1 < tmp2)
  {
////        return Comparison::LEFT;
    return Comparison_in_MasterSchedulerBackend_LEFT;
  }
////    if (right.task->Priority() < left.task->Priority())
  if(tmp2 < tmp1)
  {
////        return Comparison::RIGHT;
    return Comparison_in_MasterSchedulerBackend_RIGHT;
  }
  else
  {
////        return Comparison::SAME;
    return Comparison_in_MasterSchedulerBackend_SAME;
  }
}

////} // namespace opendnp3
void   Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver1(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend)
{
  pRecord_in_MasterSchedulerBackend->runner = NULL;
}

////        Record(const std::shared_ptr<IMasterTask>& task, IMasterTaskRunner& runner) : task(task), runner(&runner) {}
void   Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend,
    IMasterTask* task, IMasterTaskRunner* runner)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2_1"<<'\n';
#endif
  pRecord_in_MasterSchedulerBackend->task = task;
  pRecord_in_MasterSchedulerBackend->runner = runner;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Record_in_MasterSchedulerBackend_in_Record_in_MasterSchedulerBackendOver2__"<<'\n';
  decrement_stack_info();
#endif
}
void Clear_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend)
{
  pRecord_in_MasterSchedulerBackend->task = NULL;//.reset();
  pRecord_in_MasterSchedulerBackend->runner = NULL;//nullptr;
}

boolean BelongsTo_in_Record_in_MasterSchedulerBackend(Record_in_MasterSchedulerBackend *pRecord_in_MasterSchedulerBackend, IMasterTaskRunner* runner)
//Принадлежит
{
////            return this->runner == &runner;
  return pRecord_in_MasterSchedulerBackend->runner == runner;
}

uint16_t getNumTask_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend)
{
  return pMasterSchedulerBackend->numTask;
}
void setNumTask_in_MasterSchedulerBackend(MasterSchedulerBackend *pMasterSchedulerBackend, uint16_t num)
{
  pMasterSchedulerBackend->numTask = num;
}


