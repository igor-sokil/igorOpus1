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

boolean IsEvent_in_SimpleEventCell_for_Analog(SimpleEventCell_for_Analog *pSimpleEventCell_for_Analog,
    AnalogConfig_for_DeadbandConfig_for_AnalogInfo *config,
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

boolean IsEvent_in_DeadbandEventCell_for_Analog(DeadbandEventCell_for_Analog *pDeadbandEventCell_for_Analog,
    AnalogConfig_for_DeadbandConfig_for_AnalogInfo *config,
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

boolean IsEvent_in_SimpleEventCell_for_Binary(SimpleEventCell_for_Binary *pSimpleEventCell_for_Binary,
    BinaryConfig_for_EventConfig_for_BinaryInfo *config,
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

boolean IsEvent_in_DeadbandEventCell_for_Binary(DeadbandEventCell_for_Binary *pDeadbandEventCell_for_Binary,
    BinaryConfig_for_EventConfig_for_BinaryInfo *config,
    Binary* newValue);

//---------------------------------Binary---------------------------------------

////} // namespace opendnp3

#endif
