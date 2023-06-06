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

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group32Var1 -------
Group32Var1 Apply_in_ConvertGroup32Var1_static(Analog* src, uint8_t Overrange);

void Group32Var1_in_Group32Var1(Group32Var1 *pGroup32Var1)
{
  pGroup32Var1->flags = 0;
  pGroup32Var1->value = 0;
}

boolean Read_in_Group32Var1_static(RSeq_for_Uint16_t* buffer, Group32Var1* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
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

////bool Group32Var2::Read(rseq_t& buffer, Group32Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}

////bool Group32Var2::Write(const Group32Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}

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
////
////bool Group32Var2::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var2::Write(ConvertGroup32Var2::Apply(value), buff);
////}
////
////// ------- Group32Var3 -------
////
////Group32Var3::Group32Var3() : flags(0), value(0), time(0)
////{}
////
////bool Group32Var3::Read(rseq_t& buffer, Group32Var3& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
////
////bool Group32Var3::Write(const Group32Var3& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
////
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
////
////bool Group32Var3::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var3::Write(ConvertGroup32Var3::Apply(value), buff);
////}
////
////// ------- Group32Var4 -------
////
////Group32Var4::Group32Var4() : flags(0), value(0), time(0)
////{}
////
////bool Group32Var4::Read(rseq_t& buffer, Group32Var4& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
////
////bool Group32Var4::Write(const Group32Var4& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
////
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
////
////bool Group32Var4::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var4::Write(ConvertGroup32Var4::Apply(value), buff);
////}
////
////// ------- Group32Var5 -------

////Group32Var5::Group32Var5() : flags(0), value(0.0)
////{}
////
////bool Group32Var5::Read(rseq_t& buffer, Group32Var5& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
////
////bool Group32Var5::Write(const Group32Var5& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
////
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
////
////bool Group32Var5::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var5::Write(ConvertGroup32Var5::Apply(value), buff);
////}
////
// ------- Group32Var6 -------

////Group32Var6::Group32Var6() : flags(0), value(0.0)
////{}
////
////bool Group32Var6::Read(rseq_t& buffer, Group32Var6& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
////
////bool Group32Var6::Write(const Group32Var6& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
////
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
////
////bool Group32Var6::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var6::Write(ConvertGroup32Var6::Apply(value), buff);
////}
////
// ------- Group32Var7 -------

////Group32Var7::Group32Var7() : flags(0), value(0.0), time(0)
////{}
////
////bool Group32Var7::Read(rseq_t& buffer, Group32Var7& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
////
////bool Group32Var7::Write(const Group32Var7& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
////
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
////
////bool Group32Var7::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var7::Write(ConvertGroup32Var7::Apply(value), buff);
////}
////
// ------- Group32Var8 -------

////Group32Var8::Group32Var8() : flags(0), value(0.0), time(0)
////{}
////
////bool Group32Var8::Read(rseq_t& buffer, Group32Var8& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
////
////bool Group32Var8::Write(const Group32Var8& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
////
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
////
////bool Group32Var8::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group32Var8::Write(ConvertGroup32Var8::Apply(value), buff);
////}
////

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
/*
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
