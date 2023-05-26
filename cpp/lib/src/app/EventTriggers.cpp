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
////#include "opendnp3/app/EventTriggers.h"
#include "header.h"
#include "EventTriggers.h"
#include <math.h>

////#include <cmath>

////namespace opendnp3
////{
////namespace measurements
////{
////    boolean IsEvent_in_EventTriggers(const TypedMeasurement<double>& newMeas, const TypedMeasurement<double>& oldMeas, double deadband)
    boolean IsEvent_in_EventTriggers_for_TypedMeasurement_for_Double64(
                                     TypedMeasurement_for_Double64 *newMeas,
                                     TypedMeasurement_for_Double64 *oldMeas,
                                     double deadband)
{
        if ((newMeas->mMeasurement).flags.value != (oldMeas->mMeasurement).flags.value)
        {
            return true;
        }
        double diff = fabs(newMeas->value - oldMeas->value);

        return diff > deadband;
}

    boolean IsEvent_in_EventTriggers_for_TypedMeasurement_for_Uint32(
                                     TypedMeasurement_for_Uint32 *val1,
                                     TypedMeasurement_for_Uint32 *val2,
                                     uint32_t deadband)
{
//       uint32_t diff = (val2 > val1) ? (static_cast<U>(val2) - static_cast<U>(val1))
//                               : (static_cast<U>(val1) - static_cast<U>(val2));

       uint32_t diff = (val2->value > val1->value) ? ((uint32_t)(val2->value) - (uint32_t)(val1->value))
                               : ((uint32_t)(val1->value) - (uint32_t)(val2->value));

        return diff > deadband;
}

/*
    boolean IsEvent_in_EventTriggers(double *newMeas, double *oldMeas, double deadband)
    {
        if (newMeas.flags.value != oldMeas.flags.value)
        {
            return true;
        }

        double diff = fabs(newMeas.value - oldMeas.value);
        if (diff == INFINITY)
        {
            return true;
        }

        return diff > deadband;
    }
*/
////} // namespace measurements
////
////} // namespace opendnp3
