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

#ifndef OPENDNP3_MEASUREMENTCONFIG_H
#define OPENDNP3_MEASUREMENTCONFIG_H

////#include "opendnp3/app/MeasurementInfo.h"
////#include "opendnp3/gen/PointClass.h"

#include "MeasurementInfo.h"
#include "PointClass.h"

////namespace opendnp3
////{

// All entries have this information
////template<class Info> struct StaticConfig
////{
////    typename Info::static_variation_t svariation = Info::DefaultStaticVariation;
////};

////template<class Info> struct EventConfig : StaticConfig<Info>
////{
////    PointClass clazz = PointClass::Class1;
////    typename Info::event_variation_t evariation = Info::DefaultEventVariation;
////};

////template<class Info> struct EventConfig : StaticConfig<Info>
typedef struct
{
  uint8_t svariation;
  PointClass_uint8_t clazz;// = PointClass_Class1;
  EventAnalogVariation_uint8_t  evariation;// = Info::DefaultEventVariation;
} EventConfig;

void EventConfig_in_EventConfig(EventConfig *pEventConfig, uint8_t svariation, uint8_t evariation);

////template<class Info> struct DeadbandConfig : EventConfig<Info>
////{
////    typename Info::value_t deadband = 0;
////};
typedef struct
{
  EventConfig eEventConfig;
  value_t_in_AnalogInfo deadband;// = 0;
} DeadbandConfig_for_AnalogInfo;
void DeadbandConfig_for_AnalogInfo_in_DeadbandConfig_for_AnalogInfo(DeadbandConfig_for_AnalogInfo *pDeadbandConfig_for_AnalogInfo);

typedef struct
{
  EventConfig eEventConfig;
  value_t_in_CounterInfo deadband;// = 0;
} DeadbandConfig_for_CounterInfo;
void DeadbandConfig_for_CounterInfo_in_DeadbandConfig_for_CounterInfo(DeadbandConfig_for_CounterInfo *pDeadbandConfig_for_CounterInfo);

typedef struct
{
  EventConfig eEventConfig;
  value_t_in_FrozenCounterInfo deadband;// = 0;
} DeadbandConfig_for_FrozenCounterInfo;
void DeadbandConfig_for_FrozenCounterInfo_in_DeadbandConfig_for_FrozenCounterInfo(DeadbandConfig_for_FrozenCounterInfo *pDeadbandConfig_for_FrozenCounterInfo);

typedef struct
{
  EventConfig eEventConfig;
  value_t_in_AnalogOutputStatusInfo deadband;// = 0;
} DeadbandConfig_for_AnalogOutputStatusInfo;
void DeadbandConfig_for_AnalogOutputStatusInfo_in_DeadbandConfig_for_AnalogOutputStatusInfo(DeadbandConfig_for_AnalogOutputStatusInfo *pDeadbandConfig_for_AnalogOutputStatusInfo);

////struct BinaryConfig : public EventConfig<BinaryInfo>
typedef struct
{
  EventConfig eEventConfig;
} BinaryConfig;
void BinaryConfig_in_BinaryConfig(BinaryConfig *pBinaryConfig);

////struct DoubleBitBinaryConfig : public EventConfig<DoubleBitBinaryInfo>
typedef struct
{
  EventConfig eEventConfig;
} DoubleBitBinaryConfig;
void DoubleBitBinaryConfig_in_DoubleBitBinaryConfig(DoubleBitBinaryConfig *pDoubleBitBinaryConfig);

////struct AnalogConfig : public DeadbandConfig<AnalogInfo>
typedef struct
{
  DeadbandConfig_for_AnalogInfo dDeadbandConfig_for_AnalogInfo;
} AnalogConfig;
void AnalogConfig_in_AnalogConfig(AnalogConfig *pAnalogConfig);

////struct CounterConfig : public DeadbandConfig<CounterInfo>
typedef struct
{
  DeadbandConfig_for_CounterInfo dDeadbandConfig_for_CounterInfo;
} CounterConfig;
void CounterConfig_in_CounterConfig(CounterConfig *pCounterConfig);

////struct FrozenCounterConfig : public DeadbandConfig<FrozenCounterInfo>
typedef struct
{
  DeadbandConfig_for_FrozenCounterInfo dDeadbandConfig_for_FrozenCounterInfo;
} FrozenCounterConfig;
void FrozenCounterConfig_in_FrozenCounterConfig(FrozenCounterConfig *pFrozenCounterConfig);

////struct BOStatusConfig : public EventConfig<BinaryOutputStatusInfo>
typedef struct
{
  EventConfig eEventConfig;
} BOStatusConfig;
void BOStatusConfig_in_BOStatusConfig(BOStatusConfig *pBOStatusConfig);

////struct AOStatusConfig : public DeadbandConfig<AnalogOutputStatusInfo>
typedef struct
{
  DeadbandConfig_for_AnalogOutputStatusInfo dDeadbandConfig_for_AnalogOutputStatusInfo;
} AOStatusConfig;
void AOStatusConfig_in_AOStatusConfig(AOStatusConfig *pAOStatusConfig);

////struct OctetStringConfig : public EventConfig<OctetStringInfo>
typedef struct
{
  EventConfig eEventConfig;
} OctetStringConfig;
void OctetStringConfig_in_OctetStringConfig(OctetStringConfig *pOctetStringConfig);

////struct TimeAndIntervalConfig : public StaticConfig<TimeAndIntervalInfo>
typedef struct
{
  static_variation_t_in_TimeAndIntervalInfo svariation;
} TimeAndIntervalConfig;
void TimeAndIntervalConfig_in_TimeAndIntervalConfig(TimeAndIntervalConfig *pTimeAndIntervalConfig);

////struct SecurityStatConfig
//typedef struct
//{
//} SecurityStatConfig;

////} // namespace opendnp3

#endif
