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
//------------------------------------Indexed_for_Group2Var1---------------------------------------------------------
/**
 * A simple tuple for pairing Values with an index
 */
////template<class T> class Indexed
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
//------------------------------------Indexed_for_Group2Var1---------------------------------------------------------

////} // namespace opendnp3

#endif
