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
#ifndef OPENDNP3_TASK_INFO_H
#define OPENDNP3_TASK_INFO_H

#include "MasterTaskType.h"
#include "TaskCompletion.h"
#include "TaskId.h"

////namespace opendnp3
////{

/**
 * Struct that provides information about a completed or failed task.
 */
////class TaskInfo
typedef struct
{

////public:
////    TaskInfo(MasterTaskType type_, TaskCompletion result_, TaskId id_) : type(type_), result(result_), id(id_) {}

  MasterTaskType_uint8_t type;
  TaskCompletion_uint8_t result;
  TaskId id;
} TaskInfo;

void TaskInfo_in_TaskInfo(TaskInfo *pTaskInfo, MasterTaskType_uint8_t type_, TaskCompletion_uint8_t result_, TaskId id_);


////} // namespace opendnp3

#endif
