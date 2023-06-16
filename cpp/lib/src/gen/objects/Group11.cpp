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

#include "Group11.h"

#include "app/parsing/DNPTimeParsing.h"
#include <ser4cpp/serialization/LittleEndian.h>
#include "app/MeasurementFactory.h"
#include "app/WriteConversions.h"

using namespace ser4cpp;

namespace opendnp3 {

// ------- Group11Var1 -------

Group11Var1::Group11Var1() : flags(0)
{}

bool Group11Var1::Read(rseq_t& buffer, Group11Var1& output)
{
  return LittleEndian::read(buffer, output.flags);
}

bool Group11Var1::Write(const Group11Var1& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags);
}

bool Group11Var1::ReadTarget(rseq_t& buff, BinaryOutputStatus& output)
{
  Group11Var1 value;
  if(Read(buff, value))
  {
    output = BinaryOutputStatusFactory::From(value.flags);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group11Var1::WriteTarget(const BinaryOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group11Var1::Write(ConvertGroup11Var1::Apply(value), buff);
}

// ------- Group11Var2 -------

Group11Var2::Group11Var2() : flags(0), time(0)
{}

bool Group11Var2::Read(rseq_t& buffer, Group11Var2& output)
{
  return LittleEndian::read(buffer, output.flags, output.time);
}

bool Group11Var2::Write(const Group11Var2& arg, ser4cpp::wseq_t& buffer)
{
  return LittleEndian::write(buffer, arg.flags, arg.time);
}

bool Group11Var2::ReadTarget(rseq_t& buff, BinaryOutputStatus& output)
{
  Group11Var2 value;
  if(Read(buff, value))
  {
    output = BinaryOutputStatusFactory::From(value.flags, value.time);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group11Var2::WriteTarget(const BinaryOutputStatus& value, ser4cpp::wseq_t& buff)
{
  return Group11Var2::Write(ConvertGroup11Var2::Apply(value), buff);
}


////}
  GroupVariationID ID_in_Group11Var0_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 11, 0);
//// return GroupVariationID(11,0);
 return gGroupVariationID;
}

 uint16_t Size_in_Group11Var1_static(void) 
{
 return 1; 
}

  GroupVariationID ID_in_Group11Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 11, 1);
////  return GroupVariationID(11,1); 
 return gGroupVariationID;
}

 DNP3Serializer_for_BinaryOutputStatus  Inst_in_Group11Var1_static(void)
{
   DNP3Serializer_for_BinaryOutputStatus dDNP3Serializer_for_BinaryOutputStatus;
   DNP3Serializer_for_BinaryOutputStatus_in_DNP3Serializer_for_BinaryOutputStatus(&dDNP3Serializer_for_BinaryOutputStatus,
                   ID_in_Group11Var1_static(),
                   Size_in_Group11Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   //void *read_func,// read_func_t_in_Serializer_for_Binary,
                   &ReadTarget_in_Group11Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
                   //void *write_func);//write_func_t_in_Serializer_for_Binary);
                   &WriteTarget_in_Group11Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_BinaryOutputStatus;
}

 uint16_t Size_in_Group11Var2_static(void) 
{
 return 7; 
}

  GroupVariationID ID_in_Group11Var2_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 11, 2);
////  return GroupVariationID(11,2); 
 return gGroupVariationID;
}

 DNP3Serializer_for_BinaryOutputStatus  Inst_in_Group11Var2_static(void)
{
   DNP3Serializer_for_BinaryOutputStatus dDNP3Serializer_for_BinaryOutputStatus;
   DNP3Serializer_for_BinaryOutputStatus_in_DNP3Serializer_for_BinaryOutputStatus(&dDNP3Serializer_for_BinaryOutputStatus,
                   ID_in_Group11Var2_static(),
                   Size_in_Group11Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   //void *read_func,// read_func_t_in_Serializer_for_Binary,
                   &ReadTarget_in_Group11Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
                   //void *write_func);//write_func_t_in_Serializer_for_Binary);
                   &WriteTarget_in_Group11Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_BinaryOutputStatus;
}
