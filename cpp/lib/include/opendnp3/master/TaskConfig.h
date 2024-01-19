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
#ifndef OPENDNP3_TASKCONFIG_H
#define OPENDNP3_TASKCONFIG_H

#include "ITaskCallback.h"
#include "TaskId.h"

////#include <memory>

////namespace opendnp3
////{

/**
 *	Object containing multiple fields for configuring tasks
* Объект, содержащий несколько полей для настройки задач.
 */
////class TaskConfig
typedef struct
{
////public:
////    TaskConfig(TaskId taskId, std::shared_ptr<ITaskCallback> pCallback) : taskId(taskId), pCallback(pCallback) {}

////    static TaskConfig Default()
////    {
////        return TaskConfig(TaskId::Undefined(), nullptr);
////    }

  ///  --- syntax sugar for building configs -----

////    static TaskConfig With(std::shared_ptr<ITaskCallback> callback)
////    {
////        return TaskConfig(TaskId::Undefined(), callback);
////    }

////    TaskConfig() = delete;

////public:
  TaskId taskId;
////    std::shared_ptr<ITaskCallback> pCallback;
  ITaskCallback* pCallback;
} TaskConfig;

void TaskConfig_in_TaskConfig(TaskConfig *pTaskConfig, TaskId taskId, ITaskCallback* pCallback);
TaskConfig Default_in_TaskConfig_static(void);
TaskConfig With_in_TaskConfig_static(ITaskCallback* callback);

////} // namespace opendnp3

#endif
