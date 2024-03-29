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
//#include <QtWidgets>
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventBuffer.h"

#include "ASDUEventWriteHandler.h"

////namespace opendnp3
////{

void EventBuffer_in_EventBufferOver2(EventBuffer *pEventBuffer, EventBufferConfig* config)
{
  EventBuffer_in_EventBufferOver1(pEventBuffer);
//void EventStorage_in_EventStorage(EventStorage *pEventStorage, EventBufferConfig* config);
//// : storage(config) {}
  EventStorage_in_EventStorage(&(pEventBuffer->storage), config);
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
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"UpdateAny_BinarySpec_in_EventBuffer1"<<'\n';
#endif
//boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
////        if (this->storage.Update(evt))
  if(Update_BinarySpec_in_EventStorage(&(pEventBuffer->storage), evt))
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"UpdateAny_BinarySpec_in_EventBuffer2"<<'\n';
#endif
    pEventBuffer->overflow = true;
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
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
IINField SelectAll_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint16_t gv)
{
//    IINField SelectMaxCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint8_t gv, uint32_t maximum);
////    return SelectMaxCount(gv, std::numeric_limits<uint32_t>::max());
  return SelectMaxCount_in_EventBuffer(pEventBuffer, gv, 0xFFFFFFFF);
}

IINField SelectCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint16_t gv, uint16_t count)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectCount_in_EventBuffer1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t count= "<<count<<'\n';
#endif
////    return SelectMaxCount(gv, count);
  IINField tmp = SelectMaxCount_in_EventBuffer(pEventBuffer, gv, count);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}

IINField SelectMaxCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint16_t gv, uint32_t maximum)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectMaxCount_in_EventBuffer1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maximum= "<<maximum<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*GroupVariation_uint16_t gv= "<<std::hex<<gv<<std::dec<<'\n';
#endif
  switch (gv)
  {
  case (GroupVariation_Group2Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group2Var0"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_in_EventBuffer(pEventBuffer, maximum, EventType_Binary);
////        return this->SelectByType(maximum, EventType::Binary);
  case (GroupVariation_Group2Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group2Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_BinarySpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryVariation_Group2Var1);
////        return this->SelectByType(maximum, EventBinaryVariation::Group2Var1);
  case (GroupVariation_Group2Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group2Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_BinarySpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryVariation_Group2Var2);
////        return this->SelectByType(maximum, EventBinaryVariation::Group2Var2);
  case (GroupVariation_Group2Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group2Var3"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_BinarySpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryVariation_Group2Var3);
////        return this->SelectByType(maximum, EventBinaryVariation::Group2Var3);

// IINField  SelectByType_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventDoubleBinaryVariation_uint8_t type);
  case (GroupVariation_Group4Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group4Var0"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_in_EventBuffer(pEventBuffer, maximum, EventType_DoubleBitBinary);
////        return this->SelectByType(maximum, EventType::DoubleBitBinary);
  case (GroupVariation_Group4Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group4Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_DoubleBitBinarySpec_in_EventBuffer(pEventBuffer, maximum, EventDoubleBinaryVariation_Group4Var1);
////        return this->SelectByType(maximum, EventDoubleBinaryVariation::Group4Var1);
  case (GroupVariation_Group4Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group4Var2"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_DoubleBitBinarySpec_in_EventBuffer(pEventBuffer, maximum, EventDoubleBinaryVariation_Group4Var2);
////        return this->SelectByType(maximum, EventDoubleBinaryVariation::Group4Var2);
  case (GroupVariation_Group4Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group4Var3"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_DoubleBitBinarySpec_in_EventBuffer(pEventBuffer, maximum, EventDoubleBinaryVariation_Group4Var3);
////        return this->SelectByType(maximum, EventDoubleBinaryVariation::Group4Var3);

  case (GroupVariation_Group11Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group11Var0"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_in_EventBuffer(pEventBuffer, maximum, EventType_BinaryOutputStatus);
////        return this->SelectByType(maximum, EventType::BinaryOutputStatus);
  case (GroupVariation_Group11Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group11Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_BinaryOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryOutputStatusVariation_Group11Var1);
////        return this->SelectByType(maximum, EventBinaryOutputStatusVariation::Group11Var1);
  case (GroupVariation_Group11Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group11Var2"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_BinaryOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventBinaryOutputStatusVariation_Group11Var2);
////        return this->SelectByType(maximum, EventBinaryOutputStatusVariation::Group11Var2);

  case (GroupVariation_Group22Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var0"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_in_EventBuffer(pEventBuffer, maximum, EventType_Counter);
////        return this->SelectByType(maximum, EventType::Counter);
  case (GroupVariation_Group22Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var1);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var1);
  case (GroupVariation_Group22Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var2"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var2);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var2);
  case (GroupVariation_Group22Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var5"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var5);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var5);
  case (GroupVariation_Group22Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group22Var6"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_CounterSpec_in_EventBuffer(pEventBuffer, maximum, EventCounterVariation_Group22Var6);
////        return this->SelectByType(maximum, EventCounterVariation::Group22Var6);

  case (GroupVariation_Group23Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var0"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_in_EventBuffer(pEventBuffer, maximum, EventType_FrozenCounter);
////        return this->SelectByType(maximum, EventType::FrozenCounter);
  case (GroupVariation_Group23Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var1);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var1);
  case (GroupVariation_Group23Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var2"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var2);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var2);
  case (GroupVariation_Group23Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var5"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var5);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var5);
  case (GroupVariation_Group23Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group23Var6"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_FrozenCounterSpec_in_EventBuffer(pEventBuffer, maximum, EventFrozenCounterVariation_Group23Var6);
////        return this->SelectByType(maximum, EventFrozenCounterVariation::Group23Var6);

  case (GroupVariation_Group32Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var0"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_in_EventBuffer(pEventBuffer, maximum, EventType_Analog);
////        return this->SelectByType(maximum, EventType::Analog);
  case (GroupVariation_Group32Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var1);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var1);
  case (GroupVariation_Group32Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var2"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var2);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var2);
  case (GroupVariation_Group32Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var3"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var3);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var3);
  case (GroupVariation_Group32Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var4"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var4);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var4);
  case (GroupVariation_Group32Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var5"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var5);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var5);
  case (GroupVariation_Group32Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var6"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var6);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var6);
  case (GroupVariation_Group32Var7):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var7"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var7);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var7);
  case (GroupVariation_Group32Var8):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group32Var8"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogVariation_Group32Var8);
////        return this->SelectByType(maximum, EventAnalogVariation::Group32Var8);

  case (GroupVariation_Group42Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var0"<<'\n';
    decrement_stack_info();
#endif
////        return this->SelectByType(maximum, EventType::AnalogOutputStatus);
    return SelectByType_in_EventBuffer(pEventBuffer, maximum, EventType_AnalogOutputStatus);
  case (GroupVariation_Group42Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var1"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var1);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var1);
  case (GroupVariation_Group42Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var2"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var2);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var2);
  case (GroupVariation_Group42Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var3"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var3);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var3);
  case (GroupVariation_Group42Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var4"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var4);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var4);
  case (GroupVariation_Group42Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var5"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var5);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var5);
  case (GroupVariation_Group42Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var6"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var6);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var6);
  case (GroupVariation_Group42Var7):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var7"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var7);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var7);
  case (GroupVariation_Group42Var8):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group42Var8"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_AnalogOutputStatusSpec_in_EventBuffer(pEventBuffer, maximum, EventAnalogOutputStatusVariation_Group42Var8);
////        return this->SelectByType(maximum, EventAnalogOutputStatusVariation::Group42Var8);

  case (GroupVariation_Group60Var2):
  {
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group60Var2"<<'\n';
#endif
    IINField tmp = SelectByClass_EventClass_in_EventBuffer(pEventBuffer, maximum, EventClass_EC1);
////        return this->SelectByClass(maximum, EventClass::EC1);
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
    return tmp;
  }
  case (GroupVariation_Group60Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group60Var3"<<'\n';
    decrement_stack_info();
#endif
    return SelectByClass_EventClass_in_EventBuffer(pEventBuffer, maximum, EventClass_EC2);
////        return this->SelectByClass(maximum, EventClass::EC2);
  case (GroupVariation_Group60Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group60Var4"<<'\n';
    decrement_stack_info();
#endif
    return SelectByClass_EventClass_in_EventBuffer(pEventBuffer, maximum, EventClass_EC3);
////        return this->SelectByClass(maximum, EventClass::EC3);
//    IINField SelectByClass_EventClass_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventClass clazz)

  case (GroupVariation_Group111Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group111Var0"<<'\n';
    decrement_stack_info();
#endif
    return SelectByType_OctetStringSpec_in_EventBuffer(pEventBuffer, maximum, EventOctetStringVariation_Group111Var0);
////        return this->SelectByType(maximum, EventOctetStringVariation::Group111Var0);

  default:
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*IINBit_FUNC_NOT_SUPPORTED"<<'\n';
    decrement_stack_info();
#endif
//   void IINField_in_IINFieldOver2(IINField *pIINField, IINBit_uint8_t bit);
//        return IINBit_FUNC_NOT_SUPPORTED;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
  }
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
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Load_in_EventBuffer1"<<'\n';
#endif
//void ASDUEventWriteHandler_in_ASDUEventWriteHandler(ASDUEventWriteHandler *pASDUEventWriteHandler, HeaderWriter* writer);
////    ASDUEventWriteHandler handler(writer);

  ASDUEventWriteHandler handler;
  ASDUEventWriteHandler_in_ASDUEventWriteHandler(&handler, writer);
//    uint32_t Write_in_EventStorage(EventStorage *pEventStorage, IEventWriteHandler* handler);
////    this->storage.Write(handler);
  Write_in_EventStorage(&(pEventBuffer->storage), &(handler.iIEventWriteHandler));

  // all selected events were written?
//    uint32_t NumSelected_in_EventStorage(EventStorage *pEventStorage);
//    return this->storage.NumSelected() == 0;
  boolean tmp = NumSelected_in_EventStorage(&(pEventBuffer->storage)) == 0;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Load_in_EventBuffer_"<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

ClassField UnwrittenClassField_in_EventBuffer(EventBuffer *pEventBuffer)
{
  ClassField cClassField;
//  void ClassField_in_ClassFieldOver5(ClassField *pClassField, boolean class0, boolean class1, boolean class2, boolean class3);
//    uint32_t NumUnwritten_in_EventStorage(EventStorage *pEventStorage, EventClass_uint8_t clazz);
////    return ClassField(false, storage.NumUnwritten(EventClass::EC1) > 0, storage.NumUnwritten(EventClass::EC2) > 0,
////                      storage.NumUnwritten(EventClass::EC3) > 0);
  ClassField_in_ClassFieldOver5(&cClassField, false,
                                NumUnwritten_in_EventStorage(&(pEventBuffer->storage), EventClass_EC1) > 0,
                                NumUnwritten_in_EventStorage(&(pEventBuffer->storage), EventClass_EC2) > 0,
                                NumUnwritten_in_EventStorage(&(pEventBuffer->storage), EventClass_EC3) > 0);
  return cClassField;
}

boolean IsOverflown_in_EventBuffer(EventBuffer *pEventBuffer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"IsOverflown_in_EventBuffer1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pEventBuffer->overflow= "<<pEventBuffer->overflow<<'\n';
  decrement_stack_info();
#endif
//    boolean IsAnyTypeFull_in_EventStorage(EventStorage *pEventStorage);
////    if (overflow && !this->storage.IsAnyTypeFull())
  if (pEventBuffer->overflow && !IsAnyTypeFull_in_EventStorage(&(pEventBuffer->storage)))
  {
    pEventBuffer->overflow = false;
  }

  return pEventBuffer->overflow;
}

void SelectAllByClass_in_EventBuffer(EventBuffer *pEventBuffer, ClassField* clazz)
{
//    uint32_t SelectByClass_in_EventStorageOver3(EventStorage *pEventStorage, ClassField* clazz);
////    this->storage.SelectByClass(clazz);
  SelectByClass_in_EventStorageOver3(&(pEventBuffer->storage), clazz);
}

void ClearWritten_in_EventBuffer(EventBuffer *pEventBuffer)
{
//    uint32_t ClearWritten_in_EventStorage(EventStorage *pEventStorage);
////    this->storage.ClearWritten();
  ClearWritten_in_EventStorage(&(pEventBuffer->storage));
}

uint32_t NumEvents_in_EventBuffer(EventBuffer *pEventBuffer, EventClass_uint8_t ec)
{
//    uint32_t NumUnwritten_in_EventStorage(EventStorage *pEventStorage, EventClass_uint8_t clazz);
////    return this->storage.NumUnwritten(ec);
  return NumUnwritten_in_EventStorage(&(pEventBuffer->storage), ec);
}

////} // namespace opendnp3
void EventBuffer_in_EventBufferOver1(EventBuffer *pEventBuffer)
{
  pEventBuffer->overflow = false;

  // ------- IEventReceiver ------

  (pEventBuffer->iIEventReceiver).pUpdate_BinarySpec_in_IEventReceiver = Update_BinarySpec_in_EventBuffer_override;
  (pEventBuffer->iIEventReceiver).pUpdate_DoubleBitBinarySpec_in_IEventReceiver = Update_DoubleBitBinarySpec_in_EventBuffer_override;
  (pEventBuffer->iIEventReceiver).pUpdate_AnalogSpec_in_IEventReceiver = Update_AnalogSpec_in_EventBuffer_override;
  (pEventBuffer->iIEventReceiver).pUpdate_CounterSpec_in_IEventReceiver = Update_CounterSpec_in_EventBuffer_override;
  (pEventBuffer->iIEventReceiver).pUpdate_FrozenCounterSpec_in_IEventReceiver = Update_FrozenCounterSpec_in_EventBuffer_override;
  (pEventBuffer->iIEventReceiver).pUpdate_BinaryOutputStatusSpec_in_IEventReceiver = Update_BinaryOutputStatusSpec_in_EventBuffer_override;
  (pEventBuffer->iIEventReceiver).pUpdate_AnalogOutputStatusSpec_in_IEventReceiver = Update_AnalogOutputStatusSpec_in_EventBuffer_override;
  (pEventBuffer->iIEventReceiver).pUpdate_OctetStringSpec_in_IEventReceiver = Update_OctetStringSpec_in_EventBuffer_override;

  setParentPointer_in_IEventReceiver(&(pEventBuffer->iIEventReceiver), pEventBuffer);

  // ------- IEventSelector ------

//(pEventBuffer->iIEventSelector).pUnselect_in_IEventSelector = Unselect_in_EventBuffer_override;

  (pEventBuffer->iIEventSelector).pSelectAll_in_IEventSelector = SelectAll_in_EventBuffer_override;
  (pEventBuffer->iIEventSelector).pSelectCount_in_IEventSelector = SelectCount_in_EventBuffer_override;

  setParentPointer_in_IEventSelector(&(pEventBuffer->iIEventSelector), pEventBuffer);

  // ------- IResponseLoader -------

  (pEventBuffer->iIResponseLoader).pHasAnySelection_in_IResponseLoader = HasAnySelection_in_EventBuffer_override;
  (pEventBuffer->iIResponseLoader).pLoad_in_IResponseLoader = Load_in_EventBuffer_override;

  setParentPointer_in_IResponseLoader(&(pEventBuffer->iIResponseLoader), pEventBuffer);
}

void Update_BinarySpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_BinarySpec *evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_BinarySpec_in_EventBuffer(parent, evt);
}
void Update_DoubleBitBinarySpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_DoubleBitBinarySpec* evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_DoubleBitBinarySpec_in_EventBuffer(parent, evt);
}
void Update_AnalogSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_AnalogSpec* evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_AnalogSpec_in_EventBuffer(parent, evt);
}
void Update_CounterSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_CounterSpec* evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_CounterSpec_in_EventBuffer(parent, evt);
}
void Update_FrozenCounterSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_FrozenCounterSpec* evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_FrozenCounterSpec_in_EventBuffer(parent, evt);
}
void Update_BinaryOutputStatusSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_BinaryOutputStatusSpec* evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_BinaryOutputStatusSpec_in_EventBuffer(parent, evt);
}
void Update_AnalogOutputStatusSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_AnalogOutputStatusSpec* evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_AnalogOutputStatusSpec_in_EventBuffer(parent, evt);
}
void Update_OctetStringSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_OctetStringSpec* evt)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventReceiver((IEventReceiver*)pIEventReceiver);

  Update_OctetStringSpec_in_EventBuffer(parent, evt);
}

// ------- IEventSelector ------

void Unselect_in_EventBuffer_override(void *pIEventSelector)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventSelector((IEventSelector*)pIEventSelector);

  Unselect_in_EventBuffer(parent);
}
IINField SelectAll_in_EventBuffer_override(void *pIEventSelector, GroupVariation_uint16_t gv)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventSelector((IEventSelector*)pIEventSelector);

  return SelectAll_in_EventBuffer(parent, gv);
}
IINField SelectCount_in_EventBuffer_override(void *pIEventSelector, GroupVariation_uint16_t gv, uint16_t count)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IEventSelector((IEventSelector*)pIEventSelector);

  return SelectCount_in_EventBuffer(parent, gv, count);
}

// ------- IResponseLoader -------

boolean HasAnySelection_in_EventBuffer_override(void *pIResponseLoader)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IResponseLoader((IResponseLoader*)pIResponseLoader);

  return HasAnySelection_in_EventBuffer(parent);
}
boolean Load_in_EventBuffer_override(void *pIResponseLoader, HeaderWriter* writer)
{
  EventBuffer *parent =
    (EventBuffer*)getParentPointer_in_IResponseLoader((IResponseLoader*)pIResponseLoader);

  return Load_in_EventBuffer(parent, writer);
}

IINField  SelectByType_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventType_uint16_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}

////    template<class T> IINField SelectByType(uint32_t max, T type)
IINField  SelectByType_BinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventBinaryVariation_uint8_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_BinarySpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
IINField  SelectByType_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventDoubleBinaryVariation_uint8_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_DoubleBitBinarySpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
IINField  SelectByType_AnalogSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventAnalogVariation_uint8_t type)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByType_AnalogSpec_in_EventBuffer1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventAnalogVariation_uint8_t type= "<<(uint16_t)type<<'\n';
  decrement_stack_info();
#endif
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_AnalogSpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
IINField  SelectByType_CounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventCounterVariation_uint8_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_CounterSpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
IINField  SelectByType_FrozenCounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventFrozenCounterVariation_uint8_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_FrozenCounterSpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
IINField  SelectByType_BinaryOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventBinaryOutputStatusVariation_uint8_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_BinaryOutputStatusSpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
IINField  SelectByType_AnalogOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventAnalogOutputStatusVariation_uint8_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_AnalogOutputStatusSpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
IINField  SelectByType_OctetStringSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventOctetStringVariation_uint8_t type)
{
//    uint32_t SelectByType_EventBinary_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
////        this->storage.SelectByType(type, max);
  SelectByType_OctetStringSpec_in_EventStorage(&(pEventBuffer->storage), type, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}

IINField SelectByClass_EventClass_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventClass_uint8_t clazz)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByClass_EventClass_in_EventBuffer1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t max= "<<max<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventClass_uint8_t clazz= "<<(int16_t)clazz<<'\n';
  decrement_stack_info();
#endif
//    uint32_t SelectByClass_in_EventStorageOver2(EventStorage *pEventStorage, EventClass_uint8_t clazz, uint32_t max);
////        this->storage.SelectByClass(clazz, max);
  SelectByClass_in_EventStorageOver2(&(pEventBuffer->storage), clazz, max);
////        return IINField::Empty();
  return Empty_in_IINField_static();
}
