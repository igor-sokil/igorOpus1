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
#include "Group32.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"

//#include "DNPTimeParsing.h"
//#include <ser4cpp/serialization/LittleEndian.h>
#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"
#include "DownSampling.h"

//#include "RSeq.h"
//#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {
Group32Var1 Apply_in_ConvertGroup32Var1_static(Analog* src, uint8_t Overrange);
Group32Var2 Apply_in_ConvertGroup32Var2_static(Analog* src, uint8_t Overrange);
Group32Var3 Apply_in_ConvertGroup32Var3_static(Analog* src, uint8_t Overrange);
Group32Var4 Apply_in_ConvertGroup32Var4_static(Analog* src, uint8_t Overrange);
Group32Var5 Apply_in_ConvertGroup32Var5_static(Analog* src, uint8_t Overrange);
//Group32Var6 Apply_in_ConvertGroup32Var6_static(Analog* src);
Group32Var7 Apply_in_ConvertGroup32Var7_static(Analog* src, uint8_t Overrange);
//Group32Var8 Apply_in_ConvertGroup32Var8_static(Analog* src);

GroupVariationID ID_in_Group32Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 0);
//// return GroupVariationID(32,0);
  return gGroupVariationID;
}

// ------- Group32Var1 -------

void Group32Var1_in_Group32Var1(Group32Var1 *pGroup32Var1)
{
  pGroup32Var1->flags = 0;
  pGroup32Var1->value = 0;
}

boolean Read_in_Group32Var1_static(RSeq_for_Uint16_t* buffer, Group32Var1* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer,  &(output->flags)) &&
         read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value));
}

boolean Write_in_Group32Var1_static(Group32Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value);
}

boolean ReadTarget_in_Group32Var1_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var1 value;
//  if(Read(buff, value))
  Group32Var1_in_Group32Var1(&value);
  if(Read_in_Group32Var1_static(buff, &value))
  {
////    output = AnalogFactory::From(value.flags, value.value);
    Analog temp = From_in_AnalogFactory_staticOver2(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group32Var1_static(Analog* value, WSeq_for_Uint16_t* buff)
{
////  return Group32Var1::Write(ConvertGroup32Var1::Apply(value), buff);
//typedef ConvertQVRangeCheck<Group32Var1, Analog, 0x20> ConvertGroup32Var1;
  Group32Var1 temp = Apply_in_ConvertGroup32Var1_static(value, 0x20);
  return Write_in_Group32Var1_static(&temp, buff);
}

Group32Var1 Apply_in_ConvertGroup32Var1_static(Analog* src, uint8_t Overrange)
{
  Group32Var1 target;
  Group32Var1_in_Group32Var1(&target);
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

// ------- Group32Var2 -------

////Group32Var2::Group32Var2() : flags(0), value(0)
////{}
void Group32Var2_in_Group32Var2(Group32Var2 *pGroup32Var2)
{
  pGroup32Var2->flags = 0;
  pGroup32Var2->value = 0;
}

////bool Group32Var2::Read(rseq_t& buffer, Group32Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group32Var2_static(RSeq_for_Uint16_t* buffer, Group32Var2* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer,  &(output->flags)) &&
         read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value));
}

////bool Group32Var2::Write(const Group32Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group32Var2_static(Group32Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group32Var2::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group32Var2 value;
////  if(Read(buff, value))
////  {
////    output = AnalogFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group32Var2_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var2 value;
//  if(Read(buff, value))
  Group32Var2_in_Group32Var2(&value);
  if(Read_in_Group32Var2_static(buff, &value))
  {
////    output = AnalogFactory::From(value.flags, value.value);
    Analog temp = From_in_AnalogFactory_staticOver2(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group32Var2::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var2::Write(ConvertGroup32Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group32Var2_static(Analog* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVRangeCheck<Group32Var2, Analog, 0x20> ConvertGroup32Var2;
  Group32Var2 temp = Apply_in_ConvertGroup32Var2_static(value, 0x20);
  return Write_in_Group32Var2_static(&temp, buff);
}

Group32Var2 Apply_in_ConvertGroup32Var2_static(Analog* src, uint8_t Overrange)
{
  Group32Var2 target;
  Group32Var2_in_Group32Var2(&target);
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

// ------- Group32Var3 -------
////
////Group32Var3::Group32Var3() : flags(0), value(0), time(0)
////{}
void Group32Var3_in_Group32Var3(Group32Var3 *pGroup32Var3)
{
  pGroup32Var3->flags = 0;
  pGroup32Var3->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup32Var3->timeDNPTime), 0);
}

////bool Group32Var3::Read(rseq_t& buffer, Group32Var3& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group32Var3_static(RSeq_for_Uint16_t* buffer, Group32Var3* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group32Var3::Write(const Group32Var3& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group32Var3_static(Group32Var3* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group32Var3::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group32Var3 value;
////  if(Read(buff, value))
////  {
////    output = AnalogFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group32Var3_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var3 value;
//  if(Read(buff, value))
  Group32Var3_in_Group32Var3(&value);
  if(Read_in_Group32Var3_static(buff, &value))
  {
    Analog temp = From_in_AnalogFactory_staticOver3(value.flags, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group32Var3::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var3::Write(ConvertGroup32Var3::Apply(value), buff);
////}
boolean WriteTarget_in_Group32Var3_static(Analog* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTRangeCheck<Group32Var3, Analog, 0x20> ConvertGroup32Var3;
  Group32Var3 temp = Apply_in_ConvertGroup32Var3_static(value, 0x20);
  return Write_in_Group32Var3_static(&temp, buff);
}

Group32Var3 Apply_in_ConvertGroup32Var3_static(Analog* src, uint8_t Overrange)
{
  Group32Var3 target;
  Group32Var3_in_Group32Var3(&target);
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

// ------- Group32Var4 -------
////
////Group32Var4::Group32Var4() : flags(0), value(0), time(0)
////{}
void Group32Var4_in_Group32Var4(Group32Var4 *pGroup32Var4)
{
  pGroup32Var4->flags = 0;
  pGroup32Var4->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup32Var4->timeDNPTime), 0);
}

////bool Group32Var4::Read(rseq_t& buffer, Group32Var4& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group32Var4_static(RSeq_for_Uint16_t* buffer, Group32Var4* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group32Var4::Write(const Group32Var4& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group32Var4_static(Group32Var4* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group32Var4::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group32Var4 value;
////  if(Read(buff, value))
////  {
////    output = AnalogFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group32Var4_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var4 value;
//  if(Read(buff, value))
  Group32Var4_in_Group32Var4(&value);
  if(Read_in_Group32Var4_static(buff, &value))
  {
    Analog temp = From_in_AnalogFactory_staticOver3(value.flags, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group32Var4::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var4::Write(ConvertGroup32Var4::Apply(value), buff);
////}
boolean WriteTarget_in_Group32Var4_static(Analog* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTRangeCheck<Group32Var4, Analog, 0x20> ConvertGroup32Var3;
  Group32Var4 temp = Apply_in_ConvertGroup32Var4_static(value, 0x20);
  return Write_in_Group32Var4_static(&temp, buff);
}

Group32Var4 Apply_in_ConvertGroup32Var4_static(Analog* src, uint8_t Overrange)
{
  Group32Var4 target;
  Group32Var4_in_Group32Var4(&target);
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

////// ------- Group32Var5 -------

////Group32Var5::Group32Var5() : flags(0), value(0.0)
////{}
void Group32Var5_in_Group32Var5(Group32Var5 *pGroup32Var5)
{
  pGroup32Var5->flags = 0;
  pGroup32Var5->value = 0.0;
}

////bool Group32Var5::Read(rseq_t& buffer, Group32Var5& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group32Var5_static(RSeq_for_Uint16_t* buffer, Group32Var5* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_Float32_static(buffer, &(output->value));
}

////bool Group32Var5::Write(const Group32Var5& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group32Var5_static(Group32Var5* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_Float32_static(buffer, arg->value);
}

////bool Group32Var5::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group32Var5 value;
////  if(Read(buff, value))
////  {
////    output = AnalogFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group32Var5_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var5 value;
  Group32Var5_in_Group32Var5(&value);
////  if(Read(buff, value))
  if(Read_in_Group32Var5_static(buff, &value))
  {
////    output = AnalogFactory::From(value.flags, value.value);
    Analog temp = From_in_AnalogFactory_staticOver2(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group32Var5::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var5::Write(ConvertGroup32Var5::Apply(value), buff);
////}
boolean WriteTarget_in_Group32Var5_static(Analog* value, WSeq_for_Uint16_t* buff)
{
////typedef ConvertQVRangeCheck<Group30Var5, Analog, 0x20> ConvertGroup30Var5;
  Group32Var5 temp = Apply_in_ConvertGroup32Var5_static(value, 0x20);
  return Write_in_Group32Var5_static(&temp, buff);
}

Group32Var5 Apply_in_ConvertGroup32Var5_static(Analog* src, uint8_t Overrange)
{
  Group32Var5 target;
  Group32Var5_in_Group32Var5(&target);
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

// ------- Group32Var6 -------
/*
////Group32Var6::Group32Var6() : flags(0), value(0.0)
////{}
void Group32Var6_in_Group32Var6(Group32Var6 *pGroup32Var6)
{
  pGroup32Var6->flags = 0;
  pGroup32Var6->value = 0.0;
}

////bool Group32Var6::Read(rseq_t& buffer, Group32Var6& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group32Var6_static(RSeq_for_Uint16_t* buffer, Group32Var6* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_Double64_static(buffer, &(output->value));
}

////bool Group32Var6::Write(const Group32Var6& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group32Var6_static(Group32Var6* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_Double64_static(buffer, arg->value);
}

////bool Group32Var6::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group32Var6 value;
////  if(Read(buff, value))
////  {
////    output = AnalogFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group32Var6_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var6 value;
  Group32Var6_in_Group32Var6(&value);
////  if(Read(buff, value))
  if(Read_in_Group32Var6_static(buff, &value))
  {
////    output = AnalogFactory::From(value.flags, value.value);
   Analog temp = From_in_AnalogFactory_staticOver2(value.flags, value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group32Var6::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var6::Write(ConvertGroup32Var6::Apply(value), buff);
////}
boolean WriteTarget_in_Group32Var6_static(Analog* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQV<Group32Var6, Analog> ConvertGroup32Var6;
  Group32Var6 temp = Apply_in_ConvertGroup32Var6_static(value);
  return Write_in_Group32Var6_static(&temp, buff);
}

Group32Var6 Apply_in_ConvertGroup32Var6_static(Analog* src)
{
  Group32Var6 target;
  Group32Var6_in_Group32Var6(&target);
  target.flags = (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
  target.value = (src->tTypedMeasurement_for_Double64).value;
  return target;
}
////template<class Target, class Source> struct ConvertQV : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.value = src.value;
////        t.flags = src.flags.value;
////        return t;
////    }
////};
*/
// ------- Group32Var7 -------

////Group32Var7::Group32Var7() : flags(0), value(0.0), time(0)
////{}
void Group32Var7_in_Group32Var7(Group32Var7 *pGroup32Var7)
{
  pGroup32Var7->flags = 0;
  pGroup32Var7->value = 0.0;
  DNPTime_in_DNPTimeOver2(&(pGroup32Var7->timeDNPTime), 0);
}

////bool Group32Var7::Read(rseq_t& buffer, Group32Var7& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group32Var7_static(RSeq_for_Uint16_t* buffer, Group32Var7* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_Float32_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group32Var7::Write(const Group32Var7& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group32Var7_static(Group32Var7* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_Float32_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group32Var7::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group32Var7 value;
////  if(Read(buff, value))
////  {
////    output = AnalogFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group32Var7_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var7 value;
//  if(Read(buff, value))
  Group32Var7_in_Group32Var7(&value);
  if(Read_in_Group32Var7_static(buff, &value))
  {
    Analog temp = From_in_AnalogFactory_staticOver3(value.flags, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group32Var7::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var7::Write(ConvertGroup32Var7::Apply(value), buff);
////}
boolean WriteTarget_in_Group32Var7_static(Analog* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTRangeCheck<Group32Var3, Analog, 0x20> ConvertGroup32Var3;
  Group32Var7 temp = Apply_in_ConvertGroup32Var7_static(value, 0x20);
  return Write_in_Group32Var7_static(&temp, buff);
}

Group32Var7 Apply_in_ConvertGroup32Var7_static(Analog* src, uint8_t Overrange)
{
  Group32Var7 target;
  Group32Var7_in_Group32Var7(&target);
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

// ------- Group32Var8 -------
/*
////Group32Var8::Group32Var8() : flags(0), value(0.0), time(0)
////{}
void Group32Var8_in_Group32Var8(Group32Var8 *pGroup32Var8)
{
 pGroup32Var8->flags = 0;
 pGroup32Var8->value = 0.0;
 DNPTime_in_DNPTimeOver2(&(pGroup32Var8->timeDNPTime), 0);
}

////bool Group32Var8::Read(rseq_t& buffer, Group32Var8& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group32Var8_static(RSeq_for_Uint16_t* buffer, Group32Var8* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_Double64_static(buffer, &(output->value)) &&
           read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group32Var8::Write(const Group32Var8& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group32Var8_static(Group32Var8* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_Double64_static(buffer, arg->value) &&
           write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group32Var8::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group32Var8 value;
////  if(Read(buff, value))
////  {
////    output = AnalogFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group32Var8_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group32Var8 value;
//  if(Read(buff, value))
  Group32Var8_in_Group32Var8(&value);
  if(Read_in_Group32Var8_static(buff, &value))
  {
   Analog temp = From_in_AnalogFactory_staticOver3(value.flags, value.value, value.timeDNPTime);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group32Var8::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var8::Write(ConvertGroup32Var8::Apply(value), buff);
////}
boolean WriteTarget_in_Group32Var8_static(Analog* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVT<Group32Var8, Analog> ConvertGroup32Var8;
  Group32Var8 temp = Apply_in_ConvertGroup32Var8_static(value);
  return Write_in_Group32Var8_static(&temp, buff);
}

Group32Var8 Apply_in_ConvertGroup32Var8_static(Analog* src)
{
  Group32Var8 target;
  Group32Var8_in_Group32Var8(&target);
  target.value = (src->tTypedMeasurement_for_Double64).value;
  target.flags = (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
  target.timeDNPTime.value = (src->tTypedMeasurement_for_Double64).mMeasurement.timeDNPTime.value;
  return target;
}
////template<class Target, class Source> struct ConvertQVT : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        t.value = src.value;
////        t.time = src.time;
////        return t;
////    }
////};
*/

////}
uint16_t Size_in_Group32Var1_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group32Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 1);
////  return GroupVariationID(32,1);
  return gGroupVariationID;
}


DNP3Serializer_for_Analog  Inst_in_Group32Var1_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group32Var1_static(),
      Size_in_Group32Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group32Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group32Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group32Var2_static(void)
{
  return 3;
}

GroupVariationID ID_in_Group32Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 2);
////  return GroupVariationID(32,2);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group32Var2_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group32Var2_static(),
      Size_in_Group32Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group32Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group32Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group32Var3_static(void)
{
  return 11;
}

GroupVariationID ID_in_Group32Var3_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 3);
////  return GroupVariationID(32,3);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group32Var3_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group32Var3_static(),
      Size_in_Group32Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group32Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group32Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group32Var4_static(void)
{
  return 9;
}

GroupVariationID ID_in_Group32Var4_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 4);
////  return GroupVariationID(32,4);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group32Var4_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group32Var4_static(),
      Size_in_Group32Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group32Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group32Var4_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group32Var5_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group32Var5_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 5);
////  return GroupVariationID(32,5);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group32Var5_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group32Var5_static(),
      Size_in_Group32Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group32Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group32Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Analog;
}
/*
 uint16_t Size_in_Group32Var6_static(void)
{
 return 9;
}

  GroupVariationID ID_in_Group32Var6_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 6);
////  return GroupVariationID(32,6);
 return gGroupVariationID;
}

 DNP3Serializer_for_Analog  Inst_in_Group32Var6_static(void)
{
   DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
   DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
                   ID_in_Group32Var6_static(),
                   Size_in_Group32Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group32Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group32Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Analog;
}
*/
uint16_t Size_in_Group32Var7_static(void)
{
  return 11;
}

GroupVariationID ID_in_Group32Var7_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 7);
////  return GroupVariationID(32,7);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group32Var7_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group32Var7_static(),
      Size_in_Group32Var7_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group32Var7_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group32Var7_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Analog;
}

/*
 uint16_t Size_in_Group32Var8_static(void)
{
 return 15;
}

  GroupVariationID ID_in_Group32Var8_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 32, 8);
////  return GroupVariationID(32,8);
 return gGroupVariationID;
}

 DNP3Serializer_for_Analog  Inst_in_Group32Var8_static(void)
{
   DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
   DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
                   ID_in_Group32Var8_static(),
                   Size_in_Group32Var8_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group32Var8_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group32Var8_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Analog;
}
*/
