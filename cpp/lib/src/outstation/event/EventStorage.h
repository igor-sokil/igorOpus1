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
#ifndef OPENDNP3_EVENTSTORAGE_H
#define OPENDNP3_EVENTSTORAGE_H

////#include "EventLists.h"
////#include "IEventWriteHandler.h"
////#include "outstation/Event.h"

////#include "opendnp3/app/ClassField.h"

////#include <limits>

#include "EventLists.h"
#include "IEventWriteHandler.h"
#include "Event.h"

#include "ClassField.h"

#include "List_for_EventRecord.h"
////#include <limits>

////namespace opendnp3
////{

/*
    Data-stucture for holding events.

    * Only performs dynamic allocation at initialization
    * Maintains distinct lists for each type of event to optimize memory usage
*/

////class EventStorage
typedef struct
{

////public:
////    explicit EventStorage(const EventBufferConfig& config);

////    bool IsAnyTypeFull() const;

  // number selected
////    uint32_t NumSelected() const;

  // unselected/selected but not already written
////    uint32_t NumUnwritten(EventClass clazz) const;

  // write selected events to some handler
////    uint32_t Write(IEventWriteHandler& handler);

  // all written events go back to unselected state
////    uint32_t ClearWritten();

  // all written and selected events are reverted to unselected state
////    void Unselect();

  // ---- these functions return true if an overflow occurs ----

////    bool Update(const Event<BinarySpec>& evt);
////    bool Update(const Event<DoubleBitBinarySpec>& evt);
////    bool Update(const Event<AnalogSpec>& evt);
////    bool Update(const Event<CounterSpec>& evt);
////    bool Update(const Event<FrozenCounterSpec>& evt);
////    bool Update(const Event<BinaryOutputStatusSpec>& evt);
////    bool Update(const Event<AnalogOutputStatusSpec>& evt);
////    bool Update(const Event<OctetStringSpec>& evt);

  // ---- function used to select distinct types ----

////    uint32_t SelectByType(EventBinaryVariation variation, uint32_t max);
////    uint32_t SelectByType(EventDoubleBinaryVariation variation, uint32_t max);
////    uint32_t SelectByType(EventAnalogVariation variation, uint32_t max);
////    uint32_t SelectByType(EventCounterVariation variation, uint32_t max);
////    uint32_t SelectByType(EventFrozenCounterVariation variation, uint32_t max);
////    uint32_t SelectByType(EventBinaryOutputStatusVariation variation, uint32_t max);
////    uint32_t SelectByType(EventAnalogOutputStatusVariation variation, uint32_t max);
////    uint32_t SelectByType(EventOctetStringVariation variation, uint32_t max);

////    uint32_t SelectByType(EventType type, uint32_t max);

  // ---- function used to select by event class ----

////    uint32_t SelectByClass(const EventClass& clazz);
////    uint32_t SelectByClass(const EventClass& clazz, uint32_t max);
////
////    uint32_t SelectByClass(const ClassField& clazz);
////    uint32_t SelectByClass(const ClassField& clazz, uint32_t max);
////
////private:
  EventLists state;
} EventStorage;

void EventStorage_in_EventStorage(EventStorage *pEventStorage, EventBufferConfig* config);

boolean Update_OctetStringSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_OctetStringSpec* evt);
boolean Update_AnalogOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogOutputStatusSpec* evt);
boolean Update_BinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinarySpec* evt);
boolean Update_BinaryOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_BinaryOutputStatusSpec* evt);
boolean Update_FrozenCounterSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_FrozenCounterSpec* evt);
boolean Update_CounterSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_CounterSpec* evt);
boolean Update_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, Event_for_AnalogSpec* evt);
boolean Update_DoubleBitBinarySpec_in_EventStorage(EventStorage *pEventStorage, Event_for_DoubleBitBinarySpec* evt);

    uint32_t SelectByType_BinarySpec_in_EventStorage(EventStorage *pEventStorage, EventBinaryVariation_uint8_t variation, uint32_t max);
    uint32_t SelectByType_DoubleBitBinarySpec_in_EventStorage(EventStorage *pEventStorage, EventDoubleBinaryVariation_uint8_t variation, uint32_t max);
    uint32_t SelectByType_AnalogSpec_in_EventStorage(EventStorage *pEventStorage, EventAnalogVariation_uint8_t variation, uint32_t max);
    uint32_t SelectByType_CounterSpec_in_EventStorage(EventStorage *pEventStorage, EventCounterVariation_uint8_t variation, uint32_t max);
    uint32_t SelectByType_FrozenCounterSpec_in_EventStorage(EventStorage *pEventStorage, EventFrozenCounterVariation_uint8_t variation, uint32_t max);
    uint32_t SelectByType_BinaryOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, EventBinaryOutputStatusVariation_uint8_t variation, uint32_t max);
    uint32_t SelectByType_AnalogOutputStatusSpec_in_EventStorage(EventStorage *pEventStorage, EventAnalogOutputStatusVariation_uint8_t variation, uint32_t max);
    uint32_t SelectByType_OctetStringSpec_in_EventStorage(EventStorage *pEventStorage, EventOctetStringVariation_uint8_t variation, uint32_t max);

    uint32_t SelectByType_in_EventStorage(EventStorage *pEventStorage, EventType_uint16_t type, uint32_t max);

    uint32_t SelectByClass_in_EventStorageOver1(EventStorage *pEventStorage, EventClass_uint8_t clazz);
    uint32_t SelectByClass_in_EventStorageOver2(EventStorage *pEventStorage, EventClass_uint8_t clazz, uint32_t max);

    uint32_t SelectByClass_in_EventStorageOver3(EventStorage *pEventStorage, ClassField* clazz);
    uint32_t SelectByClass_in_EventStorageOver4(EventStorage *pEventStorage, ClassField* clazz, uint32_t max);

    uint32_t Write_in_EventStorage(EventStorage *pEventStorage, IEventWriteHandler* handler);

    uint32_t ClearWritten_in_EventStorage(EventStorage *pEventStorage);

    boolean IsAnyTypeFull_in_EventStorage(EventStorage *pEventStorage);

  // number selected
    uint32_t NumSelected_in_EventStorage(EventStorage *pEventStorage);

  // unselected/selected but not already written
    uint32_t NumUnwritten_in_EventStorage(EventStorage *pEventStorage, EventClass_uint8_t clazz);

  // all written and selected events are reverted to unselected state
    void Unselect_in_EventStorage(EventStorage *pEventStorage);

////} // namespace opendnp3

  uint32_t RemoveAll_in_List_for_EventRecord(EventStorage *pEventStorage, 
                            List_for_EventRecord *pList_for_EventRecord, 
                            boolean (*match)(EventStorage *pEventStorage, 
                            EventRecord* record));//const U& match);

#endif
