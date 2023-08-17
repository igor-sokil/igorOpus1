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
#ifndef OPENDNP3_DOWNSAMPLING_H
#define OPENDNP3_DOWNSAMPLING_H

////#include "opendnp3/util/Uncopyable.h"

////#include <cstdint>
////#include <limits>
#include "MeasurementTypes.h"

////namespace opendnp3
////{

// A safe down sampling class
////template<class Source, class Target> class DownSampling : private Uncopyable
////{
////    static const Target TARGET_MAX;
////    static const Target TARGET_MIN;

////public:
////    static bool Apply(Source src, Target& target)
////    {
////        if (src > TARGET_MAX)
////        {
////            target = TARGET_MAX;
////            return true;
////        }
////        else if (src < TARGET_MIN)
////        {
////            target = TARGET_MIN;
////            return true;
////        }
////        else
////        {
////            target = static_cast<Target>(src);
////            return false;
////        }
////    }
////};

boolean Apply_in_DownSampling_for_uint32(double src, uint32_t *target);
boolean Apply_in_DownSampling_for_uint16(double src, uint16_t *target);
boolean Apply_in_DownSampling_for_Float32(double src, float *target);

////template<class Source, class Target>
////const Target DownSampling<Source, Target>::TARGET_MAX(std::numeric_limits<Target>::max());
const double TARGET_MAX_for_double = (double) 0xFFFFFFFFFFFFFFFF;////(std::numeric_limits<double>::max());
const float TARGET_MAX_for_float  = (float)  0xFFFFFFFF;////(std::numeric_limits<double>::max());
const uint32_t TARGET_MAX_for_uint32 = (uint32_t) 0x7FFFFFFF;////(std::numeric_limits<uint32_t>::max());
const uint16_t TARGET_MAX_for_uint16 = (uint16_t) 0x7FFF;////(std::numeric_limits<uint16_t>::max());

////template<class Source, class Target>
////const Target DownSampling<Source, Target>::TARGET_MIN(std::numeric_limits<Target>::lowest());
const double TARGET_MIN_for_double = -((double) 0xFFFFFFFFFFFFFFFF);////(std::numeric_limits<double>::lowest());
const float TARGET_MIN_for_float  = -((float)  0xFFFFFFFF);////(std::numeric_limits<double>::lowest());
const uint32_t TARGET_MIN_for_uint32 = 0x80000000;////(std::numeric_limits<uint32_t>::lowest());
const uint16_t TARGET_MIN_for_uint16 = 0x8000;////(std::numeric_limits<uint16_t>::lowest());

////} // namespace opendnp3

#endif
