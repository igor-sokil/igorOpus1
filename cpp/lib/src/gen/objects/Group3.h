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

#ifndef OPENDNP3_GROUP3_H
#define OPENDNP3_GROUP3_H

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

// Double-bit Binary Input - Any Variation
////struct Group3Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(3,0); }
////};
   GroupVariationID ID_in_Group3Var0_static(void);
   GroupVariationID ID_in_Group3Var1_static(void);

   GroupVariationID ID_in_Group3Var0_static(void)
{
//// return GroupVariationID(3,0);
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 3, 0);
////  return GroupVariationID(3,0); 
 return gGroupVariationID;
}

// Double-bit Binary Input - Packed Format
////struct Group3Var1
////{
////  static GroupVariationID ID() { return GroupVariationID(3,1); }
////};
   GroupVariationID ID_in_Group3Var1_static(void)
{
//// return GroupVariationID(3,1);
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 3, 1);
////  return GroupVariationID(3,1); 
 return gGroupVariationID;
}

// Double-bit Binary Input - With Flags
////struct Group3Var2
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(3,2); }

////  Group3Var2();

////  static size_t Size() { return 1; }
////  static bool Read(ser4cpp::rseq_t&, Group3Var2&);
////  static bool Write(const Group3Var2&, ser4cpp::wseq_t&);

  uint8_t flags;

////  typedef DoubleBitBinary Target;
////  typedef DoubleBitBinarySpec Spec;
////  static bool ReadTarget(ser4cpp::rseq_t&, DoubleBitBinary&);
////  static bool WriteTarget(const DoubleBitBinary&, ser4cpp::wseq_t&);
////  static DNP3Serializer<DoubleBitBinary> Inst() { return DNP3Serializer<DoubleBitBinary>(ID(), Size(), &ReadTarget, &WriteTarget); }
////  static const StaticDoubleBinaryVariation svariation = StaticDoubleBinaryVariation::Group3Var2;
} Group3Var2;
   GroupVariationID ID_in_Group3Var2_static(void);
   Group3Var2_in_Group3Var2(Group3Var2 *pGroup3Var2);
   uint16_t Size_in_Group3Var2_static(void);
 boolean Read_in_Group3Var2_static(RSeq_for_Uint16_t *, Group3Var2*);
 boolean Write_in_Group3Var2_static(Group3Var2*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group3Var2_static(RSeq_for_Uint16_t*, DoubleBitBinary*);
 boolean WriteTarget_in_Group3Var2_static(DoubleBitBinary*, WSeq_for_Uint16_t*);
 DNP3Serializer_for_Binary  Inst_in_Group3Var2_static(void);
////  static const StaticDoubleBinaryVariation svariation = StaticDoubleBinaryVariation::Group3Var2;
 const StaticDoubleBinaryVariation_uint8_t  svariation_in_Group3Var2 = StaticDoubleBinaryVariation_Group3Var2;

   GroupVariationID ID_in_Group3Var2_static(void)
{
//// return GroupVariationID(3,2);
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 3, 2);
////  return GroupVariationID(3,2); 
 return gGroupVariationID;
}

 uint16_t Size_in_Group3Var2_static(void) 
{
 return 1; 
}

 DNP3Serializer_for_Binary  Inst_in_Group3Var2_static(void)
{
   DNP3Serializer_for_Binary dDNP3Serializer_for_Binary;
   DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(&dDNP3Serializer_for_Binary,
                   ID_in_Group3Var2_static(),
                   Size_in_Group3Var2_static(),
                   &ReadTarget_in_Group3Var2_static,
                   &WriteTarget_in_Group3Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Binary;
}

////}

#endif
