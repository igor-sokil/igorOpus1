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

#ifndef OPENDNP3_GROUP30_H
#define OPENDNP3_GROUP30_H

///#include "opendnp3/app/GroupVariationID.h"
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

// Analog Input - Any Variation
////struct Group30Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(30,0); }
////};

  GroupVariationID ID_in_Group30Var0_static(void);

// Analog Input - 32-bit With Flag
////struct Group30Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(30,1); }

////  Group30Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group30Var1&);
////  static bool Write(const Group30Var1&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t flags;
  int32_t value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogVariation svariation = StaticAnalogVariation::Group30Var1;
} Group30Var1;

  uint16_t Size_in_Group30Var1_static(void);
 DNP3Serializer_for_Analog  Inst_in_Group30Var1_static(void);
  GroupVariationID ID_in_Group30Var1_static(void);
 void Group30Var1_in_Group30Var1(Group30Var1 *pGroup30Var1);

 boolean Read_in_Group30Var1_static(RSeq_for_Uint16_t *, Group30Var1*);
 boolean Write_in_Group30Var1_static(Group30Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group30Var1_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group30Var1_static(Analog*, WSeq_for_Uint16_t*);

  const StaticAnalogVariation_uint8_t svariation_in_Group30Var1 = StaticAnalogVariation_Group30Var1;

// Analog Input - 16-bit With Flag
////struct Group30Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(30,2); }

////  Group30Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group30Var2&);
////  static bool Write(const Group30Var2&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t flags;
  int16_t value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogVariation svariation = StaticAnalogVariation::Group30Var2;
} Group30Var2;

  uint16_t Size_in_Group30Var2_static(void);
 DNP3Serializer_for_Analog  Inst_in_Group30Var2_static(void);
  GroupVariationID ID_in_Group30Var2_static(void);
 void Group30Var2_in_Group30Var2(Group30Var2 *pGroup30Var2);

 boolean Read_in_Group30Var2_static(RSeq_for_Uint16_t *, Group30Var2*);
 boolean Write_in_Group30Var2_static(Group30Var2*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group30Var2_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group30Var2_static(Analog*, WSeq_for_Uint16_t*);

  const StaticAnalogVariation_uint8_t svariation_in_Group30Var2 = StaticAnalogVariation_Group30Var2;

// Analog Input - 32-bit Without Flag
////struct Group30Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(30,3); }

////  Group30Var3();

////  static size_t Size() { return 4; }
////  static bool Read(ser4cpp::rseq_t&, Group30Var3&);
////  static bool Write(const Group30Var3&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  int32_t value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogVariation svariation = StaticAnalogVariation::Group30Var3;
} Group30Var3;

  uint16_t Size_in_Group30Var3_static(void);
 DNP3Serializer_for_Analog  Inst_in_Group30Var3_static(void);
  GroupVariationID ID_in_Group30Var3_static(void);
 void Group30Var3_in_Group30Var3(Group30Var3 *pGroup30Var3);

 boolean Read_in_Group30Var3_static(RSeq_for_Uint16_t *, Group30Var3*);
 boolean Write_in_Group30Var3_static(Group30Var3*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group30Var3_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group30Var3_static(Analog*, WSeq_for_Uint16_t*);

  const StaticAnalogVariation_uint8_t svariation_in_Group30Var3 = StaticAnalogVariation_Group30Var3;

// Analog Input - 16-bit Without Flag
////struct Group30Var4
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(30,4); }

////  Group30Var4();

////  static size_t Size() { return 2; }
////  static bool Read(ser4cpp::rseq_t&, Group30Var4&);
////  static bool Write(const Group30Var4&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  int16_t value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogVariation svariation = StaticAnalogVariation::Group30Var4;
} Group30Var4;

  uint16_t Size_in_Group30Var4_static(void);
 DNP3Serializer_for_Analog  Inst_in_Group30Var4_static(void);
  GroupVariationID ID_in_Group30Var4_static(void);
 void Group30Var4_in_Group30Var4(Group30Var4 *pGroup30Var4);

 boolean Read_in_Group30Var4_static(RSeq_for_Uint16_t *, Group30Var4*);
 boolean Write_in_Group30Var4_static(Group30Var4*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group30Var4_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group30Var4_static(Analog*, WSeq_for_Uint16_t*);

  const StaticAnalogVariation_uint8_t svariation_in_Group30Var4 = StaticAnalogVariation_Group30Var4;

// Analog Input - Single-precision With Flag
////struct Group30Var5
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(30,5); }

////  Group30Var5();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group30Var5&);
////  static bool Write(const Group30Var5&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t flags;
  float value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogVariation svariation = StaticAnalogVariation::Group30Var5;
} Group30Var5;

  uint16_t Size_in_Group30Var5_static(void);
  DNP3Serializer_for_Analog  Inst_in_Group30Var5_static(void);
  GroupVariationID ID_in_Group30Var5_static(void);
  void Group30Var5_in_Group30Var5(Group30Var5 *pGroup30Var5);

 boolean Read_in_Group30Var5_static(RSeq_for_Uint16_t *, Group30Var5*);
 boolean Write_in_Group30Var5_static(Group30Var5*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group30Var5_static(RSeq_for_Uint16_t*, Analog*);
 boolean WriteTarget_in_Group30Var5_static(Analog*, WSeq_for_Uint16_t*);

  const StaticAnalogVariation_uint8_t svariation_in_Group30Var5 = StaticAnalogVariation_Group30Var5;

// Analog Input - Double-precision With Flag
////struct Group30Var6
//typedef struct
//{
////  static GroupVariationID ID() { return GroupVariationID(30,6); }

////  Group30Var6();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group30Var6&);
///  static bool Write(const Group30Var6&, ser4cpp::wseq_t&);

////  typedef double ValueType;
//  uint8_t flags;
//  double value;

////  typedef Analog Target;
////  typedef AnalogSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Analog&);
////  static bool WriteTarget(const Analog&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Analog> Inst() { return DNP3Serializer<Analog>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogVariation svariation = StaticAnalogVariation::Group30Var6;
//} Group30Var6;

//  uint16_t Size_in_Group30Var6_static(void);

// uint16_t Size_in_Group30Var6_static(void) 
//{
// return 9; 
//}

// void Group30Var6_in_Group30Var6(Group30Var6 *pGroup30Var6);

//  GroupVariationID ID_in_Group30Var6_static(void)
//{
// GroupVariationID gGroupVariationID;
// GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 30, 6);
////  return GroupVariationID(30,6); 
// return gGroupVariationID;
//}

// boolean Read_in_Group30Var6_static(RSeq_for_Uint16_t *, Group2Var1*);
// boolean Write_in_Group30Var6_static(Group2Var1*, WSeq_for_Uint16_t*);

// boolean ReadTarget_in_Group30Var6_static(RSeq_for_Uint16_t*, Analog*);
// boolean WriteTarget_in_Group30Var6_static(Analog*, WSeq_for_Uint16_t*);

// DNP3Serializer_for_Analog  Inst_in_Group30Var6_static(void)
//{
//   DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
//   DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
//                   ID_in_Group30Var6_static(),
//                   Size_in_Group30Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
//                   &ReadTarget_in_Group30Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
//                   &WriteTarget_in_Group30Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
//   return dDNP3Serializer_for_Analog;
//}

//  const StaticAnalogVariation_uint8_t svariation_in_Group30Var6 = StaticAnalogVariation_Group30Var6;

////}

#endif
