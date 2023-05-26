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

#ifndef OPENDNP3_GROUP51_H
#define OPENDNP3_GROUP51_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "RSeq.h"
#include "WSeq.h"
#include "SerializationTemplates.h"

////namespace opendnp3 {

// Time and Date CTO - Absolute time, synchronized
////struct Group51Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(51,1); }

////  Group51Var1();

////  static size_t Size() { return 6; }
////  static bool Read(ser4cpp::rseq_t&, Group51Var1&);
////  static bool Write(const Group51Var1&, ser4cpp::wseq_t&);

  DNPTime timeDNPTime;
} Group51Var1;

  uint16_t Size_in_Group51Var1_static(void);
 boolean Read_in_Group51Var1_static(RSeq_for_Uint16_t *, Group51Var1*);
 boolean Write_in_Group51Var1_static(Group51Var1*, WSeq_for_Uint16_t*);
 void Group51Var1_in_Group51Var1(Group51Var1 *pGroup51Var1);
  GroupVariationID ID_in_Group51Var1_static(void);

// Time and Date CTO - Absolute time, unsynchronized
////struct Group51Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(51,2); }

////  Group51Var2();

////  static size_t Size() { return 6; }
////  static bool Read(ser4cpp::rseq_t&, Group51Var2&);
////  static bool Write(const Group51Var2&, ser4cpp::wseq_t&);

  DNPTime timeDNPTime;
} Group51Var2;

  uint16_t Size_in_Group51Var2_static(void);
 void Group51Var2_in_Group51Var2(Group51Var2 *pGroup51Var2);
  GroupVariationID ID_in_Group51Var2_static(void);
 boolean Read_in_Group51Var2_static(RSeq_for_Uint16_t *, Group51Var2*);
 boolean Write_in_Group51Var2_static(Group51Var2*, WSeq_for_Uint16_t*);

////}

#endif
