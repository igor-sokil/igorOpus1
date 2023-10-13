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
#include "Group43.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"
#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"
#include "DownSampling.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

Group43Var1 Apply_in_ConvertGroup43Var1_static(AnalogCommandEvent* src);
Group43Var2 Apply_in_ConvertGroup43Var2_static(AnalogCommandEvent* src);
Group43Var3 Apply_in_ConvertGroup43Var3_static(AnalogCommandEvent* src);
Group43Var4 Apply_in_ConvertGroup43Var4_static(AnalogCommandEvent* src);
Group43Var5 Apply_in_ConvertGroup43Var5_static(AnalogCommandEvent* src);
//Group43Var6 Apply_in_ConvertGroup43Var6_static(AnalogCommandEvent* src);
Group43Var7 Apply_in_ConvertGroup43Var7_static(AnalogCommandEvent* src);
//Group43Var8 Apply_in_ConvertGroup43Var8_static(AnalogCommandEvent* src);

// ------- Group43Var1 -------

////Group43Var1::Group43Var1() : status(0), value(0)
////{}
void Group43Var1_in_Group43Var1(Group43Var1 *pGroup43Var1)
{
  pGroup43Var1->status = 0;
  pGroup43Var1->value = 0;
}

////bool Group43Var1::Read(rseq_t& buffer, Group43Var1& output)
////{
////  return LittleEndian::read(buffer, output.status, output.value);
////}
boolean Read_in_Group43Var1_static(RSeq_for_Uint16_t* buffer, Group43Var1* output)
{
////  return LittleEndian::read(buffer, output.status, output.value);
  return read_from_in_UInt8_static(buffer,  &(output->status)) &&
         read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value));
}

////bool Group43Var1::Write(const Group43Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.status, arg.value);
////}
boolean Write_in_Group43Var1_static(Group43Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.status, arg.value);
  return write_to_in_UInt8_static(buffer, arg->status) &&
         write_to_in_UInt32_static(buffer, arg->value);
}

////bool Group43Var1::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
////{
////  Group43Var1 value;
////  if(Read(buff, value))
////  {
////    output = AnalogCommandEventFactory::From(value.status, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group43Var1_static(RSeq_for_Uint16_t* buff, AnalogCommandEvent* output)
{
  Group43Var1 value;
//  if(Read(buff, value))
  Group43Var1_in_Group43Var1(&value);
  if(Read_in_Group43Var1_static(buff, &value))
  {
////    output = AnalogFactory::From(value.status, value.value);
    AnalogCommandEvent temp = From_in_AnalogCommandEventFactory_staticOver1(value.status, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group43Var1::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group43Var1::Write(ConvertGroup43Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group43Var1_static(AnalogCommandEvent* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertGroup43RangeCheck<Group43Var1> ConvertGroup43Var1;
  Group43Var1 temp = Apply_in_ConvertGroup43Var1_static(value);
  return Write_in_Group43Var1_static(&temp, buff);
}

Group43Var1 Apply_in_ConvertGroup43Var1_static(AnalogCommandEvent* src)
{
  Group43Var1 target;
  Group43Var1_in_Group43Var1(&target);
////        DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint32(src->value, (uint32_t*)&target.value);

////        t.status = CommandStatusSpec::to_type(src.status);
  target.status = src->status;
  return target;
}

////template<class Target> struct ConvertGroup43RangeCheck : private StaticOnly
////{
////    static Target Apply(const AnalogCommandEvent& src)
////    {
////        Target t;
////        DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
////        t.status = CommandStatusSpec::to_type(src.status);
////        return t;
////    }
////};

// ------- Group43Var2 -------

////Group43Var2::Group43Var2() : status(0), value(0)
////{}
void Group43Var2_in_Group43Var2(Group43Var2 *pGroup43Var2)
{
  pGroup43Var2->status = 0;
  pGroup43Var2->value = 0;
}

////bool Group43Var2::Read(rseq_t& buffer, Group43Var2& output)
////{
////  return LittleEndian::read(buffer, output.status, output.value);
////}
boolean Read_in_Group43Var2_static(RSeq_for_Uint16_t* buffer, Group43Var2* output)
{
////  return LittleEndian::read(buffer, output.status, output.value);
  return read_from_in_UInt8_static(buffer,  &(output->status)) &&
         read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value));
}

////bool Group43Var2::Write(const Group43Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.status, arg.value);
////}
boolean Write_in_Group43Var2_static(Group43Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.status, arg.value);
  return write_to_in_UInt8_static(buffer, arg->status) &&
         write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group43Var2::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
////{
////  Group43Var2 value;
////  if(Read(buff, value))
////  {
////    output = AnalogCommandEventFactory::From(value.status, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group43Var2_static(RSeq_for_Uint16_t* buff, AnalogCommandEvent* output)
{
  Group43Var2 value;
//  if(Read(buff, value))
  Group43Var2_in_Group43Var2(&value);
  if(Read_in_Group43Var2_static(buff, &value))
  {
////    output = AnalogFactory::From(value.status, value.value);
    AnalogCommandEvent temp = From_in_AnalogCommandEventFactory_staticOver1(value.status, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group43Var2::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group43Var2::Write(ConvertGroup43Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group43Var2_static(AnalogCommandEvent* value, WSeq_for_Uint16_t* buff)
{
////typedef ConvertGroup43RangeCheck<Group43Var2> ConvertGroup43Var2;
  Group43Var2 temp = Apply_in_ConvertGroup43Var2_static(value);
  return Write_in_Group43Var2_static(&temp, buff);
}

Group43Var2 Apply_in_ConvertGroup43Var2_static(AnalogCommandEvent* src)
{
  Group43Var2 target;
  Group43Var2_in_Group43Var2(&target);
////        DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint32(src->value, (uint32_t*)&target.value);

////        t.status = CommandStatusSpec::to_type(src.status);
  target.status = src->status;
  return target;
}

////template<class Target> struct ConvertGroup43RangeCheck : private StaticOnly
////{
////    static Target Apply(const AnalogCommandEvent& src)
////    {
////        Target t;
////        DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
////        t.status = CommandStatusSpec::to_type(src.status);
////        return t;
////    }
////};

// ------- Group43Var3 -------

////Group43Var3::Group43Var3() : status(0), value(0), time(0)
////{}
void Group43Var3_in_Group43Var3(Group43Var3 *pGroup43Var3)
{
  pGroup43Var3->status = 0;
  pGroup43Var3->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup43Var3->timeDNPTime), 0);
}

////bool Group43Var3::Read(rseq_t& buffer, Group43Var3& output)
////{
////  return LittleEndian::read(buffer, output.status, output.value, output.time);
////}
boolean Read_in_Group43Var3_static(RSeq_for_Uint16_t* buffer, Group43Var3* output)
{
  return read_from_in_UInt8_static(buffer, &(output->status)) &&
         read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group43Var3::Write(const Group43Var3& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.status, arg.value, arg.time);
////}
boolean Write_in_Group43Var3_static(Group43Var3* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt8_static(buffer, arg->status) &&
         write_to_in_UInt32_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group43Var3::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
////{
////  Group43Var3 value;
////  if(Read(buff, value))
////  {
////    output = AnalogCommandEventFactory::From(value.status, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group43Var3_static(RSeq_for_Uint16_t* buff, AnalogCommandEvent* output)
{
  Group43Var3 value;
//  if(Read(buff, value))
  Group43Var3_in_Group43Var3(&value);
  if(Read_in_Group43Var3_static(buff, &value))
  {
    AnalogCommandEvent temp = From_in_AnalogCommandEventFactory_staticOver2(value.status, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group43Var3::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group43Var3::Write(ConvertGroup43Var3::Apply(value), buff);
////}

boolean WriteTarget_in_Group43Var3_static(AnalogCommandEvent* value, WSeq_for_Uint16_t* buff)
{
////typedef ConvertGroup43WithTimeRangeCheck<Group43Var3> ConvertGroup43Var3;
  Group43Var3 temp = Apply_in_ConvertGroup43Var3_static(value);
  return Write_in_Group43Var3_static(&temp, buff);
}

Group43Var3 Apply_in_ConvertGroup43Var3_static(AnalogCommandEvent* src)
{
  Group43Var3 target;
  Group43Var3_in_Group43Var3(&target);
////    DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint32(src->value, (uint32_t*)&target.value);

////    t.status = CommandStatusSpec::to_type(src.status);
  target.status = src->status;
////    t.time = src.time;
  target.timeDNPTime = src->timeDNPTime;
  return target;
}

////template<class Target> struct ConvertGroup43WithTimeRangeCheck : private StaticOnly
////{
////  static Target Apply(const AnalogCommandEvent& src)
////  {
////    Target t;
////    DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
////    t.status = CommandStatusSpec::to_type(src.status);
////    t.time = src.time;
////    return t;
////  }
////};

// ------- Group43Var4 -------

////Group43Var4::Group43Var4() : status(0), value(0), time(0)
////{}
void Group43Var4_in_Group43Var4(Group43Var4 *pGroup43Var4)
{
  pGroup43Var4->status = 0;
  pGroup43Var4->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup43Var4->timeDNPTime), 0);
}

////bool Group43Var4::Read(rseq_t& buffer, Group43Var4& output)
////{
////  return LittleEndian::read(buffer, output.status, output.value, output.time);
////}
boolean Read_in_Group43Var4_static(RSeq_for_Uint16_t* buffer, Group43Var4* output)
{
  return read_from_in_UInt8_static(buffer, &(output->status)) &&
         read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group43Var4::Write(const Group43Var4& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.status, arg.value, arg.time);
////}
boolean Write_in_Group43Var4_static(Group43Var4* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt8_static(buffer, arg->status) &&
         write_to_in_UInt16_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group43Var4::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
////{
////  Group43Var4 value;
////  if(Read(buff, value))
////  {
////    output = AnalogCommandEventFactory::From(value.status, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group43Var4_static(RSeq_for_Uint16_t* buff, AnalogCommandEvent* output)
{
  Group43Var4 value;
//  if(Read(buff, value))
  Group43Var4_in_Group43Var4(&value);
  if(Read_in_Group43Var4_static(buff, &value))
  {
    AnalogCommandEvent temp = From_in_AnalogCommandEventFactory_staticOver2(value.status, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group43Var4::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group43Var4::Write(ConvertGroup43Var4::Apply(value), buff);
////}
////typedef ConvertGroup43WithTimeRangeCheck<Group43Var4> ConvertGroup43Var4;
boolean WriteTarget_in_Group43Var4_static(AnalogCommandEvent* value, WSeq_for_Uint16_t* buff)
{
////typedef ConvertGroup43WithTimeRangeCheck<Group43Var4> ConvertGroup43Var4;
  Group43Var4 temp = Apply_in_ConvertGroup43Var4_static(value);
  return Write_in_Group43Var4_static(&temp, buff);
}

Group43Var4 Apply_in_ConvertGroup43Var4_static(AnalogCommandEvent* src)
{
  Group43Var4 target;
  Group43Var4_in_Group43Var4(&target);
////    DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint32(src->value, (uint32_t*)&target.value);

////    t.status = CommandStatusSpec::to_type(src.status);
  target.status = src->status;
////    t.time = src.time;
  target.timeDNPTime = src->timeDNPTime;
  return target;
}

////template<class Target> struct ConvertGroup43WithTimeRangeCheck : private StaticOnly
////{
////  static Target Apply(const AnalogCommandEvent& src)
////  {
////    Target t;
////    DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
////    t.status = CommandStatusSpec::to_type(src.status);
////    t.time = src.time;
////    return t;
////  }
////};

// ------- Group43Var5 -------

////Group43Var5::Group43Var5() : status(0), value(0.0)
////{}
void Group43Var5_in_Group43Var5(Group43Var5 *pGroup43Var5)
{
  pGroup43Var5->status = 0;
  pGroup43Var5->value = 0.0;
}

////bool Group43Var5::Read(rseq_t& buffer, Group43Var5& output)
////{
////  return LittleEndian::read(buffer, output.status, output.value);
////}
boolean Read_in_Group43Var5_static(RSeq_for_Uint16_t* buffer, Group43Var5* output)
{
////  return LittleEndian::read(buffer, output.status, output.value);
  return read_from_in_UInt8_static(buffer, &(output->status)) &&
         read_from_in_Float32_static(buffer, &(output->value));
}

////bool Group43Var5::Write(const Group43Var5& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.status, arg.value);
////}
boolean Write_in_Group43Var5_static(Group43Var5* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.status, arg.value);
  return write_to_in_UInt8_static(buffer, arg->status) &&
         write_to_in_Float32_static(buffer, arg->value);
}

////bool Group43Var5::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
////{
////  Group43Var5 value;
////  if(Read(buff, value))
////  {
////    output = AnalogCommandEventFactory::From(value.status, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group43Var5_static(RSeq_for_Uint16_t* buff, AnalogCommandEvent* output)
{
  Group43Var5 value;
  Group43Var5_in_Group43Var5(&value);
////  if(Read(buff, value))
  if(Read_in_Group43Var5_static(buff, &value))
  {
////    output = AnalogFactory::From(value.status, value.value);
    AnalogCommandEvent temp = From_in_AnalogCommandEventFactory_staticOver1(value.status, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group43Var5::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group43Var5::Write(ConvertGroup43Var5::Apply(value), buff);
////}
////typedef ConvertGroup43RangeCheck<Group43Var5> ConvertGroup43Var5;
boolean WriteTarget_in_Group43Var5_static(AnalogCommandEvent* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertGroup43RangeCheck<Group43Var1> ConvertGroup43Var1;
  Group43Var5 temp = Apply_in_ConvertGroup43Var5_static(value);
  return Write_in_Group43Var5_static(&temp, buff);
}

Group43Var5 Apply_in_ConvertGroup43Var5_static(AnalogCommandEvent* src)
{
  Group43Var5 target;
  Group43Var5_in_Group43Var5(&target);
////        DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint32(src->value, (uint32_t*)&target.value);

////    t.status = CommandStatusSpec::to_type(src.status);
  target.status = src->status;
  return target;
}

////template<class Target> struct ConvertGroup43RangeCheck : private StaticOnly
////{
////    static Target Apply(const AnalogCommandEvent& src)
////    {
////        Target t;
////        DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
////        t.status = CommandStatusSpec::to_type(src.status);
////        return t;
////    }
////};

// ------- Group43Var6 -------
/*
Group43Var6::Group43Var6() : status(0), value(0.0)
{}

bool Group43Var6::Read(rseq_t& buffer, Group43Var6& output)
{
  return LittleEndian::read(buffer, output.status, output.value);
}

bool Group43Var6::Write(const Group43Var6& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.status, arg.value);
}

bool Group43Var6::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
{
  Group43Var6 value;
  if(Read(buff, value))
  {
    output = AnalogCommandEventFactory::From(value.status, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group43Var6::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
{
  return Group43Var6::Write(ConvertGroup43Var6::Apply(value), buff);
}
*/
// ------- Group43Var7 -------

////Group43Var7::Group43Var7() : status(0), value(0.0), time(0)
////{}
void Group43Var7_in_Group43Var7(Group43Var7 *pGroup43Var7)
{
  pGroup43Var7->status = 0;
  pGroup43Var7->value = 0.0;
  DNPTime_in_DNPTimeOver2(&(pGroup43Var7->timeDNPTime), 0);
}

////bool Group43Var7::Read(rseq_t& buffer, Group43Var7& output)
////{
////  return LittleEndian::read(buffer, output.status, output.value, output.time);
////}
boolean Read_in_Group43Var7_static(RSeq_for_Uint16_t* buffer, Group43Var7* output)
{
////  return LittleEndian::read(buffer, output.status, output.value);
  return read_from_in_UInt8_static(buffer, &(output->status)) &&
         read_from_in_Float32_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group43Var7::Write(const Group43Var7& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.status, arg.value, arg.time);
////}
boolean Write_in_Group43Var7_static(Group43Var7* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.status, arg.value);
  return write_to_in_UInt8_static(buffer, arg->status) &&
         write_to_in_Float32_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group43Var7::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
////{
////  Group43Var7 value;
////  if(Read(buff, value))
////  {
////    output = AnalogCommandEventFactory::From(value.status, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group43Var7_static(RSeq_for_Uint16_t* buff, AnalogCommandEvent* output)
{
  Group43Var7 value;
//  if(Read(buff, value))
  Group43Var7_in_Group43Var7(&value);
  if(Read_in_Group43Var7_static(buff, &value))
  {
    AnalogCommandEvent temp = From_in_AnalogCommandEventFactory_staticOver2(value.status, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group43Var7::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group43Var7::Write(ConvertGroup43Var7::Apply(value), buff);
////}
////typedef ConvertGroup43WithTimeRangeCheck<Group43Var7> ConvertGroup43Var7;
boolean WriteTarget_in_Group43Var7_static(AnalogCommandEvent* value, WSeq_for_Uint16_t* buff)
{
////typedef ConvertGroup43WithTimeRangeCheck<Group43Var3> ConvertGroup43Var3;
  Group43Var7 temp = Apply_in_ConvertGroup43Var7_static(value);
  return Write_in_Group43Var7_static(&temp, buff);
}

Group43Var7 Apply_in_ConvertGroup43Var7_static(AnalogCommandEvent* src)
{
  Group43Var7 target;
  Group43Var7_in_Group43Var7(&target);
////    DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint32(src->value, (uint32_t*)&target.value);

////    t.status = CommandStatusSpec::to_type(src.status);
  target.status = src->status;
////    t.time = src.time;
  target.timeDNPTime = src->timeDNPTime;
  return target;
}

////template<class Target> struct ConvertGroup43WithTimeRangeCheck : private StaticOnly
////{
////  static Target Apply(const AnalogCommandEvent& src)
////  {
////    Target t;
////    DownSampling<double, typename Target::ValueType>::Apply(src.value, t.value);
////    t.status = CommandStatusSpec::to_type(src.status);
////    t.time = src.time;
////    return t;
////  }
////};

// ------- Group43Var8 -------
/*
Group43Var8::Group43Var8() : status(0), value(0.0), time(0)
{}

bool Group43Var8::Read(rseq_t& buffer, Group43Var8& output)
{
  return LittleEndian::read(buffer, output.status, output.value, output.time);
}

bool Group43Var8::Write(const Group43Var8& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.status, arg.value, arg.time);
}

bool Group43Var8::ReadTarget(rseq_t& buff, AnalogCommandEvent& output)
{
  Group43Var8 value;
  if(Read(buff, value))
  {
    output = AnalogCommandEventFactory::From(value.status, value.value, value.time);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group43Var8::WriteTarget(const AnalogCommandEvent& value, ser4cpp::wseq_t& buff)
{
  return Group43Var8::Write(ConvertGroup43Var8::Apply(value), buff);
}
*/

////}
uint16_t Size_in_Group43Var1_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group43Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 1);
////  return GroupVariationID(43,1);
  return gGroupVariationID;
}

uint16_t Size_in_Group43Var2_static(void)
{
  return 3;
}

GroupVariationID ID_in_Group43Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 2);
////  return GroupVariationID(43,2);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var2_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var2_static(),
      Size_in_Group43Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

uint16_t Size_in_Group43Var3_static(void)
{
  return 11;
}

GroupVariationID ID_in_Group43Var3_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 3);
////  return GroupVariationID(43,3);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var3_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var3_static(),
      Size_in_Group43Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

uint16_t Size_in_Group43Var4_static(void)
{
  return 9;
}

GroupVariationID ID_in_Group43Var4_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 4);
////  return GroupVariationID(43,4);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var4_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var4_static(),
      Size_in_Group43Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var4_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

uint16_t Size_in_Group43Var5_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group43Var5_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 5);
////  return GroupVariationID(43,5);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var5_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var5_static(),
      Size_in_Group43Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}

uint16_t Size_in_Group43Var7_static(void)
{
  return 11;
}

GroupVariationID ID_in_Group43Var7_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 43, 7);
////  return GroupVariationID(43,7);
  return gGroupVariationID;
}

DNP3Serializer_for_AnalogCommandEvent  Inst_in_Group43Var7_static(void)
{
  DNP3Serializer_for_AnalogCommandEvent dDNP3Serializer_for_AnalogCommandEvent;
  DNP3Serializer_for_AnalogCommandEvent_in_DNP3Serializer_for_AnalogCommandEvent(&dDNP3Serializer_for_AnalogCommandEvent,
      ID_in_Group43Var7_static(),
      Size_in_Group43Var7_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group43Var7_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group43Var7_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_AnalogCommandEvent;
}
