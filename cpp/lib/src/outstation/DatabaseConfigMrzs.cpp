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
//#include <QApplication>
#include "header.h"
#include "DatabaseConfigMrzs.h"

////namespace opendnp3
////{
////template<class T>

static DatabaseConfigMrzs dDatabaseConfigMrzs;//database config

DatabaseConfigMrzs *getDatabaseConfigMrzs(void)
{
 return &dDatabaseConfigMrzs;
}
//void initialize_BinaryConfig(std::map<uint16_t, BinaryConfig>& map, uint16_t count)
void initialize_BinaryConfig_in_DatabaseConfigMrzs(uint16_t count)
{
  BinaryConfig bBinaryConfig;
  BinaryConfig_in_BinaryConfig(&bBinaryConfig);
  if(count > SIZE_BinaryConfig) count = SIZE_BinaryConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.binary_input[i] = bBinaryConfig;//{};
  }
  dDatabaseConfigMrzs.countBinary_input = count;
}
////template<class T>
void initialize_DoubleBitBinaryConfig_in_DatabaseConfigMrzs(uint16_t count)
{
  DoubleBitBinaryConfig dDoubleBitBinaryConfig;
  DoubleBitBinaryConfig_in_DoubleBitBinaryConfig(&dDoubleBitBinaryConfig);
  if(count > SIZE_DoubleBitBinaryConfig) count = SIZE_DoubleBitBinaryConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.double_binary[i] = dDoubleBitBinaryConfig;//{};
  }
  dDatabaseConfigMrzs.countDouble_binary = count;
}
////template<class T>
void initialize_AnalogConfig_in_DatabaseConfigMrzs(uint16_t count)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{initialize_AnalogConfig_in_DatabaseConfigMrzs1"<<'\n';
#endif
  AnalogConfig aAnalogConfig;
  AnalogConfig_in_AnalogConfig(&aAnalogConfig);
  if(count > SIZE_AnalogConfig) count = SIZE_AnalogConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.analog_input[i] = aAnalogConfig;//{};
  }
  dDatabaseConfigMrzs.sizeConfig_for_AnalogMrzs = count;
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"*dDatabaseConfigMrzs.sizeConfig_for_AnalogMrzs= "<<dDatabaseConfigMrzs.sizeConfig_for_AnalogMrzs<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}initialize_AnalogConfig_in_DatabaseConfigMrzs_"<<'\n';
  decrement_stack_info();
#endif
}
////template<class T>
void initialize_CounterConfig_in_DatabaseConfigMrzs(uint16_t count)
{
  CounterConfig cCounterConfig;
  CounterConfig_in_CounterConfig(&cCounterConfig);
  if(count > SIZE_CounterConfig) count = SIZE_CounterConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.counter[i] = cCounterConfig;//{};
  }
  dDatabaseConfigMrzs.countCounter = count;
}
////template<class T>
void initialize_FrozenCounterConfig_in_DatabaseConfigMrzs(uint16_t count)
{
  FrozenCounterConfig fFrozenCounterConfig;
  FrozenCounterConfig_in_FrozenCounterConfig(&fFrozenCounterConfig);
  if(count > SIZE_FrozenCounterConfig) count = SIZE_FrozenCounterConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.frozen_counter[i] = fFrozenCounterConfig;//{};
  }
  dDatabaseConfigMrzs.countFrozen_counter = count;
}
void initialize_BOStatusConfig_in_DatabaseConfigMrzs(uint16_t count)
{
  BOStatusConfig bBOStatusConfig;
  BOStatusConfig_in_BOStatusConfig(&bBOStatusConfig);
  if(count > SIZE_BOStatusConfig) count = SIZE_BOStatusConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.binary_output_status[i] = bBOStatusConfig;//{};
  }
  dDatabaseConfigMrzs.countBinary_output_status = count;
}
void initialize_AOStatusConfig_in_DatabaseConfigMrzs(uint16_t count)
{
  AOStatusConfig aAOStatusConfig;
  AOStatusConfig_in_AOStatusConfig(&aAOStatusConfig);
  if(count > SIZE_AOStatusConfig) count = SIZE_AOStatusConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.analog_output_status[i] = aAOStatusConfig;//{};
  }
  dDatabaseConfigMrzs.countAnalog_output_status = count;
}
void initialize_TimeAndIntervalConfig_in_DatabaseConfigMrzs(uint16_t count)
{
  TimeAndIntervalConfig tTimeAndIntervalConfig;
  TimeAndIntervalConfig_in_TimeAndIntervalConfig(&tTimeAndIntervalConfig);
  if(count > SIZE_TimeAndIntervalConfig) count = SIZE_TimeAndIntervalConfig;
  for (uint16_t i = 0; i < count; ++i)
  {
    dDatabaseConfigMrzs.time_and_interval[i] = tTimeAndIntervalConfig;//{};
  }
  dDatabaseConfigMrzs.countTime_and_interval = count;
}
//void initialize_OctetStringConfig(std::map<uint16_t, OctetStringConfig>& map, uint16_t count)
////{
////  OctetStringConfig oOctetStringConfig;
////  OctetStringConfig_in_OctetStringConfig(&oOctetStringConfig);
////  for (uint16_t i = 0; i < count; ++i)
////  {
////    map[i] = oOctetStringConfig;//{};
////  }
////}
/*
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
*/
////} // namespace opendnp3
