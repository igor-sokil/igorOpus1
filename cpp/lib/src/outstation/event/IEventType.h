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

#ifndef OPENDNP3_IEVENTTYPE_H
#define OPENDNP3_IEVENTTYPE_H

////#include "List.h"

////#include "opendnp3/app/EventType.h"

#include "EventLists.h"

#include "EventType.h"
//#include "EventLists.h"
#include "EventRecord.h"
#include "IEventWriteHandler.h"
////namespace opendnp3
////{

////class EventLists;
////class IEventWriteHandler;
////class EventRecord;

////class IEventType
typedef struct
{

////public:
    EventType_uint16_t value;

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
     void (*pSelectDefaultVariation_in_IEventType)(void *, EventRecord* record);

////    virtual uint16_t WriteSome(List<EventRecord>::Iterator& iterator,
////                               EventLists& lists,
////                               IEventWriteHandler& handler) const = 0;
     uint16_t (*pWriteSome_in_IEventType)(void *, 
                              Iterator_in_List_for_EventRecord* iterator,
                               EventLists* lists,
                               IEventWriteHandler* handler);// const = 0;

////    virtual void RemoveTypeFromStorage(EventRecord& record, EventLists& lists) const = 0;
     void (*pRemoveTypeFromStorage_in_IEventType)(void *, EventRecord* record, EventLists* lists);// const = 0;

  void* pParentPointer_in_IEventType;
} IEventType;

void SelectDefaultVariation_in_IEventType(IEventType *, EventRecord* record);
uint16_t WriteSome_in_IEventType(IEventType *, 
                              Iterator_in_List_for_EventRecord* iterator,
                               EventLists* lists,
                               IEventWriteHandler* handler);
void RemoveTypeFromStorage_in_IEventType(IEventType *, EventRecord* record, EventLists* lists);

void* getParentPointer_in_IEventType(IEventType*);
void  setParentPointer_in_IEventType(IEventType*, void*);

   void IEventType_in_IEventType(IEventType *pIEventType, EventType_uint16_t value);
   boolean IsEqual_in_IEventType(IEventType* pIEventType, EventType_uint16_t type);
   boolean IsNotEqual_in_IEventType(IEventType* pIEventType, EventType_uint16_t type);

////} // namespace opendnp3

#endif
