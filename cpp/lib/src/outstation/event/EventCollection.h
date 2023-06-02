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
#ifndef OPENDNP3_EVENTCOLLECTION_H
#define OPENDNP3_EVENTCOLLECTION_H

////#include "EventWriting.h"
////#include "IEventWriteHandler.h"
////#include "TypedStorage.h"

#include "EventWriting.h"
#include "TypedStorage.h"
#include "IEventWriteHandler.h"
#include "MeasurementTypes.h"

////namespace opendnp3
////{
//---------------------------------Binary------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_Binary iIEventCollection_for_Binary;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_BinaryInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_Binary;

void  EventCollection_for_Binary_in_EventCollection_for_Binary(EventCollection_for_Binary *pEventCollection_for_Binary,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_BinaryInfo variation);
uint16_t WriteSome_in_EventCollection_for_Binary(/*EventCollection_for_Binary*/void *pEventCollection_for_Binary, IEventWriter_for_Binary* writer);
boolean WriteOne_in_EventCollection_for_Binary(EventCollection_for_Binary *pEventCollection_for_Binary, IEventWriter_for_Binary* writer);
//---------------------------------Binary------------------------------------------
//---------------------------------DoubleBitBinary------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_DoubleBitBinary iIEventCollection_for_DoubleBitBinary;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_DoubleBitBinaryInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_DoubleBitBinary;

void  EventCollection_for_DoubleBitBinary_in_EventCollection_for_DoubleBitBinary(EventCollection_for_DoubleBitBinary *pEventCollection_for_DoubleBitBinary,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_DoubleBitBinaryInfo variation);
uint16_t WriteSome_in_EventCollection_for_DoubleBitBinary(/*EventCollection_for_DoubleBitBinary*/void *pEventCollection_for_DoubleBitBinary, IEventWriter_for_DoubleBitBinary* writer);
boolean WriteOne_in_EventCollection_for_DoubleBitBinary(EventCollection_for_DoubleBitBinary *pEventCollection_for_DoubleBitBinary, IEventWriter_for_DoubleBitBinary* writer);
//---------------------------------DoubleBitBinary------------------------------------------
//---------------------------------Analog------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_Analog iIEventCollection_for_Analog;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_AnalogInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_Analog;

void  EventCollection_for_Analog_in_EventCollection_for_Analog(EventCollection_for_Analog *pEventCollection_for_Analog,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_AnalogInfo variation);
uint16_t WriteSome_in_EventCollection_for_Analog(/*EventCollection_for_Analog*/void *pEventCollection_for_Analog, IEventWriter_for_Analog* writer);
boolean WriteOne_in_EventCollection_for_Analog(EventCollection_for_Analog *pEventCollection_for_Analog, IEventWriter_for_Analog* writer);
//---------------------------------Analog------------------------------------------
//---------------------------------Counter------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_Counter iIEventCollection_for_Counter;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_CounterInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_Counter;

void  EventCollection_for_Counter_in_EventCollection_for_Counter(EventCollection_for_Counter *pEventCollection_for_Counter,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_CounterInfo variation);
uint16_t WriteSome_in_EventCollection_for_Counter(/*EventCollection_for_Counter*/void *pEventCollection_for_Counter, IEventWriter_for_Counter* writer);
boolean WriteOne_in_EventCollection_for_Counter(EventCollection_for_Counter *pEventCollection_for_Counter, IEventWriter_for_Counter* writer);
//---------------------------------Counter------------------------------------------
//---------------------------------FrozenCounter------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_FrozenCounter iIEventCollection_for_FrozenCounter;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_FrozenCounterInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_FrozenCounter;

void  EventCollection_for_FrozenCounter_in_EventCollection_for_FrozenCounter(EventCollection_for_FrozenCounter *pEventCollection_for_FrozenCounter,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_FrozenCounterInfo variation);
uint16_t WriteSome_in_EventCollection_for_FrozenCounter(/*EventCollection_for_FrozenCounter*/void *pEventCollection_for_FrozenCounter, IEventWriter_for_FrozenCounter* writer);
boolean WriteOne_in_EventCollection_for_FrozenCounter(EventCollection_for_FrozenCounter *pEventCollection_for_FrozenCounter, IEventWriter_for_FrozenCounter* writer);
//---------------------------------FrozenCounter------------------------------------------
//---------------------------------BinaryOutputStatus------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_BinaryOutputStatus iIEventCollection_for_BinaryOutputStatus;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_BinaryOutputStatusInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_BinaryOutputStatus;

void  EventCollection_for_BinaryOutputStatus_in_EventCollection_for_BinaryOutputStatus(EventCollection_for_BinaryOutputStatus *pEventCollection_for_BinaryOutputStatus,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_BinaryOutputStatusInfo variation);
uint16_t WriteSome_in_EventCollection_for_BinaryOutputStatus(/*EventCollection_for_BinaryOutputStatus*/void *pEventCollection_for_BinaryOutputStatus, IEventWriter_for_BinaryOutputStatus* writer);
boolean WriteOne_in_EventCollection_for_BinaryOutputStatus(EventCollection_for_BinaryOutputStatus *pEventCollection_for_BinaryOutputStatus, IEventWriter_for_BinaryOutputStatus* writer);
//---------------------------------BinaryOutputStatus------------------------------------------
//---------------------------------AnalogOutputStatus------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_AnalogOutputStatus iIEventCollection_for_AnalogOutputStatus;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_AnalogOutputStatusInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_AnalogOutputStatus;

void  EventCollection_for_AnalogOutputStatus_in_EventCollection_for_AnalogOutputStatus(EventCollection_for_AnalogOutputStatus *pEventCollection_for_AnalogOutputStatus,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_AnalogOutputStatusInfo variation);
uint16_t WriteSome_in_EventCollection_for_AnalogOutputStatus(/*EventCollection_for_AnalogOutputStatus*/void *pEventCollection_for_AnalogOutputStatus, IEventWriter_for_AnalogOutputStatus* writer);
boolean WriteOne_in_EventCollection_for_AnalogOutputStatus(EventCollection_for_AnalogOutputStatus *pEventCollection_for_AnalogOutputStatus, IEventWriter_for_AnalogOutputStatus* writer);
//---------------------------------AnalogOutputStatus------------------------------------------
//---------------------------------OctetString------------------------------------------
////template<class T> class EventCollection final : public IEventCollection<typename T::meas_t>
typedef struct
{
  IEventCollection_for_OctetString iIEventCollection_for_OctetString;
////private:
////    List<EventRecord>::Iterator& iterator;
  Iterator_in_List_for_EventRecord* iteratorEv;
////    EventClassCounters& counters;
  EventClassCounters* counters;
////    typename T::event_variation_t variation;
  event_variation_t_in_OctetStringInfo variation;

////public:
////    EventCollection(List<EventRecord>::Iterator& iterator,
////                    EventClassCounters& counters,
////                    typename T::event_variation_t variation)
////        : iterator(iterator), counters(counters), variation(variation)
////    {
////    }
////
////    virtual uint16_t WriteSome(IEventWriter<typename T::meas_t>& writer) override;
////
////private:
////    bool WriteOne(IEventWriter<typename T::meas_t>& writer);
} EventCollection_for_OctetString;

void  EventCollection_for_OctetString_in_EventCollection_for_OctetString(EventCollection_for_OctetString *pEventCollection_for_OctetString,
    Iterator_in_List_for_EventRecord* iteratorEv,
    EventClassCounters* counters,
    event_variation_t_in_OctetStringInfo variation);
uint16_t WriteSome_in_EventCollection_for_OctetString(/*EventCollection_for_OctetString*/void *pEventCollection_for_OctetString, IEventWriter_for_OctetString* writer);
boolean WriteOne_in_EventCollection_for_OctetString(EventCollection_for_OctetString *pEventCollection_for_OctetString, IEventWriter_for_OctetString* writer);
//---------------------------------OctetString------------------------------------------

////} // namespace opendnp3

#endif
