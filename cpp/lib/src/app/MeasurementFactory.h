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
#ifndef OPENDNP3_MEASUREMENTFACTORY_H
#define OPENDNP3_MEASUREMENTFACTORY_H

////#include "opendnp3/app/AnalogCommandEvent.h"
////#include "opendnp3/app/AnalogOutput.h"
////#include "opendnp3/app/BinaryCommandEvent.h"
////#include "opendnp3/app/ControlRelayOutputBlock.h"
////#include "opendnp3/app/MeasurementTypes.h"
////#include "opendnp3/util/StaticOnly.h"

#include "AnalogCommandEvent.h"
#include "AnalogOutput.h"
#include "BinaryCommandEvent.h"
#include "ControlRelayOutputBlock.h"
#include "MeasurementTypes.h"
//#include "/StaticOnly.h"

////namespace opendnp3
////{

////struct BinaryFactory : private StaticOnly
////{
////    inline static Binary From(uint8_t flags)
////    {
////        return Binary(Flags(flags));
////    }
////
////    inline static Binary From(uint8_t flags, uint16_t time)
////    {
////        return From(flags, DNPTime(time));
////    }
////
////    inline static Binary From(uint8_t flags, DNPTime time)
////    {
////        return Binary(Flags(flags), time);
////    }
////};

   Binary From_in_BinaryFactory_staticOver1(uint8_t flags);
   Binary From_in_BinaryFactory_staticOver2(uint8_t flags, uint16_t timeDNPTime);
   Binary From_in_BinaryFactory_staticOver3(uint8_t flags, DNPTime timeDNPTime);

////struct DoubleBitBinaryFactory : private StaticOnly
////{
////    inline static DoubleBitBinary From(uint8_t flags)
////    {
////        return DoubleBitBinary(Flags(flags));
////    }
////
////    inline static DoubleBitBinary From(uint8_t flags, uint16_t time)
////    {
////        return From(flags, DNPTime(time));
////    }
////
////    inline static DoubleBitBinary From(uint8_t flags, DNPTime time)
////    {
////        return DoubleBitBinary(Flags(flags), time);
////    }
////};

   DoubleBitBinary From_in_DoubleBitBinaryFactory_staticOver1(uint8_t flags);
   DoubleBitBinary From_in_DoubleBitBinaryFactory_staticOver2(uint8_t flags, uint16_t timeDNPTime);
   DoubleBitBinary From_in_DoubleBitBinaryFactory_staticOver3(uint8_t flags, DNPTime timeDNPTime);


////struct AnalogFactory : private StaticOnly
////{
////    static Analog From(int32_t count)
////    {
////        return Analog(count);
////    }
////    static Analog From(uint8_t flags, double value)
////    {
////        return Analog(value, Flags(flags));
////    }
////    static Analog From(uint8_t flags, double value, DNPTime time)
////    {
////        return Analog(value, Flags(flags), time);
////    }
////};

    Analog From_in_AnalogFactory_staticOver1(int32_t count);
    Analog From_in_AnalogFactory_staticOver2(uint8_t flags, double value);
    Analog From_in_AnalogFactory_staticOver3(uint8_t flags, double value, DNPTime timeDNPTime);

////struct CounterFactory : private StaticOnly
////{
////    inline static Counter From(uint32_t count)
////    {
////        return Counter(count);
////    }
////    inline static Counter From(uint8_t flags, uint32_t count)
////    {
////        return Counter(count, Flags(flags));
////    }
////    inline static Counter From(uint8_t flags, uint32_t count, DNPTime time)
////    {
////        return Counter(count, Flags(flags), time);
////    }
////};

    Counter From_in_CounterFactory_staticOver1(uint32_t count);
    Counter From_in_CounterFactory_staticOver2(uint8_t flags, uint32_t count);
    Counter From_in_CounterFactory_staticOver3(uint8_t flags, uint32_t count, DNPTime timeDNPTime);


////struct FrozenCounterFactory : private StaticOnly
////{
////    inline static FrozenCounter From(uint32_t count)
////    {
////        return FrozenCounter(count);
////    }
////    inline static FrozenCounter From(uint8_t flags, uint32_t count)
////    {
////        return FrozenCounter(count, Flags(flags));
////    }
////    inline static FrozenCounter From(uint8_t flags, uint32_t count, DNPTime time)
////    {
////        return FrozenCounter(count, Flags(flags), time);
////    }
////};

    FrozenCounter From_in_FrozenCounterFactory_staticOver1(uint32_t count);
    FrozenCounter From_in_FrozenCounterFactory_staticOver2(uint8_t flags, uint32_t count);
    FrozenCounter From_in_FrozenCounterFactory_staticOver3(uint8_t flags, uint32_t count, DNPTime timeDNPTime);

////struct TimeAndIntervalFactory : private StaticOnly
////{
////    inline static TimeAndInterval From(DNPTime time, uint32_t interval, uint8_t units)
////    {
////        return TimeAndInterval(time, interval, units);
////    }
////};
  TimeAndInterval From_in_TimeAndIntervalFactory_static(DNPTime timeDNPTime, uint32_t interval, uint8_t units);


////struct ControlRelayOutputBlockFactory : private StaticOnly
////{
////    inline static ControlRelayOutputBlock From(
////        uint8_t code, uint8_t count, uint32_t onTime, uint32_t offTime, uint8_t status)
////    {
////        return ControlRelayOutputBlock(code, count, onTime, offTime, CommandStatusSpec::from_type(status));
////    }
////};
   ControlRelayOutputBlock From_in_ControlRelayOutputBlock_static(
        uint8_t code, uint8_t count, uint32_t onTime, uint32_t offTime, uint8_t status);


////struct BinaryOutputStatusFactory : private StaticOnly
////{
////    inline static BinaryOutputStatus From(uint8_t flags)
////    {
////        return BinaryOutputStatus(Flags(flags));
////    }
////
////    inline static BinaryOutputStatus From(uint8_t flags, DNPTime time)
////    {
////        return BinaryOutputStatus(Flags(flags), time);
////    }
////};
////
   BinaryOutputStatus From_in_BinaryOutputStatusFactory_staticOver1(uint8_t flags);
   BinaryOutputStatus From_in_BinaryOutputStatusFactory_staticOver2(uint8_t flags, DNPTime timeDNPTime);

////struct BinaryCommandEventFactory : private StaticOnly
////{
////    inline static BinaryCommandEvent From(uint8_t flags)
////    {
////        return BinaryCommandEvent(Flags(flags));
////    }
////
////    inline static BinaryCommandEvent From(uint8_t flags, DNPTime time)
////    {
////        return BinaryCommandEvent(Flags(flags), time);
////    }
////};

   BinaryCommandEvent From_in_BinaryCommandEventFactory_staticOver1(uint8_t flags);
   BinaryCommandEvent From_in_BinaryCommandEventFactory_staticOver2(uint8_t flags, DNPTime timeDNPTime);

////struct AnalogOutputStatusFactory : private StaticOnly
////{
////    inline static AnalogOutputStatus From(uint8_t flags, double value)
////    {
////        return AnalogOutputStatus(value, Flags(flags));
////    }
////
////    inline static AnalogOutputStatus From(uint8_t flags, double value, DNPTime time)
////    {
////        return AnalogOutputStatus(value, Flags(flags), time);
////    }
////};
    AnalogOutputStatus From_in_AnalogOutputStatusFactory_staticOver1(uint8_t flags, double value);
    AnalogOutputStatus From_in_AnalogOutputStatusFactory_staticOver2(uint8_t flags, double value, DNPTime timeDNPTime);



////struct AnalogCommandEventFactory : private StaticOnly
////{
////    inline static AnalogCommandEvent From(uint8_t status, double value)
////    {
////        return AnalogCommandEvent(value, CommandStatusSpec::from_type(status));
////    }
////
////    inline static AnalogCommandEvent From(uint8_t status, double value, DNPTime time)
////    {
////        return AnalogCommandEvent(value, CommandStatusSpec::from_type(status), time);
////    }
////};

    AnalogCommandEvent From_in_AnalogCommandEventFactory_staticOver1(uint8_t status, double value);
    AnalogCommandEvent From_in_AnalogCommandEventFactory_staticOver2(uint8_t status, double value, DNPTime timeDNPTime);


////template<class Target, class ValueType> struct AnalogOutputFactory : private StaticOnly
////{
////    inline static Target From(ValueType value, uint8_t status)
////    {
////        return Target(value, CommandStatusSpec::from_type(status));
////    }
////};

//using AnalogOutputInt32Factory = AnalogOutputFactory<AnalogOutputInt32, int32_t>;
#define From_in_AnalogOutputInt32Factory(value, status) From_in_AnalogOutputFactory_for_Int32_t_static(value, status)
   AnalogOutputInt32 From_in_AnalogOutputFactory_for_Int32_t_static(int32_t value, uint8_t status);


//using AnalogOutputInt16Factory = AnalogOutputFactory<AnalogOutputInt16, int16_t>;
#define From_in_AnalogOutputInt16Factory(value, status) From_in_AnalogOutputFactory_for_Int16_t_static(value, status)
   AnalogOutputInt16 From_in_AnalogOutputFactory_for_Int16_t_static(int16_t value, uint8_t status);


//using AnalogOutputFloat32Factory = AnalogOutputFactory<AnalogOutputFloat32, float>;
#define From_in_AnalogOutputFloat32Factory(value, status) From_in_AnalogOutputFactory_for_Float32_static(value, status)
   AnalogOutputFloat32 From_in_AnalogOutputFactory_for_Float32_static(float value, uint8_t status);

//using AnalogOutputDouble64Factory = AnalogOutputFactory<AnalogOutputDouble64, double>;
#define From_in_AnalogOutputDouble64Factory(value, status) From_in_AnalogOutputFactory_for_Double64_static(value, status)
   AnalogOutputDouble64 From_in_AnalogOutputFactory_for_Double64_static(double value, uint8_t status);


////} // namespace opendnp3

#endif
