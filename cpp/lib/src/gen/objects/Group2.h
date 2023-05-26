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

#ifndef OPENDNP3_GROUP2_H
#define OPENDNP3_GROUP2_H

///#include "opendnp3/app/GroupVariationID.h"
///#include <ser4cpp/container/SequenceTypes.h>
///#include "opendnp3/app/DNPTime.h"
///#include "app/DNP3Serializer.h"
///#include "app/MeasurementTypeSpecs.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "MeasurementTypeSpecs.h"

////namespace opendnp3 {

// Binary Input Event - Any Variation
////struct Group2Var0
////typedef struct
////{
////  static GroupVariationID ID() { return GroupVariationID(2,0); }
////};
  GroupVariationID ID_in_Group2Var0_static(void);

// Binary Input Event - Without Time
////struct Group2Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(2,1); }

////  Group2Var1();

////  static size_t Size() { return 1; }
////  static bool Read(ser4cpp::rseq_t&, Group2Var1&);
////  static bool Write(const Group2Var1&, ser4cpp::wseq_t&);

  uint8_t flags;

////  typedef Binary Target;
////  typedef BinarySpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Binary&);
////  static bool WriteTarget(const Binary&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Binary> Inst() { return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group2Var1;

  GroupVariationID ID_in_Group2Var1_static(void);
 uint16_t Size_in_Group2Var1_static(void);

 void Group2Var1_in_Group2Var1(Group2Var1 *pGroup2Var1);

 boolean Read_in_Group2Var1_static(RSeq_for_Uint16_t *, Group2Var1*);
 boolean Write_in_Group2Var1_static(Group2Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group2Var1_static(RSeq_for_Uint16_t*, Binary*);
 boolean WriteTarget_in_Group2Var1_static(Binary*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_Binary  Inst_in_Group2Var1_static(void);

//// DNP3Serializer<Binary> Inst_in_Group2Var1_static() { return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget); }
//    void DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary,
//                   GroupVariationID id,
//                   uint16_t size,
//                    read_func_t_in_Serializer_for_Binary read_func,
//                    write_func_t_in_Serializer_for_Binary write_func);

// Binary Input Event - With Absolute Time
////struct Group2Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(2,2); }

////  Group2Var2();

////  static size_t Size() { return 7; }
////  static bool Read(ser4cpp::rseq_t&, Group2Var2&);
////  static bool Write(const Group2Var2&, ser4cpp::wseq_t&);

  uint8_t flags;
  DNPTime timeDNPTime;

////  typedef Binary Target;
////  typedef BinarySpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Binary&);
////  static bool WriteTarget(const Binary&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Binary> Inst() { return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group2Var2;

 void Group2Var2_in_Group2Var2(Group2Var2 *pGroup2Var2);
  GroupVariationID ID_in_Group2Var2_static(void);
 uint16_t Size_in_Group2Var2_static(void);

 boolean Read_in_Group2Var2_static(RSeq_for_Uint16_t *, Group2Var2*);
 boolean Write_in_Group2Var2_static(Group2Var2*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group2Var2_static(RSeq_for_Uint16_t*, Binary*);
 boolean WriteTarget_in_Group2Var2_static(Binary*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_Binary  Inst_in_Group2Var2_static(void);

//// DNP3Serializer<Binary> Inst_in_Group2Var2_static() { return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget); }
// Binary Input Event - With Relative Time
////struct Group2Var3
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(2,3); }

////  Group2Var3();

////  static size_t Size() { return 3; }
////  static bool Read(ser4cpp::rseq_t&, Group2Var3&);
////  static bool Write(const Group2Var3&, ser4cpp::wseq_t&);

  uint8_t flags;
  uint16_t time_uint16_t;

////  typedef Binary Target;
////  typedef BinarySpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, Binary&);
////  static bool WriteTarget(const Binary&, ser4cpp::wseq_t&);
////  static DNP3Serializer<Binary> Inst() { return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group2Var3;

 void Group2Var3_in_Group2Var3(Group2Var3 *pGroup2Var3);
  GroupVariationID ID_in_Group2Var3_static(void);
 uint16_t Size_in_Group2Var3_static(void);
 boolean Read_in_Group2Var3_static(RSeq_for_Uint16_t *, Group2Var3*);
 boolean Write_in_Group2Var3_static(Group2Var3*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group2Var3_static(RSeq_for_Uint16_t*, Binary*);
 boolean WriteTarget_in_Group2Var3_static(Binary*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_Binary  Inst_in_Group2Var3_static(void);

////}

#endif
