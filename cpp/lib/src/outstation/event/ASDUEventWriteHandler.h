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
#ifndef OPENDNP3_ASDUEVENTWRITEHANDLER_H
#define OPENDNP3_ASDUEVENTWRITEHANDLER_H

////#include "IEventWriteHandler.h"
////#include "app/DNP3Serializer.h"
////#include "app/HeaderWriter.h"

////#include "opendnp3/util/Uncopyable.h"

#include "IEventWriteHandler.h"
#include "DNP3Serializer.h"
#include "HeaderWriter.h"

////namespace opendnp3
////{

////class ASDUEventWriteHandler final : public IEventWriteHandler, private Uncopyable
typedef struct
{
  IEventWriteHandler iIEventWriteHandler;

////public:
////    explicit ASDUEventWriteHandler(const HeaderWriter& writer) : writer(writer) {}

////    virtual uint16_t Write(EventBinaryVariation variation,
////                           const Binary& first,
////                           IEventCollection<Binary>& items) override;
////    virtual uint16_t Write(EventDoubleBinaryVariation variation,
////                           const DoubleBitBinary& first,
////                           IEventCollection<DoubleBitBinary>& items) override;
////    virtual uint16_t Write(EventCounterVariation variation,
////                           const Counter& first,
////                           IEventCollection<Counter>& items) override;
////    virtual uint16_t Write(EventFrozenCounterVariation variation,
////                           const FrozenCounter& first,
////                           IEventCollection<FrozenCounter>& items) override;
////    virtual uint16_t Write(EventAnalogVariation variation,
////                           const Analog& first,
////                           IEventCollection<Analog>& items) override;
////    virtual uint16_t Write(EventBinaryOutputStatusVariation variation,
////                           const BinaryOutputStatus& first,
////                           IEventCollection<BinaryOutputStatus>& items) override;
////    virtual uint16_t Write(EventAnalogOutputStatusVariation variation,
////                           const AnalogOutputStatus& first,
////                           IEventCollection<AnalogOutputStatus>& items) override;
////    virtual uint16_t Write(EventOctetStringVariation variation,
////                           const OctetString& first,
////                           IEventCollection<OctetString>& items) override;

////private:
  HeaderWriter writer;
} ASDUEventWriteHandler;

void ASDUEventWriteHandler_in_ASDUEventWriteHandler(ASDUEventWriteHandler *pASDUEventWriteHandler, HeaderWriter* writer);

uint16_t Write_for_Binary_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventBinaryVariation_uint8_t variation,
    Binary* first,
    IEventCollection_for_Binary* items);
uint16_t Write_for_DoubleBitBinary_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventDoubleBinaryVariation variation,
    DoubleBitBinary* first,
    IEventCollection_for_DoubleBitBinary* items);
uint16_t Write_for_Counter_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventCounterVariation variation,
    Counter* first,
    IEventCollection_for_Counter* items);
uint16_t Write_for_FrozenCounter_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventFrozenCounterVariation variation,
    FrozenCounter* first,
    IEventCollection_for_FrozenCounter* items);
uint16_t Write_for_Analog_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventAnalogVariation variation,
    Analog* first,
    IEventCollection_for_Analog* items);
uint16_t Write_for_BinaryOutputStatus_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventBinaryOutputStatusVariation variation,
    BinaryOutputStatus* first,
    IEventCollection_for_BinaryOutputStatus* items);
uint16_t Write_for_AnalogOutputStatus_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventAnalogOutputStatusVariation variation,
    AnalogOutputStatus* first,
    IEventCollection_for_AnalogOutputStatus* items);
uint16_t Write_for_OctetString_in_ASDUEventWriteHandler_override(void *pASDUEventWriteHandler,
    EventOctetStringVariation variation,
    OctetString* first,
    IEventCollection_for_OctetString* items);


////} // namespace opendnp3

#endif
