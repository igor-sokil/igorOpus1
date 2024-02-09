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
#ifndef OPENDNP3_USERPOLLTASK_H
#define OPENDNP3_USERPOLLTASK_H

#include "HeaderBuilder.h"
#include "PollTaskBase.h"
#include "TaskPriority.h"

#include "ITaskCallback.h"

////#include <functional>

////namespace opendnp3
////{

////class ISOEHandler;

/**
 * A generic interface for defining master request/response style tasks
* ќбщий интерфейс дл€ определени€ основных задач стил€ запроса/ответа.
 */

////class UserPollTask final : public PollTaskBase
typedef struct
{
  PollTaskBase pPollTaskBase;

////public:
////    UserPollTask(const std::shared_ptr<TaskContext>& context,
////                 HeaderBuilderT builder,
////                 const TaskBehavior& behavior,
////                 bool recurring,
////                 IMasterApplication& app,
////                 std::shared_ptr<ISOEHandler> soeHandler,
////                 const Logger& logger,
////                 TaskConfig config);

////    virtual int Priority() const override
////    {
////        return priority::USER_POLL;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override;

////    virtual bool BlocksLowerPriority() const override
////    {
////        return false;
////    }

////    virtual bool IsRecurring() const override
////    {
////        return recurring;
////    }

////    virtual bool IsEnabled() const override
////    {
////        return true;
////    }

////private:
////    virtual MasterTaskType GetTaskType() const override
////    {
////        return MasterTaskType::USER_TASK;
////    }

  HeaderBuilderT builder;
  boolean recurring;//повтор€ющийс€
} UserPollTask;

void UserPollTask_in_UserPollTask(UserPollTask *pUserPollTask,
//                 TaskContext* context,
                                  HeaderBuilderT builder,
                                  TaskBehavior* behavior,
                                  boolean recurring,
                                  IMasterApplication* app,
                                  ISOEHandler* soeHandler,
////                 const Logger& logger,
                                  TaskConfig config);

int Priority_in_UserPollTask(UserPollTask *pUserPollTask);
int Priority_in_UserPollTask_override(void *pIMasterTask);
boolean BuildRequest_in_UserPollTask(UserPollTask *pUserPollTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_UserPollTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);
boolean BlocksLowerPriority_in_UserPollTask(UserPollTask *pUserPollTask);
boolean BlocksLowerPriority_in_UserPollTask_override(void *pIMasterTask);
boolean IsRecurring_in_UserPollTask(UserPollTask *pUserPollTask);
boolean IsRecurring_in_UserPollTask_override(void *pIMasterTask);
boolean IsEnabled_in_UserPollTask(UserPollTask *pUserPollTask);
boolean IsEnabled_in_UserPollTask_override(void *pIMasterTask);
MasterTaskType_uint8_t GetTaskType_in_UserPollTask(UserPollTask *pUserPollTask);
MasterTaskType_uint8_t GetTaskType_in_UserPollTask_override(void *pIMasterTask);
char * Name_in_UserPollTask(UserPollTask *pUserPollTask);
char * Name_in_UserPollTask_override(void *pUserPollTask);


////} // namespace opendnp3

#endif
