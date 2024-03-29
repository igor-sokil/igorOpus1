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
#ifndef OPENDNP3_TIMESTAMP_H
#define OPENDNP3_TIMESTAMP_H

#include "TimeDuration.h"

////namespace opendnp3
////{

/**
 *  Strong typing for millisecond-based monotonic timestamps
 */
////class Timestamp
typedef struct
{

////public:
////    static Timestamp Max();
////    static Timestamp Min();

////    Timestamp();
////    explicit Timestamp(std::chrono::steady_clock::time_point value);

////    bool IsMax() const;
////    bool IsMin() const;

  // overflow capped to maximum value
////    Timestamp operator+(const TimeDuration& duration) const;
////    Timestamp& operator+=(const TimeDuration& duration);
////    Timestamp operator-(const TimeDuration& duration) const;
////    Timestamp& operator-=(const TimeDuration& duration);

////    TimeDuration operator-(const Timestamp& timestamp) const;

////    bool operator==(const Timestamp& other) const;
////    bool operator!=(const Timestamp& other) const;
////    bool operator<(const Timestamp& other) const;
////    bool operator<=(const Timestamp& other) const;
////    bool operator>(const Timestamp& other) const;
////    bool operator>=(const Timestamp& other) const;

////    std::chrono::steady_clock::time_point value;
  uint64_t time_point_value;
} Timestamp;
void Timestamp_in_TimestampOver1(Timestamp *pTimestamp);
void Timestamp_in_TimestampOver2(Timestamp *pTimestamp, uint64_t value);
boolean  operatorEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other);
boolean  operatorLTEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other);
boolean  operatorGTEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other);
boolean  operatorLT_in_Timestamp(Timestamp* pTimestamp, Timestamp* other);
TimeDuration operatorMINUS_in_Timestamp(Timestamp* pTimestamp, Timestamp* timestamp);
Timestamp operatorPLUS_in_Timestamp(Timestamp *pTimestamp, TimeDuration* duration);

Timestamp Max_in_Timestamp_static(void);
////    static Timestamp Min();
Timestamp Min_in_Timestamp_static(void);

////} // namespace opendnp3

#endif
