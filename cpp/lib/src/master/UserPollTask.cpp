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
#include <QApplication>
#include "header.h"

#include "UserPollTask.h"

////#include <utility>

////namespace opendnp3
////{

////UserPollTask::UserPollTask(const std::shared_ptr<TaskContext>& context,
////                           HeaderBuilderT builder,
////                           const TaskBehavior& behavior,
////                           bool recurring,
////                           IMasterApplication& app,
////                           std::shared_ptr<ISOEHandler> soeHandler,
////                           const Logger& logger,
////                           TaskConfig config)
void UserPollTask_in_UserPollTask(UserPollTask *pUserPollTask,
//                 TaskContext* context,
                                  HeaderBuilderT builder,
                                  TaskBehavior* behavior,
                                  boolean recurring,
                                  IMasterApplication* app,
                                  ISOEHandler* soeHandler,
////                 const Logger& logger,
                                  TaskConfig config)
{
//void PollTaskBase_in_PollTaskBase(PollTaskBase *pPollTaskBase,
//                 TaskContext* context,
//                                  IMasterApplication* application,
//                                  ISOEHandler* handler,
//                                  TaskBehavior* behavior,
//                 const Logger& logger,
//                                  TaskConfig config);
////    : PollTaskBase(context, app, std::move(soeHandler), behavior, logger, config),
  PollTaskBase_in_PollTaskBase(&(pUserPollTask->pPollTaskBase),
//                 TaskContext* context,
                               app,
                               soeHandler,
                               behavior,
//                 const Logger& logger,
                               config);

  pUserPollTask->builder = builder;
  pUserPollTask->recurring = recurring;

  pUserPollTask->pPollTaskBase.iIMasterTask.pPriority_in_IMasterTask = Priority_in_UserPollTask_override;
  pUserPollTask->pPollTaskBase.iIMasterTask.pBuildRequest_in_IMasterTask =  BuildRequest_in_UserPollTask_override;
  pUserPollTask->pPollTaskBase.iIMasterTask.pBlocksLowerPriority_in_IMasterTask = BlocksLowerPriority_in_UserPollTask_override;
  pUserPollTask->pPollTaskBase.iIMasterTask.pIsRecurring_in_IMasterTask =  IsRecurring_in_UserPollTask_override;
  pUserPollTask->pPollTaskBase.iIMasterTask.pIsEnabled_in_IMasterTask = IsEnabled_in_UserPollTask_override;
  pUserPollTask->pPollTaskBase.iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_UserPollTask_override;

  setParentPointer_in_IMasterTask(&(pUserPollTask->pPollTaskBase.iIMasterTask), pUserPollTask);
}

////bool UserPollTask::BuildRequest(APDURequest& request, uint8_t seq)
boolean BuildRequest_in_UserPollTask(UserPollTask *pUserPollTask, APDURequest* request, uint8_t seq)
{
  pUserPollTask->pPollTaskBase.rxCount = 0;

//void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code);
////    request.SetFunction(FunctionCode::READ);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_READ);

//AppControlField Request_in_AppControlField_static(uint8_t seq);
//void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control);
////    request.SetControl(AppControlField::Request(seq));
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), Request_in_AppControlField_static(seq));

//HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper);
////    auto writer = request.GetWriter();
  HeaderWriter writer = GetWriter_in_APDUWrapper(&(request->aAPDUWrapper));

//typedef boolean (*HeaderBuilderT)(HeaderWriter*);
////    return builder(writer);
  return pUserPollTask->builder(&writer);
}
boolean BuildRequest_in_UserPollTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  UserPollTask *parent = (UserPollTask *)getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_UserPollTask(parent, request, seq);
}

////} // namespace opendnp3
int Priority_in_UserPollTask(UserPollTask *pUserPollTask)
{
  UNUSED(pUserPollTask);
  return priority_USER_POLL;
}
int Priority_in_UserPollTask_override(void *pIMasterTask)
{
  UserPollTask *parent = (UserPollTask *)getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_UserPollTask(parent);
}

boolean BlocksLowerPriority_in_UserPollTask(UserPollTask *pUserPollTask)
{
  UNUSED(pUserPollTask);
  return false;
}
boolean BlocksLowerPriority_in_UserPollTask_override(void *pIMasterTask)
{
  UserPollTask *parent = (UserPollTask *)getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BlocksLowerPriority_in_UserPollTask(parent);
}

boolean IsRecurring_in_UserPollTask(UserPollTask *pUserPollTask)
{
  UNUSED(pUserPollTask);
  return pUserPollTask->recurring;
}
boolean IsRecurring_in_UserPollTask_override(void *pIMasterTask)
{
  UserPollTask *parent = (UserPollTask *)getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_UserPollTask(parent);
}

boolean IsEnabled_in_UserPollTask(UserPollTask *pUserPollTask)
{
  UNUSED(pUserPollTask);
  return true;
}
boolean IsEnabled_in_UserPollTask_override(void *pIMasterTask)
{
  UserPollTask *parent = (UserPollTask *)getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsEnabled_in_UserPollTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_UserPollTask(UserPollTask *pUserPollTask)
{
  UNUSED(pUserPollTask);
  return MasterTaskType_USER_TASK;
}
MasterTaskType_uint8_t GetTaskType_in_UserPollTask_override(void *pIMasterTask)
{
  UserPollTask *parent = (UserPollTask *)getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_UserPollTask(parent);
}


