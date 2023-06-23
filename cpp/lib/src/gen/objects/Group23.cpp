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
#include "Group23.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"
#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

Group23Var1 Apply_in_ConvertGroup23Var1_static(FrozenCounter* src);
Group23Var2 Apply_in_ConvertGroup23Var2_static(FrozenCounter* src);
Group23Var5 Apply_in_ConvertGroup23Var5_static(FrozenCounter* src);
Group23Var6 Apply_in_ConvertGroup23Var6_static(FrozenCounter* src);

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group23Var1 -------

////Group23Var1::Group23Var1() : flags(0), value(0)
////{}
void Group23Var1_in_Group23Var1(Group23Var1 *pGroup23Var1)
{
  pGroup23Var1->flags = 0;
  pGroup23Var1->value = 0;
}

////bool Group23Var1::Read(rseq_t& buffer, Group23Var1& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group23Var1_static(RSeq_for_Uint16_t* buffer, Group23Var1* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_UInt32_static(buffer, &(output->value));
}

////bool Group23Var1::Write(const Group23Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group23Var1_static(Group23Var1* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt32_static(buffer, arg->value);
}

////bool Group23Var1::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group23Var1 value;
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
boolean ReadTarget_in_Group23Var1_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group23Var1 value;
  Group23Var1_in_Group23Var1(&value);
  if(Read_in_Group23Var1_static(buff, &value))
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

////bool Group23Var1::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group23Var1::Write(ConvertGroup23Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group23Var1_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQV<Group23Var1, FrozenCounter> ConvertGroup23Var1;
  Group23Var1 temp = Apply_in_ConvertGroup23Var1_static(value);
  return Write_in_Group23Var1_static(&temp, buff);
}

Group23Var1 Apply_in_ConvertGroup23Var1_static(FrozenCounter* src)
{
  Group23Var1 target;
  Group23Var1_in_Group23Var1(&target);
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

// ------- Group23Var2 -------

////Group23Var2::Group23Var2() : flags(0), value(0)
////{}
void Group23Var2_in_Group23Var2(Group23Var2 *pGroup23Var2)
{
  pGroup23Var2->flags = 0;
  pGroup23Var2->value = 0;
}

////bool Group23Var2::Read(rseq_t& buffer, Group23Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group23Var2_static(RSeq_for_Uint16_t* buffer, Group23Var2* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_UInt16_static(buffer, &(output->value));
}

////bool Group23Var2::Write(const Group23Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group23Var2_static(Group23Var2* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group23Var2::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group23Var2 value;
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
boolean ReadTarget_in_Group23Var2_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group23Var2 value;
  Group23Var2_in_Group23Var2(&value);
//  if(Read(buff, value))
  if(Read_in_Group23Var2_static(buff, &value))
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

////bool Group23Var2::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group23Var2::Write(ConvertGroup23Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group23Var2_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVandTruncate<Group23Var2, FrozenCounter> ConvertGroup23Var2;
  Group23Var2 temp = Apply_in_ConvertGroup23Var2_static(value);
  return Write_in_Group23Var2_static(&temp, buff);
}

Group23Var2 Apply_in_ConvertGroup23Var2_static(FrozenCounter* src)
{
  Group23Var2 target;
  Group23Var2_in_Group23Var2(&target);
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

// ------- Group23Var5 -------

////Group23Var5::Group23Var5() : flags(0), value(0), time(0)
////{}
void Group23Var5_in_Group23Var5(Group23Var5 *pGroup23Var5)
{
 pGroup23Var5->flags = 0;
 pGroup23Var5->value = 0;
 DNPTime_in_DNPTimeOver2(&(pGroup23Var5->timeDNPTime), 0);
}

////bool Group23Var5::Read(rseq_t& buffer, Group23Var5& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group23Var5_static(RSeq_for_Uint16_t* buffer, Group23Var5* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group23Var5::Write(const Group23Var5& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group23Var5_static(Group23Var5* arg, WSeq_for_Uint16_t* buffer)
{
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt32_static(buffer, arg->value) &&
           write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group23Var5::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group23Var5 value;
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
boolean ReadTarget_in_Group23Var5_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group23Var5 value;
  Group23Var5_in_Group23Var5(&value);
//  if(Read(buff, value))
  if(Read_in_Group23Var5_static(buff, &value))
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

////bool Group23Var5::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
///{
////  return Group23Var5::Write(ConvertGroup23Var5::Apply(value), buff);
////}
boolean WriteTarget_in_Group23Var5_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVT<Group23Var5, FrozenCounter> ConvertGroup23Var5;
  Group23Var5 temp = Apply_in_ConvertGroup23Var5_static(value);
  return Write_in_Group23Var5_static(&temp, buff);
}

Group23Var5 Apply_in_ConvertGroup23Var5_static(FrozenCounter* src)
{
  Group23Var5 target;
  Group23Var5_in_Group23Var5(&target);
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

// ------- Group23Var6 -------

////Group23Var6::Group23Var6() : flags(0), value(0), time(0)
////{}
void Group23Var6_in_Group23Var6(Group23Var6 *pGroup23Var6)
{
 pGroup23Var6->flags = 0;
 pGroup23Var6->value = 0;
 DNPTime_in_DNPTimeOver2(&(pGroup23Var6->timeDNPTime), 0);
}

////bool Group23Var6::Read(rseq_t& buffer, Group23Var6& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group23Var6_static(RSeq_for_Uint16_t* buffer, Group23Var6* output)
{
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group23Var6::Write(const Group23Var6& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group23Var6_static(Group23Var6* arg, WSeq_for_Uint16_t* buffer)
{
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt16_static(buffer, arg->value) &&
           write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group23Var6::ReadTarget(rseq_t& buff, FrozenCounter& output)
////{
////  Group23Var6 value;
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
boolean ReadTarget_in_Group23Var6_static(RSeq_for_Uint16_t* buff, FrozenCounter* output)
{
  Group23Var6 value;
  Group23Var6_in_Group23Var6(&value);
//  if(Read(buff, value))
  if(Read_in_Group23Var6_static(buff, &value))
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

////bool Group23Var6::WriteTarget(const FrozenCounter& value, ser4cpp::wseq_t& buff)
////{
////  return Group23Var6::Write(ConvertGroup23Var6::Apply(value), buff);
////}
boolean WriteTarget_in_Group23Var6_static(FrozenCounter* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQVTandTruncate<Group23Var6, FrozenCounter> ConvertGroup23Var6;
  Group23Var6 temp = Apply_in_ConvertGroup23Var6_static(value);
  return Write_in_Group23Var6_static(&temp, buff);
}

Group23Var6 Apply_in_ConvertGroup23Var6_static(FrozenCounter* src)
{
  Group23Var6 target;
  Group23Var6_in_Group23Var6(&target);
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


////}
  GroupVariationID ID_in_Group23Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 23, 0);
//// return GroupVariationID(23,0);
 return gGroupVariationID;
}

 uint16_t Size_in_Group23Var1_static(void) 
{
 return 5; 
}

  GroupVariationID ID_in_Group23Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 23, 1);
////  return GroupVariationID(23,1); 
 return gGroupVariationID;
}

 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var1_static(void)
{
   DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
   DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
                   ID_in_Group23Var1_static(),
                   Size_in_Group23Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group23Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group23Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_FrozenCounter;
}

 uint16_t Size_in_Group23Var2_static(void) 
{
 return 3; 
}

  GroupVariationID ID_in_Group23Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 23, 2);
////  return GroupVariationID(23,2); 
 return gGroupVariationID;
}

 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var2_static(void)
{
   DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
   DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
                   ID_in_Group23Var2_static(),
                   Size_in_Group23Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group23Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group23Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_FrozenCounter;
}

 uint16_t Size_in_Group23Var5_static(void) 
{
 return 11; 
}

  GroupVariationID ID_in_Group23Var5_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 23, 5);
////  return GroupVariationID(23,5); 
 return gGroupVariationID;
}

 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var5_static(void)
{
   DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
   DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
                   ID_in_Group23Var5_static(),
                   Size_in_Group23Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group23Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group23Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_FrozenCounter;
}

 uint16_t Size_in_Group23Var6_static(void) 
{
 return 9; 
}

  GroupVariationID ID_in_Group23Var6_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 23, 6);
////  return GroupVariationID(23,6); 
 return gGroupVariationID;
}

 DNP3Serializer_for_FrozenCounter  Inst_in_Group23Var6_static(void)
{
   DNP3Serializer_for_FrozenCounter dDNP3Serializer_for_FrozenCounter;
   DNP3Serializer_for_FrozenCounter_in_DNP3Serializer_for_FrozenCounter(&dDNP3Serializer_for_FrozenCounter,
                   ID_in_Group23Var6_static(),
                   Size_in_Group23Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group23Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group23Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_FrozenCounter;
}
