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
#include "Group42.h"

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

Group42Var1 Apply_in_ConvertGroup42Var1_static(AnalogOutputStatus* src, uint8_t Overrange);
Group42Var2 Apply_in_ConvertGroup42Var2_static(AnalogOutputStatus* src, uint8_t Overrange);
Group42Var3 Apply_in_ConvertGroup42Var3_static(AnalogOutputStatus* src, uint8_t Overrange);
Group42Var4 Apply_in_ConvertGroup42Var4_static(AnalogOutputStatus* src, uint8_t Overrange);
Group42Var5 Apply_in_ConvertGroup42Var5_static(AnalogOutputStatus* src, uint8_t Overrange);
//Group42Var6 Apply_in_ConvertGroup42Var6_static(AnalogOutputStatus* src);
Group42Var7 Apply_in_ConvertGroup42Var7_static(AnalogOutputStatus* src, uint8_t Overrange);
//Group42Var8 Apply_in_ConvertGroup42Var8_static(AnalogOutputStatus* src);

// ------- Group42Var1 -------

////Group42Var1::Group42Var1() : flags(0), value(0)
////{}
void Group42Var1_in_Group42Var1(Group42Var1 *pGroup42Var1)
{
  pGroup42Var1->flags = 0;
  pGroup42Var1->value = 0;
}

////bool Group42Var1::Read(rseq_t& buffer, Group42Var1& output)
///{
///  return LittleEndian::read(buffer, output.flags, output.value);
///}
boolean Read_in_Group42Var1_static(RSeq_for_Uint16_t* buffer, Group42Var1* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer,  &(output->flags)) &&
           read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value));
}

////bool Group42Var1::Write(const Group42Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group42Var1_static(Group42Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt32_static(buffer, arg->value);
}

////bool Group42Var1::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group42Var1 value;
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
boolean ReadTarget_in_Group42Var1_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group42Var1 value;
//  if(Read(buff, value))
  Group42Var1_in_Group42Var1(&value);
  if(Read_in_Group42Var1_static(buff, &value))
  {
////    output = AnalogFactory::From(value.flags, value.value);
   AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver1(value.flags, value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group42Var1::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group42Var1::Write(ConvertGroup42Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group42Var1_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVRangeCheck<Group42Var1, AnalogOutputStatus, 0x20> ConvertGroup42Var1;
  Group42Var1 temp = Apply_in_ConvertGroup42Var1_static(value, 0x20);
  return Write_in_Group42Var1_static(&temp, buff);
}

Group42Var1 Apply_in_ConvertGroup42Var1_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group42Var1 target;
  Group42Var1_in_Group42Var1(&target);
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


// ------- Group42Var2 -------

////Group42Var2::Group42Var2() : flags(0), value(0)
////{}
void Group42Var2_in_Group42Var2(Group42Var2 *pGroup42Var2)
{
  pGroup42Var2->flags = 0;
  pGroup42Var2->value = 0;
}

////bool Group42Var2::Read(rseq_t& buffer, Group42Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group42Var2_static(RSeq_for_Uint16_t* buffer, Group42Var2* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer,  &(output->flags)) &&
           read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value));
}

////bool Group42Var2::Write(const Group42Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group42Var2_static(Group42Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group42Var2::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group42Var2 value;
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
boolean ReadTarget_in_Group42Var2_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group42Var2 value;
//  if(Read(buff, value))
  Group42Var2_in_Group42Var2(&value);
  if(Read_in_Group42Var2_static(buff, &value))
  {
////    output = AnalogFactory::From(value.flags, value.value);
   AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver1(value.flags, value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group42Var2::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group42Var2::Write(ConvertGroup42Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group42Var2_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVRangeCheck<Group42Var2, Analog, 0x20> ConvertGroup32Var2;
  Group42Var2 temp = Apply_in_ConvertGroup42Var2_static(value, 0x20);
  return Write_in_Group42Var2_static(&temp, buff);
}

Group42Var2 Apply_in_ConvertGroup42Var2_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group42Var2 target;
  Group42Var2_in_Group42Var2(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint16((src->tTypedMeasurement_for_Double64).value, (uint16_t*)&target.value);

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

// ------- Group42Var3 -------

////Group42Var3::Group42Var3() : flags(0), value(0), time(0)
////{}
void Group42Var3_in_Group42Var3(Group42Var3 *pGroup42Var3)
{
 pGroup42Var3->flags = 0;
 pGroup42Var3->value = 0;
 DNPTime_in_DNPTimeOver2(&(pGroup42Var3->timeDNPTime), 0);
}

////bool Group42Var3::Read(rseq_t& buffer, Group42Var3& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group42Var3_static(RSeq_for_Uint16_t* buffer, Group42Var3* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group42Var3::Write(const Group42Var3& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group42Var3_static(Group42Var3* arg, WSeq_for_Uint16_t* buffer)
{
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt32_static(buffer, arg->value) &&
           write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group42Var3::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group42Var3 value;
////  if(Read(buff, value))
////  {
////    output = AnalogOutputStatusFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group42Var3_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group42Var3 value;
//  if(Read(buff, value))
  Group42Var3_in_Group42Var3(&value);
  if(Read_in_Group42Var3_static(buff, &value))
  {
   AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver2(value.flags, value.value, value.timeDNPTime);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group42Var3::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group42Var3::Write(ConvertGroup42Var3::Apply(value), buff);
////}
boolean WriteTarget_in_Group42Var3_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTRangeCheck<Group42Var3, AnalogOutputStatus, 0x20> ConvertGroup42Var3;
  Group42Var3 temp = Apply_in_ConvertGroup42Var3_static(value, 0x20);
  return Write_in_Group42Var3_static(&temp, buff);
}

Group42Var3 Apply_in_ConvertGroup42Var3_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group42Var3 target;
  Group42Var3_in_Group42Var3(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint32((src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
////        t.time = src.time;
  target.timeDNPTime = (src->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime;
  return target;
}
////template<class Target, class Source, uint8_t Overrange> struct ConvertQVTRangeCheck : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
////        t.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
////        t.time = src.time;
////        return t;
////    }
////};

// ------- Group42Var4 -------

////Group42Var4::Group42Var4() : flags(0), value(0), time(0)
////{}
void Group42Var4_in_Group42Var4(Group42Var4 *pGroup42Var4)
{
 pGroup42Var4->flags = 0;
 pGroup42Var4->value = 0;
 DNPTime_in_DNPTimeOver2(&(pGroup42Var4->timeDNPTime), 0);
}

////bool Group42Var4::Read(rseq_t& buffer, Group42Var4& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group42Var4_static(RSeq_for_Uint16_t* buffer, Group42Var4* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group42Var4::Write(const Group42Var4& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group42Var4_static(Group42Var4* arg, WSeq_for_Uint16_t* buffer)
{
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt16_static(buffer, arg->value) &&
           write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group42Var4::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group42Var4 value;
////  if(Read(buff, value))
////  {
////    output = AnalogOutputStatusFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group42Var4_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group42Var4 value;
//  if(Read(buff, value))
  Group42Var4_in_Group42Var4(&value);
  if(Read_in_Group42Var4_static(buff, &value))
  {
   AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver2(value.flags, value.value, value.timeDNPTime);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group42Var4::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group42Var4::Write(ConvertGroup42Var4::Apply(value), buff);
////}
boolean WriteTarget_in_Group42Var4_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTRangeCheck<Group42Var4, Analog, 0x20> ConvertGroup32Var3;
  Group42Var4 temp = Apply_in_ConvertGroup42Var4_static(value, 0x20);
  return Write_in_Group42Var4_static(&temp, buff);
}

Group42Var4 Apply_in_ConvertGroup42Var4_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group42Var4 target;
  Group42Var4_in_Group42Var4(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint32((src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
////        t.time = src.time;
  target.timeDNPTime = (src->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime;
  return target;
}
////template<class Target, class Source, uint8_t Overrange> struct ConvertQVTRangeCheck : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
////        t.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
////        t.time = src.time;
////        return t;
////    }
////};

// ------- Group42Var5 -------

////Group42Var5::Group42Var5() : flags(0), value(0.0)
////{}
void Group42Var5_in_Group42Var5(Group42Var5 *pGroup42Var5)
{
  pGroup42Var5->flags = 0;
  pGroup42Var5->value = 0.0;
}

////bool Group42Var5::Read(rseq_t& buffer, Group42Var5& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group42Var5_static(RSeq_for_Uint16_t* buffer, Group42Var5* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_Float32_static(buffer, &(output->value));
}

////bool Group42Var5::Write(const Group42Var5& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group42Var5_static(Group42Var5* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_Float32_static(buffer, arg->value);
}

////bool Group42Var5::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group42Var5 value;
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
boolean ReadTarget_in_Group42Var5_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group42Var5 value;
  Group42Var5_in_Group42Var5(&value);
////  if(Read(buff, value))
  if(Read_in_Group42Var5_static(buff, &value))
  {
////    output = AnalogFactory::From(value.flags, value.value);
   AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver1(value.flags, value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group42Var5::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group42Var5::Write(ConvertGroup42Var5::Apply(value), buff);
////}
boolean WriteTarget_in_Group42Var5_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
////typedef ConvertQVRangeCheck<Group30Var5, Analog, 0x20> ConvertGroup30Var5;
  Group42Var5 temp = Apply_in_ConvertGroup42Var5_static(value, 0x20);
  return Write_in_Group42Var5_static(&temp, buff);
}

Group42Var5 Apply_in_ConvertGroup42Var5_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group42Var5 target;
  Group42Var5_in_Group42Var5(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_Float32((src->tTypedMeasurement_for_Double64).value, &target.value);

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


// ------- Group42Var6 -------
/*
Group42Var6::Group42Var6() : flags(0), value(0.0)
{}

bool Group42Var6::Read(rseq_t& buffer, Group42Var6& output)
{
  return LittleEndian::read(buffer, output.flags, output.value);
}

bool Group42Var6::Write(const Group42Var6& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value);
}

bool Group42Var6::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var6 value;
  if(Read(buff, value))
  {
    output = AnalogOutputStatusFactory::From(value.flags, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group42Var6::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var6::Write(ConvertGroup42Var6::Apply(value), buff);
}
*/
// ------- Group42Var7 -------

////Group42Var7::Group42Var7() : flags(0), value(0.0), time(0)
////{}
void Group42Var7_in_Group42Var7(Group42Var7 *pGroup42Var7)
{
 pGroup42Var7->flags = 0;
 pGroup42Var7->value = 0.0;
 DNPTime_in_DNPTimeOver2(&(pGroup42Var7->timeDNPTime), 0);
}

////bool Group42Var7::Read(rseq_t& buffer, Group42Var7& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group42Var7_static(RSeq_for_Uint16_t* buffer, Group42Var7* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_Float32_static(buffer, &(output->value)) &&
           read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group42Var7::Write(const Group42Var7& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group42Var7_static(Group42Var7* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_Float32_static(buffer, arg->value) &&
           write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group42Var7::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
////{
////  Group42Var7 value;
////  if(Read(buff, value))
////  {
////    output = AnalogOutputStatusFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group42Var7_static(RSeq_for_Uint16_t* buff, AnalogOutputStatus* output)
{
  Group42Var7 value;
//  if(Read(buff, value))
  Group42Var7_in_Group42Var7(&value);
  if(Read_in_Group42Var7_static(buff, &value))
  {
   AnalogOutputStatus temp = From_in_AnalogOutputStatusFactory_staticOver2(value.flags, value.value, value.timeDNPTime);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group42Var7::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
////{
////  return Group42Var7::Write(ConvertGroup42Var7::Apply(value), buff);
////}
boolean WriteTarget_in_Group42Var7_static(AnalogOutputStatus* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTRangeCheck<Group32Var3, Analog, 0x20> ConvertGroup32Var3;
  Group42Var7 temp = Apply_in_ConvertGroup42Var7_static(value, 0x20);
  return Write_in_Group42Var7_static(&temp, buff);
}

Group42Var7 Apply_in_ConvertGroup42Var7_static(AnalogOutputStatus* src, uint8_t Overrange)
{
  Group42Var7 target;
  Group42Var7_in_Group42Var7(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint32((src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
////        t.time = src.time;
  target.timeDNPTime = (src->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime;
  return target;
}
////template<class Target, class Source, uint8_t Overrange> struct ConvertQVTRangeCheck : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
////        t.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
////        t.time = src.time;
////        return t;
////    }
////};

// ------- Group42Var8 -------
/*
Group42Var8::Group42Var8() : flags(0), value(0.0), time(0)
{}

bool Group42Var8::Read(rseq_t& buffer, Group42Var8& output)
{
  return LittleEndian::read(buffer, output.flags, output.value, output.time);
}

bool Group42Var8::Write(const Group42Var8& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
}

bool Group42Var8::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var8 value;
  if(Read(buff, value))
  {
    output = AnalogOutputStatusFactory::From(value.flags, value.value, value.time);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group42Var8::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var8::Write(ConvertGroup42Var8::Apply(value), buff);
}

*/
////}
  GroupVariationID ID_in_Group42Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 0);
//// return GroupVariationID(42,0);
 return gGroupVariationID;
}

 uint16_t Size_in_Group42Var1_static(void) 
{
 return 5; 
}

  GroupVariationID ID_in_Group42Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 1);
////  return GroupVariationID(42,1); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var1_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var1_static(),
                   Size_in_Group42Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}

 uint16_t Size_in_Group42Var2_static(void) 
{
 return 3; 
}

  GroupVariationID ID_in_Group42Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 2);
////  return GroupVariationID(42,2); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var2_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var2_static(),
                   Size_in_Group42Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}

 uint16_t Size_in_Group42Var3_static(void) 
{
 return 11; 
}

  GroupVariationID ID_in_Group42Var3_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 3);
////  return GroupVariationID(42,3); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var3_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var3_static(),
                   Size_in_Group42Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}

 uint16_t Size_in_Group42Var4_static(void) 
{
 return 9; 
}

  GroupVariationID ID_in_Group42Var4_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 4);
////  return GroupVariationID(42,4); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var4_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var4_static(),
                   Size_in_Group42Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var4_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}

 uint16_t Size_in_Group42Var5_static(void) 
{
 return 5; 
}

  GroupVariationID ID_in_Group42Var5_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 5);
////  return GroupVariationID(42,5); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var5_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var5_static(),
                   Size_in_Group42Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}
/*
 uint16_t Size_in_Group42Var6_static(void) 
{
 return 9; 
}

  GroupVariationID ID_in_Group42Var6_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 6);
////  return GroupVariationID(42,6); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var6_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var6_static(),
                   Size_in_Group42Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}
*/
 uint16_t Size_in_Group42Var7_static(void) 
{
 return 1; 
}

  GroupVariationID ID_in_Group42Var7_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 7);
////  return GroupVariationID(42,7); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var7_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var7_static(),
                   Size_in_Group42Var7_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var7_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var7_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}

 uint16_t Size_in_Group42Var8_static(void) 
{
 return 15; 
}
/*
  GroupVariationID ID_in_Group42Var8_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 42, 8);
////  return GroupVariationID(42,8); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputStatus  Inst_in_Group42Var8_static(void)
{
   DNP3Serializer_for_AnalogOutputStatus dDNP3Serializer_for_AnalogOutputStatus;
   DNP3Serializer_for_AnalogOutputStatus_in_DNP3Serializer_for_AnalogOutputStatus(&dDNP3Serializer_for_AnalogOutputStatus,
                   ID_in_Group42Var8_static(),
                   Size_in_Group42Var8_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group42Var8_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group42Var8_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputStatus;
}
*/
