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
#ifndef OPENDNP3_EVENTLISTS_H
#define OPENDNP3_EVENTLISTS_H

////#include "ClazzCount.h"
////#include "EventRecord.h"
////#include "TypedEventRecord.h"
////#include "app/MeasurementTypeSpecs.h"

////#include "opendnp3/outstation/EventBufferConfig.h"
////#include "opendnp3/util/Uncopyable.h"

#include "ClazzCount.h"
//#include "EventRecord.h"
#include "List_for_EventRecord.h"
#include "TypedEventRecord.h"
//#include "app/MeasurementTypeSpecs.h"

#include "EventBufferConfig.h"
//#include "opendnp3/util/Uncopyable.h"

#include "List_TypedEventRecord_for_BinarySpec.h"
#include "List_TypedEventRecord_for_DoubleBitBinarySpec.h"
#include "List_TypedEventRecord_for_AnalogSpec.h"
#include "List_TypedEventRecord_for_CounterSpec.h"
#include "List_TypedEventRecord_for_FrozenCounterSpec.h"
#include "List_TypedEventRecord_for_BinaryOutputStatusSpec.h"
#include "List_TypedEventRecord_for_AnalogOutputStatusSpec.h"
#include "List_TypedEventRecord_for_OctetStringSpec.h"

////namespace opendnp3
////{

////typedef List<EventRecord>::Iterator event_iter_t;

////class EventLists : private Uncopyable
typedef struct
{
////public:
////    EventLists() = delete;

////    EventLists(const EventBufferConfig& config);

  // master list keeps the aggregate order and generic data
////    List<EventRecord> events;
  List_for_EventRecord events;

////    template<class T> List<TypedEventRecord<T>>& GetList();

////    bool IsAnyTypeFull() const;

  EventClassCounters counters;

////private:
  // sub-lists just act as type-specific storage
////    List<TypedEventRecord<BinarySpec>> binary;
        List_TypedEventRecord_for_BinarySpec binary;
////    List<TypedEventRecord<DoubleBitBinarySpec>> doubleBinary;
        List_TypedEventRecord_for_DoubleBitBinarySpec doubleBinary;
////    List<TypedEventRecord<AnalogSpec>> analog;
        List_TypedEventRecord_for_AnalogSpec analog;
////    List<TypedEventRecord<CounterSpec>> counter;
        List_TypedEventRecord_for_CounterSpec counter;
////    List<TypedEventRecord<FrozenCounterSpec>> frozenCounter;
        List_TypedEventRecord_for_FrozenCounterSpec frozenCounter;
////    List<TypedEventRecord<BinaryOutputStatusSpec>> binaryOutputStatus;
        List_TypedEventRecord_for_BinaryOutputStatusSpec binaryOutputStatus;
////    List<TypedEventRecord<AnalogOutputStatusSpec>> analogOutputStatus;
        List_TypedEventRecord_for_AnalogOutputStatusSpec analogOutputStatus;
////    List<TypedEventRecord<OctetStringSpec>> octetString;
        List_TypedEventRecord_for_OctetStringSpec octetString;
} EventLists;

  void EventLists_in_EventLists(EventLists *pEventLists, EventBufferConfig* config);

  List_TypedEventRecord_for_BinarySpec*             GetList_for_BinarySpec_in_EventLists(EventLists *pEventLists);
  List_TypedEventRecord_for_DoubleBitBinarySpec*    GetList_for_DoubleBitBinarySpec_in_EventLists(EventLists *pEventLists);
  List_TypedEventRecord_for_AnalogSpec*             GetList_for_AnalogSpec_in_EventLists(EventLists *pEventLists);
  List_TypedEventRecord_for_CounterSpec*            GetList_for_CounterSpec_in_EventLists(EventLists *pEventLists);
  List_TypedEventRecord_for_FrozenCounterSpec*      GetList_for_FrozenCounterSpec_in_EventLists(EventLists *pEventLists);
  List_TypedEventRecord_for_BinaryOutputStatusSpec* GetList_for_BinaryOutputStatusSpec_in_EventLists(EventLists *pEventLists);
  List_TypedEventRecord_for_AnalogOutputStatusSpec* GetList_for_AnalogOutputStatusSpec_in_EventLists(EventLists *pEventLists);
  List_TypedEventRecord_for_OctetStringSpec*        GetList_for_OctetStringSpec_in_EventLists(EventLists *pEventLists);

  boolean IsAnyTypeFull_in_EventLists(EventLists *pEventLists);

void  ForeachWhile_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_AnalogOutputStatusSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));

void  ForeachWhile_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_AnalogSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));

void  ForeachWhile_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_BinaryOutputStatusSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));

void  ForeachWhile_in_List_TypedEventRecord_for_BinarySpec( List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_BinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));

void  ForeachWhile_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_CounterSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));

void  ForeachWhile_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_DoubleBitBinarySpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));

void  ForeachWhile_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_FrozenCounterSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));

void  ForeachWhile_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec,
    EventLists* lists,
    uint32_t num_selected, uint32_t maxEv,
    event_variation_t_in_BinaryInfo variation,
    boolean useDefaultVariation,
    boolean (*select_match)(EventLists* lists, TypedEventRecord_for_OctetStringSpec* node, uint32_t num_selected, uint32_t maxEv, event_variation_t_in_BinaryInfo variation, boolean useDefaultVariation));


////} // namespace opendnp3

#endif
