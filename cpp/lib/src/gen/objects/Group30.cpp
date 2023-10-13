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
#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "DownSampling.h"
#include "Group30.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"

#include "MeasurementFactory.h"
//#include "app/WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

Group30Var1 Apply_in_ConvertGroup30Var1_static(Analog* src, uint8_t Overrange);
Group30Var2 Apply_in_ConvertGroup30Var2_static(Analog* src, uint8_t Overrange);
Group30Var3 Apply_in_ConvertGroup30Var3_static(Analog* src);//, uint8_t Overrange);
Group30Var4 Apply_in_ConvertGroup30Var4_static(Analog* src);//, uint8_t Overrange);
Group30Var5 Apply_in_ConvertGroup30Var5_static(Analog* src, uint8_t Overrange);

////using namespace ser4cpp;

////namespace opendnp3 {

GroupVariationID ID_in_Group30Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 30, 0);
//// return GroupVariationID(30,0);
  return gGroupVariationID;
}

// ------- Group30Var1 -------

void Group30Var1_in_Group30Var1(Group30Var1 *pGroup30Var1)
{
  pGroup30Var1->flags = 0;
  pGroup30Var1->value = 0;
}

boolean Read_in_Group30Var1_static(RSeq_for_Uint16_t* buffer, Group30Var1* output)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Read_in_Group30Var1_static1"<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->flags= "<<(uint16_t)output->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->value= "<<(uint32_t)output->value<<'\n';
  decrement_stack_info();
#endif
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value));
}

boolean Write_in_Group30Var1_static(Group30Var1* arg, WSeq_for_Uint16_t* buffer)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_Group30Var1_static"<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*arg->flags= "<<std::hex<<(uint16_t)arg->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*arg->value= "<<std::hex<<(uint32_t)arg->value<<'\n';
  decrement_stack_info();
#endif
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value);
}

boolean ReadTarget_in_Group30Var1_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group30Var1 value;
////  if(Read(buff, value))
  Group30Var1_in_Group30Var1(&value);
  if(Read_in_Group30Var1_static(buff, &value))
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

boolean WriteTarget_in_Group30Var1_static(Analog* value, WSeq_for_Uint16_t* buff)
{
////  return Group30Var1::Write(ConvertGroup30Var1::Apply(value), buff);
//typedef ConvertQVRangeCheck<Group30Var1, Analog, 0x20> ConvertGroup30Var1;
  Group30Var1 temp = Apply_in_ConvertGroup30Var1_static(value, 0x20);
  return Write_in_Group30Var1_static(&temp, buff);
}

Group30Var1 Apply_in_ConvertGroup30Var1_static(Analog* src, uint8_t Overrange)
{
  Group30Var1 target;
  Group30Var1_in_Group30Var1(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint32((uint32_t)(src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;

#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Apply_in_ConvertGroup30Var1_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*src.value= "<<std::hex<<(double)(src->tTypedMeasurement_for_Double64).value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*target.value= "<<std::hex<<(uint32_t)(target.value)<<'\n';
  decrement_stack_info();
#endif
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

// ------- Group30Var2 -------

void Group30Var2_in_Group30Var2(Group30Var2 *pGroup30Var2)
{
  pGroup30Var2->flags = 0;
  pGroup30Var2->value = 0;
}

boolean Read_in_Group30Var2_static(RSeq_for_Uint16_t* buffer, Group30Var2* output)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Read_in_Group30Var2_static1"<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->flags= "<<(uint16_t)output->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->value= "<<(uint16_t)output->value<<'\n';
  decrement_stack_info();
#endif
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value));
}

boolean Write_in_Group30Var2_static(Group30Var2* arg, WSeq_for_Uint16_t* buffer)
{
#ifdef  LOG_INFO
  std::cout<<""<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_Group30Var2_static"<<'\n';

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*arg->flags= "<<std::hex<<(uint16_t)arg->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*arg->value= "<<std::hex<<(uint16_t)arg->value<<'\n';
  decrement_stack_info();
#endif
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value);
}

boolean ReadTarget_in_Group30Var2_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group30Var2 value;
  Group30Var2_in_Group30Var2(&value);
////  if(Read(buff, value))
  if(Read_in_Group30Var2_static(buff, &value))
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

boolean WriteTarget_in_Group30Var2_static(Analog* value, WSeq_for_Uint16_t* buff)
{
////  return Group30Var2::Write(ConvertGroup30Var2::Apply(value), buff);
//typedef ConvertQVRangeCheck<Group30Var2, Analog, 0x20> ConvertGroup30Var2;
  Group30Var2 temp = Apply_in_ConvertGroup30Var2_static(value, 0x20);
  return Write_in_Group30Var2_static(&temp, buff);
}

Group30Var2 Apply_in_ConvertGroup30Var2_static(Analog* src, uint8_t Overrange)
{
  Group30Var2 target;
  Group30Var2_in_Group30Var2(&target);
////        auto overrange = DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  boolean overrange = Apply_in_DownSampling_for_uint16((uint16_t)(src->tTypedMeasurement_for_Double64).value, (uint16_t*)&(target.value));

////        t.flags = overrange ? Overrange : 0;
  target.flags = overrange ? Overrange : 0;
////        t.flags |= src.flags.value;
  target.flags |= (src->tTypedMeasurement_for_Double64).mMeasurement.flags.value;
  return target;
}

// ------- Group30Var3 -------

void Group30Var3_in_Group30Var3(Group30Var3 *pGroup30Var3)
{
  pGroup30Var3->value = 0;
}

boolean Read_in_Group30Var3_static(RSeq_for_Uint16_t* buffer, Group30Var3* output)
{
////  return LittleEndian::read(buffer, output.value);
  return  read_from_in_UInt32_static(buffer, (uint32_t*)&(output->value));
}

boolean Write_in_Group30Var3_static(Group30Var3* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.value);
  return  write_to_in_UInt32_static(buffer, arg->value);
}

boolean ReadTarget_in_Group30Var3_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group30Var3 value;
  Group30Var3_in_Group30Var3(&value);
////  if(Read(buff, value))
  if(Read_in_Group30Var3_static(buff, &value))
  {
////    output = AnalogFactory::From(value.value);
    Analog temp = From_in_AnalogFactory_staticOver1(value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group30Var3_static(Analog* value, WSeq_for_Uint16_t* buff)
{
////  return Group30Var3::Write(ConvertGroup30Var3::Apply(value), buff);
//typedef ConvertVRangeCheck<Group30Var3, Analog> ConvertGroup30Var3;
  Group30Var3 temp = Apply_in_ConvertGroup30Var3_static(value);
  return Write_in_Group30Var3_static(&temp, buff);
}

Group30Var3 Apply_in_ConvertGroup30Var3_static(Analog* src)
{
  Group30Var3 target;
  Group30Var3_in_Group30Var3(&target);
////        DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint32((uint32_t)(src->tTypedMeasurement_for_Double64).value, (uint32_t*)&target.value);
  return target;
}
////template<class Target, class Source> struct ConvertVRangeCheck : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
////        return t;
////    }
////};

// ------- Group30Var4 -------

void Group30Var4_in_Group30Var4(Group30Var4 *pGroup30Var4)
{
  pGroup30Var4->value = 0;
}

boolean Read_in_Group30Var4_static(RSeq_for_Uint16_t* buffer, Group30Var4* output)
{
////  return LittleEndian::read(buffer, output.value);
  return  read_from_in_UInt16_static(buffer, (uint16_t*)&(output->value));
}

boolean Write_in_Group30Var4_static(Group30Var4* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.value);
  return  write_to_in_UInt16_static(buffer, arg->value);
}

boolean ReadTarget_in_Group30Var4_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group30Var4 value;
  Group30Var4_in_Group30Var4(&value);
////  if(Read(buff, value))
  if(Read_in_Group30Var4_static(buff, &value))
  {
////    output = AnalogFactory::From(value.value);
    Analog temp = From_in_AnalogFactory_staticOver1(value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group30Var4_static(Analog* value, WSeq_for_Uint16_t* buff)
{
//typedef ConvertVRangeCheck<Group30Var4, Analog> ConvertGroup30Var4;
////  return Group30Var4::Write(ConvertGroup30Var4::Apply(value), buff);
  Group30Var4 temp = Apply_in_ConvertGroup30Var4_static(value);
  return Write_in_Group30Var4_static(&temp, buff);
}

Group30Var4 Apply_in_ConvertGroup30Var4_static(Analog* src)
{
  Group30Var4 target;
  Group30Var4_in_Group30Var4(&target);
////        DownSampling<typename Source::Type, typename Target::ValueType>::Apply(src.value, t.value);
  Apply_in_DownSampling_for_uint16((uint16_t)(src->tTypedMeasurement_for_Double64).value, (uint16_t*)&target.value);
  return target;
}

// ------- Group30Var5 -------

void Group30Var5_in_Group30Var5(Group30Var5 *pGroup30Var5)
{
  pGroup30Var5->flags = 0;
  pGroup30Var5->value = 0.0;
}

boolean Read_in_Group30Var5_static(RSeq_for_Uint16_t* buffer, Group30Var5* output)
{
////  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_Float32_static(buffer, &(output->value));
}

boolean Write_in_Group30Var5_static(Group30Var5* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_Float32_static(buffer, arg->value);
}

boolean ReadTarget_in_Group30Var5_static(RSeq_for_Uint16_t* buff, Analog* output)
{
  Group30Var5 value;
  Group30Var5_in_Group30Var5(&value);
////  if(Read(buff, value))
  if(Read_in_Group30Var5_static(buff, &value))
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

boolean WriteTarget_in_Group30Var5_static(Analog* value, WSeq_for_Uint16_t* buff)
{
////  return Group30Var5::Write(ConvertGroup30Var5::Apply(value), buff);
////typedef ConvertQVRangeCheck<Group30Var5, Analog, 0x20> ConvertGroup30Var5;
  Group30Var5 temp = Apply_in_ConvertGroup30Var5_static(value, 0x20);
  return Write_in_Group30Var5_static(&temp, buff);
}

Group30Var5 Apply_in_ConvertGroup30Var5_static(Analog* src, uint8_t Overrange)
{
  Group30Var5 target;
  Group30Var5_in_Group30Var5(&target);
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

// ------- Group30Var6 -------

////void Group30Var6_in_Group30Var6(Group30Var6 *pGroup30Var6)
////{
////  pGroup30Var6->flags = 0;
////  pGroup30Var6->value = 0.0;
////}
////
////boolean Read_in_Group30Var6_static(RSeq_for_Uint16_t* buffer, Group30Var6* output)
////{
////////  return LittleEndian::read(buffer, output.flags, output.value);
////    return read_from_in_UInt8_static(buffer, &(output->flags)) &&
////           read_from_in_Double64_static(buffer, &(output->value));
////}
////
////bool Group30Var6::Write(const Group30Var6& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
////
////bool Group30Var6::ReadTarget(rseq_t& buff, Analog& output)
////{
////  Group30Var6 value;
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
////bool Group30Var6::WriteTarget(const Analog& value, ser4cpp::wseq_t& buff)
////{
////  return Group30Var6::Write(ConvertGroup30Var6::Apply(value), buff);
////}


////}

uint16_t Size_in_Group30Var5_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group30Var5_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 30, 5);
////  return GroupVariationID(30,5);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group30Var5_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group30Var5_static(),
      Size_in_Group30Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group30Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group30Var5_static);

  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group30Var4_static(void)
{
  return 2;
}

GroupVariationID ID_in_Group30Var4_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 30, 4);
////  return GroupVariationID(30,4);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group30Var4_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group30Var4_static(),
      Size_in_Group30Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group30Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group30Var4_static);

  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group30Var3_static(void)
{
  return 4;
}

GroupVariationID ID_in_Group30Var3_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 30, 3);
////  return GroupVariationID(2,1);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group30Var3_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group30Var3_static(),
      Size_in_Group30Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group30Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group30Var3_static);

  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group30Var2_static(void)
{
  return 3;
}

GroupVariationID ID_in_Group30Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 30, 2);
////  return GroupVariationID(30,2);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group30Var2_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group30Var2_static(),
      Size_in_Group30Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group30Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group30Var2_static);

  return dDNP3Serializer_for_Analog;
}

uint16_t Size_in_Group30Var1_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group30Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 30, 1);
////  return GroupVariationID(30,1);
  return gGroupVariationID;
}

DNP3Serializer_for_Analog  Inst_in_Group30Var1_static(void)
{
  DNP3Serializer_for_Analog dDNP3Serializer_for_Analog;
  DNP3Serializer_for_Analog_in_DNP3Serializer_for_Analog(&dDNP3Serializer_for_Analog,
      ID_in_Group30Var1_static(),
      Size_in_Group30Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group30Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group30Var1_static);

  return dDNP3Serializer_for_Analog;
}
