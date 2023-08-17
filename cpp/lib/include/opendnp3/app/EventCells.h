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
#ifndef OPENDNP3_EVENTCELLS_H
#define OPENDNP3_EVENTCELLS_H

////#include "opendnp3/app/EventType.h"
////#include "opendnp3/gen/PointClass.h"
#include "EventType.h"
#include "PointClass.h"

////namespace opendnp3
////{

/// A null object for types that have no metadata
////struct EmptyEventCell
//typedef struct
//{
//} EmptyEventCell;

/// Base class for different types of event metadata
////template<class Spec> struct EventCellBase
////{
////    PointClass clazz;
////    typename Spec::meas_t lastEvent;
////    typename Spec::event_variation_t evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
////};
//---------------------------------Analog---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  Analog lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_AnalogInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_Analog;
void EventCellBase_for_Analog_in_EventCellBase_for_Analog(EventCellBase_for_Analog *pEventCellBase_for_Analog);
void SetEventValue_in_EventCellBase_for_Analog(EventCellBase_for_Analog *pEventCellBase_for_Analog, Analog* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_Analog eEventCellBase_for_Analog;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_Analog;
void SimpleEventCell_for_Analog_in_SimpleEventCell_for_Analog(SimpleEventCell_for_Analog *pSimpleEventCell_for_Analog);

boolean IsEvent_in_SimpleEventCell_for_Analog(SimpleEventCell_for_Analog *pSimpleEventCell_for_Analog,
    AnalogConfig *config,
    Analog* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_Analog sSimpleEventCell_for_Analog;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_Analog;
void DeadbandEventCell_for_Analog_in_DeadbandEventCell_for_Analog(DeadbandEventCell_for_Analog *pDeadbandEventCell_for_Analog);

boolean IsEvent_in_DeadbandEventCell_for_Analog(DeadbandEventCell_for_Analog *pDeadbandEventCell_for_Analog,
    AnalogConfig *config,
    Analog* newValue);

//---------------------------------Analog---------------------------------------
//---------------------------------Binary---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  Binary lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_BinaryInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_Binary;
void EventCellBase_for_Binary_in_EventCellBase_for_Binary(EventCellBase_for_Binary *pEventCellBase_for_Binary);
void SetEventValue_in_EventCellBase_for_Binary(EventCellBase_for_Binary *pEventCellBase_for_Binary, Binary* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_Binary eEventCellBase_for_Binary;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_Binary;
void SimpleEventCell_for_Binary_in_SimpleEventCell_for_Binary(SimpleEventCell_for_Binary *pSimpleEventCell_for_Binary);
//void SimpleEventCell_for_Binary_in_SimpleEventCell_for_Binary(SimpleEventCell_for_Binary *pSimpleEventCell_for_Binary)
//{
//  EventCellBase_for_Binary_in_EventCellBase_for_Binary(&(pSimpleEventCell_for_Binary->eEventCellBase_for_Binary));
//}

boolean IsEvent_in_SimpleEventCell_for_Binary(SimpleEventCell_for_Binary *pSimpleEventCell_for_Binary,
    BinaryConfig *config,
    Binary* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_Binary sSimpleEventCell_for_Binary;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_Binary;

void DeadbandEventCell_for_Binary_in_DeadbandEventCell_for_Binary(DeadbandEventCell_for_Binary *pDeadbandEventCell_for_Binary);
//void DeadbandEventCell_for_Binary_in_DeadbandEventCell_for_Binary(DeadbandEventCell_for_Binary *pDeadbandEventCell_for_Binary)
//{
//  SimpleEventCell_for_Binary_in_SimpleEventCell_for_Binary(&(pDeadbandEventCell_for_Binary->sSimpleEventCell_for_Binary));
//}

boolean IsEvent_in_DeadbandEventCell_for_Binary(DeadbandEventCell_for_Binary *pDeadbandEventCell_for_Binary,
    BinaryConfig *config,
    Binary* newValue);

//---------------------------------Binary---------------------------------------
//---------------------------------DoubleBitBinary---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  DoubleBitBinary lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_DoubleBitBinaryInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_DoubleBitBinary;
void EventCellBase_for_DoubleBitBinary_in_EventCellBase_for_DoubleBitBinary(EventCellBase_for_DoubleBitBinary *pEventCellBase_for_DoubleBitBinary);
void SetEventValue_in_EventCellBase_for_DoubleBitBinary(EventCellBase_for_DoubleBitBinary *pEventCellBase_for_DoubleBitBinary, DoubleBitBinary* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_DoubleBitBinary eEventCellBase_for_DoubleBitBinary;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_DoubleBitBinary;
void SimpleEventCell_for_DoubleBitBinary_in_SimpleEventCell_for_DoubleBitBinary(SimpleEventCell_for_DoubleBitBinary *pSimpleEventCell_for_DoubleBitBinary);

boolean IsEvent_in_SimpleEventCell_for_DoubleBitBinary(SimpleEventCell_for_DoubleBitBinary *pSimpleEventCell_for_DoubleBitBinary,
    DoubleBitBinaryConfig *config,
    DoubleBitBinary* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_DoubleBitBinary sSimpleEventCell_for_DoubleBitBinary;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_DoubleBitBinary;
void DeadbandEventCell_for_DoubleBitBinary_in_DeadbandEventCell_for_DoubleBitBinary(DeadbandEventCell_for_DoubleBitBinary *pDeadbandEventCell_for_DoubleBitBinary);

boolean IsEvent_in_DeadbandEventCell_for_DoubleBitBinary(DeadbandEventCell_for_DoubleBitBinary *pDeadbandEventCell_for_DoubleBitBinary,
    DoubleBitBinaryConfig *config,
    DoubleBitBinary* newValue);

//---------------------------------DoubleBitBinary---------------------------------------
//---------------------------------Counter---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  Counter lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_CounterInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_Counter;
void EventCellBase_for_Counter_in_EventCellBase_for_Counter(EventCellBase_for_Counter *pEventCellBase_for_Counter);
void SetEventValue_in_EventCellBase_for_Counter(EventCellBase_for_Counter *pEventCellBase_for_Counter, Counter* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_Counter eEventCellBase_for_Counter;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_Counter;
void SimpleEventCell_for_Counter_in_SimpleEventCell_for_Counter(SimpleEventCell_for_Counter *pSimpleEventCell_for_Counter);

boolean IsEvent_in_SimpleEventCell_for_Counter(SimpleEventCell_for_Counter *pSimpleEventCell_for_Counter,
    CounterConfig *config,
    Counter* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_Counter sSimpleEventCell_for_Counter;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_Counter;
void DeadbandEventCell_for_Counter_in_DeadbandEventCell_for_Counter(DeadbandEventCell_for_Counter *pDeadbandEventCell_for_Counter);

boolean IsEvent_in_DeadbandEventCell_for_Counter(DeadbandEventCell_for_Counter *pDeadbandEventCell_for_Counter,
    CounterConfig *config,
    Counter* newValue);

//---------------------------------Counter---------------------------------------
//---------------------------------FrozenCounter---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  FrozenCounter lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_FrozenCounterInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_FrozenCounter;
void EventCellBase_for_FrozenCounter_in_EventCellBase_for_FrozenCounter(EventCellBase_for_FrozenCounter *pEventCellBase_for_FrozenCounter);
void SetEventValue_in_EventCellBase_for_FrozenCounter(EventCellBase_for_FrozenCounter *pEventCellBase_for_FrozenCounter, FrozenCounter* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_FrozenCounter eEventCellBase_for_FrozenCounter;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_FrozenCounter;
void SimpleEventCell_for_FrozenCounter_in_SimpleEventCell_for_FrozenCounter(SimpleEventCell_for_FrozenCounter *pSimpleEventCell_for_FrozenCounter);

boolean IsEvent_in_SimpleEventCell_for_FrozenCounter(SimpleEventCell_for_FrozenCounter *pSimpleEventCell_for_FrozenCounter,
    FrozenCounterConfig *config,
    FrozenCounter* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_FrozenCounter sSimpleEventCell_for_FrozenCounter;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_FrozenCounter;
void DeadbandEventCell_for_FrozenCounter_in_DeadbandEventCell_for_FrozenCounter(DeadbandEventCell_for_FrozenCounter *pDeadbandEventCell_for_FrozenCounter);

boolean IsEvent_in_DeadbandEventCell_for_FrozenCounter(DeadbandEventCell_for_FrozenCounter *pDeadbandEventCell_for_FrozenCounter,
    FrozenCounterConfig *config,
    FrozenCounter* newValue);

//---------------------------------FrozenCounter---------------------------------------
//---------------------------------BinaryOutputStatus---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  BinaryOutputStatus lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_BinaryOutputStatusInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_BinaryOutputStatus;
void EventCellBase_for_BinaryOutputStatus_in_EventCellBase_for_BinaryOutputStatus(EventCellBase_for_BinaryOutputStatus *pEventCellBase_for_BinaryOutputStatus);
void SetEventValue_in_EventCellBase_for_BinaryOutputStatus(EventCellBase_for_BinaryOutputStatus *pEventCellBase_for_BinaryOutputStatus, BinaryOutputStatus* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_BinaryOutputStatus eEventCellBase_for_BinaryOutputStatus;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_BinaryOutputStatus;
void SimpleEventCell_for_BinaryOutputStatus_in_SimpleEventCell_for_BinaryOutputStatus(SimpleEventCell_for_BinaryOutputStatus *pSimpleEventCell_for_BinaryOutputStatus);

boolean IsEvent_in_SimpleEventCell_for_BinaryOutputStatus(SimpleEventCell_for_BinaryOutputStatus *pSimpleEventCell_for_BinaryOutputStatus,
    BOStatusConfig *config,
    BinaryOutputStatus* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_BinaryOutputStatus sSimpleEventCell_for_BinaryOutputStatus;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_BinaryOutputStatus;
void DeadbandEventCell_for_BinaryOutputStatus_in_DeadbandEventCell_for_BinaryOutputStatus(DeadbandEventCell_for_BinaryOutputStatus *pDeadbandEventCell_for_BinaryOutputStatus);

boolean IsEvent_in_DeadbandEventCell_for_BinaryOutputStatus(DeadbandEventCell_for_BinaryOutputStatus *pDeadbandEventCell_for_BinaryOutputStatus,
    BOStatusConfig *config,
    BinaryOutputStatus* newValue);

//---------------------------------BinaryOutputStatus---------------------------------------
//---------------------------------AnalogOutputStatus---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  AnalogOutputStatus lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_AnalogOutputStatusInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_AnalogOutputStatus;
void EventCellBase_for_AnalogOutputStatus_in_EventCellBase_for_AnalogOutputStatus(EventCellBase_for_AnalogOutputStatus *pEventCellBase_for_AnalogOutputStatus);
void SetEventValue_in_EventCellBase_for_AnalogOutputStatus(EventCellBase_for_AnalogOutputStatus *pEventCellBase_for_AnalogOutputStatus, AnalogOutputStatus* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_AnalogOutputStatus eEventCellBase_for_AnalogOutputStatus;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_AnalogOutputStatus;
void SimpleEventCell_for_AnalogOutputStatus_in_SimpleEventCell_for_AnalogOutputStatus(SimpleEventCell_for_AnalogOutputStatus *pSimpleEventCell_for_AnalogOutputStatus);

boolean IsEvent_in_SimpleEventCell_for_AnalogOutputStatus(SimpleEventCell_for_AnalogOutputStatus *pSimpleEventCell_for_AnalogOutputStatus,
    AOStatusConfig *config,
    AnalogOutputStatus* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_AnalogOutputStatus sSimpleEventCell_for_AnalogOutputStatus;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_AnalogOutputStatus;
void DeadbandEventCell_for_AnalogOutputStatus_in_DeadbandEventCell_for_AnalogOutputStatus(DeadbandEventCell_for_AnalogOutputStatus *pDeadbandEventCell_for_AnalogOutputStatus);

boolean IsEvent_in_DeadbandEventCell_for_AnalogOutputStatus(DeadbandEventCell_for_AnalogOutputStatus *pDeadbandEventCell_for_AnalogOutputStatus,
    AOStatusConfig *config,
    AnalogOutputStatus* newValue);

//---------------------------------AnalogOutputStatus---------------------------------------
//---------------------------------OctetString---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  OctetString lastEvent;
////    typename Spec::event_variation_t evariation;
  event_variation_t_in_OctetStringInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_OctetString;
void EventCellBase_for_OctetString_in_EventCellBase_for_OctetString(EventCellBase_for_OctetString *pEventCellBase_for_OctetString);
void SetEventValue_in_EventCellBase_for_OctetString(EventCellBase_for_OctetString *pEventCellBase_for_OctetString, OctetString* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_OctetString eEventCellBase_for_OctetString;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_OctetString;
void SimpleEventCell_for_OctetString_in_SimpleEventCell_for_OctetString(SimpleEventCell_for_OctetString *pSimpleEventCell_for_OctetString);

boolean IsEvent_in_SimpleEventCell_for_OctetString(SimpleEventCell_for_OctetString *pSimpleEventCell_for_OctetString,
    OctetStringConfig *config,
    OctetString* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_OctetString sSimpleEventCell_for_OctetString;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_OctetString;
void DeadbandEventCell_for_OctetString_in_DeadbandEventCell_for_OctetString(DeadbandEventCell_for_OctetString *pDeadbandEventCell_for_OctetString);

boolean IsEvent_in_DeadbandEventCell_for_OctetString(DeadbandEventCell_for_OctetString *pDeadbandEventCell_for_OctetString,
    OctetStringConfig *config,
    OctetString* newValue);

//---------------------------------OctetString---------------------------------------
//---------------------------------TimeAndInterval---------------------------------------
////template<class Spec> struct EventCellBase
typedef struct
{
  PointClass_uint8_t clazz;
////    typename Spec::meas_t lastEvent;
  TimeAndInterval lastEvent;
////    typename Spec::event_variation_t evariation;
//  event_variation_t_in_TimeAndIntervalInfo evariation;

////    void SetEventValue(const typename Spec::meas_t& value)
////    {
////        lastEvent = value;
////    }

////protected:
////    EventCellBase() : clazz(PointClass::Class1), lastEvent(), evariation(Spec::DefaultEventVariation) {}
} EventCellBase_for_TimeAndInterval;
void EventCellBase_for_TimeAndInterval_in_EventCellBase_for_TimeAndInterval(EventCellBase_for_TimeAndInterval *pEventCellBase_for_TimeAndInterval);
void SetEventValue_in_EventCellBase_for_TimeAndInterval(EventCellBase_for_TimeAndInterval *pEventCellBase_for_TimeAndInterval, TimeAndInterval* value);

/// Metatype w/o a deadband
////template<class Spec> struct SimpleEventCell : EventCellBase<Spec>
typedef struct
{
  EventCellBase_for_TimeAndInterval eEventCellBase_for_TimeAndInterval;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue);
////    }
} SimpleEventCell_for_TimeAndInterval;
void SimpleEventCell_for_TimeAndInterval_in_SimpleEventCell_for_TimeAndInterval(SimpleEventCell_for_TimeAndInterval *pSimpleEventCell_for_TimeAndInterval);

boolean IsEvent_in_SimpleEventCell_for_TimeAndInterval(SimpleEventCell_for_TimeAndInterval *pSimpleEventCell_for_TimeAndInterval,
    TimeAndIntervalConfig *config,
    TimeAndInterval* newValue);

/// Structure for holding metadata information on points that have support deadbanding
////template<class Spec> struct DeadbandEventCell : SimpleEventCell<Spec>
typedef struct
{
  SimpleEventCell_for_TimeAndInterval sSimpleEventCell_for_TimeAndInterval;
////    bool IsEvent(const typename Spec::config_t& config, const typename Spec::meas_t& newValue) const
////    {
////        return Spec::IsEvent(this->lastEvent, newValue, config.deadband);
////    }
} DeadbandEventCell_for_TimeAndInterval;
void DeadbandEventCell_for_TimeAndInterval_in_DeadbandEventCell_for_TimeAndInterval(DeadbandEventCell_for_TimeAndInterval *pDeadbandEventCell_for_TimeAndInterval);

boolean IsEvent_in_DeadbandEventCell_for_TimeAndInterval(DeadbandEventCell_for_TimeAndInterval *pDeadbandEventCell_for_TimeAndInterval,
    TimeAndIntervalConfig *config,
    TimeAndInterval* newValue);

//---------------------------------TimeAndInterval---------------------------------------

////} // namespace opendnp3

#endif
