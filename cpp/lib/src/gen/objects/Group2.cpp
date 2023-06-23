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
#include "Group2.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"

#include "MeasurementFactory.h"
//#include "WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

Group2Var1 Apply_in_ConvertGroup2Var1_static(Binary* src);
Group2Var2 Apply_in_ConvertGroup2Var2_static(Binary* src);
Group2Var3 Apply_in_ConvertGroup2Var3_static(Binary* src);

// ------- Group2Var1 -------

void Group2Var1_in_Group2Var1(Group2Var1 *pGroup2Var1)
{
  pGroup2Var1->flags = 0;
}

boolean Read_in_Group2Var1_static(RSeq_for_Uint16_t* buffer, Group2Var1* output)
{
//  return LittleEndian::read(buffer, output.flags);
  return read_from_in_UInt8_static(buffer, &(output->flags));
}

boolean Write_in_Group2Var1_static(Group2Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags);
  return write_to_in_UInt8_static(buffer, arg->flags);
}

boolean ReadTarget_in_Group2Var1_static(RSeq_for_Uint16_t* buff, Binary* output)
{
  Group2Var1 value;
//  if(Read(buff, value))
  Group2Var1_in_Group2Var1(&value);
  if(Read_in_Group2Var1_static(buff, &value))
  {
////    output = BinaryFactory::From(value.flags);
    Binary temp = From_in_BinaryFactory_staticOver1(value.flags);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group2Var1_static(Binary* value, WSeq_for_Uint16_t* buff)
{
////  return Group2Var1::Write(ConvertGroup2Var1::Apply(value), buff);
//typedef ConvertQ<Group2Var1, Binary> ConvertGroup2Var1;
  Group2Var1 temp = Apply_in_ConvertGroup2Var1_static(value);
  return Write_in_Group2Var1_static(&temp, buff);
}

Group2Var1 Apply_in_ConvertGroup2Var1_static(Binary* src)
{
  Group2Var1 target;
  Group2Var1_in_Group2Var1(&target);
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

////}

// ------- Group2Var2 -------

void Group2Var2_in_Group2Var2(Group2Var2 *pGroup2Var2)
{
  pGroup2Var2->flags = 0;
//// time(0)
  DNPTime_in_DNPTimeOver2(&(pGroup2Var2->timeDNPTime), 0);
}

boolean Read_in_Group2Var2_static(RSeq_for_Uint16_t* buffer, Group2Var2* output)
{
////  return LittleEndian::read(buffer, output.flags, output.time);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

boolean Write_in_Group2Var2_static(Group2Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

boolean ReadTarget_in_Group2Var2_static(RSeq_for_Uint16_t* buff, Binary* output)
{
  Group2Var2 value;
////  if(Read(buff, value))
  Group2Var2_in_Group2Var2(&value);
  if(Read_in_Group2Var2_static(buff, &value))
  {
////    output = BinaryFactory::From(value.flags, value.time);
    Binary temp = From_in_BinaryFactory_staticOver3(value.flags, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group2Var2_static(Binary* value, WSeq_for_Uint16_t* buff)
{
////  return Group2Var2::Write(ConvertGroup2Var2::Apply(value), buff);
////typedef ConvertQT<Group2Var2, Binary> ConvertGroup2Var2;
  Group2Var2 temp = Apply_in_ConvertGroup2Var2_static(value);
  return Write_in_Group2Var2_static(&temp, buff);
}

Group2Var2 Apply_in_ConvertGroup2Var2_static(Binary* src)
{
  Group2Var2 target;
  Group2Var2_in_Group2Var2(&target);
  target.flags = (src->tTypedMeasurement_for_Boolean).mMeasurement.flags.value;
  target.timeDNPTime.value = (src->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value;
  return target;
}

////template<class Target, class Source> struct ConvertQT : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        t.time = src.time;
////        return t;
////    }
////};

// ------- Group2Var3 -------

void Group2Var3_in_Group2Var3(Group2Var3 *pGroup2Var3)
{
  pGroup2Var3->flags = 0;
  pGroup2Var3->time_uint16_t = 0;
}

boolean Read_in_Group2Var3_static(RSeq_for_Uint16_t* buffer, Group2Var3* output)
{
//  return LittleEndian::read(buffer, output.flags, output.time);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, &(output->time_uint16_t));
}

boolean Write_in_Group2Var3_static(Group2Var3* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->time_uint16_t);
}

boolean ReadTarget_in_Group2Var3_static(RSeq_for_Uint16_t* buff, Binary* output)
{
  Group2Var3 value;
////  if(Read(buff, value))
  Group2Var3_in_Group2Var3(&value);
  if(Read_in_Group2Var3_static(buff, &value))
  {
////    output = BinaryFactory::From(value.flags, value.time);
    Binary temp = From_in_BinaryFactory_staticOver2(value.flags, value.time_uint16_t);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group2Var3_static(Binary* value, WSeq_for_Uint16_t* buff)
{
////  return Group2Var3::Write(ConvertGroup2Var3::Apply(value), buff);
////typedef ConvertQTDowncast<Group2Var3, Binary, uint16_t> ConvertGroup2Var3;
  Group2Var3 temp = Apply_in_ConvertGroup2Var3_static(value);
  return Write_in_Group2Var3_static(&temp, buff);
}

Group2Var3 Apply_in_ConvertGroup2Var3_static(Binary* src)
{
  Group2Var3 target;
  Group2Var3_in_Group2Var3(&target);
  target.flags = (src->tTypedMeasurement_for_Boolean).mMeasurement.flags.value;
  target.time_uint16_t = (uint16_t)(src->tTypedMeasurement_for_Boolean).mMeasurement.timeDNPTime.value;
  return target;
}

////template<class Target, class Source, class Downcast> struct ConvertQTDowncast : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        t.time = static_cast<Downcast>(src.time.value);
////        return t;
////    }
////};


////}
GroupVariationID ID_in_Group2Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 2, 0);
//// return GroupVariationID(2,0);
  return gGroupVariationID;
}

GroupVariationID ID_in_Group2Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 2, 1);
////  return GroupVariationID(2,1);
  return gGroupVariationID;
}
////  static size_t Size() { return 1; }
uint16_t Size_in_Group2Var1_static(void)
{
  return 1;
}

DNP3Serializer_for_Binary  Inst_in_Group2Var1_static(void)
{
  DNP3Serializer_for_Binary dDNP3Serializer_for_Binary;
  DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(&dDNP3Serializer_for_Binary,
      ID_in_Group2Var1_static(),
      Size_in_Group2Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group2Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group2Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Binary;
}

GroupVariationID ID_in_Group2Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 2, 2);
////  return GroupVariationID(2,2);
  return gGroupVariationID;
}

uint16_t Size_in_Group2Var2_static(void)
{
  return 7;
}

DNP3Serializer_for_Binary  Inst_in_Group2Var2_static(void)
{
  DNP3Serializer_for_Binary dDNP3Serializer_for_Binary;
  DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(&dDNP3Serializer_for_Binary,
      ID_in_Group2Var2_static(),
      Size_in_Group2Var2_static(),
      &ReadTarget_in_Group2Var2_static,
      &WriteTarget_in_Group2Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Binary;
}

GroupVariationID ID_in_Group2Var3_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 2, 3);
////  return GroupVariationID(2,3);
  return gGroupVariationID;
}

uint16_t Size_in_Group2Var3_static(void)
{
  return 3;
}

////  static DNP3Serializer<Binary> Inst() { return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget); }
DNP3Serializer_for_Binary  Inst_in_Group2Var3_static(void)
{
  DNP3Serializer_for_Binary dDNP3Serializer_for_Binary;
  DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(&dDNP3Serializer_for_Binary,
      ID_in_Group2Var3_static(),
      Size_in_Group2Var3_static(),
      &ReadTarget_in_Group2Var3_static,
      &WriteTarget_in_Group2Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Binary;
}
