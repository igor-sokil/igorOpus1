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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "Database.h"

////Database::Database(const DatabaseConfig& config,
////                   IEventReceiver& event_receiver,
////                   IDnpTimeSource& time_source,
////                   StaticTypeBitField allowed_class_zero_types)
void  Database_in_Database(Database *pDatabase,
                           DatabaseConfig* config,
                           IEventReceiver* event_receiver,
                           IDnpTimeSource* time_source,
                           StaticTypeBitField allowed_class_zero_types)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Database_in_Database1"<<'\n';
  decrement_stack_info();
#endif

  pDatabase->event_receiver = event_receiver;
  pDatabase->time_source    = time_source;
  pDatabase->allowed_class_zero_types = allowed_class_zero_types;

//  StaticDataMap_for_BinarySpec          binary_input;
//  std::map<uint16_t, BinaryConfig> binary_input;
//  void StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpec(StaticDataMap_for_BinarySpec *pStaticDataMap, std::map<uint16_t, BinaryConfig>& config)
////      binary_input(config.binary_input),
  StaticDataMap_for_BinarySpec_in_StaticDataMap_for_BinarySpecOver2(&(pDatabase->binary_input), config->binary_input);

////      double_binary(config.double_binary),
  StaticDataMap_for_DoubleBitBinarySpec_in_StaticDataMap_for_DoubleBitBinarySpecOver2(&(pDatabase->double_binary), config->double_binary);

////      analog_input(config.analog_input),
  StaticDataMap_for_AnalogSpec_in_StaticDataMap_for_AnalogSpecOver2(&(pDatabase->analog_input), config->analog_input);

////      counter(config.counter),
  StaticDataMap_for_CounterSpec_in_StaticDataMap_for_CounterSpecOver2(&(pDatabase->counter), config->counter);

////      frozen_counter(config.frozen_counter),
  StaticDataMap_for_FrozenCounterSpec_in_StaticDataMap_for_FrozenCounterSpecOver2(&(pDatabase->frozen_counter), config->frozen_counter);

////      binary_output_status(config.binary_output_status),
  StaticDataMap_for_BinaryOutputStatusSpec_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(&(pDatabase->binary_output_status), config->binary_output_status);

////      analog_output_status(config.analog_output_status),
  StaticDataMap_for_AnalogOutputStatusSpec_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(&(pDatabase->analog_output_status), config->analog_output_status);

////      time_and_interval(config.time_and_interval),
  StaticDataMap_for_TimeAndIntervalSpec_in_StaticDataMap_for_TimeAndIntervalSpecOver2(&(pDatabase->time_and_interval), config->time_and_interval);

////      octet_string(config.octet_string)
  StaticDataMap_for_OctetStringSpec_in_StaticDataMap_for_OctetStringSpecOver2(&(pDatabase->octet_string), config->octet_string);

  // ------- IStaticSelector -------------
  pDatabase->iIStaticSelector.pSelectAll_in_IStaticSelector     = SelectAll_in_Database_override;
  pDatabase->iIStaticSelector.pSelectRange_in_IStaticSelector   = SelectRange_in_Database_override;
  pDatabase->iIStaticSelector.pSelectIndices_in_IStaticSelector = SelectIndices_in_Database_override;
  pDatabase->iIStaticSelector.pUnselect_in_IStaticSelector      = Unselect_in_Database_override;

  setParentPointer_in_IStaticSelector(&(pDatabase->iIStaticSelector), pDatabase);
  // ------- IStaticSelector -------------

  // ------- IClassAssigner -------------
  pDatabase->iIClassAssigner.pAssignClassToRange_in_IClassAssigner = AssignClassToRange_in_Database_override;
  pDatabase->iIClassAssigner.pAssignClassToAll_in_IClassAssigner   = AssignClassToAll_in_Database_override;

  setParentPointer_in_IClassAssigner(&(pDatabase->iIClassAssigner), pDatabase);
  // ------- IClassAssigner -------------

  // ------- IResponseLoader -------------
  pDatabase->iIResponseLoader.pHasAnySelection_in_IResponseLoader =  HasAnySelection_in_Database_override;
  pDatabase->iIResponseLoader.pLoad_in_IResponseLoader            =  Load_in_Database_override;
  setParentPointer_in_IResponseLoader(&(pDatabase->iIResponseLoader), pDatabase);
  // ------- IResponseLoader -------------

  // ------- IUpdateHandler -------------
  pDatabase->iIUpdateHandler.pUpdate_Binary_in_IUpdateHandler             = Update_for_Binary_in_Database_override;
  pDatabase->iIUpdateHandler.pUpdate_DoubleBitBinary_in_IUpdateHandler    = Update_for_DoubleBitBinary_in_Database_override;
  pDatabase->iIUpdateHandler.pUpdate_Analog_in_IUpdateHandler             = Update_for_Analog_in_Database_override;
  pDatabase->iIUpdateHandler.pUpdate_Counter_in_IUpdateHandler            = Update_for_Counter_in_Database_override;
  pDatabase->iIUpdateHandler.pUpdate_BinaryOutputStatus_in_IUpdateHandler = Update_for_BinaryOutputStatus_in_Database_override;
  pDatabase->iIUpdateHandler.pUpdate_AnalogOutputStatus_in_IUpdateHandler = Update_for_AnalogOutputStatus_in_Database_override;
  pDatabase->iIUpdateHandler.pUpdate_TimeAndInterval_in_IUpdateHandler    = Update_for_TimeAndInterval_in_Database_override;
  pDatabase->iIUpdateHandler.pUpdate_OctetString_in_IUpdateHandler        = Update_for_OctetString_in_Database_override;
  pDatabase->iIUpdateHandler.pModify_in_IUpdateHandler                    = Modify_in_Database_override;
  pDatabase->iIUpdateHandler.pFreezeCounter_in_IUpdateHandler             = FreezeCounter_in_Database_override;
  setParentPointer_in_IUpdateHandler(&(pDatabase->iIUpdateHandler), pDatabase);
  // ------- IUpdateHandler -------------

  /*
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
  */
}

////namespace opendnp3
////{
/*
template<class Spec>
IINField select_indices(StaticDataMap<Spec>& map,
                        const ICollection<uint16_t>& indices,
                        typename Spec::static_variation_t variation)
{
    auto missing_index = false;
    auto select = [&](uint16_t index) {
        if (!map.select(index, variation))
        {
            missing_index = true;
        }
    };
    indices.ForeachItem(select);

    return missing_index ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
}

template<class Spec> IINField select_indices(StaticDataMap<Spec>& map, const ICollection<uint16_t>& indices)
{
    auto missing_index = false;
    auto select = [&](uint16_t index) {
        if (!map.select(index))
        {
            missing_index = true;
        }
    };
    indices.ForeachItem(select);

    return missing_index ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
}

template<class Spec> bool load_type(StaticDataMap<Spec>& map, HeaderWriter& writer)
{
    while (true)
    {
        auto iter = map.begin();

        if (iter == map.end())
        {
            // there is no data left to write
            return true;
        }

        if (!StaticWriters::get((*iter).second.variation)(map, writer))
        {
            // the APDU is full
            return false;
        }
    }
}

Database::Database(const DatabaseConfig& config,
                   IEventReceiver& event_receiver,
                   IDnpTimeSource& time_source,
                   StaticTypeBitField allowed_class_zero_types)
    : event_receiver(event_receiver),
      time_source(time_source),
      allowed_class_zero_types(allowed_class_zero_types),
      binary_input(config.binary_input),
      double_binary(config.double_binary),
      analog_input(config.analog_input),
      counter(config.counter),
      frozen_counter(config.frozen_counter),
      binary_output_status(config.binary_output_status),
      analog_output_status(config.analog_output_status),
      time_and_interval(config.time_and_interval),
      octet_string(config.octet_string)
{
}

IINField Database::SelectAll(GroupVariation gv)
{
    if (gv == GroupVariation::Group60Var1)
    {
        this->select_all_class_zero<BinarySpec>(this->binary_input);
        this->select_all_class_zero<DoubleBitBinarySpec>(this->double_binary);
        this->select_all_class_zero<BinaryOutputStatusSpec>(this->binary_output_status);
        this->select_all_class_zero<CounterSpec>(this->counter);
        this->select_all_class_zero<FrozenCounterSpec>(this->frozen_counter);
        this->select_all_class_zero<AnalogSpec>(this->analog_input);
        this->select_all_class_zero<AnalogOutputStatusSpec>(this->analog_output_status);
        this->select_all_class_zero<TimeAndIntervalSpec>(this->time_and_interval);
        this->select_all_class_zero<OctetStringSpec>(this->octet_string);

        return IINField::Empty();
    }

    switch (gv)
    {
    case (GroupVariation::Group1Var0):
        return select_all<BinarySpec>(this->binary_input);
    case (GroupVariation::Group1Var1):
        return select_all<BinarySpec>(this->binary_input, StaticBinaryVariation::Group1Var1);
    case (GroupVariation::Group1Var2):
        return select_all<BinarySpec>(this->binary_input, StaticBinaryVariation::Group1Var2);

    case (GroupVariation::Group3Var0):
        return select_all<DoubleBitBinarySpec>(this->double_binary);
    case (GroupVariation::Group3Var2):
        return select_all<DoubleBitBinarySpec>(this->double_binary, StaticDoubleBinaryVariation::Group3Var2);

    case (GroupVariation::Group10Var0):
        return select_all<BinaryOutputStatusSpec>(this->binary_output_status);
    case (GroupVariation::Group10Var2):
        return select_all<BinaryOutputStatusSpec>(this->binary_output_status,
                                                  StaticBinaryOutputStatusVariation::Group10Var2);

    case (GroupVariation::Group20Var0):
        return select_all<CounterSpec>(this->counter);
    case (GroupVariation::Group20Var1):
        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var1);
    case (GroupVariation::Group20Var2):
        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var2);
    case (GroupVariation::Group20Var5):
        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var5);
    case (GroupVariation::Group20Var6):
        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var6);

    case (GroupVariation::Group21Var0):
        return select_all<FrozenCounterSpec>(this->frozen_counter);
    case (GroupVariation::Group21Var1):
        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var1);
    case (GroupVariation::Group21Var2):
        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var2);
    case (GroupVariation::Group21Var5):
        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var5);
    case (GroupVariation::Group21Var6):
        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var6);
    case (GroupVariation::Group21Var9):
        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var9);
    case (GroupVariation::Group21Var10):
        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var10);

    case (GroupVariation::Group30Var0):
        return select_all<AnalogSpec>(this->analog_input);
    case (GroupVariation::Group30Var1):
        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var1);
    case (GroupVariation::Group30Var2):
        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var2);
    case (GroupVariation::Group30Var3):
        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var3);
    case (GroupVariation::Group30Var4):
        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var4);
    case (GroupVariation::Group30Var5):
        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var5);
    case (GroupVariation::Group30Var6):
        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var6);

    case (GroupVariation::Group40Var0):
        return select_all<AnalogOutputStatusSpec>(this->analog_output_status);
    case (GroupVariation::Group40Var1):
        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
                                                  StaticAnalogOutputStatusVariation::Group40Var1);
    case (GroupVariation::Group40Var2):
        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
                                                  StaticAnalogOutputStatusVariation::Group40Var2);
    case (GroupVariation::Group40Var3):
        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
                                                  StaticAnalogOutputStatusVariation::Group40Var3);
    case (GroupVariation::Group40Var4):
        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
                                                  StaticAnalogOutputStatusVariation::Group40Var4);

    case (GroupVariation::Group50Var4):
        return select_all<TimeAndIntervalSpec>(this->time_and_interval, StaticTimeAndIntervalVariation::Group50Var4);

    case (GroupVariation::Group110Var0):
        return select_all<OctetStringSpec>(this->octet_string);

    default:
        return IINField(IINBit::FUNC_NOT_SUPPORTED);
    }
}

IINField Database::SelectRange(GroupVariation gv, const Range& range)
{
    switch (gv)
    {
    case (GroupVariation::Group1Var0):
        return select_range<BinarySpec>(this->binary_input, range);
    case (GroupVariation::Group1Var1):
        return select_range<BinarySpec>(this->binary_input, range, StaticBinaryVariation::Group1Var1);
    case (GroupVariation::Group1Var2):
        return select_range<BinarySpec>(this->binary_input, range, StaticBinaryVariation::Group1Var2);

    case (GroupVariation::Group3Var0):
        return select_range<DoubleBitBinarySpec>(this->double_binary, range);
    case (GroupVariation::Group3Var2):
        return select_range<DoubleBitBinarySpec>(this->double_binary, range, StaticDoubleBinaryVariation::Group3Var2);

    case (GroupVariation::Group10Var0):
        return select_range<BinaryOutputStatusSpec>(this->binary_output_status, range);
    case (GroupVariation::Group10Var2):
        return select_range<BinaryOutputStatusSpec>(this->binary_output_status, range,
                                                    StaticBinaryOutputStatusVariation::Group10Var2);

    case (GroupVariation::Group20Var0):
        return select_range<CounterSpec>(this->counter, range);
    case (GroupVariation::Group20Var1):
        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var1);
    case (GroupVariation::Group20Var2):
        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var2);
    case (GroupVariation::Group20Var5):
        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var5);
    case (GroupVariation::Group20Var6):
        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var6);

    case (GroupVariation::Group21Var0):
        return select_range<FrozenCounterSpec>(this->frozen_counter, range);
    case (GroupVariation::Group21Var1):
        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var1);
    case (GroupVariation::Group21Var2):
        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var2);
    case (GroupVariation::Group21Var5):
        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var5);
    case (GroupVariation::Group21Var6):
        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var6);
    case (GroupVariation::Group21Var9):
        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var9);
    case (GroupVariation::Group21Var10):
        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var10);

    case (GroupVariation::Group30Var0):
        return select_range<AnalogSpec>(this->analog_input, range);
    case (GroupVariation::Group30Var1):
        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var1);
    case (GroupVariation::Group30Var2):
        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var2);
    case (GroupVariation::Group30Var3):
        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var3);
    case (GroupVariation::Group30Var4):
        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var4);
    case (GroupVariation::Group30Var5):
        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var5);
    case (GroupVariation::Group30Var6):
        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var6);

    case (GroupVariation::Group40Var0):
        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range);
    case (GroupVariation::Group40Var1):
        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
                                                    StaticAnalogOutputStatusVariation::Group40Var1);
    case (GroupVariation::Group40Var2):
        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
                                                    StaticAnalogOutputStatusVariation::Group40Var2);
    case (GroupVariation::Group40Var3):
        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
                                                    StaticAnalogOutputStatusVariation::Group40Var3);
    case (GroupVariation::Group40Var4):
        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
                                                    StaticAnalogOutputStatusVariation::Group40Var4);

    case (GroupVariation::Group50Var4):
        return select_range<TimeAndIntervalSpec>(this->time_and_interval, range,
                                                 StaticTimeAndIntervalVariation::Group50Var4);

    case (GroupVariation::Group110Var0):
        return select_range<OctetStringSpec>(this->octet_string, range, StaticOctetStringVariation::Group110Var0);

    default:
        return IINField(IINBit::FUNC_NOT_SUPPORTED);
    }
}

IINField Database::SelectIndices(GroupVariation gv, const ICollection<uint16_t>& indices)
{
    switch (gv)
    {
    case (GroupVariation::Group1Var0):
        return select_indices(this->binary_input, indices);
    case (GroupVariation::Group1Var1):
        return select_indices(this->binary_input, indices, StaticBinaryVariation::Group1Var1);
    case (GroupVariation::Group1Var2):
        return select_indices(this->binary_input, indices, StaticBinaryVariation::Group1Var2);

    case (GroupVariation::Group3Var0):
        return select_indices(this->double_binary, indices);
    case (GroupVariation::Group3Var2):
        return select_indices(this->double_binary, indices, StaticDoubleBinaryVariation::Group3Var2);

    case (GroupVariation::Group10Var0):
        return select_indices(this->binary_output_status, indices);
    case (GroupVariation::Group10Var2):
        return select_indices(this->binary_output_status, indices, StaticBinaryOutputStatusVariation::Group10Var2);

    case (GroupVariation::Group20Var0):
        return select_indices(this->counter, indices);
    case (GroupVariation::Group20Var1):
        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var1);
    case (GroupVariation::Group20Var2):
        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var2);
    case (GroupVariation::Group20Var5):
        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var5);
    case (GroupVariation::Group20Var6):
        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var6);

    case (GroupVariation::Group21Var0):
        return select_indices(this->frozen_counter, indices);
    case (GroupVariation::Group21Var1):
        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var1);
    case (GroupVariation::Group21Var2):
        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var2);
    case (GroupVariation::Group21Var5):
        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var5);
    case (GroupVariation::Group21Var6):
        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var6);
    case (GroupVariation::Group21Var9):
        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var9);
    case (GroupVariation::Group21Var10):
        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var10);

    case (GroupVariation::Group30Var0):
        return select_indices<AnalogSpec>(this->analog_input, indices);
    case (GroupVariation::Group30Var1):
        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var1);
    case (GroupVariation::Group30Var2):
        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var2);
    case (GroupVariation::Group30Var3):
        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var3);
    case (GroupVariation::Group30Var4):
        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var4);
    case (GroupVariation::Group30Var5):
        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var5);
    case (GroupVariation::Group30Var6):
        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var6);

    case (GroupVariation::Group40Var0):
        return select_indices(this->analog_output_status, indices);
    case (GroupVariation::Group40Var1):
        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var1);
    case (GroupVariation::Group40Var2):
        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var2);
    case (GroupVariation::Group40Var3):
        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var3);
    case (GroupVariation::Group40Var4):
        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var4);

    case (GroupVariation::Group50Var4):
        return select_indices(this->time_and_interval, indices, StaticTimeAndIntervalVariation::Group50Var4);

    case (GroupVariation::Group110Var0):
        return select_indices(this->octet_string, indices, StaticOctetStringVariation::Group110Var0);

    default:
        return IINField(IINBit::FUNC_NOT_SUPPORTED);
    }
}

void Database::Unselect()
{
    this->binary_input.clear_selection();
    this->double_binary.clear_selection();
    this->binary_output_status.clear_selection();
    this->counter.clear_selection();
    this->frozen_counter.clear_selection();
    this->analog_input.clear_selection();
    this->analog_output_status.clear_selection();
    this->time_and_interval.clear_selection();
    this->octet_string.clear_selection();
}

Range Database::AssignClassToAll(AssignClassType type, PointClass clazz)
{
    switch (type)
    {
    case (AssignClassType::BinaryInput):
        return this->binary_input.assign_class(clazz);
    case (AssignClassType::DoubleBinaryInput):
        return this->double_binary.assign_class(clazz);
    case (AssignClassType::Counter):
        return this->counter.assign_class(clazz);
    case (AssignClassType::FrozenCounter):
        return this->frozen_counter.assign_class(clazz);
    case (AssignClassType::AnalogInput):
        return this->analog_input.assign_class(clazz);
    case (AssignClassType::BinaryOutputStatus):
        return this->binary_output_status.assign_class(clazz);
    case (AssignClassType::AnalogOutputStatus):
        return this->analog_output_status.assign_class(clazz);
    default:
        return Range::Invalid();
    }
}

Range Database::AssignClassToRange(AssignClassType type, PointClass clazz, const Range& range)
{
    switch (type)
    {
    case (AssignClassType::BinaryInput):
        return this->binary_input.assign_class(clazz, range);
    case (AssignClassType::DoubleBinaryInput):
        return this->double_binary.assign_class(clazz, range);
    case (AssignClassType::Counter):
        return this->counter.assign_class(clazz, range);
    case (AssignClassType::FrozenCounter):
        return this->frozen_counter.assign_class(clazz, range);
    case (AssignClassType::AnalogInput):
        return this->analog_input.assign_class(clazz, range);
    case (AssignClassType::BinaryOutputStatus):
        return this->binary_output_status.assign_class(clazz, range);
    case (AssignClassType::AnalogOutputStatus):
        return this->analog_output_status.assign_class(clazz, range);
    default:
        return Range::Invalid();
    }
}

bool Database::HasAnySelection() const
{
    return binary_input.has_any_selection() || double_binary.has_any_selection() || analog_input.has_any_selection()
        || counter.has_any_selection() || frozen_counter.has_any_selection() || binary_output_status.has_any_selection()
        || analog_output_status.has_any_selection() || time_and_interval.has_any_selection()
        || octet_string.has_any_selection();
}

bool Database::Load(HeaderWriter& writer)
{
    return load_type(this->binary_input, writer) && load_type(this->double_binary, writer)
        && load_type(this->analog_input, writer) && load_type(this->counter, writer)
        && load_type(this->frozen_counter, writer) && load_type(this->binary_output_status, writer)
        && load_type(this->analog_output_status, writer) && load_type(this->time_and_interval, writer)
        && load_type(this->octet_string, writer);
}

bool Database::Update(const Binary& meas, uint16_t index, EventMode mode)
{
    return this->binary_input.update(meas, index, mode, event_receiver);
}

bool Database::Update(const DoubleBitBinary& meas, uint16_t index, EventMode mode)
{
    return this->double_binary.update(meas, index, mode, event_receiver);
}

bool Database::Update(const Analog& meas, uint16_t index, EventMode mode)
{
    return this->analog_input.update(meas, index, mode, event_receiver);
}

bool Database::Update(const Counter& meas, uint16_t index, EventMode mode)
{
    return this->counter.update(meas, index, mode, event_receiver);
}

bool Database::FreezeCounter(uint16_t index, bool clear, EventMode mode)
{
    auto num_selected = this->counter.select(Range::From(index, index));
    this->FreezeSelectedCounters(clear, mode);

    return num_selected > 0;
}

bool Database::Update(const BinaryOutputStatus& meas, uint16_t index, EventMode mode)
{
    return this->binary_output_status.update(meas, index, mode, event_receiver);
}

bool Database::Update(const AnalogOutputStatus& meas, uint16_t index, EventMode mode)
{
    return this->analog_output_status.update(meas, index, mode, event_receiver);
}

bool Database::Update(const OctetString& meas, uint16_t index, EventMode mode)
{
    return this->octet_string.update(meas, index, mode, event_receiver);
}

bool Database::Update(const TimeAndInterval& meas, uint16_t index)
{
    return this->time_and_interval.update(meas, index, EventMode::Suppress, event_receiver);
}

bool Database::Modify(FlagsType type, uint16_t start, uint16_t stop, uint8_t flags)
{
    switch (type)
    {
    case (FlagsType::BinaryInput):
        return this->binary_input.modify(start, stop, flags, this->event_receiver);
    case (FlagsType::DoubleBinaryInput):
        return this->double_binary.modify(start, stop, flags, this->event_receiver);
    case (FlagsType::AnalogInput):
        return this->analog_input.modify(start, stop, flags, this->event_receiver);
    case (FlagsType::Counter):
        return this->counter.modify(start, stop, flags, this->event_receiver);
    case (FlagsType::FrozenCounter):
        return this->frozen_counter.modify(start, stop, flags, this->event_receiver);
    case (FlagsType::BinaryOutputStatus):
        return this->binary_output_status.modify(start, stop, flags, this->event_receiver);
    case (FlagsType::AnalogOutputStatus):
        return this->analog_output_status.modify(start, stop, flags, this->event_receiver);
    }

    return false;
}

bool Database::FreezeSelectedCounters(bool clear, EventMode mode)
{
    for (auto c : this->counter)
    {
        FrozenCounter new_value(c.second.value.value, c.second.value.flags, time_source.Now());
        this->frozen_counter.update(new_value, c.first, mode, this->event_receiver);

        if (clear)
        {
            c.second.value.value = 0;
            c.second.value.time = time_source.Now();
            this->counter.update(c.second.value, c.first, mode, this->event_receiver);
        }
    }

    this->counter.clear_selection();

    return true;
}

template<class Spec> IINField Database::select_all(StaticDataMap<Spec>& map)
{
    map.select_all();
    return IINField::Empty();
}

template<class Spec>
IINField Database::select_all(StaticDataMap<Spec>& map, typename Spec::static_variation_t variation)
{
    map.select_all(variation);
    return IINField::Empty();
}

template<class Spec> IINField Database::select_range(StaticDataMap<Spec>& map, const Range& range)
{
    const auto count = map.select(range);
    return (count != range.Count()) ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
}

template<class Spec>
IINField Database::select_range(StaticDataMap<Spec>& map,
                                const Range& range,
                                typename Spec::static_variation_t variation)
{
    const auto count = map.select(range, variation);
    return (count != range.Count()) ? IINField(IINBit::PARAM_ERROR) : IINField::Empty();
}
*/

IINField SelectAll_in_Database_override(void *pIStaticSelector, GroupVariation_uint16_t gv)
{
  Database *parent =
    (Database*)getParentPointer_in_IStaticSelector((IStaticSelector*)pIStaticSelector);
  return SelectAll_in_Database(parent, gv);
}

IINField SelectAll_in_Database( Database *pDatabase, GroupVariation_uint16_t gv)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectAll_in_Database1"<<'\n';
#endif
  if (gv == GroupVariation_Group60Var1)
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group60Var1"<<'\n';
    decrement_stack_info();
#endif
////        this->select_all_class_zero<BinarySpec>(this->binary_input);
    select_all_class_zero_StaticDataMap_for_BinarySpec(pDatabase, &(pDatabase->binary_input));
////        this->select_all_class_zero<DoubleBitBinarySpec>(this->double_binary);
    select_all_class_zero_StaticDataMap_for_DoubleBitBinarySpec(pDatabase, &(pDatabase->double_binary));
////        this->select_all_class_zero<BinaryOutputStatusSpec>(this->binary_output_status);
    select_all_class_zero_StaticDataMap_for_BinaryOutputStatusSpec(pDatabase, &(pDatabase->binary_output_status));
////        this->select_all_class_zero<CounterSpec>(this->counter);
    select_all_class_zero_StaticDataMap_for_CounterSpec(pDatabase, &(pDatabase->counter));
////        this->select_all_class_zero<FrozenCounterSpec>(this->frozen_counter);
    select_all_class_zero_StaticDataMap_for_FrozenCounterSpec(pDatabase, &(pDatabase->frozen_counter));
////        this->select_all_class_zero<AnalogSpec>(this->analog_input);
    select_all_class_zero_StaticDataMap_for_AnalogSpec(pDatabase, &(pDatabase->analog_input));
////        this->select_all_class_zero<AnalogOutputStatusSpec>(this->analog_output_status);
    select_all_class_zero_StaticDataMap_for_AnalogOutputStatusSpec(pDatabase, &(pDatabase->analog_output_status));
////        this->select_all_class_zero<TimeAndIntervalSpec>(this->time_and_interval);
    select_all_class_zero_StaticDataMap_for_TimeAndIntervalSpec(pDatabase, &(pDatabase->time_and_interval));
////        this->select_all_class_zero<OctetStringSpec>(this->octet_string);
    select_all_class_zero_StaticDataMap_for_OctetStringSpec(pDatabase, &(pDatabase->octet_string));

////        return IINField::Empty();
    return Empty_in_IINField_static();
  }

  switch (gv)
  {
  case (GroupVariation_Group1Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var0"<<'\n';
    decrement_stack_info();
#endif
//IINField select_all_StaticDataMap_for_BinarySpec_in_Database_static(StaticDataMap_for_BinarySpec* map)
////        return select_all<BinarySpec>(this->binary_input);
    return select_all_StaticDataMap_for_BinarySpec_in_Database_staticOver1(&(pDatabase->binary_input));

  case (GroupVariation_Group1Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<BinarySpec>(this->binary_input, StaticBinaryVariation::Group1Var1);
    return select_all_StaticDataMap_for_BinarySpec_in_Database_staticOver2(&(pDatabase->binary_input), StaticBinaryVariation_Group1Var1);

  case (GroupVariation_Group1Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<BinarySpec>(this->binary_input, StaticBinaryVariation::Group1Var2);
    return select_all_StaticDataMap_for_BinarySpec_in_Database_staticOver2(&(pDatabase->binary_input), StaticBinaryVariation_Group1Var2);

  case (GroupVariation_Group3Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<DoubleBitBinarySpec>(this->double_binary);
    return select_all_StaticDataMap_for_DoubleBitBinarySpec_in_Database_staticOver1(&(pDatabase->double_binary));

  case (GroupVariation_Group3Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<DoubleBitBinarySpec>(this->double_binary, StaticDoubleBinaryVariation::Group3Var2);
    return select_all_StaticDataMap_for_DoubleBitBinarySpec_in_Database_staticOver2(&(pDatabase->double_binary), StaticDoubleBinaryVariation_Group3Var2);

  case (GroupVariation_Group10Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<BinaryOutputStatusSpec>(this->binary_output_status);
    return select_all_StaticDataMap_for_BinaryOutputStatusSpec_in_Database_staticOver1(&(pDatabase->binary_output_status));

  case (GroupVariation_Group10Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group10Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<BinaryOutputStatusSpec>(this->binary_output_status,
////                                                  StaticBinaryOutputStatusVariation::Group10Var2);
    return select_all_StaticDataMap_for_BinaryOutputStatusSpec_in_Database_staticOver2(&(pDatabase->binary_output_status), StaticBinaryOutputStatusVariation_Group10Var2);

  case (GroupVariation_Group20Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<CounterSpec>(this->counter);
    return select_all_StaticDataMap_for_CounterSpec_in_Database_staticOver1(&(pDatabase->counter));

  case (GroupVariation_Group20Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var1);
    return select_all_StaticDataMap_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), StaticCounterVariation_Group20Var1);

  case (GroupVariation_Group20Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var2);
    return select_all_StaticDataMap_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), StaticCounterVariation_Group20Var2);

  case (GroupVariation_Group20Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var5);
    return select_all_StaticDataMap_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), StaticCounterVariation_Group20Var5);

  case (GroupVariation_Group20Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<CounterSpec>(this->counter, StaticCounterVariation::Group20Var6);
    return select_all_StaticDataMap_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), StaticCounterVariation_Group20Var6);

  case (GroupVariation_Group21Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<FrozenCounterSpec>(this->frozen_counter);
    return select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter));

  case (GroupVariation_Group21Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var1);
    return select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), StaticFrozenCounterVariation_Group21Var1);

  case (GroupVariation_Group21Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var2);
    return select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), StaticFrozenCounterVariation_Group21Var2);

  case (GroupVariation_Group21Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var5);
    return select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), StaticFrozenCounterVariation_Group21Var5);

  case (GroupVariation_Group21Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var6);
    return select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), StaticFrozenCounterVariation_Group21Var6);

  case (GroupVariation_Group21Var9):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var9"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var9);
    return select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), StaticFrozenCounterVariation_Group21Var9);

  case (GroupVariation_Group21Var10):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var10"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<FrozenCounterSpec>(this->frozen_counter, StaticFrozenCounterVariation::Group21Var10);
    return select_all_StaticDataMap_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), StaticFrozenCounterVariation_Group21Var10);

  case (GroupVariation_Group30Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogSpec>(this->analog_input);
    return select_all_StaticDataMap_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input));

  case (GroupVariation_Group30Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var1);
    return select_all_StaticDataMap_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), StaticAnalogVariation_Group30Var1);

  case (GroupVariation_Group30Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var2);
    return select_all_StaticDataMap_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), StaticAnalogVariation_Group30Var2);

  case (GroupVariation_Group30Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var3"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var3);
    return select_all_StaticDataMap_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), StaticAnalogVariation_Group30Var3);

  case (GroupVariation_Group30Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var4);
    return select_all_StaticDataMap_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), StaticAnalogVariation_Group30Var4);

  case (GroupVariation_Group30Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var5);
    return select_all_StaticDataMap_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), StaticAnalogVariation_Group30Var5);

  case (GroupVariation_Group30Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogSpec>(this->analog_input, StaticAnalogVariation::Group30Var6);
    return select_all_StaticDataMap_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), StaticAnalogVariation_Group30Var6);

  case (GroupVariation_Group40Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogOutputStatusSpec>(this->analog_output_status);
    return select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver1(&(pDatabase->analog_output_status));

  case (GroupVariation_Group40Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
////                                                  StaticAnalogOutputStatusVariation::Group40Var1);
    return select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), StaticAnalogOutputStatusVariation_Group40Var1);

  case (GroupVariation_Group40Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
////                                                  StaticAnalogOutputStatusVariation::Group40Var2);
    return select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), StaticAnalogOutputStatusVariation_Group40Var2);

  case (GroupVariation_Group40Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var3"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
////                                                  StaticAnalogOutputStatusVariation::Group40Var3);
    return select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), StaticAnalogOutputStatusVariation_Group40Var3);

  case (GroupVariation_Group40Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<AnalogOutputStatusSpec>(this->analog_output_status,
////                                                  StaticAnalogOutputStatusVariation::Group40Var4);
    return select_all_StaticDataMap_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), StaticAnalogOutputStatusVariation_Group40Var4);

  case (GroupVariation_Group50Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group50Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<TimeAndIntervalSpec>(this->time_and_interval, StaticTimeAndIntervalVariation::Group50Var4);
    return select_all_StaticDataMap_for_TimeAndIntervalSpec_in_Database_staticOver2(&(pDatabase->time_and_interval), StaticTimeAndIntervalVariation_Group50Var4);

  case (GroupVariation_Group110Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group110Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_all<OctetStringSpec>(this->octet_string);
    return select_all_StaticDataMap_for_OctetStringSpec_in_Database_staticOver1(&(pDatabase->octet_string));

  default:
////        return IINField(IINBit::FUNC_NOT_SUPPORTED);
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FUNC_NOT_SUPPORTED"<<'\n';
    decrement_stack_info();
#endif
////           return IINBit::FUNC_NOT_SUPPORTED;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
  }
  }
}

////IINField Database::SelectRange(GroupVariation gv, const Range& range)
IINField SelectRange_in_Database(Database *pDatabase, GroupVariation_uint16_t gv, Range* range)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectRange_in_Database1"<<'\n';
#endif
  switch (gv)
  {
  case (GroupVariation_Group1Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<BinarySpec>(this->binary_input, range);
    return select_range_for_BinarySpec_in_Database_staticOver1(&(pDatabase->binary_input), range);

  case (GroupVariation_Group1Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<BinarySpec>(this->binary_input, range, StaticBinaryVariation::Group1Var1);
    return select_range_for_BinarySpec_in_Database_staticOver2(&(pDatabase->binary_input), range, StaticBinaryVariation_Group1Var1);

  case (GroupVariation_Group1Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<BinarySpec>(this->binary_input, range, StaticBinaryVariation::Group1Var2);
    return select_range_for_BinarySpec_in_Database_staticOver2(&(pDatabase->binary_input), range, StaticBinaryVariation_Group1Var2);

  case (GroupVariation_Group3Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<DoubleBitBinarySpec>(this->double_binary, range);
    return select_range_for_DoubleBitBinarySpec_in_Database_staticOver1(&(pDatabase->double_binary), range);

  case (GroupVariation_Group3Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<DoubleBitBinarySpec>(this->double_binary, range, StaticDoubleBinaryVariation::Group3Var2);
    return select_range_for_DoubleBitBinarySpec_in_Database_staticOver2(&(pDatabase->double_binary), range, StaticDoubleBinaryVariation_Group3Var2);

  case (GroupVariation_Group10Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group10Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<BinaryOutputStatusSpec>(this->binary_output_status, range);
    return select_range_for_BinaryOutputStatusSpec_in_Database_staticOver1(&(pDatabase->binary_output_status), range);

  case (GroupVariation_Group10Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group10Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<BinaryOutputStatusSpec>(this->binary_output_status, range,
////                                                    StaticBinaryOutputStatusVariation::Group10Var2);
    return select_range_for_BinaryOutputStatusSpec_in_Database_staticOver2(&(pDatabase->binary_output_status), range, StaticBinaryOutputStatusVariation_Group10Var2);

  case (GroupVariation_Group20Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<CounterSpec>(this->counter, range);
    return select_range_for_CounterSpec_in_Database_staticOver1(&(pDatabase->counter), range);

  case (GroupVariation_Group20Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var1);
    return select_range_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), range, StaticCounterVariation_Group20Var1);

  case (GroupVariation_Group20Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var2);
    return select_range_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), range, StaticCounterVariation_Group20Var2);

  case (GroupVariation_Group20Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var5);
    return select_range_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), range, StaticCounterVariation_Group20Var5);

  case (GroupVariation_Group20Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<CounterSpec>(this->counter, range, StaticCounterVariation::Group20Var6);
    return select_range_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), range, StaticCounterVariation_Group20Var6);

  case (GroupVariation_Group21Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<FrozenCounterSpec>(this->frozen_counter, range);
    return select_range_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter), range);

  case (GroupVariation_Group21Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var1);
    return select_range_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), range, StaticFrozenCounterVariation_Group21Var1);

  case (GroupVariation_Group21Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var2);
    return select_range_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), range, StaticFrozenCounterVariation_Group21Var2);

  case (GroupVariation_Group21Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var5);
    return select_range_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), range, StaticFrozenCounterVariation_Group21Var5);

  case (GroupVariation_Group21Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var6);
    return select_range_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), range, StaticFrozenCounterVariation_Group21Var6);

  case (GroupVariation_Group21Var9):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var9"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var9);
    return select_range_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), range, StaticFrozenCounterVariation_Group21Var9);

  case (GroupVariation_Group21Var10):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var10"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<FrozenCounterSpec>(this->frozen_counter, range, StaticFrozenCounterVariation::Group21Var10);
    return select_range_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), range, StaticFrozenCounterVariation_Group21Var10);

  case (GroupVariation_Group30Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogSpec>(this->analog_input, range);
    return select_range_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input), range);

  case (GroupVariation_Group30Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var1);
    return select_range_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), range, StaticAnalogVariation_Group30Var1);

  case (GroupVariation_Group30Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var2);
    return select_range_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), range, StaticAnalogVariation_Group30Var2);

  case (GroupVariation_Group30Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var3"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var3);
    return select_range_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), range, StaticAnalogVariation_Group30Var3);

  case (GroupVariation_Group30Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var4);
    return select_range_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), range, StaticAnalogVariation_Group30Var4);

  case (GroupVariation_Group30Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var5);
    return select_range_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), range, StaticAnalogVariation_Group30Var5);

  case (GroupVariation_Group30Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogSpec>(this->analog_input, range, StaticAnalogVariation::Group30Var6);
    return select_range_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), range, StaticAnalogVariation_Group30Var6);

  case (GroupVariation_Group40Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range);
    return select_range_for_AnalogOutputStatusSpec_in_Database_staticOver1(&(pDatabase->analog_output_status), range);

  case (GroupVariation_Group40Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
////                                                    StaticAnalogOutputStatusVariation::Group40Var1);
    return select_range_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), range, StaticAnalogOutputStatusVariation_Group40Var1);

  case (GroupVariation_Group40Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
////                                                    StaticAnalogOutputStatusVariation::Group40Var2);
    return select_range_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), range, StaticAnalogOutputStatusVariation_Group40Var2);

  case (GroupVariation_Group40Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var3"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
////                                                    StaticAnalogOutputStatusVariation::Group40Var3);
    return select_range_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), range, StaticAnalogOutputStatusVariation_Group40Var3);

  case (GroupVariation_Group40Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<AnalogOutputStatusSpec>(this->analog_output_status, range,
////                                                    StaticAnalogOutputStatusVariation::Group40Var4);
    return select_range_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), range, StaticAnalogOutputStatusVariation_Group40Var4);

  case (GroupVariation_Group50Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group50Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_range<TimeAndIntervalSpec>(this->time_and_interval, range,
////                                                 StaticTimeAndIntervalVariation::Group50Var4);
    return select_range_for_TimeAndIntervalSpec_in_Database_staticOver2(&(pDatabase->time_and_interval), range, StaticTimeAndIntervalVariation_Group50Var4);

////    case (GroupVariation::Group110Var0):
////        return select_range<OctetStringSpec>(this->octet_string, range, StaticOctetStringVariation::Group110Var0);

  default:
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FUNC_NOT_SUPPORTED"<<'\n';
    decrement_stack_info();
#endif
////           return IINBit::FUNC_NOT_SUPPORTED;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
  }
  }
}

IINField SelectRange_in_Database_override(void *pIStaticSelector, GroupVariation_uint16_t gv, Range* range)
{
  Database *parent =
    (Database*)getParentPointer_in_IStaticSelector((IStaticSelector*)pIStaticSelector);
  return SelectRange_in_Database(parent, gv, range);
}

////IINField Database::SelectIndices(GroupVariation gv, const ICollection<uint16_t>& indices)
IINField SelectIndices_in_Database(Database *pDatabase, GroupVariation_uint16_t gv, ICollection_for_uint16* indices)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"SelectIndices_in_Database1"<<'\n';
#endif
  switch (gv)
  {
  case (GroupVariation_Group1Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->binary_input, indices);
    return select_indices_for_BinarySpec_in_Database_staticOver2(&(pDatabase->binary_input), indices);

  case (GroupVariation_Group1Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->binary_input, indices, StaticBinaryVariation::Group1Var1);
    return select_indices_for_BinarySpec_in_Database_staticOver1(&(pDatabase->binary_input), indices, StaticBinaryVariation_Group1Var1);

  case (GroupVariation_Group1Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group1Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->binary_input, indices, StaticBinaryVariation::Group1Var2);
    return select_indices_for_BinarySpec_in_Database_staticOver1(&(pDatabase->binary_input), indices, StaticBinaryVariation_Group1Var2);

  case (GroupVariation_Group3Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->double_binary, indices);
    return select_indices_for_DoubleBitBinarySpec_in_Database_staticOver2(&(pDatabase->double_binary), indices);

  case (GroupVariation_Group3Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group3Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->double_binary, indices, StaticDoubleBinaryVariation::Group3Var2);
    return select_indices_for_DoubleBitBinarySpec_in_Database_staticOver1(&(pDatabase->double_binary), indices, StaticDoubleBinaryVariation_Group3Var2);

  case (GroupVariation_Group10Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group10Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->binary_output_status, indices);
    return select_indices_for_BinaryOutputStatusSpec_in_Database_staticOver2(&(pDatabase->binary_output_status), indices);

  case (GroupVariation_Group10Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group10Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->binary_output_status, indices, StaticBinaryOutputStatusVariation::Group10Var2);
    return select_indices_for_BinaryOutputStatusSpec_in_Database_staticOver1(&(pDatabase->binary_output_status), indices, StaticBinaryOutputStatusVariation_Group10Var2);

  case (GroupVariation_Group20Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->counter, indices);
    return select_indices_for_CounterSpec_in_Database_staticOver2(&(pDatabase->counter), indices);

  case (GroupVariation_Group20Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var1);
    return select_indices_for_CounterSpec_in_Database_staticOver1(&(pDatabase->counter), indices, StaticCounterVariation_Group20Var1);

  case (GroupVariation_Group20Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var2);
    return select_indices_for_CounterSpec_in_Database_staticOver1(&(pDatabase->counter), indices, StaticCounterVariation_Group20Var2);

  case (GroupVariation_Group20Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var5);
    return select_indices_for_CounterSpec_in_Database_staticOver1(&(pDatabase->counter), indices, StaticCounterVariation_Group20Var5);

  case (GroupVariation_Group20Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group20Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->counter, indices, StaticCounterVariation::Group20Var6);
    return select_indices_for_CounterSpec_in_Database_staticOver1(&(pDatabase->counter), indices, StaticCounterVariation_Group20Var6);

  case (GroupVariation_Group21Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->frozen_counter, indices);
    return select_indices_for_FrozenCounterSpec_in_Database_staticOver2(&(pDatabase->frozen_counter), indices);

  case (GroupVariation_Group21Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var1);
    return select_indices_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter), indices, StaticFrozenCounterVariation_Group21Var1);

  case (GroupVariation_Group21Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var2);
    return select_indices_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter), indices, StaticFrozenCounterVariation_Group21Var2);

  case (GroupVariation_Group21Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var5);
    return select_indices_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter), indices, StaticFrozenCounterVariation_Group21Var5);

  case (GroupVariation_Group21Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var6);
    return select_indices_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter), indices, StaticFrozenCounterVariation_Group21Var6);

  case (GroupVariation_Group21Var9):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var9"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var9);
    return select_indices_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter), indices, StaticFrozenCounterVariation_Group21Var9);

  case (GroupVariation_Group21Var10):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group21Var10"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->frozen_counter, indices, StaticFrozenCounterVariation::Group21Var10);
    return select_indices_for_FrozenCounterSpec_in_Database_staticOver1(&(pDatabase->frozen_counter), indices, StaticFrozenCounterVariation_Group21Var10);

  case (GroupVariation_Group30Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices<AnalogSpec>(this->analog_input, indices);
    return select_indices_for_AnalogSpec_in_Database_staticOver2(&(pDatabase->analog_input), indices);

  case (GroupVariation_Group30Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var1);
    return select_indices_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input), indices, StaticAnalogVariation_Group30Var1);

  case (GroupVariation_Group30Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var2);
    return select_indices_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input), indices, StaticAnalogVariation_Group30Var2);

  case (GroupVariation_Group30Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var3"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var3);
    return select_indices_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input), indices, StaticAnalogVariation_Group30Var3);

  case (GroupVariation_Group30Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var4);
    return select_indices_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input), indices, StaticAnalogVariation_Group30Var4);

  case (GroupVariation_Group30Var5):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var5"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var5);
    return select_indices_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input), indices, StaticAnalogVariation_Group30Var5);

  case (GroupVariation_Group30Var6):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group30Var6"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_input, indices, StaticAnalogVariation::Group30Var6);
    return select_indices_for_AnalogSpec_in_Database_staticOver1(&(pDatabase->analog_input), indices, StaticAnalogVariation_Group30Var6);

  case (GroupVariation_Group40Var0):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var0"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_output_status, indices);
    return select_indices_for_AnalogOutputStatusSpec_in_Database_staticOver2(&(pDatabase->analog_output_status), indices);

  case (GroupVariation_Group40Var1):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var1"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var1);
    return select_indices_for_AnalogOutputStatusSpec_in_Database_staticOver1(&(pDatabase->analog_output_status), indices, StaticAnalogOutputStatusVariation_Group40Var1);

  case (GroupVariation_Group40Var2):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var2"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var2);
    return select_indices_for_AnalogOutputStatusSpec_in_Database_staticOver1(&(pDatabase->analog_output_status), indices, StaticAnalogOutputStatusVariation_Group40Var2);

  case (GroupVariation_Group40Var3):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var3"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var3);
    return select_indices_for_AnalogOutputStatusSpec_in_Database_staticOver1(&(pDatabase->analog_output_status), indices, StaticAnalogOutputStatusVariation_Group40Var3);

  case (GroupVariation_Group40Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group40Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->analog_output_status, indices, StaticAnalogOutputStatusVariation::Group40Var4);
    return select_indices_for_AnalogOutputStatusSpec_in_Database_staticOver1(&(pDatabase->analog_output_status), indices, StaticAnalogOutputStatusVariation_Group40Var4);

  case (GroupVariation_Group50Var4):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*GroupVariation_Group50Var4"<<'\n';
    decrement_stack_info();
#endif
////        return select_indices(this->time_and_interval, indices, StaticTimeAndIntervalVariation::Group50Var4);
    return select_indices_for_TimeAndIntervalSpec_in_Database_staticOver1(&(pDatabase->time_and_interval), indices, StaticTimeAndIntervalVariation_Group50Var4);

////    case (GroupVariation::Group110Var0):
////        return select_indices(this->octet_string, indices, StaticOctetStringVariation::Group110Var0);

  default:
  {
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FUNC_NOT_SUPPORTED"<<'\n';
    decrement_stack_info();
#endif
////           return IINBit::FUNC_NOT_SUPPORTED;
    IINField iIINField;
    IINField_in_IINFieldOver2(&iIINField, IINBit_FUNC_NOT_SUPPORTED);
    return iIINField;
  }
  }
}

IINField SelectIndices_in_Database_override(void *pIStaticSelector, GroupVariation_uint16_t gv, ICollection_for_uint16* indices)
{
  Database *parent =
    (Database*)getParentPointer_in_IStaticSelector((IStaticSelector*)pIStaticSelector);
  return SelectIndices_in_Database(parent, gv, indices);
}

////} // namespace opendnp3
void Unselect_in_Database(Database *pDatabase)
{
////    this->binary_input.clear_selection();
  clear_selection_in_StaticDataMap_for_BinarySpec(&(pDatabase->binary_input));
////    this->double_binary.clear_selection();
  clear_selection_in_StaticDataMap_for_DoubleBitBinarySpec(&(pDatabase->double_binary));
////    this->binary_output_status.clear_selection();
  clear_selection_in_StaticDataMap_for_BinaryOutputStatusSpec(&(pDatabase->binary_output_status));
////    this->counter.clear_selection();
  clear_selection_in_StaticDataMap_for_CounterSpec(&(pDatabase->counter));
////    this->frozen_counter.clear_selection();
  clear_selection_in_StaticDataMap_for_FrozenCounterSpec(&(pDatabase->frozen_counter));
////    this->analog_input.clear_selection();
  clear_selection_in_StaticDataMap_for_AnalogSpec(&(pDatabase->analog_input));
////    this->analog_output_status.clear_selection();
  clear_selection_in_StaticDataMap_for_AnalogOutputStatusSpec(&(pDatabase->analog_output_status));
////    this->time_and_interval.clear_selection();
  clear_selection_in_StaticDataMap_for_TimeAndIntervalSpec(&(pDatabase->time_and_interval));
////    this->octet_string.clear_selection();
  clear_selection_in_StaticDataMap_for_OctetStringSpec(&(pDatabase->octet_string));
}

void Unselect_in_Database_override(void *pIStaticSelector)
{
  Database *parent =
    (Database*)getParentPointer_in_IStaticSelector((IStaticSelector*)pIStaticSelector);
  Unselect_in_Database(parent);
}

////bool Database::HasAnySelection() const
boolean HasAnySelection_in_Database(Database *pDatabase)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"HasAnySelection_in_Database1"<<'\n';
  decrement_stack_info();
#endif
  return has_any_selection_in_StaticDataMap_for_AnalogSpec(&(pDatabase->analog_input)) ||
         has_any_selection_in_StaticDataMap_for_BinarySpec(&(pDatabase->binary_input)) ||
         has_any_selection_in_StaticDataMap_for_DoubleBitBinarySpec(&(pDatabase->double_binary)) ||
////    return binary_input.has_any_selection() || double_binary.has_any_selection() || analog_input.has_any_selection()
         has_any_selection_in_StaticDataMap_for_CounterSpec(&(pDatabase->counter)) ||
         has_any_selection_in_StaticDataMap_for_FrozenCounterSpec(&(pDatabase->frozen_counter)) ||
         has_any_selection_in_StaticDataMap_for_BinaryOutputStatusSpec(&(pDatabase->binary_output_status)) ||
////        || counter.has_any_selection() || frozen_counter.has_any_selection() || binary_output_status.has_any_selection()
         has_any_selection_in_StaticDataMap_for_AnalogOutputStatusSpec(&(pDatabase->analog_output_status)) ||
         has_any_selection_in_StaticDataMap_for_TimeAndIntervalSpec(&(pDatabase->time_and_interval)) ||
////        || analog_output_status.has_any_selection() || time_and_interval.has_any_selection()
         has_any_selection_in_StaticDataMap_for_OctetStringSpec(&(pDatabase->octet_string));
////        || octet_string.has_any_selection();
}

boolean HasAnySelection_in_Database_override(void *pIResponseLoader)
{
  Database *parent =
    (Database*)getParentPointer_in_IResponseLoader((IResponseLoader*)pIResponseLoader);
  return HasAnySelection_in_Database(parent);
}

boolean Load_in_Database_override(void *pIResponseLoader, HeaderWriter* writer)
{
  Database *parent =
    (Database*)getParentPointer_in_IResponseLoader((IResponseLoader*)pIResponseLoader);
  return Load_in_Database(parent, writer);
}
////bool Database::Load(HeaderWriter& writer)
boolean Load_in_Database(Database *pDatabase, HeaderWriter* writer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Load_in_Database1"<<'\n';
  decrement_stack_info();
#endif
//boolean load_type_for_Binary_in_Database_static(StaticDataMap_for_BinarySpec& map, HeaderWriter* writer)
////    return load_type(this->binary_input, writer) && load_type(this->double_binary, writer)
////        && load_type(this->analog_input, writer) && load_type(this->counter, writer)
////        && load_type(this->frozen_counter, writer) && load_type(this->binary_output_status, writer)
////        && load_type(this->analog_output_status, writer) && load_type(this->time_and_interval, writer)
////        && load_type(this->octet_string, writer);

  return load_type_for_Analog_in_Database_static(pDatabase->analog_input, writer) &&
         load_type_for_Binary_in_Database_static(pDatabase->binary_input, writer) &&
         load_type_for_BinaryOutputStatus_in_Database_static(pDatabase->binary_output_status, writer) &&
         load_type_for_AnalogOutputStatus_in_Database_static(pDatabase->analog_output_status, writer) &&
         load_type_for_DoubleBitBinary_in_Database_static(pDatabase->double_binary, writer) &&
         load_type_for_Counter_in_Database_static(pDatabase->counter, writer) &&
         load_type_for_FrozenCounter_in_Database_static(pDatabase->frozen_counter, writer) &&
         load_type_for_OctetString_in_Database_static(pDatabase->octet_string, writer) &&
         load_type_for_TimeAndInterval_in_Database_static(pDatabase->time_and_interval, writer);
}

boolean Update_for_Binary_in_Database_override(void *pIUpdateHandler, Binary* meas, uint16_t index, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_Binary_in_Database(parent, meas, index, mode);
}

boolean Update_for_DoubleBitBinary_in_Database_override(void *pIUpdateHandler, DoubleBitBinary* meas, uint16_t index, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_DoubleBitBinary_in_Database(parent, meas, index, mode);
}

boolean Update_for_Analog_in_Database_override(void *pIUpdateHandler, Analog* meas, uint16_t index, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_Analog_in_Database(parent, meas, index, mode);
}

boolean Update_for_Counter_in_Database_override(void *pIUpdateHandler, Counter* meas, uint16_t index, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_Counter_in_Database(parent, meas, index, mode);
}

boolean Update_for_BinaryOutputStatus_in_Database_override(void *pIUpdateHandler, BinaryOutputStatus* meas, uint16_t index, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_BinaryOutputStatus_in_Database(parent, meas, index, mode);
}

boolean Update_for_AnalogOutputStatus_in_Database_override(void *pIUpdateHandler, AnalogOutputStatus* meas, uint16_t index, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_AnalogOutputStatus_in_Database(parent, meas, index, mode);
}

boolean Update_for_TimeAndInterval_in_Database_override(void *pIUpdateHandler, TimeAndInterval* meas, uint16_t index)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_TimeAndInterval_in_Database(parent, meas, index);
}

boolean Update_for_OctetString_in_Database_override(void *pIUpdateHandler, OctetString* meas, uint16_t index, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Update_for_OctetString_in_Database(parent, meas, index, mode);
}

boolean Modify_in_Database_override(void *pIUpdateHandler, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return Modify_in_Database(parent, type, start, stop, flags);
}

////boolean Database::Modify(FlagsType type, uint16_t start, uint16_t stop, uint8_t flags)
boolean Modify_in_Database(Database *pDatabase, FlagsType_uint8_t type, uint16_t start, uint16_t stop, uint8_t flags)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Modify_in_Database1"<<'\n';
  decrement_stack_info();
#endif
  switch (type)
  {
  case (FlagsType_BinaryInput):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FlagsType_BinaryInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->binary_input.modify(start, stop, flags, this->event_receiver);
    return modify_in_StaticDataMap_for_BinarySpec(&(pDatabase->binary_input), start, stop, flags, pDatabase->event_receiver);
  case (FlagsType_DoubleBinaryInput):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FlagsType_DoubleBinaryInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->double_binary.modify(start, stop, flags, this->event_receiver);
    return modify_in_StaticDataMap_for_DoubleBitBinarySpec(&(pDatabase->double_binary), start, stop, flags, pDatabase->event_receiver);
  case (FlagsType_AnalogInput):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FlagsType_AnalogInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->analog_input.modify(start, stop, flags, this->event_receiver);
    return modify_in_StaticDataMap_for_AnalogSpec(&(pDatabase->analog_input), start, stop, flags, pDatabase->event_receiver);
  case (FlagsType_Counter):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FlagsType_Counter"<<'\n';
    decrement_stack_info();
#endif
////        return this->counter.modify(start, stop, flags, this->event_receiver);
    return modify_in_StaticDataMap_for_CounterSpec(&(pDatabase->counter), start, stop, flags, pDatabase->event_receiver);
  case (FlagsType_FrozenCounter):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FlagsType_FrozenCounter"<<'\n';
    decrement_stack_info();
#endif
////        return this->frozen_counter.modify(start, stop, flags, this->event_receiver);
    return modify_in_StaticDataMap_for_FrozenCounterSpec(&(pDatabase->frozen_counter), start, stop, flags, pDatabase->event_receiver);
  case (FlagsType_BinaryOutputStatus):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FlagsType_BinaryOutputStatus"<<'\n';
    decrement_stack_info();
#endif
////        return this->binary_output_status.modify(start, stop, flags, this->event_receiver);
    return modify_in_StaticDataMap_for_BinaryOutputStatusSpec(&(pDatabase->binary_output_status), start, stop, flags, pDatabase->event_receiver);
  case (FlagsType_AnalogOutputStatus):
#ifdef  LOG_INFO
    std::cout<<"*"<<getString_stack_info();
    std::cout<<"*FlagsType_AnalogOutputStatus"<<'\n';
    decrement_stack_info();
#endif
////        return this->analog_output_status.modify(start, stop, flags, this->event_receiver);
    return modify_in_StaticDataMap_for_AnalogOutputStatusSpec(&(pDatabase->analog_output_status), start, stop, flags, pDatabase->event_receiver);
  }

  return false;
}

////bool Database::FreezeSelectedCounters(bool clear, EventMode mode)
boolean FreezeSelectedCounters_in_Database(Database *pDatabase, boolean clear, EventMode_uint8_t mode)// = EventMode::Detect);
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{FreezeSelectedCounters_in_Database1"<<'\n';
#endif
  for (auto c : pDatabase->counter)
  {
//DNPTime Now_in_IDnpTimeSource_static(IDnpTimeSource*);
//void FrozenCounter_in_FrozenCounterOver4(FrozenCounter *pFrozenCounter, uint32_t value, Flags flags, DNPTime timeDNPTime);
////        FrozenCounter new_value(c.second.value.value, c.second.value.flags, time_source.Now());
    FrozenCounter new_value;
    FrozenCounter_in_FrozenCounterOver4(&new_value, c.second.value.tTypedMeasurement_for_Uint32.value, c.second.value.tTypedMeasurement_for_Uint32.mMeasurement.flags, Now_in_IDnpTimeSource_static(pDatabase->time_source));

#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*FreezeSelectedCounters_in_Database2"<<'\n';
  inspect_FrozenCounter(&new_value);
#endif

//boolean update_in_StaticDataMap_for_FrozenCounterSpecOver1(StaticDataMap_for_FrozenCounterSpec *pStaticDataMap_for_FrozenCounterSpec,
//    FrozenCounter* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////        this->frozen_counter.update(new_value, c.first, mode, this->event_receiver);
    update_in_StaticDataMap_for_FrozenCounterSpecOver1(&(pDatabase->frozen_counter),
        &new_value, c.first, mode, (pDatabase->event_receiver));

    if (clear)
    {
      c.second.value.tTypedMeasurement_for_Uint32.value = 0;
////            c.second.value.time = time_source.Now();
      c.second.value.tTypedMeasurement_for_Uint32.mMeasurement.timeDNPTime = Now_in_IDnpTimeSource_static(pDatabase->time_source);

//boolean update_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec,
//    Counter* value,
//    uint16_t index,
//    EventMode_uint8_t mode,
//    IEventReceiver* receiver);
////            this->counter.update(c.second.value, c.first, mode, this->event_receiver);
      Counter tmp = c.second.value;
      update_in_StaticDataMap_for_CounterSpecOver1(&(pDatabase->counter),
          &tmp, c.first, mode, (pDatabase->event_receiver));
    }
  }

//void clear_selection_in_StaticDataMap_for_CounterSpec(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec);
////    this->counter.clear_selection();
  clear_selection_in_StaticDataMap_for_CounterSpec(&(pDatabase->counter));

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}FreezeSelectedCounters_in_Database_"<<'\n';
  decrement_stack_info();
#endif
  return true;
}

////bool Database::FreezeCounter(uint16_t index, bool clear, EventMode mode)
boolean FreezeCounter_in_Database(Database *pDatabase, uint16_t index, boolean clear, EventMode_uint8_t mode)
{
//Range From_in_Range_static(uint16_t start, uint16_t stop);
//uint16_t select_in_StaticDataMap_for_CounterSpecOver1(StaticDataMap_for_CounterSpec *pStaticDataMap_for_CounterSpec, Range range);
////    auto num_selected = this->counter.select(Range::From(index, index));
  uint16_t num_selected = select_in_StaticDataMap_for_CounterSpecOver1(&(pDatabase->counter), From_in_Range_static(index, index));

//boolean FreezeSelectedCounters_in_Database(Database *pDatabase, boolean clear, EventMode_uint8_t mode)// = EventMode::Detect);
////    this->FreezeSelectedCounters(clear, mode);
  FreezeSelectedCounters_in_Database(pDatabase, clear, mode);

  return num_selected > 0;
}

boolean FreezeCounter_in_Database_override(void *pIUpdateHandler, uint16_t index, boolean clear, EventMode_uint8_t mode)
{
  Database *parent =
    (Database*)getParentPointer_in_IUpdateHandler((IUpdateHandler*)pIUpdateHandler);
  return FreezeCounter_in_Database(parent, index, clear, mode);
}

////Range Database::AssignClassToAll(AssignClassType type, PointClass clazz)
Range AssignClassToAll_in_Database(Database *pDatabase, AssignClassType_uint8_t type, PointClass_uint8_t clazz)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<"+"<<getString_stack_info();
  std::cout<<"AssignClassToAll_in_Database1"<<'\n';
#endif
  switch (type)
  {
  case (AssignClassType_BinaryInput):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_BinaryInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->binary_input.assign_class(clazz);
    return assign_class_in_StaticDataMap_for_BinarySpecOver1(&(pDatabase->binary_input), clazz);

  case (AssignClassType_DoubleBinaryInput):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_DoubleBinaryInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->double_binary.assign_class(clazz);
    return assign_class_in_StaticDataMap_for_DoubleBitBinarySpecOver1(&(pDatabase->double_binary), clazz);

  case (AssignClassType_Counter):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_Counter"<<'\n';
    decrement_stack_info();
#endif
////        return this->counter.assign_class(clazz);
    return assign_class_in_StaticDataMap_for_CounterSpecOver1(&(pDatabase->counter), clazz);

  case (AssignClassType_FrozenCounter):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_FrozenCounter"<<'\n';
    decrement_stack_info();
#endif
////        return this->frozen_counter.assign_class(clazz);
    return assign_class_in_StaticDataMap_for_FrozenCounterSpecOver1(&(pDatabase->frozen_counter), clazz);

  case (AssignClassType_AnalogInput):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_AnalogInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->analog_input.assign_class(clazz);
    return assign_class_in_StaticDataMap_for_AnalogSpecOver1(&(pDatabase->analog_input), clazz);

  case (AssignClassType_BinaryOutputStatus):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_BinaryOutputStatus"<<'\n';
    decrement_stack_info();
#endif
////        return this->binary_output_status.assign_class(clazz);
    return assign_class_in_StaticDataMap_for_BinaryOutputStatusSpecOver1(&(pDatabase->binary_output_status), clazz);

  case (AssignClassType_AnalogOutputStatus):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_AnalogOutputStatus"<<'\n';
    decrement_stack_info();
#endif
////        return this->analog_output_status.assign_class(clazz);
    return assign_class_in_StaticDataMap_for_AnalogOutputStatusSpecOver1(&(pDatabase->analog_output_status), clazz);

  default:
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
////        return Range::Invalid();
    return Invalid_in_Range_static();
  }
}

////Range Database::AssignClassToRange(AssignClassType type, PointClass clazz, const Range& range)
Range AssignClassToRange_in_Database(Database *pDatabase, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"AssignClassToRange_in_Database1"<<'\n';
#endif
  switch (type)
  {
  case (AssignClassType_BinaryInput):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_BinaryInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->binary_input.assign_class(clazz, range);
    return assign_class_in_StaticDataMap_for_BinarySpecOver2(&(pDatabase->binary_input), clazz, range);

  case (AssignClassType_DoubleBinaryInput):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_DoubleBinaryInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->double_binary.assign_class(clazz, range);
    return assign_class_in_StaticDataMap_for_DoubleBitBinarySpecOver2(&(pDatabase->double_binary), clazz, range);

  case (AssignClassType_Counter):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_Counter"<<'\n';
    decrement_stack_info();
#endif
////        return this->counter.assign_class(clazz, range);
    return assign_class_in_StaticDataMap_for_CounterSpecOver2(&(pDatabase->counter), clazz, range);

  case (AssignClassType_FrozenCounter):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_FrozenCounter"<<'\n';
    decrement_stack_info();
#endif
////        return this->frozen_counter.assign_class(clazz, range);
    return assign_class_in_StaticDataMap_for_FrozenCounterSpecOver2(&(pDatabase->frozen_counter), clazz, range);

  case (AssignClassType_AnalogInput):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_AnalogInput"<<'\n';
    decrement_stack_info();
#endif
////        return this->analog_input.assign_class(clazz, range);
    return assign_class_in_StaticDataMap_for_AnalogSpecOver2(&(pDatabase->analog_input), clazz, range);

  case (AssignClassType_BinaryOutputStatus):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_BinaryOutputStatus"<<'\n';
    decrement_stack_info();
#endif
////        return this->binary_output_status.assign_class(clazz, range);
    return assign_class_in_StaticDataMap_for_BinaryOutputStatusSpecOver2(&(pDatabase->binary_output_status), clazz, range);

  case (AssignClassType_AnalogOutputStatus):
#ifdef  LOG_INFO
    std::cout<<"@@@@"<<getString_stack_info();
    std::cout<<"*AssignClassType_AnalogOutputStatus"<<'\n';
    decrement_stack_info();
#endif
////        return this->analog_output_status.assign_class(clazz, range);
    return assign_class_in_StaticDataMap_for_AnalogOutputStatusSpecOver2(&(pDatabase->analog_output_status), clazz, range);

  default:
#ifdef  LOG_INFO
    decrement_stack_info();
#endif
////        return Range::Invalid();
    return Invalid_in_Range_static();
  }
}

Range AssignClassToAll_in_Database_override(void *pIClassAssigner, AssignClassType_uint8_t type, PointClass_uint8_t clazz)
{
  Database *parent =
    (Database*)getParentPointer_in_IClassAssigner((IClassAssigner*)pIClassAssigner);
  return AssignClassToAll_in_Database(parent, type, clazz);
}

Range AssignClassToRange_in_Database_override(void *pIClassAssigner, AssignClassType_uint8_t type, PointClass_uint8_t clazz, Range* range)
{
  Database *parent =
    (Database*)getParentPointer_in_IClassAssigner((IClassAssigner*)pIClassAssigner);
  return AssignClassToRange_in_Database(parent, type, clazz, range);
}

