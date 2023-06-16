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
#ifndef OPENDNP3_ICOMMANDHANDLER_H
#define OPENDNP3_ICOMMANDHANDLER_H

#include "IUpdateHandler.h"

////#include "opendnp3/app/AnalogOutput.h"
////#include "opendnp3/app/ControlRelayOutputBlock.h"
////#include "opendnp3/gen/OperateType.h"

#include "AnalogOutput.h"
#include "ControlRelayOutputBlock.h"
#include "OperateType.h"

////namespace opendnp3
////{

/**
 * Interface used to dispatch SELECT / OPERATE / DIRECT OPERATE (Binary/Analog output) from the outstation to
 * application code.
 *
 * The ITransactable sub-interface is used to determine the start and end of an ASDU containing commands.
 */
////class ICommandHandler
typedef struct
{
////public:
////    virtual ~ICommandHandler() = default;

    /**
     * called when a command APDU begins processing
     */
    void (*pBegin_in_ICommandHandler)(void*);// = 0;

    /**
     * called when a command APDU ends processing
     */
    void (*pEnd_in_ICommandHandler)(void*);// = 0;

    /**
     * Ask if the application supports a ControlRelayOutputBlock - group 12 variation 1
     *
     * @param command command to operate
     * @param index index of the command
     * @return result of request
     */
    CommandStatus_uint8_t (*pSelect_ControlRelayOutputBlock_in_ICommandHandler)(void*, ControlRelayOutputBlock* command, uint16_t index);// = 0;

    /**
     * Operate a ControlRelayOutputBlock - group 12 variation 1
     *
     * @param command command to operate
     * @param index index of the command
     * @param handler interface for loading measurement changes
     * @param opType the operation type the outstation received.
     * @return result of request
     */
    CommandStatus_uint8_t (*pOperate_ControlRelayOutputBlock_in_ICommandHandler)(void*, ControlRelayOutputBlock* command,
                                  uint16_t index,
                                  IUpdateHandler* handler,
                                  OperateType_uint8_t opType);
//        = 0;

    /**
     * Ask if the application supports a 16 bit analog output - group 41 variation 2
     *
     * @param command command to operate
     * @param index index of the command
     * @return result of request
     */
    CommandStatus_uint8_t (*pSelect_AnalogOutputInt16_in_ICommandHandler)(void*, AnalogOutputInt16* command, uint16_t index);// = 0;

    /**
     * Ask if the application supports a 16 bit analog output - group 41 variation 2
     *
     * @param command command to operate
     * @param index index of the command
     * @param handler interface for loading measurement changes
     * @param opType the operation type the outstation received.
     * @return result of request
     */
    CommandStatus_uint8_t (*pOperate_AnalogOutputInt16_in_ICommandHandler)(void*, AnalogOutputInt16* command,
                                  uint16_t index,
                                  IUpdateHandler* handler,
                                  OperateType_uint8_t opType);
//        = 0;

    /**
     * Ask if the application supports a 32 bit analog output - group 41 variation 1
     *
     * @param command command to operate
     * @param index index of the command
     * @return result of request
     */
    CommandStatus_uint8_t (*pSelect_AnalogOutputInt32_in_ICommandHandler)(void*, AnalogOutputInt32* command, uint16_t index);// = 0;

    /**
     * Operate a 32 bit analog output - group 41 variation 1
     *
     * @param command command to operate
     * @param index index of the command
     * @param handler interface for loading measurement changes
     * @param opType the operation type the outstation received.
     * @return result of request
     */
    CommandStatus_uint8_t (*pOperate_AnalogOutputInt32_in_ICommandHandler)(void*, AnalogOutputInt32* command,
                                  uint16_t index,
                                  IUpdateHandler* handler,
                                  OperateType_uint8_t opType);
//        = 0;

    /**
     * Ask if the application supports a single precision, floating point analog output - group 41 variation 3
     *
     * @param command command to operate
     * @param index index of the command
     * @return result of request
     */
    CommandStatus_uint8_t (*pSelect_AnalogOutputFloat32_in_ICommandHandler)(void*, AnalogOutputFloat32* command, uint16_t index);// = 0;

    /**
     * Operate a single precision, floating point analog output - group 41 variation 3
     *
     * @param command command to operate
     * @param index index of the command
     * @param handler interface for loading measurement changes
     * @param opType the operation type the outstation received.
     * @return result of request
     */
    CommandStatus_uint8_t (*pOperate_AnalogOutputFloat32_in_ICommandHandler)(void*, AnalogOutputFloat32* command,
                                  uint16_t index,
                                  IUpdateHandler* handler,
                                  OperateType_uint8_t opType);
//        = 0;

    /**
     * Ask if the application supports a double precision, floating point analog output - group 41 variation 4
     *
     * @param command command to operate
     * @param index index of the command
     * @return result of request
     */
    CommandStatus_uint8_t (*pSelect_AnalogOutputDouble64_in_ICommandHandler)(void*, AnalogOutputDouble64* command, uint16_t index);// = 0;

    /**
     * Operate a double precision, floating point analog output - group 41 variation 4
     *
     * @param command command to operate
     * @param index index of the command
     * @param handler interface for loading measurement changes
     * @param opType the operation type the outstation received.
     * @return result of request
     */
    CommandStatus_uint8_t (*pOperate_AnalogOutputDouble64_in_ICommandHandler)(void*, AnalogOutputDouble64* command,
                                  uint16_t index,
                                  IUpdateHandler* handler,
                                  OperateType_uint8_t opType);
//        = 0;
} ICommandHandler;

////} // namespace opendnp3

#endif
