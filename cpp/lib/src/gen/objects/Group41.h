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

#ifndef OPENDNP3_GROUP41_H
#define OPENDNP3_GROUP41_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
////#include "opendnp3/app/AnalogOutput.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "AnalogOutput.h"

////namespace opendnp3 {

// Analog Output - Any Variation
////struct Group41Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(41,0); }
////};

GroupVariationID ID_in_Group41Var0_static(void);

// Analog Output - 32-bit With Flag
////struct Group41Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(41,1); }

////  Group41Var1();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group41Var1&);
////  static bool Write(const Group41Var1&, ser4cpp::wseq_t&);

////  typedef int32_t ValueType;
  int32_t value;
  uint8_t status;

////  typedef AnalogOutputInt32 Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputInt32&);
////  static bool WriteTarget(const AnalogOutputInt32&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputInt32> Inst() { return DNP3Serializer<AnalogOutputInt32>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group41Var1;

uint16_t Size_in_Group41Var1_static(void);


DNP3Serializer_for_AnalogOutputInt32  Inst_in_Group41Var1_static(void);
void Group41Var1_in_Group41Var1(Group41Var1 *pGroup41Var1);

boolean Read_in_Group41Var1_static(RSeq_for_Uint16_t *, Group41Var1*);
boolean Write_in_Group41Var1_static(Group41Var1*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group41Var1_static(RSeq_for_Uint16_t*, AnalogOutputInt32*);
boolean WriteTarget_in_Group41Var1_static(AnalogOutputInt32*, WSeq_for_Uint16_t*);

// Analog Output - 16-bit With Flag
////struct Group41Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(41,2); }

////  Group41Var2();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group41Var2&);
////  static bool Write(const Group41Var2&, ser4cpp::wseq_t&);

////  typedef int16_t ValueType;
  int16_t value;
  uint8_t status;

////  typedef AnalogOutputInt16 Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputInt16&);
////  static bool WriteTarget(const AnalogOutputInt16&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputInt16> Inst() { return DNP3Serializer<AnalogOutputInt16>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group41Var2;

uint16_t Size_in_Group41Var2_static(void);
void Group41Var2_in_Group41Var2(Group41Var2 *pGroup41Var2);

boolean Read_in_Group41Var2_static(RSeq_for_Uint16_t *, Group41Var2*);
boolean Write_in_Group41Var2_static(Group41Var2*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group41Var2_static(RSeq_for_Uint16_t*, AnalogOutputInt16*);
boolean WriteTarget_in_Group41Var2_static(AnalogOutputInt32*, WSeq_for_Uint16_t*);
DNP3Serializer_for_AnalogOutputInt16  Inst_in_Group41Var2_static(void);

// Analog Output - Single-precision
////struct Group41Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(41,3); }

////  Group41Var3();

////  static size_t Size() { return 5; }
////  static bool Read(ser4cpp::rseq_t&, Group41Var3&);
////  static bool Write(const Group41Var3&, ser4cpp::wseq_t&);

////  typedef float ValueType;
  float value;
  uint8_t status;

////  typedef AnalogOutputFloat32 Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputFloat32&);
////  static bool WriteTarget(const AnalogOutputFloat32&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputFloat32> Inst() { return DNP3Serializer<AnalogOutputFloat32>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group41Var3;

DNP3Serializer_for_AnalogOutputFloat32  Inst_in_Group41Var3_static(void);
uint16_t Size_in_Group41Var3_static(void);
void Group41Var3_in_Group41Var3(Group41Var3 *pGroup41Var3);

boolean Read_in_Group41Var3_static(RSeq_for_Uint16_t *, Group41Var3*);
boolean Write_in_Group41Var3_static(Group41Var3*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group41Var3_static(RSeq_for_Uint16_t*, AnalogOutputFloat32*);
boolean WriteTarget_in_Group41Var3_static(AnalogOutputFloat32*, WSeq_for_Uint16_t*);

// Analog Output - Double-precision
////struct Group41Var4
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(41,4); }

////  Group41Var4();

////  static size_t Size() { return 9; }
////  static bool Read(ser4cpp::rseq_t&, Group41Var4&);
////  static bool Write(const Group41Var4&, ser4cpp::wseq_t&);

////  typedef double ValueType;
  double value;
  uint8_t status;

////  typedef AnalogOutputDouble64 Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, AnalogOutputDouble64&);
////  static bool WriteTarget(const AnalogOutputDouble64&, ser4cpp::wseq_t&);
////  static DNP3Serializer<AnalogOutputDouble64> Inst() { return DNP3Serializer<AnalogOutputDouble64>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group41Var4;

uint16_t Size_in_Group41Var4_static(void);
void Group41Var4_in_Group41Var4(Group41Var4 *pGroup41Var4);

boolean Read_in_Group41Var4_static(RSeq_for_Uint16_t *, Group41Var4*);
boolean Write_in_Group41Var4_static(Group41Var4*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group41Var4_static(RSeq_for_Uint16_t*, AnalogOutputDouble64*);
boolean WriteTarget_in_Group41Var4_static(AnalogOutputDouble64*, WSeq_for_Uint16_t*);


////}

#endif
