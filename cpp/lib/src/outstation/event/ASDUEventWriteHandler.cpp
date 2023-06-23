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
#include "ASDUEventWriteHandler.h"

#include "EventWriters_for_Analog.h"
#include "EventWriters_for_AnalogOutputStatus.h"
#include "EventWriters_for_Binary.h"
#include "EventWriters_for_BinaryOutputStatus.h"
#include "EventWriters_for_DoubleBitBinary.h"
#include "EventWriters_for_Counter.h"
#include "EventWriters_for_FrozenCounter.h"
#include "Group2.h"
#include "Group4.h"
#include "Group11.h"
#include "Group22.h"
#include "Group23.h"
#include "Group32.h"
#include "Group42.h"

////namespace opendnp3
////{
uint16_t Write_for_Binary_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventBinaryVariation_uint8_t variation,
    Binary* first,
    IEventCollection_for_Binary* items)
{
  switch (variation)
  {
  case (EventBinaryVariation_Group2Var1):
    {
//uint16_t Write_for_Binary_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_Binary* items, DNP3Serializer_for_Binary* serializer);
 DNP3Serializer_for_Binary temp = Inst_in_Group2Var1_static();
    return Write_for_Binary_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
    }
  case (EventBinaryVariation_Group2Var2):
    {
//uint16_t Write_for_Binary_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_Binary* items, DNP3Serializer_for_Binary* serializer);
 DNP3Serializer_for_Binary temp = Inst_in_Group2Var2_static();
    return Write_for_Binary_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventBinaryVariation_Group2Var3):
    {
//uint16_t Write_for_Binary_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_Binary* items, DNP3Serializer_for_Binary* serializer);
 DNP3Serializer_for_Binary temp = Inst_in_Group2Var3_static();
    return WriteWithCTO_for_Binary_in_EventWriters_static(&((first->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime), &(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
    }
  default:
    {
//uint16_t Write_for_Binary_in_EventWriters_static(HeaderWriter* writer, IEventCollection_for_Binary* items, DNP3Serializer_for_Binary* serializer);
 DNP3Serializer_for_Binary temp = Inst_in_Group2Var1_static();
    return Write_for_Binary_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
    }
  }
}

uint16_t Write_for_DoubleBitBinary_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventDoubleBinaryVariation variation,
    DoubleBitBinary* first,
    IEventCollection_for_DoubleBitBinary* items)
{
  switch (variation)
  {
  case (EventDoubleBinaryVariation_Group4Var1):
    {
DNP3Serializer_for_DoubleBitBinary temp = Inst_in_Group4Var1_static();
    return Write_for_DoubleBitBinary_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventDoubleBinaryVariation_Group4Var2):
    {
DNP3Serializer_for_DoubleBitBinary temp = Inst_in_Group4Var2_static();
    return Write_for_DoubleBitBinary_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventDoubleBinaryVariation_Group4Var3):
    {
DNP3Serializer_for_DoubleBitBinary temp = Inst_in_Group4Var3_static();
    return WriteWithCTO_for_DoubleBitBinary_in_EventWriters_static(&((first->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.timeDNPTime), &(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  default:
    {
DNP3Serializer_for_DoubleBitBinary temp = Inst_in_Group4Var1_static();
    return Write_for_DoubleBitBinary_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  }
}

uint16_t Write_for_Counter_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventCounterVariation variation,
    Counter* first,
    IEventCollection_for_Counter* items)
{
  UNUSED(first);
  switch (variation)
  {
  case (EventCounterVariation_Group22Var1):
    {
DNP3Serializer_for_Counter temp = Inst_in_Group22Var1_static();
    return Write_for_Counter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventCounterVariation_Group22Var2):
    {
DNP3Serializer_for_Counter temp = Inst_in_Group22Var2_static();
    return Write_for_Counter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventCounterVariation_Group22Var5):
    {
DNP3Serializer_for_Counter temp = Inst_in_Group22Var5_static();
    return Write_for_Counter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventCounterVariation_Group22Var6):
    {
DNP3Serializer_for_Counter temp = Inst_in_Group22Var6_static();
    return Write_for_Counter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  default:
    {
DNP3Serializer_for_Counter temp = Inst_in_Group22Var1_static();
    return Write_for_Counter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  }
}

uint16_t Write_for_FrozenCounter_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventFrozenCounterVariation variation,
    FrozenCounter* first,
    IEventCollection_for_FrozenCounter* items)
{
  UNUSED(first);
  switch (variation)
  {
  case (EventFrozenCounterVariation_Group23Var1):
    {
DNP3Serializer_for_FrozenCounter temp = Inst_in_Group23Var1_static();
    return Write_for_FrozenCounter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventFrozenCounterVariation_Group23Var2):
    {
DNP3Serializer_for_FrozenCounter temp = Inst_in_Group23Var2_static();
    return Write_for_FrozenCounter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventFrozenCounterVariation_Group23Var5):
    {
DNP3Serializer_for_FrozenCounter temp = Inst_in_Group23Var5_static();
    return Write_for_FrozenCounter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventFrozenCounterVariation_Group23Var6):
    {
DNP3Serializer_for_FrozenCounter temp = Inst_in_Group23Var6_static();
    return Write_for_FrozenCounter_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  default:
    return 0;
  }
}

uint16_t Write_for_Analog_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventAnalogVariation variation,
    Analog* first,
    IEventCollection_for_Analog* items)
{
  UNUSED(first);
  switch (variation)
  {
  case (EventAnalogVariation_Group32Var1):
{
DNP3Serializer_for_Analog temp = Inst_in_Group32Var1_static();
    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogVariation_Group32Var2):
{
DNP3Serializer_for_Analog temp = Inst_in_Group32Var2_static();
    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogVariation_Group32Var3):
{
DNP3Serializer_for_Analog temp = Inst_in_Group32Var3_static();
    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogVariation_Group32Var4):
{
DNP3Serializer_for_Analog temp = Inst_in_Group32Var4_static();
    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogVariation_Group32Var5):
{
DNP3Serializer_for_Analog temp = Inst_in_Group32Var5_static();
    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
//  case (EventAnalogVariation_Group32Var6):
//    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, Inst_in_Group32Var6_static());
  case (EventAnalogVariation_Group32Var7):
{
DNP3Serializer_for_Analog temp = Inst_in_Group32Var7_static();
    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
//  case (EventAnalogVariation_Group32Var8):
//    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, Inst_in_Group32Var8_static());
  default:
{
DNP3Serializer_for_Analog temp = Inst_in_Group32Var1_static();
    return Write_for_Analog_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  }
}

uint16_t Write_for_BinaryOutputStatus_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventBinaryOutputStatusVariation variation,
    BinaryOutputStatus* first,
    IEventCollection_for_BinaryOutputStatus* items)
{
  UNUSED(first);
  switch (variation)
  {
  case (EventBinaryOutputStatusVariation_Group11Var1):
{
DNP3Serializer_for_BinaryOutputStatus temp = Inst_in_Group11Var1_static();
    return Write_for_BinaryOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventBinaryOutputStatusVariation_Group11Var2):
{
DNP3Serializer_for_BinaryOutputStatus temp = Inst_in_Group11Var2_static();
    return Write_for_BinaryOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  default:
{
DNP3Serializer_for_BinaryOutputStatus temp = Inst_in_Group11Var1_static();
    return Write_for_BinaryOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  }
}

uint16_t Write_for_AnalogOutputStatus_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventAnalogOutputStatusVariation variation,
    AnalogOutputStatus* first,
    IEventCollection_for_AnalogOutputStatus* items)
{
  UNUSED(first);
  switch (variation)
  {
  case (EventAnalogOutputStatusVariation_Group42Var1):
{
DNP3Serializer_for_AnalogOutputStatus temp = Inst_in_Group42Var1_static();
    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogOutputStatusVariation_Group42Var2):
{
DNP3Serializer_for_AnalogOutputStatus temp = Inst_in_Group42Var2_static();
    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogOutputStatusVariation_Group42Var3):
{
DNP3Serializer_for_AnalogOutputStatus temp = Inst_in_Group42Var3_static();
    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogOutputStatusVariation_Group42Var4):
{
DNP3Serializer_for_AnalogOutputStatus temp = Inst_in_Group42Var4_static();
    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
  case (EventAnalogOutputStatusVariation_Group42Var5):
{
DNP3Serializer_for_AnalogOutputStatus temp = Inst_in_Group42Var5_static();
    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
//  case (EventAnalogOutputStatusVariation_Group42Var6):
//    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, Inst_in_Group42Var6_static());
  case (EventAnalogOutputStatusVariation_Group42Var7):
{
DNP3Serializer_for_AnalogOutputStatus temp = Inst_in_Group42Var7_static();
    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
//  case (EventAnalogOutputStatusVariation_Group42Var8):
//    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, Inst_in_Group42Var8_static());
  default:
{
DNP3Serializer_for_AnalogOutputStatus temp = Inst_in_Group42Var1_static();
    return Write_for_AnalogOutputStatus_in_EventWriters_static(&(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items, &temp);
}
}
}
/*
uint16_t Write_for_OctetString_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventOctetStringVariation variation,
    OctetString* first,
    IEventCollection_for_OctetString* items)
{
  UNUSED(variation);
//   uint16_t Size_in_OctetData(OctetData *pOctetData);
  return Write_for_OctetString_in_EventWriters_static(Size_in_OctetData(&(first->oOctetData)), &(((ASDUEventWriteHandler*)pASDUEventWriteHandler)->writer), items);
}
*/
////} // namespace opendnp3
/*
void ASDUEventWriteHandler_in_ASDUEventWriteHandler(ASDUEventWriteHandler *pASDUEventWriteHandler, HeaderWriter* writer)
{
  pASDUEventWriteHandler->writer = *writer;

  setParentPointer_in_IEventWriteHandler(&(pASDUEventWriteHandler->iIEventWriteHandler), pASDUEventWriteHandler);

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_Binary_in_IEventWriteHandler = Write_for_Binary_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventBinaryVariation variation,
////                           const Binary& first,
////                           IEventCollection<Binary>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_DoubleBinary_in_IEventWriteHandler = Write_for_DoubleBinary_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventDoubleBinaryVariation variation,
////                           const DoubleBitBinary& first,
////                           IEventCollection<DoubleBitBinary>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_Counter_in_IEventWriteHandler = Write_for_Counter_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventCounterVariation variation,
////                           const Counter& first,
////                           IEventCollection<Counter>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_FrozenCounter_in_IEventWriteHandler = Write_for_FrozenCounter_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventFrozenCounterVariation variation,
////                           const FrozenCounter& first,
////                           IEventCollection<FrozenCounter>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_Analog_in_IEventWriteHandler = Write_for_Analog_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventAnalogVariation variation,
////                           const Analog& first,
////                           IEventCollection<Analog>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_BinaryOutputStatus_in_IEventWriteHandler = Write_for_BinaryOutputStatus_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventBinaryOutputStatusVariation variation,
////                           const BinaryOutputStatus& first,
////                           IEventCollection<BinaryOutputStatus>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_AnalogOutputStatus_in_IEventWriteHandler = Write_for_AnalogOutputStatus_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventAnalogOutputStatusVariation variation,
////                           const AnalogOutputStatus& first,
////                           IEventCollection<AnalogOutputStatus>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_for_OctetString_in_IEventWriteHandler = Write_for_OctetString_in_ASDUEventWriteHandler_override;
////    virtual uint16_t Write(EventOctetStringVariation variation,
////                           const OctetString& first,
////                           IEventCollection<OctetString>& items) override;
}
*/
