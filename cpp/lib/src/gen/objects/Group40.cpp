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
#include "Group40.h"

#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"
#include "DownSampling.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

Group40Var1 Apply_in_ConvertGroup40Var1_static(AnalogOutputStatus* src, uint8_t Overrange);
Group40Var2 Apply_in_ConvertGroup40Var2_static(AnalogOutputStatus* src, uint8_t Overrange);
Group40Var3 Apply_in_ConvertGroup40Var3_static(AnalogOutputStatus* src, uint8_t Overrange);

// ------- Group40Var1 -------

////Group40Var1::Group40Var1() : flags(0), value(0)
////{}
void Group40Var1_in_Group40Var1(Group40Var1 *pGroup40Var1)
{
  pGroup40Var1->flags = 0;
  pGroup40Var1->value = 0;
}

////bool Group40Var1::Read(rseq_t& buffer, Group40Var1& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group40Var1_static(RSeq_for_Uint16_t* buffer, Group40Var1* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value));
}

////bool Group40Var1::Write(const Group40Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group40Var1_static(Group40Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value);
}

////bool Group40Var1::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group40Var1 value;
////  if(Read(buff, value))
////  {
////    output = AnalogOutputStatusFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group40Var1_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group40Var1 value;
////  if(Read(buff, value))
  Group40Var1_in_Group40Var1(&value);
  if(Read_in_Group40Var1_static(buff, &value))
  {
//AnalogOutputStatus From_in_AnalogOutputStatusFactory_staticOver1(uint8_t flags, double value);
////    output = AnalogOutputStatusFactory::From(value.flags, value.value);
    AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver1(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group40Var1::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group40Var1::Write(ConvertGroup40Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group40Var1_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
////  return Group40Var1::Write(ConvertGroup40Var1::Apply(value), buff);
//typedef ConvertQVRangeCheck<Group40Var1, AnalogOutputStatus, 0x20> ConvertGroup40Var1;
  Group40Var1 temp = Apply_in_ConvertGroup40Var1_static(value, 0x20);
  return Write_in_Group40Var1_static(&temp, buff);
}

Group40Var1 Apply_in_ConvertGroup40Var1_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group40Var1 target;
  Group40Var1_in_Group40Var1(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint32((src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
  return target;
}
////template<class Target, class Source, uint8_t Overrange> struct ConvertQVRangeCheck : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
////        t.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
////        return t;
////    }
////};

// ------- Group40Var2 -------

////Group40Var2::Group40Var2() : flags(0), value(0)
////{}
void Group40Var2_in_Group40Var2(Group40Var2 *pGroup40Var2)
{
  pGroup40Var2->flags = 0;
  pGroup40Var2->value = 0;
}

////bool Group40Var2::Read(rseq_t& buffer, Group40Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group40Var2_static(RSeq_for_Uint16_t* buffer, Group40Var2* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value));
}

///bool Group40Var2::Write(const Group40Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group40Var2_static(Group40Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group40Var2::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group40Var2 value;
////  if(Read(buff, value))
////  {
////    output = AnalogOutputStatusFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
///  }
////}
boolean ReadTarget_in_Group40Var2_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group40Var2 value;
////  if(Read(buff, value))
  Group40Var2_in_Group40Var2(&value);
  if(Read_in_Group40Var2_static(buff, &value))
  {
//AnalogOutputStatus From_in_AnalogOutputStatusFactory_staticOver1(uint8_t flags, double value);
////    output = AnalogOutputStatusFactory::From(value.flags, value.value);
    AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver1(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group40Var2::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group40Var2::Write(ConvertGroup40Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group40Var2_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
////  return Group40Var1::Write(ConvertGroup40Var1::Apply(value), buff);
//typedef ConvertQVRangeCheck<Group40Var1, AnalogOutputStatus, 0x20> ConvertGroup40Var1;
  Group40Var2 temp = Apply_in_ConvertGroup40Var2_static(value, 0x20);
  return Write_in_Group40Var2_static(&temp, buff);
}

Group40Var2 Apply_in_ConvertGroup40Var2_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group40Var2 target;
  Group40Var2_in_Group40Var2(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint32((src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
  return target;
}
////template<class Target, class Source, uint8_t Overrange> struct ConvertQVRangeCheck : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
////        t.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
////        return t;
////    }
////};

// ------- Group40Var3 -------

////Group40Var3::Group40Var3() : flags(0), value(0.0)
////{}
void Group40Var3_in_Group40Var3(Group40Var3 *pGroup40Var3)
{
  pGroup40Var3->flags = 0;
  pGroup40Var3->value = 0.0;
}

////bool Group40Var3::Read(rseq_t& buffer, Group40Var3& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group40Var3_static(RSeq_for_Uint16_t* buffer, Group40Var3* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_Float32_static(buffer, &(output->value));
}

////bool Group40Var3::Write(const Group40Var3& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group40Var3_static(Group40Var3* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_Float32_static(buffer, arg->value);
}

////bool Group40Var3::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group40Var3 value;
////  if(Read(buff, value))
////  {
////    output = AnalogOutputStatusFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group40Var3_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group40Var3 value;
////  if(Read(buff, value))
  Group40Var3_in_Group40Var3(&value);
  if(Read_in_Group40Var3_static(buff, &value))
  {
//AnalogOutputStatus From_in_AnalogOutputStatusFactory_staticOver1(uint8_t flags, double value);
////    output = AnalogOutputStatusFactory::From(value.flags, value.value);
    AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver1(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group40Var3::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group40Var3::Write(ConvertGroup40Var3::Apply(value), buff);
////}
boolean WriteTarget_in_Group40Var3_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
////  return Group40Var1::Write(ConvertGroup40Var1::Apply(value), buff);
//typedef ConvertQVRangeCheck<Group40Var1, AnalogOutputStatus, 0x20> ConvertGroup40Var1;
  Group40Var3 temp = Apply_in_ConvertGroup40Var3_static(value, 0x20);
  return Write_in_Group40Var3_static(&temp, buff);
}

Group40Var3 Apply_in_ConvertGroup40Var3_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group40Var3 target;
  Group40Var3_in_Group40Var3(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint32((src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
  return target;
}
////template<class Target, class Source, uint8_t Overrange> struct ConvertQVRangeCheck : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
////        t.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
////        return t;
////    }
////};

// ------- Group40Var4 -------

////Group40Var4::Group40Var4() : flags(0), value(0.0)
////{}
////
////bool Group40Var4::Read(rseq_t& buffer, Group40Var4& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
////
////bool Group40Var4::Write(const Group40Var4& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
////
////bool Group40Var4::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group40Var4 value;
////  if(Read(buff, value))
////  {
////    output = AnalogOutputStatusFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
////
////bool Group40Var4::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group40Var4::Write(ConvertGroup40Var4::Apply(value), buff);
////}
////

////}
GroupVariationID ID_in_Group40Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 40, 0);
//// return GroupVariationID(40,0);
  return gGroupVariationID;
}

uint16_t Size_in_Group40Var1_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group40Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 40, 1);
////  return GroupVariationID(40,1);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group40Var1_static(void)
{
  DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
  DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
      ID_in_Group40Var1_static(),
      Size_in_Group40Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group40Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group40Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogOutputStatus;
}

uint16_t Size_in_Group40Var2_static(void)
{
  return 3;
}

GroupVariationID ID_in_Group40Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 40, 2);
////  return GroupVariationID(40,2);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group40Var2_static(void)
{
  DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
  DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
      ID_in_Group40Var2_static(),
      Size_in_Group40Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group40Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group40Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogOutputStatus;
}

uint16_t Size_in_Group40Var3_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group40Var3_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 40, 3);
////  return GroupVariationID(40,3);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group40Var3_static(void)
{
  DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
  DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
      ID_in_Group40Var3_static(),
      Size_in_Group40Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group40Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group40Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogOutputStatus;
}

