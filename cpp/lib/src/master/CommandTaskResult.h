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

#ifndef OPENDNP3_COMMAND_TASK_RESULT_H
#define OPENDNP3_COMMAND_TASK_RESULT_H

#include "CommandSet.h"
#include "ICommandTaskResult.h"
////#include "opendnp3/util/Uncopyable.h"

////namespace opendnp3
////{

////class CommandTaskResult final : public ICommandTaskResult, private Uncopyable
typedef struct
{
  ICommandTaskResult iICommandTaskResult;

////public:
////    CommandTaskResult(TaskCompletion result, const CommandSet::HeaderVector& vector);

  /// --- Implement ICollection<CommandResult> ----

////    virtual size_t Count() const override;
////    virtual void Foreach(IVisitor<CommandPointResult>& visitor) const override;

////private:
////    CommandTaskResult() = delete;

////    const CommandSet::HeaderVector* m_vector;
  HeaderVector_in_CommandSet* m_vector;
} CommandTaskResult;

void CommandTaskResult_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult, TaskCompletion_uint8_t result, HeaderVector_in_CommandSet* vector);

uint16_t Count_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult);
void Foreach_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult, IVisitor__for__CommandPointResult* visitor);
void Foreach_in_CommandTaskResult_override(void *pICollection_for_CommandPointResult, IVisitor__for__CommandPointResult* visitor);
uint16_t Count_in_CommandTaskResult_override(void *pICollection_for_CommandPointResult);

////} // namespace opendnp3

#endif
