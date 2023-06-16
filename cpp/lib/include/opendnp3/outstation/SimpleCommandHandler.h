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
#ifndef OPENDNP3_SIMPLECOMMANDHANDLER_H
#define OPENDNP3_SIMPLECOMMANDHANDLER_H

////#include "opendnp3/outstation/ICommandHandler.h"
#include "ICommandHandler.h"

//#include <memory>

////namespace opendnp3
////{

/**
 * Mock ICommandHandler used for examples and demos
 */
////class SimpleCommandHandler : public ICommandHandler
typedef struct SimpleCommandHandler
{
    ICommandHandler iICommandHandler;
////public:

    void (*pDoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler)(void*, ControlRelayOutputBlock* command, uint16_t index);// {}
    void (*pDoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler)(void*, ControlRelayOutputBlock* command, uint16_t index, OperateType_uint8_t opType);// {}

    void (*pDoSelect_AnalogOutputInt16_in_SimpleCommandHandler)(void*, AnalogOutputInt16* command, uint16_t index);// {}
    void (*pDoOperate_AnalogOutputInt16_in_SimpleCommandHandler)(void*, AnalogOutputInt16* command, uint16_t index, OperateType_uint8_t opType);// {}

    void (*pDoSelect_AnalogOutputInt32_in_SimpleCommandHandler)(void*, AnalogOutputInt32* command, uint16_t index);// {}
    void (*pDoOperate_AnalogOutputInt32_in_SimpleCommandHandler)(void*, AnalogOutputInt32* command, uint16_t index, OperateType_uint8_t opType);// {}

    void (*pDoSelect_AnalogOutputFloat32_in_SimpleCommandHandler)(void*, AnalogOutputFloat32* command, uint16_t index);// {}
    void (*pDoOperate_AnalogOutputFloat32_in_SimpleCommandHandler)(void*, AnalogOutputFloat32* command, uint16_t index, OperateType_uint8_t opType);// {}

    void (*pDoSelect_AnalogOutputDouble64_in_SimpleCommandHandler)(void*, AnalogOutputDouble64* command, uint16_t index);// {}
    void (*pDoOperate_AnalogOutputDouble64_in_SimpleCommandHandler)(void*, AnalogOutputDouble64* command, uint16_t index, OperateType_uint8_t opType);// {}

////protected:

    CommandStatus_uint8_t status;

////public:
    uint32_t numOperate;
    uint32_t numSelect;
    uint32_t numStart;
    uint32_t numEnd;
} SimpleCommandHandler;

    /**
     * @param status The status value to return in response to all commands
     */
    void SimpleCommandHandler_in_SimpleCommandHandler(SimpleCommandHandler *pSimpleCommandHandler, CommandStatus_uint8_t status);
    void Begin_in_SimpleCommandHandler(void*);// override;
    void End_in_SimpleCommandHandler(void*);// override;

    CommandStatus_uint8_t Select_ControlRelayOutputBlock_in_SimpleCommandHandler(void*, ControlRelayOutputBlock* command, uint16_t index);// override;
    CommandStatus_uint8_t Operate_ControlRelayOutputBlock_in_SimpleCommandHandler(void*, ControlRelayOutputBlock* command,
                          uint16_t index,
                          IUpdateHandler* handler,
                          OperateType_uint8_t opType);// override;

    CommandStatus_uint8_t Select_AnalogOutputInt16_in_SimpleCommandHandler(void*, AnalogOutputInt16* command, uint16_t index);// override;
    CommandStatus_uint8_t Operate_AnalogOutputInt16_in_SimpleCommandHandler(void*, AnalogOutputInt16* command,
                          uint16_t index,
                          IUpdateHandler* handler,
                          OperateType_uint8_t opType);// override;

    CommandStatus_uint8_t Select_AnalogOutputInt32_in_SimpleCommandHandler(void*, AnalogOutputInt32* command, uint16_t index);// override;
    CommandStatus_uint8_t Operate_AnalogOutputInt32_in_SimpleCommandHandler(void*, AnalogOutputInt32* command,
                          uint16_t index,
                          IUpdateHandler* handler,
                          OperateType_uint8_t opType);// override;

    CommandStatus_uint8_t Select_AnalogOutputFloat32_in_SimpleCommandHandler(void*, AnalogOutputFloat32* command, uint16_t index);// override;
    CommandStatus_uint8_t Operate_AnalogOutputFloat32_in_SimpleCommandHandler(void*, AnalogOutputFloat32* command,
                          uint16_t index,
                          IUpdateHandler* handler,
                          OperateType_uint8_t opType);// override;

    CommandStatus_uint8_t Select_AnalogOutputDouble64_in_SimpleCommandHandler(void*, AnalogOutputDouble64* command, uint16_t index);// override;
    CommandStatus_uint8_t Operate_AnalogOutputDouble64_in_SimpleCommandHandler(void*, AnalogOutputDouble64* command,
                          uint16_t index,
                          IUpdateHandler* handler,
                          OperateType_uint8_t opType);// override;

    void DoSelect_ControlRelayOutputBlock_in_SimpleCommandHandler(void*, ControlRelayOutputBlock* command, uint16_t index);// {}
    void DoOperate_ControlRelayOutputBlock_in_SimpleCommandHandler(void*, ControlRelayOutputBlock* command, uint16_t index, OperateType_uint8_t opType);// {}

    void DoSelect_AnalogOutputInt16_in_SimpleCommandHandler(void*, AnalogOutputInt16* command, uint16_t index);// {}
    void DoOperate_AnalogOutputInt16_in_SimpleCommandHandler(void*, AnalogOutputInt16* command, uint16_t index, OperateType_uint8_t opType);// {}

    void DoSelect_AnalogOutputInt32_in_SimpleCommandHandler(void*, AnalogOutputInt32* command, uint16_t index);// {}
    void DoOperate_AnalogOutputInt32_in_SimpleCommandHandler(void*, AnalogOutputInt32* command, uint16_t index, OperateType_uint8_t opType);// {}

    void DoSelect_AnalogOutputFloat32_in_SimpleCommandHandler(void*, AnalogOutputFloat32* command, uint16_t index);// {}
    void DoOperate_AnalogOutputFloat32_in_SimpleCommandHandler(void*, AnalogOutputFloat32* command, uint16_t index, OperateType_uint8_t opType);// {}

    void DoSelect_AnalogOutputDouble64_in_SimpleCommandHandler(void*, AnalogOutputDouble64* command, uint16_t index);// {}
    void DoOperate_AnalogOutputDouble64_in_SimpleCommandHandler(void*, AnalogOutputDouble64* command, uint16_t index, OperateType_uint8_t opType);// {}

/**
 * A singleton command handler that always returns success
 */
////class SuccessCommandHandler : public SimpleCommandHandler
typedef struct 
{
  SimpleCommandHandler sSimpleCommandHandler;
////public:
////    static std::shared_ptr<ICommandHandler> Create()
////    {
////        return std::make_shared<SuccessCommandHandler>();
////    }

////    SuccessCommandHandler() : SimpleCommandHandler(CommandStatus::SUCCESS) {}
} SuccessCommandHandler;
 void SuccessCommandHandler_in_SuccessCommandHandler(SuccessCommandHandler *pSuccessCommandHandler);

////} // namespace opendnp3


#endif
