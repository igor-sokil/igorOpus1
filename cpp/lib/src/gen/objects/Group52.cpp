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

#include "header.h"
#include "Group52.h"

#include "SerializationTemplates.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group52Var1 -------

////Group52Var1::Group52Var1() : time(0)
////{}
void Group52Var1_in_Group52Var1(Group52Var1 *pGroup52Var1)
{
  pGroup52Var1->time_uint16_t = 0;
}

////bool Group52Var1::Read(rseq_t& buffer, Group52Var1& output)
///{
////  return LittleEndian::read(buffer, output.time);
////}
boolean Read_in_Group52Var1_static(RSeq_for_Uint16_t* buffer, Group52Var1* output)
{
////  return LittleEndian::read(buffer, output.time);
  return read_from_in_UInt16_static(buffer, &(output->time_uint16_t));
}

////bool Group52Var1::Write(const Group52Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.time);
////}
boolean Write_in_Group52Var1_static(Group52Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.time);
  return  write_to_in_UInt16_static(buffer, arg->time_uint16_t);////arg->value);
}

// ------- Group52Var2 -------

////Group52Var2::Group52Var2() : time(0)
////{}
void Group52Var2_in_Group52Var2(Group52Var2 *pGroup52Var2)
{
  pGroup52Var2->time_uint16_t = 0;
}

////bool Group52Var2::Read(rseq_t& buffer, Group52Var2& output)
////{
////  return LittleEndian::read(buffer, output.time);
////}
boolean Read_in_Group52Var2_static(RSeq_for_Uint16_t* buffer, Group52Var2* output)
{
////  return LittleEndian::read(buffer, output.time);
  return read_from_in_UInt16_static(buffer, &(output->time_uint16_t));
}

////bool Group52Var2::Write(const Group52Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.time);
////}
boolean Write_in_Group52Var2_static(Group52Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.time);
  return  write_to_in_UInt16_static(buffer, arg->time_uint16_t);////arg->value);
}


////}
uint16_t Size_in_Group52Var1_static(void)
{
  return 2;
}
GroupVariationID ID_in_Group52Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 52, 1);
////  return GroupVariationID(52,1);
  return gGroupVariationID;
}

uint16_t Size_in_Group52Var2_static(void)
{
  return 2;
}
GroupVariationID ID_in_Group52Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 52, 2);
////  return GroupVariationID(52,2);
  return gGroupVariationID;
}
