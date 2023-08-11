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
////#include "opendnp3/app/MeasurementTypes.h"

////#include "app/QualityFlags.h"

////#include "opendnp3/gen/BinaryQuality.h"
#include "header.h"
#include "MeasurementTypes.h"

#include "QualityFlags.h"

#include "BinaryQuality.h"

////namespace opendnp3
////{

// ------------ Binary ---------------

void Binary_in_BinaryOver1(Binary *pBinary)
{
//// : TypedMeasurement(false, flags::RESTART) {}
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_RESTART);
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinary->tTypedMeasurement_for_Boolean),
      false, fFlags);
}

void Binary_in_BinaryOver2(Binary *pBinary, boolean value)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_ONLINE);
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinary->tTypedMeasurement_for_Boolean),
      value,
      GetBinaryFlags_in_QualityFlagsOver2(fFlags, value));
//// : TypedMeasurement(value, flags::GetBinaryFlags(flags::ONLINE, value)) {}
}

void Binary_in_BinaryOver3(Binary *pBinary, Flags flags)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinary->tTypedMeasurement_for_Boolean),
      GetBinaryValue_in_QualityFlagsOver1(flags),
      flags);
//// : TypedMeasurement(flags::GetBinaryValue(flags), flags) {}
}

void Binary_in_BinaryOver4(Binary *pBinary, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver4(&(pBinary->tTypedMeasurement_for_Boolean),
      GetBinaryValue_in_QualityFlagsOver1(flags),
      flags,
      timeDNPTime);
//// : TypedMeasurement(flags::GetBinaryValue(flags), flags, time) {}
}

void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinary->tTypedMeasurement_for_Boolean),
      value,
      GetBinaryFlags_in_QualityFlagsOver2(flags, value));
//// : TypedMeasurement(value, flags::GetBinaryFlags(flags, value)) {}
}

void Binary_in_BinaryOver6(Binary *pBinary, boolean value, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver4(&(pBinary->tTypedMeasurement_for_Boolean),
      value,
      GetBinaryFlags_in_QualityFlagsOver2(flags, value),
      timeDNPTime);
////    : TypedMeasurement(value, flags::GetBinaryFlags(flags, value), time)
}

// ------------ Double Bit Binary ---------------

void DoubleBitBinary_in_DoubleBitBinaryOver1(DoubleBitBinary *pDoubleBitBinary)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_RESTART);
  TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver3(&(pDoubleBitBinary->tTypedMeasurement_for_DoubleBit_uint8_t),
      DoubleBit_INDETERMINATE, fFlags);
//// : TypedMeasurement(DoubleBit::INDETERMINATE, flags::RESTART) {}
}

void DoubleBitBinary_in_DoubleBitBinaryOver2(DoubleBitBinary *pDoubleBitBinary, DoubleBit_uint8_t value)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_ONLINE);
  TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver3(&(pDoubleBitBinary->tTypedMeasurement_for_DoubleBit_uint8_t),
      value,
      GetFlags_in_DoubleBitBinary_static(fFlags, value));
//// : TypedMeasurement(value, GetFlags(flags::ONLINE, value)) {}
}

void DoubleBitBinary_in_DoubleBitBinaryOver3(DoubleBitBinary *pDoubleBitBinary, Flags flags)
{
  TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver3(&(pDoubleBitBinary->tTypedMeasurement_for_DoubleBit_uint8_t),
      GetValue_in_DoubleBitBinary_static(flags),
      flags);
//// : TypedMeasurement(GetValue(flags), flags) {}
}

void DoubleBitBinary_in_DoubleBitBinaryOver4(DoubleBitBinary *pDoubleBitBinary, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver4(&(pDoubleBitBinary->tTypedMeasurement_for_DoubleBit_uint8_t),
      GetValue_in_DoubleBitBinary_static(flags),
      flags,
      timeDNPTime);
//// : TypedMeasurement(GetValue(flags), flags, time) {}
}

void DoubleBitBinary_in_DoubleBitBinaryOver5(DoubleBitBinary *pDoubleBitBinary, DoubleBit_uint8_t value, Flags flags)
{
  TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver3(&(pDoubleBitBinary->tTypedMeasurement_for_DoubleBit_uint8_t),
      value,
      GetFlags_in_DoubleBitBinary_static(flags, value));
//// : TypedMeasurement(value, GetFlags(flags, value)) {}
}

void DoubleBitBinary_in_DoubleBitBinaryOver6(DoubleBitBinary *pDoubleBitBinary, DoubleBit_uint8_t value, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver4(&(pDoubleBitBinary->tTypedMeasurement_for_DoubleBit_uint8_t),
      value,
      GetFlags_in_DoubleBitBinary_static(flags, value),
      timeDNPTime);
////    : TypedMeasurement(value, GetFlags(flags, value), time)
}

DoubleBit_uint8_t GetValue_in_DoubleBitBinary_static(Flags flags)
{
  // the value is the top 2 bits, so down-shift 6
  uint8_t value = flags.value >> 6;
  return from_type_in_DoubleBitSpec(value);
}

Flags GetFlags_in_DoubleBitBinary_static(Flags flags, DoubleBit_uint8_t state)
{
////    uint8_t value = DoubleBitSpec::to_type(state) << 6;
  uint8_t value = ((DoubleBit_uint8_t)state) << 6;
////    return Flags((QualityMask & flags.value) | value);
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, (QualityMask_in_DoubleBitBinary & flags.value) | value);
  return fFlags;
}

// ------------ Binary Output Status ---------------

void BinaryOutputStatus_in_BinaryOutputStatusOver1(BinaryOutputStatus *pBinaryOutputStatus)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_RESTART);
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinaryOutputStatus->tTypedMeasurement_for_Boolean),
      false, fFlags);
//// : TypedMeasurement(false, flags::RESTART) {}
}

void BinaryOutputStatus_in_BinaryOutputStatusOver2(BinaryOutputStatus *pBinaryOutputStatus, boolean value)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_ONLINE);
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinaryOutputStatus->tTypedMeasurement_for_Boolean),
      false,
      GetBinaryFlags_in_QualityFlagsOver2(fFlags, value));
////    : TypedMeasurement(value, flags::GetBinaryFlags(flags::ONLINE, value))
}

void BinaryOutputStatus_in_BinaryOutputStatusOver3(BinaryOutputStatus *pBinaryOutputStatus, Flags flags)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinaryOutputStatus->tTypedMeasurement_for_Boolean),
      GetBinaryValue_in_QualityFlagsOver1(flags),
      flags);
//// : TypedMeasurement(flags::GetBinaryValue(flags), flags) {}
}

void BinaryOutputStatus_in_BinaryOutputStatusOver4(BinaryOutputStatus *pBinaryOutputStatus, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver4(&(pBinaryOutputStatus->tTypedMeasurement_for_Boolean),
      GetBinaryValue_in_QualityFlagsOver1(flags),
      flags,
      timeDNPTime);
////    : TypedMeasurement(flags::GetBinaryValue(flags), flags, time)
}

void BinaryOutputStatus_in_BinaryOutputStatusOver5(BinaryOutputStatus *pBinaryOutputStatus, boolean value, Flags flags)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(&(pBinaryOutputStatus->tTypedMeasurement_for_Boolean),
      value,
      GetBinaryFlags_in_QualityFlagsOver2(flags, value));
////    : TypedMeasurement(value, flags::GetBinaryFlags(flags, value))
}

void BinaryOutputStatus_in_BinaryOutputStatusOver6(BinaryOutputStatus *pBinaryOutputStatus, boolean value, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver4(&(pBinaryOutputStatus->tTypedMeasurement_for_Boolean),
      value,
      GetBinaryFlags_in_QualityFlagsOver2(flags, value),
      timeDNPTime);
////    : TypedMeasurement(value, flags::GetBinaryFlags(flags, value), time)
}

// ------------ Analog ---------------

void Analog_in_AnalogOver1(Analog *pAnalog)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_RESTART);
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over2(&(pAnalog->tTypedMeasurement_for_Double64),
      fFlags);
//// : TypedMeasurement(flags::RESTART) {}
}

void Analog_in_AnalogOver2(Analog *pAnalog, double value)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_ONLINE);
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over3(&(pAnalog->tTypedMeasurement_for_Double64),
      value,
      fFlags);
//// : TypedMeasurement(value, flags::ONLINE) {}
}

void Analog_in_AnalogOver3(Analog *pAnalog, double value, Flags flags)
{
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over3(&(pAnalog->tTypedMeasurement_for_Double64),
      value,
      flags);
//// : TypedMeasurement(value, flags) {}
}

void Analog_in_AnalogOver4(Analog *pAnalog, double value, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over4(&(pAnalog->tTypedMeasurement_for_Double64),
      value,
      flags,
      timeDNPTime);
//// : TypedMeasurement<double>(value, flags, time) {}
}

// ------------ Counter ---------------

void Counter_in_CounterOver1(Counter *pCounter)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_RESTART);
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(&(pCounter->tTypedMeasurement_for_Uint32),
      0,
      fFlags);
//// : TypedMeasurement(0, flags::RESTART) {}
}

void Counter_in_CounterOver2(Counter *pCounter, uint32_t value)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_ONLINE);
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(&(pCounter->tTypedMeasurement_for_Uint32),
      value,
      fFlags);
//// : TypedMeasurement<uint32_t>(value, flags::ONLINE) {}
}

void Counter_in_CounterOver3(Counter *pCounter, uint32_t value, Flags flags)
{
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(&(pCounter->tTypedMeasurement_for_Uint32),
      value,
      flags);
//// : TypedMeasurement<uint32_t>(value, flags) {}
}

void Counter_in_CounterOver4(Counter *pCounter, uint32_t value, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over4(&(pCounter->tTypedMeasurement_for_Uint32),
      value,
      flags,
      timeDNPTime);
//// : TypedMeasurement<uint32_t>(value, flags, time) {}
}

// ------------ Frozen Counter ---------------

void FrozenCounter_in_FrozenCounterOver1(FrozenCounter *pFrozenCounter)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_RESTART);
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(&(pFrozenCounter->tTypedMeasurement_for_Uint32),
      0,
      fFlags);
//// : TypedMeasurement(0, flags::RESTART) {}
}

void FrozenCounter_in_FrozenCounterOver2(FrozenCounter *pFrozenCounter, uint32_t value)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_ONLINE);
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(&(pFrozenCounter->tTypedMeasurement_for_Uint32),
      value,
      fFlags);
//// : TypedMeasurement<uint32_t>(value, flags::ONLINE) {}
}

void FrozenCounter_in_FrozenCounterOver3(FrozenCounter *pFrozenCounter, uint32_t value, Flags flags)
{
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(&(pFrozenCounter->tTypedMeasurement_for_Uint32),
      value,
      flags);
//// : TypedMeasurement<uint32_t>(value, flags) {}
}

void FrozenCounter_in_FrozenCounterOver4(FrozenCounter *pFrozenCounter, uint32_t value, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over4(&(pFrozenCounter->tTypedMeasurement_for_Uint32),
      value,
      flags,
      timeDNPTime);
//// : TypedMeasurement<uint32_t>(value, flags, time)
}

// ------------ Analog Output Status ---------------

void AnalogOutputStatus_in_AnalogOutputStatusOver1(AnalogOutputStatus *pAnalogOutputStatus)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_RESTART);
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over2(&(pAnalogOutputStatus->tTypedMeasurement_for_Double64),
      fFlags);
//// : TypedMeasurement<double>(flags::RESTART) {}
}

void AnalogOutputStatus_in_AnalogOutputStatusOver2(AnalogOutputStatus *pAnalogOutputStatus, double value)
{
  Flags fFlags;
  Flags_In_FlagsOver2(&fFlags, Flags_ONLINE);
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over3(&(pAnalogOutputStatus->tTypedMeasurement_for_Double64),
      value,
      fFlags);
//// : TypedMeasurement<double>(value, flags::ONLINE) {}
}

void AnalogOutputStatus_in_AnalogOutputStatusOver3(AnalogOutputStatus *pAnalogOutputStatus, double value, Flags flags)
{
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over3(&(pAnalogOutputStatus->tTypedMeasurement_for_Double64),
      value,
      flags);
//// : TypedMeasurement<double>(value, flags) {}
}

void AnalogOutputStatus_in_AnalogOutputStatusOver4(AnalogOutputStatus *pAnalogOutputStatus, double value, Flags flags, DNPTime timeDNPTime)
{
  TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over4(&(pAnalogOutputStatus->tTypedMeasurement_for_Double64),
      value,
      flags,
      timeDNPTime);
////    : TypedMeasurement<double>(value, flags, time)
}

// ------------ TimeAndInterval ---------------

void TimeAndInterval_in_TimeAndIntervalOver1(TimeAndInterval *pTimeAndInterval)
{
//// : time(0), interval(0), units(0) {}
  DNPTime_in_DNPTimeOver2(&(pTimeAndInterval->timeDNPTime), 0);
  pTimeAndInterval->interval = 0;
  pTimeAndInterval->units = 0;
}

void TimeAndInterval_in_TimeAndIntervalOver2(TimeAndInterval *pTimeAndInterval, DNPTime time_, uint32_t interval_, uint8_t units_)
{
  pTimeAndInterval->timeDNPTime = time_;
  pTimeAndInterval->interval = interval_;
  pTimeAndInterval->units = units_;
////    : time(time_), interval(interval_), units(units_)
}

void TimeAndInterval_in_TimeAndIntervalOver3(TimeAndInterval *pTimeAndInterval, DNPTime time_, uint32_t interval_, IntervalUnits_uint8_t units_)
{
  pTimeAndInterval->timeDNPTime = time_;
  pTimeAndInterval->interval = interval_;
  pTimeAndInterval->units = units_;
////    : time(time_), interval(interval_), units(static_cast<uint8_t>(units_))
}

IntervalUnits_uint8_t GetUnitsEnum_in_TimeAndInterval(TimeAndInterval *pTimeAndInterval)
{
  return from_type_in_IntervalUnitsSpec(pTimeAndInterval->units);
////    return IntervalUnitsSpec::from_type(units);
}

////} // namespace opendnp3
