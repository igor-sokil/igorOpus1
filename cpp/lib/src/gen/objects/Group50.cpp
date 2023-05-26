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
#include "Group50.h"

////#include "app/parsing/DNPTimeParsing.h"
////#include <ser4cpp/serialization/LittleEndian.h>
////#include "app/MeasurementFactory.h"
////#include "app/WriteConversions.h"
#include "MeasurementFactory.h"
#include "SerializationTemplates.h"
#include "RSeq.h"
#include "WSeq.h"


////using namespace ser4cpp;

////namespace opendnp3 {
  Group50Var4 Apply_in_ConvertGroup50Var4_static(TimeAndInterval *value);

// ------- Group50Var1 -------

void Group50Var1_in_Group50Var1(Group50Var1 *pGroup50Var1)
{
//// : time(0)
  DNPTime_in_DNPTimeOver2(&(pGroup50Var1->timeDNPTime), 0);
}

boolean Read_in_Group50Var1_static(RSeq_for_Uint16_t* buffer, Group50Var1* output)
{
////  return LittleEndian::read(buffer, output.time);
    return read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

boolean Write_in_Group50Var1_static(Group50Var1* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.time);
     return  write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

// ------- Group50Var3 -------

void Group50Var3_in_Group50Var3(Group50Var3 *pGroup50Var3)
{
//// : time(0)
  DNPTime_in_DNPTimeOver2(&(pGroup50Var3->timeDNPTime), 0);
}

boolean Read_in_Group50Var3_static(RSeq_for_Uint16_t* buffer, Group50Var3* output)
{
////  return LittleEndian::read(buffer, output.time);
    return read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value));
}

boolean Write_in_Group50Var3_static(Group50Var3* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.time);
     return  write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value);
}

// ------- Group50Var4 -------

void Group50Var4_in_Group50Var4(Group50Var4 *pGroup50Var4)
{
// : time(0), interval(0), units(0)
  DNPTime_in_DNPTimeOver2(&(pGroup50Var4->timeDNPTime), 0);
  pGroup50Var4->interval = 0;
  pGroup50Var4->units = 0;
}

boolean Read_in_Group50Var4_static(RSeq_for_Uint16_t* buffer, Group50Var4* output)
{
////  return LittleEndian::read(buffer, output.time, output.interval, output.units);
     return read_from_in_UInt48_static(buffer, &((output->timeDNPTime).value)) &&
            read_from_in_UInt32_static(buffer, &(output->interval)) &&
            read_from_in_UInt8_static(buffer, &(output->units));
}

boolean Write_in_Group50Var4_static(Group50Var4* arg, WSeq_for_Uint16_t* buffer)
{
////  return LittleEndian::write(buffer, arg.time, arg.interval, arg.units);
     return  write_to_in_UInt48_static(buffer, (arg->timeDNPTime).value) &&
             write_to_in_UInt32_static(buffer, arg->interval) &&
             write_to_in_UInt8_static(buffer, arg->units);
}

boolean ReadTarget_in_Group50Var4_static(RSeq_for_Uint16_t* buff, TimeAndInterval* output)
{
  Group50Var4 value;
////  if(Read(buff, value))
  Group50Var4_in_Group50Var4(&value);
  if(Read_in_Group50Var4_static(buff, &value))
  {
////    output = TimeAndIntervalFactory::From(value.time, value.interval, value.units);
   TimeAndInterval temp = From_in_TimeAndIntervalFactory_static(value.timeDNPTime, value.interval, value.units);
   *output = temp;
    return true;
  }
  else
  {
    return false;
  }
}

boolean WriteTarget_in_Group50Var4_static(TimeAndInterval* value, WSeq_for_Uint16_t* buff)
{
////  return Group50Var4::Write(ConvertGroup50Var4::Apply(value), buff);
  Group50Var4 temp = Apply_in_ConvertGroup50Var4_static(value);
  return Write_in_Group50Var4_static(&temp, buff);
}

  Group50Var4 Apply_in_ConvertGroup50Var4_static(TimeAndInterval *value)
{
        Group50Var4 ret;
        ret.timeDNPTime = value->timeDNPTime;
        ret.interval = value->interval;
        ret.units = value->units;
        return ret;
}

////struct ConvertGroup50Var4 : private StaticOnly
////{
////    static Group50Var4 Apply(const TimeAndInterval& value)
////    {
////        Group50Var4 ret;
////        ret.time = value.time;
////        ret.interval = value.interval;
////        ret.units = value.units;
////        return ret;
////    }
////};


////}

 uint16_t Size_in_Group50Var1_static(void) 
{
 return 6; 
}

  GroupVariationID ID_in_Group50Var1_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 50, 1);
////  return GroupVariationID(50,1); 
 return gGroupVariationID;
}

 uint16_t Size_in_Group50Var3_static(void) 
{
 return 6; 
}

  GroupVariationID ID_in_Group50Var3_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 50, 3);
////  return GroupVariationID(50,3); 
 return gGroupVariationID;
}

 uint16_t Size_in_Group50Var4_static(void) 
{
 return 11; 
}

  GroupVariationID ID_in_Group50Var4_static(void)
{
 GroupVariationID gGroupVariationID;
 GroupVariationID_in_GroupVariationIDOver2(&gGroupVariationID, 50, 4);
////  return GroupVariationID(50,4); 
 return gGroupVariationID;
}

 DNP3Serializer_for_TimeAndInterval  Inst_in_Group50Var4_static(void)
{
   DNP3Serializer_for_TimeAndInterval dDNP3Serializer_for_TimeAndInterval;
   DNP3Serializer_for_TimeAndInterval_in_DNP3Serializer_for_TimeAndInterval(&dDNP3Serializer_for_TimeAndInterval,
                   ID_in_Group50Var4_static(),
                   Size_in_Group50Var4_static(),
////                   typename Serializer<T>::read_func_t read_func,
                   &ReadTarget_in_Group50Var4_static,
////                   typename Serializer<T>::write_func_t write_func)
                   &WriteTarget_in_Group50Var4_static);

//  return DNP3Serializer<Binary>(ID(), Size(), &ReadTarget, &WriteTarget);
   return dDNP3Serializer_for_TimeAndInterval;
}
