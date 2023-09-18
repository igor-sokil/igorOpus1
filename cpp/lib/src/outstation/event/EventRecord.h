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

#ifndef OPENDNP3_EVENTRECORD_H
#define OPENDNP3_EVENTRECORD_H

////#include "EventState.h"
////#include "IEventType.h"

////#include "opendnp3/app/EventType.h"

#include "EventState.h"
//#include "IEventType.h"

#include "EventType.h"

////namespace opendnp3
////{

/**
 * Generic event information with an opaque pointer to
 * the specific event details
* Общая информация о событии с непрозрачным указателем на
  * конкретная информация о мероприятии
 */
////class EventRecord
typedef struct
{

////public:
////    EventRecord() = default;
////    EventRecord(uint16_t index, EventClass clazz);

  uint16_t index;// = 0;
  EventClass_uint8_t clazz;// = EventClass_EC1;
  EventState_uint8_t state;// = EventState_unselected;

  // always set as a unit
//  IEventType* type;//// = nullptr;
  void* type;//// = nullptr;
  void* storage_node;//// = nullptr;
} EventRecord;

void EventRecord_in_EventRecordOver1(EventRecord *pEventRecord);
void EventRecord_in_EventRecordOver2(EventRecord *pEventRecord, uint16_t index, EventClass_uint8_t clazz);

/*
typedef struct
{

////public:
  EventType value;

////    inline bool IsEqual(EventType type) const
////    {
////        return type == value;
////    }

////    inline bool IsNotEqual(EventType type) const
////    {
////        return type != value;
////    }

////protected:
////    IEventType(EventType value) : value(value) {}

////public:
////    virtual void SelectDefaultVariation(EventRecord& record) const = 0;
  void (*pSelectDefaultVariation)(EventRecord* record);

////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const = 0;
//     uint16_t (*pWriteSome)(Iterator_in_List_for_EventRecord* iterator,
//                               EventLists* lists,
//                               IEventWriteHandler* handler);// const = 0;

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const = 0;
//     void (*pRemoveTypeFromStorage)(EventRecord* record, EventLists* lists);// const = 0;
} IEventType;
*/
////} // namespace opendnp3

#endif
