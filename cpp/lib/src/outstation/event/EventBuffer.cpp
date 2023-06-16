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
#include "EventBuffer.h"

#include "ASDUEventWriteHandler.h"

////namespace opendnp3
////{

void EventBuffer_in_EventBufferOver2(EventBuffer *pEventBuffer, EventBufferConfig* config)
{
  EventBuffer_in_EventBufferOver1(pEventBuffer);
//void EventStorage_in_EventStorage(EventStorage *pEventStorage, EventBufferConfig* config);
//// : storage(config) {}
  EventStorage_in_EventStorage(pEventBuffer->storage, config);
}

////void EventBuffer::Update(const Event<BinarySpec>& evt)
    void Update_BinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinarySpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_BinarySpec_in_EventBuffer(pEventBuffer, evt);
}

////void EventBuffer::Update(const Event<DoubleBitBinarySpec>& evt)
    void Update_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_DoubleBitBinarySpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_DoubleBitBinarySpec_in_EventBuffer(pEventBuffer, evt);
}

////void EventBuffer::Update(const Event<AnalogSpec>& evt)
    void Update_AnalogSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogSpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_AnalogSpec_in_EventBuffer(pEventBuffer, evt);
}

////void EventBuffer::Update(const Event<CounterSpec>& evt)
    void Update_CounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_CounterSpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_CounterSpec_in_EventBuffer(pEventBuffer, evt);
}

////void EventBuffer::Update(const Event<FrozenCounterSpec>& evt)
    void Update_FrozenCounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_FrozenCounterSpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_FrozenCounterSpec_in_EventBuffer(pEventBuffer, evt);
}

////void EventBuffer::Update(const Event<BinaryOutputStatusSpec>& evt)
    void Update_BinaryOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinaryOutputStatusSpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_BinaryOutputStatusSpec_in_EventBuffer(pEventBuffer, evt);
}

////void EventBuffer::Update(const Event<AnalogOutputStatusSpec>& evt)
    void Update_AnalogOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogOutputStatusSpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, evt);
}

////void EventBuffer::Update(const Event<OctetStringSpec>& evt)
    void Update_OctetStringSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_OctetStringSpec *evt)
{
////    this->UpdateAny(evt);
   UpdateAny_OctetStringSpec_in_EventBuffer(pEventBuffer, evt);
}

////    template<class T> void UpdateAny(const Event<T>& evt)
  void UpdateAny_BinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinarySpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_BinarySpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }
  void UpdateAny_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_DoubleBitBinarySpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_DoubleBitBinarySpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }
  void UpdateAny_AnalogSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogSpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_AnalogSpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }
  void UpdateAny_CounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_CounterSpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_CounterSpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }
  void UpdateAny_FrozenCounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_FrozenCounterSpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_FrozenCounterSpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }
  void UpdateAny_BinaryOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinaryOutputStatusSpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_BinaryOutputStatusSpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }
  void UpdateAny_AnalogOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogOutputStatusSpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_AnalogOutputStatusSpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }
  void UpdateAny_OctetStringSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_OctetStringSpec *evt)
    {
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
         if(Update_OctetStringSpec_in_EventStorage(&(pEventBuffer->storage), evt))
        {
            pEventBuffer->overflow = true;
        }
    }

////void EventBuffer::Unselect()
     void Unselect_in_EventBuffer(EventBuffer *pEventBuffer)
{
//    void Unselect_in_EventStorage(EventStorage *pEventStorage);
////    this->storage.Unselect();
     Unselect_in_EventStorage(&(pEventBuffer->storage));
}

////IINField EventBuffer::SelectAll(GroupVariation gv)
     IINField SelectAll_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint8_t gv)
{
//    IINField SelectMaxCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint8_t gv, uint32_t maximum);
////    return SelectMaxCount(gv, std::numeric_limits<uint32_t>::max());
    return SelectMaxCount_in_EventBuffer(pEventBuffer, gv, 0xFFFFFFFF);
}

IINField SelectCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation gv, uint16_t count)
{
////    return SelectMaxCount(gv, count);
    return SelectMaxCount_in_EventBuffer(pEventBuffer, gv, count);
}

IINField SelectMaxCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation gv, uint32_t maximum)
{
    switch (gv)
    {
    case (GroupVariation_Group2Var0):
        return SelectByType_BinarySpec_in_EventBuffer(pEventBuffer, maximum, EventType_Binary);
////        return this->SelectByType(maximum, EventType::Binary);
    case (GroupVariation_Group2Var1):
        return SelectByType_BinarySpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryVariation_Group2Var1);
////        return this->SelectByType(maximum, EventBinaryVariation::Group2Var1);
    case (GroupVariation_Group2Var2):
        return SelectByType_BinarySpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryVariation_Group2Var2);
////        return this->SelectByType(maximum, EventBinaryVariation::Group2Var2);
    case (GroupVariation_Group2Var3):
        return SelectByType_BinarySpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryVariation_Group2Var3);
////        return this->SelectByType(maximum, EventBinaryVariation::Group2Var3);

    case (GroupVariation_Group4Var0):
        return SelectByType_DoubleBinarySpec_in_EventBuffer(pEventBuffer, maximum, EventType_DoubleBitBinary);
////        return this->SelectByType(maximum, EventType::DoubleBitBinary);
    case (GroupVariation_Group4Var1):
        return SelectByType_DoubleBinarySpec_in_EventBuffer(pEventBuffer, maximum, EventDoubleBinaryVariation_Group4Var1);
////        return this->SelectByType(maximum, EventDoubleBinaryVariation::Group4Var1);
    case (GroupVariation_Group4Var2):
        return SelectByType_DoubleBinarySpec_in_EventBuffer(pEventBuffer, maximum, EventDoubleBinaryVariation_Group4Var2);
////        return this->SelectByType(maximum, EventDoubleBinaryVariation::Group4Var2);
    case (GroupVariation_Group4Var3):
        return SelectByType_DoubleBinarySpec_in_EventBuffer(pEventBuffer, maximum, EventDoubleBinaryVariation_Group4Var3);
////        return this->SelectByType(maximum, EventDoubleBinaryVariation::Group4Var3);

    case (GroupVariation_Group11Var0):
        return SelectByType_BinaryOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventType_BinaryOutputStatus);
////        return this->SelectByType(maximum, EventType::BinaryOutputStatus);
    case (GroupVariation_Group11Var1):
        return SelectByType_BinaryOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryOutputStatusVariation_Group11Var1);
////        return this->SelectByType(maximum, EventBinaryOutputStatusVariation::Group11Var1);
    case (GroupVariation_Group11Var2):
        return SelectByType_BinaryOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryOutputStatusVariation_Group11Var2);
////        return this->SelectByType(maximum, EventBinaryOutputStatusVariation::Group11Var2);

    case (GroupVariation_Group22Var0):
        return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventType_Counter);
////        return this->SelectByType(maximum, EventType::Counter);
    case (GroupVariation_Group22Var1):
        return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var1);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var1);
    case (GroupVariation_Group22Var2):
        return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var2);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var2);
    case (GroupVariation_Group22Var5):
        return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var5);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var5);
    case (GroupVariation_Group22Var6):
        return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var6);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var6);

    case (GroupVariation_Group23Var0):
        return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventType_FrozenCounter);
////        return this->SelectByType(maximum, EventType::FrozenCounter);
    case (GroupVariation_Group23Var1):
        return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var1);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var1);
    case (GroupVariation_Group23Var2):
        return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var2);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var2);
    case (GroupVariation_Group23Var5):
        return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var5);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var5);
    case (GroupVariation_Group23Var6):
        return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var6);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var6);

    case (GroupVariation_Group32Var0):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventType_Analog);
////        return this->SelectByType(maximum, EventType::Analog);
    case (GroupVariation_Group32Var1):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var1);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var1);
    case (GroupVariation_Group32Var2):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var2);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var2);
    case (GroupVariation_Group32Var3):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var3);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var3);
    case (GroupVariation_Group32Var4):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var4);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var4);
    case (GroupVariation_Group32Var5):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var5);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var5);
    case (GroupVariation_Group32Var6):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var6);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var6);
    case (GroupVariation_Group32Var7):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var7);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var7);
    case (GroupVariation_Group32Var8):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var8);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var8);

    case (GroupVariation_Group42Var0):
        return this->SelectByType(maximum, EventType::AnalogOutputStatus);
    case (GroupVariation_Group42Var1):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var1);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var1);
    case (GroupVariation_Group42Var2):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var2);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var2);
    case (GroupVariation_Group42Var3):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var3);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var3);
    case (GroupVariation_Group42Var4):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var4);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var4);
    case (GroupVariation_Group42Var5):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var5);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var5);
    case (GroupVariation_Group42Var6):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var6);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var6);
    case (GroupVariation_Group42Var7):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var7);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var7);
    case (GroupVariation_Group42Var8):
        return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var8);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var8);

    case (GroupVariation_Group60Var2):
        return SelectByClass_EventClass_in_EventBuffer(pEventBuffer, maximum, EventClass_EC1);
////        return this->SelectByClass(maximum, EventClass::EC1);
    case (GroupVariation_Group60Var3):
        return SelectByClass_EventClass_in_EventBuffer(pEventBuffer, maximum, EventClass_EC2);
////        return this->SelectByClass(maximum, EventClass::EC2);
    case (GroupVariation_Group60Var4):
        return SelectByClass_EventClass_in_EventBuffer(pEventBuffer, maximum, EventClass_EC3);
////        return this->SelectByClass(maximum, EventClass::EC3);
//    IINField SelectByClass_EventClass_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventClass clazz)

    case (GroupVariation_Group111Var0):
        return SelectByType_OctetStringSpec_in_EventBuffer(pEventBuffer, maximum, EventOctetStringVariation_Group111Var0);
////        return this->SelectByType(maximum, EventOctetStringVariation::Group111Var0);

    default:
        return IINBit_FUNC_NOT_SUPPORTED;
    }
}

boolean HasAnySelection_in_EventBuffer(EventBuffer *pEventBuffer) 
{
    // are there any selected, but unwritten, events
//    uint32_t NumSelected_in_EventStorage(EventStorage *pEventStorage);
////    return storage.NumSelected() > 0;
    return NumSelected_in_EventStorage(&(pEventBuffer->storage)) > 0;
}

boolean Load_in_EventBuffer(EventBuffer *pEventBuffer, HeaderWriter* writer)
{
MYTODO
    ASDUEventWriteHandler handler(writer);
    this->storage.Write(handler);
    // all selected events were written?
    return this->storage.NumSelected() == 0;
}

ClassField EventBuffer::UnwrittenClassField() const
{
    return ClassField(false, storage.NumUnwritten(EventClass::EC1) > 0, storage.NumUnwritten(EventClass::EC2) > 0,
                      storage.NumUnwritten(EventClass::EC3) > 0);
}

bool EventBuffer::IsOverflown()
{
    if (overflow && !this->storage.IsAnyTypeFull())
    {
        overflow = false;
    }

    return overflow;
}

void EventBuffer::SelectAllByClass(const ClassField& clazz)
{
//    uint32_t SelectByClass_in_EventStorageOver3(EventStorage *pEventStorage, ClassField* clazz);
////    this->storage.SelectByClass(clazz);
      SelectByClass_in_EventStorageOver3();
}

void EventBuffer::ClearWritten()
{
    this->storage.ClearWritten();
}

uint32_t EventBuffer::NumEvents(EventClass ec) const
{
    return this->storage.NumUnwritten(ec);
}

////} // namespace opendnp3
 void EventBuffer_in_EventBufferOver1(EventBuffer *pEventBuffer)
{
  pEventBuffer->overflow = false;
}

////    template<class T> IINField SelectByType(uint32_t max, T type)
      IINField  SelectByType_BinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventBinaryVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventBinary_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
      IINField  SelectByType_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventDoubleBitBinaryVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventDoubleBitBinary_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
      IINField  SelectByType_AnalogSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventAnalogVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventAnalog_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
      IINField  SelectByType_CounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventCounterVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventCounter_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
      IINField  SelectByType_FrozenCounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventFrozenCounterVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventFrozenCounter_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
      IINField  SelectByType_BinaryOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventBinaryOutputStatusVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventBinaryOutputStatus_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
      IINField  SelectByType_AnalogOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventAnalogOutputStatusVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventAnalogOutputStatus_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
      IINField  SelectByType_OctetStringSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventOctetStringVariation_uint8_t type)
    {
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
           SelectByType_EventOctetString_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }

    IINField SelectByClass_EventClass_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventClass clazz)
    {
//    uint32_t SelectByClass_in_EventStorageOver2(EventStorage *pEventStorage, EventClass_uint8_t clazz, uint32_t max);
////        this->storage.SelectByClass(clazz, max);
          SelectByClass_in_EventStorageOver2(&(pEventBuffer->storage), clazz, max);
////        return IINField::Empty();
           return Empty_in_IINField_static();
    }
