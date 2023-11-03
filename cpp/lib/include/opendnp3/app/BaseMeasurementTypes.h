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
#ifndef OPENDNP3_BASEMEASUREMENTTYPES_H
#define OPENDNP3_BASEMEASUREMENTTYPES_H

////#include "opendnp3/app/DNPTime.h"
////#include "opendnp3/app/Flags.h"

#include "DNPTime.h"
#include "Flags.h"
#include "DoubleBit.h"

////#include <cstdint>

////namespace opendnp3
////{

/**
  Base class shared by all of the DataPoint types.
*/
////class Measurement
typedef struct
{
////public:
    Flags flags;  //	bitfield that stores type specific quality information
                  // Bitfield, который хранит тип конкретной информации о качестве
    DNPTime timeDNPTime; //	timestamp associated with the measurement
                         // временная метка, связанная с измерением

////protected:
////    Measurement() {}

////    Measurement(Flags flags) : flags(flags) {}

////    Measurement(Flags flags, DNPTime time) : flags(flags), time(time) {}
} Measurement;

 void Measurement_in_MeasurementOver1(Measurement *pMeasurement);
 void Measurement_in_MeasurementOver2(Measurement *pMeasurement, Flags flags);
 void Measurement_in_MeasurementOver3(Measurement *pMeasurement, Flags flags, DNPTime timeDNPTime);

////    Measurement(Flags flags, DNPTime time) : flags(flags), time(time) {}

typedef struct
{
  Measurement mMeasurement;
  double value;
} TypedMeasurement_for_Double64;

/// Common subclass to analogs and counters
////template<class T> class TypedMeasurement : public Measurement
////{
////public:
////    T value;

////    typedef T Type;

////protected:
////    TypedMeasurement() : Measurement(), value(0) {}
////    TypedMeasurement(Flags flags) : Measurement(flags), value(0) {}
////    TypedMeasurement(T value, Flags flags) : Measurement(flags), value(value) {}
////    TypedMeasurement(T value, Flags flags, DNPTime time) : Measurement(flags, time), value(value) {}
////};
   void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over4(
                            TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64, double value, Flags flags, DNPTime timeDNPTime);
   void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over3(
                            TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64, double value, Flags flags);
   void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over2(
                            TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64, Flags flags);
   void TypedMeasurement_for_Double64_in_TypedMeasurement_for_Double64Over1(
                            TypedMeasurement_for_Double64 *pTypedMeasurement_for_Double64);


typedef struct
{
  Measurement mMeasurement;
  boolean value;
} TypedMeasurement_for_Boolean;

   void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver4(
                            TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean, boolean value, Flags flags, DNPTime timeDNPTime);
   void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver3(
                            TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean, boolean value, Flags flags);
   void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver2(
                            TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean, Flags flags);
   void TypedMeasurement_for_Boolean_in_TypedMeasurement_for_BooleanOver1(
                            TypedMeasurement_for_Boolean *pTypedMeasurement_for_Boolean);


typedef struct
{
  Measurement mMeasurement;
  uint32_t value;
} TypedMeasurement_for_Uint32;

   void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over4(
                            TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32, uint32_t value, Flags flags, DNPTime timeDNPTime);
   void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over3(
                            TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32, uint32_t value, Flags flags);
   void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over2(
                            TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32, Flags flags);
   void TypedMeasurement_for_Uint32_in_TypedMeasurement_for_Uint32Over1(
                            TypedMeasurement_for_Uint32 *pTypedMeasurement_for_Uint32);

typedef struct
{
  Measurement mMeasurement;
  DoubleBit_uint8_t value;
} TypedMeasurement_for_DoubleBit_uint8_t;

   void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver4(
                            TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t, DoubleBit_uint8_t value, Flags flags, DNPTime timeDNPTime);
   void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver3(
                            TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t, DoubleBit_uint8_t value, Flags flags);
   void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver2(
                            TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t, Flags flags);
   void TypedMeasurement_for_DoubleBit_uint8_t_in_TypedMeasurement_for_DoubleBit_uint8_tOver1(
                            TypedMeasurement_for_DoubleBit_uint8_t *pTypedMeasurement_for_DoubleBit_uint8_t);

////} // namespace opendnp3

#endif
