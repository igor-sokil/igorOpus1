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
#ifndef OPENDNP3_DATABASECONFIG_H
#define OPENDNP3_DATABASECONFIG_H

//#include "opendnp3/outstation/MeasurementConfig.h"
//#include <QApplication>

#include "MeasurementConfig.h"


#include <map>

////namespace opendnp3
////{

////struct DatabaseConfig
typedef struct
{
////    DatabaseConfig() = default;

////    DatabaseConfig(uint16_t all_types);

    std::map<uint16_t, BinaryConfig_for_EventConfig_for_BinaryInfo> binary_input;
    std::map<uint16_t, DoubleBitBinaryConfig_for_EventConfig_for_DoubleBitBinaryInfo> double_binary;
    std::map<uint16_t, AnalogConfig_for_DeadbandConfig_for_AnalogInfo> analog_input;
    std::map<uint16_t, CounterConfig_for_DeadbandConfig_for_CounterInfo> counter;
    std::map<uint16_t, FrozenCounterConfig_for_DeadbandConfig_for_FrozenCounterInfo> frozen_counter;
    std::map<uint16_t, BOStatusConfig_for_EventConfig_for_BinaryOutputStatusInfo> binary_output_status;
    std::map<uint16_t, AOStatusConfig_for_DeadbandConfig_for_AnalogOutputStatusInfo> analog_output_status;
    std::map<uint16_t, TimeAndIntervalConfig_for_StaticConfig_for_TimeAndIntervalInfo> time_and_interval;
    std::map<uint16_t, OctetStringConfig_for_EventConfig_for_OctetStringInfo> octet_string;

} DatabaseConfig;

   void DatabaseConfig_in_DatabaseConfig(uint16_t all_types);

////} // namespace opendnp3

#endif
