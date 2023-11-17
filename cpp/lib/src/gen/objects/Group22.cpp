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
#include "Group22.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"

#include "MeasurementFactory.h"
//#include "WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

////using namespace ser4cpp;

////namespace opendnp3 {

Group22Var1 Apply_in_ConvertGroup22Var1_static(Counter* src);
Group22Var2 Apply_in_ConvertGroup22Var2_static(Counter* src);
Group22Var5 Apply_in_ConvertGroup22Var5_static(Counter* src);
Group22Var6 Apply_in_ConvertGroup22Var6_static(Counter* src);

// ------- Group22Var1 -------

////Group22Var1::Group22Var1() : flags(0), value(0)
////{}
void Group22Var1_in_Group22Var1(Group22Var1 *pGroup22Var1)
{
  pGroup22Var1->flags = 0;
  pGroup22Var1->value = 0;
}

////bool Group22Var1::Read(rseq_t& buffer, Group22Var1& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group22Var1_static(RSeq_for_Uint16_t* buffer, Group22Var1* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, &(output->value));
}

////bool Group22Var1::Write(const Group22Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group22Var1_static(Group22Var1* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value);
}

////bool Group22Var1::ReadTarget(rseq_t& buff, Counter& output)
////{
////  Group22Var1 value;
////  if(Read(buff, value))
////  {
////    output = CounterFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group22Var1_static(RSeq_for_Uint16_t* buff, Counter* output)
{
  Group22Var1 value;
//  if(Read(buff, value))
  Group22Var1_in_Group22Var1(&value);
  if(Read_in_Group22Var1_static(buff, &value))
  {
    Counter temp = From_in_CounterFactory_staticOver2(value.flags, value.value);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group22Var1::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
////{
////  return Group22Var1::Write(ConvertGroup22Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group22Var1_static(Counter* value, WSeq_for_Uint16_t* buff)
{
////  return Group2Var1::Write(ConvertGroup2Var1::Apply(value), buff);
//typedef ConvertQV<Group22Var1, Counter> ConvertGroup22Var1;
  Group22Var1 temp = Apply_in_ConvertGroup22Var1_static(value);
  return Write_in_Group22Var1_static(&temp, buff);
}

Group22Var1 Apply_in_ConvertGroup22Var1_static(Counter* src)
{
  Group22Var1 target;
  Group22Var1_in_Group22Var1(&target);
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

// ------- Group22Var2 -------

////Group22Var2::Group22Var2() : flags(0), value(0)
////{}
void Group22Var2_in_Group22Var2(Group22Var2 *pGroup22Var2)
{
  pGroup22Var2->flags = 0;
  pGroup22Var2->value = 0;
}

////bool Group22Var2::Read(rseq_t& buffer, Group22Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value);
////}
boolean Read_in_Group22Var2_static(RSeq_for_Uint16_t* buffer, Group22Var2* output)
{
//  return LittleEndian::read(buffer, output.flags, output.value);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, &(output->value));
}

////bool Group22Var2::Write(const Group22Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value);
////}
boolean Write_in_Group22Var2_static(Group22Var2* arg, WSeq_for_Uint16_t* buffer)
{
//  return LittleEndian::write(buffer, arg.flags, arg.value);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value);
}

////bool Group22Var2::ReadTarget(rseq_t& buff, Counter& output)
////{
////  Group22Var2 value;
////  if(Read(buff, value))
////  {
////    output = CounterFactory::From(value.flags, value.value);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group22Var2_static(RSeq_for_Uint16_t* buff, Counter* output)
{
  Group22Var2 value;
  Group22Var2_in_Group22Var2(&value);
//  if(Read(buff, value))
  if(Read_in_Group22Var2_static(buff, &value))
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

////bool Group22Var2::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
////{
////  return Group22Var2::Write(ConvertGroup22Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group22Var2_static(Counter* value, WSeq_for_Uint16_t* buff)
{
//  return Group20Var2::Write(ConvertGroup20Var2::Apply(value), buff);
//typedef ConvertQVandTruncate<Group22Var2, Counter> ConvertGroup22Var2;
  Group22Var2 temp = Apply_in_ConvertGroup22Var2_static(value);
  return Write_in_Group22Var2_static(&temp, buff);
}

Group22Var2 Apply_in_ConvertGroup22Var2_static(Counter* src)
{
  Group22Var2 target;
  Group22Var2_in_Group22Var2(&target);
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

// ------- Group22Var5 -------

////Group22Var5::Group22Var5() : flags(0), value(0), time(0)
////{}
void Group22Var5_in_Group22Var5(Group22Var5 *pGroup22Var5)
{
  pGroup22Var5->flags = 0;
  pGroup22Var5->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup22Var5->timeDNPTime), 0);
}

////bool Group22Var5::Read(rseq_t& buffer, Group22Var5& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group22Var5_static(RSeq_for_Uint16_t* buffer, Group22Var5* output)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Read_in_Group22Var5_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->flags= "<<(uint32_t)output->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->value= "<<(uint32_t)output->value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(output->timeDNPTime).value= "<<(uint32_t)(output->timeDNPTime).value<<'\n';
  decrement_stack_info();
#endif
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt32_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group22Var5::Write(const Group22Var5& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group22Var5_static(Group22Var5* arg, WSeq_for_Uint16_t* buffer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_Group22Var5_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->flags= "<<(uint32_t)arg->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->value= "<<(uint32_t)arg->value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(output->timeDNPTime).value= "<<(uint32_t)(arg->timeDNPTime).value<<'\n';
  decrement_stack_info();
#endif
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt32_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group22Var5::ReadTarget(rseq_t& buff, Counter& output)
////{
////  Group22Var5 value;
////  if(Read(buff, value))
////  {
////    output = CounterFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group22Var5_static(RSeq_for_Uint16_t* buff, Counter* output)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ReadTarget_in_Group22Var5_static1"<<'\n';
  inspect_RSeq(buff);
  decrement_stack_info();
#endif
  Group22Var5 value;
  Group22Var5_in_Group22Var5(&value);
////  if(Read(buff, value))
  if(Read_in_Group22Var5_static(buff, &value))
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

////bool Group22Var5::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
////{
////  return Group22Var5::Write(ConvertGroup22Var5::Apply(value), buff);
////}
boolean WriteTarget_in_Group22Var5_static(Counter* value, WSeq_for_Uint16_t* buff)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteTarget_in_Group22Var5_static1"<<'\n';
  decrement_stack_info();
#endif
//typedef ConvertQVT<Group22Var5, Counter> ConvertGroup22Var5;
  Group22Var5 temp = Apply_in_ConvertGroup22Var5_static(value);
  return Write_in_Group22Var5_static(&temp, buff);
}

Group22Var5 Apply_in_ConvertGroup22Var5_static(Counter* src)
{
  Group22Var5 target;
  Group22Var5_in_Group22Var5(&target);
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

// ------- Group22Var6 -------

////Group22Var6::Group22Var6() : flags(0), value(0), time(0)
////{}
void Group22Var6_in_Group22Var6(Group22Var6 *pGroup22Var6)
{
  pGroup22Var6->flags = 0;
  pGroup22Var6->value = 0;
  DNPTime_in_DNPTimeOver2(&(pGroup22Var6->timeDNPTime), 0);
}

////bool Group22Var6::Read(rseq_t& buffer, Group22Var6& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.value, output.time);
////}
boolean Read_in_Group22Var6_static(RSeq_for_Uint16_t* buffer, Group22Var6* output)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Read_in_Group22Var6_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->flags= "<<(uint32_t)output->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->value= "<<(uint32_t)output->value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(output->timeDNPTime).value= "<<(uint32_t)(output->timeDNPTime).value<<'\n';
  decrement_stack_info();
#endif
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt16_static(buffer, &(output->value)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group22Var6::Write(const Group22Var6& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
////}
boolean Write_in_Group22Var6_static(Group22Var6* arg, WSeq_for_Uint16_t* buffer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Write_in_Group22Var6_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->flags= "<<(uint32_t)arg->flags<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*output->value= "<<(uint32_t)arg->value<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*(output->timeDNPTime).value= "<<(uint32_t)(arg->timeDNPTime).value<<'\n';
  decrement_stack_info();
#endif
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt16_static(buffer, arg->value) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group22Var6::ReadTarget(rseq_t& buff, Counter& output)
////{
////  Group22Var6 value;
////  if(Read(buff, value))
////  {
////    output = CounterFactory::From(value.flags, value.value, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group22Var6_static(RSeq_for_Uint16_t* buff, Counter* output)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"ReadTarget_in_Group22Var6_static1"<<'\n';
  inspect_RSeq(buff);
  decrement_stack_info();
#endif
  Group22Var6 value;
  Group22Var6_in_Group22Var6(&value);
//  if(Read(buff, value))
  if(Read_in_Group22Var6_static(buff, &value))
  {
//    Counter From_in_CounterFactory_staticOver3(uint8_t flags, uint32_t count, DNPTime timeDNPTime);
    Counter temp = From_in_CounterFactory_staticOver3(value.flags, value.value, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group22Var6::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
////{
////  return Group22Var6::Write(ConvertGroup22Var6::Apply(value), buff);
////}
boolean WriteTarget_in_Group22Var6_static(Counter* value, WSeq_for_Uint16_t* buff)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"WriteTarget_in_Group22Var6_static1"<<'\n';
  decrement_stack_info();
#endif
//typedef ConvertQVTandTruncate<Group22Var6, Counter> ConvertGroup22Var6;
  Group22Var6 temp = Apply_in_ConvertGroup22Var6_static(value);
  return Write_in_Group22Var6_static(&temp, buff);
}

Group22Var6 Apply_in_ConvertGroup22Var6_static(Counter* src)
{
  Group22Var6 target;
  Group22Var6_in_Group22Var6(&target);
  target.flags = (src->tTypedMeasurement_for_Uint32).mMeasurement.flags.value;
  target.value = (uint16_t)((src->tTypedMeasurement_for_Uint32).value);
  target.timeDNPTime.value = (src->tTypedMeasurement_for_Uint32).mMeasurement.timeDNPTime.value;
  return target;
}
////template<class Target, class Source> struct ConvertQVTandTruncate : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        t.value = static_cast<typename Target::ValueType>(src.value);
////        t.time = src.time;
////        return t;
////    }
////};

////}
GroupVariationID ID_in_Group22Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 0);
//// return GroupVariationID(22,0);
  return gGroupVariationID;
}

uint16_t Size_in_Group22Var1_static(void)
{
  return 5;
}

GroupVariationID ID_in_Group22Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 1);
////  return GroupVariationID(22,1);
  return gGroupVariationID;
}

DNP3Serializer_for_Counter  Inst_in_Group22Var1_static(void)
{
  DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
  DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
      ID_in_Group22Var1_static(),
      Size_in_Group22Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group22Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group22Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Counter;
}

uint16_t Size_in_Group22Var2_static(void)
{
  return 3;
}

GroupVariationID ID_in_Group22Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 2);
////  return GroupVariationID(22,2);
  return gGroupVariationID;
}

DNP3Serializer_for_Counter  Inst_in_Group22Var2_static(void)
{
  DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
  DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
      ID_in_Group22Var2_static(),
      Size_in_Group22Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group22Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group22Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Counter;
}

uint16_t Size_in_Group22Var5_static(void)
{
  return 11;
}

GroupVariationID ID_in_Group22Var5_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 5);
////  return GroupVariationID(22,5);
  return gGroupVariationID;
}

DNP3Serializer_for_Counter  Inst_in_Group22Var5_static(void)
{
  DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
  DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
      ID_in_Group22Var5_static(),
      Size_in_Group22Var5_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group22Var5_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group22Var5_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Counter;
}

uint16_t Size_in_Group22Var6_static(void)
{
  return 9;
}

GroupVariationID ID_in_Group22Var6_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 22, 6);
////  return GroupVariationID(22,6);
  return gGroupVariationID;
}

DNP3Serializer_for_Counter  Inst_in_Group22Var6_static(void)
{
  DNP3Serializer_for_Counter dDNP3Serializer_for_Counter;
  DNP3Serializer_for_Counter_in_DNP3Serializer_for_Counter(&dDNP3Serializer_for_Counter,
      ID_in_Group22Var6_static(),
      Size_in_Group22Var6_static(),
////                   typename Serializer<T>::read_func_t read_func,
      &ReadTarget_in_Group22Var6_static,
////                   typename Serializer<T>::write_func_t write_func)
      &WriteTarget_in_Group22Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_Counter;
}


