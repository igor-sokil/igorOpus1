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
#ifndef OPENDNP3_EVENTSCANTASK_H
#define OPENDNP3_EVENTSCANTASK_H

#include "PollTaskBase.h"
#include "TaskPriority.h"

#include "ClassField.h"

////namespace opendnp3
////{
////class ISOEHandler;

/**
 * An auto event scan task that happens when the master sees the event IIN bits
* ������ ��������������� ������������ �������, ������� ����������, ����� ������ ����� ���� ������� IN.
 */
////class EventScanTask final : public PollTaskBase
typedef struct
{
  PollTaskBase pPollTaskBase;

////public:
////    EventScanTask(const std::shared_ptr<TaskContext>& context,
////                  IMasterApplication& application,
////                  std::shared_ptr<ISOEHandler> soeHandler,
////                  ClassField classes,
////                  const Logger& logger);

////    virtual bool IsRecurring() const override
////    {
////        return true;
////    }

////    virtual bool BuildRequest(APDURequest& request, uint8_t seq) override;

////    virtual int Priority() const override
////    {
////        return priority::EVENT_SCAN;
////    }

////    virtual bool BlocksLowerPriority() const override
////    {
////        return true;
////    }

////private:
  ClassField classes;

////    virtual MasterTaskType GetTaskType() const override
////    {
////        return MasterTaskType::AUTO_EVENT_SCAN;
////    }

////    virtual bool IsEnabled() const override;
} EventScanTask;

void EventScanTask_in_EventScanTask(EventScanTask *pEventScanTask,
//                       const std::shared_ptr<TaskContext>& context,
                                    IMasterApplication* application,
                                    ISOEHandler* soeHandler,
                                    ClassField classes);

boolean IsRecurring_in_EventScanTask(EventScanTask *pEventScanTask);
boolean IsRecurring_in_EventScanTask_override(void *pIMasterTask);

boolean BuildRequest_in_EventScanTask(EventScanTask *pEventScanTask, APDURequest* request, uint8_t seq);
boolean BuildRequest_in_EventScanTask_override(void *pIMasterTask, APDURequest* request, uint8_t seq);

int Priority_in_EventScanTask(EventScanTask *pEventScanTask);
int Priority_in_EventScanTask_override(void *pIMasterTask);

MasterTaskType_uint8_t GetTaskType_in_EventScanTask(EventScanTask *pEventScanTask);
MasterTaskType_uint8_t GetTaskType_in_EventScanTask_override(void *pIMasterTask);

boolean BlocksLowerPriority_in_EventScanTask(EventScanTask *pEventScanTask);
boolean BlocksLowerPriority_in_EventScanTask_override(void *pIMasterTask);

char * Name_in_EventScanTask(EventScanTask *pEventScanTask);
char * Name_in_EventScanTask_override(void *pEventScanTask);

////} // namespace opendnp3


#endif
