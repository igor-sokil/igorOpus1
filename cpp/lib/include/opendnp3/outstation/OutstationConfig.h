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
#ifndef OPENDNP3_OUTSTATIONCONFIG_H
#define OPENDNP3_OUTSTATIONCONFIG_H

////#include "opendnp3/outstation/EventBufferConfig.h"
////#include "opendnp3/outstation/OutstationParams.h"
////#include "opendnp3/util/TimeDuration.h"

#include "EventBufferConfig.h"
#include "OutstationParams.h"
//#include "TimeDuration.h"

//extern boolean expectsContents;//_in_RangeParser;
//extern boolean expectsContents_in_CountIndexParser;
//extern boolean expectsContents_in_CountParser;

////namespace opendnp3
////{

/** Configuration information for a dnp3 outstation (outstation)

Used as both input describing the startup configuration of the outstation, and as configuration state of mutable
properties (i.e. unsolicited responses).

Major feature areas are unsolicited responses, time synchronization requests, event buffer limits, and the DNP3
object/variations to use by default when the master requests class data or variation 0.
»спользуетс€ как вход, описывающий конфигурацию запуска удаленной станции, так и как состо€ние конфигурации измен€емого
свойства (т. е. нежелательные ответы).

ќсновными област€ми функций €вл€ютс€ незапрошенные ответы, запросы синхронизации времени, ограничени€ буфера событий и протокол DNP3.
объект/вариации, которые будут использоватьс€ по умолчанию, когда мастер запрашивает данные класса или вариант 0.

*/
////struct OutstationConfig
typedef struct
{
  /// Various parameters that govern outstation behavior
  OutstationParams params;

  /// Describes the sizes in the event buffer
  EventBufferConfig eventBufferConfig;
} OutstationConfig;
void OutstationConfig_in_OutstationConfig(OutstationConfig *pOutstationConfig);

////} // namespace opendnp3

#endif
