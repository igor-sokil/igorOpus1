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
#ifndef OPENDNP3_CLEARRESTARTTASK_H
#define OPENDNP3_CLEARRESTARTTASK_H

#include "IMasterTask.h"
#include "TaskPriority.h"

////namespace opendnp3
////{

/**
 * Clear the IIN restart bit
 */
////class ClearRestartTask final : public IMasterTask
typedef struct
{
  IMasterTask iIMasterTask;

////public:
////    ClearRestartTask(const std::shared_ptr<TaskContext>& context,
////                     IMasterApplication& application,
////                     const Logger& logger);

////    virtual char const* Name() const override
////    {
////        return "Clear Restart IIN";
////    }

////    virtual bool IsRecurring() const override
////    {
////        return true;
////    }

////    virtual int Priority() const override
////    {
////        return priority::CLEAR_RESTART;
////    }

////    virtual bool BlocksLowerPriority() const override
////    {
////        return true;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override;

////private:
////    virtual MasterTaskType GetTaskType() const override
////    {
////        return MasterTaskType::CLEAR_RESTART;
////    }

////    virtual bool IsEnabled() const override
////    {
////        return true;
////    }

////    virtual ResponseResult ProcessResponse(const APDUResponseHeader& response, const ser4cpp::rseq_t& objects) override;
} ClearRestartTask;

void ClearRestartTask_in_ClearRestartTask(ClearRestartTask *pClearRestartTask,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* application);

boolean IsRecurring_in_ClearRestartTask(ClearRestartTask *pClearRestartTask);
boolean IsRecurring_in_ClearRestartTask_override(void *pIMasterTask);

boolean BuildRequest_in_ClearRestartTask(ClearRestartTask *pClearRestartTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_ClearRestartTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_ClearRestartTask(ClearRestartTask *pClearRestartTask);
int Priority_in_ClearRestartTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_ClearRestartTask(ClearRestartTask *pClearRestartTask);
MasterTaskType_uint8_t GetTaskType_in_ClearRestartTask_override(void *pIMasterTask);

boolean IsEnabled_in_ClearRestartTask(ClearRestartTask *pClearRestartTask);
boolean IsEnabled_in_ClearRestartTask_override(void *pIMasterTask);

ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_ClearRestartTask(ClearRestartTask *pClearRestartTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);
ResponseResult_in_IMasterTask_uint8_t ProcessResponse_in_ClearRestartTask_override(void *pIMasterTask,
    APDUResponseHeader* header, RSeq_for_Uint16_t* objects);

char * Name_in_ClearRestartTask(ClearRestartTask *pClearRestartTask);
char * Name_in_ClearRestartTask_override(void *pClearRestartTask);

////    virtual bool IsRecurring() const override
////    {
////        return true;
////    }

////    virtual int Priority() const override
////    {
////        return priority::CLEAR_RESTART;
////    }

////    virtual bool BlocksLowerPriority() const override
////    {
////        return true;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override;

////private:
////    virtual MasterTaskType GetTaskType() const override
////    {
////        return MasterTaskType::CLEAR_RESTART;
////    }

////    virtual bool IsEnabled() const override
////    {
////        return true;
////    }

////} // namespace opendnp3

#endif
