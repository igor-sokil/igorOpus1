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
#ifndef OPENDNP3_ENABLEUNSOLICITEDTASK_H
#define OPENDNP3_ENABLEUNSOLICITEDTASK_H

#include "IMasterTask.h"
#include "TaskPriority.h"

#include "ClassField.h"

////namespace opendnp3
////{

/**
 * Base class for tasks that only require a single response
* Базовый класс для задач, требующих только одного ответа.
 */

////class EnableUnsolicitedTask final : public IMasterTask
typedef struct
{

  IMasterTask iIMasterTask;

////public:
////    EnableUnsolicitedTask(const std::shared_ptr<TaskContext>& context,
////                          IMasterApplication& app,
////                          const TaskBehavior& behavior,
////                          ClassField enabledClasses,
////                          const Logger& logger);

////    virtual bool IsRecurring() const override
////    {
////        return true;
////    }

////    virtual char const* Name() const override
////    {
////        return "Enable Unsolicited";
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override;

////    virtual int Priority() const override
////    {
////        return priority::ENABLE_UNSOLICITED;
////    }

////    virtual bool BlocksLowerPriority() const override
////    {
////        return true;
////    }

////private:
  ClassField enabledClasses;

////    virtual MasterTaskType GetTaskType() const override
////    {
////        return MasterTaskType::ENABLE_UNSOLICITED;
////    }

////    virtual ResponseResult ProcessResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects) override;

////    virtual bool IsEnabled() const override;
} EnableUnsolicitedTask;

void EnableUnsolicitedTask_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application,
    TaskBehavior* behavior,
    ClassField enabledClasses);

boolean IsRecurring_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask);
boolean IsRecurring_in_EnableUnsolicitedTask_override(void *pIMasterTask);

boolean BuildRequest_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_EnableUnsolicitedTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask);
int Priority_in_EnableUnsolicitedTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask);
MasterTaskType_uint8_t GetTaskType_in_EnableUnsolicitedTask_override(void *pIMasterTask);

boolean BlocksLowerPriority_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask);
boolean BlocksLowerPriority_in_EnableUnsolicitedTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_EnableUnsolicitedTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

char * Name_in_EnableUnsolicitedTask(EnableUnsolicitedTask *pEnableUnsolicitedTask);
char * Name_in_EnableUnsolicitedTask_override(void *pEnableUnsolicitedTask);

////} // namespace opendnp3

#endif
