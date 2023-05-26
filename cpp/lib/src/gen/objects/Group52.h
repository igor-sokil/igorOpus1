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

#ifndef OPENDNP3_GROUP52_H
#define OPENDNP3_GROUP52_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"

////namespace opendnp3 {

// Time Delay - Coarse
////struct Group52Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(52,1); }

////  Group52Var1();

////  static size_t Size() { return 2; }
////  static bool Read(ser4cpp::rseq_t&, Group52Var1&);
////  static bool Write(const Group52Var1&, ser4cpp::wseq_t&);

  uint16_t time_uint16_t;
} Group52Var1;

  uint16_t Size_in_Group52Var1_static(void);

 uint16_t Size_in_Group52Var1_static(void) 
{
 return 2; 
}

 void Group52Var1_in_Group52Var1(Group52Var1 *pGroup52Var1);

  GroupVariationID ID_in_Group52Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 52, 1);
////  return GroupVariationID(52,1); 
 return gGroupVariationID;
}

// Time Delay - Fine
////struct Group52Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(52,2); }

////  Group52Var2();

////  static size_t Size() { return 2; }
////  static bool Read(ser4cpp::rseq_t&, Group52Var2&);
////  static bool Write(const Group52Var2&, ser4cpp::wseq_t&);

  uint16_t time_uint16_t;
} Group52Var2;

  uint16_t Size_in_Group52Var2_static(void);

 uint16_t Size_in_Group52Var2_static(void) 
{
 return 2; 
}

 void Group52Var2_in_Group52Var2(Group52Var2 *pGroup52Var2);

  GroupVariationID ID_in_Group52Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 52, 2);
////  return GroupVariationID(52,2); 
 return gGroupVariationID;
}

 boolean Read_in_Group52Var2_static(RSeq_for_Uint16_t *, Group2Var1*);
 boolean Write_in_Group52Var2_static(Group2Var1*, WSeq_for_Uint16_t*);

////}

#endif
