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
#include "EnableUnsolicitedTask.h"

////#include "MasterTasks.h"
#include "APDUBuilders.h"

////#include <exe4cpp/IExecutor.h>

////namespace opendnp3
////{

////EnableUnsolicitedTask::EnableUnsolicitedTask(const std::shared_ptr<TaskContext>& context,
////                                             IMasterApplication& app,
////                                             const TaskBehavior& behavior,
////                                             ClassField enabledClasses,
////                                             const Logger& logger)
////    : IMasterTask(context, app, behavior, logger, TaskConfig::Default()), enabledClasses(enabledClasses)
///{
////}
void EnableUnsolicitedTask_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application,
    TaskBehavior* behavior,
    ClassField enabledClasses)
{
////    : IMasterTask(context, application, behavior, logger, TaskConfig::Default())
  IMasterTask_in_IMasterTask(&(pEnableUnsolicitedTask->iIMasterTask),
//                TaskContext* context,
                             application,
                             *behavior,
//                const Logger& logger,
                             Default_in_TaskConfig_static());

  pEnableUnsolicitedTask->enabledClasses = enabledClasses;

  pEnableUnsolicitedTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_EnableUnsolicitedTask_override;
  pEnableUnsolicitedTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_EnableUnsolicitedTask_override;
  pEnableUnsolicitedTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_EnableUnsolicitedTask_override;
  pEnableUnsolicitedTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_EnableUnsolicitedTask_override;
  pEnableUnsolicitedTask->iIMasterTask.pBlocksLowerPriority_in_IMasterTask = BlocksLowerPriority_in_EnableUnsolicitedTask_override;
  pEnableUnsolicitedTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_EnableUnsolicitedTask_override;
  pEnableUnsolicitedTask->iIMasterTask.pName_in_IMasterTask = Name_in_EnableUnsolicitedTask_override;

  setParentPointer_in_IMasterTask(&(pEnableUnsolicitedTask->iIMasterTask), pEnableUnsolicitedTask);
}

boolean BuildRequest_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask, APDURequest* request, uint8_t seq)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{BuildRequest_in_EnableUnsolicitedTask1"<<'\n';
#endif
  UNUSED(pEnableUnsolicitedTask);
////    build::EnableUnsolicited(request, enabledClasses.OnlyEventClasses(), seq);
  ClassField tmp = OnlyEventClasses_in_ClassField(&(pEnableUnsolicitedTask->enabledClasses));
  EnableUnsolicited_in_APDUBuilders_static(request, &tmp, seq);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BuildRequest_in_EnableUnsolicitedTask_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

boolean IsEnabled_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask)
{
//boolean HasEventClass_in_ClassField(ClassField *pClassField);
////    return enabledClasses.HasEventClass();
  return HasEventClass_in_ClassField(&(pEnableUnsolicitedTask->enabledClasses));
}

////IMasterTask::ResponseResult EnableUnsolicitedTask::ProcessResponse(const APDUResponseHeader& header,
////                                                                   const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
////    return ValidateNullResponse(header, objects) ? ResponseResult::OK_FINAL : ResponseResult::ERROR_BAD_RESPONSE;
  return ValidateNullResponse_in_IMasterTask(&(pEnableUnsolicitedTask->iIMasterTask), header, objects) ?
         ResponseResult_in_IMasterTask_OK_FINAL :  ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////} // namespace opendnp3
boolean BlocksLowerPriority_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask)
{
  UNUSED(pEnableUnsolicitedTask);
  return true;
}

int Priority_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask)
{
  UNUSED(pEnableUnsolicitedTask);
  return priority_ENABLE_UNSOLICITED;
}

boolean IsRecurring_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask)
{
  UNUSED(pEnableUnsolicitedTask);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask)
{
  UNUSED(pEnableUnsolicitedTask);
  return MasterTaskType_ENABLE_UNSOLICITED;
}

boolean IsRecurring_in_EnableUnsolicitedTask_override(void *pIMasterTask)
{
  EnableUnsolicitedTask *parent = (EnableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_EnableUnsolicitedTask(parent);
}

boolean BuildRequest_in_EnableUnsolicitedTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  EnableUnsolicitedTask *parent = (EnableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_EnableUnsolicitedTask(parent, request, seq);
}

int Priority_in_EnableUnsolicitedTask_override(void *pIMasterTask)
{
  EnableUnsolicitedTask *parent = (EnableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_EnableUnsolicitedTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_EnableUnsolicitedTask_override(void *pIMasterTask)
{
  EnableUnsolicitedTask *parent = (EnableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_EnableUnsolicitedTask(parent);
}

boolean BlocksLowerPriority_in_EnableUnsolicitedTask_override(void *pIMasterTask)
{
  EnableUnsolicitedTask *parent = (EnableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BlocksLowerPriority_in_EnableUnsolicitedTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EnableUnsolicitedTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  EnableUnsolicitedTask *parent = (EnableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_EnableUnsolicitedTask(parent, header, objects);
}

char * Name_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask)
{
   return "EnableUnsolicitedTask";
}
char * Name_in_EnableUnsolicitedTask_override(void *pIMasterTask)
{
  EnableUnsolicitedTask *parent = (EnableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Name_in_EnableUnsolicitedTask(parent);
}
