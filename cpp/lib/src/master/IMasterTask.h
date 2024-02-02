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
#ifndef OPENDNP3_IMASTERTASK_H
#define OPENDNP3_IMASTERTASK_H

#include "APDUHeader.h"
#include "APDURequest.h"
#include "TaskBehavior.h"
///#include "TaskContext.h"

////#include "opendnp3/logging/Logger.h"
#include "IMasterApplication.h"
#include "TaskConfig.h"

////#include <exe4cpp/IExecutor.h>
////#include <exe4cpp/Typedefs.h>

////namespace opendnp3
////{

#define ResponseResult_in_IMasterTask_uint8_t uint8_t

enum ////class ResponseResult : uint8_t
{
  /// The response was bad, the task has failed
  ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE,

  /// The response was good and the task is complete
  ResponseResult_in_IMasterTask_OK_FINAL,

  /// The response was good and the task should repeat the format, transmit, and await response sequence
  ResponseResult_in_IMasterTask_OK_REPEAT,

  /// The response was good and the task should continue executing. Restart the response timer, and increment
  /// expected SEQ#.
  ResponseResult_in_IMasterTask_OK_CONTINUE
};

/**
 * A generic interface for defining master request/response style tasks
* Общий интерфейс для определения основных задач стиля запроса/ответа.
 */
////class IMasterTask : private Uncopyable
typedef struct
{

////public:

////    IMasterTask(std::shared_ptr<TaskContext> context,
////                IMasterApplication& app,
////                TaskBehavior behavior,
////                const Logger& logger,
////                TaskConfig config);

////    virtual ~IMasterTask();

  /**
   *
   * @return	the name of the task
   */
  char * (*pName_in_IMasterTask)(void *);// const = 0;

  /**
   * The task's priority. Lower numbers are higher priority.
* Приоритет задачи. Меньшие числа имеют более высокий приоритет.
   */
  int (*pPriority_in_IMasterTask)(void *);// const = 0;

  /**
   * Indicates if the task should be rescheduled (true) or discarded
   * after a single execution (false)
* Указывает, следует ли перепланировать задачу (истина) или отказаться от нее.
    * после однократного выполнения (ложь)
   */
  boolean (*pIsRecurring_in_IMasterTask)(void *);// const = 0;

  /**
   * The time when this task can run again.
* Время, когда эта задача может быть запущена снова.
   */
////    Timestamp ExpirationTime() const;

  /**
   * Helper to test if the task is expired
* Помощник для проверки, истек ли срок действия задачи
   */
////    bool IsExpired(const Timestamp& now) const
////    {
////        return now >= this->ExpirationTime();
////    }

  /**
   * Build a request APDU.
   *
   * Return false if some kind of internal error prevents the task for formatting the request.
  * Возвращайте false, если какая-то внутренняя ошибка не позволяет выполнить задачу по форматированию запроса.
   */
  boolean (*pBuildRequest_in_IMasterTask)(void *, APDURequest* request, uint8_t seq);// = 0;

  /**
   * Handler for responses
   */
////    ResponseResult OnResponse_in_IMasterTask(IMasterTask *pIMasterTask, const APDUResponseHeader& response, const ser4cpp::rseq_t& objects, Timestamp now);

  /**
   * Called when a response times out
   */
////    void OnResponseTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);

  /**
   * Called when the layer closes while the task is executing.
* Вызывается, когда слой закрывается во время выполнения задачи.
   */
////    void OnLowerLayerClose_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);

  /**
   * The start timeout expired before the task could be run
* Тайм-аут запуска истек до того, как задачу удалось запустить.
   */
////    void OnStartTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);

  /**
   * Called when the master is unable to format the request associated with the task
* Вызывается, когда мастер не может отформатировать запрос, связанный с задачей.
   */
////    void OnMessageFormatError_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);

  /**
   * Called when the task first starts, before the first request is formatted
* Вызывается при первом запуске задачи, до форматирования первого запроса.
   */
////    void OnStart_in_IMasterTask(IMasterTask *pIMasterTask);

  /**
   * Set the expiration time to minimum. The scheduler must also be informed
* Установите срок годности на минимум. Планировщик также должен быть проинформирован
   */
////    void SetMinExpiration_in_IMasterTask(IMasterTask *pIMasterTask);

  /**
   * Check if the task is blocked from executing by another task
   */
////    boolean IsBlocked_in_IMasterTask(IMasterTask *pIMasterTask);
////    {
////        return this->context->IsBlocked(*this);
////    }

////protected:
  // called during OnStart() to initialize any state for a new run
  void (*pInitialize_in_IMasterTask)(void *);// {}

  ResponseResult_in_IMasterTask_uint8_t (*pProcessResponse_in_IMasterTask)(void *, APDUResponseHeader* response, RSeq_for_Uint16_t* objects);// = 0;

////    void CompleteTask_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion result, Timestamp now);

  void (*pOnTaskComplete_in_IMasterTask)(void *, TaskCompletion_uint8_t result, Timestamp now);// {}

  boolean (*pIsEnabled_in_IMasterTask)(void *);
////    {
////        return true;
////    }

  MasterTaskType_uint8_t (*pGetTaskType_in_IMasterTask)(void *);// const = 0;

//    TaskContext* context;
  IMasterApplication* application;
////    Logger logger;

  // Validation helpers for various behaviors to avoid deep inheritance
////    bool ValidateSingleResponse(const APDUResponseHeader& header);
////    bool ValidateNullResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects);
////    bool ValidateNoObjects(const ser4cpp::rseq_t& objects);
////    bool ValidateInternalIndications(const APDUResponseHeader& header);

////private:
  /**
   * Allows tasks to enter a blocking mode where lower priority
   * tasks cannot run until this task completes
  * Позволяет задачам переходить в режим блокировки с более низким приоритетом.
    * задачи не могут выполняться, пока эта задача не завершится
   */
  boolean (*pBlocksLowerPriority_in_IMasterTask)(void *);// const = 0;

////    IMasterTask();

  TaskConfig config;
  TaskBehavior behavior;

  void *pParentPointer_in_IMasterTask;
} IMasterTask;

void IMasterTask_in_IMasterTask(IMasterTask *pIMasterTask,
//                TaskContext* context,
                                IMasterApplication* app,
                                TaskBehavior behavior,
//                const Logger& logger,
                                TaskConfig config);
boolean ValidateSingleResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header);
boolean ValidateNullResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
boolean ValidateNoObjects_in_IMasterTask(IMasterTask *pIMasterTask, RSeq_for_Uint16_t* objects);
boolean ValidateInternalIndications_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header);
void CompleteTask_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);
boolean IsBlocked_in_IMasterTask(IMasterTask *pIMasterTask);
void SetMinExpiration_in_IMasterTask(IMasterTask *pIMasterTask);
void OnStart_in_IMasterTask(IMasterTask *pIMasterTask);
void OnMessageFormatError_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
void OnStartTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
void OnLowerLayerClose_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
void OnResponseTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now);
ResponseResult_in_IMasterTask_uint8_t OnResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* response, RSeq_for_Uint16_t* objects, Timestamp now);
Timestamp StartExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
boolean IsExpired_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp* now);
Timestamp StartExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
Timestamp ExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);


char * Name_in_IMasterTask(IMasterTask *pIMasterTask);
int Priority_in_IMasterTask(IMasterTask *pIMasterTask);
boolean IsRecurring_in_IMasterTask(IMasterTask *pIMasterTask);
boolean BuildRequest_in_IMasterTask(IMasterTask *pIMasterTask, APDURequest* request, uint8_t seq);
void Initialize_in_IMasterTask(IMasterTask *pIMasterTask);
void Initialize_in_IMasterTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* response, RSeq_for_Uint16_t* objects);

void OnTaskComplete_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);
void OnTaskComplete_in_IMasterTask_override(void *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);

boolean IsEnabled_in_IMasterTask(IMasterTask *pIMasterTask);
boolean IsEnabled_in_IMasterTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_IMasterTask(IMasterTask *pIMasterTask);
boolean BlocksLowerPriority_in_IMasterTask(IMasterTask *pIMasterTask);

void* getParentPointer_in_IMasterTask(IMasterTask*);
void  setParentPointer_in_IMasterTask(IMasterTask*, void*);


////} // namespace opendnp3

#endif
