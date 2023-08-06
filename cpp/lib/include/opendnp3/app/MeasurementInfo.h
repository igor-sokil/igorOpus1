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
#ifndef OPENDNP3_MEASUREMENTINFO_H
#define OPENDNP3_MEASUREMENTINFO_H

////#include "opendnp3/app/EventType.h"
////#include "opendnp3/app/MeasurementTypes.h"
////#include "opendnp3/app/OctetString.h"
////#include "opendnp3/gen/BinaryQuality.h"
////#include "opendnp3/gen/EventAnalogOutputStatusVariation.h"
////#include "opendnp3/gen/EventAnalogVariation.h"
////#include "opendnp3/gen/EventBinaryOutputStatusVariation.h"
////#include "opendnp3/gen/EventBinaryVariation.h"
////#include "opendnp3/gen/EventCounterVariation.h"
////#include "opendnp3/gen/EventDoubleBinaryVariation.h"
////#include "opendnp3/gen/EventFrozenCounterVariation.h"
////#include "opendnp3/gen/EventOctetStringVariation.h"
////#include "opendnp3/gen/EventSecurityStatVariation.h"
////#include "opendnp3/gen/StaticAnalogOutputStatusVariation.h"
////#include "opendnp3/gen/StaticAnalogVariation.h"
////#include "opendnp3/gen/StaticBinaryOutputStatusVariation.h"
////#include "opendnp3/gen/StaticBinaryVariation.h"
////#include "opendnp3/gen/StaticCounterVariation.h"
////#include "opendnp3/gen/StaticDoubleBinaryVariation.h"
////#include "opendnp3/gen/StaticFrozenCounterVariation.h"
////#include "opendnp3/gen/StaticOctetStringVariation.h"
////#include "opendnp3/gen/StaticSecurityStatVariation.h"
////#include "opendnp3/gen/StaticTimeAndIntervalVariation.h"
////#include "opendnp3/gen/StaticTypeBitmask.h"
////#include "opendnp3/util/StaticOnly.h"

#include "EventType.h"
#include "MeasurementTypes.h"
#include "OctetString.h"
#include "BinaryQuality.h"
#include "EventAnalogOutputStatusVariation.h"
#include "EventAnalogVariation.h"
#include "EventBinaryOutputStatusVariation.h"
#include "EventBinaryVariation.h"
#include "EventCounterVariation.h"
#include "EventDoubleBinaryVariation.h"
#include "EventFrozenCounterVariation.h"
#include "EventOctetStringVariation.h"
#include "EventSecurityStatVariation.h"
#include "StaticAnalogOutputStatusVariation.h"
#include "StaticAnalogVariation.h"
#include "StaticBinaryOutputStatusVariation.h"
#include "StaticBinaryVariation.h"
#include "StaticCounterVariation.h"
#include "StaticDoubleBinaryVariation.h"
#include "StaticFrozenCounterVariation.h"
#include "StaticOctetStringVariation.h"
#include "StaticSecurityStatVariation.h"
#include "StaticTimeAndIntervalVariation.h"
#include "StaticTypeBitmask.h"
//#include "StaticOnly.h"

////namespace opendnp3
////{

#define static_variation_t_in_BinaryInfo StaticBinaryVariation_uint8_t
#define event_variation_t_in_BinaryInfo  EventBinaryVariation_uint8_t
#define meas_t_in_BinaryInfo             Binary
#define value_t_in_BinaryInfo            boolean

#define DefaultStaticVariation_in_BinaryInfo static_variation_t_in_BinaryInfo
#define DefaultEventVariation_in_BinaryInfo  event_variation_t_in_BinaryInfo

////struct BinaryInfo : private StaticOnly
////struct BinaryInfo : private StaticOnly
////{
////    typedef Binary meas_t;
////    typedef bool value_t;
////    typedef EventBinaryVariation event_variation_t;
////    typedef StaticBinaryVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_DoubleBitBinaryInfo StaticDoubleBinaryVariation_uint8_t
#define event_variation_t_in_DoubleBitBinaryInfo  EventDoubleBinaryVariation_uint8_t
#define meas_t_in_DoubleBitBinaryInfo           DoubleBitBinary
#define value_t_in_DoubleBitBinaryInfo          DoubleBit_uint8_t

#define DefaultStaticVariation_in_DoubleBitBinaryInfo static_variation_t_in_DoubleBitBinaryInfo
#define DefaultEventVariation_in_DoubleBitBinaryInfo  event_variation_t_in_DoubleBitBinaryInfo
////struct DoubleBitBinaryInfo : private StaticOnly
////{
////    typedef DoubleBitBinary meas_t;
////    typedef DoubleBit value_t;
////    typedef EventDoubleBinaryVariation event_variation_t;
////    typedef StaticDoubleBinaryVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_BinaryOutputStatusInfo StaticBinaryOutputStatusVariation_uint8_t
#define event_variation_t_in_BinaryOutputStatusInfo  EventBinaryOutputStatusVariation_uint8_t
#define meas_t_in_BinaryOutputStatusInfo           BinaryOutputStatus
#define value_t_in_BinaryOutputStatusInfo          boolean

#define DefaultStaticVariation_in_BinaryOutputStatusInfo static_variation_t_in_BinaryOutputStatusInfo
#define DefaultEventVariation_in_BinaryOutputStatusInfo  event_variation_t_in_BinaryOutputStatusInfo
////struct BinaryOutputStatusInfo : private StaticOnly
////{
////    typedef BinaryOutputStatus meas_t;
////    typedef bool value_t;
////    typedef EventBinaryOutputStatusVariation event_variation_t;
////    typedef StaticBinaryOutputStatusVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_AnalogInfo  StaticAnalogVariation_uint8_t
#define event_variation_t_in_AnalogInfo   EventAnalogVariation_uint8_t
#define meas_t_in_AnalogInfo           Analog
#define value_t_in_AnalogInfo          double

#define DefaultStaticVariation_in_AnalogInfo static_variation_t_in_AnalogInfo
#define DefaultEventVariation_in_AnalogInfo  event_variation_t_in_AnalogInfo
////struct AnalogInfo : private StaticOnly
////{
////    typedef Analog meas_t;
////    typedef double value_t;
////    typedef EventAnalogVariation event_variation_t;
////    typedef StaticAnalogVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_CounterInfo  StaticCounterVariation_uint8_t
#define event_variation_t_in_CounterInfo   EventCounterVariation_uint8_t
#define meas_t_in_CounterInfo           Counter
#define value_t_in_CounterInfo          uint32_t

#define DefaultStaticVariation_in_CounterInfo static_variation_t_in_CounterInfo
#define DefaultEventVariation_in_CounterInfo  event_variation_t_in_CounterInfo
////struct CounterInfo : private StaticOnly
////{
////    typedef Counter meas_t;
////    typedef uint32_t value_t;
////    typedef EventCounterVariation event_variation_t;
////    typedef StaticCounterVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_FrozenCounterInfo  StaticFrozenCounterVariation_uint8_t
#define event_variation_t_in_FrozenCounterInfo   EventFrozenCounterVariation_uint8_t
#define meas_t_in_FrozenCounterInfo           FrozenCounter
#define value_t_in_FrozenCounterInfo          uint32_t

#define DefaultStaticVariation_in_FrozenCounterInfo static_variation_t_in_FrozenCounterInfo
#define DefaultEventVariation_in_FrozenCounterInfo  event_variation_t_in_FrozenCounterInfo
////struct FrozenCounterInfo : private StaticOnly
////{
////    typedef FrozenCounter meas_t;
////    typedef uint32_t value_t;
////    typedef EventFrozenCounterVariation event_variation_t;
////    typedef StaticFrozenCounterVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_AnalogOutputStatusInfo  StaticAnalogOutputStatusVariation_uint8_t
#define event_variation_t_in_AnalogOutputStatusInfo   EventAnalogOutputStatusVariation_uint8_t
#define meas_t_in_AnalogOutputStatusInfo           AnalogOutputStatus
#define value_t_in_AnalogOutputStatusInfo          double

#define DefaultStaticVariation_in_AnalogOutputStatusInfo static_variation_t_in_AnalogOutputStatusInfo
#define DefaultEventVariation_in_AnalogOutputStatusInfo  event_variation_t_in_AnalogOutputStatusInfo
////struct AnalogOutputStatusInfo : private StaticOnly
////{
////    typedef AnalogOutputStatus meas_t;
////    typedef double value_t;
////    typedef EventAnalogOutputStatusVariation event_variation_t;
////    typedef StaticAnalogOutputStatusVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_OctetStringInfo  StaticOctetStringVariation_uint8_t
#define event_variation_t_in_OctetStringInfo   EventOctetStringVariation_uint8_t
#define meas_t_in_OctetStringInfo           OctetString

#define DefaultStaticVariation_in_OctetStringInfo static_variation_t_in_OctetStringInfo
////struct OctetStringInfo : private StaticOnly
////{
////    typedef OctetString meas_t;
////    typedef EventOctetStringVariation event_variation_t;
////    typedef StaticOctetStringVariation static_variation_t;
////
////    static const EventType EventTypeEnum;
////    static const StaticTypeBitmask StaticTypeEnum;
////    static const event_variation_t DefaultEventVariation;
////    static const static_variation_t DefaultStaticVariation;
////};

#define static_variation_t_in_TimeAndIntervalInfo  StaticTimeAndIntervalVariation_uint8_t
#define meas_t_in_TimeAndIntervalInfo           TimeAndInterval

#define DefaultStaticVariation_in_TimeAndIntervalInfo static_variation_t_in_TimeAndIntervalInfo
////struct TimeAndIntervalInfo : private StaticOnly
////{
////    typedef TimeAndInterval meas_t;
////    typedef StaticTimeAndIntervalVariation static_variation_t;

////    static const StaticTypeBitmask StaticTypeEnum;
////    static const StaticTimeAndIntervalVariation DefaultStaticVariation;
////};

////} // namespace opendnp3

#endif
