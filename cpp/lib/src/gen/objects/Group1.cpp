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

////#include "Group1.h"
////
////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"

#include "header.h"
#include "Group1.h"

//#include "parsing/DNPTimeParsing.h"
//#include <ser4cpp/serialization/LittleEndian.h>
#include "MeasurementFactory.h"
//#include "WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"
Group1Var2 Apply_in_ConvertGroup1Var2_static(Binary* src);
////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group1Var2 -------

void Group1Var2_in_Group1Var2(Group1Var2 *pGroup1Var2)
{
  pGroup1Var2->flags = 0;
}

////bool Read_in_Group1Var2(rseq_t& buffer, Group1Var2& output)
boolean Read_in_Group1Var2_static(RSeq_for_Uint16_t* buffer, Group1Var2* output)
{
////  return LittleEndian::read(buffer, output.flags);
//  return read1Byte_in_LittleEndian(buffer, output->flags);
  return read_from_in_UInt8_static(buffer, &(output->flags));
}

////bool Group1Var2::Write(const Group1Var2& arg, ser4cpp::wseq_t& buffer)
boolean Write_in_Group1Var2_static(Group1Var2* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.flags);
//  return write1Byte_in_LittleEndian(buffer, arg->flags);
  return write_to_in_UInt8_static(buffer, arg->flags);
}

boolean ReadTarget_in_Group1Var2_static(RSeq_for_Uint16_t* buff, Binary* output)
{
  Group1Var2 value;
  Group1Var2_in_Group1Var2(&value);
  if(Read_in_Group1Var2_static(buff, &value))
  {
//    output = BinaryFactory::From(value.flags);
//   Binary From_in_BinaryFactory_staticOver1(uint8_t flags)
    Binary temp = From_in_BinaryFactory_staticOver1(value.flags);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

////bool Group1Var2::WriteTarget(const Binary& value, ser4cpp::wseq_t& buff)
boolean WriteTarget_in_Group1Var2_static(Binary* value, WSeq_for_Uint16_t* buff)
{
////  return Group1Var2::Write(ConvertGroup1Var2::Apply(value), buff);
//typedef ConvertQ<Group1Var2, Binary> ConvertGroup1Var2;
  Group1Var2 temp = Apply_in_ConvertGroup1Var2_static(value);
  return Write_in_Group1Var2_static(&temp, buff);
}

Group1Var2 Apply_in_ConvertGroup1Var2_static(Binary* src)
{
  Group1Var2 target;
  Group1Var2_in_Group1Var2(&target);
  target.flags = (src->tTypedMeasurement_for_Boolean).mMeasurement.flags.value;
  return target;
}
////template<class Target, class Source> struct ConvertQ : private StaticOnly
////{
////    static Target Apply(const Source& src)
////    {
////        Target t;
////        t.flags = src.flags.value;
////        return t;
////    }

////}

GroupVariationID ID_in_Group1Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 1, 0);
  return gGroupVariationID;//GroupVariationID(1,0);
}

GroupVariationID ID_in_Group1Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 1, 1);
  return gGroupVariationID;
////  return GroupVariationID(1,1);
}

GroupVariationID ID_in_Group1Var2_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 1, 2);
  return gGroupVariationID;
////  return GroupVariationID(1,2);
}

uint16_t Size_in_Group1Var2_static(void)
{
  return 1;
}

DNP3Serializer_for_Binary Inst_in_Group1Var2_static(void)
{
////    return DNP3Serializer<Binary>(ID_in_Group1Var0_static(), Size_in_Group1Var2_static(), &ReadTarget, &WriteTarget);
  DNP3Serializer_for_Binary dDNP3Serializer_for_Binary;
  DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(&dDNP3Serializer_for_Binary,
      ID_in_Group1Var0_static(),
      Size_in_Group1Var2_static(),
      &ReadTarget_in_Group1Var2_static, &WriteTarget_in_Group1Var2_static);
//    void DNP3Serializer_for_Binary_in_DNP3Serializer_for_Binary(DNP3Serializer_for_Binary *pDNP3Serializer_for_Binary,
//                   GroupVariationID id,
//                   uint16_t size,
//                    read_func_t_in_Serializer_for_Binary read_func,
//                    write_func_t_in_Serializer_for_Binary write_func);
  return dDNP3Serializer_for_Binary;
}
