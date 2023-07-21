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
#include "CommandResponseHandler.h"

#include "Group12.h"
#include "Group41.h"
#include <string.h>

extern void* pPointerGlobal1;
extern void* pPointerGlobal2;
extern void* pPointerGlobal3;

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

   void CommandResponseHandler_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, uint32_t maxCommands_, ICommandAction* pCommandAction_, HeaderWriter* pWriter_)
{
  pCommandResponseHandler->pCommandAction = pCommandAction_;
  pCommandResponseHandler->numRequests = 0;
  pCommandResponseHandler->numSuccess = 0;
  pCommandResponseHandler->maxCommands = maxCommands_;
  pCommandResponseHandler->pWriter = pWriter_;
/*
  (pCommandResponseHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_CommandResponseHandler_override;
  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_CommandResponseHandler_override;
  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_CommandResponseHandler_override;
  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_CommandResponseHandler_override;
  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_CommandResponseHandler_override;
  (pCommandResponseHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_CommandResponseHandler_override;
*/
  setParentPointer_in_IWhiteList(&((pCommandResponseHandler->iIAPDUHandler).iIWhiteList), pCommandResponseHandler);
  setParentPointer_in_IAPDUHandler(&(pCommandResponseHandler->iIAPDUHandler), pCommandResponseHandler);
}

boolean IsAllowed_in_CommandResponseHandler_override(void *v, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
UNUSED(v);
UNUSED(headerCount);
    if (!(qc == QualifierCode_UINT8_CNT_UINT8_INDEX || qc == QualifierCode_UINT16_CNT_UINT16_INDEX))
    {
        return false;
    }

    switch (gv)
    {
    case (GroupVariation_Group12Var1): //	CROB
    case (GroupVariation_Group41Var1): //	4 kinds of AO
    case (GroupVariation_Group41Var2):
    case (GroupVariation_Group41Var3):
    case (GroupVariation_Group41Var4):
        return true;
    default:
        return false;
    }
}
/*
IINField ProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_ControlRelayOutputBlock* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    template<class T> IINField ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas);
//     IINField ProcessAny_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
//                                       HeaderRecord* record, ICollection_Indexed_for_ControlRelayOutputBlock* meas);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_ControlRelayOutputBlock_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}
*/
////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputInt16>>& meas)
/*
IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputInt16* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}
*/
////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputInt32>>& meas)
/*
IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputInt32* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputInt32_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}
*/
////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputFloat32>>& meas)
/*
IINField ProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputFloat32* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputFloat32_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}
*/
////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputDouble64>>& meas)
/*
IINField ProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputDouble64* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputDouble64_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}
*/
////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<ControlRelayOutputBlock>>& meas)
/*
    IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                           HeaderRecord* record,
                                       ICollection_Indexed_for_ControlRelayOutputBlock* meas)
{
UNUSED(record);
// IINField  RespondToHeader_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                                                      QualifierCode_uint8_t qualifier,
//                                                     DNP3Serializer_for_ControlRelayOutputBlock* serializer,
//                                                     ICollection_Indexed_for_ControlRelayOutputBlock* values
//                                                      );
//DNP3Serializer_for_ControlRelayOutputBlock  Inst_in_Group12Var1_static(void);
////    return this->RespondToHeader<ControlRelayOutputBlock, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                           Group12Var1::Inst(), meas);
DNP3Serializer_for_ControlRelayOutputBlock temp = Inst_in_Group12Var1_static();
 return  RespondToHeader_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler(pCommandResponseHandler,
                                                     QualifierCode_UINT16_CNT_UINT16_INDEX,
                                                     &temp,
                                                     meas
                                                      );
}
*/
////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
///                                                           const ICollection<Indexed<AnalogOutputInt16>>& meas)
////    IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
////                                           HeaderRecord* record,
////                                       ICollection_Indexed_for_ControlRelayOutputBlock* meas)
////{
////    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                     Group41Var2::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputInt32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputInt32, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                     Group41Var1::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputFloat32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputFloat32, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                       Group41Var3::Inst(), meas);
///}

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputDouble64>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputDouble64, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                        Group41Var4::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<ControlRelayOutputBlock>>& meas)
////{
////    return this->RespondToHeader<ControlRelayOutputBlock, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                          Group12Var1::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputInt16>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                    Group41Var2::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputInt32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputInt32, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                    Group41Var1::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputFloat32>>& meas)
////{
////    return this->RespondToHeader<AnalogOutputFloat32, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                      Group41Var3::Inst(), meas);
////}

////IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<AnalogOutputDouble64>>& meas)
///{
////    return this->RespondToHeader<AnalogOutputDouble64, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
////                                                                       Group41Var4::Inst(), meas);
////}

////} // namespace opendnp3
    boolean AllCommandsSuccessful_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler)
    {
        return pCommandResponseHandler->numRequests == pCommandResponseHandler->numSuccess;
    }

//----------------------------------------------------ControlRelayOutputBlock------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
/*
     IINField ProcessAny_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_ControlRelayOutputBlock* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(record) == QualifierCode_UINT8_CNT_UINT8_INDEX)
    {
//    IINField ProcessIndexPrefixOneByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
//                                            HeaderRecord* record,
//                                        ICollection_Indexed_for_ControlRelayOutputBlock* meas);
////        return ProcessIndexPrefixOneByte(record, meas);
           return ProcessIndexPrefixOneByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
    else
    {
////        return ProcessIndexPrefixTwoByte(record, meas);
           return ProcessIndexPrefixTwoByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
}
*/
//----------------------------------------------------ControlRelayOutputBlock------------------------------------------------------------
//----------------------------------------------------AnalogOutputInt16------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
/*
     IINField ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt16* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(record) == QualifierCode_UINT8_CNT_UINT8_INDEX)
    {
//    IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
//                                            HeaderRecord* record,
//                                        ICollection_Indexed_for_AnalogOutputInt16* meas);
////        return ProcessIndexPrefixOneByte(record, meas);
           return ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
    else
    {
////        return ProcessIndexPrefixTwoByte(record, meas);
           return ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputInt16_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
}
*/
//----------------------------------------------------AnalogOutputInt16------------------------------------------------------------
//----------------------------------------------------AnalogOutputInt32------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
/*
     IINField ProcessAny_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt32* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(record) == QualifierCode_UINT8_CNT_UINT8_INDEX)
    {
//    IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
//                                            HeaderRecord* record,
//                                        ICollection_Indexed_for_AnalogOutputInt32* meas);
////        return ProcessIndexPrefixOneByte(record, meas);
           return ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputInt32_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
    else
    {
////        return ProcessIndexPrefixTwoByte(record, meas);
           return ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputInt32_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
}
*/
//----------------------------------------------------AnalogOutputInt32------------------------------------------------------------
//----------------------------------------------------AnalogOutputFloat32------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
/*
     IINField ProcessAny_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputFloat32* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(record) == QualifierCode_UINT8_CNT_UINT8_INDEX)
    {
//    IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
//                                            HeaderRecord* record,
//                                        ICollection_Indexed_for_AnalogOutputFloat32* meas);
////        return ProcessIndexPrefixOneByte(record, meas);
           return ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputFloat32_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
    else
    {
////        return ProcessIndexPrefixTwoByte(record, meas);
           return ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputFloat32_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
}
*/
//----------------------------------------------------AnalogOutputFloat32------------------------------------------------------------
//----------------------------------------------------AnalogOutputDouble64------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
/*
     IINField ProcessAny_for_AnalogOutputDouble64_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputDouble64* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(record) == QualifierCode_UINT8_CNT_UINT8_INDEX)
    {
//    IINField ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputDouble64_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
//                                            HeaderRecord* record,
//                                        ICollection_Indexed_for_AnalogOutputDouble64* meas);
////        return ProcessIndexPrefixOneByte(record, meas);
           return ProcessIndexPrefixOneByte_HeaderRecord_for_AnalogOutputDouble64_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
    else
    {
////        return ProcessIndexPrefixTwoByte(record, meas);
           return ProcessIndexPrefixTwoByte_HeaderRecord_for_AnalogOutputDouble64_in_CommandResponseHandler(pCommandResponseHandler, 
                                             record, meas);
    }
}
*/
//----------------------------------------------------AnalogOutputDouble64------------------------------------------------------------

//---------------------------------------ControlRelayOutputBlock----------------------------------------------------------

  void process_for_ControlRelayOutputBlock_in_CommandResponseHandler(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, 
                                            Indexed_for_ControlRelayOutputBlock* pair)
{
 CommandResponseHandler* pCommandResponseHandler = (CommandResponseHandler*)pPointerGlobal1;//CommandResponseHandler*
 PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock * pIterator = 
       (PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock*)pPointerGlobal2;//PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock*
 IINField* ret = (IINField*) pPointerGlobal3;//IINField*

////        Target response(pair.value);
    ControlRelayOutputBlock response;
    response = pair->value;

// CommandStatus_uint8_t ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                               ControlRelayOutputBlock* command, uint16_t index)
//    CommandStatus_uint8_t status;
////        response.status = this->ProcessCommand(pair.value, pair.index);
response.status = ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler(pCommandResponseHandler,
                               &(pair->value), pair->index);


        switch (response.status)
        {
        case (CommandStatus_SUCCESS):
            ++(pCommandResponseHandler->numSuccess);
            break;
        case (CommandStatus_NOT_SUPPORTED):
//    void SetBit_in_IINField(IINField *, IINBit_uint8_t bit);
////            ret.SetBit(IINBit::PARAM_ERROR);
    SetBit_in_IINField(ret, IINBit_PARAM_ERROR);
            break;
        default:
            break;
        }

        if (pIterator)
        {
//    boolean Write_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock(PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock *pPrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock,
//                                                                  ControlRelayOutputBlock* value, uint16_t index);
////            pIterator->Write(response, static_cast<typename IndexType::type_t>(pair.index));
     Write_in_PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock(pIterator,
                                                                  &response, pair->index);
        }
}

IINField RespondToHeaderWithIterator_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
                                         QualifierCode_uint8_t qualifier,
                                         DNP3Serializer_for_ControlRelayOutputBlock* serializer,
                                         ICollection_Indexed_for_ControlRelayOutputBlock* values,
                                         PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock* pIterator
                                        )
{
UNUSED(qualifier);
UNUSED(serializer);
UNUSED(values);

    IINField ret;
    IINField_in_IINFieldOver1(&ret);

 pPointerGlobal1 = pCommandResponseHandler;//CommandResponseHandler*
 pPointerGlobal2 = pIterator;//PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock*
 pPointerGlobal3 = &ret;//IINField*

////
////    auto process = [this, pIterator, &ret](const Indexed<Target>& pair) {
////        Target response(pair.value);
////        response.status = this->ProcessCommand(pair.value, pair.index);
////
////        switch (response.status)
////        {
////        case (CommandStatus::SUCCESS):
////            ++this->numSuccess;
////            break;
////        case (CommandStatus::NOT_SUPPORTED):
////            ret.SetBit(IINBit::PARAM_ERROR);
////            break;
////        default:
////            break;
////        }
////
////        if (pIterator)
////        {
////            pIterator->Write(response, static_cast<typename IndexType::type_t>(pair.index));
////        }
////    };
////
//void ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(
//        ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, 
//        void (*fun)(ICollection_Indexed_for_ControlRelayOutputBlock *pICollection_Indexed_for_ControlRelayOutputBlock, Indexed_for_ControlRelayOutputBlock* item));

////    values.ForeachItem(process);
 ForeachItem_in_ICollection_Indexed_for_ControlRelayOutputBlock(values,
                            process_for_ControlRelayOutputBlock_in_CommandResponseHandler);

    return ret;
}

 CommandStatus_uint8_t ProcessCommand_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
                               ControlRelayOutputBlock* command, uint16_t index)
{
    if (pCommandResponseHandler->numRequests < pCommandResponseHandler->maxCommands)
    {
        ++(pCommandResponseHandler->numRequests);
//CommandStatus_uint8_t Action_ControlRelayOutputBlock_in_ICommandAction(ICommandAction *, ControlRelayOutputBlock* arCommand, uint16_t aIndex);
////        return pCommandAction->Action(command, index);
return Action_ControlRelayOutputBlock_in_ICommandAction(pCommandResponseHandler->pCommandAction, command, index);
    }
    else
    {
        return CommandStatus_TOO_MANY_OPS;
    }
}

 IINField  RespondToHeader_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
                                                      QualifierCode_uint8_t qualifier,
                                                     DNP3Serializer_for_ControlRelayOutputBlock* serializer,
                                                     ICollection_Indexed_for_ControlRelayOutputBlock* values
                                                      )
{
    if (pCommandResponseHandler->pWriter)
    {
//  PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock IterateOverCountWithPrefix_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(HeaderWriter *pHeaderWriter,
//    QualifierCode_uint8_t qc, DNP3Serializer_for_ControlRelayOutputBlock* serializer);
////        auto iter = pWriter->IterateOverCountWithPrefix<IndexType, Target>(qualifier, serializer);
        PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock iter = IterateOverCountWithPrefix_for_UInt16_ControlRelayOutputBlock_in_HeaderWriter(
                                          pCommandResponseHandler->pWriter,
                                          qualifier, serializer);
//IINField RespondToHeaderWithIterator_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler,
//                                         QualifierCode_uint8_t qualifier,
//                                         DNP3Serializer_for_ControlRelayOutputBlock* serializer,
//                                         ICollection_Indexed_for_ControlRelayOutputBlock* values,
//                                         PrefixedWriteIterator_for_UInt16_ControlRelayOutputBlock* pIterator
//                                        );
////        return this->RespondToHeaderWithIterator<Target, IndexType>(qualifier, serializer, values, &iter);
return RespondToHeaderWithIterator_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler(pCommandResponseHandler,
                                          qualifier,
                                          serializer,
                                          values,
                                          &iter
                                        );
    }
    else
    {
////        return this->RespondToHeaderWithIterator<Target, IndexType>(qualifier, serializer, values);

return RespondToHeaderWithIterator_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler(pCommandResponseHandler,
                                          qualifier,
                                          serializer,
                                          values,
                                          NULL
                                        );
    }
}

//---------------------------------------ControlRelayOutputBlock----------------------------------------------------------
