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
#include "Group13.h"

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

Group13Var1 Apply_in_ConvertGroup13Var1_static(BinaryCommandEvent* ev);
Group13Var2 Apply_in_ConvertGroup13Var2_static(BinaryCommandEvent* ev);

// ------- Group13Var1 -------

void Group13Var1_in_Group13Var1(Group13Var1 *pGroup13Var1)
{
  pGroup13Var1->flags = 0;
}

////bool Group13Var1::Read(rseq_t& buffer, Group13Var1& output)
////{
////  return LittleEndian::read(buffer, output.flags);
////}
boolean Read_in_Group13Var1_static(RSeq_for_Uint16_t* buffer, Group13Var1* output)
{
//  return LittleEndian::read(buffer, output.flags);
  return read_from_in_UInt8_static(buffer, &(output->flags));
}

////bool Group13Var1::Write(const Group13Var1& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags);
////}
boolean Write_in_Group13Var1_static(Group13Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags);
  return write_to_in_UInt8_static(buffer, arg->flags);
}

////bool Group13Var1::ReadTarget(rseq_t& buff, BinaryCommandEvent& output)
////{
////  Group13Var1 value;
////  if(Read(buff, value))
////  {
////    output = BinaryCommandEventFactory::From(value.flags);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group13Var1_static(RSeq_for_Uint16_t* buff, BinaryCommandEvent* output)
{
  Group13Var1 value;
//  if(Read(buff, value))
  Group13Var1_in_Group13Var1(&value);
  if(Read_in_Group13Var1_static(buff, &value))
  {
    BinaryCommandEvent temp = From_in_BinaryCommandEventFactory_staticOver1(value.flags);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group13Var1::WriteTarget(const BinaryCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group13Var1::Write(ConvertGroup13Var1::Apply(value), buff);
////}
boolean WriteTarget_in_Group13Var1_static(BinaryCommandEvent* value, WSeq_for_Uint16_t* buff)
{
  Group13Var1 temp = Apply_in_ConvertGroup13Var1_static(value);
  return Write_in_Group13Var1_static(&temp, buff);
}

Group13Var1 Apply_in_ConvertGroup13Var1_static(BinaryCommandEvent* ev)
{
  Group13Var1 ret;
  Group13Var1_in_Group13Var1(&ret);
  ret.flags = GetFlags_in_BinaryCommandEvent(ev).value;
  return ret;
}
////struct ConvertGroup13Var1 : private StaticOnly
////{
////    static Group13Var1 Apply(const BinaryCommandEvent& ev)
////    {
////        Group13Var1 ret;
////        ret.flags = ev.GetFlags().value;
////        return ret;
////    }
////};


// ------- Group13Var2 -------

////Group13Var2::Group13Var2() : flags(0), time(0)
////{}
void Group13Var2_in_Group13Var2(Group13Var2 *pGroup13Var2)
{
  pGroup13Var2->flags = 0;
//// time(0)
  DNPTime_in_DNPTimeOver2(&(pGroup13Var2->timeDNPTime), 0);
}

////bool Group13Var2::Read(rseq_t& buffer, Group13Var2& output)
////{
////  return LittleEndian::read(buffer, output.flags, output.time);
////}
boolean Read_in_Group13Var2_static(RSeq_for_Uint16_t* buffer, Group13Var2* output)
{
////  return LittleEndian::read(buffer, output.flags, output.time);
  return read_from_in_UInt8_static(buffer, &(output->flags)) &&
         read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

////bool Group13Var2::Write(const Group13Var2& arg, ser4cpp::wseq_t& buffer)
////{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
////}
boolean Write_in_Group13Var2_static(Group13Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags, arg.time);
  return write_to_in_UInt8_static(buffer, arg->flags) &&
         write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

////bool Group13Var2::ReadTarget(rseq_t& buff, BinaryCommandEvent& output)
////{
////  Group13Var2 value;
////  if(Read(buff, value))
////  {
////    output = BinaryCommandEventFactory::From(value.flags, value.time);
////    return true;
////  }
////  else
////  {
////    return false;
////  }
////}
boolean ReadTarget_in_Group13Var2_static(RSeq_for_Uint16_t* buff, BinaryCommandEvent* output)
{
  Group13Var2 value;
////  if(Read(buff, value))
  Group13Var2_in_Group13Var2(&value);
  if(Read_in_Group13Var2_static(buff, &value))
  {
////    output = BinaryFactory::From(value.flags, value.time);
    BinaryCommandEvent temp = From_in_BinaryCommandEventFactory_staticOver2(value.flags, value.timeDNPTime);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group13Var2::WriteTarget(const BinaryCommandEvent& value, ser4cpp::wseq_t& buff)
////{
////  return Group13Var2::Write(ConvertGroup13Var2::Apply(value), buff);
////}
boolean WriteTarget_in_Group13Var2_static(BinaryCommandEvent* value, WSeq_for_Uint16_t* buff)
{
  Group13Var2 temp = Apply_in_ConvertGroup13Var2_static(value);
  return Write_in_Group13Var2_static(&temp, buff);
}

Group13Var2 Apply_in_ConvertGroup13Var2_static(BinaryCommandEvent* ev)
{
  Group13Var2 ret;
  Group13Var2_in_Group13Var2(&ret);
  ret.flags = GetFlags_in_BinaryCommandEvent(ev).value;
  ret.timeDNPTime = ev->timeDNPTime;
  return ret;
}

////struct ConvertGroup13Var2 : private StaticOnly
////{
////    static Group13Var2 Apply(const BinaryCommandEvent& ev)
////    {
////        Group13Var2 ret;
////        ret.flags = ev.GetFlags().value;
////        ret.time = ev.time;
////        return ret;
////    }
////};

////}

uint16_t Size_in_Group13Var1_static(void)
{
  return 1;
}

GroupVariationID ID_in_Group13Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 13, 1);
////  return GroupVariationID(13,1);
  return gGroupVariationID;
}

DNP3Serializer_for_BinaryCommandEvent  Inst_in_Group13Var1_static(void)
{
  DNP3Serializer_for_BinaryCommandEvent dDNP3Serializer_for_BinaryCommandEvent;
  DNP3Serializer_for_BinaryCommandEvent_in_DNP3Serializer_for_BinaryCommandEvent(&dDNP3Serializer_for_BinaryCommandEvent,
      ID_in_Group13Var1_static(),
      Size_in_Group13Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group13Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group13Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_BinaryCommandEvent;
}

uint16_t Size_in_Group13Var2_static(void)
{
  return 7;
}

GroupVariationID ID_in_Group13Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 13, 2);
////  return GroupVariationID(13,2);
  return gGroupVariationID;
}

DNP3Serializer_for_BinaryCommandEvent  Inst_in_Group13Var2_static(void)
{
  DNP3Serializer_for_BinaryCommandEvent dDNP3Serializer_for_BinaryCommandEvent;
  DNP3Serializer_for_BinaryCommandEvent_in_DNP3Serializer_for_BinaryCommandEvent(&dDNP3Serializer_for_BinaryCommandEvent,
      ID_in_Group13Var2_static(),
      Size_in_Group13Var2_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group13Var2_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group13Var2_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_BinaryCommandEvent;
}
