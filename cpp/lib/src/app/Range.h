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
#ifndef OPENDNP3_RANGE_H
#define OPENDNP3_RANGE_H

////#include <ser4cpp/util/Comparisons.h>

////#include <cstddef>
////#include <cstdint>

////namespace opendnp3
////{

////class Range
typedef struct
{
////public:
////    static Range From(uint16_t start, uint16_t stop)
////    {
////        return Range(start, stop);
////    }

////    static Range Invalid()
////    {
////        return Range(1, 0);
////    }

////    Range() : start(1), stop(0) {}

////    size_t Count() const
////    {
////        return IsValid() ? (static_cast<size_t>(stop) - static_cast<size_t>(start) + 1) : 0;
////    }

////    bool Advance()
////    {
////        if (this->IsValid())
////        {
////            if (start < stop)
////            {
////                ++start;
////            }
////            else
////            {
////                // make the range invalid
////                start = 1;
////                stop = 0;
////            }
////
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }

////    bool Contains(uint16_t index) const
////    {
////        return (index >= start) && (index <= stop);
////    }

  /// @return A new range with only values found in both ranges
////    Range Intersection(const Range& other) const
////    {
////        return Range(ser4cpp::max<uint16_t>(start, other.start), ser4cpp::min<uint16_t>(stop, other.stop));
////    }

  /// @return A new range with min start and the max stop of both ranges
////    Range Union(const Range& other) const
////    {
////        if (!this->IsValid())
////        {
////            return other;
////        }

////        return Range(ser4cpp::min<uint16_t>(start, other.start), ser4cpp::max<uint16_t>(stop, other.stop));
////    }

////    bool Equals(const Range& other) const
////    {
////        return (other.start == start) && (other.stop == stop);
////    }

////    bool IsValid() const
////    {
////        return start <= stop;
////    }

////    bool IsOneByte() const
////    {
////        return IsValid() && (start <= 255) && (stop <= 255);
////    }

  uint16_t start;
  uint16_t stop;

////private:
////    Range(uint16_t index_) : start(index_), stop(index_) {}

////    Range(uint16_t start_, uint16_t stop_) : start(start_), stop(stop_) {}
} Range;

Range From_in_Range_static(uint16_t start, uint16_t stop);
Range Invalid_in_Range_static(void);
void Range_in_RangeOver1(Range *pRange);
uint32_t Count_in_Range(Range *pRange);
boolean Advance_in_Range(Range *pRange);
boolean Contains_in_Range(Range *pRange, uint16_t index);
uint16_t ser4cpp_max_uint16_t(uint16_t t1, uint16_t t2);
uint16_t ser4cpp_min_uint16_t(uint16_t t1, uint16_t t2);
boolean Equals_in_Range(Range *pRange, Range* other);
boolean IsValid_in_Range(Range *pRange);
boolean IsOneByte_in_Range(Range *pRange);
void Range_in_RangeOver2(Range *pRange, uint16_t index_);
void Range_in_RangeOver3(Range *pRange, uint16_t start_, uint16_t stop_);
Range Intersection_in_Range(Range *pRange, Range* other);
Range Union_in_Range(Range *pRange, Range* other);


////} // namespace opendnp3

#endif
