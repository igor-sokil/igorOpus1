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

/**
 * Holds particular measurement type in the database.
 */

////template<class Spec> struct StaticDataCell
typedef struct
{
///    typename Spec::meas_t value;       // current value
  Binary  value;       // current value
////    typename Spec::config_t config;    // configuration
  BinaryConfig_for_EventConfig_for_BinaryInfo  config;    // configuration
////    typename Spec::event_cell_t event; // event cell
  SimpleEventCell_for_Binary event; // event cell
////    SelectedValue<Spec> selection;     // selected value
  SelectedValue_for_BinarySpec  selection;     // selected value
////    StaticDataCell() = default;
////    StaticDataCell(const typename Spec::meas_t& value, const typename Spec::config_t& config)
///        : value(value), config(config)
////    {
////    }
////    StaticDataCell(const typename Spec::config_t& config) : config(config) {}
} StaticDataCell_for_Binary;

void StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver1(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
    BinaryConfig_for_EventConfig_for_BinaryInfo* config);
void  StaticDataCell_for_Binary_in_StaticDataCell_for_BinaryOver2(StaticDataCell_for_Binary *pStaticDataCell_for_Binary,
    Binary* value,
    BinaryConfig_for_EventConfig_for_BinaryInfo* config);


////} // namespace opendnp3

#endif
