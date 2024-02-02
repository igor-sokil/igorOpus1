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
#ifndef OPENDNP3_IMASTERSCHEDULER_H
#define OPENDNP3_IMASTERSCHEDULER_H

#include "IMasterTask.h"
#include "IMasterTaskRunner.h"

////namespace opendnp3
////{

/**
 * Interface used by master sessions to schedule tasks
 */
////class IMasterScheduler
typedef struct
{

////public:
////    virtual ~IMasterScheduler() {}

  void (*pShutdown_in_IMasterScheduler)(void *);// = 0;

  /**
   * Add a single task to the scheduler. The tasks will be started asynchronously,
   * i.e. not by the call to this method
  * Добавьте одну задачу в планировщик. Задачи будут запускаться асинхронно,
    * т.е. не путем вызова этого метода
   */
  void (*pAdd_in_IMasterScheduler)(void *, IMasterTask* task, IMasterTaskRunner* runner);// = 0;

  /**
   * Remove all tasks associated with this context, including the running one
  * Удалить все задачи, связанные с этим контекстом, включая запущенную.
   */
  void (*pSetRunnerOffline_in_IMasterScheduler)(void *, IMasterTaskRunner* runner);// = 0;

  /**
   *
   */
  boolean (*pCompleteCurrentFor_in_IMasterScheduler)(void *, IMasterTaskRunner* runner);// = 0;

  /**
   *  Called if task changes in such a way that it might be runnable sooner than scheduled
  * Вызывается, если задача изменяется таким образом, что ее можно запустить раньше, чем запланировано.
   */
  void (*pEvaluate_in_IMasterScheduler)(void *);// = 0;

  /**
   * Run a task as soon as possible
  * Запустите задачу как можно скорее
   */
  void (*pDemand_in_IMasterScheduler)(void *, IMasterTask* task);// = 0;

  /**
   * Add multiple tasks in one call
  * Добавляйте несколько задач за один звонок
   */
////    void Add_in_IMasterScheduler(std::initializer_list<std::shared_ptr<IMasterTask>> tasks, IMasterTaskRunner& runner)
////    {
////        for (auto& task : tasks)
////            this->Add(task, runner);
////    }

  void *pParentPointer_in_IMasterScheduler;
} IMasterScheduler;

//void IMasterScheduler_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler);

void Shutdown_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler);
void Add_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTask* task, IMasterTaskRunner* runner);
///void Add_in_IMasterScheduler_override(void *pIMasterScheduler, IMasterTask* task, IMasterTaskRunner* runner);
void SetRunnerOffline_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTaskRunner* runner);
boolean CompleteCurrentFor_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTaskRunner* runner);
void Evaluate_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler);
void Demand_in_IMasterScheduler(IMasterScheduler *pIMasterScheduler, IMasterTask* task);

///void Add_in_IMasterSchedulerOver2(IMasterScheduler *pIMasterScheduler, IMasterTask* tasks, IMasterTaskRunner* runner);

void* getParentPointer_in_IMasterScheduler(IMasterScheduler* pIMasterScheduler);
void  setParentPointer_in_IMasterScheduler(IMasterScheduler* pIMasterScheduler, void*);

////} // namespace opendnp3

#endif
