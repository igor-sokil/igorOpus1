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
#include "Group41.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"
#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

Group41Var1 Apply_in_ConvertGroup41Var1_static(AnalogOutputInt32* src);
Group41Var2 Apply_in_ConvertGroup41Var2_static(AnalogOutputInt16* src);
Group41Var3 Apply_in_ConvertGroup41Var3_static(AnalogOutputFloat32* src);

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group41Var1 -------

void Group41Var1_in_Group41Var1(Group41Var1 *pGroup41Var1)
{
  pGroup41Var1->value = 0;
  pGroup41Var1->status = 0;
}

////bool Group41Var1::Read(rseq_t& buffer, Group41Var1& output)
////{
////  return LittleEndian::read(buffer, output.value, output.status);
////}
boolean Read_in_Group41Var1_static(RSeq_for_Uint16_t* buffer, Group41Var1* output)
{
    return read_from_in_UInt32_static(buffer,  (uint32_t*)&(output->value)) &&
           read_from_in_UInt8_static(buffer,   &(output->status));
}

////bool Group41Var1::Write(const Group41Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.value, arg.status);
////}
boolean Write_in_Group41Var1_static(Group41Var1* arg, WSeq_for_Uint16_t* buffer)
{
    return write_to_in_UInt32_static(buffer, arg->value) &&
           write_to_in_UInt8_static(buffer, arg->status);
}

boolean ReadTarget_in_Group41Var1_static(RSeq_for_Uint16_t* buff, AnalogOutputInt32* output)
{
  Group41Var1 value;
//  if(Read(buff, value))
  Group41Var1_in_Group41Var1(&value);
  if(Read_in_Group41Var1_static(buff, &value))
  {
//   AnalogOutputInt32 From_in_AnalogOutputFactory_for_Int32_t_static(int32_t value, uint8_t status);
////    output = From_in_AnalogOutputInt32Factory(value.value, value.status);
   AnalogOutputInt32 temp = From_in_AnalogOutputFactory_for_Int32_t_static(value.value, value.status);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group41Var1_static(AnalogOutputInt32* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQS<Group41Var1, AnalogOutputInt32> ConvertGroup41Var1;
////  return Group41Var1::Write(ConvertGroup41Var1::Apply(value), buff);
  Group41Var1 temp = Apply_in_ConvertGroup41Var1_static(value);
  return Write_in_Group41Var1_static(&temp, buff);
}

Group41Var1 Apply_in_ConvertGroup41Var1_static(AnalogOutputInt32* src)
{
  Group41Var1 target;
  Group41Var1_in_Group41Var1(&target);

        target.value = (src->aAnalogOutput_for_Int32).value;
        target.status = (src->aAnalogOutput_for_Int32).status;
  return target;
}

////template<class Target, class Source> struct ConvertQS : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.value = src.value;
////        t.status = CommandStatusSpec::to_type(src.status);
////        return t;
////    }
////};

// ------- Group41Var2 -------

void Group41Var2_in_Group41Var2(Group41Var2 *pGroup41Var2)
{
 pGroup41Var2->value = 0;
 pGroup41Var2->status = 0;
}

////bool Group41Var2::Read(rseq_t& buffer, Group41Var2& output)
////{
////  return LittleEndian::read(buffer, output.value, output.status);
////}
boolean Read_in_Group41Var2_static(RSeq_for_Uint16_t* buffer, Group41Var2* output)
{
    return read_from_in_UInt16_static(buffer,  (uint16_t*)&(output->value)) &&
           read_from_in_UInt8_static(buffer,   &(output->status));
}

////bool Group41Var2::Write(const Group41Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.value, arg.status);
////}
boolean Write_in_Group41Var2_static(Group41Var2* arg, WSeq_for_Uint16_t* buffer)
{
    return write_to_in_UInt16_static(buffer, arg->value) &&
           write_to_in_UInt8_static(buffer, arg->status);
}

boolean ReadTarget_in_Group41Var2_static(RSeq_for_Uint16_t* buff, AnalogOutputInt16* output)
{
  Group41Var2 value;
////  if(Read(buff, value))
  Group41Var2_in_Group41Var2(&value);
  if(Read_in_Group41Var2_static(buff, &value))
  {
////    output = From_in_AnalogOutputInt16Factory(value.value, value.status);
   AnalogOutputInt16 temp = From_in_AnalogOutputFactory_for_Int16_t_static(value.value, value.status);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group41Var2_static(AnalogOutputInt16* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQS<Group41Var2, AnalogOutputInt16> ConvertGroup41Var2;
////  return Group41Var2::Write(ConvertGroup41Var2::Apply(value), buff);
  Group41Var2 temp = Apply_in_ConvertGroup41Var2_static(value);
  return Write_in_Group41Var2_static(&temp, buff);
}

Group41Var2 Apply_in_ConvertGroup41Var2_static(AnalogOutputInt16* src)
{
  Group41Var2 target;
  Group41Var2_in_Group41Var2(&target);

        target.value = (src->aAnalogOutput_for_Int16).value;
//        target.status = src->status;
        target.status = (src->aAnalogOutput_for_Int16).status;
  return target;
}

////template<class Target, class Source> struct ConvertQS : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.value = src.value;
////        t.status = CommandStatusSpec::to_type(src.status);
////        return t;
////    }
////};

// ------- Group41Var3 -------

void Group41Var3_in_Group41Var3(Group41Var3 *pGroup41Var3)
{
 pGroup41Var3->value = 0.0;
 pGroup41Var3->status = 0;
}

/////bool Group41Var3::Read(rseq_t& buffer, Group41Var3& output)
////{
////  return LittleEndian::read(buffer, output.value, output.status);
////}
boolean Read_in_Group41Var3_static(RSeq_for_Uint16_t* buffer, Group41Var3* output)
{
    return read_from_in_Float32_static(buffer, &(output->value)) &&
           read_from_in_UInt8_static(buffer, &(output->status));
}

boolean Write_in_Group41Var3_static(Group41Var3* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.value, arg.status);
    return write_to_in_Float32_static(buffer, arg->value) &&
           write_to_in_UInt8_static(buffer, arg->status);
}

boolean ReadTarget_in_Group41Var3_static(RSeq_for_Uint16_t* buff, AnalogOutputFloat32* output)
{
  Group41Var3 value;
  Group41Var3_in_Group41Var3(&value);
////  if(Read(buff, value))
  if(Read_in_Group41Var3_static(buff, &value))
  {
////    output = From_in_AnalogOutputFloat32Factory(value.value, value.status);
   AnalogOutputFloat32 temp = From_in_AnalogOutputFactory_for_Float32_static(value.value, value.status);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group41Var3_static(AnalogOutputFloat32* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertQS<Group41Var3, AnalogOutputFloat32> ConvertGroup41Var3;
////  return Group41Var3::Write(ConvertGroup41Var3::Apply(value), buff);
  Group41Var3 temp = Apply_in_ConvertGroup41Var3_static(value);
  return Write_in_Group41Var3_static(&temp, buff);
}

Group41Var3 Apply_in_ConvertGroup41Var3_static(AnalogOutputFloat32* src)
{
  Group41Var3 target;
  Group41Var3_in_Group41Var3(&target);

        target.value = (src->aAnalogOutput_for_Float32).value;
        target.status = (src->aAnalogOutput_for_Float32).status;
  return target;
}

////template<class Target, class Source> struct ConvertQS : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.value = src.value;
////        t.status = CommandStatusSpec::to_type(src.status);
////        return t;
////    }
////};

// ------- Group41Var4 -------

/////Group41Var4::Group41Var4() : value(0.0), status(0)
////{}
////
////bool Group41Var4::Read(rseq_t& buffer, Group41Var4& output)
////{
////  return LittleEndian::read(buffer, output.value, output.status);
////}
////
////bool Group41Var4::Write(const Group41Var4& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.value, arg.status);
////}
////
////bool Group41Var4::ReadTarget(rseq_t& buff, AnalogOutputDouble64& output)
////{
////  Group41Var4 value;
////  if(Read(buff, value))
////  {
////    output = From_in_AnalogOutputDouble64Factory(value.value, value.status);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
////
////bool Group41Var4::WriteTarget(const AnalogOutputDouble64& value, ser4cpp::wseq_t& buff)
////{
////  return Group41Var4::Write(ConvertGroup41Var4::Apply(value), buff);
////}


////}
  GroupVariationID ID_in_Group41Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 41, 0);
//// return GroupVariationID(41,0);
 return gGroupVariationID;
}

 uint16_t Size_in_Group41Var1_static(void) 
{
 return 5; 
}
  GroupVariationID ID_in_Group41Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 41, 1);
////  return GroupVariationID(41,1); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputInt32  Inst_in_Group41Var1_static(void)
{
   DNP3Serializer_for_AnalogOutputInt32 dDNP3Serializer_for_AnalogOutputInt32;
   DNP3Serializer_for_AnalogOutputInt32_in_DNP3Serializer_for_AnalogOutputInt32(&dDNP3Serializer_for_AnalogOutputInt32,
                   ID_in_Group41Var1_static(),
                   Size_in_Group41Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group41Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group41Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputInt32;
}

 uint16_t Size_in_Group41Var2_static(void) 
{
 return 3; 
}

  GroupVariationID ID_in_Group41Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 41, 2);
////  return GroupVariationID(41,2); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputInt16  Inst_in_Group41Var2_static(void)
{
   DNP3Serializer_for_AnalogOutputInt16 dDNP3Serializer_for_AnalogOutputInt16;
   DNP3Serializer_for_AnalogOutputInt16_in_DNP3Serializer_for_AnalogOutputInt16(&dDNP3Serializer_for_AnalogOutputInt16,
                   ID_in_Group41Var2_static(),
                   Size_in_Group41Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group41Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group41Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputInt16;
}

 uint16_t Size_in_Group41Var3_static(void) 
{
 return 5; 
}

  GroupVariationID ID_in_Group41Var3_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 41, 3);
////  return GroupVariationID(41,3); 
 return gGroupVariationID;
}

 DNP3Serializer_for_AnalogOutputFloat32  Inst_in_Group41Var3_static(void)
{
   DNP3Serializer_for_AnalogOutputFloat32 dDNP3Serializer_for_AnalogOutputFloat32;
   DNP3Serializer_for_AnalogOutputFloat32_in_DNP3Serializer_for_AnalogOutputFloat32(&dDNP3Serializer_for_AnalogOutputFloat32,
                   ID_in_Group41Var3_static(),
                   Size_in_Group41Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group41Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group41Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputFloat32;
}

 uint16_t Size_in_Group41Var4_static(void) 
{
 return 9; 
}

  GroupVariationID ID_in_Group41Var4_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 41, 4);
////  return GroupVariationID(41,4); 
 return gGroupVariationID;
}
/*
 DNP3Serializer_for_AnalogOutputDouble64  Inst_in_Group41Var4_static(void)
{
   DNP3Serializer_for_AnalogOutputDouble64 dDNP3Serializer_for_AnalogOutputDouble64;
   DNP3Serializer_for_AnalogOutputDouble64_in_DNP3Serializer_for_AnalogOutputDouble64(&dDNP3Serializer_for_AnalogOutputDouble64,
                   ID_in_Group41Var4_static(),
                   Size_in_Group41Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group41Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group41Var4_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_AnalogOutputDouble64;
}
*/