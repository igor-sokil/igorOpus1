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
#include "EventStorage.h"

#include "EventSelection.h"
#include "EventUpdate.h"
#include "EventWriting.h"

////namespace opendnp3
////{

uint32_t RemoveAll_in_List_for_EventRecord(EventStorage *pEventStorage, List_for_EventRecord *pList_for_EventRecord, boolean (*match)(EventStorage *pEventStorage, EventRecord* record));//const U& match);

void EventStorage_in_EventStorage(EventStorage *pEventStorage, EventBufferConfig* config)
{
////: state(config) {}
  EventLists_in_EventLists(&(pEventStorage->state), config);
}

boolean IsAnyTypeFull_in_EventStorage(EventStorage *pEventStorage)
{
////  return this->state.IsAnyTypeFull();
  return IsAnyTypeFull_in_EventLists(&(pEventStorage->state));
}

uint32_t NumSelected_in_EventStorage(EventStorage *pEventStorage)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"NumSelected_in_EventStorage1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(pEventStorage->state).counters.selected= "<<(uint16_t)(pEventStorage->state).counters.selected<<'\n';
  decrement_stack_info();
#endif
////  return this->state.counters.selected;
  return (pEventStorage->state).counters.selected;
}

uint32_t NumUnwritten_in_EventStorage(EventStorage *pEventStorage, EventClass_uint8_t clazz)
{
////  return this->state.counters.total.Get(clazz) - this->state.counters.written.Get(clazz);
  return Get_in_ClazzCount(&((pEventStorage->state).counters.total), clazz) -
         Get_in_ClazzCount(&((pEventStorage->state).counters.written), clazz);
}

boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_BinarySpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

boolean Update_DoubleBitBinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_DoubleBitBinarySpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_DoubleBitBinarySpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

boolean Update_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogSpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_AnalogSpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

boolean Update_CounterSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_CounterSpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_CounterSpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

boolean Update_FrozenCounterSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_FrozenCounterSpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_FrozenCounterSpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

boolean Update_BinaryOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinaryOutputStatusSpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_BinaryOutputStatusSpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

boolean Update_AnalogOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogOutputStatusSpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_AnalogOutputStatusSpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

boolean Update_OctetStringSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_OctetStringSpec* evt)
{
////  return EventUpdate::Update(state, evt);
  return Update_OctetStringSpec_in_EventUpdate_static(&(pEventStorage->state), evt);
}

uint32_t SelectByType_BinarySpec_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_BinarySpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
}

uint32_t SelectByType_DoubleBitBinarySpec_in_EventStorage(EventStorage *pEventStorage, EventDoubleBinaryVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_DoubleBitBinarySpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
}

uint32_t SelectByType_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, EventAnalogVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_AnalogSpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
}

uint32_t SelectByType_CounterSpec_in_EventStorage(EventStorage *pEventStorage, EventCounterVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_CounterSpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
}

uint32_t SelectByType_FrozenCounterSpec_in_EventStorage(EventStorage *pEventStorage, EventFrozenCounterVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_FrozenCounterSpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
}

uint32_t SelectByType_BinaryOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, EventBinaryOutputStatusVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_BinaryOutputStatusSpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
////  return 0;
}

uint32_t SelectByType_AnalogOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, EventAnalogOutputStatusVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_AnalogOutputStatusSpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
}

uint32_t SelectByType_OctetStringSpec_in_EventStorage(EventStorage *pEventStorage, EventOctetStringVariation_uint8_t variation, uint32_t max)
{
  return SelectByType_for_OctetStringSpec_in_EventSelection_staticOver2(&(pEventStorage->state), variation, max);
}

uint32_t SelectByType_in_EventStorage(EventStorage *pEventStorage, EventType_uint16_t type, uint32_t max)
{
  switch (type)
  {
  case (EventType_Binary):
    return SelectByType_for_BinarySpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  case (EventType_DoubleBitBinary):
    return SelectByType_for_DoubleBitBinarySpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  case (EventType_Counter):
    return SelectByType_for_CounterSpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  case (EventType_FrozenCounter):
    return SelectByType_for_FrozenCounterSpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  case (EventType_Analog):
    return SelectByType_for_AnalogSpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  case (EventType_BinaryOutputStatus):
    return SelectByType_for_BinaryOutputStatusSpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  case (EventType_AnalogOutputStatus):
    return SelectByType_for_AnalogOutputStatusSpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  case (EventType_OctetString):
    return SelectByType_for_OctetStringSpec_in_EventSelection_staticOver1(&(pEventStorage->state), max);
  default:
    return 0;
  }
}

uint32_t SelectByClass_in_EventStorageOver1(EventStorage *pEventStorage, EventClass_uint8_t clazz)
{
////  return EventSelection::SelectByClass(this->state, ClassField(clazz), 0xFFFFFFFF);//std::numeric_limits<uint32_t>::max());
  ClassField cClassField;
  ClassField_in_ClassFieldOver3(&cClassField, clazz);
  return SelectByClass_in_EventSelection_static(&(pEventStorage->state), &cClassField, 0xFFFFFFFF);
}

////uint32_t EventStorage::SelectByClass(EventClass_uint8_t* clazz, uint32_t max)
uint32_t SelectByClass_in_EventStorageOver2(EventStorage *pEventStorage, EventClass_uint8_t clazz, uint32_t max)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectByClass_in_EventStorageOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*EventClass_uint8_t clazz= "<<(uint16_t)clazz<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t max= "<<(uint16_t)max<<'\n';
#endif
  ClassField cClassField;
  ClassField_in_ClassFieldOver3(&cClassField, clazz);
////  return EventSelection::SelectByClass(this->state, ClassField(clazz), max);
  uint32_t tmp = SelectByClass_in_EventSelection_static(&(pEventStorage->state), &cClassField, max);
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t tmp= "<<(uint16_t)tmp<<'\n';
  decrement_stack_info();
#endif
  return tmp;
}

//uint32_t EventStorage::SelectByClass(ClassField* clazz)
uint32_t SelectByClass_in_EventStorageOver3(EventStorage *pEventStorage, ClassField* clazz)
{
////  return EventSelection::SelectByClass(this->state, clazz, 0xFFFFFFFF);//std::numeric_limits<uint32_t>::max());
  return SelectByClass_in_EventSelection_static(&(pEventStorage->state), clazz, 0xFFFFFFFF);
}

//uint32_t EventStorage::SelectByClass(const ClassField* clazz, uint32_t max)
uint32_t SelectByClass_in_EventStorageOver4(EventStorage *pEventStorage, ClassField* clazz, uint32_t max)
{
////  return EventSelection::SelectByClass(this->state, clazz, max);
  return SelectByClass_in_EventSelection_static(&(pEventStorage->state), clazz, max);
}

////uint32_t EventStorage::Write(IEventWriteHandler* handler)
uint32_t Write_in_EventStorage(EventStorage *pEventStorage, IEventWriteHandler* handler)
{
//    uint32_t Write_in_EventWriting_static(EventLists* lists, IEventWriteHandler* handler);
////  return EventWriting::Write(this->state, handler);
  return Write_in_EventWriting_static(&(pEventStorage->state), handler);
}

boolean written_in_EventStorage(EventStorage *pEventStorage, EventRecord* record);

boolean written_in_EventStorage(EventStorage *pEventStorage, EventRecord* record)
{
////  auto written = [this](EventRecord& record) -> bool {
  if (record->state == EventState_written)
  {
//     void (*pRemoveTypeFromStorage)(EventRecord* record, EventLists* lists);// const = 0;
//void RemoveTypeFromStorage_in_IEventType(IEventType *, EventRecord* record, EventLists* lists);
////      record.type->RemoveTypeFromStorage(record, this->state);
    //((IEventType*)record->type)->
    RemoveTypeFromStorage_in_IEventType(((IEventType*)record->type), record, &(pEventStorage->state));//pRemoveTypeFromStorage(record, &(pEventStorage->state));
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////      this->state.counters.OnRemove(record.clazz, record.state);
    OnRemove_in_EventClassCounters(&((pEventStorage->state).counters), record->clazz, record->state);
    return true;
  }

  return false;
}


////uint32_t EventStorage::ClearWritten()
uint32_t ClearWritten_in_EventStorage(EventStorage *pEventStorage)
{
////  auto written = [this](EventRecord& record) -> bool {
////    if (record.state == EventState::written)
////    {
////      record.type->RemoveTypeFromStorage(record, this->state);
//void OnRemove_in_EventClassCounters(EventClassCounters *pEventClassCounters, EventClass_uint8_t clazz, EventState_uint8_t state);
////      this->state.counters.OnRemove(record.clazz, record.state);
////      return true;
////    }

////    return false;
////  };

////  return this->state.events.RemoveAll(&((pEventStorage->state).events), written);
  return RemoveAll_in_List_for_EventRecord(pEventStorage, &((pEventStorage->state).events), written_in_EventStorage);
}

void clear_in_EventStorage(EventRecord* record);
void clear_in_EventStorage(EventRecord* record)
{
  record->state = EventState_unselected;
}

void Unselect_in_EventStorage(EventStorage *pEventStorage)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Unselect_in_EventStorage1"<<'\n';
#endif
//void ResetOnFail_in_EventClassCounters(EventClassCounters *pEventClassCounters);
////  auto clear = [](EventRecord& record) -> void { record.state = EventState::unselected; };

////  this->state.events.Foreach(clear);
  Foreach_in_List_for_EventRecord(&((pEventStorage->state).events), clear_in_EventStorage);

  // keep the total, but clear the selected/written
////  this->state.counters.ResetOnFail();
  ResetOnFail_in_EventClassCounters(&((pEventStorage->state).counters));
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}
/*
////template<class T> template<class U> void List<T>::Foreach(const U& action)
////{
////    auto iter = this->Iterate();
////    while (iter.HasNext())
////    {
////        action(iter.Next()->value);
////    }
////}
*/
////} // namespace opendnp3
