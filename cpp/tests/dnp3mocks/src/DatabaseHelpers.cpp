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

#include <QApplication>
#include "header.h"
#include "DatabaseHelpers.h"

////namespace configure
////{

////namespace by_count_of
////{
////    opendnp3::DatabaseConfig all_types(uint16_t num)
DatabaseConfig all_types_in_DatabaseHelpers(uint16_t num)
{
//void DatabaseConfig_in_DatabaseConfig(uint16_t all_types);
////        return opendnp3::DatabaseConfig(num);
  DatabaseConfig dDatabaseConfig;
  DatabaseConfig_in_DatabaseConfig(&dDatabaseConfig, num);
  return dDatabaseConfig;
}

DatabaseConfig binary_input_in_DatabaseHelpers(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpers(num, 0, 0, 0, 0, 0, 0, 0, 0);
}

DatabaseConfig counter_in_DatabaseHelpers(uint16_t num, boolean with_frozen)
{
  uint16_t num_frozen = with_frozen ? num : 0;
  return database_by_sizes_in_DatabaseHelpers(0, 0, 0, num, num_frozen, 0, 0, 0, 0);
}

DatabaseConfig binary_output_status_in_DatabaseHelpers(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpers(0, 0, 0, 0, 0, num, 0, 0, 0);
}

DatabaseConfig analog_input_in_DatabaseHelpers(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpers(0, 0, num, 0, 0, 0, 0, 0, 0);
}

DatabaseConfig analog_output_status_in_DatabaseHelpers(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpers(0, 0, 0, 0, 0, 0, num, 0, 0);
}

DatabaseConfig time_and_interval_in_DatabaseHelpers(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpers(0, 0, 0, 0, 0, 0, 0, num, 0);
}

DatabaseConfig octet_string_in_DatabaseHelpers(uint16_t num)
{
  return database_by_sizes_in_DatabaseHelpers(0, 0, 0, 0, 0, 0, 0, 0, num);
}

////} // namespace by_count_of

////opendnp3::DatabaseConfig from(std::map<uint16_t, opendnp3::AnalogConfig> map)
DatabaseConfig from_AnalogConfig_in_DatabaseHelpers(std::map<uint16_t, AnalogConfig> map)
{
  DatabaseConfig config;
  config.analog_input = std::move(map);
  return config;
}

////opendnp3::DatabaseConfig from(std::map<uint16_t, opendnp3::BinaryConfig> map)
DatabaseConfig from_BinaryConfig_in_DatabaseHelpers(std::map<uint16_t, BinaryConfig> map)
{
  DatabaseConfig config;
  config.binary_input = std::move(map);
  return config;
}

AnalogConfig analog_in_DatabaseHelpers(StaticAnalogVariation_uint8_t variation)
{
////    opendnp3::AnalogConfig config;
  AnalogConfig config;
  AnalogConfig_in_AnalogConfig(&config);

////    config.svariation = variation;
  config.dDeadbandConfig_for_AnalogInfo.eEventConfig.svariation = variation;
  return config;
}

DatabaseConfig database_by_sizes_in_DatabaseHelpers(uint16_t num_binary,
    uint16_t num_double_binary,
    uint16_t num_analog,
    uint16_t num_counter,
    uint16_t num_frozen_counter,
    uint16_t num_binary_output_status,
    uint16_t num_analog_output_status,
    uint16_t num_time_and_interval,
    uint16_t num_octet_string)
{
  DatabaseConfig config;

  for (uint16_t i = 0; i < num_binary; ++i)
  {
    config.binary_input[i] = {};
  }
  for (uint16_t i = 0; i < num_double_binary; ++i)
  {
    config.double_binary[i] = {};
  }
  for (uint16_t i = 0; i < num_analog; ++i)
  {
    config.analog_input[i] = {};
  }
  for (uint16_t i = 0; i < num_counter; ++i)
  {
    config.counter[i] = {};
  }
  for (uint16_t i = 0; i < num_frozen_counter; ++i)
  {
    config.frozen_counter[i] = {};
  }
  for (uint16_t i = 0; i < num_binary_output_status; ++i)
  {
    config.binary_output_status[i] = {};
  }
  for (uint16_t i = 0; i < num_analog_output_status; ++i)
  {
    config.analog_output_status[i] = {};
  }
  for (uint16_t i = 0; i < num_time_and_interval; ++i)
  {
    config.time_and_interval[i] = {};
  }
  for (uint16_t i = 0; i < num_octet_string; ++i)
  {
    config.octet_string[i] = {};
  }

  return config;
}

////} // namespace configure
