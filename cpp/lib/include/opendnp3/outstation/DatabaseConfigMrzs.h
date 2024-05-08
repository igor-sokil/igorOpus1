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
#ifndef OPENDNP3_DATABASECONFIGMRZS_H
#define OPENDNP3_DATABASECONFIGMRZS_H

//#include "opendnp3/outstation/MeasurementConfig.h"
//#include <QApplication>

#include "MeasurementConfig.h"

#define SIZE_BinaryConfig 100
#define SIZE_DoubleBitBinaryConfig 100
#define SIZE_AnalogConfig 100
#define SIZE_CounterConfig 100
#define SIZE_FrozenCounterConfig 100
#define SIZE_BOStatusConfig 100
#define SIZE_AOStatusConfig 100
#define SIZE_TimeAndIntervalConfig 100

////#include <map>

////namespace opendnp3
////{

////struct DatabaseConfig
typedef struct
{
////    DatabaseConfig() = default;

////    DatabaseConfig(uint16_t all_types);

//  std::map<uint16_t, BinaryConfig> binary_input;
  BinaryConfig binary_input[SIZE_BinaryConfig];
//  std::map<uint16_t, DoubleBitBinaryConfig> double_binary;
  DoubleBitBinaryConfig double_binary[SIZE_DoubleBitBinaryConfig];
//  std::map<uint16_t, AnalogConfig> analog_input;
  AnalogConfig analog_input[SIZE_AnalogConfig];
//  std::map<uint16_t, CounterConfig> counter;
  CounterConfig counter[SIZE_CounterConfig];
//  std::map<uint16_t, FrozenCounterConfig> frozen_counter;
  FrozenCounterConfig frozen_counter[SIZE_FrozenCounterConfig];
//  std::map<uint16_t, BOStatusConfig> binary_output_status;
  BOStatusConfig binary_output_status[SIZE_BOStatusConfig];
//  std::map<uint16_t, AOStatusConfig> analog_output_status;
  AOStatusConfig  analog_output_status[SIZE_AOStatusConfig];
//  std::map<uint16_t, TimeAndIntervalConfig> time_and_interval;
  TimeAndIntervalConfig time_and_interval[SIZE_TimeAndIntervalConfig];
//  std::map<uint16_t, OctetStringConfig> octet_string;

  uint16_t countBinary_input;
  uint16_t countDouble_binary;
  uint16_t sizeConfig_for_AnalogMrzs;
  uint16_t countCounter;
  uint16_t countFrozen_counter;
  uint16_t countBinary_output_status;
  uint16_t countAnalog_output_status;
  uint16_t countTime_and_interval;
} DatabaseConfigMrzs;

//void DatabaseConfig_in_DatabaseConfig_default(DatabaseConfig *pDatabaseConfig);
//void DatabaseConfig_in_DatabaseConfig(DatabaseConfig *pDatabaseConfig, uint16_t all_types);

DatabaseConfigMrzs *getDatabaseConfigMrzs(void);
void initialize_TimeAndIntervalConfig_in_DatabaseConfigMrzs(uint16_t count);
void initialize_AOStatusConfig_in_DatabaseConfigMrzs(uint16_t count);
void initialize_BOStatusConfig_in_DatabaseConfigMrzs(uint16_t count);
void initialize_FrozenCounterConfig_in_DatabaseConfigMrzs(uint16_t count);
void initialize_CounterConfig_in_DatabaseConfigMrzs(uint16_t count);
void initialize_AnalogConfig_in_DatabaseConfigMrzs(uint16_t count);
void initialize_DoubleBitBinaryConfig_in_DatabaseConfigMrzs(uint16_t count);
void initialize_BinaryConfig_in_DatabaseConfigMrzs(uint16_t count);

////} // namespace opendnp3

#endif
