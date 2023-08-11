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
#ifndef OPENDNP3_ICOMMANDACTION_H
#define OPENDNP3_ICOMMANDACTION_H

////#include "opendnp3/app/AnalogOutput.h"
////#include "opendnp3/app/ControlRelayOutputBlock.h"

#include "AnalogOutput.h"
#include "ControlRelayOutputBlock.h"

////namespace opendnp3
////{

/**
 * Interface used to dispatch an abstract action using a command
 */
////class ICommandAction
typedef struct
{
////public:
////    virtual ~ICommandAction() {}

////    virtual CommandStatus Action(const ControlRelayOutputBlock& arCommand, uint16_t aIndex) = 0;
  CommandStatus_uint8_t (*pAction_ControlRelayOutputBlock_in_ICommandAction)(void*, ControlRelayOutputBlock* arCommand, uint16_t aIndex);// = 0;

////    virtual CommandStatus Action(const AnalogOutputInt16& arCommand, uint16_t aIndex) = 0;
  CommandStatus_uint8_t (*pAction_AnalogOutputInt16_in_ICommandAction)(void*, AnalogOutputInt16* arCommand, uint16_t aIndex);// = 0;

////    virtual CommandStatus Action(const AnalogOutputInt32& arCommand, uint16_t aIndex) = 0;
  CommandStatus_uint8_t (*pAction_AnalogOutputInt32_in_ICommandAction)(void*, AnalogOutputInt32* arCommand, uint16_t aIndex);// = 0;

////    virtual CommandStatus Action(const AnalogOutputFloat32& arCommand, uint16_t aIndex) = 0;
  CommandStatus_uint8_t (*pAction_AnalogOutputFloat32_in_ICommandAction)(void*, AnalogOutputFloat32* arCommand, uint16_t aIndex);// = 0;

////    virtual CommandStatus Action(const AnalogOutputDouble64& arCommand, uint16_t aIndex) = 0;
  CommandStatus_uint8_t (*pAction_AnalogOutputDouble64_in_ICommandAction)(void*, AnalogOutputDouble64* arCommand, uint16_t aIndex);// = 0;

  void* pParentPointer_in_ICommandAction;
} ICommandAction;

void* getParentPointer_in_ICommandAction(ICommandAction*);
void  setParentPointer_in_ICommandAction(ICommandAction*, void*);

CommandStatus_uint8_t Action_ControlRelayOutputBlock_in_ICommandAction(ICommandAction *, ControlRelayOutputBlock* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputInt16_in_ICommandAction(ICommandAction *, AnalogOutputInt16* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputInt32_in_ICommandAction(ICommandAction *, AnalogOutputInt32* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputFloat32_in_ICommandAction(ICommandAction *, AnalogOutputFloat32* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputDouble64_in_ICommandAction(ICommandAction *, AnalogOutputDouble64* arCommand, uint16_t aIndex);


////} // namespace opendnp3

#endif
