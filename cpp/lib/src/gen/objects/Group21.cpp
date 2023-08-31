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
#include "Group21.h"

#include "MeasurementFactory.h"
//#include "WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

Group21Var1 Apply_in_ConvertGroup21Var1_static(FrozenCounter* src);
Group21Var2 Apply_in_ConvertGroup21Var2_static(FrozenCounter* src);
Group21Var5 Apply_in_ConvertGroup21Var5_static(FrozenCounter* src);
Group21Var6 Apply_in_ConvertGroup21Var6_static(FrozenCounter* src);
Group21Var9 Apply_in_ConvertGroup21Var9_static(FrozenCounter* src);
Group21Var10 Apply_in_ConvertGroup21Var10_static(FrozenCounter* src);

// ------- Group21Var1 -------

////Group21Var1::Group21Var1() : flags(0), value(0)
////{}
void Group21Var1_in_Group21Var1(Group21Var1 *pGroup21Var1)
{
  pGroup21Var1->flags = 0;
  pGroup21Var1->value = 0;
}

////bool Group21Var1::Read(rseq_t& buffer, Group21Var1& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group21Var1_static(RSeq_for_Uint16_t* buffer, Group21Var1* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, &(output->value));
}

////bool Group21Var1::Write(const Group21Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group21Var1_static(Group21Var1* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value);
}

////bool Group21Var1::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group21Var1 value;
////  if(Read(buff, value))
////  {
////    output = FrozenCounterFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group21Var1_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group21Var1 value;
//  if(Read(buff, value))
  Group21Var1_in_Group21Var1(&value);
  if(Read_in_Group21Var1_static(buff, &value))
  {
    FrozenCounter temp = From_in_FrozenCounterFactory_staticOver2(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group21Var1::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group21Var1::Write(ConvertGroup21Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group21Var1_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
////  return Group2Var1::Write(ConvertGroup2Var1::Apply(value), buff);
//typedef ConvertQV<Group22Var1, Counter> ConvertGroup22Var1;
  Group21Var1 temp = Apply_in_ConvertGroup21Var1_static(value);
  return Write_in_Group21Var1_static(&temp, buff);
}

Group21Var1 Apply_in_ConvertGroup21Var1_static(FrozenCounter* src)
{
  Group21Var1 target;
  Group21Var1_in_Group21Var1(&target);
  target.flags = (src->tTypedMeasurement_for_Uint32).mMeasurement.flags.value;
  target.value = (src->tTypedMeasurement_for_Uint32).value;
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

// ------- Group21Var2 -------

////Group21Var2::Group21Var2() : flags(0), value(0)
////{}
void Group21Var2_in_Group21Var2(Group21Var2 *pGroup21Var2)
{
  pGroup21Var2->flags = 0;
  pGroup21Var2->value = 0;
}

////bool Group21Var2::Read(rseq_t& buffer, Group21Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group21Var2_static(RSeq_for_Uint16_t* buffer, Group21Var2* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, &(output->value));
}

////bool Group21Var2::Write(const Group21Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group21Var2_static(Group21Var2* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group21Var2::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group21Var2 value;
////  if(Read(buff, value))
////  {
////    output = FrozenCounterFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group21Var2_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group21Var2 value;
  Group21Var2_in_Group21Var2(&value);
//  if(Read(buff, value))
  if(Read_in_Group21Var2_static(buff, &value))
  {
//    output = CounterFactory::From(value.flags, value.value);
    FrozenCounter temp = From_in_FrozenCounterFactory_staticOver2(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group21Var2::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group21Var2::Write(ConvertGroup21Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group21Var2_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
////  return Group21Var2::Write(ConvertGroup21Var2::Apply(value), buff);
//typedef ConvertQVandTruncate<Group20Var2, Counter> ConvertGroup20Var2;
  Group21Var2 temp = Apply_in_ConvertGroup21Var2_static(value);
  return Write_in_Group21Var2_static(&temp, buff);
}

Group21Var2 Apply_in_ConvertGroup21Var2_static(FrozenCounter* src)
{
  Group21Var2 target;
  Group21Var2_in_Group21Var2(&target);
  target.flags = (src->tTypedMeasurement_for_Uint32).mMeasurement.flags.value;
  target.value = (uint16_t)((src->tTypedMeasurement_for_Uint32).value);
  return target;
}
////template<class Target, class Source> struct ConvertQVandTruncate : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        t.value = static_cast<typename Target::ValueType>(src.value);
////        return t;
////    }
////};

// ------- Group21Var5 -------

////Group21Var5::Group21Var5() : flags(0), value(0), time(0)
////{}
void Group21Var5_in_Group21Var5(Group21Var5 *pGroup21Var5)
{
  pGroup21Var5->flags = 0;
  pGroup21Var5->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup21Var5->timeDNPTime), 0);
}

////bool Group21Var5::Read(rseq_t& buffer, Group21Var5& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group21Var5_static(RSeq_for_Uint16_t* buffer, Group21Var5* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group21Var5::Write(const Group21Var5& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group21Var5_static(Group21Var5* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group21Var5::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group21Var5 value;
////  if(Read(buff, value))
////  {
////    output = FrozenCounterFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group21Var5_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group21Var5 value;
  Group21Var5_in_Group21Var5(&value);
//  if(Read(buff, value))
  if(Read_in_Group21Var5_static(buff, &value))
  {
    FrozenCounter temp = From_in_FrozenCounterFactory_staticOver3(value.flags, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group21Var5::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group21Var5::Write(ConvertGroup21Var5::Apply(value), buff);
////}
boolean WriteTarget_in_Group21Var5_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVT<Group23Var5, FrozenCounter> ConvertGroup23Var5;
  Group21Var5 temp = Apply_in_ConvertGroup21Var5_static(value);
  return Write_in_Group21Var5_static(&temp, buff);
}

Group21Var5 Apply_in_ConvertGroup21Var5_static(FrozenCounter* src)
{
  Group21Var5 target;
  Group21Var5_in_Group21Var5(&target);
  target.value = (src->tTypedMeasurement_for_Uint32).value;
  target.flags = (src->tTypedMeasurement_for_Uint32).mMeasurement.flags.value;
  target.timeDNPTime.value = (src->tTypedMeasurement_for_Uint32).mMeasurement.timeDNPTime.value;
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

// ------- Group21Var6 -------

////Group21Var6::Group21Var6() : flags(0), value(0), time(0)
////{}
void Group21Var6_in_Group21Var6(Group21Var6 *pGroup21Var6)
{
  pGroup21Var6->flags = 0;
  pGroup21Var6->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup21Var6->timeDNPTime), 0);
}

////bool Group21Var6::Read(rseq_t& buffer, Group21Var6& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group21Var6_static(RSeq_for_Uint16_t* buffer, Group21Var6* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group21Var6::Write(const Group21Var6& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group21Var6_static(Group21Var6* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group21Var6::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group21Var6 value;
////  if(Read(buff, value))
////  {
////    output = FrozenCounterFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
///  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group21Var6_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group21Var6 value;
  Group21Var6_in_Group21Var6(&value);
//  if(Read(buff, value))
  if(Read_in_Group21Var6_static(buff, &value))
  {
    FrozenCounter temp = From_in_FrozenCounterFactory_staticOver3(value.flags, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group21Var6::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group21Var6::Write(ConvertGroup21Var6::Apply(value), buff);
////}
boolean WriteTarget_in_Group21Var6_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTandTruncate<Group23Var6, FrozenCounter> ConvertGroup23Var6;
  Group21Var6 temp = Apply_in_ConvertGroup21Var6_static(value);
  return Write_in_Group21Var6_static(&temp, buff);
}

Group21Var6 Apply_in_ConvertGroup21Var6_static(FrozenCounter* src)
{
  Group21Var6 target;
  Group21Var6_in_Group21Var6(&target);
  target.flags = (src->tTypedMeasurement_for_Uint32).mMeasurement.flags.value;
  target.value = (uint16_t)((src->tTypedMeasurement_for_Uint32).value);
  return target;
}
////template<class Target, class Source> struct ConvertQVandTruncate : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        t.value = static_cast<typename Target::ValueType>(src.value);
////        return t;
////    }
////};

// ------- Group21Var9 -------

////Group21Var9::Group21Var9() : value(0)
////{}
void Group21Var9_in_Group21Var9(Group21Var9 *pGroup21Var9)
{
  pGroup21Var9->value = 0;
}

////bool Group21Var9::Read(rseq_t& buffer, Group21Var9& output)
////{
////  return LittleEndian::read(buffer, output.value);
////}
boolean Read_in_Group21Var9_static(RSeq_for_Uint16_t* buffer, Group21Var9* output)
{
  return read_from_in_UInt32_static(buffer, &(output->value));
}

////bool Group21Var9::Write(const Group21Var9& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.value);
////}
boolean Write_in_Group21Var9_static(Group21Var9* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt32_static(buffer, arg->value);
}

////bool Group21Var9::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group21Var9 value;
////  if(Read(buff, value))
////  {
////    output = FrozenCounterFactory::From(value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group21Var9_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group21Var9 value;
  Group21Var9_in_Group21Var9(&value);
//  if(Read(buff, value))
  if(Read_in_Group21Var9_static(buff, &value))
  {
    FrozenCounter temp = From_in_FrozenCounterFactory_staticOver1(value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group21Var9::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group21Var9::Write(ConvertGroup21Var9::Apply(value), buff);
////}
boolean WriteTarget_in_Group21Var9_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
////  return Group21Var9::Write(ConvertGroup21Var9::Apply(value), buff);
//typedef ConvertV<Group21Var9, FrozenCounter> ConvertGroup21Var9;
  Group21Var9 temp = Apply_in_ConvertGroup21Var9_static(value);
  return Write_in_Group21Var9_static(&temp, buff);
}

Group21Var9 Apply_in_ConvertGroup21Var9_static(FrozenCounter* src)
{
  Group21Var9 target;
  Group21Var9_in_Group21Var9(&target);
  target.value = (src->tTypedMeasurement_for_Uint32).value;
  return target;
}
////template<class Target, class Source> struct ConvertV : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.value = src.value;
////        return t;
////    }
////};

// ------- Group21Var10 -------

////Group21Var10::Group21Var10() : value(0)
////{}
void Group21Var10_in_Group21Var10(Group21Var10 *pGroup21Var10)
{
  pGroup21Var10->value = 0;
}

////bool Group21Var10::Read(rseq_t& buffer, Group21Var10& output)
////{
////  return LittleEndian::read(buffer, output.value);
////}
boolean Read_in_Group21Var10_static(RSeq_for_Uint16_t* buffer, Group21Var10* output)
{
  return read_from_in_UInt16_static(buffer, &(output->value));
}

////bool Group21Var10::Write(const Group21Var10& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.value);
////}
boolean Write_in_Group21Var10_static(Group21Var10* arg, WSeq_for_Uint16_t* buffer)
{
  return write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group21Var10::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group21Var10 value;
////  if(Read(buff, value))
////  {
////    output = FrozenCounterFactory::From(value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group21Var10_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group21Var10 value;
  Group21Var10_in_Group21Var10(&value);
//  if(Read(buff, value))
  if(Read_in_Group21Var10_static(buff, &value))
  {
    FrozenCounter temp = From_in_FrozenCounterFactory_staticOver1(value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group21Var10::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group21Var10::Write(ConvertGroup21Var10::Apply(value), buff);
////}
boolean WriteTarget_in_Group21Var10_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTandTruncate<Group23Var6, FrozenCounter> ConvertGroup23Var6;
  Group21Var10 temp = Apply_in_ConvertGroup21Var10_static(value);
  return Write_in_Group21Var10_static(&temp, buff);
}

Group21Var10 Apply_in_ConvertGroup21Var10_static(FrozenCounter* src)
{
  Group21Var10 target;
  Group21Var10_in_Group21Var10(&target);
  target.value = (uint16_t)((src->tTypedMeasurement_for_Uint32).value);
  return target;
}
////template<class Target, class Source> struct ConvertVandTruncate : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.value = static_cast<typename Target::ValueType>(src.value);
////        return t;
////    }
////};


////}
GroupVariationID ID_in_Group21Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 21, 0);
//// return GroupVariationID(21,0);
  return gGroupVariationID;
}

uint16_t Size_in_Group21Var1_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group21Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 21, 1);
////  return GroupVariationID(21,1);
  return gGroupVariationID;
}

DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var1_static(void)
{
  DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
  DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
      ID_in_Group21Var1_static(),
      Size_in_Group21Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group21Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group21Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_FrozenCounter;
}

uint16_t Size_in_Group21Var2_static(void)
{
  return 3;
}

GroupVariationID ID_in_Group21Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 21, 2);
////  return GroupVariationID(21,2);
  return gGroupVariationID;
}

DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var2_static(void)
{
  DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
  DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
      ID_in_Group21Var2_static(),
      Size_in_Group21Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group21Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group21Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_FrozenCounter;
}

uint16_t Size_in_Group21Var5_static(void)
{
  return 11;
}

GroupVariationID ID_in_Group21Var5_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 21, 5);
////  return GroupVariationID(21,5);
  return gGroupVariationID;
}

DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var5_static(void)
{
  DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
  DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
      ID_in_Group21Var5_static(),
      Size_in_Group21Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group21Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group21Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_FrozenCounter;
}

uint16_t Size_in_Group21Var6_static(void)
{
  return 9;
}

GroupVariationID ID_in_Group21Var6_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 21, 6);
////  return GroupVariationID(21,6);
  return gGroupVariationID;
}

DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var6_static(void)
{
  DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
  DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
      ID_in_Group21Var6_static(),
      Size_in_Group21Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group21Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group21Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_FrozenCounter;
}

uint16_t Size_in_Group21Var9_static(void)
{
  return 4;
}

GroupVariationID ID_in_Group21Var9_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 21, 9);
////  return GroupVariationID(21,9);
  return gGroupVariationID;
}

DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var9_static(void)
{
  DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
  DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
      ID_in_Group21Var9_static(),
      Size_in_Group21Var9_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group21Var9_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group21Var9_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_FrozenCounter;
}

uint16_t Size_in_Group21Var10_static(void)
{
  return 2;
}

GroupVariationID ID_in_Group21Var10_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 21, 10);
////  return GroupVariationID(21,10);
  return gGroupVariationID;
}

DNP3Serializer_for_FrozenCounter  Inst_in_Group21Var10_static(void)
{
  DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
  DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
      ID_in_Group21Var10_static(),
      Size_in_Group21Var10_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group21Var10_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group21Var10_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_FrozenCounter;
}

