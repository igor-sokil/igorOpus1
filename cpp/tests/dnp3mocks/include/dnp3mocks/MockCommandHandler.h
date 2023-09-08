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
#ifndef OPENDNP3_UNITTESTS_MOCK_COMMAND_HANDLER_H
#define OPENDNP3_UNITTESTS_MOCK_COMMAND_HANDLER_H

////#include <opendnp3/app/Indexed.h>
////#include <opendnp3/outstation/SimpleCommandHandler.h>
#include <Indexed.h>
#include <SimpleCommandHandler.h>

#include <vector>

////template<class T> class Operation : public opendnp3::Indexed<T>
////{
////public:
////    Operation(T value, uint16_t index, opendnp3::OperateType opType_)
////        : opendnp3::Indexed<T>(value, index), opType(opType_)
///    {
///    }

////    opendnp3::OperateType opType;
////};

//-------------------ControlRelayOutputBlock--------------------------------
////template<class T> class Operation : public opendnp3::Indexed<T>
typedef struct
{
  Indexed_for_ControlRelayOutputBlock iIndexed_for_ControlRelayOutputBlock;
////public:
////    Operation(T value, uint16_t index, opendnp3::OperateType opType_)
////        : opendnp3::Indexed<T>(value, index), opType(opType_)
///    {
///    }

////    opendnp3::OperateType opType;
  OperateType_uint8_t opType;
} Operation_for_ControlRelayOutputBlock;

void Operation_for_ControlRelayOutputBlock_in_Operation_for_ControlRelayOutputBlock(Operation_for_ControlRelayOutputBlock *pOperation_for_ControlRelayOutputBlock,
    ControlRelayOutputBlock value,
    uint16_t index,
    OperateType_uint8_t opType_
                                                                                   );
//-------------------ControlRelayOutputBlock--------------------------------
//-------------------AnalogOutputInt16--------------------------------
////template<class T> class Operation : public opendnp3::Indexed<T>
typedef struct
{
  Indexed_for_AnalogOutputInt16 iIndexed_for_AnalogOutputInt16;
////public:
////    Operation(T value, uint16_t index, opendnp3::OperateType opType_)
////        : opendnp3::Indexed<T>(value, index), opType(opType_)
///    {
///    }

////    opendnp3::OperateType opType;
  OperateType_uint8_t opType;
} Operation_for_AnalogOutputInt16;

void Operation_for_AnalogOutputInt16_in_Operation_for_AnalogOutputInt16(Operation_for_AnalogOutputInt16 *pOperation_for_AnalogOutputInt16,
    AnalogOutputInt16 value,
    uint16_t index,
    OperateType_uint8_t opType_
                                                                       );
//-------------------AnalogOutputInt16--------------------------------
//-------------------AnalogOutputInt32--------------------------------
////template<class T> class Operation : public opendnp3::Indexed<T>
typedef struct
{
  Indexed_for_AnalogOutputInt32 iIndexed_for_AnalogOutputInt32;
////public:
////    Operation(T value, uint16_t index, opendnp3::OperateType opType_)
////        : opendnp3::Indexed<T>(value, index), opType(opType_)
///    {
///    }

////    opendnp3::OperateType opType;
  OperateType_uint8_t opType;
} Operation_for_AnalogOutputInt32;

void Operation_for_AnalogOutputInt32_in_Operation_for_AnalogOutputInt32(Operation_for_AnalogOutputInt32 *pOperation_for_AnalogOutputInt32,
    AnalogOutputInt32 value,
    uint16_t index,
    OperateType_uint8_t opType_
                                                                       );
//-------------------AnalogOutputInt32--------------------------------
//-------------------AnalogOutputFloat32--------------------------------
////template<class T> class Operation : public opendnp3::Indexed<T>
typedef struct
{
  Indexed_for_AnalogOutputFloat32 iIndexed_for_AnalogOutputFloat32;
////public:
////    Operation(T value, uint16_t index, opendnp3::OperateType opType_)
////        : opendnp3::Indexed<T>(value, index), opType(opType_)
///    {
///    }

////    opendnp3::OperateType opType;
  OperateType_uint8_t opType;
} Operation_for_AnalogOutputFloat32;

void Operation_for_AnalogOutputFloat32_in_Operation_for_AnalogOutputFloat32(Operation_for_AnalogOutputFloat32 *pOperation_for_AnalogOutputFloat32,
    AnalogOutputFloat32 value,
    uint16_t index,
    OperateType_uint8_t opType_
                                                                           );
//-------------------AnalogOutputFloat32--------------------------------
//-------------------AnalogOutputDouble64--------------------------------
////template<class T> class Operation : public opendnp3::Indexed<T>
typedef struct
{
  Indexed_for_AnalogOutputDouble64 iIndexed_for_AnalogOutputDouble64;
////public:
////    Operation(T value, uint16_t index, opendnp3::OperateType opType_)
////        : opendnp3::Indexed<T>(value, index), opType(opType_)
///    {
///    }

////    opendnp3::OperateType opType;
  OperateType_uint8_t opType;
} Operation_for_AnalogOutputDouble64;

void Operation_for_AnalogOutputDouble64_in_Operation_for_AnalogOutputDouble64(Operation_for_AnalogOutputDouble64 *pOperation_for_AnalogOutputDouble64,
    AnalogOutputDouble64 value,
    uint16_t index,
    OperateType_uint8_t opType_
                                                                             );
//-------------------AnalogOutputDouble64--------------------------------

////class MockCommandHandler final : public opendnp3::SimpleCommandHandler
typedef struct
{
  SimpleCommandHandler sSimpleCommandHandler;

////public:
////    MockCommandHandler(opendnp3::CommandStatus status = opendnp3::CommandStatus::SUCCESS)
////        : opendnp3::SimpleCommandHandler(status)
////    {
////    }

////    void SetResponse(opendnp3::CommandStatus status_)
////    {
////        status = status_;
////    }

////    uint32_t NumInvocations() const
////    {
////        return numSelect + numOperate;
////    }

////    uint32_t NumSelect() const
////    {
////        return numSelect;
////    }

////    uint32_t NumOperate() const
////    {
////        return numOperate;
////    }

////protected:
////    virtual void DoOperate(const opendnp3::ControlRelayOutputBlock& command,
////                           uint16_t index,
////                           opendnp3::OperateType opType) override
////    {
////        this->crobOps.push_back(Operation<opendnp3::ControlRelayOutputBlock>(command, index, opType));
////    }
////
////    virtual void DoOperate(const opendnp3::AnalogOutputInt16& command,
////                           uint16_t index,
////                           opendnp3::OperateType opType) override
////    {
////        this->aoInt16Ops.push_back(Operation<opendnp3::AnalogOutputInt16>(command, index, opType));
////    }

////    virtual void DoOperate(const opendnp3::AnalogOutputInt32& command,
////                           uint16_t index,
////                           opendnp3::OperateType opType) override
////    {
////        this->aoInt32Ops.push_back(Operation<opendnp3::AnalogOutputInt32>(command, index, opType));
////    }

////    virtual void DoOperate(const opendnp3::AnalogOutputFloat32& command,
////                           uint16_t index,
////                           opendnp3::OperateType opType) override
////    {
////        this->aoFloat32Ops.push_back(Operation<opendnp3::AnalogOutputFloat32>(command, index, opType));
////    }

////    virtual void DoOperate(const opendnp3::AnalogOutputDouble64& command,
////                           uint16_t index,
////                           opendnp3::OperateType opType) override
////    {
////        this->aoDouble64Ops.push_back(Operation<opendnp3::AnalogOutputDouble64>(command, index, opType));
////    }

////public:
  std::vector<Operation_for_ControlRelayOutputBlock> crobOps;
  std::vector<Operation_for_AnalogOutputInt16> aoInt16Ops;
  std::vector<Operation_for_AnalogOutputInt32> aoInt32Ops;
  std::vector<Operation_for_AnalogOutputFloat32> aoFloat32Ops;
  std::vector<Operation_for_AnalogOutputDouble64> aoDouble64Ops;
} MockCommandHandler;

///*
void DoOperate_ControlRelayOutputBlock_in_MockCommandHandler_override(void*, ControlRelayOutputBlock* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputInt16_in_MockCommandHandler_override(void*, AnalogOutputInt16* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputInt32_in_MockCommandHandler_override(void*, AnalogOutputInt32* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputFloat32_in_MockCommandHandler_override(void*, AnalogOutputFloat32* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputDouble64_in_MockCommandHandler_override(void*, AnalogOutputDouble64* command, uint16_t index, OperateType_uint8_t opType);

void DoOperate_ControlRelayOutputBlock_in_MockCommandHandler(MockCommandHandler*, ControlRelayOutputBlock* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputInt16_in_MockCommandHandler(MockCommandHandler*, AnalogOutputInt16* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputInt32_in_MockCommandHandler(MockCommandHandler*, AnalogOutputInt32* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputFloat32_in_MockCommandHandler(MockCommandHandler*, AnalogOutputFloat32* command, uint16_t index, OperateType_uint8_t opType);
void DoOperate_AnalogOutputDouble64_in_MockCommandHandler(MockCommandHandler*, AnalogOutputDouble64* command, uint16_t index, OperateType_uint8_t opType);
//*/

void  MockCommandHandler_in_MockCommandHandler(MockCommandHandler *pMockCommandHandler, CommandStatus_uint8_t status);/// = opendnp3::CommandStatus::SUCCESS)
void SetResponse_in_MockCommandHandler(MockCommandHandler *pMockCommandHandler, CommandStatus status_);
uint32_t NumInvocations_in_MockCommandHandler(MockCommandHandler *pMockCommandHandler);
uint32_t NumSelect_in_MockCommandHandler(MockCommandHandler *pMockCommandHandler);
uint32_t NumOperate_in_MockCommandHandler(MockCommandHandler *pMockCommandHandler);



#endif
