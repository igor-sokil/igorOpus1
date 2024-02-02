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
#ifndef OPENDNP3_EVENTBUFFER_H
#define OPENDNP3_EVENTBUFFER_H

////#include "EventStorage.h"
////#include "outstation/IEventReceiver.h"
////#include "outstation/IEventSelector.h"
////#include "outstation/IResponseLoader.h"

////#include "opendnp3/app/ClassField.h"
////#include "opendnp3/outstation/EventBufferConfig.h"

#include "EventStorage.h"
#include "IEventReceiver.h"
#include "IEventSelector.h"
#include "IResponseLoader.h"

#include "ClassField.h"
#include "EventBufferConfig.h"

////namespace opendnp3
////{

/*
    The sequence of events list is a doubly linked-list implemented
    in a finite array.  The list is desired for O(1) remove operations from
    arbitrary parts of the list depending on what the user asks for in terms
    of event type or Class1/2/3.

    At worst, selection is O(n) but it has some type/class tracking to avoid looping
    over the SOE list when there are no more events to be written.
Список последовательности событий представляет собой реализованный двусвязный список.
     в конечном массиве. Список необходим для O(1) операций удаления из
     произвольные части списка в зависимости от того, что запрашивает пользователь в терминах
     типа события или класса 1/2/3.

     В худшем случае выбор равен O(n), но он имеет некоторое отслеживание типов/классов, чтобы избежать зацикливания.
     над списком SOE, когда больше нет событий для записи.
*/

////class EventBuffer final : public IEventReceiver, public IEventSelector, public IResponseLoader
typedef struct
{
  IEventReceiver iIEventReceiver;
  IEventSelector iIEventSelector;
  IResponseLoader iIResponseLoader;
////public:
////    explicit EventBuffer(const EventBufferConfig& config);

  // ------- IEventReceiver ------

////    virtual void Update(const Event<BinarySpec>& evt) override;
////    virtual void Update(const Event<DoubleBitBinarySpec>& evt) override;
////    virtual void Update(const Event<AnalogSpec>& evt) override;
////    virtual void Update(const Event<CounterSpec>& evt) override;
////    virtual void Update(const Event<FrozenCounterSpec>& evt) override;
////    virtual void Update(const Event<BinaryOutputStatusSpec>& evt) override;
////    virtual void Update(const Event<AnalogOutputStatusSpec>& evt) override;
////    virtual void Update(const Event<OctetStringSpec>& evt) override;

  // ------- IEventSelector ------

////    virtual void Unselect();
//     void (*pUnselect_in_EventBuffer)(void*);

////    virtual IINField SelectAll(GroupVariation gv) override final;

////    virtual IINField SelectCount(GroupVariation gv, uint16_t count) override final;

  // ------- IResponseLoader -------

////    virtual bool HasAnySelection() const override final;

////    virtual bool Load(HeaderWriter& writer) override final;

  // ------- Misc -------

////    void ClearWritten(); // called when a transmission succeeds

////    ClassField UnwrittenClassField() const;

////    bool IsOverflown();

////    void SelectAllByClass(const ClassField& clazz);

////    uint32_t NumEvents(EventClass ec) const;


////private:
  boolean overflow;// = false;
  EventStorage storage;

////    IINField SelectMaxCount(GroupVariation gv, uint32_t maximum);

////    template<class T> IINField SelectByType(uint32_t max, T type)
////    {
////        this->storage.SelectByType(type, max);
////        return IINField::Empty();
////    }

////    template<class T> void UpdateAny(const Event<T>& evt)
////    {
////        if (this->storage.Update(evt))
////        {
////            this->overflow = true;
////        }
////    }

////    IINField SelectByClass(uint32_t max, EventClass clazz)
////    {
////        this->storage.SelectByClass(clazz, max);
////        return IINField::Empty();
////    }
} EventBuffer;

void EventBuffer_in_EventBufferOver1(EventBuffer *pEventBuffer);
void EventBuffer_in_EventBufferOver2(EventBuffer *pEventBuffer, EventBufferConfig* config);
void UpdateAny_BinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinarySpec *evt);
void UpdateAny_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_DoubleBitBinarySpec *evt);
void UpdateAny_AnalogSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogSpec *evt);
void UpdateAny_CounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_CounterSpec *evt);
void UpdateAny_FrozenCounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_FrozenCounterSpec *evt);
void UpdateAny_BinaryOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinaryOutputStatusSpec *evt);
void UpdateAny_AnalogOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogOutputStatusSpec *evt);
void UpdateAny_OctetStringSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_OctetStringSpec *evt);

IINField  SelectByType_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventType_uint16_t type);
IINField  SelectByType_BinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventBinaryVariation_uint8_t type);
IINField  SelectByType_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventDoubleBinaryVariation_uint8_t type);
IINField  SelectByType_AnalogSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventAnalogVariation_uint8_t type);
IINField  SelectByType_CounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventCounterVariation_uint8_t type);
IINField  SelectByType_FrozenCounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventFrozenCounterVariation_uint8_t type);
IINField  SelectByType_BinaryOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventBinaryOutputStatusVariation_uint8_t type);
IINField  SelectByType_AnalogOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventAnalogOutputStatusVariation_uint8_t type);
IINField  SelectByType_OctetStringSpec_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventOctetStringVariation_uint8_t type);

IINField SelectByClass_EventClass_in_EventBuffer(EventBuffer *pEventBuffer, uint32_t max, EventClass_uint8_t clazz);

// ------- IEventReceiver ------

void Update_BinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinarySpec *evt);
void Update_DoubleBitBinarySpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_DoubleBitBinarySpec* evt);
void Update_AnalogSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogSpec* evt);
void Update_CounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_CounterSpec* evt);
void Update_FrozenCounterSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_FrozenCounterSpec* evt);
void Update_BinaryOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_BinaryOutputStatusSpec* evt);
void Update_AnalogOutputStatusSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_AnalogOutputStatusSpec* evt);
void Update_OctetStringSpec_in_EventBuffer(EventBuffer *pEventBuffer, Event_for_OctetStringSpec* evt);

void Update_BinarySpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_BinarySpec *evt);
void Update_DoubleBitBinarySpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_DoubleBitBinarySpec* evt);
void Update_AnalogSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_AnalogSpec* evt);
void Update_CounterSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_CounterSpec* evt);
void Update_FrozenCounterSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_FrozenCounterSpec* evt);
void Update_BinaryOutputStatusSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_BinaryOutputStatusSpec* evt);
void Update_AnalogOutputStatusSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_AnalogOutputStatusSpec* evt);
void Update_OctetStringSpec_in_EventBuffer_override(void *pIEventReceiver, Event_for_OctetStringSpec* evt);

// ------- IEventSelector ------

void Unselect_in_EventBuffer(EventBuffer *pEventBuffer);
IINField SelectAll_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint16_t gv);
IINField SelectCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint16_t gv, uint16_t count);

void Unselect_in_EventBuffer_override(void *pIEventSelector);
IINField SelectAll_in_EventBuffer_override(void *pIEventSelector, GroupVariation_uint16_t gv);
IINField SelectCount_in_EventBuffer_override(void *pIEventSelector, GroupVariation_uint16_t gv, uint16_t count);

// ------- IResponseLoader -------

boolean HasAnySelection_in_EventBuffer(EventBuffer *pEventBuffer);
boolean Load_in_EventBuffer(EventBuffer *pEventBuffer, HeaderWriter* writer);

boolean HasAnySelection_in_EventBuffer_override(void *pIResponseLoader);
boolean Load_in_EventBuffer_override(void *pIResponseLoader, HeaderWriter* writer);

// ------- Misc -------

void ClearWritten_in_EventBuffer(EventBuffer *pEventBuffer); // called when a transmission succeeds

ClassField UnwrittenClassField_in_EventBuffer(EventBuffer *pEventBuffer);

boolean IsOverflown_in_EventBuffer(EventBuffer *pEventBuffer);

void SelectAllByClass_in_EventBuffer(EventBuffer *pEventBuffer, ClassField* clazz);

uint32_t NumEvents_in_EventBuffer(EventBuffer *pEventBuffer, EventClass_uint8_t ec);

IINField SelectMaxCount_in_EventBuffer(EventBuffer *pEventBuffer, GroupVariation_uint16_t gv, uint32_t maximum);

////} // namespace opendnp3

#endif
