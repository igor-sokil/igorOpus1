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
#include "DatabaseConfig.h"

////namespace opendnp3
////{
////template<class T>
void initialize_BinaryConfig(std::map<uint16_t, BinaryConfig>& map, uint16_t count)
{
  BinaryConfig bBinaryConfig;
  BinaryConfig_in_BinaryConfig(&bBinaryConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = bBinaryConfig;//{};
  }
}
////template<class T>
void initialize_DoubleBitBinaryConfig(std::map<uint16_t, DoubleBitBinaryConfig>& map, uint16_t count)
{
  DoubleBitBinaryConfig dDoubleBitBinaryConfig;
  DoubleBitBinaryConfig_in_DoubleBitBinaryConfig(&dDoubleBitBinaryConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = dDoubleBitBinaryConfig;//{};
  }
}
////template<class T>
void initialize_AnalogConfig(std::map<uint16_t, AnalogConfig>& map, uint16_t count)
{
  AnalogConfig aAnalogConfig;
  AnalogConfig_in_AnalogConfig(&aAnalogConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = aAnalogConfig;//{};
  }
}
////template<class T>
void initialize_CounterConfig(std::map<uint16_t, CounterConfig>& map, uint16_t count)
{
  CounterConfig cCounterConfig;
  CounterConfig_in_CounterConfig(&cCounterConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = cCounterConfig;//{};
  }
}
////template<class T>
void initialize_FrozenCounterConfig(std::map<uint16_t, FrozenCounterConfig>& map, uint16_t count)
{
  FrozenCounterConfig fFrozenCounterConfig;
  FrozenCounterConfig_in_FrozenCounterConfig(&fFrozenCounterConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = fFrozenCounterConfig;//{};
  }
}
void initialize_BOStatusConfig(std::map<uint16_t, BOStatusConfig>& map, uint16_t count)
{
  BOStatusConfig bBOStatusConfig;
  BOStatusConfig_in_BOStatusConfig(&bBOStatusConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = bBOStatusConfig;//{};
  }
}
void initialize_AOStatusConfig(std::map<uint16_t, AOStatusConfig>& map, uint16_t count)
{
  AOStatusConfig aAOStatusConfig;
  AOStatusConfig_in_AOStatusConfig(&aAOStatusConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = aAOStatusConfig;//{};
  }
}
void initialize_TimeAndIntervalConfig(std::map<uint16_t, TimeAndIntervalConfig>& map, uint16_t count)
{
  TimeAndIntervalConfig tTimeAndIntervalConfig;
  TimeAndIntervalConfig_in_TimeAndIntervalConfig(&tTimeAndIntervalConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = tTimeAndIntervalConfig;//{};
  }
}
void initialize_OctetStringConfig(std::map<uint16_t, OctetStringConfig>& map, uint16_t count)
{
  OctetStringConfig oOctetStringConfig;
  OctetStringConfig_in_OctetStringConfig(&oOctetStringConfig);
  for (uint16_t i = 0; i < count; ++i)
  {
    map[i] = oOctetStringConfig;//{};
  }
}

void DatabaseConfig_in_DatabaseConfig_default(DatabaseConfig *pDatabaseConfig)
{
 UNUSED(pDatabaseConfig);
}

void DatabaseConfig_in_DatabaseConfig(DatabaseConfig *pDatabaseConfig, uint16_t all_types)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"DatabaseConfig_in_DatabaseConfig1"<<'\n';
  decrement_stack_info();
#endif
////  initialize(this->binary_input, all_types);
  initialize_BinaryConfig(pDatabaseConfig->binary_input, all_types);

////  initialize(this->double_binary, all_types);
  initialize_DoubleBitBinaryConfig(pDatabaseConfig->double_binary, all_types);

////  initialize(this->analog_input, all_types);
  initialize_AnalogConfig(pDatabaseConfig->analog_input, all_types);

////  initialize(this->counter, all_types);
  initialize_CounterConfig(pDatabaseConfig->counter, all_types);

////  initialize(this->frozen_counter, all_types);
  initialize_FrozenCounterConfig(pDatabaseConfig->frozen_counter, all_types);

////  initialize(this->binary_output_status, all_types);
  initialize_BOStatusConfig(pDatabaseConfig->binary_output_status, all_types);

////  initialize(this->analog_output_status, all_types);
  initialize_AOStatusConfig(pDatabaseConfig->analog_output_status, all_types);

////  initialize(this->time_and_interval, all_types);
  initialize_TimeAndIntervalConfig(pDatabaseConfig->time_and_interval, all_types);

////  initialize(this->octet_string, all_types);
  initialize_OctetStringConfig(pDatabaseConfig->octet_string, all_types);
};

////} // namespace opendnp3
