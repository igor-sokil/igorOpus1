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

#ifndef OPENDNP3_GROUP42_H
#define OPENDNP3_GROUP42_H

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

// Analog Output Event - Any Variation
////struct Group42Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(42,0); }
////};

  GroupVariationID ID_in_Group42Var0_static(void);

// Analog Output Event - 32-bit With Flag
////struct Group42Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,1); }

////  Group42Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var1&);
////  static bool Write(const Group42Var1&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t flags;
  int32_t value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var1;

  uint16_t Size_in_Group42Var1_static(void);
 void Group42Var1_in_Group42Var1(Group42Var1 *pGroup42Var1);
  GroupVariationID ID_in_Group42Var1_static(void);

 boolean Read_in_Group42Var1_static(RSeq_for_Uint16_t *, Group42Var1*);
 boolean Write_in_Group42Var1_static(Group42Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var1_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var1_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var1_static(void);

// Analog Output Event - 16-bit With Flag
////struct Group42Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,2); }

////  Group42Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var2&);
////  static bool Write(const Group42Var2&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t flags;
  int16_t value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var2;

  uint16_t Size_in_Group42Var2_static(void);

 void Group42Var2_in_Group42Var2(Group42Var2 *pGroup42Var2);
  GroupVariationID ID_in_Group42Var2_static(void);

 boolean Read_in_Group42Var2_static(RSeq_for_Uint16_t *, Group42Var2*);
 boolean Write_in_Group42Var2_static(Group42Var2*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var2_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var2_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var2_static(void);

// Analog Output Event - 32-bit With Flag and Time
////struct Group42Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,3); }

////  Group42Var3();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var3&);
////  static bool Write(const Group42Var3&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t flags;
  int32_t value;
  DNPTime time;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var3;

  uint16_t Size_in_Group42Var3_static(void);

 void Group42Var3_in_Group42Var3(Group42Var3 *pGroup42Var3);
  GroupVariationID ID_in_Group42Var3_static(void);

 boolean Read_in_Group42Var3_static(RSeq_for_Uint16_t *, Group42Var3*);
 boolean Write_in_Group42Var3_static(Group42Var3*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var3_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var3_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var3_static(void);

// Analog Output Event - 16-bit With Flag and Time
////struct Group42Var4
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,4); }

////  Group42Var4();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var4&);
////  static bool Write(const Group42Var4&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t flags;
  int16_t value;
  DNPTime timeDNPTime;

////  typedef AnalogOutputStatus Target;
///  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var4;

  uint16_t Size_in_Group42Var4_static(void);

 void Group42Var4_in_Group42Var4(Group42Var4 *pGroup42Var4);
  GroupVariationID ID_in_Group42Var4_static(void);

 boolean Read_in_Group42Var4_static(RSeq_for_Uint16_t *, Group42Var4*);
 boolean Write_in_Group42Var4_static(Group42Var4*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var4_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var4_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var4_static(void);

// Analog Output Event - Single-precision With Flag
////struct Group42Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,5); }

////  Group42Var5();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var5&);
////  static bool Write(const Group42Var5&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t flags;
  float value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var5;

  uint16_t Size_in_Group42Var5_static(void);

 void Group42Var5_in_Group42Var5(Group42Var5 *pGroup42Var5);
  GroupVariationID ID_in_Group42Var5_static(void);

 boolean Read_in_Group42Var5_static(RSeq_for_Uint16_t *, Group42Var5*);
 boolean Write_in_Group42Var5_static(Group42Var5*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var5_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var5_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var4_static(void);

// Analog Output Event - Double-precision With Flag
////struct Group42Var6
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,6); }

////  Group42Var6();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var6&);
////  static bool Write(const Group42Var6&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  uint8_t flags;
  double value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var6;

  uint16_t Size_in_Group42Var6_static(void);

 void Group42Var6_in_Group42Var6(Group42Var6 *pGroup42Var6);
  GroupVariationID ID_in_Group42Var6_static(void);

 boolean Read_in_Group42Var6_static(RSeq_for_Uint16_t *, Group42Var6*);
 boolean Write_in_Group42Var6_static(Group42Var6*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var6_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var6_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var6_static(void);

// Analog Output Event - Single-precision With Flag and Time
////struct Group42Var7
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,7); }

////  Group42Var7();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var7&);
////  static bool Write(const Group42Var7&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t flags;
  float value;
  DNPTime timeDNPTime;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var7;

  uint16_t Size_in_Group42Var7_static(void);

 void Group42Var7_in_Group42Var7(Group42Var7 *pGroup42Var7);
  GroupVariationID ID_in_Group42Var7_static(void);

 boolean Read_in_Group42Var7_static(RSeq_for_Uint16_t *, Group42Var7*);
 boolean Write_in_Group42Var7_static(Group42Var7*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var7_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var7_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var7_static(void);

// Analog Output Event - Double-precision With Flag and Time
////struct Group42Var8
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(42,8); }

////  Group42Var8();

////  static size_t Size() { return 15; }
////  static bool Read(ser4cpp::rseq_t&, Group42Var8&);
////  static bool Write(const Group42Var8&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  uint8_t flags;
  double value;
  DNPTime timeDNPTime;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group42Var8;

  uint16_t Size_in_Group42Var8_static(void);

 void Group42Var8_in_Group42Var8(Group42Var8 *pGroup42Var8);
  GroupVariationID ID_in_Group42Var8_static(void);

 boolean Read_in_Group42Var8_static(RSeq_for_Uint16_t *, Group42Var8*);
 boolean Write_in_Group42Var8_static(Group42Var8*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group42Var8_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group42Var8_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var8_static(void);

////}

#endif
