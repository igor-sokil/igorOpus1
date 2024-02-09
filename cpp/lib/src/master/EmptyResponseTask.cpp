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
#include "EmptyResponseTask.h"

#include "TaskPriority.h"

////#include <utility>

////namespace opendnp3
////{

void EmptyResponseTask_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask,
    //const std::shared_ptr<TaskContext>& context,
    IMasterApplication* app,
    //std::string name,
    FunctionCode_uint8_t func,
////                                     std::function<bool(HeaderWriter&)> format,
    HeaderBuilderT format,
    Timestamp startExpiration,
    //const Logger& logger,
    TaskConfig* config)
{
//TaskBehavior SingleExecutionNoRetry_in_TaskBehavior_staticOver2(Timestamp* startExpiration);
////    : IMasterTask(context, app, TaskBehavior::SingleExecutionNoRetry(startExpiration), logger, config),
  TaskBehavior tmp = SingleExecutionNoRetry_in_TaskBehavior_staticOver2(&startExpiration);
  IMasterTask_in_IMasterTask(&(pEmptyResponseTask->iIMasterTask),
//                TaskContext* context,
                             app,
                             tmp,
//                const Logger& logger,
                             *config);

  pEmptyResponseTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_EmptyResponseTask_override;
  pEmptyResponseTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_EmptyResponseTask_override;
  pEmptyResponseTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_EmptyResponseTask_override;
  pEmptyResponseTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_EmptyResponseTask_override;
  pEmptyResponseTask->iIMasterTask.pBlocksLowerPriority_in_IMasterTask = BlocksLowerPriority_in_EmptyResponseTask_override;
  pEmptyResponseTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_EmptyResponseTask_override;
  pEmptyResponseTask->iIMasterTask.pName_in_IMasterTask = Name_in_EmptyResponseTask_override;

  setParentPointer_in_IMasterTask(&(pEmptyResponseTask->iIMasterTask), pEmptyResponseTask);

////      name(std::move(name)),
  pEmptyResponseTask->func  = func;
  pEmptyResponseTask->format = format;
}

////bool EmptyResponseTask::EmptyResponseTask::BuildRequest(APDURequest& request, uint8_t seq)
boolean BuildRequest_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask, APDURequest* request, uint8_t seq)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{BuildRequest_in_EmptyResponseTask1"<<'\n';
#endif
////    request.SetControl(AppControlField(true, true, false, false, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, seq);
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), aAppControlField);

////    request.SetFunction(this->func);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), pEmptyResponseTask->func);
////    auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));
//                                     std::function<bool(HeaderWriter&)> format,
////    return format(writer);
  boolean tmp = pEmptyResponseTask->format(&writer);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BuildRequest_in_EmptyResponseTask_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

/*func, priority::USER_REQUEST, format*/

////IMasterTask::ResponseResult EmptyResponseTask::ProcessResponse(const APDUResponseHeader& header,
////                                                               const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
////    return ValidateNullResponse(header, objects) ? ResponseResult::OK_FINAL : ResponseResult::ERROR_BAD_RESPONSE;
  return ValidateNullResponse_in_IMasterTask(&(pEmptyResponseTask->iIMasterTask), header, objects) ?
         ResponseResult_in_IMasterTask_OK_FINAL :  ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////} // namespace opendnp3
boolean BlocksLowerPriority_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask)
{
  UNUSED(pEmptyResponseTask);
  return true;
}

int Priority_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask)
{
  UNUSED(pEmptyResponseTask);
  return priority_USER_REQUEST;
}

boolean IsRecurring_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask)
{
  UNUSED(pEmptyResponseTask);
  return false;
}

MasterTaskType_uint8_t GetTaskType_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask)
{
  UNUSED(pEmptyResponseTask);
  return MasterTaskType_USER_TASK;
}

boolean IsRecurring_in_EmptyResponseTask_override(void *pIMasterTask)
{
  EmptyResponseTask *parent = (EmptyResponseTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_EmptyResponseTask(parent);
}

boolean BuildRequest_in_EmptyResponseTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  EmptyResponseTask *parent = (EmptyResponseTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_EmptyResponseTask(parent, request, seq);
}

int Priority_in_EmptyResponseTask_override(void *pIMasterTask)
{
  EmptyResponseTask *parent = (EmptyResponseTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_EmptyResponseTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_EmptyResponseTask_override(void *pIMasterTask)
{
  EmptyResponseTask *parent = (EmptyResponseTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_EmptyResponseTask(parent);
}

boolean BlocksLowerPriority_in_EmptyResponseTask_override(void *pIMasterTask)
{
  EmptyResponseTask *parent = (EmptyResponseTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BlocksLowerPriority_in_EmptyResponseTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EmptyResponseTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  EmptyResponseTask *parent = (EmptyResponseTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_EmptyResponseTask_override(parent, header, objects);
}

char * Name_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask)
{
   return "EmptyResponseTask";
}
char * Name_in_EmptyResponseTask_override(void *pIMasterTask)
{
  EmptyResponseTask *parent = (EmptyResponseTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Name_in_EmptyResponseTask(parent);
}
