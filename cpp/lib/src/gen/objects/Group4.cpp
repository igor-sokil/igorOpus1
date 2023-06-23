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
#include "Group4.h"

//#include "DNPTimeParsing.h"
//#include <ser4cpp/serialization/LittleEndian.h>
#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

Group4Var1 Apply_in_ConvertGroup4Var1_static(DoubleBitBinary* src);
Group4Var2 Apply_in_ConvertGroup4Var2_static(DoubleBitBinary* src);
Group4Var3 Apply_in_ConvertGroup4Var3_static(DoubleBitBinary* src);

// ------- Group4Var1 -------

////Group4Var1::Group4Var1() : flags(0)
////{}
void Group4Var1_in_Group4Var1(Group4Var1 *pGroup4Var1)
{
  pGroup4Var1->flags = 0;
}

////bool Group4Var1::Read(rseq_t& buffer, Group4Var1& output)
////{
////  return LittleEndian::read(buffer, output.flags);
////}
boolean Read_in_Group4Var1_static(RSeq_for_Uint16_t* buffer, Group4Var1* output)
{
//  return LittleEndian::read(buffer, output.flags);
  return read_from_in_UInt8_static(buffer, &(output->flags));
}

////bool Group4Var1::Write(const Group4Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags);
////}
boolean Write_in_Group4Var1_static(Group4Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags);
  return write_to_in_UInt8_static(buffer, arg->flags);
}

////bool Group4Var1::ReadTarget(rseq_t& buff, DoubleBitBinary& output)
////{
////  Group4Var1 value;
////  if(Read(buff, value))
////  {
////    output = DoubleBitBinaryFactory::From(value.flags);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group4Var1_static(RSeq_for_Uint16_t* buff, DoubleBitBinary* output)
{
  Group4Var1 value;
//  if(Read(buff, value))
  Group4Var1_in_Group4Var1(&value);
  if(Read_in_Group4Var1_static(buff, &value))
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

////bool Group4Var1::WriteTarget(const DoubleBitBinary& value, ser4cpp::wseq_t& buff)
////{
////  return Group4Var1::Write(ConvertGroup4Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group4Var1_static(DoubleBitBinary* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQ<Group4Var1, DoubleBitBinary> ConvertGroup4Var1;
  Group4Var1 temp = Apply_in_ConvertGroup4Var1_static(value);
  return Write_in_Group4Var1_static(&temp, buff);
}

Group4Var1 Apply_in_ConvertGroup4Var1_static(DoubleBitBinary* src)
{
  Group4Var1 target;
  Group4Var1_in_Group4Var1(&target);
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

// ------- Group4Var2 -------

////Group4Var2::Group4Var2() : flags(0), time(0)
////{}
void Group4Var2_in_Group4Var2(Group4Var2 *pGroup4Var2)
{
  pGroup4Var2->flags = 0;
//// time(0)
  DNPTime_in_DNPTimeOver2(&(pGroup4Var2->timeDNPTime), 0);
}

////bool Group4Var2::Read(rseq_t& buffer, Group4Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.time);
////}
boolean Read_in_Group4Var2_static(RSeq_for_Uint16_t* buffer, Group4Var2* output)
{
////  return LittleEndian::read(buffer, output.flags, output.time);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group4Var2::Write(const Group4Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
////}
boolean Write_in_Group4Var2_static(Group4Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group4Var2::ReadTarget(rseq_t& buff, DoubleBitBinary& output)
////{
////  Group4Var2 value;
////  if(Read(buff, value))
////  {
////    output = DoubleBitBinaryFactory::From(value.flags, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group4Var2_static(RSeq_for_Uint16_t* buff, DoubleBitBinary* output)
{
  Group4Var2 value;
////  if(Read(buff, value))
  Group4Var2_in_Group4Var2(&value);
  if(Read_in_Group4Var2_static(buff, &value))
  {
////    output = BinaryFactory::From(value.flags, value.time);
    DoubleBitBinary temp = From_in_DoubleBitBinaryFactory_staticOver3(value.flags, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group4Var2::WriteTarget(const DoubleBitBinary& value, ser4cpp::wseq_t& buff)
////{
////  return Group4Var2::Write(ConvertGroup4Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group4Var2_static(DoubleBitBinary* value, WSeq_for_Uint16_t* buff)
{
////  return Group4Var2::Write(ConvertGroup4Var2::Apply(value), buff);
//typedef ConvertQT<Group4Var2, DoubleBitBinary> ConvertGroup4Var2;
  Group4Var2 temp = Apply_in_ConvertGroup4Var2_static(value);
  return Write_in_Group4Var2_static(&temp, buff);
}

Group4Var2 Apply_in_ConvertGroup4Var2_static(DoubleBitBinary* src)
{
  Group4Var2 target;
  Group4Var2_in_Group4Var2(&target);
  target.flags = (src->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.flags.value;
  target.timeDNPTime.value = (src->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.timeDNPTime.value;
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

// ------- Group4Var3 -------

////Group4Var3::Group4Var3() : flags(0), time(0)
////{}
void Group4Var3_in_Group4Var3(Group4Var3 *pGroup4Var3)
{
  pGroup4Var3->flags = 0;
  pGroup4Var3->time_uint16_t = 0;
}

////bool Group4Var3::Read(rseq_t& buffer, Group4Var3& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.time);
////}
boolean Read_in_Group4Var3_static(RSeq_for_Uint16_t* buffer, Group4Var3* output)
{
//  return LittleEndian::read(buffer, output.flags, output.time);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, &(output->time_uint16_t));
}

////bool Group4Var3::Write(const Group4Var3& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
////}
boolean Write_in_Group4Var3_static(Group4Var3* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->time_uint16_t);
}

////bool Group4Var3::ReadTarget(rseq_t& buff, DoubleBitBinary& output)
////{
////  Group4Var3 value;
////  if(Read(buff, value))
////  {
////    output = DoubleBitBinaryFactory::From(value.flags, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group4Var3_static(RSeq_for_Uint16_t* buff, DoubleBitBinary* output)
{
  Group4Var3 value;
////  if(Read(buff, value))
  Group4Var3_in_Group4Var3(&value);
  if(Read_in_Group4Var3_static(buff, &value))
  {
////    output = BinaryFactory::From(value.flags, value.time);
    DoubleBitBinary temp = From_in_DoubleBitBinaryFactory_staticOver2(value.flags, value.time_uint16_t);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group4Var3::WriteTarget(const DoubleBitBinary& value, ser4cpp::wseq_t& buff)
////{
////  return Group4Var3::Write(ConvertGroup4Var3::Apply(value), buff);
////}
boolean WriteTarget_in_Group4Var3_static(DoubleBitBinary* value, WSeq_for_Uint16_t* buff)
{
////typedef ConvertQTDowncast<Group4Var3, DoubleBitBinary, uint16_t> ConvertGroup4Var3;
  Group4Var3 temp = Apply_in_ConvertGroup4Var3_static(value);
  return Write_in_Group4Var3_static(&temp, buff);
}

Group4Var3 Apply_in_ConvertGroup4Var3_static(DoubleBitBinary* src)
{
  Group4Var3 target;
  Group4Var3_in_Group4Var3(&target);
  target.flags = (src->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.flags.value;
  target.time_uint16_t = (uint16_t)(src->tTypedMeasurement_for_DoubleBit_uint8_t).mMeasurement.timeDNPTime.value;
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
GroupVariationID ID_in_Group4Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 0);
//// return GroupVariationID(4,0);
  return gGroupVariationID;
}

uint16_t Size_in_Group4Var1_static(void)
{
  return 1;
}

GroupVariationID ID_in_Group4Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 1);
////  return GroupVariationID(4,1);
  return gGroupVariationID;
}

DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var1_static(void)
{
  DNP3Serializer_for_DoubleBitBinary dDNP3Serializer_for_DoubleBitBinary;
  DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(&dDNP3Serializer_for_DoubleBitBinary,
      ID_in_Group4Var1_static(),
      Size_in_Group4Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group4Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group4Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_DoubleBitBinary;
}

uint16_t Size_in_Group4Var2_static(void)
{
  return 7;
}

GroupVariationID ID_in_Group4Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 2);
////  return GroupVariationID(4,2);
  return gGroupVariationID;
}

DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var2_static(void)
{
  DNP3Serializer_for_DoubleBitBinary dDNP3Serializer_for_DoubleBitBinary;
  DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(&dDNP3Serializer_for_DoubleBitBinary,
      ID_in_Group4Var2_static(),
      Size_in_Group4Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group4Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group4Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_DoubleBitBinary;
}

uint16_t Size_in_Group4Var3_static(void)
{
  return 3;
}

GroupVariationID ID_in_Group4Var3_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 3);
////  return GroupVariationID(4,3);
  return gGroupVariationID;
}

DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var3_static(void)
{
  DNP3Serializer_for_DoubleBitBinary dDNP3Serializer_for_DoubleBitBinary;
  DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(&dDNP3Serializer_for_DoubleBitBinary,
      ID_in_Group4Var3_static(),
      Size_in_Group4Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group4Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group4Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_DoubleBitBinary;
}
