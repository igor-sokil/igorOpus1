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

#ifndef OPENDNP3_STATICWRITERS_H
#define OPENDNP3_STATICWRITERS_H

////#include "app/HeaderWriter.h"
////#include "app/MeasurementTypeSpecs.h"
////#include "outstation/StaticDataMap.h"

////#include "opendnp3/gen/StaticAnalogOutputStatusVariation.h"
////#include "opendnp3/gen/StaticAnalogVariation.h"
////#include "opendnp3/gen/StaticBinaryOutputStatusVariation.h"
////#include "opendnp3/gen/StaticBinaryVariation.h"
////#include "opendnp3/gen/StaticCounterVariation.h"
////#include "opendnp3/gen/StaticDoubleBinaryVariation.h"
////#include "opendnp3/gen/StaticFrozenCounterVariation.h"
////#include "opendnp3/util/StaticOnly.h"
#include "HeaderWriter.h"
#include "MeasurementTypeSpecs.h"
//#include "outstation/StaticDataMap.h"

#include "StaticDataMap_for_AnalogOutputStatus.h"
#include "StaticDataMap_for_Analog.h"
#include "StaticDataMap_for_Binary.h"
#include "StaticDataMap_for_BinaryOutputStatus.h"
#include "StaticDataMap_for_Counter.h"
#include "StaticDataMap_for_DoubleBitBinary.h"
#include "StaticDataMap_for_FrozenCounter.h"
#include "StaticDataMap_for_OctetString.h"
#include "StaticDataMap_for_TimeAndInterval.h"

#include "StaticAnalogOutputStatusVariation.h"
#include "StaticAnalogVariation.h"
#include "StaticBinaryOutputStatusVariation.h"
#include "StaticBinaryVariation.h"
#include "StaticCounterVariation.h"
#include "StaticDoubleBinaryVariation.h"
#include "StaticFrozenCounterVariation.h"
//#include "opendnp3/util/StaticOnly.h"

////namespace opendnp3
////{

////template<class Spec> using static_write_func_t = bool (*)(StaticDataMap<Spec>& map, HeaderWriter& writer);
typedef boolean  (* static_write_func_t_for_BinarySpec)(StaticDataMap_for_BinarySpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_DoubleBitBinarySpec)(StaticDataMap_for_DoubleBitBinarySpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_CounterSpec)(StaticDataMap_for_CounterSpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_FrozenCounterSpec)(StaticDataMap_for_FrozenCounterSpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_AnalogSpec)(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_AnalogOutputStatusSpec)(StaticDataMap_for_AnalogOutputStatusSpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_BinaryOutputStatusSpec)(StaticDataMap_for_BinaryOutputStatusSpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_OctetStringSpec)(StaticDataMap_for_OctetStringSpec& map, HeaderWriter* writer);//указатель на ф-цию
typedef boolean  (* static_write_func_t_for_TimeAndIntervalSpec)(StaticDataMap_for_TimeAndIntervalSpec& map, HeaderWriter* writer);//указатель на ф-цию

////struct StaticWriters : private StaticOnly
////{
////    static static_write_func_t<BinarySpec> get(StaticBinaryVariation variation);
////    static static_write_func_t<DoubleBitBinarySpec> get(StaticDoubleBinaryVariation variation);
////    static static_write_func_t<CounterSpec> get(StaticCounterVariation variation);
////    static static_write_func_t<FrozenCounterSpec> get(StaticFrozenCounterVariation variation);
////    static static_write_func_t<AnalogSpec> get(StaticAnalogVariation variation);
////    static static_write_func_t<AnalogOutputStatusSpec> get(StaticAnalogOutputStatusVariation variation);
////    static static_write_func_t<BinaryOutputStatusSpec> get(StaticBinaryOutputStatusVariation variation);
////    static static_write_func_t<OctetStringSpec> get(StaticOctetStringVariation variation);
////    static static_write_func_t<TimeAndIntervalSpec> get(StaticTimeAndIntervalVariation variation);
////};

static_write_func_t_for_BinarySpec                   get_for_BinarySpec_in_StaticWriters_static(StaticBinaryVariation_uint8_t variation);
static_write_func_t_for_DoubleBitBinarySpec          get_for_DoubleBitBinarySpec_in_StaticWriters_static(StaticDoubleBinaryVariation_uint8_t variation);
static_write_func_t_for_CounterSpec                  get_for_CounterSpec_in_StaticWriters_static(StaticCounterVariation_uint8_t variation);
static_write_func_t_for_FrozenCounterSpec            get_for_FrozenCounterSpec_in_StaticWriters_static(StaticFrozenCounterVariation_uint8_t variation);
static_write_func_t_for_AnalogSpec                   get_for_AnalogSpec_in_StaticWriters_static(StaticAnalogVariation_uint8_t variation);
static_write_func_t_for_AnalogOutputStatusSpec       get_for_AnalogOutputStatusSpec_in_StaticWriters_static(StaticAnalogOutputStatusVariation_uint8_t variation);
static_write_func_t_for_BinaryOutputStatusSpec       get_for_BinaryOutputStatusSpec_in_StaticWriters_static(StaticBinaryOutputStatusVariation_uint8_t variation);
static_write_func_t_for_OctetStringSpec              get_for_OctetStringSpec_in_StaticWriters_static(StaticOctetStringVariation_uint8_t variation);
static_write_func_t_for_TimeAndIntervalSpec          get_for_TimeAndIntervalSpec_in_StaticWriters_static(StaticTimeAndIntervalVariation_uint8_t variation);

////} // namespace opendnp3

#endif
