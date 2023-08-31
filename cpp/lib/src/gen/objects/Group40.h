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

#ifndef OPENDNP3_GROUP40_H
#define OPENDNP3_GROUP40_H

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

// Analog Output Status - Any Variation
////struct Group40Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(40,0); }
////};

GroupVariationID ID_in_Group40Var0_static(void);

// Analog Output Status - 32-bit With Flag
////struct Group40Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(40,1); }

////  Group40Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group40Var1&);
////  static bool Write(const Group40Var1&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  uint8_t flags;
  int32_t value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogOutputStatusVariation svariation = StaticAnalogOutputStatusVariation::Group40Var1;
} Group40Var1;

uint16_t Size_in_Group40Var1_static(void);
void Group40Var1_in_Group40Var1(Group40Var1 *pGroup40Var1);

boolean Read_in_Group40Var1_static(RSeq_for_Uint16_t *, Group40Var1*);
boolean Write_in_Group40Var1_static(Group40Var1*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group40Var1_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
boolean WriteTarget_in_Group40Var1_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);

const StaticAnalogOutputStatusVariation_uint8_t svariation_in_Group40Var1 = StaticAnalogOutputStatusVariation_Group40Var1;

// Analog Output Status - 16-bit With Flag
////struct Group40Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(40,2); }

////  Group40Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group40Var2&);
////  static bool Write(const Group40Var2&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  uint8_t flags;
  int16_t value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogOutputStatusVariation svariation = StaticAnalogOutputStatusVariation::Group40Var2;
} Group40Var2;

uint16_t Size_in_Group40Var2_static(void);
void Group40Var2_in_Group40Var2(Group40Var2 *pGroup40Var2);

boolean Read_in_Group40Var2_static(RSeq_for_Uint16_t *, Group40Var2*);
boolean Write_in_Group40Var2_static(Group40Var2*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group40Var2_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
boolean WriteTarget_in_Group40Var2_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);

const StaticAnalogOutputStatusVariation_uint8_t svariation_in_Group40Var2 = StaticAnalogOutputStatusVariation_Group40Var2;

// Analog Output Status - Single-precision With Flag
////struct Group40Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(40,3); }

////  Group40Var3();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group40Var3&);
////  static bool Write(const Group40Var3&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  uint8_t flags;
  float value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogOutputStatusVariation svariation = StaticAnalogOutputStatusVariation::Group40Var3;
} Group40Var3;

uint16_t Size_in_Group40Var3_static(void);
void Group40Var3_in_Group40Var3(Group40Var3 *pGroup40Var3);

boolean Read_in_Group40Var3_static(RSeq_for_Uint16_t *, Group40Var3*);
boolean Write_in_Group40Var3_static(Group40Var3*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group40Var3_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
boolean WriteTarget_in_Group40Var3_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);

const StaticAnalogOutputStatusVariation_uint8_t svariation_in_Group40Var3 = StaticAnalogOutputStatusVariation_Group40Var3;
/*
// Analog Output Status - Double-precision With Flag
////struct Group40Var4
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(40,4); }

////  Group40Var4();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group40Var4&);
////  static bool Write(const Group40Var4&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  uint8_t flags;
  double value;

////  typedef AnalogOutputStatus Target;
////  typedef AnalogOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputStatus&);
////  static bool WriteTarget(const AnalogOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputStatus> Inst() { return DNP3Serializer<AnalogOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticAnalogOutputStatusVariation svariation = StaticAnalogOutputStatusVariation::Group40Var4;
} Group40Var4;

  uint16_t Size_in_Group40Var4_static(void);

 uint16_t Size_in_Group40Var4_static(void)
{
 return 9;
}
 void Group40Var4_in_Group40Var4(Group40Var4 *pGroup40Var4);

  GroupVariationID ID_in_Group40Var4_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 40, 4);
////  return GroupVariationID(2,1);
 return gGroupVariationID;
}

 boolean Read_in_Group40Var4_static(RSeq_for_Uint16_t *, Group40Var4*);
 boolean Write_in_Group40Var4_static(Group40Var4*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group40Var4_static(RSeq_for_Uint16_t*, AnalogOutputStatus*);
 boolean WriteTarget_in_Group40Var4_static(AnalogOutputStatus*, WSeq_for_Uint16_t*);

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group40Var4_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group40Var4_static(),
                   Size_in_Group40Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group40Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group40Var4_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}

  const StaticAnalogOutputStatusVariation_uint8_t svariation_in_Group40Var4 = StaticAnalogOutputStatusVariation_Group40Var4;
*/
////}

#endif
