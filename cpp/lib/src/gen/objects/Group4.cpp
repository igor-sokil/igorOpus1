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

#include "Group4.h"

#include "app/parsing/DNPTimeParsing.h"
#include <ser4cpp/serialization/LittleEndian.h>
#include "app/MeasurementFactory.h"
#include "app/WriteConversions.h"

using namespace ser4cpp;

namespace opendnp3 {

// ------- Group4Var1 -------

Group4Var1::Group4Var1() : flags(0)
{}

bool Group4Var1::Read(rseq_t& buffer, Group4Var1& output)
{
  return LittleEndian::read(buffer, output.flags);
}

bool Group4Var1::Write(const Group4Var1& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags);
}

bool Group4Var1::ReadTarget(rseq_t& buff, DoubleBitBinary& output)
{
  Group4Var1 value;
  if(Read(buff, value))
  {
    output = DoubleBitBinaryFactory::From(value.flags);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group4Var1::WriteTarget(const DoubleBitBinary& value, ser4cpp::wseq_t& buff)
{
  return Group4Var1::Write(ConvertGroup4Var1::Apply(value), buff);
}

// ------- Group4Var2 -------

Group4Var2::Group4Var2() : flags(0), time(0)
{}

bool Group4Var2::Read(rseq_t& buffer, Group4Var2& output)
{
  return LittleEndian::read(buffer, output.flags, output.time);
}

bool Group4Var2::Write(const Group4Var2& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.time);
}

bool Group4Var2::ReadTarget(rseq_t& buff, DoubleBitBinary& output)
{
  Group4Var2 value;
  if(Read(buff, value))
  {
    output = DoubleBitBinaryFactory::From(value.flags, value.time);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group4Var2::WriteTarget(const DoubleBitBinary& value, ser4cpp::wseq_t& buff)
{
  return Group4Var2::Write(ConvertGroup4Var2::Apply(value), buff);
}

// ------- Group4Var3 -------

Group4Var3::Group4Var3() : flags(0), time(0)
{}

bool Group4Var3::Read(rseq_t& buffer, Group4Var3& output)
{
  return LittleEndian::read(buffer, output.flags, output.time);
}

bool Group4Var3::Write(const Group4Var3& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.time);
}

bool Group4Var3::ReadTarget(rseq_t& buff, DoubleBitBinary& output)
{
  Group4Var3 value;
  if(Read(buff, value))
  {
    output = DoubleBitBinaryFactory::From(value.flags, value.time);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group4Var3::WriteTarget(const DoubleBitBinary& value, ser4cpp::wseq_t& buff)
{
  return Group4Var3::Write(ConvertGroup4Var3::Apply(value), buff);
}


////}
  GroupVariationID ID_in_Group4Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 0);
//// return GroupVariationID(4,0);
 return gGroupVariationID;
}

 uint16_t Size_in_Group4Var1_static(void) 
{
 return 1; 
}

  GroupVariationID ID_in_Group4Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 1);
////  return GroupVariationID(4,1); 
 return gGroupVariationID;
}

 DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var1_static(void)
{
   DNP3Serializer_for_DoubleBitBinary dDNP3Serializer_for_DoubleBitBinary;
   DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(&dDNP3Serializer_for_DoubleBitBinary,
                   ID_in_Group4Var1_static(),
                   Size_in_Group4Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   //void *read_func,// read_func_t_in_Serializer_for_Binary,
                   &ReadTarget_in_Group4Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   //void *write_func);//write_func_t_in_Serializer_for_Binary);
                   &WriteTarget_in_Group4Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_DoubleBitBinary;
}

 uint16_t Size_in_Group4Var2_static(void) 
{
 return 7; 
}

  GroupVariationID ID_in_Group4Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 2);
////  return GroupVariationID(4,2); 
 return gGroupVariationID;
}

 DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var2_static(void)
{
   DNP3Serializer_for_DoubleBitBinary dDNP3Serializer_for_DoubleBitBinary;
   DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(&dDNP3Serializer_for_DoubleBitBinary,
                   ID_in_Group4Var2_static(),
                   Size_in_Group4Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   //void *read_func,// read_func_t_in_Serializer_for_Binary,
                   &ReadTarget_in_Group4Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
                   //void *write_func);//write_func_t_in_Serializer_for_Binary);
                   &WriteTarget_in_Group4Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_DoubleBitBinary;
}

 uint16_t Size_in_Group4Var3_static(void) 
{
 return 3; 
}

  GroupVariationID ID_in_Group4Var3_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 4, 3);
////  return GroupVariationID(4,3); 
 return gGroupVariationID;
}

 DNP3Serializer_for_DoubleBitBinary  Inst_in_Group4Var3_static(void)
{
   DNP3Serializer_for_DoubleBitBinary dDNP3Serializer_for_DoubleBitBinary;
   DNP3Serializer_for_DoubleBitBinary_in_DNP3Serializer_for_DoubleBitBinary(&dDNP3Serializer_for_DoubleBitBinary,
                   ID_in_Group4Var3_static(),
                   Size_in_Group4Var3_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   //void *read_func,// read_func_t_in_Serializer_for_Binary,
                   &ReadTarget_in_Group4Var3_static,
////                   typename Serializer<T>::write_func_t write_func)
                   //void *write_func);//write_func_t_in_Serializer_for_Binary);
                   &WriteTarget_in_Group4Var3_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_DoubleBitBinary;
}
