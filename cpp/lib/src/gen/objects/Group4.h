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

#ifndef OPENDNP3_GROUP4_H
#define OPENDNP3_GROUP4_H

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

// Double-bit Binary Input Event - Any Variation
////struct Group4Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(4,0); }
////};

  GroupVariationID ID_in_Group4Var0_static(void);

// Double-bit Binary Input Event - Without Time
////struct Group4Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(4,1); }

////  Group4Var1();

////  static size_t Size() { return 1; }
////  static bool Read(ser4cpp::rseq_t&, Group4Var1&);
////  static bool Write(const Group4Var1&, ser4cpp::wseq_t&);

  uint8_t flags;

////  typedef DoubleBitBinary Target;
////  typedef DoubleBitBinarySpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, DoubleBitBinary&);
////  static bool WriteTarget(const DoubleBitBinary&, ser4cpp::wseq_t&);
////  static DNP3Serializer<DoubleBitBinary> Inst() { return DNP3Serializer<DoubleBitBinary>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group4Var1;

  uint16_t Size_in_Group4Var1_static(void);

 void Group4Var1_in_Group4Var1(Group4Var1 *pGroup4Var1);
  GroupVariationID ID_in_Group4Var1_static(void);

 boolean Read_in_Group4Var1_static(RSeq_for_Uint16_t *, Group4Var1*);
 boolean Write_in_Group4Var1_static(Group4Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group4Var1_static(RSeq_for_Uint16_t*, DoubleBitBinary*);
 boolean WriteTarget_in_Group4Var1_static(DoubleBitBinary*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var1_static(void);

// Double-bit Binary Input Event - With Absolute Time
////struct Group4Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(4,2); }

////  Group4Var2();

////  static size_t Size() { return 7; }
////  static bool Read(ser4cpp::rseq_t&, Group4Var2&);
////  static bool Write(const Group4Var2&, ser4cpp::wseq_t&);

  uint8_t flags;
  DNPTime timeDNPTime;

////  typedef DoubleBitBinary Target;
////  typedef DoubleBitBinarySpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, DoubleBitBinary&);
////  static bool WriteTarget(const DoubleBitBinary&, ser4cpp::wseq_t&);
////  static DNP3Serializer<DoubleBitBinary> Inst() { return DNP3Serializer<DoubleBitBinary>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group4Var2;

  uint16_t Size_in_Group4Var2_static(void);

 void Group2Var2_in_Group4Var2(Group4Var2 *pGroup4Var2);
  GroupVariationID ID_in_Group4Var2_static(void);

 boolean Read_in_Group4Var2_static(RSeq_for_Uint16_t *, Group4Var2*);
 boolean Write_in_Group4Var2_static(Group4Var2*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group4Var2_static(RSeq_for_Uint16_t*, DoubleBitBinary*);
 boolean WriteTarget_in_Group4Var2_static(DoubleBitBinary*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var2_static(void);

// Double-bit Binary Input Event - With Relative Time
////struct Group4Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(4,3); }

////  Group4Var3();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group4Var3&);
////  static bool Write(const Group4Var3&, ser4cpp::wseq_t&);

  uint8_t flags;
  uint16_t time_uint16_t;

////  typedef DoubleBitBinary Target;
////  typedef DoubleBitBinarySpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, DoubleBitBinary&);
////  static bool WriteTarget(const DoubleBitBinary&, ser4cpp::wseq_t&);
////  static DNP3Serializer<DoubleBitBinary> Inst() { return DNP3Serializer<DoubleBitBinary>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group4Var3;

  uint16_t Size_in_Group4Var3_static(void);

 void Group2Var3_in_Group4Var3(Group4Var3 *pGroup4Var3);
  GroupVariationID ID_in_Group4Var3_static(void);

 boolean Read_in_Group4Var3_static(RSeq_for_Uint16_t *, Group4Var3*);
 boolean Write_in_Group4Var3_static(Group4Var3*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group4Var3_static(RSeq_for_Uint16_t*, DoubleBitBinary*);
 boolean WriteTarget_in_Group4Var3_static(DoubleBitBinary*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var3_static(void);

////}   

#endif
