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

#include "ASDUEventWriteHandler.h"

#include "EventWriters.h"
#include "Group11.h"
#include "Group2.h"
#include "Group22.h"
#include "Group23.h"
#include "Group32.h"
#include "Group4.h"
#include "Group42.h"

////namespace opendnp3
////{
MYTODO
uint16_t Write_for_Binary_in_ASDUEventWriteHandler(ASDUEventWriteHandler *pASDUEventWriteHandler,
                                      EventBinaryVariation_uint8_t variation,
                                      Binary* first,
                                      IEventCollection_for_Binary* items)
{
    switch (variation)
    {
    case (EventBinaryVariation_Group2Var1):
        return EventWriters::Write(this->writer, items, Group2Var1::Inst());
    case (EventBinaryVariation_Group2Var2):
        return EventWriters::Write(this->writer, items, Group2Var2::Inst());
    case (EventBinaryVariation_Group2Var3):
        return EventWriters::WriteWithCTO(first.time, this->writer, items, Group2Var3::Inst());
    default:
        return EventWriters::Write(this->writer, items, Group2Var1::Inst());
    }
}

uint16_t ASDUEventWriteHandler::Write(EventDoubleBinaryVariation variation,
                                      const DoubleBitBinary& first,
                                      IEventCollection<DoubleBitBinary>& items)
{
    switch (variation)
    {
    case (EventDoubleBinaryVariation::Group4Var1):
        return EventWriters::Write(this->writer, items, Group4Var1::Inst());
    case (EventDoubleBinaryVariation::Group4Var2):
        return EventWriters::Write(this->writer, items, Group4Var2::Inst());
    case (EventDoubleBinaryVariation::Group4Var3):
        return EventWriters::WriteWithCTO(first.time, this->writer, items, Group4Var3::Inst());
    default:
        return EventWriters::Write(this->writer, items, Group4Var1::Inst());
    }
}

uint16_t ASDUEventWriteHandler::Write(EventCounterVariation variation,
                                      const Counter& /*first*/,
                                      IEventCollection<Counter>& items)
{
    switch (variation)
    {
    case (EventCounterVariation::Group22Var1):
        return EventWriters::Write(this->writer, items, Group22Var1::Inst());
    case (EventCounterVariation::Group22Var2):
        return EventWriters::Write(this->writer, items, Group22Var2::Inst());
    case (EventCounterVariation::Group22Var5):
        return EventWriters::Write(this->writer, items, Group22Var5::Inst());
    case (EventCounterVariation::Group22Var6):
        return EventWriters::Write(this->writer, items, Group22Var6::Inst());
    default:
        return EventWriters::Write(this->writer, items, Group22Var1::Inst());
    }
}

uint16_t ASDUEventWriteHandler::Write(EventFrozenCounterVariation variation,
                                      const FrozenCounter& /*first*/,
                                      IEventCollection<FrozenCounter>& items)
{
    switch (variation)
    {
    case (EventFrozenCounterVariation::Group23Var1):
        return EventWriters::Write(this->writer, items, Group23Var1::Inst());
    case (EventFrozenCounterVariation::Group23Var2):
        return EventWriters::Write(this->writer, items, Group23Var2::Inst());
    case (EventFrozenCounterVariation::Group23Var5):
        return EventWriters::Write(this->writer, items, Group23Var5::Inst());
    case (EventFrozenCounterVariation::Group23Var6):
        return EventWriters::Write(this->writer, items, Group23Var6::Inst());
    default:
        return 0;
    }
}

uint16_t ASDUEventWriteHandler::Write(EventAnalogVariation variation,
                                      const Analog& /*first*/,
                                      IEventCollection<Analog>& items)
{
    switch (variation)
    {
    case (EventAnalogVariation::Group32Var1):
        return EventWriters::Write(this->writer, items, Group32Var1::Inst());
    case (EventAnalogVariation::Group32Var2):
        return EventWriters::Write(this->writer, items, Group32Var2::Inst());
    case (EventAnalogVariation::Group32Var3):
        return EventWriters::Write(this->writer, items, Group32Var3::Inst());
    case (EventAnalogVariation::Group32Var4):
        return EventWriters::Write(this->writer, items, Group32Var4::Inst());
    case (EventAnalogVariation::Group32Var5):
        return EventWriters::Write(this->writer, items, Group32Var5::Inst());
    case (EventAnalogVariation::Group32Var6):
        return EventWriters::Write(this->writer, items, Group32Var6::Inst());
    case (EventAnalogVariation::Group32Var7):
        return EventWriters::Write(this->writer, items, Group32Var7::Inst());
    case (EventAnalogVariation::Group32Var8):
        return EventWriters::Write(this->writer, items, Group32Var8::Inst());
    default:
        return EventWriters::Write(this->writer, items, Group32Var1::Inst());
    }
}

uint16_t ASDUEventWriteHandler::Write(EventBinaryOutputStatusVariation variation,
                                      const BinaryOutputStatus& /*first*/,
                                      IEventCollection<BinaryOutputStatus>& items)
{
    switch (variation)
    {
    case (EventBinaryOutputStatusVariation::Group11Var1):
        return EventWriters::Write(this->writer, items, Group11Var1::Inst());
    case (EventBinaryOutputStatusVariation::Group11Var2):
        return EventWriters::Write(this->writer, items, Group11Var2::Inst());
    default:
        return EventWriters::Write(this->writer, items, Group11Var1::Inst());
    }
}

uint16_t ASDUEventWriteHandler::Write(EventAnalogOutputStatusVariation variation,
                                      const AnalogOutputStatus& /*first*/,
                                      IEventCollection<AnalogOutputStatus>& items)
{
    switch (variation)
    {
    case (EventAnalogOutputStatusVariation::Group42Var1):
        return EventWriters::Write(this->writer, items, Group42Var1::Inst());
    case (EventAnalogOutputStatusVariation::Group42Var2):
        return EventWriters::Write(this->writer, items, Group42Var2::Inst());
    case (EventAnalogOutputStatusVariation::Group42Var3):
        return EventWriters::Write(this->writer, items, Group42Var3::Inst());
    case (EventAnalogOutputStatusVariation::Group42Var4):
        return EventWriters::Write(this->writer, items, Group42Var4::Inst());
    case (EventAnalogOutputStatusVariation::Group42Var5):
        return EventWriters::Write(this->writer, items, Group42Var5::Inst());
    case (EventAnalogOutputStatusVariation::Group42Var6):
        return EventWriters::Write(this->writer, items, Group42Var6::Inst());
    case (EventAnalogOutputStatusVariation::Group42Var7):
        return EventWriters::Write(this->writer, items, Group42Var7::Inst());
    case (EventAnalogOutputStatusVariation::Group42Var8):
        return EventWriters::Write(this->writer, items, Group42Var8::Inst());
    default:
        return EventWriters::Write(this->writer, items, Group42Var1::Inst());
    }
}

uint16_t ASDUEventWriteHandler::Write(EventOctetStringVariation /*variation*/,
                                      const OctetString& first,
                                      IEventCollection<OctetString>& items)
{
    return EventWriters::Write(first.Size(), this->writer, items);
}

////} // namespace opendnp3
  void ASDUEventWriteHandler_in_ASDUEventWriteHandler(ASDUEventWriteHandler *pASDUEventWriteHandler, HeaderWriter* writer)
{
  writer = *writer;
  //signatura_ASDUEventWriteHandler
  (pASDUEventWriteHandler->iIEventWriteHandler).pParentPointer = pASDUEventWriteHandler;
  (pASDUEventWriteHandler->iIEventWriteHandler).parentType = PARENTTYPE_ASDUEventWriteHandler;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventBinary_in_IEventWriteHandler = Write_EventBinary_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventBinaryVariation variation,
////                           const Binary& first,
////                           IEventCollection<Binary>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventDoubleBinary_in_IEventWriteHandler = Write_EventDoubleBinary_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventDoubleBinaryVariation variation,
////                           const DoubleBitBinary& first,
////                           IEventCollection<DoubleBitBinary>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventCounter_in_IEventWriteHandler = Write_EventCounter_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventCounterVariation variation,
////                           const Counter& first,
////                           IEventCollection<Counter>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventFrozenCounter_in_IEventWriteHandler = Write_EventFrozenCounter_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventFrozenCounterVariation variation,
////                           const FrozenCounter& first,
////                           IEventCollection<FrozenCounter>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventAnalog_in_IEventWriteHandler = Write_EventAnalog_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventAnalogVariation variation,
////                           const Analog& first,
////                           IEventCollection<Analog>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventBinaryOutputStatus_in_IEventWriteHandler = Write_EventBinaryOutputStatus_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventBinaryOutputStatusVariation variation,
////                           const BinaryOutputStatus& first,
////                           IEventCollection<BinaryOutputStatus>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventAnalogOutputStatus_in_IEventWriteHandler = Write_EventAnalogOutputStatus_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventAnalogOutputStatusVariation variation,
////                           const AnalogOutputStatus& first,
////                           IEventCollection<AnalogOutputStatus>& items) override;

  (pASDUEventWriteHandler->iIEventWriteHandler).pWrite_EventOctetString_in_IEventWriteHandler = Write_EventOctetString_in_ASDUEventWriteHandler;
////    virtual uint16_t Write(EventOctetStringVariation variation,
////                           const OctetString& first,
////                           IEventCollection<OctetString>& items) override;
}
