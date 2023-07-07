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
#ifndef OPENDNP3_COMMANDACTIONADAPTER_H
#define OPENDNP3_COMMANDACTIONADAPTER_H

#include "ICommandAction.h"

////#include "opendnp3/outstation/ICommandHandler.h"
#include "ICommandHandler.h"

////namespace opendnp3
////{

/**
 * Interface used to dispatch an abstract action using a command
 */
////class CommandActionAdapter final : public ICommandAction
typedef struct
{
  ICommandAction iICommandAction;

////public:
////    CommandActionAdapter(ICommandHandler& handler, bool is_select, IUpdateHandler& updates, OperateType op_type);

////    ~CommandActionAdapter();

////    virtual CommandStatus Action(const ControlRelayOutputBlock& command, uint16_t index) override;

////    virtual CommandStatus Action(const AnalogOutputInt16& command, uint16_t index) override;

////    virtual CommandStatus Action(const AnalogOutputInt32& command, uint16_t index) override;

////    virtual CommandStatus Action(const AnalogOutputFloat32& command, uint16_t index) override;

////    virtual CommandStatus Action(const AnalogOutputDouble64& command, uint16_t index) override;

////private:
////    template<class T> CommandStatus ActionT(const T& command, uint16_t index)
////    {
////        this->CheckStart();
////        return is_select ? this->handler.Select(command, index)
////                         : this->handler.Operate(command, index, this->updates, this->op_type);
////    }

////    void CheckStart();

    boolean is_started;//// = false;

    ICommandHandler* handler;
    boolean is_select;
    IUpdateHandler* updates;
    OperateType_uint8_t op_type;
} CommandActionAdapter;

 void  CommandActionAdapter_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, ICommandHandler* handler, boolean is_select, IUpdateHandler* updates, OperateType_uint8_t op_type);
 void  CommandActionAdapter_destr_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter);

 void CheckStart_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter);

 CommandStatus_uint8_t ActionT_ControlRelayOutputBlock_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, ControlRelayOutputBlock* command, uint16_t index);
 CommandStatus_uint8_t ActionT_AnalogOutputInt16_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputInt16* command, uint16_t index);
 CommandStatus_uint8_t ActionT_AnalogOutputInt32_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputInt32* command, uint16_t index);
 CommandStatus_uint8_t ActionT_AnalogOutputFloat32_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputFloat32* command, uint16_t index);
 CommandStatus_uint8_t ActionT_AnalogOutputDouble64_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputDouble64* command, uint16_t index);

CommandStatus_uint8_t Action_ControlRelayOutputBlock_in_CommandActionAdapter_override(void *, ControlRelayOutputBlock* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputInt16_in_CommandActionAdapter_override(void *, AnalogOutputInt16* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputInt32_in_CommandActionAdapter_override(void *, AnalogOutputInt32* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputFloat32_in_CommandActionAdapter_override(void *, AnalogOutputFloat32* arCommand, uint16_t aIndex);
CommandStatus_uint8_t Action_AnalogOutputDouble64_in_CommandActionAdapter_override(void *, AnalogOutputDouble64* arCommand, uint16_t aIndex);


////} // namespace opendnp3

#endif
