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
#ifndef OPENDNP3_DISABLEUNSOLICITEDTASK_H
#define OPENDNP3_DISABLEUNSOLICITEDTASK_H

#include "IMasterTask.h"
#include "TaskPriority.h"

////namespace opendnp3
////{

////class DisableUnsolicitedTask final : public IMasterTask
typedef struct
{
  IMasterTask iIMasterTask;

////public:
////    DisableUnsolicitedTask(const std::shared_ptr<TaskContext>& context,
////                           IMasterApplication& application,
////                           const TaskBehavior& behavior,
////                           const Logger& logger);

////    virtual char const* Name() const override
////    {
////        return "Disable Unsolicited";
////    }

////    virtual bool IsRecurring() const override
////    {
////        return true;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override;

////    virtual int Priority() const override
////    {
////        return priority::DISABLE_UNSOLICITED;
////    }

////    virtual bool BlocksLowerPriority() const override
////    {
////        return true;
////    }

////private:
////    virtual MasterTaskType GetTaskType() const override
////    {
////        return MasterTaskType::DISABLE_UNSOLICITED;
////    }

////    virtual ResponseResult ProcessResponse(const APDUResponseHeader& header, const ser4cpp::rseq_t& objects) override;
} DisableUnsolicitedTask;

void DisableUnsolicitedTask_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application,
    TaskBehavior* behavior);

boolean IsRecurring_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask);
boolean IsRecurring_in_DisableUnsolicitedTask_override(void *pIMasterTask);

boolean BuildRequest_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_DisableUnsolicitedTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask);
int Priority_in_DisableUnsolicitedTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask);
MasterTaskType_uint8_t GetTaskType_in_DisableUnsolicitedTask_override(void *pIMasterTask);

boolean BlocksLowerPriority_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask);
boolean BlocksLowerPriority_in_DisableUnsolicitedTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_DisableUnsolicitedTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

char * Name_in_DisableUnsolicitedTask(DisableUnsolicitedTask *pDisableUnsolicitedTask);
char * Name_in_DisableUnsolicitedTask_override(void *pDisableUnsolicitedTask);

////} // namespace opendnp3

#endif
