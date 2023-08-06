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
#ifndef OPENDNP3_EVENTTYPE_H
#define OPENDNP3_EVENTTYPE_H

////#include <cstdint>

////namespace opendnp3
////{

//enum class EventType : uint16_t
#define EventType_uint16_t uint16_t
enum EventType
{
  EventType_Binary = 0,
  EventType_Analog = 1,
  EventType_Counter = 2,
  EventType_FrozenCounter = 3,
  EventType_DoubleBitBinary = 4,
  EventType_BinaryOutputStatus = 5,
  EventType_AnalogOutputStatus = 6,
  EventType_OctetString = 7
};

//enum class EventClass : uint8_t
#define EventClass_uint8_t uint8_t
enum EventClass
{
  EventClass_EC1 = 0,
  EventClass_EC2 = 1,
  EventClass_EC3 = 2
};

////} // namespace opendnp3

#endif
