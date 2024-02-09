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
#ifndef OPENDNP3_EMPTY_RESPONSE_TASK_H
#define OPENDNP3_EMPTY_RESPONSE_TASK_H

#include "HeaderBuilder.h"
#include "IMasterTask.h"
#include "TaskPriority.h"

////#include <string>

////namespace opendnp3
////{

////class EmptyResponseTask final : public IMasterTask
typedef struct
{
  IMasterTask iIMasterTask;
////public:
////    EmptyResponseTask(const std::shared_ptr<TaskContext>& context,
////                      IMasterApplication& app,
////                      std::string name,
////                      FunctionCode func,
////                      HeaderBuilderT format,
////                      Timestamp startExpiration,
////                      const Logger& logger,
////                      const TaskConfig& config);

////    bool BuildRequest(APDURequest& request, uint8_t seq) override;

////    char const* Name() const override
////    {
////        return name.c_str();
////    }

////    bool IsRecurring() const override
////    {
////        return false;
////    }

////    int Priority() const override
////    {
////        return priority::USER_REQUEST;
////    }

////    bool BlocksLowerPriority() const override
////    {
////        return false;
////    }

////private:
////    MasterTaskType GetTaskType() const override
////    {
////        return MasterTaskType::USER_TASK;
////    }

////    const std::string name;

  FunctionCode_uint8_t func;
  HeaderBuilderT format;

////    IMasterTask::ResponseResult ProcessResponse(const APDUResponseHeader& header,
////                                                const ser4cpp::rseq_t& objects) override final;
} EmptyResponseTask;

void EmptyResponseTask_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask,
    //const std::shared_ptr<TaskContext>& context,
    IMasterApplication* app,
    //std::string name,
    FunctionCode_uint8_t func,
    HeaderBuilderT format,
    Timestamp startExpiration,
    //const Logger& logger,
    TaskConfig* config);

boolean IsRecurring_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask);
boolean IsRecurring_in_EmptyResponseTask_override(void *pIMasterTask);

boolean BuildRequest_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_EmptyResponseTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask);
int Priority_in_EmptyResponseTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask);
MasterTaskType_uint8_t GetTaskType_in_EmptyResponseTask_override(void *pIMasterTask);

boolean BlocksLowerPriority_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask);
boolean BlocksLowerPriority_in_EmptyResponseTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EmptyResponseTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

char * Name_in_EmptyResponseTask(EmptyResponseTask *pEmptyResponseTask);
char * Name_in_EmptyResponseTask_override(void *EmptyResponseTask);

////} // namespace opendnp3

#endif
