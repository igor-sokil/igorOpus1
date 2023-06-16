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

#include "Group22.h"

#include "app/parsing/DNPTimeParsing.h"
#include <ser4cpp/serialization/LittleEndian.h>
#include "app/MeasurementFactory.h"
#include "app/WriteConversions.h"

using namespace ser4cpp;

namespace opendnp3 {

// ------- Group22Var1 -------

Group22Var1::Group22Var1() : flags(0), value(0)
{}

bool Group22Var1::Read(rseq_t& buffer, Group22Var1& output)
{
  return LittleEndian::read(buffer, output.flags, output.value);
}

bool Group22Var1::Write(const Group22Var1& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value);
}

bool Group22Var1::ReadTarget(rseq_t& buff, Counter& output)
{
  Group22Var1 value;
  if(Read(buff, value))
  {
    output = CounterFactory::From(value.flags, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group22Var1::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
{
  return Group22Var1::Write(ConvertGroup22Var1::Apply(value), buff);
}

// ------- Group22Var2 -------

Group22Var2::Group22Var2() : flags(0), value(0)
{}

bool Group22Var2::Read(rseq_t& buffer, Group22Var2& output)
{
  return LittleEndian::read(buffer, output.flags, output.value);
}

bool Group22Var2::Write(const Group22Var2& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value);
}

bool Group22Var2::ReadTarget(rseq_t& buff, Counter& output)
{
  Group22Var2 value;
  if(Read(buff, value))
  {
    output = CounterFactory::From(value.flags, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group22Var2::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
{
  return Group22Var2::Write(ConvertGroup22Var2::Apply(value), buff);
}

// ------- Group22Var5 -------

Group22Var5::Group22Var5() : flags(0), value(0), time(0)
{}

bool Group22Var5::Read(rseq_t& buffer, Group22Var5& output)
{
  return LittleEndian::read(buffer, output.flags, output.value, output.time);
}

bool Group22Var5::Write(const Group22Var5& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
}

bool Group22Var5::ReadTarget(rseq_t& buff, Counter& output)
{
  Group22Var5 value;
  if(Read(buff, value))
  {
    output = CounterFactory::From(value.flags, value.value, value.time);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group22Var5::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
{
  return Group22Var5::Write(ConvertGroup22Var5::Apply(value), buff);
}

// ------- Group22Var6 -------

Group22Var6::Group22Var6() : flags(0), value(0), time(0)
{}

bool Group22Var6::Read(rseq_t& buffer, Group22Var6& output)
{
  return LittleEndian::read(buffer, output.flags, output.value, output.time);
}

bool Group22Var6::Write(const Group22Var6& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
}

bool Group22Var6::ReadTarget(rseq_t& buff, Counter& output)
{
  Group22Var6 value;
  if(Read(buff, value))
  {
    output = CounterFactory::From(value.flags, value.value, value.time);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group22Var6::WriteTarget(const Counter& value, ser4cpp::wseq_t& buff)
{
  return Group22Var6::Write(ConvertGroup22Var6::Apply(value), buff);
}


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
                   &WriteTarget_in_Group26Var6_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_Counter;
}
