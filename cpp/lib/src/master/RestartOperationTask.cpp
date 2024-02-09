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
#include "RestartOperationTask.h"

#include "APDUBuilders.h"
#include "APDUParser.h"
#include "TaskPriority.h"
//#include "Group52.h"

////#include <utility>

////namespace opendnp3
////{

////RestartOperationTask::RestartOperationTask(const std::shared_ptr<TaskContext>& context,
////                                           IMasterApplication& app,
////                                           const Timestamp& startTimeout,
////                                           RestartType operationType,
////                                           RestartOperationCallbackT callback,
////                                           const Logger& logger,
////                                           const TaskConfig& config)
void RestartOperationTask_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask,
    //const std::shared_ptr<TaskContext>& context,
    IMasterApplication* app,
    Timestamp* startTimeout,
    RestartType_uint8_t operationType,
    RestartOperationCallbackT callback,
    //const Logger& logger,
    TaskConfig* config)
{
  IAPDUHandler_in_IAPDUHandler(&(pRestartOperationTask->iIAPDUHandler));

////    : IMasterTask(context, app, TaskBehavior::SingleExecutionNoRetry(startTimeout), logger, config),
  TaskBehavior tmp = SingleExecutionNoRetry_in_TaskBehavior_staticOver2(startTimeout);
  IMasterTask_in_IMasterTask(&(pRestartOperationTask->iIMasterTask),
//                TaskContext* context,
                             app,
                             tmp,
//                const Logger& logger,
                             *config);

  pRestartOperationTask->iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_RestartOperationTask_override;
  pRestartOperationTask->iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_RestartOperationTask_override;
  pRestartOperationTask->iIMasterTask.pPriority_in_IMasterTask = Priority_in_RestartOperationTask_override;
  pRestartOperationTask->iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_RestartOperationTask_override;
  pRestartOperationTask->iIMasterTask.pBlocksLowerPriority_in_IMasterTask = BlocksLowerPriority_in_RestartOperationTask_override;
  pRestartOperationTask->iIMasterTask.pProcessResponse_in_IMasterTask = ProcessResponse_in_RestartOperationTask_override;
  pRestartOperationTask->iIMasterTask.pOnTaskComplete_in_IMasterTask = OnTaskComplete_in_RestartOperationTask_override;
  pRestartOperationTask->iIMasterTask.pName_in_IMasterTask = Name_in_RestartOperationTask_override;

  pRestartOperationTask->iIAPDUHandler.iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_RestartOperationTask_override;//(void *pIWhiteList;
  pRestartOperationTask->iIAPDUHandler.pProcessHeader_CountHeader_for_Group52Var1_in_IAPDUHandler = ProcessHeader_for_Group52Var1_in_RestartOperationTask_override;//(void *pIAPDUHandler;
  pRestartOperationTask->iIAPDUHandler.pProcessHeader_CountHeader_for_Group52Var2_in_IAPDUHandler = ProcessHeader_for_Group52Var2_in_RestartOperationTask_override;//(void *pIAPDUHandler;

  setParentPointer_in_IMasterTask(&(pRestartOperationTask->iIMasterTask), pRestartOperationTask);
  setParentPointer_in_IAPDUHandler(&(pRestartOperationTask->iIAPDUHandler), pRestartOperationTask);
  setParentPointer_in_IWhiteList(&(pRestartOperationTask->iIAPDUHandler.iIWhiteList), pRestartOperationTask);

  pRestartOperationTask->function = (operationType == RestartType_COLD) ? FunctionCode_COLD_RESTART : FunctionCode_WARM_RESTART;
  pRestartOperationTask->callback = callback;
}

boolean BuildRequest_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, APDURequest* request, uint8_t seq)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{BuildRequest_in_RestartOperationTask1"<<'\n';
#endif
////    request.SetControl(AppControlField(true, true, false, false, seq));
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver4(&aAppControlField, true, true, false, false, seq);
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), aAppControlField);

////    request.SetFunction(this->function);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), pRestartOperationTask->function);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BuildRequest_in_RestartOperationTask_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool RestartOperationTask::IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode /*qc*/)
boolean IsAllowed_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(pRestartOperationTask);
  UNUSED(qc);
  if (headerCount != 0)
  {
    return false;
  }

  switch (gv)
  {
  case (GroupVariation_Group52Var1):
  case (GroupVariation_Group52Var2):
    return true;
  default:
    return false;
  }
}
boolean IsAllowed_in_RestartOperationTask_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IWhiteList((IWhiteList*)pIWhiteList);
  return IsAllowed_in_RestartOperationTask(parent, headerCount, gv, qc);
}

////MasterTaskType RestartOperationTask::GetTaskType() const
///{
///    return MasterTaskType::USER_TASK;
///}

////char const* RestartOperationTask::Name() const
////{
////    return FunctionCodeSpec::to_human_string(this->function);
////}

////IMasterTask::ResponseResult RestartOperationTask::ProcessResponse(const APDUResponseHeader& header,
////                                                                  const ser4cpp::rseq_t& objects)
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
//    boolean ValidateInternalIndications_in_IMasterTask(IMasterTask *pIMasterTask, APDUResponseHeader* header);
////    if (!(ValidateSingleResponse(header) && ValidateInternalIndications(header)))
  if (!ValidateSingleResponse_in_IMasterTask(&(pRestartOperationTask->iIMasterTask), header)  &&
      ValidateInternalIndications_in_IMasterTask(&(pRestartOperationTask->iIMasterTask), header))
  {
    return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
  }

////    if (objects.is_empty())
  if(is_empty_in_HasLength_for_Uint16_t(&(objects->hHasLength)))
  {
    return ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
  }

//ParseResult_uint8_t Parse_in_APDUParser_static(
//  RSeq_for_Uint16_t *buffer,
//  IAPDUHandler *handler);
////    auto result = APDUParser::Parse(objects, *this, &logger);
  ParseResult_uint8_t result = Parse_in_APDUParser_static(
                                 objects,
                                 &(pRestartOperationTask->iIAPDUHandler));

  return (result == ParseResult_OK) ? ResponseResult_in_IMasterTask_OK_FINAL : ResponseResult_in_IMasterTask_ERROR_BAD_RESPONSE;
}

////IINField RestartOperationTask::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group52Var1>& values)
IINField ProcessHeader_for_Group52Var1_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, CountHeader* header, ICollection_for_Group52Var1* values)
{
  UNUSED(header);
  Group52Var1 value;
  Group52Var1_in_Group52Var1(&value);

//boolean ReadOnlyValue_in_ICollection_for_Group52Var1(ICollection_for_Group52Var1 *pICollection_for_Group52Var1, Group52Var1* value);
////    if (values.ReadOnlyValue(value))
  if (ReadOnlyValue_in_ICollection_for_Group52Var1(values, &value))
  {
    pRestartOperationTask->duration = Milliseconds_in_TimeDuration_static(value.time_uint16_t);
////        return IINField::Empty();
    return Empty_in_IINField_static();
  }

////    return IINBit::PARAM_ERROR;
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return iIINField;
}
IINField ProcessHeader_for_Group52Var1_in_RestartOperationTask_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var1* values)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessHeader_for_Group52Var1_in_RestartOperationTask(parent, header, values);
}

////IINField RestartOperationTask::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group52Var2>& values)
IINField ProcessHeader_for_Group52Var2_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, CountHeader* header, ICollection_for_Group52Var2* values)
{
  UNUSED(header);
  Group52Var2 value;
  Group52Var2_in_Group52Var2(&value);

////    if (values.ReadOnlyValue(value))
  if (ReadOnlyValue_in_ICollection_for_Group52Var2(values, &value))
  {
////        this->duration = TimeDuration::Milliseconds(value.time);
    pRestartOperationTask->duration = Milliseconds_in_TimeDuration_static(value.time_uint16_t);
////        return IINField::Empty();
    return Empty_in_IINField_static();
  }

////    return IINBit::PARAM_ERROR;
  IINField iIINField;
  IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
  return iIINField;
}
IINField ProcessHeader_for_Group52Var2_in_RestartOperationTask_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var2* values)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
  return ProcessHeader_for_Group52Var2_in_RestartOperationTask(parent, header, values);
}

////FunctionCode RestartOperationTask::ToFunctionCode(RestartType op)
FunctionCode_uint8_t ToFunctionCode_in_RestartOperationTask_static(RestartType_uint8_t op)
{
  return (op == RestartType_COLD) ? FunctionCode_COLD_RESTART : FunctionCode_WARM_RESTART;
}

////void RestartOperationTask::OnTaskComplete(TaskCompletion result, Timestamp /*now*/)
void OnTaskComplete_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, TaskCompletion_uint8_t result, Timestamp now)
{
  UNUSED(now);
////    if (this->Errors().Any())
  IINField tmp = Errors_in_IAPDUHandler(&(pRestartOperationTask->iIAPDUHandler));
  if (Any_in_IINField(&tmp))
  {
//typedef void (*RestartOperationCallbackT)(RestartOperationResult*);
//void RestartOperationResult_in_RestartOperationResultOver2(RestartOperationResult *pRestartOperationResult, TaskCompletion_uint8_t summary_, TimeDuration restartTime_);
////        this->callback(RestartOperationResult(TaskCompletion::FAILURE_BAD_RESPONSE, this->duration));
    RestartOperationResult rRestartOperationResult;
    RestartOperationResult_in_RestartOperationResultOver2(&rRestartOperationResult,
        TaskCompletion_FAILURE_BAD_RESPONSE, pRestartOperationTask->duration);
    pRestartOperationTask->callback(&rRestartOperationResult);
  }
  else
  {
////        this->callback(RestartOperationResult(result, this->duration));
    RestartOperationResult rRestartOperationResult;
    RestartOperationResult_in_RestartOperationResultOver2(&rRestartOperationResult,
        result, pRestartOperationTask->duration);
    pRestartOperationTask->callback(&rRestartOperationResult);
  }
}
void OnTaskComplete_in_RestartOperationTask_override(void *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return OnTaskComplete_in_RestartOperationTask(parent, result, now);
}

////} // namespace opendnp3
boolean BlocksLowerPriority_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask)
{
  UNUSED(pRestartOperationTask);
  return false;
}

int Priority_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask)
{
  UNUSED(pRestartOperationTask);
  return priority_USER_REQUEST;
}

boolean IsRecurring_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask)
{
  UNUSED(pRestartOperationTask);
  return false;
}

MasterTaskType_uint8_t GetTaskType_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask)
{
  UNUSED(pRestartOperationTask);
  return MasterTaskType_USER_TASK;
}

boolean IsRecurring_in_RestartOperationTask_override(void *pIMasterTask)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_RestartOperationTask(parent);
}

boolean BuildRequest_in_RestartOperationTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_RestartOperationTask(parent, request, seq);
}

int Priority_in_RestartOperationTask_override(void *pIMasterTask)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_RestartOperationTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_RestartOperationTask_override(void *pIMasterTask)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_RestartOperationTask(parent);
}

boolean BlocksLowerPriority_in_RestartOperationTask_override(void *pIMasterTask)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BlocksLowerPriority_in_RestartOperationTask(parent);
}

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_RestartOperationTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return ProcessResponse_in_RestartOperationTask_override(parent, header, objects);
}

char * Name_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask)
{
   return "RestartOperationTask";
}
char * Name_in_RestartOperationTask_override(void *pIMasterTask)
{
  RestartOperationTask *parent = (RestartOperationTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Name_in_RestartOperationTask(parent);
}
