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

#ifndef OPENDNP3_ICOMMAND_TASK_RESULT_H
#define OPENDNP3_ICOMMAND_TASK_RESULT_H

#include "ICollection.h"
#include "TaskCompletion.h"
#include "CommandPointResult.h"

////namespace opendnp3
////{

/**
 * Abstract result type returned via callback to a command operation.
 *
 * Provides the TaskCompleton summary value and access to a collection
 * of flatten results.
 *
 * A result value is provided for every object in every header specified
 * in the CommandSet used to start the operation.
* ����������� ��� ����������, ������������ ����������� ��������� ������ ��������� ��������.
  *
  * ������������� ������� �������� TaskCompleton � ������ � ���������.
  * ����������� �����������.
  *
  * �������� ���������� ��������������� ��� ������� ������� � ������ ��������� ���������.
  * � ������ ������, ������������ ��� ������� ��������.
 *
 */
////class ICommandTaskResult : public ICollection<CommandPointResult>
typedef struct
{
  ICollection_for_CommandPointResult iICollection_for_CommandPointResult;
////public:
///    ICommandTaskResult(TaskCompletion_uint8_t result_) : summary(result_) {}

  /// A summary result for the entire task
/// ������� ��������� �� ���� ������
  TaskCompletion_uint8_t summary;
} ICommandTaskResult;

void ICommandTaskResult_in_ICommandTaskResult(ICommandTaskResult *pICommandTaskResult, TaskCompletion_uint8_t result_);

////} // namespace opendnp3

#endif
