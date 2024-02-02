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
#include "TaskBehavior.h"

////#include <limits>

////namespace opendnp3
////{

////TaskBehavior TaskBehavior::SingleExecutionNoRetry()
TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_staticOver1(void)
{
// TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_static(Timestamp* startExpiration);
////    return SingleExecutionNoRetry(Timestamp::Max()); // no start expiration
  Timestamp smax = Max_in_Timestamp_static();
  return SingleExecutionNoRetry_in_TaskBehavior_staticOver2(&smax);
}

////TaskBehavior TaskBehavior::SingleExecutionNoRetry(const Timestamp& startExpiration)
TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_staticOver2(Timestamp* startExpiration)
{
//TimeDuration Min_in_TimeDuration_static(void);
//Timestamp Min_in_Timestamp_static(void);
////    return TaskBehavior(TimeDuration::Min(), // not periodic
////                        Timestamp::Min(),    // run immediately
////                        TimeDuration::Max(), TimeDuration::Max(), startExpiration);
  TimeDuration dmin = Min_in_TimeDuration_static();
  Timestamp smin = Min_in_Timestamp_static();
  TimeDuration dmax = Max_in_TimeDuration_static();
  TaskBehavior tTaskBehavior;
  TaskBehavior_in_TaskBehavior(&tTaskBehavior, &dmin, &smin, &dmax, &dmax, startExpiration);
  return tTaskBehavior;
}

////TaskBehavior TaskBehavior::ImmediatePeriodic(const TimeDuration& period,
////                                             const TimeDuration& minRetryDelay,
////                                             const TimeDuration& maxRetryDelay)
TaskBehavior ImmediatePeriodic_in_TaskBehavior_static(TimeDuration* period,
    TimeDuration* minRetryDelay,
    TimeDuration* maxRetryDelay)
{
////    return TaskBehavior(period,
////                        Timestamp::Min(), // run immediately
////                        minRetryDelay, maxRetryDelay,
////                        Timestamp::Max() // no start expiraion
////    );
  Timestamp smin = Min_in_Timestamp_static();
  Timestamp smax = Max_in_Timestamp_static();
  TaskBehavior tTaskBehavior;
  TaskBehavior_in_TaskBehavior(&tTaskBehavior, period, &smin, minRetryDelay, maxRetryDelay, &smax);
  return tTaskBehavior;
}

////TaskBehavior TaskBehavior::SingleImmediateExecutionWithRetry(const TimeDuration& minRetryDelay,
////                                                             const TimeDuration& maxRetryDelay)
TaskBehavior SingleImmediateExecutionWithRetry_in_TaskBehavior_static(TimeDuration* minRetryDelay, TimeDuration* maxRetryDelay)
{
////    return TaskBehavior(TimeDuration::Min(), // not periodic
////                        Timestamp::Min(),    // run immediatey
////                        minRetryDelay, maxRetryDelay, Timestamp::Max());
  TimeDuration dmin = Min_in_TimeDuration_static();
  Timestamp smin = Min_in_Timestamp_static();
  Timestamp smax = Max_in_Timestamp_static();
  TaskBehavior tTaskBehavior;
  TaskBehavior_in_TaskBehavior(&tTaskBehavior, &dmin, &smin, minRetryDelay, maxRetryDelay, &smax);
  return tTaskBehavior;
}

////TaskBehavior TaskBehavior::ReactsToIINOnly()
TaskBehavior ReactsToIINOnly_in_TaskBehavior_static(void)
{
////    return TaskBehavior(TimeDuration::Min(), // not periodic
////                        Timestamp::Max(),    // only run when needed
////                        TimeDuration::Max(), // never retry
////                        TimeDuration::Max(), Timestamp::Max());
  TimeDuration dmin = Min_in_TimeDuration_static();
  TimeDuration dmax = Max_in_TimeDuration_static();
  Timestamp smax = Max_in_Timestamp_static();
  TaskBehavior tTaskBehavior;
  TaskBehavior_in_TaskBehavior(&tTaskBehavior, &dmin, &smax, &dmax, &dmax, &smax);
  return tTaskBehavior;
}

////TaskBehavior::TaskBehavior(const TimeDuration& period,
////                           const Timestamp& expiration,
////                           const TimeDuration& minRetryDelay,
////                           const TimeDuration& maxRetryDelay,
////                           const Timestamp& startExpiration)
////    : period(period),
////      minRetryDelay(minRetryDelay),
////      maxRetryDelay(maxRetryDelay),
////      startExpiration(startExpiration),
////      expiration(expiration),
////      currentRetryDelay(minRetryDelay)
void TaskBehavior_in_TaskBehavior(TaskBehavior *pTaskBehavior,
                                  TimeDuration* period,
                                  Timestamp* expiration,
                                  TimeDuration* minRetryDelay,
                                  TimeDuration* maxRetryDelay,
                                  Timestamp* startExpiration)
{
  pTaskBehavior->period = *period;
  pTaskBehavior->minRetryDelay = *minRetryDelay;
  pTaskBehavior->maxRetryDelay = *maxRetryDelay;
  pTaskBehavior->startExpiration = *startExpiration;
  pTaskBehavior->expiration = *expiration;
  pTaskBehavior->currentRetryDelay = *minRetryDelay;

  pTaskBehavior->disabled = false;
}

////void TaskBehavior::OnSuccess(const Timestamp& now)
void OnSuccess_in_TaskBehavior(TaskBehavior *pTaskBehavior, Timestamp* now)
{
  pTaskBehavior->currentRetryDelay = pTaskBehavior->minRetryDelay;

//Timestamp operatorPLUS_in_Timestamp(Timestamp *pTimestamp, TimeDuration* duration)
//boolean IsNegative_in_TimeDuration(TimeDuration* pTimeDuration);
////    this->expiration = this->period.IsNegative() ? Timestamp::Max() : now + this->period;
  pTaskBehavior->expiration = IsNegative_in_TimeDuration(&(pTaskBehavior->period)) ? Max_in_Timestamp_static() :/// now + this->period;
                              operatorPLUS_in_Timestamp(now, &(pTaskBehavior->period));
}

////void TaskBehavior::OnResponseTimeout(const Timestamp& now)
void OnResponseTimeout_in_TaskBehavior(TaskBehavior *pTaskBehavior, Timestamp* now)
{
//Timestamp operatorPLUS_in_Timestamp(Timestamp *pTimestamp, TimeDuration* duration)
////    this->expiration = now + this->currentRetryDelay;
  pTaskBehavior->expiration = operatorPLUS_in_Timestamp(now, &(pTaskBehavior->currentRetryDelay));

//   TimeDuration CalcNextRetryTimeout_in_TaskBehavior(TaskBehavior* pTaskBehavior);
////    this->currentRetryDelay = this->CalcNextRetryTimeout();
  pTaskBehavior->currentRetryDelay = CalcNextRetryTimeout_in_TaskBehavior(pTaskBehavior);
}

////void TaskBehavior::Reset()
void Reset_in_TaskBehavior(TaskBehavior *pTaskBehavior)
{
  pTaskBehavior->disabled = false;

////    this->expiration = Timestamp::Min();
  pTaskBehavior->expiration = Min_in_Timestamp_static();

  pTaskBehavior->currentRetryDelay = pTaskBehavior->minRetryDelay;
}

////void TaskBehavior::Disable()
void Disable_in_TaskBehavior(TaskBehavior *pTaskBehavior)
{
  pTaskBehavior->disabled = true;
////    this->expiration = Timestamp::Max();
  pTaskBehavior->expiration = Max_in_Timestamp_static();
}

////TimeDuration TaskBehavior::CalcNextRetryTimeout() const
TimeDuration CalcNextRetryTimeout_in_TaskBehavior(TaskBehavior* pTaskBehavior)
{
//TimeDuration Double_in_TimeDuration(TimeDuration *pTimeDuration)
////    const auto doubled = this->currentRetryDelay.Double();
  TimeDuration doubled = Double_in_TimeDuration(&(pTaskBehavior->currentRetryDelay));

////    return (doubled > this->maxRetryDelay) ? this->maxRetryDelay : doubled;
  return (doubled.duration_value > (pTaskBehavior->maxRetryDelay).duration_value) ? pTaskBehavior->maxRetryDelay : doubled;
}

////} // namespace opendnp3
Timestamp GetStartExpiration_in_TaskBehavior(TaskBehavior *pTaskBehavior)
{
  return pTaskBehavior->startExpiration;
}
Timestamp GetExpiration_in_TaskBehavior(TaskBehavior *pTaskBehavior)
{
  return pTaskBehavior->expiration;
}
