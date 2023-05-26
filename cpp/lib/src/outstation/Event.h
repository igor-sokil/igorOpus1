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
#ifndef OPENDNP3_EVENT_H
#define OPENDNP3_EVENT_H

////#include "opendnp3/app/EventType.h"
#include "EventType.h"
#include "MeasurementInfo.h"

////namespace opendnp3
////{

typedef struct////struct Evented
{
////    Evented(uint16_t index, EventClass clazz) : index(index), clazz(clazz) {}

////    Evented() : clazz(EventClass::EC1) {}

    uint16_t index;//// = 0;
    EventClass_uint8_t clazz; // class of the event (CLASS<1-3>)
} Evented;
   void Evented_in_EventedOver2(Evented *pEvented, uint16_t index, EventClass_uint8_t clazz);
   void Evented_in_EventedOver1(Evented *pEvented);



/**
 * Record of an event that includes value, index, and class
 */
////template<typename Spec> struct Event : public Evented
////{
////    typedef typename Spec::meas_t meas_type_t;

////    Event(const meas_type_t& value, uint16_t index, EventClass clazz, typename Spec::event_variation_t variation)
////        : Evented(index, clazz), value(value), variation(variation)
////    {
////    }
////
////    Event() : Evented(), value(), variation() {}
////
////    meas_type_t value;
////    typename Spec::event_variation_t variation;
////};
//--------------------------------BinarySpec-------------------------
////template<typename Spec> struct Event : public Evented
typedef struct
{
    Evented eEvented;
#define meas_type_t_in_EventBinarySpec  meas_t_in_BinarySpec 
////    typedef typename Spec::meas_t meas_type_t;

//#define event_variation_t_in_BinaryInfo  EventBinaryVariation_uint8_t

////    Event() : Evented(), value(), variation() {}
////
////    meas_type_t value;
        Binary bBinary;
////    typename Spec::event_variation_t variation;
        event_variation_t_in_BinaryInfo variation;
} Event_for_BinarySpec;
   void Event_for_BinarySpec_in_Event_for_BinarySpec(Event_for_BinarySpec *pEvent_for_BinarySpec,
                                                  Binary* value, uint16_t index,
                                                  EventClass_uint8_t clazz,
                                                  event_variation_t_in_BinaryInfo variation);

//--------------------------------BinarySpec-------------------------

////} // namespace opendnp3

#endif
