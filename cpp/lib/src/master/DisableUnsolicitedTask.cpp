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
#include "DisableUnsolicitedTask.h"

////#include "MasterTasks.h"
#include "APDUBuilders.h"

////namespace opendnp3
////{

////DisableUnsolicitedTask::DisableUnsolicitedTask(const std::shared_ptr<TaskContext>& context,
////                                               IMasterApplication& application,
////                                               const TaskBehavior& behavior,
////                                               const Logger& logger)
void DisableUnsolicitedTask_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application,
    TaskBehavior* behavior)
{
////    : IMasterTask(context, application, behavior, logger, TaskConfig::Default())
  IMasterTask_in_IMasterTask(&(pDisableUnsolicitedTask->iIMasterTask),
//                TaskContext* context,
                             application,
                             *behavior,
//                const Logger& logger,
                             Default_in_TaskConfig_static());

  pDisableUnsolicitedTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_DisableUnsolicitedTask_override;
  pDisableUnsolicitedTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_DisableUnsolicitedTask_override;
  pDisableUnsolicitedTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_DisableUnsolicitedTask_override;
  pDisableUnsolicitedTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_DisableUnsolicitedTask_override;
  pDisableUnsolicitedTask->iIMasterTask.pBlocksLowerPriority_in_IMasterTask = BlocksLowerPriority_in_DisableUnsolicitedTask_override;
  pDisableUnsolicitedTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_DisableUnsolicitedTask_override;

  setParentPointer_in_IMasterTask(&(pDisableUnsolicitedTask->iIMasterTask), pDisableUnsolicitedTask);
}

boolean BuildRequest_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask, APDURequest* request, uint8_t seq)
{
  UNUSED(pDisableUnsolicitedTask);
//void DisableUnsolicited_in_APDUBuilders_static(APDURequest* request, uint8_t seq);// = 0);
////    build::DisableUnsolicited(request, seq);
  DisableUnsolicited_in_APDUBuilders_static(request, seq);
  return true;
}

////IMasterTask::ResponseResult DisableUnsolicitedTask::ProcessResponse(const APDUResponseHeader& header,
////                                                                    const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
////    return ValidateNullResponse(header, objects) ? ResponseResult::OK_FINAL : ResponseResult::ERROR_BAD_RESPONSE;
  return ValidateNullResponse_in_IMasterTask(&(pDisableUnsolicitedTask->iIMasterTask), header, objects) ?
         ResponseResult_in_IMasterTask_OK_FINAL :  ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////} // namespace opendnp3
boolean BlocksLowerPriority_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask)
{
  UNUSED(pDisableUnsolicitedTask);
  return true;
}

int Priority_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask)
{
  UNUSED(pDisableUnsolicitedTask);
  return priority_DISABLE_UNSOLICITED;
}

boolean IsRecurring_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask)
{
  UNUSED(pDisableUnsolicitedTask);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask)
{
  UNUSED(pDisableUnsolicitedTask);
  return MasterTaskType_DISABLE_UNSOLICITED;
}

boolean IsRecurring_in_DisableUnsolicitedTask_override(void *pIMasterTask)
{
  DisableUnsolicitedTask *parent = (DisableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_DisableUnsolicitedTask(parent);
}

boolean BuildRequest_in_DisableUnsolicitedTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  DisableUnsolicitedTask *parent = (DisableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_DisableUnsolicitedTask(parent, request, seq);
}

int Priority_in_DisableUnsolicitedTask_override(void *pIMasterTask)
{
  DisableUnsolicitedTask *parent = (DisableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_DisableUnsolicitedTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_DisableUnsolicitedTask_override(void *pIMasterTask)
{
  DisableUnsolicitedTask *parent = (DisableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_DisableUnsolicitedTask(parent);
}

boolean BlocksLowerPriority_in_DisableUnsolicitedTask_override(void *pIMasterTask)
{
  DisableUnsolicitedTask *parent = (DisableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BlocksLowerPriority_in_DisableUnsolicitedTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_DisableUnsolicitedTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  DisableUnsolicitedTask *parent = (DisableUnsolicitedTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_DisableUnsolicitedTask_override(parent, header, objects);
}

