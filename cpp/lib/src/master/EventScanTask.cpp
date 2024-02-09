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
#include "EventScanTask.h"

////#include "MasterTasks.h"
#include "APDUBuilders.h"
#include "APDUParser.h"
////#include "logging/LogMacros.h"
////#include "master/MeasurementHandler.h"

////#include "opendnp3/logging/LogLevels.h"

////namespace opendnp3
////{

////EventScanTask::EventScanTask(const std::shared_ptr<TaskContext>& context,
////                             IMasterApplication& application,
////                             std::shared_ptr<ISOEHandler> soeHandler,
////                             ClassField classes,
////                             const Logger& logger)
////    : PollTaskBase(
////          context, application, std::move(soeHandler), TaskBehavior::ReactsToIINOnly(), logger, TaskConfig::Default()),
////      classes(classes.OnlyEventClasses())
void EventScanTask_in_EventScanTask(EventScanTask *pEventScanTask,
//                       const std::shared_ptr<TaskContext>& context,
                                    IMasterApplication* app,
                                    ISOEHandler* soeHandler,
                                    ClassField   classes)
{
  TaskBehavior tmp = ReactsToIINOnly_in_TaskBehavior_static();
  PollTaskBase_in_PollTaskBase(&(pEventScanTask->pPollTaskBase),
//                 TaskContext* context,
                               app,
                               soeHandler,
//                 const Logger& logger,
                               &tmp, 
                               Default_in_TaskConfig_static());
//ClassField OnlyEventClasses_in_ClassField(ClassField *pClassField)
  pEventScanTask->classes = OnlyEventClasses_in_ClassField(&classes);

  pEventScanTask->pPollTaskBase.iIMasterTask.pIsRecurring_in_IMasterTask = IsRecurring_in_EventScanTask_override;
  pEventScanTask->pPollTaskBase.iIMasterTask.pBuildRequest_in_IMasterTask = BuildRequest_in_EventScanTask_override;
  pEventScanTask->pPollTaskBase.iIMasterTask.pPriority_in_IMasterTask = Priority_in_EventScanTask_override;
  pEventScanTask->pPollTaskBase.iIMasterTask.pGetTaskType_in_IMasterTask = GetTaskType_in_EventScanTask_override;
  pEventScanTask->pPollTaskBase.iIMasterTask.pName_in_IMasterTask = Name_in_EventScanTask_override;

  setParentPointer_in_IMasterTask(&(pEventScanTask->pPollTaskBase.iIMasterTask), pEventScanTask);
}

boolean BuildRequest_in_EventScanTask(EventScanTask *pEventScanTask, APDURequest* request, uint8_t seq)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{BuildRequest_in_EventScanTask1"<<'\n';
#endif
//void ClassRequest_in_APDUBuilders_static(APDURequest* request, FunctionCode_uint8_t fc, ClassField* classes, uint8_t seq);
////    build::ClassRequest(request, FunctionCode::READ, classes, seq);
  ClassRequest_in_APDUBuilders_static(request, FunctionCode_READ, &(pEventScanTask->classes), seq);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}BuildRequest_in_EventScanTask_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

boolean IsEnabled_in_EventScanTask(EventScanTask *pEventScanTask)
{
////    return classes.HasEventClass();
  return HasEventClass_in_ClassField(&(pEventScanTask->classes));
}

////} // namespace opendnp3
boolean BlocksLowerPriority_in_EventScanTask(EventScanTask *pEventScanTask)
{
  UNUSED(pEventScanTask);
  return true;
}

int Priority_in_EventScanTask(EventScanTask *pEventScanTask)
{
  UNUSED(pEventScanTask);
  return priority_EVENT_SCAN;
}

boolean IsRecurring_in_EventScanTask(EventScanTask *pEventScanTask)
{
  UNUSED(pEventScanTask);
  return true;
}

MasterTaskType_uint8_t GetTaskType_in_EventScanTask(EventScanTask *pEventScanTask)
{
  UNUSED(pEventScanTask);
  return MasterTaskType_AUTO_EVENT_SCAN;
}

boolean IsRecurring_in_EventScanTask_override(void *pIMasterTask)
{
  EventScanTask *parent = (EventScanTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return IsRecurring_in_EventScanTask(parent);
}

boolean BuildRequest_in_EventScanTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq)
{
  EventScanTask *parent = (EventScanTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BuildRequest_in_EventScanTask(parent, request, seq);
}

int Priority_in_EventScanTask_override(void *pIMasterTask)
{
  EventScanTask *parent = (EventScanTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Priority_in_EventScanTask(parent);
}

MasterTaskType_uint8_t GetTaskType_in_EventScanTask_override(void *pIMasterTask)
{
  EventScanTask *parent = (EventScanTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return GetTaskType_in_EventScanTask(parent);
}

boolean BlocksLowerPriority_in_EventScanTask_override(void *pIMasterTask)
{
  EventScanTask *parent = (EventScanTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return BlocksLowerPriority_in_EventScanTask(parent);
}

char * Name_in_EventScanTask(EventScanTask *pEventScanTask)
{
   return "EventScanTask";
}
char * Name_in_EventScanTask_override(void *pIMasterTask)
{
  EventScanTask *parent = (EventScanTask*) getParentPointer_in_IMasterTask((IMasterTask*) pIMasterTask);
  return Name_in_EventScanTask(parent);
}
