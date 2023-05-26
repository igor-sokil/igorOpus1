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
#include "Group20.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"

//#include "DNPTimeParsing.h"
//#include <ser4cpp/serialization/LittleEndian.h>
#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

Group20Var6 Apply_in_ConvertGroup20Var6_static(Counter* src);
Group20Var5 Apply_in_ConvertGroup20Var5_static(Counter* src);
Group20Var2 Apply_in_ConvertGroup20Var2_static(Counter* src);
Group20Var1 Apply_in_ConvertGroup20Var1_static(Counter* src);

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group20Var1 -------

void Group20Var1_in_Group20Var1(Group20Var1 *pGroup20Var1)
{
  pGroup20Var1->flags = 0;
  pGroup20Var1->value = 0;
}

boolean Read_in_Group20Var1_static(RSeq_for_Uint16_t* buffer, Group20Var1* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_UInt32_static(buffer, &(output->value));
}

boolean Write_in_Group20Var1_static(Group20Var1* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt32_static(buffer, arg->value);
}

boolean ReadTarget_in_Group20Var1_static(RSeq_for_Uint16_t* buff, Counter* output)
{
  Group20Var1 value;
  Group20Var1_in_Group20Var1(&value);
  if(Read_in_Group20Var1_static(buff, &value))
  {
//    output = CounterFactory::From(value.flags, value.value);
   Counter temp = From_in_CounterFactory_staticOver2(value.flags, value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group20Var1_static(Counter* value, WSeq_for_Uint16_t* buff)
{
//  return Group20Var1::Write(ConvertGroup20Var1::Apply(value), buff);
//typedef ConvertQV<Group20Var1, Counter> ConvertGroup20Var1;
  Group20Var1 temp = Apply_in_ConvertGroup20Var1_static(value);
  return Write_in_Group20Var1_static(&temp, buff);
}

Group20Var1 Apply_in_ConvertGroup20Var1_static(Counter* src)
{
  Group20Var1 target;
  Group20Var1_in_Group20Var1(&target);
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

// ------- Group20Var2 -------

void Group20Var2_in_Group20Var2(Group20Var2 *pGroup20Var2)
{
  pGroup20Var2->flags = 0;
  pGroup20Var2->value = 0;
}

boolean Read_in_Group20Var2_static(RSeq_for_Uint16_t* buffer, Group20Var2* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
           read_from_in_UInt16_static(buffer, &(output->value));
}

boolean Write_in_Group20Var2_static(Group20Var2* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
    return write_to_in_UInt8_static(buffer, arg->flags) &&
           write_to_in_UInt16_static(buffer, arg->value);
}

boolean ReadTarget_in_Group20Var2_static(RSeq_for_Uint16_t* buff, Counter* output)
{
  Group20Var2 value;
  Group20Var2_in_Group20Var2(&value);
//  if(Read(buff, value))
  if(Read_in_Group20Var2_static(buff, &value))
  {
//    output = CounterFactory::From(value.flags, value.value);
   Counter temp = From_in_CounterFactory_staticOver2(value.flags, value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group20Var2_static(Counter* value, WSeq_for_Uint16_t* buff)
{
//  return Group20Var2::Write(ConvertGroup20Var2::Apply(value), buff);
//typedef ConvertQVandTruncate<Group20Var2, Counter> ConvertGroup20Var2;
  Group20Var2 temp = Apply_in_ConvertGroup20Var2_static(value);
  return Write_in_Group20Var2_static(&temp, buff);
}

Group20Var2 Apply_in_ConvertGroup20Var2_static(Counter* src)
{
  Group20Var2 target;
  Group20Var2_in_Group20Var2(&target);
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


// ------- Group20Var5 -------

void Group20Var5_in_Group20Var5(Group20Var5 *pGroup20Var5)
{
 pGroup20Var5->value = 0;
}

boolean Read_in_Group20Var5_static(RSeq_for_Uint16_t* buffer, Group20Var5* output)
{
  //return LittleEndian::read(buffer, output.value);
  return read_from_in_UInt32_static(buffer, &(output->value));
}

boolean Write_in_Group20Var5_static(Group20Var5* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.value);
    return write_to_in_UInt32_static(buffer, arg->value);
}

boolean ReadTarget_in_Group20Var5_static(RSeq_for_Uint16_t* buff, Counter* output)
{
  Group20Var5 value;
  Group20Var5_in_Group20Var5(&value);
//  if(Read(buff, value))
  if(Read_in_Group20Var5_static(buff, &value))
  {
//    output = CounterFactory::From(value.value);
   Counter temp = From_in_CounterFactory_staticOver1(value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group20Var5_static(Counter* value, WSeq_for_Uint16_t* buff)
{
//  return Group20Var5::Write(ConvertGroup20Var5::Apply(value), buff);
//typedef ConvertV<Group20Var5, Counter> ConvertGroup20Var5;
  Group20Var5 temp = Apply_in_ConvertGroup20Var5_static(value);
  return Write_in_Group20Var5_static(&temp, buff);
}

Group20Var5 Apply_in_ConvertGroup20Var5_static(Counter* src)
{
  Group20Var5 target;
  Group20Var5_in_Group20Var5(&target);
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

// ------- Group20Var6 -------

void Group20Var6_in_Group20Var6(Group20Var6 *pGroup20Var6)
{
  pGroup20Var6->value = 0;
}

boolean Read_in_Group20Var6_static(RSeq_for_Uint16_t* buffer, Group20Var6* output)
{
  //return LittleEndian::read(buffer, output.value);
  return  read_from_in_UInt16_static(buffer, &(output->value));
}

boolean Write_in_Group20Var6_static(Group20Var6* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.value);
    return write_to_in_UInt16_static(buffer, arg->value);
}

boolean ReadTarget_in_Group20Var6_static(RSeq_for_Uint16_t* buff, Counter* output)
{
//  Group20Var6 value;
//  if(Read(buff, value))
  Group20Var6 value;
  Group20Var6_in_Group20Var6(&value);
//  if(Read(buff, value))
  if(Read_in_Group20Var6_static(buff, &value))
  {
////    output = CounterFactory::From(value.value);
   Counter temp = From_in_CounterFactory_staticOver1(value.value);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group20Var6_static(Counter* value, WSeq_for_Uint16_t* buff)
{
////  return Group20Var6::Write(ConvertGroup20Var6::Apply(value), buff);
//typedef ConvertVandTruncate<Group20Var6, Counter> ConvertGroup20Var6;
  Group20Var6 temp = Apply_in_ConvertGroup20Var6_static(value);
  return Write_in_Group20Var6_static(&temp, buff);
}

Group20Var6 Apply_in_ConvertGroup20Var6_static(Counter* src)
{
  Group20Var6 target;
  Group20Var6_in_Group20Var6(&target);
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

  GroupVariationID ID_in_Group20Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 20, 0);
//// return GroupVariationID(20,0);
 return gGroupVariationID;
}

 uint16_t Size_in_Group20Var1_static(void) 
{
 return 5; 
}

  GroupVariationID ID_in_Group20Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 20, 1);
////  return GroupVariationID(20,1); 
 return gGroupVariationID;
}

 DNP3Serializer_for_Counter  Inst_in_Group20Var1_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group20Var1_static(),
                   Size_in_Group20Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group20Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group20Var1_static);

   return dDNP3Serializer_for_Counter;
}

 uint16_t Size_in_Group20Var2_static(void) 
{
 return 3; 
}

  GroupVariationID ID_in_Group20Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 20, 2);
////  return GroupVariationID(20,2); 
 return gGroupVariationID;
}

 DNP3Serializer_for_Counter  Inst_in_Group20Var2_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group20Var2_static(),
                   Size_in_Group20Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group20Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group20Var2_static);

   return dDNP3Serializer_for_Counter;
}

 uint16_t Size_in_Group20Var5_static(void) 
{
 return 4; 
}

  GroupVariationID ID_in_Group20Var5_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 20, 5);
////  return GroupVariationID(20,5); 
 return gGroupVariationID;
}

 DNP3Serializer_for_Counter  Inst_in_Group20Var5_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group20Var5_static(),
                   Size_in_Group20Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group20Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group20Var5_static);

   return dDNP3Serializer_for_Counter;
}

 uint16_t Size_in_Group20Var6_static(void) 
{
 return 2; 
}

  GroupVariationID ID_in_Group20Var6_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 20, 6);
////  return GroupVariationID(20,6); 
 return gGroupVariationID;
}

 DNP3Serializer_for_Counter  Inst_in_Group20Var6_static(void)
{
   DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
   DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
                   ID_in_Group20Var6_static(),
                   Size_in_Group20Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group20Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group20Var6_static);

   return dDNP3Serializer_for_Counter;
}
