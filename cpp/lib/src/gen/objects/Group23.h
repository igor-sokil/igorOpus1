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

#ifndef OPENDNP3_GROUP23_H
#define OPENDNP3_GROUP23_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
////#include "app/MeasurementTypeSpecs.h"

#include "GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "MeasurementTypeSpecs.h"

////namespace opendnp3 {

// Frozen Counter Event - Any Variation
////struct Group23Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(23,0); }
////};

  GroupVariationID ID_in_Group23Var0_static(void);

// Frozen Counter Event - 32-bit With Flag
////struct Group23Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(23,1); }

////  Group23Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group23Var1&);
////  static bool Write(const Group23Var1&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint8_t flags;
  uint32_t value;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group23Var1;

  uint16_t Size_in_Group23Var1_static(void);

 void Group23Var1_in_Group23Var1(Group23Var1 *pGroup23Var1);
  GroupVariationID ID_in_Group23Var1_static(void);

 boolean Read_in_Group23Var1_static(RSeq_for_Uint16_t *, Group23Var1*);
 boolean Write_in_Group23Var1_static(Group23Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group23Var1_static(RSeq_for_Uint16_t*, FrozenCounter*);
 boolean WriteTarget_in_Group23Var1_static(FrozenCounter*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var1_static(void);

// Frozen Counter Event - 16-bit With Flag
////struct Group23Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(23,2); }

////  Group23Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group23Var2&);
////  static bool Write(const Group23Var2&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint8_t flags;
  uint16_t value;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group23Var2;

  uint16_t Size_in_Group23Var2_static(void);

 void Group23Var2_in_Group23Var2(Group23Var2 *pGroup23Var2);
  GroupVariationID ID_in_Group23Var2_static(void);

 boolean Read_in_Group23Var2_static(RSeq_for_Uint16_t *, Group23Var2*);
 boolean Write_in_Group23Var2_static(Group23Var2*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group23Var2_static(RSeq_for_Uint16_t*, FrozenCounter*);
 boolean WriteTarget_in_Group23Var2_static(FrozenCounter*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var2_static(void);

// Frozen Counter Event - 32-bit With Flag and Time
////struct Group23Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(23,5); }

////  Group23Var5();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group23Var5&);
////  static bool Write(const Group23Var5&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint8_t flags;
  uint32_t value;
  DNPTime timeDNPTime;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group23Var5;

  uint16_t Size_in_Group23Var5_static(void);

 void Group23Var5_in_Group23Var5(Group23Var5 *pGroup23Var5);
  GroupVariationID ID_in_Group23Var5_static(void);

 boolean Read_in_Group23Var5_static(RSeq_for_Uint16_t *, Group23Var5*);
 boolean Write_in_Group23Var5_static(Group23Var5*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group23Var5_static(RSeq_for_Uint16_t*, FrozenCounter*);
 boolean WriteTarget_in_Group23Var5_static(FrozenCounter*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var5_static(void);

// Frozen Counter Event - 16-bit With Flag and Time
////struct Group23Var6
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(23,6); }

////  Group23Var6();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group23Var6&);
////  static bool Write(const Group23Var6&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint8_t flags;
  uint16_t value;
  DNPTime timeDNPTime;

////  typedef FrozenCounter Target;
////  typedef FrozenCounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, FrozenCounter&);
////  static bool WriteTarget(const FrozenCounter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<FrozenCounter> Inst() { return DNP3Serializer<FrozenCounter>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group23Var6;

  uint16_t Size_in_Group23Var6_static(void);

 void Group23Var6_in_Group23Var6(Group23Var6 *pGroup23Var6);
  GroupVariationID ID_in_Group23Var6_static(void);

 boolean Read_in_Group23Var6_static(RSeq_for_Uint16_t *, Group23Var6*);
 boolean Write_in_Group23Var6_static(Group23Var6*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group23Var6_static(RSeq_for_Uint16_t*, FrozenCounter*);
 boolean WriteTarget_in_Group23Var6_static(FrozenCounter*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var6_static(void);


////}

#endif
