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

#include "Group42.h"

#include "app/parsing/DNPTimeParsing.h"
#include <ser4cpp/serialization/LittleEndian.h>
#include "app/MeasurementFactory.h"
#include "app/WriteConversions.h"

using namespace ser4cpp;

namespace opendnp3 {

// ------- Group42Var1 -------

Group42Var1::Group42Var1() : flags(0), value(0)
{}

bool Group42Var1::Read(rseq_t& buffer, Group42Var1& output)
{
  return LittleEndian::read(buffer, output.flags, output.value);
}

bool Group42Var1::Write(const Group42Var1& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value);
}

bool Group42Var1::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var1 value;
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

bool Group42Var1::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var1::Write(ConvertGroup42Var1::Apply(value), buff);
}

// ------- Group42Var2 -------

Group42Var2::Group42Var2() : flags(0), value(0)
{}

bool Group42Var2::Read(rseq_t& buffer, Group42Var2& output)
{
  return LittleEndian::read(buffer, output.flags, output.value);
}

bool Group42Var2::Write(const Group42Var2& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value);
}

bool Group42Var2::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var2 value;
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

bool Group42Var2::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var2::Write(ConvertGroup42Var2::Apply(value), buff);
}

// ------- Group42Var3 -------

Group42Var3::Group42Var3() : flags(0), value(0), time(0)
{}

bool Group42Var3::Read(rseq_t& buffer, Group42Var3& output)
{
  return LittleEndian::read(buffer, output.flags, output.value, output.time);
}

bool Group42Var3::Write(const Group42Var3& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
}

bool Group42Var3::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var3 value;
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

bool Group42Var3::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var3::Write(ConvertGroup42Var3::Apply(value), buff);
}

// ------- Group42Var4 -------

Group42Var4::Group42Var4() : flags(0), value(0), time(0)
{}

bool Group42Var4::Read(rseq_t& buffer, Group42Var4& output)
{
  return LittleEndian::read(buffer, output.flags, output.value, output.time);
}

bool Group42Var4::Write(const Group42Var4& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
}

bool Group42Var4::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var4 value;
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

bool Group42Var4::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var4::Write(ConvertGroup42Var4::Apply(value), buff);
}

// ------- Group42Var5 -------

Group42Var5::Group42Var5() : flags(0), value(0.0)
{}

bool Group42Var5::Read(rseq_t& buffer, Group42Var5& output)
{
  return LittleEndian::read(buffer, output.flags, output.value);
}

bool Group42Var5::Write(const Group42Var5& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value);
}

bool Group42Var5::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var5 value;
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

bool Group42Var5::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var5::Write(ConvertGroup42Var5::Apply(value), buff);
}

// ------- Group42Var6 -------

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

// ------- Group42Var7 -------

Group42Var7::Group42Var7() : flags(0), value(0.0), time(0)
{}

bool Group42Var7::Read(rseq_t& buffer, Group42Var7& output)
{
  return LittleEndian::read(buffer, output.flags, output.value, output.time);
}

bool Group42Var7::Write(const Group42Var7& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.value, arg.time);
}

bool Group42Var7::ReadTarget(rseq_t& buff, AnalogOutputStatus& output)
{
  Group42Var7 value;
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

bool Group42Var7::WriteTarget(const AnalogOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group42Var7::Write(ConvertGroup42Var7::Apply(value), buff);
}

// ------- Group42Var8 -------

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

