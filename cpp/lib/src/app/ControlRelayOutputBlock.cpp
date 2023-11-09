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
////#include "opendnp3/app/ControlRelayOutputBlock.h"
#include "header.h"
#include "ControlRelayOutputBlock.h"

////namespace opendnp3
////{

void ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1(ControlRelayOutputBlock *pControlRelayOutputBlock,
    OperationType_uint8_t opType_,
    TripCloseCode_uint8_t tcc_,
    boolean clear_,
    uint8_t count_,
    uint32_t onTime_,
    uint32_t offTime_,
    CommandStatus_uint8_t status_)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ControlRelayOutputBlock_in_ControlRelayOutputBlockOver1_1"<<'\n';
  decrement_stack_info();
#endif

  pControlRelayOutputBlock->opType = opType_;
  pControlRelayOutputBlock->tcc = tcc_;
  pControlRelayOutputBlock->clear = clear_;
  pControlRelayOutputBlock->count = count_;
  pControlRelayOutputBlock->onTimeMS = onTime_;
  pControlRelayOutputBlock->offTimeMS = offTime_;
  pControlRelayOutputBlock->status = status_;
  pControlRelayOutputBlock->rawCode = ((pControlRelayOutputBlock->tcc << 6) & 0xC0) | ((((uint8_t) pControlRelayOutputBlock->clear) << 5) & 0x20)
                                      | (pControlRelayOutputBlock->opType & 0x0F);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pControlRelayOutputBlock->rawCode ="<<(uint16_t)pControlRelayOutputBlock->rawCode<<'\n';
#endif
}

void ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2(ControlRelayOutputBlock *pControlRelayOutputBlock,
    uint8_t rawCode_, uint8_t count_, uint32_t onTime_, uint32_t offTime_, CommandStatus_uint8_t status_)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ControlRelayOutputBlock_in_ControlRelayOutputBlockOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pControlRelayOutputBlock->rawCode ="<<(uint16_t)rawCode_<<'\n';
  decrement_stack_info();
#endif

  pControlRelayOutputBlock->opType = from_type_in_OperationTypeSpec_static((rawCode_ & 0x0F));
  pControlRelayOutputBlock->tcc = from_type_in_TripCloseCodeSpec_static((rawCode_ >> 6) & 0x3);
  pControlRelayOutputBlock->clear = (rawCode_ & 0x20) != 0;
  pControlRelayOutputBlock->count = count_;
  pControlRelayOutputBlock->onTimeMS = onTime_;
  pControlRelayOutputBlock->offTimeMS = offTime_;
  pControlRelayOutputBlock->status = status_;
  pControlRelayOutputBlock->rawCode = rawCode_;
}

boolean IsQUFlagSet_in_ControlRelayOutputBlock(ControlRelayOutputBlock *pControlRelayOutputBlock)
{
  return (pControlRelayOutputBlock->rawCode & 0x10) != 0;
}

boolean ValuesEqual_in_ControlRelayOutputBlock(ControlRelayOutputBlock *pControlRelayOutputBlock, ControlRelayOutputBlock *lhs)
{
  return (pControlRelayOutputBlock->opType == lhs->opType) &&
         (pControlRelayOutputBlock->tcc == lhs->tcc) &&
         (pControlRelayOutputBlock->clear == lhs->clear) &&
         (pControlRelayOutputBlock->count == lhs->count) &&
         (pControlRelayOutputBlock->onTimeMS == lhs->onTimeMS) &&
         (pControlRelayOutputBlock->offTimeMS == lhs->offTimeMS);
}

////} // namespace opendnp3
