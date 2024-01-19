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
#include "header.h"
#include "IMasterTask.h"

////#include "logging/LogMacros.h"

////#include "opendnp3/logging/LogLevels.h"

////#include <utility>

////namespace opendnp3
////{

////IMasterTask::IMasterTask(std::shared_ptr<TaskContext> context,
////                         IMasterApplication& app,
////                         TaskBehavior behavior,
////                         const Logger& logger,
////                         TaskConfig config)
void IMasterTask_in_IMasterTask(IMasterTask *pIMasterTask,
//                TaskContext* context,
                                IMasterApplication* app,
                                TaskBehavior behavior,
////                const Logger& logger,
                                TaskConfig config)
{
////    : context(std::move(context)), application(&app), logger(logger), config(config), behavior(std::move(behavior))
  pIMasterTask->application = app;
  pIMasterTask->config = config;
  pIMasterTask->behavior = behavior;

  pIMasterTask->pInitialize_in_IMasterTask = Initialize_in_IMasterTask_override;
  pIMasterTask->pOnTaskComplete_in_IMasterTask = OnTaskComplete_in_IMasterTask_override;
  pIMasterTask->pIsEnabled_in_IMasterTask = IsEnabled_in_IMasterTask_override;
}

////IMasterTask::~IMasterTask()
////{
////    context->RemoveBlock(*this);

////    if (config.pCallback)
////    {
////        config.pCallback->OnDestroyed();
////    }
////}

////Timestamp IMasterTask::ExpirationTime() const
Timestamp ExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask)
{
//   Timestamp GetExpiration_in_TaskBehavior(TaskBehavior *pTaskBehavior);
//    boolean IsEnabled_in_IMasterTask(IMasterTask *pIMasterTask);
////    return this->IsEnabled() ? this->behavior.GetExpiration() : Timestamp::Max();
  return IsEnabled_in_IMasterTask(pIMasterTask) ? GetExpiration_in_TaskBehavior(&(pIMasterTask->behavior)) :
         Max_in_Timestamp_static();
}

////Timestamp IMasterTask::StartExpirationTime() const
Timestamp StartExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask)
{
//    Timestamp GetStartExpiration_in_TaskBehavior(TaskBehavior *pTaskBehavior);
////    return this->behavior.GetStartExpiration();
  return GetStartExpiration_in_TaskBehavior(&(pIMasterTask->behavior));
}

////IMasterTask::ResponseResult IMasterTask::OnResponse(const APDUResponseHeader& response,
////                                                    const ser4cpp::rseq_t& objects,
////                                                    Timestamp now)
ResponseResult_in_IMasterTask_uint8_t OnResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* response, RSeq_for_Uint16_t* objects, Timestamp now)
{
//    ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* response, RSeq_for_Uint16_t* objects);
////    auto result = this->ProcessResponse(response, objects);
  ResponseResult_in_IMasterTask_uint8_t result = ProcessResponse_in_IMasterTask(pIMasterTask, response, objects);

  switch (result)
  {
  case (ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE):
//    void CompleteTask_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);
////        this->CompleteTask(TaskCompletion::FAILURE_BAD_RESPONSE, now);
    CompleteTask_in_IMasterTask(pIMasterTask, TaskCompletion_FAILURE_BAD_RESPONSE, now);
    break;
  case (ResponseResult_in_IMasterTask_OK_FINAL):
////        this->CompleteTask(TaskCompletion::SUCCESS, now);
    CompleteTask_in_IMasterTask(pIMasterTask, TaskCompletion_SUCCESS, now);
    break;
  default:
    break;
  }

  return result;
}

////void IMasterTask::CompleteTask(TaskCompletion result, Timestamp now)
void CompleteTask_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now)
{
  switch (result)
  {

  // retry immediately when the comms come back online
  case (TaskCompletion_FAILURE_NO_COMMS):
///        this->behavior.Reset();
    Reset_in_TaskBehavior(&(pIMasterTask->behavior));
    break;

  // back-off exponentially using the task retry
  case (TaskCompletion_FAILURE_RESPONSE_TIMEOUT):
  {
//   void OnResponseTimeout_in_TaskBehavior(TaskBehavior *pTaskBehavior, Timestamp* now);
////        this->behavior.OnResponseTimeout(now);
    OnResponseTimeout_in_TaskBehavior(&(pIMasterTask->behavior), &now);
//        if (this->BlocksLowerPriority())
//            this->context->AddBlock(*this);
    break;
  }

  case (TaskCompletion_SUCCESS):
////        this->behavior.OnSuccess(now);
    OnSuccess_in_TaskBehavior(&(pIMasterTask->behavior), &now);
//        this->context->RemoveBlock(*this);
    break;

  /**
  FAILURE_BAD_RESPONSE
  FAILURE_START_TIMEOUT
  FAILURE_MESSAGE_FORMAT_ERROR
  */
  default:
  {
////        this->behavior.Disable();
    Disable_in_TaskBehavior(&(pIMasterTask->behavior));
//        if (this->BlocksLowerPriority())
//            this->context->AddBlock(*this);
  }
  }

  if (pIMasterTask->config.pCallback)
  {
//void OnComplete_in_ITaskCallback(ITaskCallback* pITaskCallback, TaskCompletion_uint8_t result);
////        config.pCallback->OnComplete(result);
    OnComplete_in_ITaskCallback(pIMasterTask->config.pCallback, result);
  }

  // notify the application
//    MasterTaskType_uint8_t GetTaskType_in_IMasterTask(IMasterTask *pIMasterTask);
//void TaskInfo_in_TaskInfo(TaskInfo *pTaskInfo, MasterTaskType_uint8_t type_, TaskCompletion result_, TaskId id_);
//void OnTaskComplete_in_IMasterApplication(IMasterApplication* pIMasterApplication, TaskInfo* info);
////    this->application->OnTaskComplete(TaskInfo(this->GetTaskType(), result, config.taskId));
  TaskInfo tTaskInfo;
  TaskInfo_in_TaskInfo(&tTaskInfo, GetTaskType_in_IMasterTask(pIMasterTask), result, pIMasterTask->config.taskId);
  OnTaskComplete_in_IMasterApplication(pIMasterTask->application, &tTaskInfo);

  // notify any super class implementations
//    void OnTaskComplete_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);
////    this->OnTaskComplete(result, now);
  OnTaskComplete_in_IMasterTask(pIMasterTask, result, now);
}

////void IMasterTask::OnResponseTimeout(Timestamp now)
void OnResponseTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now)
{
//    void CompleteTask_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);
////    this->CompleteTask(TaskCompletion::FAILURE_RESPONSE_TIMEOUT, now);
  CompleteTask_in_IMasterTask(pIMasterTask, TaskCompletion_FAILURE_RESPONSE_TIMEOUT, now);
}

////void IMasterTask::OnLowerLayerClose(Timestamp now)
void OnLowerLayerClose_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now)
{
////    this->CompleteTask(TaskCompletion::FAILURE_NO_COMMS, now);
  CompleteTask_in_IMasterTask(pIMasterTask, TaskCompletion_FAILURE_NO_COMMS, now);
}

////void IMasterTask::OnStartTimeout(Timestamp now)
void OnStartTimeout_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now)
{
////    this->CompleteTask(TaskCompletion::FAILURE_START_TIMEOUT, now);
  CompleteTask_in_IMasterTask(pIMasterTask, TaskCompletion_FAILURE_START_TIMEOUT, now);
}

////void IMasterTask::OnMessageFormatError(Timestamp now)
void OnMessageFormatError_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp now)
{
////    this->CompleteTask(TaskCompletion::FAILURE_MESSAGE_FORMAT_ERROR, now);
  CompleteTask_in_IMasterTask(pIMasterTask, TaskCompletion_FAILURE_MESSAGE_FORMAT_ERROR, now);
}

////void IMasterTask::OnStart()
void OnStart_in_IMasterTask(IMasterTask *pIMasterTask)
{
  if (pIMasterTask->config.pCallback)
  {
////        config.pCallback->OnStart();
    OnStart_in_ITaskCallback(pIMasterTask->config.pCallback);
  }

//    MasterTaskType_uint8_t GetTaskType_in_IMasterTask(IMasterTask *pIMasterTask);
//void OnTaskStart_in_IMasterApplication(IMasterApplication *pIMasterApplication, MasterTaskType type, TaskId* id);
////    this->application->OnTaskStart(this->GetTaskType(), config.taskId);
  OnTaskStart_in_IMasterApplication(pIMasterTask->application, GetTaskType_in_IMasterTask(pIMasterTask), &(pIMasterTask->config.taskId));

//    void Initialize_in_IMasterTask(IMasterTask *pIMasterTask);
////    this->Initialize();
  Initialize_in_IMasterTask(pIMasterTask);
}

////void IMasterTask::SetMinExpiration()
void SetMinExpiration_in_IMasterTask(IMasterTask *pIMasterTask)
{
////    this->behavior.Reset();
  Reset_in_TaskBehavior(&(pIMasterTask->behavior));
}

////bool IMasterTask::ValidateSingleResponse(const APDUResponseHeader& header)
boolean ValidateSingleResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header)
{
  UNUSED(pIMasterTask);
  if (header->aAPDUHeader.control.FIR && header->aAPDUHeader.control.FIN)
  {
    return true;
  }

#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SIMPLE_LOG_BLOCK(logger, flags::WARN, 'Ignoring unexpected response FIR/FIN not set')"<<'\n';
  decrement_stack_info();
#endif
////    SIMPLE_LOG_BLOCK(logger, flags::WARN, "Ignoring unexpected response FIR/FIN not set");
  return false;
}

////bool IMasterTask::ValidateNullResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects)
boolean ValidateNullResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
//    boolean ValidateInternalIndications_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header);
//    boolean ValidateNoObjects_in_IMasterTask(IMasterTask *pIMasterTask, RSeq_for_Uint16_t* objects);
//    boolean ValidateSingleResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header);
////    return ValidateSingleResponse(header) && ValidateNoObjects(objects) && ValidateInternalIndications(header);
  return ValidateSingleResponse_in_IMasterTask(pIMasterTask, header) &&
         ValidateNoObjects_in_IMasterTask(pIMasterTask, objects) &&
         ValidateInternalIndications_in_IMasterTask(pIMasterTask, header);
}

////bool IMasterTask::ValidateInternalIndications(const APDUResponseHeader& header)
boolean ValidateInternalIndications_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header)
{
  UNUSED(pIMasterTask);
//boolean HasRequestError_in_IINField(IINField *pIINField);
////    if (header.IIN.HasRequestError())
  if (HasRequestError_in_IINField(&(header->IIN)))
  {
////        FORMAT_LOG_BLOCK(logger, flags::WARN, "Task was explicitly rejected via response with error IIN bit(s): %s",
////                         this->Name());
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<getString_stack_info();
    std::cout<<"FORMAT_LOG_BLOCK(logger, flags::WARN, 'Task was explicitly rejected via response with error IIN bit(s): %s'"<<'\n';
    decrement_stack_info();
#endif
    return false;
  }

  return true;
}

////bool IMasterTask::ValidateNoObjects(const ser4cpp::rseq_t& objects)
boolean ValidateNoObjects_in_IMasterTask(IMasterTask *pIMasterTask, RSeq_for_Uint16_t* objects)
{
  UNUSED(pIMasterTask);
////    if (objects.is_empty())
  if(is_empty_in_HasLength_for_Uint16_t(&(objects->hHasLength)))
  {
    return true;
  }

/////    FORMAT_LOG_BLOCK(logger, flags::WARN, "Received unexpected response object headers for task: %s", this->Name());
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"FORMAT_LOG_BLOCK(logger, flags::WARN, 'Received unexpected response object headers for task: %s', this->Name())"<<'\n';
  decrement_stack_info();
#endif
  return false;
}

////} // namespace opendnp3

char * Name_in_IMasterTask(IMasterTask *pIMasterTask)
{
  return (pIMasterTask->pName_in_IMasterTask)(pIMasterTask);
}
int Priority_in_IMasterTask(IMasterTask *pIMasterTask)
{
  return (pIMasterTask->pPriority_in_IMasterTask)(pIMasterTask);
}
boolean IsRecurring_in_IMasterTask(IMasterTask *pIMasterTask)
{
  return (pIMasterTask->pIsRecurring_in_IMasterTask)(pIMasterTask);
}
boolean BuildRequest_in_IMasterTask(IMasterTask *pIMasterTask, APDURequest* request, uint8_t seq)
{
  return (pIMasterTask->pBuildRequest_in_IMasterTask)(pIMasterTask, request, seq);
}
void Initialize_in_IMasterTask(IMasterTask *pIMasterTask)
{
  (pIMasterTask->pInitialize_in_IMasterTask)(pIMasterTask);
}
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* response, RSeq_for_Uint16_t* objects)
{
  return (pIMasterTask->pProcessResponse_in_IMasterTask)(pIMasterTask, response, objects);
}

void OnTaskComplete_in_IMasterTask(IMasterTask *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now)
{
  (pIMasterTask->pOnTaskComplete_in_IMasterTask)(pIMasterTask, result, now);
}

boolean IsEnabled_in_IMasterTask(IMasterTask *pIMasterTask)
{
  return (pIMasterTask->pIsEnabled_in_IMasterTask)(pIMasterTask);
}
boolean IsEnabled_in_IMasterTask_override(void *pIMasterTask)
{
  UNUSED(pIMasterTask);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_IMasterTask(IMasterTask *pIMasterTask)
{
  return (pIMasterTask->pGetTaskType_in_IMasterTask)(pIMasterTask);
}
boolean BlocksLowerPriority_in_IMasterTask(IMasterTask *pIMasterTask)
{
  return (pIMasterTask->pBlocksLowerPriority_in_IMasterTask)(pIMasterTask);
}

void OnTaskComplete_in_IMasterTask_override(void *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now)
{
  UNUSED(pIMasterTask);
  UNUSED(result);
  UNUSED(now);
}

void Initialize_in_IMasterTask_override(void *pIMasterTask)
{
  UNUSED(pIMasterTask);
}

//    boolean IsBlocked_in_IMasterTask(IMasterTask *pIMasterTask)
//    {
////        return this->context->IsBlocked(*this);
//    }

boolean IsExpired_in_IMasterTask(IMasterTask *pIMasterTask, Timestamp* now)
{
//boolean  operatorGTEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other)
//    Timestamp ExpirationTime_in_IMasterTask(IMasterTask *pIMasterTask);
////        return now >= this->ExpirationTime();
  Timestamp tmp = ExpirationTime_in_IMasterTask(pIMasterTask);
  return  operatorGTEQ_in_Timestamp(now, &tmp);
}

void* getParentPointer_in_IMasterTask(IMasterTask* pIMasterTask)
{
  return pIMasterTask->pParentPointer_in_IMasterTask;
}
void  setParentPointer_in_IMasterTask(IMasterTask* pIMasterTask, void* pParentPointer)
{
  pIMasterTask->pParentPointer_in_IMasterTask = pParentPointer;
}
