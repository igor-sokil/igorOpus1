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

#ifndef OPENDNP3_GROUP11_H
#define OPENDNP3_GROUP11_H

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

// Binary Output Event - Any Variation
////struct Group11Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(11,0); }
////};

GroupVariationID ID_in_Group11Var0_static(void);

// Binary Output Event - Output Status Without Time
////struct Group11Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(11,1); }

////  Group11Var1();

////  static size_t Size() { return 1; }
////  static bool Read(ser4cpp::rseq_t&, Group11Var1&);
////  static bool Write(const Group11Var1&, ser4cpp::wseq_t&);

  uint8_t flags;

////  typedef BinaryOutputStatus Target;
////  typedef BinaryOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, BinaryOutputStatus&);
////  static bool WriteTarget(const BinaryOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<BinaryOutputStatus> Inst() { return DNP3Serializer<BinaryOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group11Var1;

uint16_t Size_in_Group11Var1_static(void);
void Group11Var1_in_Group11Var1(Group11Var1 *pGroup11Var1);
GroupVariationID ID_in_Group11Var1_static(void);

boolean Read_in_Group11Var1_static(RSeq_for_Uint16_t *, Group11Var1*);
boolean Write_in_Group11Var1_static(Group11Var1*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group11Var1_static(RSeq_for_Uint16_t*, BinaryOutputStatus*);
boolean WriteTarget_in_Group11Var1_static(BinaryOutputStatus*, WSeq_for_Uint16_t*);
DNP3Serializer_for_BinaryOutputStatus  Inst_in_Group11Var1_static(void);

// Binary Output Event - Output Status With Time
////struct Group11Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(11,2); }

////  Group11Var2();

////  static size_t Size() { return 7; }
////  static bool Read(ser4cpp::rseq_t&, Group11Var2&);
////  static bool Write(const Group11Var2&, ser4cpp::wseq_t&);

  uint8_t flags;
  DNPTime timeDNPTime;

////  typedef BinaryOutputStatus Target;
////  typedef BinaryOutputStatusSpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, BinaryOutputStatus&);
////  static bool WriteTarget(const BinaryOutputStatus&, ser4cpp::wseq_t&);
////  static DNP3Serializer<BinaryOutputStatus> Inst() { return DNP3Serializer<BinaryOutputStatus>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group11Var2;

uint16_t Size_in_Group11Var2_static(void);

void Group11Var2_in_Group11Var2(Group11Var2 *pGroup11Var2);
GroupVariationID ID_in_Group11Var2_static(void);

boolean Read_in_Group11Var2_static(RSeq_for_Uint16_t *, Group11Var2*);
boolean Write_in_Group11Var2_static(Group11Var2*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group11Var2_static(RSeq_for_Uint16_t*, BinaryOutputStatus*);
boolean WriteTarget_in_Group11Var2_static(BinaryOutputStatus*, WSeq_for_Uint16_t*);

DNP3Serializer_for_BinaryOutputStatus  Inst_in_Group11Var2_static(void);

////}

#endif
