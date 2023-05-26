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

#ifndef OPENDNP3_GROUP12_H
#define OPENDNP3_GROUP12_H

////#include "opendnp3/app/GroupVariationID.h"
////#include <ser4cpp/container/SequenceTypes.h>
////#include "opendnp3/app/DNPTime.h"
////#include "app/DNP3Serializer.h"
////#include "opendnp3/app/ControlRelayOutputBlock.h"

#include "GroupVariationID.h"
//#include <ser4cpp/container/SequenceTypes.h>
#include "DNPTime.h"
#include "DNP3Serializer.h"
#include "ControlRelayOutputBlock.h"

////namespace opendnp3 {

// Binary Command - Any Variation
////struct Group12Var0
////{
////  static GroupVariationID ID() { return GroupVariationID(12,0); }
////};

  GroupVariationID ID_in_Group12Var0_static(void);

  GroupVariationID ID_in_Group12Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 12, 0);
//// return GroupVariationID(12,0);
 return gGroupVariationID;
}

// Binary Command - CROB
////struct Group12Var1
typedef struct
{
////  static GroupVariationID ID() { return GroupVariationID(12,1); }

////  Group12Var1();

////  static size_t Size() { return 11; }
////  static bool Read(ser4cpp::rseq_t&, Group12Var1&);
////  static bool Write(const Group12Var1&, ser4cpp::wseq_t&);

  uint8_t code;
  uint8_t count;
  uint32_t onTime;
  uint32_t offTime;
  uint8_t status;

////  typedef ControlRelayOutputBlock Target;
////  static bool ReadTarget(ser4cpp::rseq_t&, ControlRelayOutputBlock&);
////  static bool WriteTarget(const ControlRelayOutputBlock&, ser4cpp::wseq_t&);
////  static DNP3Serializer<ControlRelayOutputBlock> Inst() { return DNP3Serializer<ControlRelayOutputBlock>(ID(), Size(), &ReadTarget, &WriteTarget); }
} Group12Var1;

  uint16_t Size_in_Group12Var1_static(void);

 uint16_t Size_in_Group12Var1_static(void) 
{
 return 11; 
}

 void Group2Var1_in_Group12Var1(Group2Var1 *pGroup12Var1);

  GroupVariationID ID_in_Group12Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 12, 1);
////  return GroupVariationID(12,1); 
 return gGroupVariationID;
}

 boolean Read_in_Group12Var1_static(RSeq_for_Uint16_t *, Group2Var1*);
 boolean Write_in_Group12Var1_static(Group2Var1*, WSeq_for_Uint16_t*);

 boolean ReadTarget_in_Group12Var1_static(RSeq_for_Uint16_t*, ControlRelayOutputBlock*);
 boolean WriteTarget_in_Group12Var1_static(ControlRelayOutputBlock*, WSeq_for_Uint16_t*);

 DNP3Serializer_for_ControlRelayOutputBlock  Inst_in_Group12Var1_static(void)
{
   DNP3Serializer_for_ControlRelayOutputBlock dDNP3Serializer_for_ControlRelayOutputBlock;
   DNP3Serializer_for_ControlRelayOutputBlock_in_DNP3Serializer_for_ControlRelayOutputBlock(&dDNP3Serializer_for_ControlRelayOutputBlock,
                   ID_in_Group12Var1_static(),
                   Size_in_Group12Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   //void *read_func,// read_func_t_in_Serializer_for_Binary,
                   &ReadTarget_in_Group12Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   //void *write_func);//write_func_t_in_Serializer_for_Binary);
                   &WriteTarget_in_Group12Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_ControlRelayOutputBlock;
}

////}

#endif
