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
#ifndef OPENDNP3_STATICDATACELL_H
#define OPENDNP3_STATICDATACELL_H

////namespace opendnp3
////{

/**
 * Type used to record whether a value is requested in a response
 */
//-------------------------------Binary-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  Binary value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_BinaryInfo variation;
} SelectedValue_for_BinarySpec;
void SelectedValue_for_BinarySpec_in_SelectedValue_for_BinarySpecOver1(SelectedValue_for_BinarySpec *pSelectedValue_for_BinarySpec);
void SelectedValue_for_BinarySpec_in_SelectedValue_for_BinarySpecOver2(SelectedValue_for_BinarySpec *pSelectedValue_for_BinarySpec,
                                          boolean selected, Binary* value, StaticBinaryVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  Binary  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  BinaryConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_Binary event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_BinarySpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_Binary;

void StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(StaticDataCell_for_Binary *pStaticDataCell_for_Binary);

void StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver2(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
    BinaryConfig* config);
void  StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver3(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
    Binary* value,
    BinaryConfig* config);
//-------------------------------Binary-------------------------------------------------
//-------------------------------DoubleBitBinary-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  DoubleBitBinary value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_DoubleBitBinaryInfo variation;
} SelectedValue_for_DoubleBitBinarySpec;
void SelectedValue_for_DoubleBitBinarySpec_in_SelectedValue_for_DoubleBitBinarySpecOver1(SelectedValue_for_DoubleBitBinarySpec *pSelectedValue_for_DoubleBitBinarySpec);
void SelectedValue_for_DoubleBitBinarySpec_in_SelectedValue_for_DoubleBitBinarySpecOver2(SelectedValue_for_DoubleBitBinarySpec *pSelectedValue_for_DoubleBitBinarySpec,
                                          boolean selected, DoubleBitBinary* value, StaticDoubleBinaryVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  DoubleBitBinary  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  DoubleBitBinaryConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_DoubleBitBinary event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_DoubleBitBinarySpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_DoubleBitBinary;

void StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver1(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary);

void StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver2(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary,
    DoubleBitBinaryConfig* config);
void  StaticDataCell_for_DoubleBitBinary_in_StaticDataCell_for_DoubleBitBinaryOver3(StaticDataCell_for_DoubleBitBinary *pStaticDataCell_for_DoubleBitBinary,
    DoubleBitBinary* value,
    DoubleBitBinaryConfig* config);
//-------------------------------DoubleBitBinary-------------------------------------------------
//-------------------------------Analog-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  Analog value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_AnalogInfo variation;
} SelectedValue_for_AnalogSpec;
void SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver1(SelectedValue_for_AnalogSpec *pSelectedValue_for_AnalogSpec);
////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
void SelectedValue_for_AnalogSpec_in_SelectedValue_for_AnalogSpecOver2(SelectedValue_for_AnalogSpec *pSelectedValue_for_AnalogSpec,
                                          boolean selected, Analog* value, StaticAnalogVariation_uint8_t variation);
/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  Analog  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  AnalogConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_Analog event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_AnalogSpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_Analog;

void StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver1(StaticDataCell_for_Analog *pStaticDataCell_for_Analog);

void StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver2(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
    AnalogConfig* config);
void  StaticDataCell_for_Analog_in_StaticDataCell_for_AnalogOver3(StaticDataCell_for_Analog *pStaticDataCell_for_Analog,
    Analog* value,
    AnalogConfig* config);
//-------------------------------Analog-------------------------------------------------
//-------------------------------Counter-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  Counter value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_CounterInfo variation;
} SelectedValue_for_CounterSpec;
void SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver1(SelectedValue_for_CounterSpec *pSelectedValue_for_CounterSpec);
void SelectedValue_for_CounterSpec_in_SelectedValue_for_CounterSpecOver2(SelectedValue_for_CounterSpec *pSelectedValue_for_CounterSpec,
                                          boolean selected, Counter* value, StaticCounterVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  Counter  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  CounterConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_Counter event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_CounterSpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_Counter;

void StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver1(StaticDataCell_for_Counter *pStaticDataCell_for_Counter);
void StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver2(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
    CounterConfig* config);
void  StaticDataCell_for_Counter_in_StaticDataCell_for_CounterOver3(StaticDataCell_for_Counter *pStaticDataCell_for_Counter,
    Counter* value,
    CounterConfig* config);
//-------------------------------Counter-------------------------------------------------
//-------------------------------FrozenCounter-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  FrozenCounter value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_FrozenCounterInfo variation;
} SelectedValue_for_FrozenCounterSpec;
void SelectedValue_for_FrozenCounterSpec_in_SelectedValue_for_FrozenCounterSpecOver1(SelectedValue_for_FrozenCounterSpec *pSelectedValue_for_FrozenCounterSpec);
void SelectedValue_for_FrozenCounterSpec_in_SelectedValue_for_FrozenCounterSpecOver2(SelectedValue_for_FrozenCounterSpec *pSelectedValue_for_FrozenCounterSpec,
                                          boolean selected, FrozenCounter* value, StaticFrozenCounterVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  FrozenCounter  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  FrozenCounterConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_FrozenCounter event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_FrozenCounterSpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_FrozenCounter;

void StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver1(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter);
void StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver2(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
    FrozenCounterConfig* config);
void  StaticDataCell_for_FrozenCounter_in_StaticDataCell_for_FrozenCounterOver3(StaticDataCell_for_FrozenCounter *pStaticDataCell_for_FrozenCounter,
    FrozenCounter* value,
    FrozenCounterConfig* config);
//-------------------------------FrozenCounter-------------------------------------------------
//-------------------------------BinaryOutputStatus-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  BinaryOutputStatus value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_BinaryOutputStatusInfo variation;
} SelectedValue_for_BinaryOutputStatusSpec;
void SelectedValue_for_BinaryOutputStatusSpec_in_SelectedValue_for_BinaryOutputStatusSpecOver1(SelectedValue_for_BinaryOutputStatusSpec *pSelectedValue_for_BinaryOutputStatusSpec);
void SelectedValue_for_BinaryOutputStatusSpec_in_SelectedValue_for_BinaryOutputStatusSpecOver2(SelectedValue_for_BinaryOutputStatusSpec *pSelectedValue_for_BinaryOutputStatusSpec,
                                          boolean selected, BinaryOutputStatus* value, StaticBinaryOutputStatusVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  BinaryOutputStatus  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  BOStatusConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_BinaryOutputStatus event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_BinaryOutputStatusSpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_BinaryOutputStatus;

void StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver1(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus);
void StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver2(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus,
    BOStatusConfig* config);
void  StaticDataCell_for_BinaryOutputStatus_in_StaticDataCell_for_BinaryOutputStatusOver3(StaticDataCell_for_BinaryOutputStatus *pStaticDataCell_for_BinaryOutputStatus,
    BinaryOutputStatus* value,
    BOStatusConfig* config);
//-------------------------------BinaryOutputStatus-------------------------------------------------
//-------------------------------AnalogOutputStatus-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  AnalogOutputStatus value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_AnalogOutputStatusInfo variation;
} SelectedValue_for_AnalogOutputStatusSpec;
void SelectedValue_for_AnalogOutputStatusSpec_in_SelectedValue_for_AnalogOutputStatusSpecOver1(SelectedValue_for_AnalogOutputStatusSpec *pSelectedValue_for_AnalogOutputStatusSpec);
void SelectedValue_for_AnalogOutputStatusSpec_in_SelectedValue_for_AnalogOutputStatusSpecOver2(SelectedValue_for_AnalogOutputStatusSpec *pSelectedValue_for_AnalogOutputStatusSpec,
                                          boolean selected, AnalogOutputStatus* value, StaticAnalogOutputStatusVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  AnalogOutputStatus  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  AOStatusConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_AnalogOutputStatus event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_AnalogOutputStatusSpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_AnalogOutputStatus;

void StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver1(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus);
void StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver2(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus,
    AOStatusConfig* config);
void  StaticDataCell_for_AnalogOutputStatus_in_StaticDataCell_for_AnalogOutputStatusOver3(StaticDataCell_for_AnalogOutputStatus *pStaticDataCell_for_AnalogOutputStatus,
    AnalogOutputStatus* value,
    AOStatusConfig* config);
//-------------------------------AnalogOutputStatus-------------------------------------------------
//-------------------------------OctetString-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  OctetString value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_OctetStringInfo variation;
} SelectedValue_for_OctetStringSpec;
void SelectedValue_for_OctetStringSpec_in_SelectedValue_for_OctetStringSpecOver1(SelectedValue_for_OctetStringSpec *pSelectedValue_for_OctetStringSpec);
void SelectedValue_for_OctetStringSpec_in_SelectedValue_for_OctetStringSpecOver2(SelectedValue_for_OctetStringSpec *pSelectedValue_for_OctetStringSpec,
                                          boolean selected, OctetString* value, StaticOctetStringVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  OctetString  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  OctetStringConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_OctetString event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_OctetStringSpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_OctetString;

void StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver1(StaticDataCell_for_OctetString *pStaticDataCell_for_OctetString);
void StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver2(StaticDataCell_for_OctetString *pStaticDataCell_for_OctetString,
    OctetStringConfig* config);
void  StaticDataCell_for_OctetString_in_StaticDataCell_for_OctetStringOver3(StaticDataCell_for_OctetString *pStaticDataCell_for_OctetString,
    OctetString* value,
    OctetStringConfig* config);
//-------------------------------OctetString-------------------------------------------------
//-------------------------------TimeAndInterval-------------------------------------------------
////template<class Spec> struct SelectedValue
typedef struct
{
////    SelectedValue() = default;

////    SelectedValue(bool selected, const typename Spec::meas_t& value, typename Spec::static_variation_t variation)
////        : selected(selected), value(value), variation(variation)
////    {
////    }

  boolean selected;// = false;
////    typename Spec::meas_t value;
  TimeAndInterval value;
////    typename Spec::static_variation_t variation = Spec::DefaultStaticVariation;
  static_variation_t_in_TimeAndIntervalInfo variation;
} SelectedValue_for_TimeAndIntervalSpec;
void SelectedValue_for_TimeAndIntervalSpec_in_SelectedValue_for_TimeAndIntervalSpecOver1(SelectedValue_for_TimeAndIntervalSpec *pSelectedValue_for_TimeAndIntervalSpec);
void SelectedValue_for_TimeAndIntervalSpec_in_SelectedValue_for_TimeAndIntervalSpecOver2(SelectedValue_for_TimeAndIntervalSpec *pSelectedValue_for_TimeAndIntervalSpec,
                                          boolean selected, TimeAndInterval* value, StaticTimeAndIntervalVariation_uint8_t variation);

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  TimeAndInterval  value_in_StaticDataCell;       // current value
////    typename Spec::config_t config;    // configuration
  TimeAndIntervalConfig  config_in_StaticDataCell;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_TimeAndInterval event_in_StaticDataCell; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_TimeAndIntervalSpec  selection_in_StaticDataCell;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_TimeAndInterval;

void StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver1(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval);
void StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver2(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval,
    TimeAndIntervalConfig* config);
void  StaticDataCell_for_TimeAndInterval_in_StaticDataCell_for_TimeAndIntervalOver3(StaticDataCell_for_TimeAndInterval *pStaticDataCell_for_TimeAndInterval,
    TimeAndInterval* value,
    TimeAndIntervalConfig* config);
//-------------------------------TimeAndInterval-------------------------------------------------


////} // namespace opendnp3

#endif
