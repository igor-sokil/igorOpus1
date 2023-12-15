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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "MeasurementHandler.h"

#include "APDUParser.h"
////#include "logging/LogMacros.h"

////namespace opendnp3
////{

////ParseResult MeasurementHandler::ProcessMeasurements(ResponseInfo info,
////                                                    const ser4cpp::rseq_t& objects,
////                                                    Logger& logger,
////                                                    ISOEHandler* pHandler)
ParseResult_uint8_t ProcessMeasurements_in_MeasurementHandler_static(ResponseInfo info,
    RSeq_for_Uint16_t* objects,
////                                           Logger& logger,
    ISOEHandler* pHandler)
{
////    MeasurementHandler handler(info, logger, pHandler);
  MeasurementHandler handler;
  MeasurementHandler_in_MeasurementHandler(&handler, info, pHandler);

//ParseResult_uint8_t Parse_in_APDUParser_static(RSeq_for_Uint16_t *buffer, IAPDUHandler *handler);
////    return APDUParser::Parse(objects, handler, &logger);
  return Parse_in_APDUParser_static(objects, &(handler.iIAPDUHandler));
}

////MeasurementHandler::MeasurementHandler(ResponseInfo info, const Logger& logger, ISOEHandler* pSOEHandler)
////    : info(info),
////      logger(logger),
////      txInitiated(false),
////      pSOEHandler(pSOEHandler),
////      commonTimeOccurence(0, TimestampQuality::INVALID)
////{
////}
void MeasurementHandler_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler, ResponseInfo info, ISOEHandler* pSOEHandler)
{
  pMeasurementHandler->info = info;
  pMeasurementHandler->txInitiated = false;
  pMeasurementHandler->pSOEHandler = pSOEHandler;
  DNPTime_in_DNPTimeOver3(&(pMeasurementHandler->commonTimeOccurence), 0, TimestampQuality_INVALID);
////     commonTimeOccurence(0, TimestampQuality::INVALID)

  (pMeasurementHandler->iIAPDUHandler).iIWhiteList.pIsAllowed_in_IWhiteList = IsAllowed_in_MeasurementHandler_override;

  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_CountHeader_for_Group50Var1_in_IAPDUHandler =
    ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_CountHeader_for_Group51Var1_in_IAPDUHandler =
    ProcessHeader_CountHeader_Indexed_for_Group51Var1_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_CountHeader_for_Group51Var2_in_IAPDUHandler =
    ProcessHeader_CountHeader_Indexed_for_Group51Var2_in_MeasurementHandler_override;

  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_Binary_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_Binary_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_Counter_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_Counter_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_Analog_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_Analog_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_OctetString_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_IAPDUHandler =
    ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler_override;

  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_Binary_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_Counter_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_Counter_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_Analog_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_Analog_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_OctetString_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MeasurementHandler_override;
  (pMeasurementHandler->iIAPDUHandler).pProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_IAPDUHandler =
    ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MeasurementHandler_override;

  setParentPointer_in_IAPDUHandler(&(pMeasurementHandler->iIAPDUHandler), pMeasurementHandler);
  setParentPointer_in_IWhiteList(&(pMeasurementHandler->iIAPDUHandler.iIWhiteList), pMeasurementHandler);
}

boolean IsAllowed_in_MeasurementHandler_override(void *v, uint32_t headerCount, GroupVariation_uint16_t gv, QualifierCode_uint8_t qc)
{
  UNUSED(v);
  UNUSED(headerCount);
  UNUSED(gv);
  UNUSED(qc);
  return true;
}

IINField ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler_override(void* pIAPDUHandler, CountHeader* header, ICollection_for_Group50Var1* values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var1_in_MeasurementHandler_override(void* pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var1* values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_CountHeader_Indexed_for_Group51Var1_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var2_in_MeasurementHandler_override(void* pIAPDUHandler, CountHeader* header, ICollection_for_Group51Var2* values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_CountHeader_Indexed_for_Group51Var2_in_MeasurementHandler(parent, header, values);
}

IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_Binary_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Counter * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_Counter_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_Analog * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_Analog_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_OctetString * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler_override(void* pIAPDUHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler(parent, header, values);
}

IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Binary * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Counter * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_Counter_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_Analog * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_Analog_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MeasurementHandler(parent, header, values);
}
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MeasurementHandler_override(void* pIAPDUHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent * values)
{
  MeasurementHandler *parent = (MeasurementHandler*) getParentPointer_in_IAPDUHandler((IAPDUHandler*) pIAPDUHandler);
  return ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MeasurementHandler(parent, header, values);
}
/*
   IINField ProcessHeader_CountHeader_Indexed_for_Group51Var1_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group51Var1* values);
   IINField ProcessHeader_CountHeader_Indexed_for_Group51Var2_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group51Var2* values);

   IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values);
   IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary * values);
   IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values);
   IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Counter * values);
   IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter * values);
   IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Analog * values);
   IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values);
   IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_OctetString * values);
   IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval * values);

   IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Binary * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Counter * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Analog * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString * values);
   IINField ProcessHeader_PrefixHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_TimeAndInterval * values);
*/
////MeasurementHandler::~MeasurementHandler()
////{
////    if (txInitiated && pSOEHandler)
////    {
////        this->pSOEHandler->EndFragment(this->info);
////    }
////}

////TimestampQuality MeasurementHandler::ModeFromType(GroupVariation gv)
TimestampQuality_uint8_t ModeFromType_in_MeasurementHandler_static(GroupVariation_uint16_t gv)
{
//boolean HasAbsoluteTime(GroupVariation_uint16_t gv);
////    return HasAbsoluteTime(gv) ? TimestampQuality::SYNCHRONIZED : TimestampQuality::INVALID;
  return HasAbsoluteTime(gv) ? TimestampQuality_SYNCHRONIZED : TimestampQuality_INVALID;
}

////void MeasurementHandler::CheckForTxStart()
void CheckForTxStart_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler)
{
  if (!pMeasurementHandler->txInitiated && pMeasurementHandler->pSOEHandler)
  {
    pMeasurementHandler->txInitiated = true;

//void BeginFragment_in_ISOEHandler(ISOEHandler* pISOEHandler, ResponseInfo* info);
////        this->pSOEHandler->BeginFragment(this->info);
    BeginFragment_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &(pMeasurementHandler->info));
  }
}

DNPTime transform_for_Group50Var1_in_MeasurementHandler(Group50Var1* input);
DNPTime transform_for_Group50Var1_in_MeasurementHandler(Group50Var1* input)
{
////    auto transform = [](const Group50Var1& input) -> DNPTime { return input.time; };
  return input->timeDNPTime;
}
////IINField MeasurementHandler::ProcessHeader(const CountHeader& header, const ICollection<Group50Var1>& values)
IINField ProcessHeader_CountHeader_Indexed_for_Group50Var1_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group50Var1* values)
{
////    this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////    auto transform = [](const Group50Var1& input) -> DNPTime { return input.time; };

//TransformedCollection_Group50Var1_for_DNPTime Map_in_Group50Var1_for_DNPTime(ICollection_for_Group50Var1* input, Transform transform);
////    auto collection = Map<Group50Var1, DNPTime>(values, transform);
  TransformedCollection_Group50Var1_for_DNPTime collection = Map_in_TransformedCollection_Group50Var1_for_DNPTime(values, transform_for_Group50Var1_in_MeasurementHandler);

//QualifierCode_uint8_t GetQualifierCode_in_HeaderRecord(HeaderRecord *pHeaderRecord);
//   void HeaderInfo_in_HeaderInfoOver2(HeaderInfo *pHeaderInfo, GroupVariation_uint16_t gv_, QualifierCode_uint8_t qualifier_,
//              TimestampQuality_uint8_t tsquality_, uint32_t headerIndex_);
////    HeaderInfo info(header.enumeration, header.GetQualifierCode(), TimestampQuality::INVALID, header.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, header->hHeaderRecord.gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(&(header->hHeaderRecord)),
                                TimestampQuality_INVALID, header->hHeaderRecord.headerIndex);

//void Process_for_DNPTime_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_for_DNPTime* values);// = 0;
////    this->pSOEHandler->Process(info, collection);
  Process_for_DNPTime_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, &(collection.iICollection_for_DNPTime));

////    return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}

////IINField MeasurementHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group51Var1>& values)
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var1_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group51Var1* values)
{
  UNUSED(header);
  Group51Var1 cto;
  Group51Var1_in_Group51Var1(&cto);

//boolean ReadOnlyValue_in_ICollection_for_Group51Var1(ICollection_for_Group51Var1 *pICollection_for_Group51Var1, Group51Var1* value);
////    if (values.ReadOnlyValue(cto))
  if (ReadOnlyValue_in_ICollection_for_Group51Var1(values, &cto))
  {
////        cto.time.quality = TimestampQuality::SYNCHRONIZED;
    cto.timeDNPTime.quality = TimestampQuality_SYNCHRONIZED;
////        commonTimeOccurence = cto.time;
    pMeasurementHandler->commonTimeOccurence = cto.timeDNPTime;
  }
////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////IINField MeasurementHandler::ProcessHeader(const CountHeader& /*header*/, const ICollection<Group51Var2>& values)
IINField ProcessHeader_CountHeader_Indexed_for_Group51Var2_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, CountHeader* header, ICollection_for_Group51Var2* values)
{
  UNUSED(header);
  Group51Var2 cto;
  Group51Var2_in_Group51Var2(&cto);

////    if (values.ReadOnlyValue(cto))
  if (ReadOnlyValue_in_ICollection_for_Group51Var2(values, &cto))
  {
////        cto.time.quality = TimestampQuality::UNSYNCHRONIZED;
    cto.timeDNPTime.quality = TimestampQuality_UNSYNCHRONIZED;
////        commonTimeOccurence = cto.time;
    pMeasurementHandler->commonTimeOccurence = cto.timeDNPTime;
  }

////    return IINField::Empty();
  return Empty_in_IINField_static();
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Binary>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Binary* values)
{
//   TimestampQuality_uint8_t ModeFromType_in_MeasurementHandler_static(GroupVariation_uint16_t gv)
//  IINField LoadValues_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Binary* values)
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_Binary_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header,
////                                           const ICollection<Indexed<DoubleBitBinary>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_DoubleBitBinary * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_DoubleBitBinary_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header,
////                                           const ICollection<Indexed<BinaryOutputStatus>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_BinaryOutputStatus_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Counter>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Counter * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_Counter_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<FrozenCounter>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_FrozenCounter * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_FrozenCounter_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<Analog>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_Analog * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_Analog_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header,
////                                           const ICollection<Indexed<AnalogOutputStatus>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_AnalogOutputStatus_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header, const ICollection<Indexed<OctetString>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_OctetString * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_OctetString_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const RangeHeader& header,
////                                           const ICollection<Indexed<TimeAndInterval>>& values)
IINField ProcessHeader_RangeHeader_Indexed_for_TimeAndInterval_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, RangeHeader* header, ICollection_Indexed_for_TimeAndInterval * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_TimeAndInterval_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Binary>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Binary * values)
{
  if (header->hHeaderRecord.gGroupVariationRecord.enumeration == GroupVariation_Group2Var3)
  {
//IINField ProcessWithCTO_for_Binary_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler, HeaderRecord* record, ICollection_Indexed_for_Binary* values)
////        return this->ProcessWithCTO(header, values);
    return ProcessWithCTO_for_Binary_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord), values);
  }

////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_Binary_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header,
////                                           const ICollection<Indexed<BinaryOutputStatus>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryOutputStatus * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_BinaryOutputStatus_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header,
////                                           const ICollection<Indexed<DoubleBitBinary>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_DoubleBitBinary * values)
{
////    if (header.enumeration == GroupVariation::Group4Var3)
  if (header->hHeaderRecord.gGroupVariationRecord.enumeration == GroupVariation_Group4Var3)
  {
////        return this->ProcessWithCTO(header, values);
    return ProcessWithCTO_for_DoubleBitBinary_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord), values);
  }

////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_DoubleBitBinary_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Counter>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Counter * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_Counter_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header,
////                                           const ICollection<Indexed<FrozenCounter>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_FrozenCounter * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_FrozenCounter_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<Analog>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_Analog * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_Analog_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header,
////                                           const ICollection<Indexed<AnalogOutputStatus>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogOutputStatus * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_AnalogOutputStatus_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header, const ICollection<Indexed<OctetString>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_OctetString * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_OctetString_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header,
////                                           const ICollection<Indexed<BinaryCommandEvent>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_BinaryCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_BinaryCommandEvent * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_BinaryCommandEvent_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////IINField MeasurementHandler::ProcessHeader(const PrefixHeader& header,
////                                           const ICollection<Indexed<AnalogCommandEvent>>& values)
IINField ProcessHeader_PrefixHeader_Indexed_for_AnalogCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, PrefixHeader* header, ICollection_Indexed_for_AnalogCommandEvent * values)
{
////    return this->LoadValues(header, ModeFromType(header.enumeration), values);
  return LoadValues_for_AnalogCommandEvent_in_MeasurementHandler(pMeasurementHandler, &(header->hHeaderRecord),
         ModeFromType_in_MeasurementHandler_static(header->hHeaderRecord.gGroupVariationRecord.enumeration), values);
}

////} // namespace opendnp3

////    template<class T>
////    IINField LoadValues(const HeaderRecord& record, TimestampQuality tsquality, const ICollection<Indexed<T>>& values)
//--------------------------------Binary----------------------------
IINField LoadValues_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Binary* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_Binary_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Binary* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_Binary_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------Binary----------------------------
//--------------------------------DoubleBitBinary----------------------------
IINField LoadValues_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_DoubleBitBinary* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_DoubleBitBinary_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_DoubleBitBinary* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_DoubleBitBinary_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------DoubleBitBinary----------------------------
//--------------------------------BinaryOutputStatus----------------------------
IINField LoadValues_for_BinaryOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_BinaryOutputStatus* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_BinaryOutputStatus_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryOutputStatus* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_BinaryOutputStatus_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------BinaryOutputStatus----------------------------
//--------------------------------Counter----------------------------
IINField LoadValues_for_Counter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Counter* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_Counter_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Counter* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_Counter_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------Counter----------------------------
//--------------------------------FrozenCounter----------------------------
IINField LoadValues_for_FrozenCounter_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_FrozenCounter* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_FrozenCounter_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_FrozenCounter* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_FrozenCounter_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------FrozenCounter----------------------------
//--------------------------------Analog----------------------------
IINField LoadValues_for_Analog_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Analog* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_Analog_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_Analog* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_Analog_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------Analog----------------------------
//--------------------------------AnalogOutpuStatus----------------------------
IINField LoadValues_for_AnalogOutputStatus_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_AnalogOutputStatus* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_AnalogOutpuStatus_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogOutpuStatus* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_AnalogOutputStatus_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------AnalogOutpuStatus----------------------------
//--------------------------------OctetString----------------------------
IINField LoadValues_for_OctetString_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_OctetString* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_OctetString_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_OctetString* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_OctetString_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------OctetString----------------------------
//--------------------------------BinaryCommandEvent----------------------------
IINField LoadValues_for_BinaryCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_BinaryCommandEvent* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_BinaryCommandEvent_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_BinaryCommanEvent* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_BinaryCommandEvent_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------BinaryCommandEvent----------------------------
//--------------------------------AnalogCommandEvent----------------------------
IINField LoadValues_for_AnalogCommandEvent_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_AnalogCommandEvent* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_AnalogCommanEvent_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_AnalogCommanEvent* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_AnalogCommandEvent_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------AnalogCommandEvent----------------------------
//--------------------------------TimeAndInterval----------------------------
IINField LoadValues_for_TimeAndInterval_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler,
    HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_TimeAndInterval* values)
{
////        this->CheckForTxStart();
  CheckForTxStart_in_MeasurementHandler(pMeasurementHandler);

////        HeaderInfo info(record.enumeration, record.GetQualifierCode(), tsquality, record.headerIndex);
  HeaderInfo info;
  HeaderInfo_in_HeaderInfoOver2(&info, record->gGroupVariationRecord.enumeration,
                                GetQualifierCode_in_HeaderRecord(record),
                                tsquality, record->headerIndex);

//void Process_Indexed_for_TimeAndInterval_in_ISOEHandler(ISOEHandler* pISOEHandler, HeaderInfo* info, ICollection_Indexed_for_TimeAndInterval* values);
////        this->pSOEHandler->Process(info, values);
  Process_Indexed_for_TimeAndInterval_in_ISOEHandler(pMeasurementHandler->pSOEHandler, &info, values);

////        return IINField();
  IINField iIINField;
  IINField_in_IINFieldOver1(&iIINField);
  return iIINField;
}
//--------------------------------TimeAndInterval----------------------------
//--------------------------------Binary----------------------------
Indexed_for_Binary transform_Indexed_for_Binary_in_MeasurementHandler(Indexed_for_Binary *input);
Indexed_for_Binary transform_Indexed_for_Binary_in_MeasurementHandler(Indexed_for_Binary *input)
{
  DNPTime* cto = (DNPTime*)pPointerGlobal1;
////    auto transform = [cto](const Indexed<T>& input) -> Indexed<T> {
////        Indexed<T> copy(input);
////        copy.value.time = DNPTime(input.value.time.value + cto.value, cto.quality);
////        return copy;
////    };
  Indexed_for_Binary copy = *input;
////        copy.value.time = DNPTime(input.value.time.value + cto.value, cto.quality);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver3(&dDNPTime, input->value.tTypedMeasurement_for_Boolean.mMeasurement.timeDNPTime.value + cto->value, cto->quality);
  copy.value.tTypedMeasurement_for_Boolean.mMeasurement.timeDNPTime = dDNPTime;
  return copy;
}
////template<class T>
////IINField MeasurementHandler::ProcessWithCTO(const HeaderRecord& record, const ICollection<Indexed<T>>& values)
IINField ProcessWithCTO_for_Binary_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler, HeaderRecord* record, ICollection_Indexed_for_Binary* values)
{
  if (pMeasurementHandler->commonTimeOccurence.quality == TimestampQuality_INVALID)
  {
////        FORMAT_LOG_BLOCK(logger, flags::WARN, "No prior CTO objects for %s",
////                         GroupVariationSpec::to_string(record.enumeration));
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::WARN, 'No prior CTO objects for %s',"<<'\n';
    decrement_stack_info();
#endif
////        return IINField(IINBit::PARAM_ERROR);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

////    const auto cto = this->commonTimeOccurence;
  DNPTime cto = pMeasurementHandler->commonTimeOccurence;

////    auto transform = [cto](const Indexed<T>& input) -> Indexed<T> {
////        Indexed<T> copy(input);
////        copy.value.time = DNPTime(input.value.time.value + cto.value, cto.quality);
////        return copy;
////    };

  pPointerGlobal1 = &cto;
//TransformedCollection_Indexed_for_Binary Map_in_TransformedCollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* input, Transform_Indexed_for_Binary transform);
////    auto adjusted = Map<Indexed<T>, Indexed<T>>(values, transform);
  TransformedCollection_Indexed_for_Binary adjusted = Map_in_TransformedCollection_Indexed_for_Binary(values, transform_Indexed_for_Binary_in_MeasurementHandler);

//  IINField LoadValues_for_Binary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_Binary* values);
////    return this->LoadValues(record, cto.quality, adjusted);
  return LoadValues_for_Binary_in_MeasurementHandler(pMeasurementHandler, record, cto.quality, &(adjusted.iICollection_Indexed_for_Binary));
}
//--------------------------------Binary----------------------------
//--------------------------------DoubleBitBinary----------------------------
Indexed_for_DoubleBitBinary transform_Indexed_for_DoubleBitBinary_in_MeasurementHandler(Indexed_for_DoubleBitBinary *input);
Indexed_for_DoubleBitBinary transform_Indexed_for_DoubleBitBinary_in_MeasurementHandler(Indexed_for_DoubleBitBinary *input)
{
  DNPTime* cto = (DNPTime*)pPointerGlobal1;
////    auto transform = [cto](const Indexed<T>& input) -> Indexed<T> {
////        Indexed<T> copy(input);
////        copy.value.time = DNPTime(input.value.time.value + cto.value, cto.quality);
////        return copy;
////    };
  Indexed_for_DoubleBitBinary copy = *input;
////        copy.value.time = DNPTime(input.value.time.value + cto.value, cto.quality);
  DNPTime dDNPTime;
  DNPTime_in_DNPTimeOver3(&dDNPTime, input->value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime.value + cto->value, cto->quality);
  copy.value.tTypedMeasurement_for_DoubleBit_uint8_t.mMeasurement.timeDNPTime = dDNPTime;
  return copy;
}
////template<class T>
////IINField MeasurementHandler::ProcessWithCTO(const HeaderRecord& record, const ICollection<Indexed<T>>& values)
IINField ProcessWithCTO_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler *pMeasurementHandler, HeaderRecord* record, ICollection_Indexed_for_DoubleBitBinary* values)
{
  if (pMeasurementHandler->commonTimeOccurence.quality == TimestampQuality_INVALID)
  {
////        FORMAT_LOG_BLOCK(logger, flags::WARN, "No prior CTO objects for %s",
////                         GroupVariationSpec::to_string(record.enumeration));
#ifdef  LOG_INFO
    increment_stack_info();
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FORMAT_LOG_BLOCK(logger, flags::WARN, 'No prior CTO objects for %s',"<<'\n';
    decrement_stack_info();
#endif
////        return IINField(IINBit::PARAM_ERROR);
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_PARAM_ERROR);
    return iIINField;
  }

////    const auto cto = this->commonTimeOccurence;
  DNPTime cto = pMeasurementHandler->commonTimeOccurence;

////    auto transform = [cto](const Indexed<T>& input) -> Indexed<T> {
////        Indexed<T> copy(input);
////        copy.value.time = DNPTime(input.value.time.value + cto.value, cto.quality);
////        return copy;
////    };

  pPointerGlobal1 = &cto;
//TransformedCollection_Indexed_for_DoubleBitBinary Map_in_TransformedCollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* input, Transform_Indexed_for_DoubleBitBinary transform);
////    auto adjusted = Map<Indexed<T>, Indexed<T>>(values, transform);
  TransformedCollection_Indexed_for_DoubleBitBinary adjusted = Map_in_TransformedCollection_Indexed_for_DoubleBitBinary(values, transform_Indexed_for_DoubleBitBinary_in_MeasurementHandler);

//  IINField LoadValues_for_DoubleBitBinary_in_MeasurementHandler(MeasurementHandler* pMeasurementHandler, HeaderRecord* record, TimestampQuality_uint8_t tsquality, ICollection_Indexed_for_DoubleBitBinary* values);
////    return this->LoadValues(record, cto.quality, adjusted);
  return LoadValues_for_DoubleBitBinary_in_MeasurementHandler(pMeasurementHandler, record, cto.quality, &(adjusted.iICollection_Indexed_for_DoubleBitBinary));
}
//--------------------------------DoubleBitBinary----------------------------
