/*
 * Copyright 2013-2022 Step Function I/O, LLC
 *
 * Licensed to Green Energy Corp (www.greenenergycorp.com) and Step Function I/O
 * LLC (https://stepfunc.io) under one or more contributor license agreements.
 * See the NOTICE file distributed with this work for additional information
 * regarding copyright ownership. Green Energy Corp and Step Function I/O LLC license
 * this file to you under the Apache License, Version 2.0 (the "License"); you
 * may not use this file except in compliance with the License. You may obtain
 * a copy of the License at:
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <QApplication>
#include "header.h"
#include "StaticDataMap.h"

////namespace opendnp3
////{

////bool convert_to_event_class(PointClass pc, EventClass& ec)
boolean convert_to_event_class_in_StaticDataMap_static(PointClass_uint8_t pc, EventClass_uint8_t* ec)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"convert_to_event_class_in_StaticDataMap_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*PointClass_uint8_t pc= "<<(uint16_t)pc<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*PointClass_Class1= "<<(uint16_t)PointClass_Class1<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*PointClass_Class2= "<<(uint16_t)PointClass_Class2<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*PointClass_Class3= "<<(uint16_t)PointClass_Class3<<'\n';
  decrement_stack_info();
#endif

  switch (pc)
  {
  case (PointClass_Class1):
    *ec = EventClass_EC1;
    return true;
  case (PointClass_Class2):
    *ec = EventClass_EC2;
    return true;
  case (PointClass_Class3):
    *ec = EventClass_EC3;
    return true;
  default:
    return false;
  }
}

////template<>
////bool StaticDataMap<TimeAndIntervalSpec>::update(const TimeAndInterval& value,
////                                                uint16_t index,
////                                                EventMode /*mode*/,
////                                                IEventReceiver& /*receiver*/)
boolean update_in_StaticDataMap_for_TimeAndIntervalSpecOver1(StaticDataMap_for_TimeAndIntervalSpec *pStaticDataMap_for_TimeAndIntervalSpec,
    TimeAndInterval* value,
    uint16_t index,
    EventMode_uint8_t mode,
    IEventReceiver* receiver)
{
  UNUSED(mode);
  UNUSED(receiver);

  const auto iter = pStaticDataMap_for_TimeAndIntervalSpec->map.find(index);
  if (iter == pStaticDataMap_for_TimeAndIntervalSpec->map.end())
  {
    return false;
  }

  iter->second.value_in_StaticDataCell = *value;

  return true;
}

////template<> StaticBinaryVariation check_for_promotion<BinarySpec>(const Binary& value, StaticBinaryVariation variation)
StaticBinaryVariation_uint8_t check_for_promotion_for_BinarySpec_static(Binary* value, StaticBinaryVariation_uint8_t variation)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"check_for_promotion_for_BinarySpec_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*StaticBinaryVariation_uint8_t variation= "<<(uint16_t)variation<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*StaticBinaryVariation_Group1Var1= "<<(uint16_t)StaticBinaryVariation_Group1Var1<<'\n';
  decrement_stack_info();
#endif
  if (variation == StaticBinaryVariation_Group1Var1)
  {
//boolean IsQualityOnlineOnly_in_BinarySpec_static(Binary *binary);
////        return BinarySpec::IsQualityOnlineOnly(value) ? variation : StaticBinaryVariation::Group1Var2;
//    return (IsQualityOnlineOnly_in_BinarySpec_static(value)  ? variation : StaticBinaryVariation_Group1Var2);
    if(IsQualityOnlineOnly_in_BinarySpec_static(value)) return variation;
    return StaticBinaryVariation_Group1Var2;
  }

  return variation;
}

////} // namespace opendnp3
