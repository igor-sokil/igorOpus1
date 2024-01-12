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
////#include "opendnp3/util/TimeDuration.h"
#include "header.h"
#include "TimeDuration.h"

////#include <exe4cpp/Typedefs.h>

////namespace opendnp3
////{
////
TimeDuration Min_in_TimeDuration_static(void)
{
////    return TimeDuration(exe4cpp::duration_t::min());
  TimeDuration tTimeDuration;
  TimeDuration_in_TimeDuration(&tTimeDuration, 0);
  return tTimeDuration;
}

TimeDuration Max_in_TimeDuration_static(void)
{
////    return TimeDuration(exe4cpp::duration_t::max());
  TimeDuration tTimeDuration;
  TimeDuration_in_TimeDuration(&tTimeDuration, 0x7FFFFFFFFFFFFFFF);
  return tTimeDuration;
}
////
////TimeDuration TimeDuration::Zero()
////{
////    return TimeDuration(std::chrono::milliseconds(0));
////}
////
////template<class T> TimeDuration TimeDuration::FromValue(int64_t value)
TimeDuration FromValue_in_TimeDuration_static(int64_t value)
{
////    // > this will overflow when converting to nanos
////    const auto MAX = std::chrono::duration_cast<T>(std::chrono::steady_clock::duration::max()).count();
////    const auto MIN = std::chrono::duration_cast<T>(std::chrono::steady_clock::duration::min()).count();
////
////    if (value > MAX)
////    {
////        return TimeDuration(std::chrono::steady_clock::duration::max());
////    }
////
////    if (value < MIN)
////    {
////        return TimeDuration(std::chrono::steady_clock::duration::min());
////    }
////
  TimeDuration tTimeDuration;
////    return TimeDuration(T(value));
  TimeDuration_in_TimeDuration(&tTimeDuration, value);
  return tTimeDuration;
}

////TimeDuration TimeDuration::Milliseconds(int64_t milliseconds)
TimeDuration Milliseconds_in_TimeDuration_static(int64_t milliseconds)
{
////    return FromValue<std::chrono::milliseconds>(milliseconds);
  return FromValue_in_TimeDuration_static(milliseconds);
}

TimeDuration Seconds_in_TimeDuration_static(int64_t seconds)
{
  return FromValue_in_TimeDuration_static(seconds*1000);
}

TimeDuration Minutes_in_TimeDuration_static(int64_t minutes)
{
  return Seconds_in_TimeDuration_static(60*minutes);
}
////TimeDuration TimeDuration::Minutes(int64_t minutes)
////{
////    return FromValue<std::chrono::minutes>(minutes);
////}
////
////
////TimeDuration::TimeDuration() : value(std::chrono::milliseconds(0)) {}

////TimeDuration TimeDuration::Double() const
TimeDuration Double_in_TimeDuration(TimeDuration *pTimeDuration)
{
  TimeDuration dmax = Max_in_TimeDuration_static();
////    const bool doubling_would_cause_mult_overflow = this->value >= exe4cpp::duration_t::max() / 2;
  boolean doubling_would_cause_mult_overflow = pTimeDuration->duration_value >= dmax.duration_value / 2;

////    return doubling_would_cause_mult_overflow ? TimeDuration::Max() : TimeDuration(this->value + this->value);
  TimeDuration ret;
  TimeDuration_in_TimeDuration(&ret, pTimeDuration->duration_value + pTimeDuration->duration_value);
  return doubling_would_cause_mult_overflow ? dmax : ret;
}

////bool TimeDuration::IsNegative() const
boolean IsNegative_in_TimeDuration(TimeDuration* pTimeDuration)
{
////    return *this < TimeDuration::Zero();
  return pTimeDuration->duration_value < 0;
}
////
////std::string TimeDuration::ToString() const
////{
////    const auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(value).count();
////
////    return std::to_string(millis);
////}
////
////bool TimeDuration::operator==(const TimeDuration& other) const
////{
////    return this->value == other.value;
////}
////
boolean operatorLT_in_TimeDuration(TimeDuration *pTimeDuration, TimeDuration* other)
{
  return pTimeDuration->duration_value < other->duration_value;
}
////
////bool TimeDuration::operator<=(const TimeDuration& other) const
////{
////    return this->value <= other.value;
////}
////
////bool TimeDuration::operator>(const TimeDuration& other) const
////{
////    return this->value > other.value;
////}
////
////bool TimeDuration::operator>=(const TimeDuration& other) const
////{
////    return this->value >= other.value;
////}
////
void TimeDuration_in_TimeDuration(TimeDuration *pTimeDuration, int64_t value)
{
////exe4cpp::duration_t value) : value(value) {}
  pTimeDuration->duration_value = value;
}
////
////} // namespace opendnp3
