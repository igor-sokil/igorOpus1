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
#ifndef OPENDNP3_DATABASE_H
#define OPENDNP3_DATABASE_H

////#include "app/MeasurementTypeSpecs.h"
////#include "outstation/IClassAssigner.h"
////#include "outstation/IEventReceiver.h"
////#include "outstation/IResponseLoader.h"
////#include "outstation/IStaticSelector.h"
////#include "outstation/StaticDataMap.h"

////#include "opendnp3/gen/FlagsType.h"
////#include "opendnp3/outstation/DatabaseConfig.h"
////#include "opendnp3/outstation/IDnpTimeSource.h"
////#include "opendnp3/outstation/IUpdateHandler.h"
////#include "opendnp3/outstation/StaticTypeBitfield.h"

#include "MeasurementTypeSpecs.h"
#include "IClassAssigner.h"
#include "IEventReceiver.h"
#include "IResponseLoader.h"
#include "IStaticSelector.h"
#include "StaticDataMap_for_AnalogOutputStatus.h"
#include "StaticDataMap_for_Analog.h"
#include "StaticDataMap_for_Binary.h"
#include "StaticDataMap_for_BinaryOutputStatus.h"
#include "StaticDataMap_for_Counter.h"
#include "StaticDataMap_for_DoubleBitBinary.h"
#include "StaticDataMap_for_FrozenCounter.h"
#include "StaticDataMap_for_OctetString.h"
#include "StaticDataMap_for_TimeAndInterval.h"

#include "FlagsType.h"
#include "DatabaseConfig.h"
#include "IDnpTimeSource.h"
#include "IUpdateHandler.h"
#include "StaticTypeBitfield.h"

#include "DatabaseConfig.h"
#include "StaticWriters.h"

////namespace opendnp3
////{

////class Database final : public IStaticSelector, public IClassAssigner, public IResponseLoader, public IUpdateHandler
typedef struct
{
  IStaticSelector iIStaticSelector;
  IClassAssigner  iIClassAssigner;
  IResponseLoader iIResponseLoader;
  IUpdateHandler  iIUpdateHandler;
////public:
////    Database(const DatabaseConfig& config,
////             IEventReceiver& event_receiver,
////             IDnpTimeSource& time_source,
////             StaticTypeBitField allowed_class_zero_types);

  // ------- IStaticSelector -------------
////    IINField SelectAll(GroupVariation gv) override;
////    IINField SelectRange(GroupVariation gv, const Range& range) override;
////    IINField SelectIndices(GroupVariation gv, const ICollection<uint16_t>& indices) override;
////    void Unselect() override;
////
  // ------- IClassAssigner -------------
////    Range AssignClassToAll(AssignClassType type, PointClass clazz) override;
////    Range AssignClassToRange(AssignClassType type, PointClass clazz, const Range& range) override;
////
////    // ------- IResponseLoader -------------
////    bool HasAnySelection() const override;
////    bool Load(HeaderWriter& writer) override;

  // ------- IUpdateHandler ---------------
////    bool Update(const Binary& meas, uint16_t index, EventMode mode) override;
////    bool Update(const DoubleBitBinary& meas, uint16_t index, EventMode mode) override;
////    bool Update(const Analog& meas, uint16_t index, EventMode mode) override;
////    bool Update(const Counter& meas, uint16_t index, EventMode mode) override;
////    bool FreezeCounter(uint16_t index, bool clear, EventMode mode) override;
////    bool Update(const BinaryOutputStatus& meas, uint16_t index, EventMode mode) override;
////    bool Update(const AnalogOutputStatus& meas, uint16_t index, EventMode mode) override;
////    bool Update(const OctetString& meas, uint16_t index, EventMode mode) override;
////    bool Update(const TimeAndInterval& meas, uint16_t index) override;
////    bool Modify(FlagsType type, uint16_t start, uint16_t stop, uint8_t flags) override;

////    bool FreezeSelectedCounters(bool clear, EventMode mode = EventMode::Detect);

////private:
  IEventReceiver* event_receiver;
  IDnpTimeSource* time_source;
  StaticTypeBitField allowed_class_zero_types;

  StaticDataMap_for_BinarySpec          binary_input;
  StaticDataMap_for_DoubleBitBinarySpec double_binary;
  StaticDataMap_for_AnalogSpec          analog_input;
  StaticDataMap_for_CounterSpec         counter;
  StaticDataMap_for_FrozenCounterSpec   frozen_counter;
  StaticDataMap_for_BinaryOutputStatusSpec    binary_output_status;
  StaticDataMap_for_AnalogOutputStatusSpec    analog_output_status;
  StaticDataMap_for_TimeAndIntervalSpec       time_and_interval;
  StaticDataMap_for_OctetStringSpec           octet_string;
////
  // ----- helper methods ------

////    template<class Spec> void select_all_class_zero(StaticDataMap<Spec>& map);

////    template<class Spec> static IINField select_all(StaticDataMap<Spec>& map);

////    template<class Spec>
////    IINField static select_all(StaticDataMap<Spec>& map, typename Spec::static_variation_t variation);

////    template<class Spec> static IINField select_range(StaticDataMap<Spec>& map, const Range& range);

////    template<class Spec>
////    static IINField select_range(StaticDataMap<Spec>& map,
////                                 const Range& range,
///                                 typename Spec::static_variation_t variation);
} Database;

void  Database_in_Database(Database *pDatabase,
                           DatabaseConfig* config,
                           IEventReceiver* event_receiver,
                           IDnpTimeSource* time_source,
                           StaticTypeBitField allowed_class_zero_types);

// ------- IStaticSelector -------------
IINField SelectAll_in_Database(Database *pDatabase, GroupVariation_uint16_t gv);
IINField SelectRange_in_Database(Database *pDatabase, GroupVariation_uint16_t gv, Range* range);
IINField SelectIndices_in_Database(Database *pDatabase, GroupVariation_uint16_t gv, ICollection_for_uint16* indices);
void Unselect_in_Database(Database *pDatabase);

IINField SelectAll_in_Database_override(void *pIStaticSelector, GroupVariation_uint16_t gv);
IINField SelectRange_in_Database_override(void *pIStaticSelector, GroupVariation_uint16_t gv, Range* range);
IINField SelectIndices_in_Database_override(void *pIStaticSelector, GroupVariation_uint16_t gv, ICollection_for_uint16* indices);
void Unselect_in_Database_override(void *pIStaticSelector);

// ------- IClassAssigner -------------
Range AssignClassToAll_in_Database(Database *pDatabase, AssignClassType_uint8_t type, PointClass_uint8_t clazz);
Range AssignClassToRange_in_Database(Database *pDatabase, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range);

Range AssignClassToAll_in_Database_override(void *pIClassAssigner, AssignClassType_uint8_t type, PointClass_uint8_t clazz);
Range AssignClassToRange_in_Database_override(void *pIClassAssigner, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range);

// ------- IResponseLoader -------------
boolean HasAnySelection_in_Database(Database *pDatabase);
boolean Load_in_Database(Database *pDatabase, HeaderWriter* writer);

boolean HasAnySelection_in_Database_override(void *pIResponseLoader);
boolean Load_in_Database_override(void *pIResponseLoader, HeaderWriter* writer);

// ------- IUpdateHandler ---------------
boolean Update_in_Database(Database *pDatabase, Binary* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database(Database *pDatabase, DoubleBitBinary* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database(Database *pDatabase, Analog* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database(Database *pDatabase, Counter* meas, uint16_t index, EventMode_uint8_t mode);
boolean FreezeCounter_in_Database(Database *pDatabase, uint16_t index, boolean clear, EventMode_uint8_t mode);
boolean Update_in_Database(Database *pDatabase, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database(Database *pDatabase, AnalogOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database(Database *pDatabase, OctetString* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database(Database *pDatabase, TimeAndInterval* meas, uint16_t index);
boolean Modify_in_Database(Database *pDatabase, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags);

boolean Update_in_Database_override(void *pIUpdateHandler, Binary* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database_override(void *pIUpdateHandler, DoubleBitBinary* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database_override(void *pIUpdateHandler, Analog* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database_override(void *pIUpdateHandler, Counter* meas, uint16_t index, EventMode_uint8_t mode);
boolean FreezeCounter_in_Database_override(void *pIUpdateHandler, uint16_t index, boolean clear, EventMode_uint8_t mode);
boolean Update_in_Database_override(void *pIUpdateHandler, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database_override(void *pIUpdateHandler, AnalogOutputStatus* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database_override(void *pIUpdateHandler, OctetString* meas, uint16_t index, EventMode_uint8_t mode);
boolean Update_in_Database_override(void *pIUpdateHandler, TimeAndInterval* meas, uint16_t index);
boolean Modify_in_Database_override(void *pIUpdateHandler, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags);

boolean FreezeSelectedCounters_in_Database(Database *pDatabase, boolean clear, EventMode_uint8_t mode);// = EventMode::Detect);

boolean load_type_for_Binary_in_Database_static(StaticDataMap_for_BinarySpec& map, HeaderWriter* writer);
boolean load_type_for_Analog_in_Database_static(StaticDataMap_for_AnalogSpec& map, HeaderWriter* writer);

void select_all_class_zero_StaticDataMap_for_AnalogSpec(Database *pDatabase, StaticDataMap_for_AnalogSpec* map);
IINField select_all_StaticDataMap_for_AnalogSpec_in_Database_static(StaticDataMap_for_AnalogSpec* map);


////} // namespace opendnp3
#endif
