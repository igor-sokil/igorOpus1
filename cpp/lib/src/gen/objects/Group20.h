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

#ifndef OPENDNP3_GROUP20_H
#define OPENDNP3_GROUP20_H

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

// Counter - Any Variation
////struct Group20Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(20,0); }
////};

GroupVariationID ID_in_Group20Var0_static(void);

// Counter - 32-bit With Flag
////struct Group20Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(20,1); }

////  Group20Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group20Var1&);
////  static bool Write(const Group20Var1&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint8_t flags;
  uint32_t value;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticCounterVariation svariation = StaticCounterVariation::Group20Var1;
} Group20Var1;

uint16_t Size_in_Group20Var1_static(void);
void Group20Var1_in_Group20Var1(Group20Var1 *pGroup20Var1);
GroupVariationID ID_in_Group20Var1_static(void);
DNP3Serializer_for_Counter Inst_in_Group20Var1_static(void);

boolean Read_in_Group20Var1_static(RSeq_for_Uint16_t *, Group20Var1*);
boolean Write_in_Group20Var1_static(Group20Var1*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group20Var1_static(RSeq_for_Uint16_t*, Counter*);
boolean WriteTarget_in_Group20Var1_static(Counter*, WSeq_for_Uint16_t*);

const StaticCounterVariation_uint8_t svariation_in_Group20Var1 = StaticCounterVariation_Group20Var1;

// Counter - 16-bit With Flag
////struct Group20Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(20,2); }

////  Group20Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group20Var2&);
////  static bool Write(const Group20Var2&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint8_t flags;
  uint16_t value;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticCounterVariation svariation = StaticCounterVariation::Group20Var2;
} Group20Var2;

uint16_t Size_in_Group20Var2_static(void);
void Group20Var2_in_Group20Var2(Group20Var2 *pGroup20Var2);
GroupVariationID ID_in_Group20Var2_static(void);
DNP3Serializer_for_Counter Inst_in_Group20Var2_static(void);

boolean Read_in_Group20Var2_static(RSeq_for_Uint16_t *, Group20Var2*);
boolean Write_in_Group20Var2_static(Group20Var2*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group20Var2_static(RSeq_for_Uint16_t*, Counter*);
boolean WriteTarget_in_Group20Var2_static(Counter*, WSeq_for_Uint16_t*);

const StaticCounterVariation_uint8_t svariation_in_Group20Var2 = StaticCounterVariation_Group20Var2;

// Counter - 32-bit Without Flag
////struct Group20Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(20,5); }

////  Group20Var5();

////  static size_t Size() { return 4; }
////  static bool Read(ser4cpp::rseq_t&, Group20Var5&);
////  static bool Write(const Group20Var5&, ser4cpp::wseq_t&);

////  typedef uint32_t ValueType;
  uint32_t value;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticCounterVariation svariation = StaticCounterVariation::Group20Var5;
} Group20Var5;

uint16_t Size_in_Group20Var5_static(void);
void Group20Var5_in_Group20Var5(Group20Var5 *pGroup20Var5);
GroupVariationID ID_in_Group20Var5_static(void);
DNP3Serializer_for_Counter Inst_in_Group20Var5_static(void);

boolean Read_in_Group20Var5_static(RSeq_for_Uint16_t *, Group20Var5*);
boolean Write_in_Group20Var5_static(Group20Var5*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group20Var5_static(RSeq_for_Uint16_t*, Counter*);
boolean WriteTarget_in_Group20Var5_static(Counter*, WSeq_for_Uint16_t*);

const StaticCounterVariation_uint8_t svariation_in_Group20Var5 = StaticCounterVariation_Group20Var5;

// Counter - 16-bit Without Flag
////struct Group20Var6
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(20,6); }

////  Group20Var6();

////  static size_t Size() { return 2; }
////  static bool Read(ser4cpp::rseq_t&, Group20Var6&);
////  static bool Write(const Group20Var6&, ser4cpp::wseq_t&);

////  typedef uint16_t ValueType;
  uint16_t value;

////  typedef Counter Target;
////  typedef CounterSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Counter&);
////  static bool WriteTarget(const Counter&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Counter> Inst() { return DNP3Serializer<Counter>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticCounterVariation svariation = StaticCounterVariation::Group20Var6;
} Group20Var6;

uint16_t Size_in_Group20Var6_static(void);
GroupVariationID ID_in_Group20Var6_static(void);
void Group20Var6_in_Group20Var6(Group20Var6 *pGroup20Var6);
DNP3Serializer_for_Counter Inst_in_Group20Var6_static(void);

boolean Read_in_Group20Var6_static(RSeq_for_Uint16_t *, Group20Var6*);
boolean Write_in_Group20Var6_static(Group20Var6*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group20Var6_static(RSeq_for_Uint16_t*, Counter*);
boolean WriteTarget_in_Group20Var6_static(Counter*, WSeq_for_Uint16_t*);

const StaticCounterVariation_uint8_t svariation_in_Group20Var6 = StaticCounterVariation_Group20Var6;

////}

#endif
