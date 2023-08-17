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
#ifndef OPENDNP3_UNITTESTS_DATABASE_HELPERS_H
#define OPENDNP3_UNITTESTS_DATABASE_HELPERS_H

////#include <opendnp3/outstation/DatabaseConfig.h>
#include "DatabaseConfig.h"

////namespace configure
////{

////namespace by_count_of
////{
DatabaseConfig all_types_in_DatabaseHelpers(uint16_t num);
DatabaseConfig binary_input_in_DatabaseHelpers(uint16_t num);
DatabaseConfig counter_in_DatabaseHelpers(uint16_t num, boolean with_frozen);// = false);
DatabaseConfig binary_output_status_in_DatabaseHelpers(uint16_t num);
DatabaseConfig analog_input_in_DatabaseHelpers(uint16_t num);
DatabaseConfig analog_output_status_in_DatabaseHelpers(uint16_t num);
DatabaseConfig time_and_interval_in_DatabaseHelpers(uint16_t num);
DatabaseConfig octet_string_in_DatabaseHelpers(uint16_t num);

////} // namespace by_count_of

DatabaseConfig from_AnalogConfig_in_DatabaseHelpers(std::map<uint16_t, AnalogConfig> map);
DatabaseConfig from_BinaryConfig_in_DatabaseHelpers(std::map<uint16_t, BinaryConfig> map);

AnalogConfig analog_in_DatabaseHelpers(StaticAnalogVariation_uint8_t variation);

DatabaseConfig database_by_sizes_in_DatabaseHelpers(uint16_t num_binary,
    uint16_t num_double_binary,
    uint16_t num_analog,
    uint16_t num_counter,
    uint16_t num_frozen_counter,
    uint16_t num_binary_output_status,
    uint16_t num_analog_output_status,
    uint16_t num_time_and_interval,
    uint16_t num_octet_string);

////} // namespace configure

#endif
