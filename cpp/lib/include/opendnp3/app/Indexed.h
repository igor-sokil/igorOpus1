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
#ifndef OPENDNP3_INDEXED_H
#define OPENDNP3_INDEXED_H

#include "AnalogOutput.h"
#include "IINValue.h"
#include "ControlRelayOutputBlock.h"
#include "OperationType.h"
#include "MeasurementTypes.h"
#include "Group1.h"
#include "Group2.h"
////#include <cstdint>

////namespace opendnp3
////{

//------------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  AnalogOutputInt16 value;
  uint16_t index;
} Indexed_for_AnalogOutputInt16;

void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over1(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16);
void Indexed_for_AnalogOutputInt16_in_Indexed_for_AnalogOutputInt16Over2(Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16,
    AnalogOutputInt16* value_, uint16_t index_);
Indexed_for_AnalogOutputInt16 WithIndex_in_Indexed_for_AnalogOutputInt16(//Indexed_for_AnalogOutputInt16 *pIndexed_for_AnalogOutputInt16,
  AnalogOutputInt16* value, uint16_t index);
//------------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputInt32---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  AnalogOutputInt32 value;
  uint16_t index;
} Indexed_for_AnalogOutputInt32;

void Indexed_for_AnalogOutputInt32_in_Indexed_for_AnalogOutputInt32Over1(Indexed_for_AnalogOutputInt32 *pIndexed_for_AnalogOutputInt32);
void Indexed_for_AnalogOutputInt32_in_Indexed_for_AnalogOutputInt32Over2(Indexed_for_AnalogOutputInt32 *pIndexed_for_AnalogOutputInt32,
    AnalogOutputInt32* value_, uint16_t index_);
Indexed_for_AnalogOutputInt32 WithIndex_in_Indexed_for_AnalogOutputInt32(//Indexed_for_AnalogOutputInt32 *pIndexed_for_AnalogOutputInt32,
  AnalogOutputInt32* value, uint16_t index);
//------------------------------------Indexed_for_AnalogOutputInt32---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputFloat32---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  AnalogOutputFloat32 value;
  uint16_t index;
} Indexed_for_AnalogOutputFloat32;

void Indexed_for_AnalogOutputFloat32_in_Indexed_for_AnalogOutputFloat32Over1(Indexed_for_AnalogOutputFloat32 *pIndexed_for_AnalogOutputFloat32);
void Indexed_for_AnalogOutputFloat32_in_Indexed_for_AnalogOutputFloat32Over2(Indexed_for_AnalogOutputFloat32 *pIndexed_for_AnalogOutputFloat32,
    AnalogOutputFloat32* value_, uint16_t index_);
Indexed_for_AnalogOutputFloat32 WithIndex_in_Indexed_for_AnalogOutputFloat32(//Indexed_for_AnalogOutputFloat32 *pIndexed_for_AnalogOutputFloat32,
  AnalogOutputFloat32* value, uint16_t index);
//------------------------------------Indexed_for_AnalogOutputFloat32---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputDouble64---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  AnalogOutputDouble64 value;
  uint16_t index;
} Indexed_for_AnalogOutputDouble64;

void Indexed_for_AnalogOutputDouble64_in_Indexed_for_AnalogOutputDouble64Over1(Indexed_for_AnalogOutputDouble64 *pIndexed_for_AnalogOutputDouble64);
void Indexed_for_AnalogOutputDouble64_in_Indexed_for_AnalogOutputDouble64Over2(Indexed_for_AnalogOutputDouble64 *pIndexed_for_AnalogOutputDouble64,
    AnalogOutputDouble64* value_, uint16_t index_);
Indexed_for_AnalogOutputDouble64 WithIndex_in_Indexed_for_AnalogOutputDouble64(//Indexed_for_AnalogOutputDouble64 *pIndexed_for_AnalogOutputDouble64,
  AnalogOutputDouble64* value, uint16_t index);
//------------------------------------Indexed_for_AnalogOutputDouble64---------------------------------------------------------
//------------------------------------Indexed_for_IINValue---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  IINValue value;
  uint16_t index;
} Indexed_for_IINValue;

void Indexed_for_IINValue_in_Indexed_for_IINValueOver1(Indexed_for_IINValue *pIndexed_for_IINValue);
void Indexed_for_IINValue_in_Indexed_for_IINValueOver2(Indexed_for_IINValue *pIndexed_for_IINValue,
    IINValue* value_, uint16_t index_);
Indexed_for_IINValue WithIndex_in_Indexed_for_IINValue(
  IINValue* value, uint16_t index);
//------------------------------------Indexed_for_IINValue---------------------------------------------------------
//------------------------------------Indexed_for_TimeAndInterval---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  TimeAndInterval value;
  uint16_t index;
} Indexed_for_TimeAndInterval;

void Indexed_for_TimeAndInterval_in_Indexed_for_TimeAndIntervalOver1(Indexed_for_TimeAndInterval *pIndexed_for_TimeAndInterval);
void Indexed_for_TimeAndInterval_in_Indexed_for_TimeAndIntervalOver2(Indexed_for_TimeAndInterval *pIndexed_for_TimeAndInterval,
    TimeAndInterval* value_, uint16_t index_);
Indexed_for_TimeAndInterval WithIndex_in_Indexed_for_TimeAndInterval(
  TimeAndInterval* value, uint16_t index);
//------------------------------------Indexed_for_TimeAndInterval---------------------------------------------------------
//------------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  ControlRelayOutputBlock value;
  uint16_t index;
} Indexed_for_ControlRelayOutputBlock;

void Indexed_for_ControlRelayOutputBlock_in_Indexed_for_ControlRelayOutputBlockOver1(Indexed_for_ControlRelayOutputBlock *pIndexed_for_ControlRelayOutputBlock);
void Indexed_for_ControlRelayOutputBlock_in_Indexed_for_ControlRelayOutputBlockOver2(Indexed_for_ControlRelayOutputBlock *pIndexed_for_ControlRelayOutputBlock,
    ControlRelayOutputBlock* value_, uint16_t index_);
Indexed_for_ControlRelayOutputBlock WithIndex_in_Indexed_for_ControlRelayOutputBlock(
  ControlRelayOutputBlock* value, uint16_t index);
//------------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------------
//------------------------------------Indexed_for_Binary---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  Binary value;
  uint16_t index;
} Indexed_for_Binary;

void Indexed_for_Binary_in_Indexed_for_BinaryOver1(Indexed_for_Binary *pIndexed_for_Binary);
void Indexed_for_Binary_in_Indexed_for_BinaryOver2(Indexed_for_Binary *pIndexed_for_Binary,
    Binary* value_, uint16_t index_);
Indexed_for_Binary WithIndex_in_Indexed_for_Binary(Binary* value, uint16_t index);
//------------------------------------Indexed_for_Binary---------------------------------------------------------
//------------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  DoubleBitBinary value;
  uint16_t index;
} Indexed_for_DoubleBitBinary;

void Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver1(Indexed_for_DoubleBitBinary *pIndexed_for_DoubleBitBinary);
void Indexed_for_DoubleBitBinary_in_Indexed_for_DoubleBitBinaryOver2(Indexed_for_DoubleBitBinary *pIndexed_for_DoubleBitBinary,
    DoubleBitBinary* value_, uint16_t index_);
Indexed_for_DoubleBitBinary WithIndex_in_Indexed_for_DoubleBitBinary(
  DoubleBitBinary* value, uint16_t index);
//------------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------------
//------------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  BinaryOutputStatus value;
  uint16_t index;
} Indexed_for_BinaryOutputStatus;

void Indexed_for_BinaryOutputStatus_in_Indexed_for_BinaryOutputStatusOver1(Indexed_for_BinaryOutputStatus *pIndexed_for_BinaryOutputStatus);
void Indexed_for_BinaryOutputStatus_in_Indexed_for_BinaryOutputStatusOver2(Indexed_for_BinaryOutputStatus *pIndexed_for_BinaryOutputStatus,
    BinaryOutputStatus* value_, uint16_t index_);
Indexed_for_BinaryOutputStatus WithIndex_in_Indexed_for_BinaryOutputStatus(
  BinaryOutputStatus* value, uint16_t index);
//------------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------------
//------------------------------------Indexed_for_Counter---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  Counter value;
  uint16_t index;
} Indexed_for_Counter;

void Indexed_for_Counter_in_Indexed_for_CounterOver1(Indexed_for_Counter *pIndexed_for_Counter);
void Indexed_for_Counter_in_Indexed_for_CounterOver2(Indexed_for_Counter *pIndexed_for_Counter,
    Counter* value_, uint16_t index_);
Indexed_for_Counter WithIndex_in_Indexed_for_Counter(
  Counter* value, uint16_t index);
//------------------------------------Indexed_for_Counter---------------------------------------------------------
//------------------------------------Indexed_for_FrozenCounter---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  FrozenCounter value;
  uint16_t index;
} Indexed_for_FrozenCounter;

void Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver1(Indexed_for_FrozenCounter *pIndexed_for_FrozenCounter);
void Indexed_for_FrozenCounter_in_Indexed_for_FrozenCounterOver2(Indexed_for_FrozenCounter *pIndexed_for_FrozenCounter,
    FrozenCounter* value_, uint16_t index_);
Indexed_for_FrozenCounter WithIndex_in_Indexed_for_FrozenCounter(
  FrozenCounter* value, uint16_t index);
//------------------------------------Indexed_for_FrozenCounter---------------------------------------------------------
//------------------------------------Indexed_for_Analog---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  Analog value;
  uint16_t index;
} Indexed_for_Analog;

void Indexed_for_Analog_in_Indexed_for_AnalogOver1(Indexed_for_Analog *pIndexed_for_Analog);
void Indexed_for_Analog_in_Indexed_for_AnalogOver2(Indexed_for_Analog *pIndexed_for_Analog,
    Analog* value_, uint16_t index_);
Indexed_for_Analog WithIndex_in_Indexed_for_Analog(
  Analog* value, uint16_t index);
//------------------------------------Indexed_for_Analog---------------------------------------------------------
//------------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  AnalogOutputStatus value;
  uint16_t index;
} Indexed_for_AnalogOutputStatus;

void Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver1(Indexed_for_AnalogOutputStatus *pIndexed_for_AnalogOutputStatus);
void Indexed_for_AnalogOutputStatus_in_Indexed_for_AnalogOutputStatusOver2(Indexed_for_AnalogOutputStatus *pIndexed_for_AnalogOutputStatus,
    AnalogOutputStatus* value_, uint16_t index_);
Indexed_for_AnalogOutputStatus WithIndex_in_Indexed_for_AnalogOutputStatus(
  AnalogOutputStatus* value, uint16_t index);
//------------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------------
//------------------------------------Indexed_for_OctetString---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  OctetString value;
  uint16_t index;
} Indexed_for_OctetString;

void Indexed_for_OctetString_in_Indexed_for_OctetStringOver1(Indexed_for_OctetString *pIndexed_for_OctetString);
void Indexed_for_OctetString_in_Indexed_for_OctetStringOver2(Indexed_for_OctetString *pIndexed_for_OctetString,
    OctetString* value_, uint16_t index_);
Indexed_for_OctetString WithIndex_in_Indexed_for_OctetString(
  OctetString* value, uint16_t index);
//------------------------------------Indexed_for_OctetString---------------------------------------------------------
//------------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  BinaryCommandEvent value;
  uint16_t index;
} Indexed_for_BinaryCommandEvent;

void Indexed_for_BinaryCommandEvent_in_Indexed_for_BinaryCommandEventOver1(Indexed_for_BinaryCommandEvent *pIndexed_for_BinaryCommandEvent);
void Indexed_for_BinaryCommandEvent_in_Indexed_for_BinaryCommandEventOver2(Indexed_for_BinaryCommandEvent *pIndexed_for_BinaryCommandEvent,
    BinaryCommandEvent* value_, uint16_t index_);
Indexed_for_BinaryCommandEvent WithIndex_in_Indexed_for_BinaryCommandEvent(
  BinaryCommandEvent* value, uint16_t index);
//------------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------------
//------------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  AnalogCommandEvent value;
  uint16_t index;
} Indexed_for_AnalogCommandEvent;

void Indexed_for_AnalogCommandEvent_in_Indexed_for_AnalogCommandEventOver1(Indexed_for_AnalogCommandEvent *pIndexed_for_AnalogCommandEvent);
void Indexed_for_AnalogCommandEvent_in_Indexed_for_AnalogCommandEventOver2(Indexed_for_AnalogCommandEvent *pIndexed_for_AnalogCommandEvent,
    AnalogCommandEvent* value_, uint16_t index_);
Indexed_for_AnalogCommandEvent WithIndex_in_Indexed_for_AnalogCommandEvent(
  AnalogCommandEvent* value, uint16_t index);
//------------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------------
//------------------------------------Indexed_for_Group2Var1---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
/*
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  Group2Var1 value;
  uint16_t index;
} Indexed_for_Group2Var1;

void Indexed_for_Group2Var1_in_Indexed_for_Group2Var1Over1(Indexed_for_Group2Var1 *pIndexed_for_Group2Var1);
void Indexed_for_Group2Var1_in_Indexed_for_Group2Var1Over2(Indexed_for_Group2Var1 *pIndexed_for_Group2Var1,
    Group2Var1* value_, uint16_t index_);
Indexed_for_Group2Var1 WithIndex_in_Indexed_for_Group2Var1(
  Group2Var1* value, uint16_t index);
*/
//------------------------------------Indexed_for_Group2Var1---------------------------------------------------------
//------------------------------------Indexed_for_Group1Var2---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
/*
typedef struct
{
////public:
////    Indexed(const T& value_, uint16_t index_) : value(value_), index(index_) {}

////    Indexed() : value(), index(0) {}

  Group1Var2 value;
  uint16_t index;
} Indexed_for_Group1Var2;

void Indexed_for_Group1Var2_in_Indexed_for_Group1Var2Over1(Indexed_for_Group1Var2 *pIndexed_for_Group1Var2);
void Indexed_for_Group1Var2_in_Indexed_for_Group1Var2Over2(Indexed_for_Group1Var2 *pIndexed_for_Group1Var2,
    Group1Var2* value_, uint16_t index_);
Indexed_for_Group1Var2 WithIndex_in_Indexed_for_Group1Var2(
  Group1Var2* value, uint16_t index);
*/
//------------------------------------Indexed_for_Group1Var2---------------------------------------------------------

////} // namespace opendnp3

#endif
