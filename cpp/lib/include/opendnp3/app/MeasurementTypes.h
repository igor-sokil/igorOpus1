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
#ifndef OPENDNP3_MEASUREMENTTYPES_H
#define OPENDNP3_MEASUREMENTTYPES_H

////#include "opendnp3/app/BaseMeasurementTypes.h"
////#include "opendnp3/gen/DoubleBit.h"
////#include "opendnp3/gen/IntervalUnits.h"

#include "BaseMeasurementTypes.h"
#include "DoubleBit.h"
#include "IntervalUnits.h"

////namespace opendnp3
////{

/**
    The Binary data type is for describing on-off (boolean) type values. Good examples of
    binaries are alarms, mode settings, enabled/disabled flags etc. Think of it as a status
    LED on a piece of equipment.
Тип данных Binary предназначен для описания значений двухпозиционного (логического) типа. Хорошие примеры
     двоичные файлы — это сигналы тревоги, настройки режима, флаги включения/отключения и т. д. Думайте об этом как о статусе.
     Светодиод на оборудовании.
*/
////class Binary : public TypedMeasurement<bool>
typedef struct
{
  TypedMeasurement_for_Boolean tTypedMeasurement_for_Boolean;
////public:
////    Binary();
////
////    explicit Binary(bool value);
////
////    explicit Binary(Flags flags);
////
////    Binary(Flags flags, DNPTime time);
////
////    Binary(bool value, Flags flags);
////
////    Binary(bool value, Flags flags, DNPTime time);
} Binary;

void Binary_in_BinaryOver1(Binary *pBinary);
void Binary_in_BinaryOver2(Binary *pBinary, boolean value);
void Binary_in_BinaryOver3(Binary *pBinary, Flags flags);
void Binary_in_BinaryOver4(Binary *pBinary, Flags flags, DNPTime timeDNPTime);
void Binary_in_BinaryOver5(Binary *pBinary, boolean value, Flags flags);
void Binary_in_BinaryOver6(Binary *pBinary, boolean value, Flags flags, DNPTime timeDNPTime);

/**
The Double-bit Binary data type has two stable states, on and off, and an in transit state. Motor operated switches
or binary valves are good examples.
Тип данных Double-bit Binary имеет два стабильных состояния: включено и выключено, а также состояние передачи. Выключатели с электроприводом
или бинарные клапаны являются хорошими примерами.
*/
////class DoubleBitBinary : public TypedMeasurement<DoubleBit>
typedef struct
{
  TypedMeasurement_for_DoubleBit_uint8_t  tTypedMeasurement_for_DoubleBit_uint8_t;
////public:
////    DoubleBitBinary();
////
////    explicit DoubleBitBinary(DoubleBit value);
////
////    explicit DoubleBitBinary(Flags flags);
////
////    DoubleBitBinary(Flags flags, DNPTime time);
////
////    DoubleBitBinary(DoubleBit value, Flags flags);
////
////    DoubleBitBinary(DoubleBit value, Flags flags, DNPTime time);

////private:
////    static const uint8_t ValueMask = 0xC0;
////    static const uint8_t QualityMask = 0x3F;
////
////    static DoubleBit GetValue(Flags flags);

////    static Flags GetFlags(Flags flags, DoubleBit state);
} DoubleBitBinary;

void DoubleBitBinary_in_DoubleBitBinaryOver1(DoubleBitBinary *pDoubleBitBinary);
void DoubleBitBinary_in_DoubleBitBinaryOver2(DoubleBitBinary *pDoubleBitBinary, DoubleBit_uint8_t value);
void DoubleBitBinary_in_DoubleBitBinaryOver3(DoubleBitBinary *pDoubleBitBinary, Flags flags);
void DoubleBitBinary_in_DoubleBitBinaryOver4(DoubleBitBinary *pDoubleBitBinary, Flags flags, DNPTime timeDNPTime);
void DoubleBitBinary_in_DoubleBitBinaryOver5(DoubleBitBinary *pDoubleBitBinary, DoubleBit_uint8_t value, Flags flags);
void DoubleBitBinary_in_DoubleBitBinaryOver6(DoubleBitBinary *pDoubleBitBinary, DoubleBit_uint8_t value, Flags flags, DNPTime timeDNPTime);

const uint8_t ValueMask_in_DoubleBitBinary = 0xC0;
const uint8_t QualityMask_in_DoubleBitBinary = 0x3F;

DoubleBit_uint8_t GetValue_in_DoubleBitBinary_static(Flags flags);

Flags GetFlags_in_DoubleBitBinary_static(Flags flags, DoubleBit_uint8_t state);

/**
    BinaryOutputStatus is used for describing the current state of a control. It is very infrequently
    used and many masters don't provide any mechanisms for reading these values so their use is
    strongly discouraged, a Binary should be used instead.
BinaryOutputStatus используется для описания текущего состояния элемента управления. Это очень редко
     используются, и многие мастера не предоставляют никаких механизмов для чтения этих значений, поэтому их использование ограничено.
     настоятельно не рекомендуется, вместо этого следует использовать двоичный файл.
*/
////class BinaryOutputStatus : public TypedMeasurement<bool>
typedef struct
{
  TypedMeasurement_for_Boolean tTypedMeasurement_for_Boolean;
////public:
////    BinaryOutputStatus();

////    explicit BinaryOutputStatus(bool value);
////
////    explicit BinaryOutputStatus(Flags flags);
////
////    BinaryOutputStatus(Flags flags, DNPTime time);
////
////    BinaryOutputStatus(bool value, Flags flags);
////
////    BinaryOutputStatus(bool value, Flags flags, DNPTime time);
} BinaryOutputStatus;

void BinaryOutputStatus_in_BinaryOutputStatusOver1(BinaryOutputStatus *pBinaryOutputStatus);
void BinaryOutputStatus_in_BinaryOutputStatusOver2(BinaryOutputStatus *pBinaryOutputStatus, boolean value);
void BinaryOutputStatus_in_BinaryOutputStatusOver3(BinaryOutputStatus *pBinaryOutputStatus, Flags flags);
void BinaryOutputStatus_in_BinaryOutputStatusOver4(BinaryOutputStatus *pBinaryOutputStatus, Flags flags, DNPTime timeDNPTime);
void BinaryOutputStatus_in_BinaryOutputStatusOver5(BinaryOutputStatus *pBinaryOutputStatus, boolean value, Flags flags);
void BinaryOutputStatus_in_BinaryOutputStatusOver6(BinaryOutputStatus *pBinaryOutputStatus, boolean value, Flags flags, DNPTime timeDNPTime);

/**
    Analogs are used for variable data points that usually reflect a real world value.
    Good examples are current, voltage, sensor readouts, etc. Think of a speedometer guage.
Аналоги используются для переменных точек данных, которые обычно отражают реальное значение.
     Хорошими примерами являются ток, напряжение, показания датчиков и т. д. Представьте себе датчик спидометра.
*/

////class Analog : public TypedMeasurement<double>
typedef struct
{
  TypedMeasurement_for_Double64  tTypedMeasurement_for_Double64;
////public:
////    Analog();

////    explicit Analog(double value);
////
////    Analog(double value, Flags flags);
////
////    Analog(double value, Flags flags, DNPTime time);
} Analog;

void Analog_in_AnalogOver1(Analog *pAnalog);
void Analog_in_AnalogOver2(Analog *pAnalog, double value);
void Analog_in_AnalogOver3(Analog *pAnalog, double value, Flags flags);
void Analog_in_AnalogOver4(Analog *pAnalog, double value, Flags flags, DNPTime timeDNPTime);

/**
    Counters are used for describing generally increasing values (non-negative!). Good examples are
    total power consumed, max voltage. Think odometer on a car.
Счетчики используются для описания обычно возрастающих значений (неотрицательных!). Хорошими примерами являются
     общая потребляемая мощность, максимальное напряжение. Представьте себе одометр автомобиля.
*/
////class Counter : public TypedMeasurement<uint32_t>
typedef struct
{
  TypedMeasurement_for_Uint32  tTypedMeasurement_for_Uint32;
////public:
////    Counter();
////
////    explicit Counter(uint32_t value);

////    Counter(uint32_t value, Flags flags);

////    Counter(uint32_t value, Flags flags, DNPTime time);
} Counter;

void Counter_in_CounterOver1(Counter *pCounter);
void Counter_in_CounterOver2(Counter *pCounter, uint32_t value);
void Counter_in_CounterOver3(Counter *pCounter, uint32_t value, Flags flags);
void Counter_in_CounterOver4(Counter *pCounter, uint32_t value, Flags flags, DNPTime timeDNPTime);

/**
    Frozen counters are used to report the value of a counter point captured at the instant when the count is frozen.
Замороженные счетчики используются для сообщения значения точки счетчика, зафиксированной в момент заморозки счета.
*/
////class FrozenCounter : public TypedMeasurement<uint32_t>
typedef struct
{
  TypedMeasurement_for_Uint32  tTypedMeasurement_for_Uint32;
////public:
////    FrozenCounter();

////    explicit FrozenCounter(uint32_t value);

////    FrozenCounter(uint32_t value, Flags flags);

////    FrozenCounter(uint32_t value, Flags flags, DNPTime time);
} FrozenCounter;

void FrozenCounter_in_FrozenCounterOver1(FrozenCounter *pFrozenCounter);
void FrozenCounter_in_FrozenCounterOver2(FrozenCounter *pFrozenCounter, uint32_t value);
void FrozenCounter_in_FrozenCounterOver3(FrozenCounter *pFrozenCounter, uint32_t value, Flags flags);
void FrozenCounter_in_FrozenCounterOver4(FrozenCounter *pFrozenCounter, uint32_t value, Flags flags, DNPTime timeDNPTime);

/**
    Describes the last set value of the set-point. Like the BinaryOutputStatus data type it is not
    well supported and its generally better practice to use an explicit analog.
Описывает последнее установленное значение уставки. Как и тип данных BinaryOutputStatus, это не так.
     хорошо поддерживается, и, как правило, лучше использовать явный аналог.
*/
////class AnalogOutputStatus : public TypedMeasurement<double>
typedef struct
{
  TypedMeasurement_for_Double64  tTypedMeasurement_for_Double64;
////public:
////    AnalogOutputStatus();

////    explicit AnalogOutputStatus(double value);

////    AnalogOutputStatus(double value, Flags flags);

////    AnalogOutputStatus(double value, Flags flags, DNPTime time);
} AnalogOutputStatus;

void AnalogOutputStatus_in_AnalogOutputStatusOver1(AnalogOutputStatus *pAnalogOutputStatus);
void AnalogOutputStatus_in_AnalogOutputStatusOver2(AnalogOutputStatus *pAnalogOutputStatus, double value);
void AnalogOutputStatus_in_AnalogOutputStatusOver3(AnalogOutputStatus *pAnalogOutputStatus, double value, Flags flags);
void AnalogOutputStatus_in_AnalogOutputStatusOver4(AnalogOutputStatus *pAnalogOutputStatus, double value, Flags flags, DNPTime timeDNPTime);

/**
    Maps to Group50Var4
    This class is a bit of an outlier as an indexed type and is really only used in the DNP3 PV profile
Сопоставляется с Group50Var4
     Этот класс немного отличается от индексированного типа и на самом деле используется только в профиле DNP3 PV.
*/
////class TimeAndInterval
typedef struct
{
////public:
////    TimeAndInterval();

////    TimeAndInterval(DNPTime time, uint32_t interval, uint8_t units);

////    TimeAndInterval(DNPTime time, uint32_t interval, IntervalUnits units);

////    IntervalUnits GetUnitsEnum() const;

  DNPTime timeDNPTime;
  uint32_t interval;
  uint8_t units;
} TimeAndInterval;

void TimeAndInterval_in_TimeAndIntervalOver1(TimeAndInterval *pTimeAndInterval);
void TimeAndInterval_in_TimeAndIntervalOver2(TimeAndInterval *pTimeAndInterval, DNPTime timeDNPTime, uint32_t interval, uint8_t units);
void TimeAndInterval_in_TimeAndIntervalOver3(TimeAndInterval *pTimeAndInterval, DNPTime timeDNPTime, uint32_t interval, IntervalUnits_uint8_t units);

IntervalUnits_uint8_t GetUnitsEnum_in_TimeAndInterval(TimeAndInterval *pTimeAndInterval);

////} // namespace opendnp3

#endif
