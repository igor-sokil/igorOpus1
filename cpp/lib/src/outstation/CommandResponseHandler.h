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

#ifndef OPENDNP3_COMMANDRESPONSEHANDLER_H
#define OPENDNP3_COMMANDRESPONSEHANDLER_H

////#include "app/APDUResponse.h"
////#include "app/parsing/IAPDUHandler.h"
////#include "outstation/ICommandAction.h"

////#include "opendnp3/logging/Logger.h"

#include "APDUResponse.h"
#include "IAPDUHandler.h"
#include "ICommandAction.h"
#include "HeaderWriter_for_Analog.h"
#include "PrefixedWriteIterator_for_ControlRelayOutputBlock.h"
#include "PrefixedWriteIterator_for_AnalogOutputInt16.h"
#include "PrefixedWriteIterator_for_AnalogOutputInt32.h"
#include "PrefixedWriteIterator_for_AnalogOutputFloat32.h"
#include "PrefixedWriteIterator_for_AnalogOutputDouble64.h"
#include "HeaderWriter_for_ControlRelayOutputBlock.h"

////namespace opendnp3
////{

////class CommandResponseHandler : public IAPDUHandler
typedef struct
{
  IAPDUHandler iIAPDUHandler;
////public:
////    CommandResponseHandler(uint32_t maxCommands_, ICommandAction* pCommandAction_, HeaderWriter* pWriter_);

////    bool AllCommandsSuccessful() const
////    {
////        return numRequests == numSuccess;
////    }

////    virtual bool IsAllowed(uint32_t headerCount, GroupVariation gv, QualifierCode qc) override final;

////private:
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<ControlRelayOutputBlock>>& meas) override final;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputInt16>>& meas) override final;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputInt32>>& meas) override final;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputFloat32>>& meas) override final;
////    virtual IINField ProcessHeader(const PrefixHeader& header,
////                                   const ICollection<Indexed<AnalogOutputDouble64>>& meas) override final;
////
////    IINField ProcessIndexPrefixTwoByte(const HeaderRecord& record,
////                                       const ICollection<Indexed<ControlRelayOutputBlock>>& meas);
////    IINField ProcessIndexPrefixTwoByte(const HeaderRecord& record, const ICollection<Indexed<AnalogOutputInt16>>& meas);
////    IINField ProcessIndexPrefixTwoByte(const HeaderRecord& record, const ICollection<Indexed<AnalogOutputInt32>>& meas);
////    IINField ProcessIndexPrefixTwoByte(const HeaderRecord& record,
////                                       const ICollection<Indexed<AnalogOutputFloat32>>& meas);
////    IINField ProcessIndexPrefixTwoByte(const HeaderRecord& record,
////                                       const ICollection<Indexed<AnalogOutputDouble64>>& meas);

////    IINField ProcessIndexPrefixOneByte(const HeaderRecord& record,
////                                       const ICollection<Indexed<ControlRelayOutputBlock>>& meas);
////    IINField ProcessIndexPrefixOneByte(const HeaderRecord& record, const ICollection<Indexed<AnalogOutputInt16>>& meas);
////    IINField ProcessIndexPrefixOneByte(const HeaderRecord& record, const ICollection<Indexed<AnalogOutputInt32>>& meas);
////    IINField ProcessIndexPrefixOneByte(const HeaderRecord& record,
////                                       const ICollection<Indexed<AnalogOutputFloat32>>& meas);
////    IINField ProcessIndexPrefixOneByte(const HeaderRecord& record,
////                                       const ICollection<Indexed<AnalogOutputDouble64>>& meas);

  ICommandAction* pCommandAction;
  uint32_t numRequests;
  uint32_t numSuccess;
  uint32_t maxCommands;
  HeaderWriter* pWriter;

////    template<class T> IINField ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas);
////
////    template<class Target, class IndexType>
////    IINField RespondToHeader(QualifierCode qualifier,
////                             const DNP3Serializer<Target>& serializer,
////                             const ICollection<Indexed<Target>>& values);
////
////    template<class Target, class IndexType>
////    IINField RespondToHeaderWithIterator(QualifierCode qualifier,
////                                         const DNP3Serializer<Target>& serializer,
////                                         const ICollection<Indexed<Target>>& values,
////                                         PrefixedWriteIterator<IndexType, Target>* pIterator = nullptr);

////    template<class Target> CommandStatus ProcessCommand(const Target& command, uint16_t index);
} CommandResponseHandler;

void CommandResponseHandler_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, uint32_t maxCommands_, ICommandAction* pCommandAction_, HeaderWriter* pWriter_);
boolean AllCommandsSuccessful_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler);

boolean IsAllowed_in_CommandResponseHandler_override(void *, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc);

IINField ProcessHeader_PrefixHeader_Indexed_for_ControlRelayOutputBlock_in_CommandResponseHandler_override(void *,
    PrefixHeader* header,
    ICollection_Indexed_for_ControlRelayOutputBlock* meas);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt16_in_CommandResponseHandler_override(void*,
    PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt16* meas);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputInt32_in_CommandResponseHandler_override(void *,
    PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputInt32* meas);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputFloat32_in_CommandResponseHandler_override(void*,
    PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputFloat32* meas);
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputDouble64_in_CommandResponseHandler_override(void *,
    PrefixHeader* header,
    ICollection_Indexed_for_AnalogOutputDouble64* meas);

IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_ControlRelayOutputBlock* meas);
IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt16* meas);
IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt32* meas);
IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_AnalogOutputFloat32* meas);
IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputDouble64_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_AnalogOutputDouble64* meas);

IINField ProcessIndexPrefixOneByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_ControlRelayOutputBlock* meas);
IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt16* meas);
IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt32* meas);
IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_AnalogOutputFloat32* meas);
IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputDouble64_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record,
    ICollection_Indexed_for_AnalogOutputDouble64* meas);

IINField ProcessAny_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_ControlRelayOutputBlock* meas);
IINField ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt16* meas);
IINField ProcessAny_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt32* meas);
IINField ProcessAny_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputFloat32* meas);
IINField ProcessAny_for_AnalogOutputDouble64_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    HeaderRecord* record, ICollection_Indexed_for_AnalogOutputDouble64* meas);

//---------------------------------------ControlRelayOutputBlock----------------------------------------------------------
////template<class Target> CommandStatus CommandResponseHandler::ProcessCommand(const Target& command, uint16_t index)
CommandStatus_uint8_t ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    ControlRelayOutputBlock* command, uint16_t index);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeaderWithIterator(QualifierCode qualifier,
////                                                             const DNP3Serializer<Target>& serializer,
////                                                             const ICollection<Indexed<Target>>& values,
////                                                             PrefixedWriteIterator<IndexType, Target>* pIterator)
IINField RespondToHeaderWithIterator_for_ControlRelayOutputBlock_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
    ICollection_Indexed_for_ControlRelayOutputBlock* values,
    PrefixedWriteIterator_for_UInt8_ControlRelayOutputBlock* pIterator);
IINField RespondToHeaderWithIterator_for_ControlRelayOutputBlock_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
    ICollection_Indexed_for_ControlRelayOutputBlock* values,
    PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock* pIterator);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeader(QualifierCode qualifier,
////                                                 const DNP3Serializer<Target>& serializer,
////                                                 const ICollection<Indexed<Target>>& values)
IINField  RespondToHeader_for_ControlRelayOutputBlock_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
    ICollection_Indexed_for_ControlRelayOutputBlock* values);
IINField  RespondToHeader_for_ControlRelayOutputBlock_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_ControlRelayOutputBlock* serializer,
    ICollection_Indexed_for_ControlRelayOutputBlock* values);
//---------------------------------------ControlRelayOutputBlock----------------------------------------------------------
//---------------------------------------AnalogOutputInt16----------------------------------------------------------
////template<class Target> CommandStatus CommandResponseHandler::ProcessCommand(const Target& command, uint16_t index)
CommandStatus_uint8_t ProcessCommand_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    AnalogOutputInt16* command, uint16_t index);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeaderWithIterator(QualifierCode qualifier,
////                                                             const DNP3Serializer<Target>& serializer,
////                                                             const ICollection<Indexed<Target>>& values,
////                                                             PrefixedWriteIterator<IndexType, Target>* pIterator)
IINField RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values,
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt16* pIterator);
IINField RespondToHeaderWithIterator_for_AnalogOutputInt16_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values,
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt16* pIterator);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeader(QualifierCode qualifier,
////                                                 const DNP3Serializer<Target>& serializer,
////                                                 const ICollection<Indexed<Target>>& values)
IINField  RespondToHeader_for_AnalogOutputInt16_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values);
IINField  RespondToHeader_for_AnalogOutputInt16_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt16* serializer,
    ICollection_Indexed_for_AnalogOutputInt16* values);
//---------------------------------------AnalogOutputInt16----------------------------------------------------------
//---------------------------------------AnalogOutputInt32----------------------------------------------------------
////template<class Target> CommandStatus CommandResponseHandler::ProcessCommand(const Target& command, uint16_t index)
CommandStatus_uint8_t ProcessCommand_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    AnalogOutputInt32* command, uint16_t index);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeaderWithIterator(QualifierCode qualifier,
////                                                             const DNP3Serializer<Target>& serializer,
////                                                             const ICollection<Indexed<Target>>& values,
////                                                             PrefixedWriteIterator<IndexType, Target>* pIterator)
IINField RespondToHeaderWithIterator_for_AnalogOutputInt32_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt32* serializer,
    ICollection_Indexed_for_AnalogOutputInt32* values,
    PrefixedWriteIterator_for_UInt8_AnalogOutputInt32* pIterator);
IINField RespondToHeaderWithIterator_for_AnalogOutputInt32_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt32* serializer,
    ICollection_Indexed_for_AnalogOutputInt32* values,
    PrefixedWriteIterator_for_UInt16_AnalogOutputInt32* pIterator);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeader(QualifierCode qualifier,
////                                                 const DNP3Serializer<Target>& serializer,
////                                                 const ICollection<Indexed<Target>>& values)
IINField  RespondToHeader_for_AnalogOutputInt32_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt32* serializer,
    ICollection_Indexed_for_AnalogOutputInt32* values);
IINField  RespondToHeader_for_AnalogOutputInt32_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputInt32* serializer,
    ICollection_Indexed_for_AnalogOutputInt32* values);
//---------------------------------------AnalogOutputInt32----------------------------------------------------------
//---------------------------------------AnalogOutputFloat32----------------------------------------------------------
////template<class Target> CommandStatus CommandResponseHandler::ProcessCommand(const Target& command, uint16_t index)
CommandStatus_uint8_t ProcessCommand_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    AnalogOutputFloat32* command, uint16_t index);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeaderWithIterator(QualifierCode qualifier,
////                                                             const DNP3Serializer<Target>& serializer,
////                                                             const ICollection<Indexed<Target>>& values,
////                                                             PrefixedWriteIterator<IndexType, Target>* pIterator)
IINField RespondToHeaderWithIterator_for_AnalogOutputFloat32_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputFloat32* serializer,
    ICollection_Indexed_for_AnalogOutputFloat32* values,
    PrefixedWriteIterator_for_UInt8_AnalogOutputFloat32* pIterator);
IINField RespondToHeaderWithIterator_for_AnalogOutputFloat32_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputFloat32* serializer,
    ICollection_Indexed_for_AnalogOutputFloat32* values,
    PrefixedWriteIterator_for_UInt16_AnalogOutputFloat32* pIterator);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeader(QualifierCode qualifier,
////                                                 const DNP3Serializer<Target>& serializer,
////                                                 const ICollection<Indexed<Target>>& values)
IINField  RespondToHeader_for_AnalogOutputFloat32_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputFloat32* serializer,
    ICollection_Indexed_for_AnalogOutputFloat32* values);
IINField  RespondToHeader_for_AnalogOutputFloat32_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputFloat32* serializer,
    ICollection_Indexed_for_AnalogOutputFloat32* values);
//---------------------------------------AnalogOutputFloat32----------------------------------------------------------
//---------------------------------------AnalogOutputDouble64----------------------------------------------------------
////template<class Target> CommandStatus CommandResponseHandler::ProcessCommand(const Target& command, uint16_t index)
CommandStatus_uint8_t ProcessCommand_for_AnalogOutputDouble64_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    AnalogOutputDouble64* command, uint16_t index);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeaderWithIterator(QualifierCode qualifier,
////                                                             const DNP3Serializer<Target>& serializer,
////                                                             const ICollection<Indexed<Target>>& values,
////                                                             PrefixedWriteIterator<IndexType, Target>* pIterator)
IINField RespondToHeaderWithIterator_for_AnalogOutputDouble64_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputDouble64* serializer,
    ICollection_Indexed_for_AnalogOutputDouble64* values,
    PrefixedWriteIterator_for_UInt8_AnalogOutputDouble64* pIterator);
IINField RespondToHeaderWithIterator_for_AnalogOutputDouble64_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputDouble64* serializer,
    ICollection_Indexed_for_AnalogOutputDouble64* values,
    PrefixedWriteIterator_for_UInt16_AnalogOutputDouble64* pIterator);

////template<class Target, class IndexType>
////IINField CommandResponseHandler::RespondToHeader(QualifierCode qualifier,
////                                                 const DNP3Serializer<Target>& serializer,
////                                                 const ICollection<Indexed<Target>>& values)
IINField  RespondToHeader_for_AnalogOutputDouble64_UInt8_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputDouble64* serializer,
    ICollection_Indexed_for_AnalogOutputDouble64* values);
IINField  RespondToHeader_for_AnalogOutputDouble64_UInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
    QualifierCode_uint8_t qualifier,
    DNP3Serializer_for_AnalogOutputDouble64* serializer,
    ICollection_Indexed_for_AnalogOutputDouble64* values);
//---------------------------------------AnalogOutputDouble64----------------------------------------------------------

////} // namespace opendnp3

#endif
