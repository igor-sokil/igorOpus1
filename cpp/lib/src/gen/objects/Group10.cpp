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
#include "Group10.h"

#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group10Var2 -------

Group10Var2 Apply_in_ConvertGroup10Var2_static(BinaryOutputStatus* src);

////Group10Var2::Group10Var2() : flags(0)
////{}
void Group10Var2_in_Group10Var2(Group10Var2 *pGroup10Var2)
{
  pGroup10Var2->flags = 0;
}

////bool Group10Var2::Read(rseq_t& buffer, Group10Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags);
////}
boolean Read_in_Group10Var2_static(RSeq_for_Uint16_t* buffer, Group10Var2* output)
{
//  return LittleEndian::read(buffer, output.flags);
  return read_from_in_UInt8_static(buffer, &(output->flags));
}

////bool Group10Var2::Write(const Group10Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags);
////}
boolean Write_in_Group10Var2_static(Group10Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags);
  return write_to_in_UInt8_static(buffer, arg->flags);
}

////bool Group10Var2::ReadTarget(rseq_t& buff, BinaryOutputStatus& output)
////{
////  Group10Var2 value;
////  if(Read(buff, value))
////  {
////    output = BinaryOutputStatusFactory::From(value.flags);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group10Var2_static(RSeq_for_Uint16_t* buff, BinaryOutputStatus* output)
{
  Group10Var2 value;
//  if(Read(buff, value))
  Group10Var2_in_Group10Var2(&value);
  if(Read_in_Group10Var2_static(buff, &value))
  {
//BinaryOutputStatus From_in_BinaryOutputStatusFactory_staticOver1(uint8_t flags);
    BinaryOutputStatus temp = From_in_BinaryOutputStatusFactory_staticOver1(value.flags);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group10Var2::WriteTarget(const BinaryOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group10Var2::Write(ConvertGroup10Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group10Var2_static(BinaryOutputStatus* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQ<Group10Var2, BinaryOutputStatus> ConvertGroup10Var2;
  Group10Var2 temp = Apply_in_ConvertGroup10Var2_static(value);
  return Write_in_Group10Var2_static(&temp, buff);
}

Group10Var2 Apply_in_ConvertGroup10Var2_static(BinaryOutputStatus* src)
{
  Group10Var2 target;
  Group10Var2_in_Group10Var2(&target);
  target.flags = (src->tTypedMeasurement_for_Boolean).mMeasurement.flags.value;
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
GroupVariationID ID_in_Group10Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 10, 0);
//// return GroupVariationID(10,0);
  return gGroupVariationID;
}

GroupVariationID ID_in_Group10Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 10, 1);
//// return GroupVariationID(10,1);
  return gGroupVariationID;
}

uint16_t Size_in_Group10Var2_static(void)
{
  return 1;
}

GroupVariationID ID_in_Group10Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 10, 2);
////  return GroupVariationID(10,2);
  return gGroupVariationID;
}

DNP3Serializer_for_BinaryOutputStatus  Inst_in_Group10Var2_static(void)
{
  DNP3Serializer_for_BinaryOutputStatus dDNP3Serializer_for_BinaryOutputStatus;
  DNP3Serializer_for_BinaryOutputStatus_in_DNP3Serializer_for_BinaryOutputStatus(&dDNP3Serializer_for_BinaryOutputStatus,
      ID_in_Group10Var2_static(),
      Size_in_Group10Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group10Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group10Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_BinaryOutputStatus;
}
