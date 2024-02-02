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
#ifndef OPENDNP3_RESTART_OPERATION_TASK_H
#define OPENDNP3_RESTART_OPERATION_TASK_H

#include "IAPDUHandler.h"
#include "IMasterTask.h"
#include "TaskPriority.h"

#include "RestartType.h"
#include "RestartOperationResult.h"

////namespace opendnp3
////{

////class RestartOperationTask final : public IMasterTask, private IAPDUHandler
typedef struct
{
  IMasterTask  iIMasterTask;
  IAPDUHandler iIAPDUHandler;

////public:
////    RestartOperationTask(const std::shared_ptr<TaskContext>& context,
////                         IMasterApplication& app,
////                         const Timestamp& startTimeout,
////                         RestartType operationType,
////                         RestartOperationCallbackT callback,
////                         const Logger& logger,
////                         const TaskConfig& config);

////    bool BuildRequest(APDURequest& request, uint8_t seq) override;

////    int Priority() const override
////    {
////        return priority::USER_REQUEST;
////    }

////    bool BlocksLowerPriority() const override
////    {
////        return false;
////    }

////    bool IsRecurring() const override
////    {
////        return false;
////    }

/////    char const* Name() const override;

////    bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override;

////private:
////    MasterTaskType GetTaskType() const override;

////    IINField ProcessHeader(const CountHeader& header, const ICollection<Group52Var1>& values) override;
////    IINField ProcessHeader(const CountHeader& header, const ICollection<Group52Var2>& values) override;

////    static FunctionCode ToFunctionCode(RestartType op);

  FunctionCode_uint8_t function;
  RestartOperationCallbackT callback;
  TimeDuration duration;

////    IMasterTask::ResponseResult ProcessResponse(const APDUResponseHeader& header,
////                                                const ser4cpp::rseq_t& objects) override;

////    void OnTaskComplete(TaskCompletion result, Timestamp now) override;
} RestartOperationTask;

void RestartOperationTask_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask,
    //const std::shared_ptr<TaskContext>& context,
    IMasterApplication* app,
    Timestamp* startTimeout,
    RestartType_uint8_t operationType,
    RestartOperationCallbackT callback,
    //const Logger& logger,
    TaskConfig* config);

FunctionCode_uint8_t ToFunctionCode_in_RestartOperationTask_static(RestartType_uint8_t op);

////    bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override;
boolean IsAllowed_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);
boolean IsAllowed_in_RestartOperationTask_override(void *pIWhiteList, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

////    IINField ProcessHeader(const CountHeader& header, const ICollection<Group52Var1>& values) override;
//IINField ProcessHeader_CountHeader_for_Group50Var3_in_IAPDUHandler(IAPDUHandler*, CountHeader* header, ICollection_for_Group50Var3* values);
IINField ProcessHeader_for_Group52Var1_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, CountHeader* header, ICollection_for_Group52Var1* values);
IINField ProcessHeader_for_Group52Var1_in_RestartOperationTask_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var1* values);
////    IINField ProcessHeader(const CountHeader& header, const ICollection<Group52Var2>& values) override;
IINField ProcessHeader_for_Group52Var2_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, CountHeader* header, ICollection_for_Group52Var2* values);
IINField ProcessHeader_for_Group52Var2_in_RestartOperationTask_override(void *pIAPDUHandler, CountHeader* header, ICollection_for_Group52Var2* values);

boolean IsRecurring_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask);
boolean IsRecurring_in_RestartOperationTask_override(void *pIMasterTask);

boolean BuildRequest_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_RestartOperationTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask);
int Priority_in_RestartOperationTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask);
MasterTaskType_uint8_t GetTaskType_in_RestartOperationTask_override(void *pIMasterTask);

boolean BlocksLowerPriority_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask);
boolean BlocksLowerPriority_in_RestartOperationTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_RestartOperationTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

void OnTaskComplete_in_RestartOperationTask(RestartOperationTask *pRestartOperationTask, TaskCompletion_uint8_t result, Timestamp now);
void OnTaskComplete_in_RestartOperationTask_override(void *pIMasterTask, TaskCompletion_uint8_t result, Timestamp now);

////} // namespace opendnp3

#endif
