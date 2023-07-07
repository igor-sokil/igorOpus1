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
#include "CommandResponseHandler.h"

#include "gen/objects/Group12.h"
#include "gen/objects/Group41.h"

#include <ser4cpp/serialization/LittleEndian.h>

namespace opendnp3
{

   void CommandResponseHandler_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, uint32_t maxCommands_, ICommandAction* pCommandAction_, HeaderWriter* pWriter_)
{
  pCommandResponseHandler->pCommandAction = pCommandAction_;
  pCommandResponseHandler->numRequests = 0;
  pCommandResponseHandler->numSuccess = 0;
  pCommandResponseHandler->maxCommands = maxCommands_;
  pCommandResponseHandler->pWriter = pWriter_;

  (pReadHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_CommandResponseHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_ControlRelayOutputBlock_in_CommandResponseHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_CommandResponseHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_CommandResponseHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_CommandResponseHandler_override;
  (pReadHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_IAPDUHandler = 
                                 ProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_CommandResponseHandler_override;

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

////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputInt16>>& meas)
IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt16_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputInt16* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}

////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputInt32>>& meas)
IINField ProcessHeader_PrefixHeader_for_AnalogOutputInt32_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputInt32* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputInt32_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}

////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputFloat32>>& meas)
IINField ProcessHeader_PrefixHeader_for_AnalogOutputFloat32_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputFloat32* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputFloat32_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}

////IINField CommandResponseHandler::ProcessHeader(const PrefixHeader& header,
////                                               const ICollection<Indexed<AnalogOutputDouble64>>& meas)
IINField ProcessHeader_PrefixHeader_for_AnalogOutputDouble64_in_CommandResponseHandler_override(void *pIAPDUHandler, 
                                               PrefixHeader* header,
                                               ICollection_Indexed_for_AnalogOutputDouble64* meas)
{
  CommandResponseHandler *parent =
    (CommandResponseHandler*)getParentPointer_in_IAPDUHandler((IAPDUHandler*)pIAPDUHandler);
////    return this->ProcessAny(header, meas);
     return ProcessAny_for_AnalogOutputDouble64_in_CommandResponseHandler(parent, &(header->hHeaderRecord), meas);
}

////IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
////                                                           const ICollection<Indexed<ControlRelayOutputBlock>>& meas)
    IINField ProcessIndexPrefixTwoByte_HeaderRecord_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                           HeaderRecord* record,
                                       ICollection_Indexed_for_ControlRelayOutputBlock* meas)
{
UNUSED(record);
// IINField  RespondToHeader_for_ControlRelayOutputBlock_uint16_in_CommandResponseHandler();
////    return this->RespondToHeader<ControlRelayOutputBlock, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
////                                                                           Group12Var1::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputInt16>>& meas)
{
    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
                                                                     Group41Var2::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputInt32>>& meas)
{
    return this->RespondToHeader<AnalogOutputInt32, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
                                                                     Group41Var1::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputFloat32>>& meas)
{
    return this->RespondToHeader<AnalogOutputFloat32, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
                                                                       Group41Var3::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixTwoByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputDouble64>>& meas)
{
    return this->RespondToHeader<AnalogOutputDouble64, ser4cpp::UInt16>(QualifierCode::UINT16_CNT_UINT16_INDEX,
                                                                        Group41Var4::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<ControlRelayOutputBlock>>& meas)
{
    return this->RespondToHeader<ControlRelayOutputBlock, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
                                                                          Group12Var1::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputInt16>>& meas)
{
    return this->RespondToHeader<AnalogOutputInt16, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
                                                                    Group41Var2::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputInt32>>& meas)
{
    return this->RespondToHeader<AnalogOutputInt32, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
                                                                    Group41Var1::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputFloat32>>& meas)
{
    return this->RespondToHeader<AnalogOutputFloat32, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
                                                                      Group41Var3::Inst(), meas);
}

IINField CommandResponseHandler::ProcessIndexPrefixOneByte(const HeaderRecord& /*unused*/,
                                                           const ICollection<Indexed<AnalogOutputDouble64>>& meas)
{
    return this->RespondToHeader<AnalogOutputDouble64, ser4cpp::UInt8>(QualifierCode::UINT8_CNT_UINT8_INDEX,
                                                                       Group41Var4::Inst(), meas);
}

////} // namespace opendnp3
    boolean AllCommandsSuccessful_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler)
    {
        return pCommandResponseHandler->numRequests == pCommandResponseHandler->numSuccess;
    }

//----------------------------------------------------ControlRelayOutputBlock------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
     IINField ProcessAny_for_ControlRelayOutputBlock_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_ControlRelayOutputBlock* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(pCommandResponseHandler) == QualifierCode_UINT8_CNT_UINT8_INDEX)
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
//----------------------------------------------------ControlRelayOutputBlock------------------------------------------------------------
//----------------------------------------------------AnalogOutputInt16------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
     IINField ProcessAny_for_AnalogOutputInt16_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt16* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(pCommandResponseHandler) == QualifierCode_UINT8_CNT_UINT8_INDEX)
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
//----------------------------------------------------AnalogOutputInt16------------------------------------------------------------
//----------------------------------------------------AnalogOutputInt32------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
     IINField ProcessAny_for_AnalogOutputInt32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputInt32* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(pCommandResponseHandler) == QualifierCode_UINT8_CNT_UINT8_INDEX)
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
//----------------------------------------------------AnalogOutputInt32------------------------------------------------------------
//----------------------------------------------------AnalogOutputFloat32------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
     IINField ProcessAny_for_AnalogOutputFloat32_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputFloat32* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(pCommandResponseHandler) == QualifierCode_UINT8_CNT_UINT8_INDEX)
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
//----------------------------------------------------AnalogOutputFloat32------------------------------------------------------------
//----------------------------------------------------AnalogOutputDouble64------------------------------------------------------------
////template<class T>
////IINField CommandResponseHandler::ProcessAny(const HeaderRecord& record, const ICollection<Indexed<T>>& meas)
     IINField ProcessAny_for_AnalogOutputDouble64_in_CommandResponseHandler(CommandResponseHandler *pCommandResponseHandler, 
                                               HeaderRecord* record, ICollection_Indexed_for_AnalogOutputDouble64* meas)
{
//   QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
////    if (record.GetQualifierCode() == QualifierCode::UINT8_CNT_UINT8_INDEX)
    if (GetQualifierCode_in_HeaderRecord(pCommandResponseHandler) == QualifierCode_UINT8_CNT_UINT8_INDEX)
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
//----------------------------------------------------AnalogOutputDouble64------------------------------------------------------------
