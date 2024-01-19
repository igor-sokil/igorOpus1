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

#ifndef OPENDNP3_TASKBEHAVIOR_H
#define OPENDNP3_TASKBEHAVIOR_H

#include "TimeDuration.h"
#include "Timestamp.h"

////namespace opendnp3
////{

/**
 *   All of the configuration parameters that control how the task wil behave
* ¬се параметры конфигурации, которые управл€ют поведением задачи.
 */
////class TaskBehavior
typedef struct
{

////public:
////    static TaskBehavior SingleExecutionNoRetry();

////    static TaskBehavior SingleExecutionNoRetry(const Timestamp& startExpiration);

////    static TaskBehavior ImmediatePeriodic(const TimeDuration& period,
////                                          const TimeDuration& minRetryDelay,
////                                          const TimeDuration& maxRetryDelay);

////    static TaskBehavior SingleImmediateExecutionWithRetry(const TimeDuration& minRetryDelay,
////                                                          const TimeDuration& maxRetryDelay);

////    static TaskBehavior ReactsToIINOnly();

  /**
   * Called when the task succeeds. Resets the retry timeout to the minimum, and returns the new expiration time
  * ¬ызываетс€ при успешном выполнении задачи. —брасывает тайм-аут повтора до минимума и возвращает новое врем€ истечени€ срока действи€.
   */
////    void OnSuccess(const Timestamp& now);

  /**
   * Called when the task fails due to a response timeout
  * ¬ызываетс€, когда задача не выполн€етс€ из-за таймаута ответа.
   */
////    void OnResponseTimeout(const Timestamp& now);

  /**
   * return the current expiration time
   */
////    Timestamp GetExpiration() const
////    {
////        return expiration;
////    }

  /**
   * return the time after which the task should fail if it hasn't start running
  * возвращает врем€, по истечении которого задача должна завершитьс€ неудачно, если она еще не запустилась
   */
////    Timestamp GetStartExpiration() const
////    {
////        return startExpiration;
////    }

  /**
   * reset to the initial state
   */
////    void Reset();

  /**
   * Disable the task
   */
////    void Disable();

////private:
////    TimeDuration CalcNextRetryTimeout() const;

////    TaskBehavior() = delete;

////    TaskBehavior(const TimeDuration& period,
////                 const Timestamp& expiration,
////                 const TimeDuration& minRetryDelay,
////                 const TimeDuration& maxRetryDelay,
////                 const Timestamp& startExpiration);

  TimeDuration period;
  TimeDuration minRetryDelay;
  TimeDuration maxRetryDelay;
  Timestamp startExpiration;//начало истечени€ срока действи€

  // permanently disable the task
  boolean disabled;// = false;

  // The tasks current expiration time
  Timestamp expiration;

  // The current retry delay
  TimeDuration currentRetryDelay;
} TaskBehavior;

void TaskBehavior_in_TaskBehavior(TaskBehavior *pTaskBehavior,
                                  TimeDuration* period,
                                  Timestamp* expiration,
                                  TimeDuration* minRetryDelay,
                                  TimeDuration* maxRetryDelay,
                                  Timestamp* startExpiration);

TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_static(void);

TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_static(Timestamp* startExpiration);

TaskBehavior ImmediatePeriodic_in_TaskBehavior_static(TimeDuration* period,
    TimeDuration* minRetryDelay,
    TimeDuration* maxRetryDelay);

TaskBehavior SingleImmediateExecutionWithRetry_in_TaskBehavior_static(TimeDuration* minRetryDelay,
    TimeDuration* maxRetryDelay);

TaskBehavior ReactsToIINOnly_in_TaskBehavior_static(void);

/**
 * Called when the task succeeds. Resets the retry timeout to the minimum, and returns the new expiration time
* ¬ызываетс€ при успешном выполнении задачи. —брасывает тайм-аут повтора до минимума и возвращает новое врем€ истечени€ срока действи€.
 */
void OnSuccess_in_TaskBehavior(TaskBehavior *pTaskBehavior, Timestamp* now);

/**
 * Called when the task fails due to a response timeout
* ¬ызываетс€, когда задача не выполн€етс€ из-за таймаута ответа.
 */
void OnResponseTimeout_in_TaskBehavior(TaskBehavior *pTaskBehavior, Timestamp* now);

/**
 * return the current expiration time
 */
Timestamp GetExpiration_in_TaskBehavior(TaskBehavior *pTaskBehavior);

/**
 * return the time after which the task should fail if it hasn't start running
* возвращает врем€, по истечении которого задача должна завершитьс€ неудачно, если она еще не запустилась
 */
Timestamp GetStartExpiration_in_TaskBehavior(TaskBehavior *pTaskBehavior);

/**
 * reset to the initial state
 */
void Reset_in_TaskBehavior(TaskBehavior *pTaskBehavior);

/**
 * Disable the task
 */
void Disable_in_TaskBehavior(TaskBehavior *pTaskBehavior);

TimeDuration CalcNextRetryTimeout_in_TaskBehavior(TaskBehavior* pTaskBehavior);

TaskBehavior ReactsToIINOnly_in_TaskBehavior_static(void);

////} // namespace opendnp3

#endif
