//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
//
// This file is auto-generated. Do not edit manually
//
// Copyright 2013-2022 Step Function I/O, LLC
//
// Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
// LLC (https://stepfunc.io) under one or more contributor license agreements.
// See the NOTICE file distributed with this work for additional information
// regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
// this file to you under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may obtain
// a copy of the License at:
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#ifndef OPENDNP3_GROUP21_H
#define OPENDNP3_GROUP21_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
////#include "app/MeasurementTypeSpecs.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "MeasurementTypeSpecs.h"

////namespace opendnp3 {

// Frozen Counter - Any Variation
////struct Group21Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(21,0); }
////};

GroupVariationID ID_in_Group21Var0_static(void);

// Frozen Counter - 32-bit With Flag
////struct Group21Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(21,1); }

////  Group21Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group21Var1&);
////  static bool Write(const Group21Var1&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint8_t flags;
  uint32_t value;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticFrozenCounterVariation svariation = StaticFrozenCounterVariation::Group21Var1;
} Group21Var1;

uint16_t Size_in_Group21Var1_static(void);

void Group21Var1_in_Group21Var1(Group21Var1 *pGroup21Var1);

boolean Read_in_Group21Var1_static(RSeq_for_Uint16_t *, Group21Var1*);
boolean Write_in_Group21Var1_static(Group21Var1*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group21Var1_static(RSeq_for_Uint16_t*, FrozenCounter*);
boolean WriteTarget_in_Group21Var1_static(FrozenCounter*, WSeq_for_Uint16_t*);

const StaticFrozenCounterVariation_uint8_t svariation_in_Group21Var1 = StaticFrozenCounterVariation_Group21Var1;

// Frozen Counter - 16-bit With Flag
////struct Group21Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(21,2); }

////  Group21Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group21Var2&);
////  static bool Write(const Group21Var2&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint8_t flags;
  uint16_t value;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticFrozenCounterVariation svariation = StaticFrozenCounterVariation::Group21Var2;
} Group21Var2;

uint16_t Size_in_Group21Var2_static(void);

void Group21Var2_in_Group21Var2(Group21Var2 *pGroup21Var2);

boolean Read_in_Group21Var2_static(RSeq_for_Uint16_t *, Group21Var2*);
boolean Write_in_Group21Var2_static(Group21Var2*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group21Var2_static(RSeq_for_Uint16_t*, FrozenCounter*);
boolean WriteTarget_in_Group21Var2_static(FrozenCounter*, WSeq_for_Uint16_t*);

const StaticFrozenCounterVariation_uint8_t svariation_in_Group21Var2 = StaticFrozenCounterVariation_Group21Var2;

// Frozen Counter - 32-bit With Flag and Time
////struct Group21Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(21,5); }

////  Group21Var5();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group21Var5&);
////  static bool Write(const Group21Var5&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint8_t flags;
  uint32_t value;
  DNPTime timeDNPTime;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticFrozenCounterVariation svariation = StaticFrozenCounterVariation::Group21Var5;
} Group21Var5;

uint16_t Size_in_Group21Var5_static(void);

void Group21Var5_in_Group21Var5(Group21Var5 *pGroup21Var5);

boolean Read_in_Group21Var5_static(RSeq_for_Uint16_t *, Group21Var5*);
boolean Write_in_Group21Var5_static(Group21Var5*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group21Var5_static(RSeq_for_Uint16_t*, FrozenCounter*);
boolean WriteTarget_in_Group21Var5_static(FrozenCounter*, WSeq_for_Uint16_t*);

const StaticFrozenCounterVariation_uint8_t svariation_in_Group21Var5 = StaticFrozenCounterVariation_Group21Var5;

// Frozen Counter - 16-bit With Flag and Time
////struct Group21Var6
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(21,6); }

////  Group21Var6();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group21Var6&);
////  static bool Write(const Group21Var6&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint8_t flags;
  uint16_t value;
  DNPTime timeDNPTime;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticFrozenCounterVariation svariation = StaticFrozenCounterVariation::Group21Var6;
} Group21Var6;

uint16_t Size_in_Group21Var6_static(void);

void Group21Var6_in_Group21Var6(Group21Var6 *pGroup21Var6);

boolean Read_in_Group21Var6_static(RSeq_for_Uint16_t *, Group21Var6*);
boolean Write_in_Group21Var6_static(Group21Var6*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group21Var6_static(RSeq_for_Uint16_t*, FrozenCounter*);
boolean WriteTarget_in_Group21Var6_static(FrozenCounter*, WSeq_for_Uint16_t*);

const StaticFrozenCounterVariation_uint8_t svariation_in_Group21Var6 = StaticFrozenCounterVariation_Group21Var6;

// Frozen Counter - 32-bit Without Flag
////struct Group21Var9
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(21,9); }

////  Group21Var9();

////  static size_t Size() { return 4; }
////  static bool Read(ser4cpp::rseq_t&, Group21Var9&);
////  static bool Write(const Group21Var9&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint32_t value;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticFrozenCounterVariation svariation = StaticFrozenCounterVariation::Group21Var9;
} Group21Var9;

uint16_t Size_in_Group21Var9_static(void);

void Group21Var9_in_Group21Var9(Group21Var9 *pGroup21Var9);

boolean Read_in_Group21Var9_static(RSeq_for_Uint16_t *, Group21Var9*);
boolean Write_in_Group21Var9_static(Group21Var9*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group21Var9_static(RSeq_for_Uint16_t*, FrozenCounter*);
boolean WriteTarget_in_Group21Var9_static(FrozenCounter*, WSeq_for_Uint16_t*);

const StaticFrozenCounterVariation_uint8_t svariation_in_Group21Var9 = StaticFrozenCounterVariation_Group21Var9;

// Frozen Counter - 16-bit Without Flag
////struct Group21Var10
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(21,10); }

////  Group21Var10();

////  static size_t Size() { return 2; }
////  static bool Read(ser4cpp::rseq_t&, Group21Var10&);
////  static bool Write(const Group21Var10&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint16_t value;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticFrozenCounterVariation svariation = StaticFrozenCounterVariation::Group21Var10;
} Group21Var10;

uint16_t Size_in_Group21Var10_static(void);

void Group21Var10_in_Group21Var10(Group21Var10 *pGroup21Var10);

boolean Read_in_Group21Var10_static(RSeq_for_Uint16_t *, Group21Var10*);
boolean Write_in_Group21Var10_static(Group21Var10*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group21Var10_static(RSeq_for_Uint16_t*, FrozenCounter*);
boolean WriteTarget_in_Group21Var10_static(FrozenCounter*, WSeq_for_Uint16_t*);

const StaticFrozenCounterVariation_uint8_t svariation_in_Group21Var10 = StaticFrozenCounterVariation_Group21Var10;

////}

#endif
