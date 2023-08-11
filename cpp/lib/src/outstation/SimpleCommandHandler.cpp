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
////#include "opendnp3/outstation/SimpleCommandHandler.h"
#include "header.h"
#include "SimpleCommandHandler.h"

////namespace opendnp3
///{

void SimpleCommandHandler_in_SimpleCommandHandler(SimpleCommandHandler *pSimpleCommandHandler, CommandStatus_uint8_t status)
{
  pSimpleCommandHandler->status = status;
  pSimpleCommandHandler->numOperate = 0;
  pSimpleCommandHandler->numSelect = 0;
  pSimpleCommandHandler->numStart = 0;
  pSimpleCommandHandler->numEnd = 0;

  pSimpleCommandHandler->pDoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler = DoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler_override;
  pSimpleCommandHandler->pDoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler = DoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler_override;

  pSimpleCommandHandler->pDoSelect_AnalogOutputInt16_in_SimpleCommandHandler = DoSelect_AnalogOutputInt16_in_SimpleCommandHandler_override;
  pSimpleCommandHandler->pDoOperate_AnalogOutputInt16_in_SimpleCommandHandler = DoOperate_AnalogOutputInt16_in_SimpleCommandHandler_override;

  pSimpleCommandHandler->pDoSelect_AnalogOutputInt32_in_SimpleCommandHandler = DoSelect_AnalogOutputInt32_in_SimpleCommandHandler_override;
  pSimpleCommandHandler->pDoOperate_AnalogOutputInt32_in_SimpleCommandHandler = DoOperate_AnalogOutputInt32_in_SimpleCommandHandler_override;

  pSimpleCommandHandler->pDoSelect_AnalogOutputFloat32_in_SimpleCommandHandler = DoSelect_AnalogOutputFloat32_in_SimpleCommandHandler_override;
  pSimpleCommandHandler->pDoOperate_AnalogOutputFloat32_in_SimpleCommandHandler = DoOperate_AnalogOutputFloat32_in_SimpleCommandHandler_override;

  pSimpleCommandHandler->pDoSelect_AnalogOutputDouble64_in_SimpleCommandHandler = DoSelect_AnalogOutputDouble64_in_SimpleCommandHandler_override;
  pSimpleCommandHandler->pDoOperate_AnalogOutputDouble64_in_SimpleCommandHandler = DoOperate_AnalogOutputDouble64_in_SimpleCommandHandler_override;

  setParentPointer_in_SimpleCommandHandler(pSimpleCommandHandler, pSimpleCommandHandler);

  (pSimpleCommandHandler->iICommandHandler).pBegin_in_ICommandHandler = Begin_in_SimpleCommandHandler_override;
  (pSimpleCommandHandler->iICommandHandler).pEnd_in_ICommandHandler = End_in_SimpleCommandHandler_override;
  (pSimpleCommandHandler->iICommandHandler).pSelect_ControlRelayOutputBlock_in_ICommandHandler = Select_ControlRelayOutputBlock_in_SimpleCommandHandler_override;
  (pSimpleCommandHandler->iICommandHandler).pOperate_ControlRelayOutputBlock_in_ICommandHandler = Operate_ControlRelayOutputBlock_in_SimpleCommandHandler_override;

  (pSimpleCommandHandler->iICommandHandler).pSelect_AnalogOutputInt16_in_ICommandHandler = Select_AnalogOutputInt16_in_SimpleCommandHandler_override;
  /*
    (pSimpleCommandHandler->iICommandHandler).pOperate_AnalogOutputInt16_in_ICommandHandler = Operate_AnalogOutputInt16_in_SimpleCommandHandler_override;
  */
  (pSimpleCommandHandler->iICommandHandler).pSelect_AnalogOutputInt32_in_ICommandHandler = Select_AnalogOutputInt32_in_SimpleCommandHandler_override;
  (pSimpleCommandHandler->iICommandHandler).pOperate_AnalogOutputInt32_in_ICommandHandler = Operate_AnalogOutputInt32_in_SimpleCommandHandler_override;

  (pSimpleCommandHandler->iICommandHandler).pSelect_AnalogOutputFloat32_in_ICommandHandler = Select_AnalogOutputFloat32_in_SimpleCommandHandler_override;
  (pSimpleCommandHandler->iICommandHandler).pOperate_AnalogOutputFloat32_in_ICommandHandler = Operate_AnalogOutputFloat32_in_SimpleCommandHandler_override;

  (pSimpleCommandHandler->iICommandHandler).pSelect_AnalogOutputDouble64_in_ICommandHandler = Select_AnalogOutputDouble64_in_SimpleCommandHandler_override;
  (pSimpleCommandHandler->iICommandHandler).pOperate_AnalogOutputDouble64_in_ICommandHandler = Operate_AnalogOutputDouble64_in_SimpleCommandHandler_override;

  setParentPointer_in_ICommandHandler(&(pSimpleCommandHandler->iICommandHandler), pSimpleCommandHandler);
}

///*
void Begin_in_SimpleCommandHandler_override(void* pICommandHandler)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  Begin_in_SimpleCommandHandler(parent);
}
void End_in_SimpleCommandHandler_override(void* pICommandHandler)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  End_in_SimpleCommandHandler(parent);
}

CommandStatus_uint8_t Select_ControlRelayOutputBlock_in_SimpleCommandHandler_override(void* pICommandHandler, ControlRelayOutputBlock* command, uint16_t index)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Select_ControlRelayOutputBlock_in_SimpleCommandHandler(parent, command, index);
}
CommandStatus_uint8_t Operate_ControlRelayOutputBlock_in_SimpleCommandHandler_override(void* pICommandHandler, ControlRelayOutputBlock* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  /*
      CommandStatus_uint8_t Operate_ControlRelayOutputBlock_in_SimpleCommandHandler(SimpleCommandHandler*, ControlRelayOutputBlock* command,
                            uint16_t index,
                            IUpdateHandler* handler,
                            OperateType_uint8_t opType);//
  */
  return Operate_ControlRelayOutputBlock_in_SimpleCommandHandler(parent, command, index, handler, opType);
}

CommandStatus_uint8_t Select_AnalogOutputInt16_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputInt16* command, uint16_t index)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Select_AnalogOutputInt16_in_SimpleCommandHandler(parent, command, index);
}
/*
    CommandStatus_uint8_t Operate_AnalogOutputInt16_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputInt16* command,
                          uint16_t index,
                          IUpdateHandler* handler,
                          OperateType_uint8_t opType)
{
  SimpleCommandHandler *parent =
         (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Operate_AnalogOutputInt16_in_SimpleCommandHandler(parent, command, index, handler, opType);
}
*/
CommandStatus_uint8_t Select_AnalogOutputInt32_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputInt32* command, uint16_t index)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Select_AnalogOutputInt32_in_SimpleCommandHandler(parent, command, index);
}
CommandStatus_uint8_t Operate_AnalogOutputInt32_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputInt32* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Operate_AnalogOutputInt32_in_SimpleCommandHandler(parent, command, index, handler, opType);
}

CommandStatus_uint8_t Select_AnalogOutputFloat32_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputFloat32* command, uint16_t index)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Select_AnalogOutputFloat32_in_SimpleCommandHandler(parent, command, index);
}
CommandStatus_uint8_t Operate_AnalogOutputFloat32_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputFloat32* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Operate_AnalogOutputFloat32_in_SimpleCommandHandler(parent, command, index, handler, opType);
}

CommandStatus_uint8_t Select_AnalogOutputDouble64_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputDouble64* command, uint16_t index)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Select_AnalogOutputDouble64_in_SimpleCommandHandler(parent, command, index);
}
CommandStatus_uint8_t Operate_AnalogOutputDouble64_in_SimpleCommandHandler_override(void* pICommandHandler, AnalogOutputDouble64* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  SimpleCommandHandler *parent =
    (SimpleCommandHandler*)getParentPointer_in_ICommandHandler((ICommandHandler*)pICommandHandler);
  return Operate_AnalogOutputDouble64_in_SimpleCommandHandler(parent, command, index, handler, opType);
}

//*/
////void SimpleCommandHandler::Begin()
void Begin_in_SimpleCommandHandler(SimpleCommandHandler *pSimpleCommandHandler)
{
  ++(pSimpleCommandHandler->numStart);
}

////void SimpleCommandHandler::End()
void End_in_SimpleCommandHandler(SimpleCommandHandler *pSimpleCommandHandler)
{
  ++(pSimpleCommandHandler->numEnd);
}

////CommandStatus SimpleCommandHandler::Select(const ControlRelayOutputBlock& command, uint16_t index)
CommandStatus_uint8_t Select_ControlRelayOutputBlock_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, ControlRelayOutputBlock* command, uint16_t index)
{
////    this->DoSelect(command, index);
  DoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler(pSimpleCommandHandler, command, index);
  ++(((SimpleCommandHandler*)pSimpleCommandHandler)->numSelect);
  return ((SimpleCommandHandler*)pSimpleCommandHandler)->status;
}
CommandStatus_uint8_t Operate_ControlRelayOutputBlock_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, ControlRelayOutputBlock* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  UNUSED(handler);
////    this->DoOperate(command, index, opType);
  DoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler(pSimpleCommandHandler, command, index, opType);
  ++(pSimpleCommandHandler->numOperate);
  return pSimpleCommandHandler->status;
}

CommandStatus_uint8_t Select_AnalogOutputInt16_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt16* command, uint16_t index)
{
////    this->DoSelect(command, index);
  DoSelect_AnalogOutputInt16_in_SimpleCommandHandler(pSimpleCommandHandler, command, index);
  ++(pSimpleCommandHandler->numSelect);
  return pSimpleCommandHandler->status;
}
/*
CommandStatus_uint8_t Operate_AnalogOutputInt16_in_SimpleCommandHandler(SimpleCommandHandlerd* pSimpleCommandHandler, AnalogOutputInt16* command,
                                            uint16_t index,
                                            IUpdateHandler* handler,
                                            OperateType_uint8_t opType)
{
UNUSED(handler);
////    this->DoOperate(command, index, opType);
    DoOperate_AnalogOutputInt16_in_SimpleCommandHandler(pSimpleCommandHandler, command, index, opType);
    ++(pSimpleCommandHandler->numOperate);
    return pSimpleCommandHandler->status;
}
*/

CommandStatus_uint8_t Select_AnalogOutputInt32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt32* command, uint16_t index)
{
////    this->DoSelect(command, index);
  DoSelect_AnalogOutputInt32_in_SimpleCommandHandler(pSimpleCommandHandler, command, index);
  ++(pSimpleCommandHandler->numSelect);
  return pSimpleCommandHandler->status;
}
CommandStatus_uint8_t Operate_AnalogOutputInt32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt32* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  UNUSED(handler);
////    this->DoOperate(command, index, opType);
  DoOperate_AnalogOutputInt32_in_SimpleCommandHandler(pSimpleCommandHandler, command, index, opType);
  ++(pSimpleCommandHandler->numOperate);
  return pSimpleCommandHandler->status;
}

CommandStatus_uint8_t Select_AnalogOutputFloat32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputFloat32* command, uint16_t index)
{
////    this->DoSelect(command, index);
  DoSelect_AnalogOutputFloat32_in_SimpleCommandHandler(pSimpleCommandHandler, command, index);
  ++(pSimpleCommandHandler->numSelect);
  return pSimpleCommandHandler->status;
}
CommandStatus_uint8_t Operate_AnalogOutputFloat32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputFloat32* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  UNUSED(handler);
////    this->DoOperate(command, index, opType);
  DoOperate_AnalogOutputFloat32_in_SimpleCommandHandler(pSimpleCommandHandler, command, index, opType);
  ++(pSimpleCommandHandler->numOperate);
  return pSimpleCommandHandler->status;
}

CommandStatus_uint8_t Select_AnalogOutputDouble64_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputDouble64* command, uint16_t index)
{
////    this->DoSelect(command, index);
  DoSelect_AnalogOutputDouble64_in_SimpleCommandHandler(pSimpleCommandHandler, command, index);
  ++(pSimpleCommandHandler->numSelect);
  return pSimpleCommandHandler->status;
}

CommandStatus_uint8_t Operate_AnalogOutputDouble64_in_SimpleCommandHandler(SimpleCommandHandler *pSimpleCommandHandler, AnalogOutputDouble64* command,
    uint16_t index,
    IUpdateHandler* handler,
    OperateType_uint8_t opType)
{
  UNUSED(handler);
////    this->DoOperate(command, index, opType);
  DoOperate_AnalogOutputDouble64_in_SimpleCommandHandler(pSimpleCommandHandler, command, index, opType);
  ++(pSimpleCommandHandler->numOperate);
  return pSimpleCommandHandler->status;
}

//} // namespace opendnp3

void SuccessCommandHandler_in_SuccessCommandHandler(SuccessCommandHandler *pSuccessCommandHandler)
{
//    void SimpleCommandHandler_in_SimpleCommandHandler(SimpleCommandHandler *pSimpleCommandHandler, CommandStatus_uint8_t status);
  SimpleCommandHandler_in_SimpleCommandHandler(&(pSuccessCommandHandler->sSimpleCommandHandler), CommandStatus_SUCCESS);
}


void DoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler_override(void*ptr, ControlRelayOutputBlock* command, uint16_t index) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
}
void DoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler_override(void*ptr, ControlRelayOutputBlock* command, uint16_t index, OperateType_uint8_t opType) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
  UNUSED(opType);
}
void DoSelect_AnalogOutputInt16_in_SimpleCommandHandler_override(void*ptr, AnalogOutputInt16* command, uint16_t index) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(ptr);
  UNUSED(index);
}
void DoOperate_AnalogOutputInt16_in_SimpleCommandHandler_override(void*ptr, AnalogOutputInt16* command, uint16_t index, OperateType_uint8_t opType) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
  UNUSED(opType);
}
void DoSelect_AnalogOutputInt32_in_SimpleCommandHandler_override(void*ptr, AnalogOutputInt32* command, uint16_t index) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(ptr);
  UNUSED(index);
}
void DoOperate_AnalogOutputInt32_in_SimpleCommandHandler_override(void*ptr, AnalogOutputInt32* command, uint16_t index, OperateType_uint8_t opType) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
  UNUSED(opType);
}
void DoSelect_AnalogOutputFloat32_in_SimpleCommandHandler_override(void*ptr, AnalogOutputFloat32* command, uint16_t index) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
}
void DoOperate_AnalogOutputFloat32_in_SimpleCommandHandler_override(void*ptr, AnalogOutputFloat32* command, uint16_t index, OperateType_uint8_t opType) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
  UNUSED(opType);
}
void DoSelect_AnalogOutputDouble64_in_SimpleCommandHandler_override(void*ptr, AnalogOutputDouble64* command, uint16_t index) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
}
void DoOperate_AnalogOutputDouble64_in_SimpleCommandHandler_override(void*ptr, AnalogOutputDouble64* command, uint16_t index, OperateType_uint8_t opType) {
  UNUSED(ptr);
  UNUSED(command);
  UNUSED(index);
  UNUSED(opType);
}

void DoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, ControlRelayOutputBlock* command, uint16_t index)
{
  (pSimpleCommandHandler->pDoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index);
}
void DoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, ControlRelayOutputBlock* command, uint16_t index, OperateType_uint8_t opType)
{
  (pSimpleCommandHandler->pDoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index, opType);
}

void DoSelect_AnalogOutputInt16_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt16* command, uint16_t index)
{
  (pSimpleCommandHandler->pDoSelect_AnalogOutputInt16_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index);
}
void DoOperate_AnalogOutputInt16_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt16* command, uint16_t index, OperateType_uint8_t opType)
{
  (pSimpleCommandHandler->pDoOperate_AnalogOutputInt16_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index, opType);
}

void DoSelect_AnalogOutputInt32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt32* command, uint16_t index)
{
  (pSimpleCommandHandler->pDoSelect_AnalogOutputInt32_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index);
}

void DoOperate_AnalogOutputInt32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt32* command, uint16_t index, OperateType_uint8_t opType)
{
  (pSimpleCommandHandler->pDoOperate_AnalogOutputInt32_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index, opType);
}

/*
    void DoOperate_AnalogOutputInt32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputInt32* command, uint16_t index, OperateType_uint8_t opType)
{
 (pSimpleCommandHandler->pDoSelect_AnalogOutputInt32_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index, opType);
}
*/
void DoSelect_AnalogOutputFloat32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputFloat32* command, uint16_t index)
{
  (pSimpleCommandHandler->pDoSelect_AnalogOutputFloat32_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index);
}
void DoOperate_AnalogOutputFloat32_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputFloat32* command, uint16_t index, OperateType_uint8_t opType)
{
  (pSimpleCommandHandler->pDoOperate_AnalogOutputFloat32_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index, opType);
}

void DoSelect_AnalogOutputDouble64_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputDouble64* command, uint16_t index)
{
  (pSimpleCommandHandler->pDoSelect_AnalogOutputDouble64_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index);
}
void DoOperate_AnalogOutputDouble64_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, AnalogOutputDouble64* command, uint16_t index, OperateType_uint8_t opType)
{
  (pSimpleCommandHandler->pDoOperate_AnalogOutputDouble64_in_SimpleCommandHandler)(pSimpleCommandHandler, command, index, opType);
}

void* getParentPointer_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler)
{
  return pSimpleCommandHandler->pParentPointer_in_SimpleCommandHandler;
}
void  setParentPointer_in_SimpleCommandHandler(SimpleCommandHandler* pSimpleCommandHandler, void* pParentPointer)
{
  pSimpleCommandHandler->pParentPointer_in_SimpleCommandHandler = pParentPointer;
}

