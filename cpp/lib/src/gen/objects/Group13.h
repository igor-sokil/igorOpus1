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

#ifndef OPENDNP3_GROUP13_H
#define OPENDNP3_GROUP13_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
////#include "opendnp3/app/BinaryCommandEvent.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "BinaryCommandEvent.h"

////namespace opendnp3 {

// Binary Command Event - Without Time
////struct Group13Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(13,1); }

////  Group13Var1();

////  static size_t Size() { return 1; }
////  static bool Read(ser4cpp::rseq_t&, Group13Var1&);
////  static bool Write(const Group13Var1&, ser4cpp::wseq_t&);

  uint8_t flags;

////  typedef BinaryCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, BinaryCommandEvent&);
////  static bool WriteTarget(const BinaryCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<BinaryCommandEvent> Inst() { return DNP3Serializer<BinaryCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group13Var1;

uint16_t Size_in_Group13Var1_static(void);
GroupVariationID ID_in_Group13Var1_static(void);

boolean Read_in_Group13Var1_static(RSeq_for_Uint16_t *, Group13Var1*);
boolean Write_in_Group13Var1_static(Group13Var1*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group13Var1_static(RSeq_for_Uint16_t*, BinaryCommandEvent*);
boolean WriteTarget_in_Group13Var1_static(BinaryCommandEvent*, WSeq_for_Uint16_t*);

// Binary Command Event - With Time
////struct Group13Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(13,2); }

////  Group13Var2();

////  static size_t Size() { return 7; }
////  static bool Read(ser4cpp::rseq_t&, Group13Var2&);
////  static bool Write(const Group13Var2&, ser4cpp::wseq_t&);

  uint8_t flags;
  DNPTime timeDNPTime;

////  typedef BinaryCommandEvent Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, BinaryCommandEvent&);
////  static bool WriteTarget(const BinaryCommandEvent&, ser4cpp::wseq_t&);
////  static DNP3Serializer<BinaryCommandEvent> Inst() { return DNP3Serializer<BinaryCommandEvent>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group13Var2;

uint16_t Size_in_Group13Var2_static(void);

void Group13Var2_in_Group13Var2(Group13Var2 *pGroup13Var2);
GroupVariationID ID_in_Group13Var2_static(void);

boolean Read_in_Group13Var2_static(RSeq_for_Uint16_t *, Group13Var2*);
boolean Write_in_Group13Var2_static(Group13Var2*, WSeq_for_Uint16_t*);

boolean ReadTarget_in_Group13Var2_static(RSeq_for_Uint16_t*, BinaryCommandEvent*);
boolean WriteTarget_in_Group13Var2_static(BinaryCommandEvent*, WSeq_for_Uint16_t*);


////}

#endif
