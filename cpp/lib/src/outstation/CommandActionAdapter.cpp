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
#include "header.h"
#include "CommandActionAdapter.h"

////namespace opendnp3
////{

 void  CommandActionAdapter_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, ICommandHandler* handler, boolean is_select, IUpdateHandler* updates, OperateType_uint8_t op_type)
{
  pCommandActionAdapter->is_started = false;

 (pCommandActionAdapter->iICommandAction).pAction_ControlRelayOutputBlock_in_ICommandAction = Action_ControlRelayOutputBlock_in_CommandActionAdapter_override;
 (pCommandActionAdapter->iICommandAction).pAction_AnalogOutputInt16_in_ICommandAction = Action_AnalogOutputInt16_in_CommandActionAdapter_override;
 (pCommandActionAdapter->iICommandAction).pAction_AnalogOutputInt32_in_ICommandAction = Action_AnalogOutputInt32_in_CommandActionAdapter_override;
 (pCommandActionAdapter->iICommandAction).pAction_AnalogOutputFloat32_in_ICommandAction = Action_AnalogOutputFloat32_in_CommandActionAdapter_override;
 (pCommandActionAdapter->iICommandAction).pAction_AnalogOutputDouble64_in_ICommandAction = Action_AnalogOutputDouble64_in_CommandActionAdapter_override;

 setParentPointer_in_ICommandAction(&(pCommandActionAdapter->iICommandAction), pCommandActionAdapter);

////CommandActionAdapter::CommandActionAdapter(ICommandHandler& handler,
////                                           bool is_select,
////                                           IUpdateHandler& updates,
////                                           OperateType op_type)
////    : handler(handler), is_select(is_select), updates(updates), op_type(op_type)
     pCommandActionAdapter->handler = handler;
     pCommandActionAdapter->is_select = is_select;
     pCommandActionAdapter->updates = updates;
     pCommandActionAdapter->op_type = op_type;
}

void CommandActionAdapter_destr_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter)
{
    if (pCommandActionAdapter->is_started)
    {
//    void End_in_ICommandHandler(ICommandHandler*);// = 0;
////        handler.End();
      End_in_ICommandHandler(pCommandActionAdapter->handler);
    }
}

void CheckStart_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter)
{
    if (!pCommandActionAdapter->is_started)
    {
        pCommandActionAdapter->is_started = true;
////        handler.Begin();
     Begin_in_ICommandHandler(pCommandActionAdapter->handler);
    }
}

////CommandStatus CommandActionAdapter::Action(const ControlRelayOutputBlock& command, uint16_t index)
CommandStatus_uint8_t Action_ControlRelayOutputBlock_in_CommandActionAdapter_override(void *pICommandAction, ControlRelayOutputBlock* command, uint16_t index)
{
  CommandActionAdapter* parent = (CommandActionAdapter*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
//  boolean IsQUFlagSet_in_ControlRelayOutputBlock(ControlRelayOutputBlock *pControlRelayOutputBlock);
////    if (command.IsQUFlagSet())
  if(IsQUFlagSet_in_ControlRelayOutputBlock(command))
    {
        return CommandStatus_NOT_SUPPORTED;
    }

// CommandStatus_uint8_t ActionT_ControlRelayOutputBlock_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, ControlRelayOutputBlock* command, uint16_t index);
////    return this->ActionT(command, index);
 return ActionT_ControlRelayOutputBlock_in_CommandActionAdapter(parent, command, index);
}

////CommandStatus_uint8_t CommandActionAdapter::Action(const AnalogOutputInt16& command, uint16_t index)
CommandStatus_uint8_t Action_AnalogOutputInt16_in_CommandActionAdapter_override(void *pICommandAction, AnalogOutputInt16* command, uint16_t index)
{
  CommandActionAdapter* parent = (CommandActionAdapter*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
////    return this->ActionT(command, index);
 return ActionT_AnalogOutputInt16_in_CommandActionAdapter(parent, command, index);
}

////CommandStatus_uint8_t CommandActionAdapter::Action(const AnalogOutputInt32& command, uint16_t index)
CommandStatus_uint8_t Action_AnalogOutputInt32_in_CommandActionAdapter_override(void *pICommandAction, AnalogOutputInt32* command, uint16_t index)
{
  CommandActionAdapter* parent = (CommandActionAdapter*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
////    return this->ActionT(command, index);
 return ActionT_AnalogOutputInt32_in_CommandActionAdapter(parent, command, index);
}

////CommandStatus_uint8_t CommandActionAdapter::Action(const AnalogOutputFloat32& command, uint16_t index)
CommandStatus_uint8_t Action_AnalogOutputFloat32_in_CommandActionAdapter_override(void *pICommandAction, AnalogOutputFloat32* command, uint16_t index)
{
  CommandActionAdapter* parent = (CommandActionAdapter*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
////    return this->ActionT(command, index);
 return ActionT_AnalogOutputFloat32_in_CommandActionAdapter(parent, command, index);
}

////CommandStatus_uint8_t CommandActionAdapter::Action(const AnalogOutputDouble64& command, uint16_t index)
CommandStatus_uint8_t Action_AnalogOutputDouble64_in_CommandActionAdapter_override(void *pICommandAction, AnalogOutputDouble64* command, uint16_t index)
{
  CommandActionAdapter* parent = (CommandActionAdapter*) getParentPointer_in_ICommandAction((ICommandAction*)pICommandAction);
////    return this->ActionT(command, index);
 return ActionT_AnalogOutputDouble64_in_CommandActionAdapter(parent, command, index);
}

////} // namespace opendnp3

 CommandStatus_uint8_t ActionT_ControlRelayOutputBlock_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, ControlRelayOutputBlock* command, uint16_t index)
    {
// void CheckStart_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter);
////        this->CheckStart();
  CheckStart_in_CommandActionAdapter(pCommandActionAdapter);
//    CommandStatus_uint8_t Select_ControlRelayOutputBlock_in_ICommandHandler(ICommandHandler*, ControlRelayOutputBlock* command, uint16_t index);// = 0;
//    CommandStatus_uint8_t Operate_ControlRelayOutputBlock_in_ICommandHandler(ICommandHandler*, ControlRelayOutputBlock* command,
//                                  uint16_t index,
//                                  IUpdateHandler* handler,
//                                  OperateType_uint8_t opType);
////        return is_select ? this->handler.Select(command, index)
////                         : this->handler.Operate(command, index, this->updates, this->op_type);
            return pCommandActionAdapter->is_select ?
                    Select_ControlRelayOutputBlock_in_ICommandHandler(pCommandActionAdapter->handler, command, index) :
                    Operate_ControlRelayOutputBlock_in_ICommandHandler(pCommandActionAdapter->handler, command,
                                   index,
                                  pCommandActionAdapter->updates,
                                  pCommandActionAdapter->op_type);
    }

 CommandStatus_uint8_t ActionT_AnalogOutputInt16_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputInt16* command, uint16_t index)
    {
// void CheckStart_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter);
////        this->CheckStart();
  CheckStart_in_CommandActionAdapter(pCommandActionAdapter);
//    CommandStatus_uint8_t Select_AnalogOutputInt16_in_ICommandHandler(ICommandHandler*, AnalogOutputInt16* command, uint16_t index);// = 0;
//    CommandStatus_uint8_t Operate_AnalogOutputInt16_in_ICommandHandler(ICommandHandler*, AnalogOutputInt16* command,
//                                  uint16_t index,
//                                  IUpdateHandler* handler,
//                                  OperateType_uint8_t opType);
////        return is_select ? this->handler.Select(command, index)
////                         : this->handler.Operate(command, index, this->updates, this->op_type);
            return pCommandActionAdapter->is_select ?
                    Select_AnalogOutputInt16_in_ICommandHandler(pCommandActionAdapter->handler, command, index) :
                    Operate_AnalogOutputInt16_in_ICommandHandler(pCommandActionAdapter->handler, command,
                                   index,
                                  pCommandActionAdapter->updates,
                                  pCommandActionAdapter->op_type);
    }

 CommandStatus_uint8_t ActionT_AnalogOutputInt32_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputInt32* command, uint16_t index)
    {
// void CheckStart_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter);
////        this->CheckStart();
  CheckStart_in_CommandActionAdapter(pCommandActionAdapter);
//    CommandStatus_uint8_t Select_AnalogOutputInt32_in_ICommandHandler(ICommandHandler*, AnalogOutputInt32* command, uint16_t index);// = 0;
//    CommandStatus_uint8_t Operate_AnalogOutputInt32_in_ICommandHandler(ICommandHandler*, AnalogOutputInt32* command,
//                                  uint16_t index,
//                                  IUpdateHandler* handler,
//                                  OperateType_uint8_t opType);
////        return is_select ? this->handler.Select(command, index)
////                         : this->handler.Operate(command, index, this->updates, this->op_type);
            return pCommandActionAdapter->is_select ?
                    Select_AnalogOutputInt32_in_ICommandHandler(pCommandActionAdapter->handler, command, index) :
                    Operate_AnalogOutputInt32_in_ICommandHandler(pCommandActionAdapter->handler, command,
                                   index,
                                  pCommandActionAdapter->updates,
                                  pCommandActionAdapter->op_type);
    }

 CommandStatus_uint8_t ActionT_AnalogOutputFloat32_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputFloat32* command, uint16_t index)
    {
// void CheckStart_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter);
////        this->CheckStart();
  CheckStart_in_CommandActionAdapter(pCommandActionAdapter);
//    CommandStatus_uint8_t Select_AnalogOutputFloat32_in_ICommandHandler(ICommandHandler*, AnalogOutputFloat32* command, uint16_t index);// = 0;
//    CommandStatus_uint8_t Operate_AnalogOutputFloat32_in_ICommandHandler(ICommandHandler*, AnalogOutputFloat32* command,
//                                  uint16_t index,
//                                  IUpdateHandler* handler,
//                                  OperateType_uint8_t opType);
////        return is_select ? this->handler.Select(command, index)
////                         : this->handler.Operate(command, index, this->updates, this->op_type);
            return pCommandActionAdapter->is_select ?
                    Select_AnalogOutputFloat32_in_ICommandHandler(pCommandActionAdapter->handler, command, index) :
                    Operate_AnalogOutputFloat32_in_ICommandHandler(pCommandActionAdapter->handler, command,
                                   index,
                                  pCommandActionAdapter->updates,
                                  pCommandActionAdapter->op_type);
    }

 CommandStatus_uint8_t ActionT_AnalogOutputDouble64_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter, AnalogOutputDouble64* command, uint16_t index)
    {
// void CheckStart_in_CommandActionAdapter(CommandActionAdapter *pCommandActionAdapter);
////        this->CheckStart();
  CheckStart_in_CommandActionAdapter(pCommandActionAdapter);
//    CommandStatus_uint8_t Select_AnalogOutputDouble64_in_ICommandHandler(ICommandHandler*, AnalogOutputDouble64* command, uint16_t index);// = 0;
//    CommandStatus_uint8_t Operate_AnalogOutputDouble64_in_ICommandHandler(ICommandHandler*, AnalogOutputDouble64* command,
//                                  uint16_t index,
//                                  IUpdateHandler* handler,
//                                  OperateType_uint8_t opType);
////        return is_select ? this->handler.Select(command, index)
////                         : this->handler.Operate(command, index, this->updates, this->op_type);
            return pCommandActionAdapter->is_select ?
                    Select_AnalogOutputDouble64_in_ICommandHandler(pCommandActionAdapter->handler, command, index) :
                    Operate_AnalogOutputDouble64_in_ICommandHandler(pCommandActionAdapter->handler, command,
                                   index,
                                  pCommandActionAdapter->updates,
                                  pCommandActionAdapter->op_type);
    }
