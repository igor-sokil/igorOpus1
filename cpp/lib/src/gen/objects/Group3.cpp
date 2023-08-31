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
#include "Group3.h"

#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

Group3Var2 Apply_in_ConvertGroup3Var2_static(DoubleBitBinary* src);

// ------- Group3Var2 -------

////Group3Var2::Group3Var2() : flags(0)
////{}
void Group3Var2_in_Group3Var2(Group3Var2 *pGroup3Var2)
{
  pGroup3Var2->flags = 0;
}

////bool Group3Var2::Read(rseq_t& buffer, Group3Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags);
////}
boolean Read_in_Group3Var2_static(RSeq_for_Uint16_t* buffer, Group3Var2* output)
{
//  return LittleEndian::read(buffer, output.flags);
  return read_from_in_UInt8_static(buffer, &(output->flags));
}

////bool Group3Var2::Write(const Group3Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags);
////}
boolean Write_in_Group3Var2_static(Group3Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags);
  return write_to_in_UInt8_static(buffer, arg->flags);
}

////bool Group3Var2::ReadTarget(rseq_t& buff, DoubleBitBinary& output)
////{
/////  Group3Var2 value;
/////  if(Read(buff, value))
/////  {
/////    output = DoubleBitBinaryFactory::From(value.flags);
/////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group3Var2_static(RSeq_for_Uint16_t* buff, DoubleBitBinary* output)
{
  Group3Var2 value;
//  if(Read(buff, value))
  Group3Var2_in_Group3Var2(&value);
  if(Read_in_Group3Var2_static(buff, &value))
  {
    DoubleBitBinary temp = From_in_DoubleBitBinaryFactory_staticOver1(value.flags);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group3Var2::WriteTarget(const DoubleBitBinary& value, ser4cpp::wseq_t& buff)
////{
////  return Group3Var2::Write(ConvertGroup3Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group3Var2_static(DoubleBitBinary* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQ<Group3Var2, DoubleBitBinary> ConvertGroup3Var2;
  Group3Var2 temp = Apply_in_ConvertGroup3Var2_static(value);
  return Write_in_Group3Var2_static(&temp, buff);
}

Group3Var2 Apply_in_ConvertGroup3Var2_static(DoubleBitBinary* src)
{
  Group3Var2 target;
  Group3Var2_in_Group3Var2(&target);
  target.flags = (src->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.flags.value;
  return target;
}

////template<class Target, class Source> struct ConvertQ : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        return t;
////    }
////};


////}
GroupVariationID ID_in_Group3Var0_static(void)
{
//// return GroupVariationID(3,0);
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 3, 0);
////  return GroupVariationID(3,0);
  return gGroupVariationID;
}

GroupVariationID ID_in_Group3Var1_static(void)
{
//// return GroupVariationID(3,1);
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 3, 1);
////  return GroupVariationID(3,1);
  return gGroupVariationID;
}

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

DNP3Serializer_for_DoubleBitBinary  Inst_in_Group3Var2_static(void)
{
  DNP3Serializer_for_DoubleBitBinary dDNP3Serializer_for_DoubleBitBinary;
  DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(&dDNP3Serializer_for_DoubleBitBinary,
      ID_in_Group3Var2_static(),
      Size_in_Group3Var2_static(),
      &ReadTarget_in_Group3Var2_static,
      &WriteTarget_in_Group3Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_DoubleBitBinary;
}
