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
#include "StartupIntegrityPoll.h"

///#include "MasterTasks.h"
#include "APDUBuilders.h"
//#include "APDUParser.h"
////#include "logging/LogMacros.h"
//#include "MeasurementHandler.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////StartupIntegrityPoll::StartupIntegrityPoll(const std::shared_ptr<TaskContext>& context,
////                                           IMasterApplication& app,
////                                           std::shared_ptr<ISOEHandler> soeHandler,
////                                           ClassField classes,
////                                           const TaskBehavior& behavior,
////                                           const Logger& logger)
void StartupIntegrityPoll_in_StartupIntegrityPoll(StartupIntegrityPoll *pStartupIntegrityPoll,
//                       const std::shared_ptr<TaskContext>& context,
    IMasterApplication* app,
    ISOEHandler* soeHandler,
    ClassField   classes,
    TaskBehavior* behavior)
{
//void PollTaskBase_in_PollTaskBase(PollTaskBase *pPollTaskBase,
//                 TaskContext* context,
//                                  IMasterApplication* application,
//                                  ISOEHandler* handler,
//                                  TaskBehavior* behavior,
//                 const Logger& logger,
//                                  TaskConfig config);
////    : PollTaskBase(context, app, std::move(soeHandler), behavior, logger, TaskConfig::Default()), classes(classes)
  PollTaskBase_in_PollTaskBase(&(pStartupIntegrityPoll->pPollTaskBase),
//                 TaskContext* context,
                               app,
                               soeHandler,
                               behavior,
//                 const Logger& logger,
                               Default_in_TaskConfig_static());
  pStartupIntegrityPoll->classes = classes;

  pStartupIntegrityPoll->pPollTaskBase.iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_StartupIntegrityPoll_override;
  pStartupIntegrityPoll->pPollTaskBase.iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_StartupIntegrityPoll_override;
  pStartupIntegrityPoll->pPollTaskBase.iIMasterTask.pPriority_in_IMasterTask = Priority_in_StartupIntegrityPoll_override;
  pStartupIntegrityPoll->pPollTaskBase.iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_StartupIntegrityPoll_override;
  pStartupIntegrityPoll->pPollTaskBase.iIMasterTask.pIsEnabled_in_IMasterTask = IsEnabled_in_StartupIntegrityPoll_override;

  setParentPointer_in_IMasterTask(&(pStartupIntegrityPoll->pPollTaskBase.iIMasterTask), pStartupIntegrityPoll);
}

boolean BuildRequest_in_StartupIntegrityPoll(StartupIntegrityPoll *pStartupIntegrityPoll, APDURequest* request, uint8_t seq)
{
//void ReadIntegrity_in_APDUBuilders_static(APDURequest* request, ClassField* classes, uint8_t seq)
////    build::ReadIntegrity(request, classes, seq);
  ReadIntegrity_in_APDUBuilders_static(request, &(pStartupIntegrityPoll->classes), seq);

////    request.SetFunction(FunctionCode::READ);
  SetFunction_in_APDUWrapper(&(request->aAPDUWrapper), FunctionCode_READ);

////    request.SetControl(AppControlField::Request(seq));
  SetControl_in_APDUWrapper(&(request->aAPDUWrapper), Request_in_AppControlField_static(seq));
  return true;
}

boolean IsEnabled_in_StartupIntegrityPoll(StartupIntegrityPoll *pStartupIntegrityPoll)
{
//boolean HasAnyClass_in_ClassField(ClassField *pClassField);
////    return classes.HasAnyClass();
  return HasAnyClass_in_ClassField(&(pStartupIntegrityPoll->classes));
}

////} // namespace opendnp3
int Priority_in_StartupIntegrityPoll(StartupIntegrityPoll *pStartupIntegrityPoll)
{
  UNUSED(pStartupIntegrityPoll);
  return priority_INTEGRITY_POLL;
}

boolean IsRecurring_in_StartupIntegrityPoll(StartupIntegrityPoll *pStartupIntegrityPoll)
{
  UNUSED(pStartupIntegrityPoll);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_StartupIntegrityPoll(StartupIntegrityPoll *pStartupIntegrityPoll)
{
  UNUSED(pStartupIntegrityPoll);
  return MasterTaskType_STARTUP_INTEGRITY_POLL;
}

boolean IsRecurring_in_StartupIntegrityPoll_override(void *pIMasterTask)
{
  StartupIntegrityPoll *parent = (StartupIntegrityPoll*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_StartupIntegrityPoll(parent);
}

boolean BuildRequest_in_StartupIntegrityPoll_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  StartupIntegrityPoll *parent = (StartupIntegrityPoll*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_StartupIntegrityPoll(parent, request, seq);
}

int Priority_in_StartupIntegrityPoll_override(void *pIMasterTask)
{
  StartupIntegrityPoll *parent = (StartupIntegrityPoll*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_StartupIntegrityPoll(parent);
}

MasterTaskType_uint8_t GetTaskType_in_StartupIntegrityPoll_override(void *pIMasterTask)
{
  StartupIntegrityPoll *parent = (StartupIntegrityPoll*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_StartupIntegrityPoll(parent);
}

boolean IsEnabled_in_StartupIntegrityPoll_override(void *pIMasterTask)
{
  StartupIntegrityPoll *parent = (StartupIntegrityPoll*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsEnabled_in_StartupIntegrityPoll(parent);
}
