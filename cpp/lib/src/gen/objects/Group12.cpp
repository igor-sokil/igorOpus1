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
#include "Group12.h"

////#include "app/parsing/DNPTimeParsing.h"
/////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"
#include "MeasurementFactory.h"
//#include "WriteConversions.h"
#include "SerializationTemplates.h"

#include "RSeq.h"
#include "WSeq.h"

Group12Var1 Apply_in_ConvertGroup12Var1_static(ControlRelayOutputBlock* crob);

////using namespace ser4cpp;

////namespace opendnp3 {

// ------- Group12Var1 -------
void Group12Var1_in_Group12Var1(Group12Var1 *pGroup12Var1)
{
  pGroup12Var1->code = 0;
  pGroup12Var1->count = 0;
  pGroup12Var1->onTime = 0;
  pGroup12Var1->offTime = 0;
  pGroup12Var1->status = 0;
}

boolean Read_in_Group12Var1_static(RSeq_for_Uint16_t* buffer, Group12Var1* output)
{
////  return LittleEndian::read(buffer, output.code, output.count, output.onTime, output.offTime, output.status);
  return read_from_in_UInt8_static(buffer, &(output->code)) &&
         read_from_in_UInt8_static(buffer, &(output->count)) &&
         read_from_in_UInt32_static(buffer, &(output->onTime)) &&
         read_from_in_UInt32_static(buffer, &(output->offTime)) &&
         read_from_in_UInt8_static(buffer, &(output->status));
}

boolean Write_in_Group12Var1_static(Group12Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.code, arg.count, arg.onTime, arg.offTime, arg.status);
  return write_to_in_UInt8_static(buffer, arg->code) &&
         write_to_in_UInt8_static(buffer, arg->count) &&
         write_to_in_UInt32_static(buffer, arg->onTime) &&
         write_to_in_UInt32_static(buffer, arg->offTime) &&
         write_to_in_UInt8_static(buffer, arg->status);
}

boolean ReadTarget_in_Group12Var1_static(RSeq_for_Uint16_t* buff, ControlRelayOutputBlock* output)
{
  Group12Var1 value;
////  if(Read(buff, value))
  Group12Var1_in_Group12Var1(&value);
  if(Read_in_Group12Var1_static(buff, &value))
  {
////    output = ControlRelayOutputBlockFactory::From(value.code, value.count, value.onTime, value.offTime, value.status);
    ControlRelayOutputBlock temp = From_in_ControlRelayOutputBlock_static(
                                     value.code, value.count, value.onTime, value.offTime, value.status);
    *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group12Var1_static(ControlRelayOutputBlock* value, WSeq_for_Uint16_t* buff)
{
////  return Group12Var1::Write(ConvertGroup12Var1::Apply(value), buff);
  Group12Var1 temp = Apply_in_ConvertGroup12Var1_static(value);
  return Write_in_Group12Var1_static(&temp, buff);
}

Group12Var1 Apply_in_ConvertGroup12Var1_static(ControlRelayOutputBlock* crob)
{
  Group12Var1 ret;
  Group12Var1_in_Group12Var1(&ret);
  ret.code = crob->rawCode;
  ret.count = crob->count;
  ret.onTime = crob->onTimeMS;
  ret.offTime = crob->offTimeMS;
////        ret.status = CommandStatusSpec::to_type(crob.status);
  ret.status = crob->status;
  return ret;
}

////struct ConvertGroup12Var1 : private StaticOnly
////{
////    static Group12Var1 Apply(const ControlRelayOutputBlock& crob)
////    {
////        Group12Var1 ret;
////        ret.code = crob.rawCode;
////        ret.count = crob.count;
////        ret.onTime = crob.onTimeMS;
////        ret.offTime = crob.offTimeMS;
////        ret.status = CommandStatusSpec::to_type(crob.status);
////        return ret;
////    }
////};


////}

GroupVariationID ID_in_Group12Var0_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 12, 0);
//// return GroupVariationID(12,0);
  return gGroupVariationID;
}

uint16_t Size_in_Group12Var1_static(void)
{
  return 11;
}

GroupVariationID ID_in_Group12Var1_static(void)
{
  GroupVariationID gGroupVariationID;
  GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 12, 1);
////  return GroupVariationID(12,1);
  return gGroupVariationID;
}

DNP3Serializer_for_ControlRelayOutputBlock  Inst_in_Group12Var1_static(void)
{
  DNP3Serializer_for_ControlRelayOutputBlock dDNP3Serializer_for_ControlRelayOutputBlock;
  DNP3Serializer_for_ControlRelayOutputBlock_in_DNP3Serializer_for_ControlRelayOutputBlock(&dDNP3Serializer_for_ControlRelayOutputBlock,
      ID_in_Group12Var1_static(),
      Size_in_Group12Var1_static(),
////                   typename Serializer<T>::read_func_t read_func,
      //void *read_func,// read_func_t_in_Serializer_for_Binary,
      &ReadTarget_in_Group12Var1_static,
////                   typename Serializer<T>::write_func_t write_func)
      //void *write_func);//write_func_t_in_Serializer_for_Binary);
      &WriteTarget_in_Group12Var1_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
  return dDNP3Serializer_for_ControlRelayOutputBlock;
}
