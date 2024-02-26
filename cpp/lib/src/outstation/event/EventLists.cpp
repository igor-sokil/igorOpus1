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
//#include <QtWidgets>
#include "header.h"
#include "EventLists.h"

////namespace opendnp3
////{

////EventLists::EventLists(const EventBufferConfig& config)
////    : events(config.TotalEvents()),
////      binary(config.maxBinaryEvents),
////      doubleBinary(config.maxDoubleBinaryEvents),
////      analog(config.maxAnalogEvents),
////      counter(config.maxCounterEvents),
////      frozenCounter(config.maxFrozenCounterEvents),
////      binaryOutputStatus(config.maxBinaryOutputStatusEvents),
////      analogOutputStatus(config.maxAnalogOutputStatusEvents),
////      octetString(config.maxOctetStringEvents)
////{
////}

void EventLists_in_EventLists(EventLists *pEventLists, EventBufferConfig* config)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"EventLists_in_EventLists1"<<'\n';
  decrement_stack_info();
#endif
  EventClassCounters_in_EventClassCounters(&(pEventLists->counters_in_EventLists));
//   uint32_t TotalEvents_in_EventBufferConfig(EventBufferConfig *pEventBufferConfig);
//    pEventLists->events = TotalEvents_in_EventBufferConfig(config);//(config.TotalEvents()),
  List_for_EventRecord_in_List_for_EventRecordOver2(&(pEventLists->events_in_EventLists), TotalEvents_in_EventBufferConfig(config));
////    pEventLists->binary = config->maxBinaryEvents),
  List_TypedEventRecord_for_BinarySpec_in_List_TypedEventRecord_for_BinarySpecOver2(&(pEventLists->binary),
      config->maxBinaryEvents);
////      doubleBinary(config.maxDoubleBinaryEvents),

  List_TypedEventRecord_for_DoubleBitBinarySpec_in_List_TypedEventRecord_for_DoubleBitBinarySpecOver2(&(pEventLists->doubleBinary),
      config->maxDoubleBinaryEvents);
////      analog(config.maxAnalogEvents),
  List_TypedEventRecord_for_AnalogSpec_in_List_TypedEventRecord_for_AnalogSpecOver2(&(pEventLists->analog),
      config->maxAnalogEvents);
////      counter(config.maxCounterEvents),
  List_TypedEventRecord_for_CounterSpec_in_List_TypedEventRecord_for_CounterSpecOver2(&(pEventLists->counter),
      config->maxCounterEvents);
////      frozenCounter(config.maxFrozenCounterEvents),
  List_TypedEventRecord_for_FrozenCounterSpec_in_List_TypedEventRecord_for_FrozenCounterSpecOver2(&(pEventLists->frozenCounter),
      config->maxFrozenCounterEvents);
////      binaryOutputStatus(config.maxBinaryOutputStatusEvents),

  List_TypedEventRecord_for_BinaryOutputStatusSpec_in_List_TypedEventRecord_for_BinaryOutputStatusSpecOver2(&(pEventLists->binaryOutputStatus),
      config->maxBinaryOutputStatusEvents);
////      analogOutputStatus(config.maxAnalogOutputStatusEvents),
  List_TypedEventRecord_for_AnalogOutputStatusSpec_in_List_TypedEventRecord_for_AnalogOutputStatusSpecOver2(&(pEventLists->analogOutputStatus),
      config->maxAnalogOutputStatusEvents);
////      octetString(config.maxOctetStringEvents)
  List_TypedEventRecord_for_OctetStringSpec_in_List_TypedEventRecord_for_OctetStringSpecOver2(&(pEventLists->octetString),
      config->maxOctetStringEvents);
}

boolean IsAnyTypeFull_in_EventLists(EventLists *pEventLists)
{
  return IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinarySpec(&(pEventLists->binary)) ||
         IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_DoubleBitBinarySpec(&(pEventLists->doubleBinary)) ||
////    return this->binary.IsFullAndCapacityNotZero() || this->doubleBinary.IsFullAndCapacityNotZero()
////        || this->counter.IsFullAndCapacityNotZero() || this->frozenCounter.IsFullAndCapacityNotZero()
         IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_CounterSpec(&(pEventLists->counter)) ||
         IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_FrozenCounterSpec(&(pEventLists->frozenCounter)) ||
////        || this->analog.IsFullAndCapacityNotZero() || this->binaryOutputStatus.IsFullAndCapacityNotZero()
////        || this->analogOutputStatus.IsFullAndCapacityNotZero() || this->octetString.IsFullAndCapacityNotZero();
         IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(&(pEventLists->analog)) ||
         IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(&(pEventLists->analogOutputStatus));
}

List_TypedEventRecord_for_BinarySpec*  GetList_for_BinarySpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->binary);
}
////template<> List<TypedEventRecord<BinarySpec>>& EventLists::GetList()
////{
////    return this->binary;
////}

List_TypedEventRecord_for_DoubleBitBinarySpec*    GetList_for_DoubleBitBinarySpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->doubleBinary);
}
////template<> List<TypedEventRecord<DoubleBitBinarySpec>>& EventLists::GetList()
////{
////    return this->doubleBinary;
////}

List_TypedEventRecord_for_CounterSpec*            GetList_for_CounterSpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->counter);
}
////template<> List<TypedEventRecord<CounterSpec>>& EventLists::GetList()
////{
////    return this->counter;
////}

List_TypedEventRecord_for_FrozenCounterSpec*      GetList_for_FrozenCounterSpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->frozenCounter);
}
////template<> List<TypedEventRecord<FrozenCounterSpec>>& EventLists::GetList()
////{
////    return this->frozenCounter;
////}

List_TypedEventRecord_for_AnalogSpec*             GetList_for_AnalogSpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->analog);
}
////template<> List<TypedEventRecord<AnalogSpec>>& EventLists::GetList()
////{
////    return this->analog;
////}

List_TypedEventRecord_for_BinaryOutputStatusSpec* GetList_for_BinaryOutputStatusSpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->binaryOutputStatus);
}
////template<> List<TypedEventRecord<BinaryOutputStatusSpec>>& EventLists::GetList()
////{
////    return this->binaryOutputStatus;
////}

List_TypedEventRecord_for_AnalogOutputStatusSpec* GetList_for_AnalogOutputStatusSpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->analogOutputStatus);
}
////template<> List<TypedEventRecord<AnalogOutputStatusSpec>>& EventLists::GetList()
////{
////    return this->analogOutputStatus;
////}

List_TypedEventRecord_for_OctetStringSpec*        GetList_for_OctetStringSpec_in_EventLists(EventLists *pEventLists)
{
  return &(pEventLists->octetString);
}
////template<> List<TypedEventRecord<OctetStringSpec>>& EventLists::GetList()
////{
////    return this->octetString;
////}

////} // namespace opendnp3
