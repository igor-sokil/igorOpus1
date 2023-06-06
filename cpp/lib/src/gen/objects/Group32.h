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

#ifndef OPENDNP3_GROUP32_H
#define OPENDNP3_GROUP32_H

///#include "opendnp3/app/GroupVariationID.h"
///#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
///#include "app/MeasurementTypeSpecs.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "MeasurementTypeSpecs.h"

////namespace opendnp3 {

// Analog Input Event - Any Variation
////struct Group32Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(32,0); }
////};

  GroupVariationID ID_in_Group32Var0_static(void);

  GroupVariationID ID_in_Group32Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 0);
//// return GroupVariationID(32,0);
 return gGroupVariationID;
}

// Analog Input Event - 32-bit With Flag
////struct Group32Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,1); }

////  Group32Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var1&);
////  static bool Write(const Group32Var1&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t flags;
  int32_t value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var1;

  uint16_t Size_in_Group32Var1_static(void);
 void Group32Var1_in_Group32Var1(Group32Var1 *pGroup32Var1);
  GroupVariationID ID_in_Group32Var1_static(void);

 boolean Read_in_Group32Var1_static(RSeq_for_Uint16_t *, Group32Var1*);
 boolean Write_in_Group32Var1_static(Group32Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var1_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var1_static(Analog*, WSeq_for_Uint16_t*);

// Analog Input Event - 16-bit With Flag
////struct Group32Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,2); }

////  Group32Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var2&);
////  static bool Write(const Group32Var2&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t flags;
  int16_t value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var2;

  uint16_t Size_in_Group32Var2_static(void);
 void Group32Var2_in_Group32Var2(Group32Var2 *pGroup32Var2);
  GroupVariationID ID_in_Group32Var2_static(void);

 boolean Read_in_Group32Var2_static(RSeq_for_Uint16_t *, Group32Var2*);
 boolean Write_in_Group32Var2_static(Group32Var2*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var2_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var2_static(Analog*, WSeq_for_Uint16_t*);

// Analog Input Event - 32-bit With Flag and Time
////struct Group32Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,3); }

////  Group32Var3();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var3&);
////  static bool Write(const Group32Var3&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t flags;
  int32_t value;
  DNPTime timeDNPTime;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var3;

  uint16_t Size_in_Group32Var3_static(void);
 void Group32Var3_in_Group32Var3(Group32Var3 *pGroup32Var3);
  GroupVariationID ID_in_Group32Var3_static(void);

 boolean Read_in_Group32Var3_static(RSeq_for_Uint16_t *, Group32Var3*);
 boolean Write_in_Group32Var3_static(Group32Var3*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var3_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var3_static(Analog*, WSeq_for_Uint16_t*);

// Analog Input Event - 16-bit With Flag and Time
////struct Group32Var4
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,4); }

////  Group32Var4();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var4&);
////  static bool Write(const Group32Var4&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t flags;
  int16_t value;
  DNPTime timeDNPTime;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var4;

  uint16_t Size_in_Group32Var4_static(void);
 void Group32Var4_in_Group32Var4(Group32Var4 *pGroup32Var4);
  GroupVariationID ID_in_Group32Var4_static(void);

 boolean Read_in_Group32Var4_static(RSeq_for_Uint16_t *, Group32Var4*);
 boolean Write_in_Group32Var4_static(Group32Var4*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var4_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var4_static(Analog*, WSeq_for_Uint16_t*);

// Analog Input Event - Single-precision With Flag
////struct Group32Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,5); }

////  Group32Var5();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var5&);
////  static bool Write(const Group32Var5&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t flags;
  float value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var5;

  uint16_t Size_in_Group32Var5_static(void);
 void Group32Var5_in_Group32Var5(Group32Var5 *pGroup32Var5);
  GroupVariationID ID_in_Group32Var5_static(void);

 boolean Read_in_Group32Var5_static(RSeq_for_Uint16_t *, Group32Var5*);
 boolean Write_in_Group32Var5_static(Group32Var5*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var5_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var5_static(Analog*, WSeq_for_Uint16_t*);

// Analog Input Event - Double-precision With Flag
////struct Group32Var6
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,6); }

////  Group32Var6();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var6&);
////  static bool Write(const Group32Var6&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  uint8_t flags;
  double value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var6;

  uint16_t Size_in_Group32Var6_static(void);
 void Group32Var6_in_Group32Var6(Group32Var6 *pGroup32Var6);
  GroupVariationID ID_in_Group32Var6_static(void);

 boolean Read_in_Group32Var6_static(RSeq_for_Uint16_t *, Group32Var6*);
 boolean Write_in_Group32Var6_static(Group32Var6*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var6_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var6_static(Analog*, WSeq_for_Uint16_t*);

// Analog Input Event - Single-precision With Flag and Time
////struct Group32Var7
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,7); }

////  Group32Var7();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var7&);
////  static bool Write(const Group32Var7&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t flags;
  float value;
  DNPTime timeDNPTime;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var7;

  uint16_t Size_in_Group32Var7_static(void);
 void Group32Var7_in_Group32Var7(Group32Var7 *pGroup32Var7);
  GroupVariationID ID_in_Group32Var7_static(void);

 boolean Read_in_Group32Var7_static(RSeq_for_Uint16_t *, Group32Var7*);
 boolean Write_in_Group32Var7_static(Group32Var7*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var7_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var7_static(Analog*, WSeq_for_Uint16_t*);

// Analog Input Event - Double-precision With Flag and Time
////struct Group32Var8
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(32,8); }

////  Group32Var8();

////  static size_t Size() { return 15; }
////  static bool Read(ser4cpp::rseq_t&, Group32Var8&);
////  static bool Write(const Group32Var8&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  uint8_t flags;
  double value;
  DNPTime timeDNPTime;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group32Var8;

  uint16_t Size_in_Group32Var8_static(void);
 void Group32Var8_in_Group32Var8(Group32Var8 *pGroup32Var8);
  GroupVariationID ID_in_Group32Var8_static(void);


 boolean Read_in_Group32Var8_static(RSeq_for_Uint16_t *, Group32Var8*);
 boolean Write_in_Group32Var8_static(Group32Var8*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group32Var8_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group32Var8_static(Analog*, WSeq_for_Uint16_t*);


////}

#endif
