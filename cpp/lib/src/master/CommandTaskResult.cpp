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

#include <QApplication>
#include "header.h"
#include "CommandTaskResult.h"

#include "ICommandHeader.h"

////namespace opendnp3
////{

////CommandTaskResult::CommandTaskResult(TaskCompletion result, const CommandSet::HeaderVector& vector)
void CommandTaskResult_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult, TaskCompletion_uint8_t result, HeaderVector_in_CommandSet* vector)
{
//void ICommandTaskResult_in_ICommandTaskResult(ICommandTaskResult *pICommandTaskResult, TaskCompletion_uint8_t result_);
////    : ICommandTaskResult(result), m_vector(&vector)
  ICommandTaskResult_in_ICommandTaskResult(&(pCommandTaskResult->iICommandTaskResult), result);
  pCommandTaskResult->m_vector = vector;

  pCommandTaskResult->iICommandTaskResult.iICollection_for_CommandPointResult.pCount_in_ICollection_for_CommandPointResult =
    Count_in_CommandTaskResult_override;
  pCommandTaskResult->iICommandTaskResult.iICollection_for_CommandPointResult.pForeach_in_ICollection_for_CommandPointResult =
    Foreach_in_CommandTaskResult_override;
  setParentPointer_in_ICollection_for_CommandPointResult(&(pCommandTaskResult->iICommandTaskResult.iICollection_for_CommandPointResult), pCommandTaskResult);
}

/// --- Implement ICollection<CommandResult> ----

uint16_t Count_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult)
{
  uint16_t count = 0;
  for (auto& header : *(pCommandTaskResult->m_vector))
  {
//uint16_t Count_in_ICollection_for_CommandState(ICollection_for_CommandState*);
////        count += header->Count();
    count += Count_in_ICollection_for_CommandState(&(header.iICollection_for_CommandState));
  }
  return count;
}
uint16_t Count_in_CommandTaskResult_override(void *pICollection_for_CommandPointResult)
{
  CommandTaskResult *parent = (CommandTaskResult*)getParentPointer_in_ICollection_for_CommandPointResult((ICollection_for_CommandPointResult*) pICollection_for_CommandPointResult);
  return Count_in_CommandTaskResult(parent);
}

static void* pPointerGlobal1_in_CommandTaskResult;
static void* pPointerGlobal2_in_CommandTaskResult;

void visit_in_CommandTaskResult(CommandState *state)
{
  IVisitor__for__CommandPointResult* visitor = (IVisitor__for__CommandPointResult*) pPointerGlobal1_in_CommandTaskResult;
  uint32_t* headerIndex = (uint32_t*) pPointerGlobal2_in_CommandTaskResult;
////        auto visit = [&](const CommandState& state) {
//  void CommandPointResult_in_CommandPointResult(CommandPointResult *pCommandPointResult,
//                                  uint32_t headerIndex_, uint16_t index_, CommandPointState_uint8_t state_, CommandStatus_uint8_t status_);
//void OnValue_in_IVisitor__for__CommandPointResult(IVisitor__for__CommandPointResult *, CommandPointResult* );
////            visitor.OnValue(CommandPointResult(headerIndex, state.index, state.state, state.status));
////        };
  CommandPointResult cCommandPointResult;
  CommandPointResult_in_CommandPointResult(&cCommandPointResult,
      *headerIndex, state->index, state->state, state->status);
  OnValue_in_IVisitor__for__CommandPointResult(visitor, &cCommandPointResult);
}

////void Foreach_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult, IVisitor<CommandPointResult>& visitor) const
void Foreach_in_CommandTaskResult(CommandTaskResult *pCommandTaskResult, IVisitor__for__CommandPointResult* visitor)
{
  uint32_t headerIndex = 0;

  for (auto& header : *(pCommandTaskResult->m_vector))
  {
////        auto visit = [&](const CommandState& state) {
////            visitor.OnValue(CommandPointResult(headerIndex, state.index, state.state, state.status));
////        };

    pPointerGlobal1_in_CommandTaskResult = visitor;
    pPointerGlobal2_in_CommandTaskResult = &headerIndex;
//void ForeachItem_in_ICollection_for_CommandState(ICollection_for_CommandState *pICollection_for_CommandState, void (*fun)(CommandState* item));
////        header->ForeachItem(visit);
    ForeachItem_in_ICollection_for_CommandState(&(header.iICollection_for_CommandState), visit_in_CommandTaskResult);///void (*fun)(CommandState* item));
    ++headerIndex;
  }
}

void Foreach_in_CommandTaskResult_override(void *pICollection_for_CommandPointResult, IVisitor__for__CommandPointResult* visitor)
{
  CommandTaskResult *parent = (CommandTaskResult*)getParentPointer_in_ICollection_for_CommandPointResult((ICollection_for_CommandPointResult*) pICollection_for_CommandPointResult);
  Foreach_in_CommandTaskResult(parent, visitor);
}

////} // namespace opendnp3
