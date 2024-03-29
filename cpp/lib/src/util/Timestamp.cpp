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
////#include "opendnp3/util/Timestamp.h"
#include "header.h"
#include "Timestamp.h"

////#include <exe4cpp/Typedefs.h>

////namespace opendnp3
////{

////Timestamp Timestamp::Max()
Timestamp Max_in_Timestamp_static(void)
{
////    return Timestamp(exe4cpp::steady_time_t::max());
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, 0x7FFFFFFFFFFFFFFF);
  return tTimestamp;
}

////Timestamp Timestamp::Min()
Timestamp Min_in_Timestamp_static(void)
{
////    return Timestamp(exe4cpp::steady_time_t::min());
  Timestamp tTimestamp;
  Timestamp_in_TimestampOver2(&tTimestamp, 0);
  return tTimestamp;
}

////bool Timestamp::IsMax() const
////{
////    return value == exe4cpp::steady_time_t::max();
////}

////bool Timestamp::IsMin() const
////{
////    return value == exe4cpp::steady_time_t::min();
////}

void Timestamp_in_TimestampOver1(Timestamp *pTimestamp)
{
////: value(exe4cpp::steady_time_t::min()) {}
  pTimestamp->time_point_value = 0;
}

void Timestamp_in_TimestampOver2(Timestamp *pTimestamp, uint64_t value)
{
  pTimestamp->time_point_value = value;
}

////Timestamp::Timestamp(exe4cpp::steady_time_t value) : value(value) {}

////Timestamp Timestamp::operator+(const TimeDuration& duration) const
Timestamp operatorPLUS_in_Timestamp(Timestamp *pTimestamp, TimeDuration* duration)
{
////    const auto maximum = exe4cpp::steady_time_t::max() - value;
  Timestamp smax = Max_in_Timestamp_static();
  Timestamp maximum;
  Timestamp_in_TimestampOver2(&maximum, smax.time_point_value - pTimestamp->time_point_value);

  Timestamp ret;
  Timestamp_in_TimestampOver2(&ret, pTimestamp->time_point_value + duration->duration_value);

////    return duration.value >= maximum ? Timestamp::Max() : Timestamp(value + duration.value);
  return (uint64_t)duration->duration_value >= maximum.time_point_value ? Max_in_Timestamp_static() : ret;
}

////Timestamp& Timestamp::operator+=(const TimeDuration& duration)
////{
////    const auto result = *this + duration;
////    this->value = result.value;
////    return *this;
////}

////Timestamp Timestamp::operator-(const TimeDuration& duration) const
////{
////    const auto maximum = value - exe4cpp::steady_time_t::min();

////    return duration.value >= maximum ? Timestamp::Min() : Timestamp(value - duration.value);
////}

////Timestamp& Timestamp::operator-=(const TimeDuration& duration)
///{
////    const auto result = *this - duration;
////    this->value = result.value;
////    return *this;
////}

////TimeDuration Timestamp::operator-(const Timestamp& timestamp) const
TimeDuration operatorMINUS_in_Timestamp(Timestamp* pTimestamp, Timestamp* timestamp)
{
  TimeDuration tTimeDuration;
// void TimeDuration_in_TimeDuration(TimeDuration *pTimeDuration, uint64_t value);
////    return TimeDuration(this->value - timestamp.value);
  TimeDuration_in_TimeDuration(&tTimeDuration, pTimestamp->time_point_value - timestamp->time_point_value);
  return tTimeDuration;
}

////bool Timestamp::operator==(const Timestamp& other) const
boolean  operatorEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other)
{
  return pTimestamp->time_point_value == other->time_point_value;
}

////bool Timestamp::operator!=(const Timestamp& other) const
////{
////    return this->value != other.value;
////}

////bool Timestamp::operator<(const Timestamp& other) const
////{
////    return this->value < other.value;
////}
boolean  operatorLT_in_Timestamp(Timestamp* pTimestamp, Timestamp* other)
{
  return pTimestamp->time_point_value < other->time_point_value;
}

////bool Timestamp::operator<=(const Timestamp& other) const
boolean  operatorLTEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other)
{
  return pTimestamp->time_point_value <= other->time_point_value;
}

////bool Timestamp::operator>(const Timestamp& other) const
////{
////    return this->value > other.value;
////}

////bool Timestamp::operator>=(const Timestamp& other) const
boolean  operatorGTEQ_in_Timestamp(Timestamp* pTimestamp, Timestamp* other)
{
////    return this->value >= other.value;
  return pTimestamp->time_point_value >= other->time_point_value;
}

////} // namespace opendnp3
