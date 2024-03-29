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
#ifndef OPENDNP3_DNPTIME_H
#define OPENDNP3_DNPTIME_H

////#include "opendnp3/gen/TimestampQuality.h"
#include "TimestampQuality.h"

////#include <cstdint>

////namespace opendnp3
////{

////struct DNPTime
typedef struct
{
////    DNPTime() : value(0), quality(TimestampQuality::INVALID) {}
////    explicit DNPTime(uint64_t value) : value(value), quality(TimestampQuality::SYNCHRONIZED) {}
////    DNPTime(uint64_t value, TimestampQuality quality) : value(value), quality(quality) {}

////    bool operator==(const DNPTime& rhs) const
////    {
////        return this->value == rhs.value && this->quality == rhs.quality;
////    }

////    uint64_t value;
  uint64_t value;
////    TimestampQuality quality;
  TimestampQuality_uint8_t quality;
} DNPTime;

void DNPTime_in_DNPTimeOver1(DNPTime *pDNPTime);
void DNPTime_in_DNPTimeOver2(DNPTime *pDNPTime, uint64_t value);
void DNPTime_in_DNPTimeOver3(DNPTime *pDNPTime, uint64_t value, TimestampQuality_uint8_t quality);
boolean operatorEQ_in_DNPTime(DNPTime *pDNPTime, DNPTime *rhs);

////} // namespace opendnp3


#endif // namespace opendnp3
