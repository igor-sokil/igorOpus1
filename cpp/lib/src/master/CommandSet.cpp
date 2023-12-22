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
#include "CommandSet.h"

#include "Group12.h"
#include "Group41.h"
#include "TypedCommandHeader.h"

////namespace opendnp3
////{

////CommandSet::CommandSet(CommandSet&& other) : m_headers(std::move(other.m_headers)) {}

////CommandSet::~CommandSet() = default;

////CommandSet::CommandSet(std::initializer_list<Indexed<ControlRelayOutputBlock>> items)
////{
////    this->Add(items);
////}

////CommandSet::CommandSet(std::initializer_list<Indexed<AnalogOutputInt16>> items)
//void CommandSet_in_CommandSetOverIndexed_for_AnalogOutputInt16(CommandSet *pCommandSet, std::initializer_list<Indexed_for_AnalogOutputInt16> items)
//{
//   void Add_Indexed_for_AnalogOutputInt16_in_CommandSet(CommandSet *pCommandSet, std::initializer_list<Indexed_for_AnalogOutputInt16> items);
////    this->Add(items);
//  Add_Indexed_for_AnalogOutputInt16_in_CommandSet(pCommandSet, items);
//}
////template<> inline ICommandCollection<AnalogOutputInt16>& CommandSet::StartHeader()
ICommandCollection_for_AnalogOutputInt16 StartHeader_for_AnalogOutputInt16_in_CommandSet(CommandSet *pCommandSet)
{
//   ICommandCollection_for_AnalogOutputInt16* StartHeaderAOInt16_in_CommandSet(CommandSet *pCommandSet);
////    return this->StartHeaderAOInt16();
  return StartHeaderAOInt16_in_CommandSet(pCommandSet);
}

////CommandSet::CommandSet(std::initializer_list<Indexed<AnalogOutputInt32>> items)
////{
////    this->Add(items);
////}

////CommandSet::CommandSet(std::initializer_list<Indexed<AnalogOutputFloat32>> items)
////{
////    this->Add(items);
////}

////CommandSet::CommandSet(std::initializer_list<Indexed<AnalogOutputDouble64>> items)
////{
////    this->Add(items);
////}

////ICommandCollection<ControlRelayOutputBlock>& CommandSet::StartHeaderCROB()
////{
////    const auto header = std::make_shared<TypedCommandHeader<ControlRelayOutputBlock>>(Group12Var1::Inst());
////    this->m_headers.push_back(header);
////    return *header;
////}

////ICommandCollection<AnalogOutputInt32>& CommandSet::StartHeaderAOInt32()
////{
////    const auto header = std::make_shared<TypedCommandHeader<AnalogOutputInt32>>(Group41Var1::Inst());
////    this->m_headers.push_back(header);
////    return *header;
////}

////ICommandCollection<AnalogOutputInt16>& CommandSet::StartHeaderAOInt16()
ICommandCollection_for_AnalogOutputInt16 StartHeaderAOInt16_in_CommandSet(CommandSet *pCommandSet)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{StartHeaderAOInt16_in_CommandSet1"<<'\n';
#endif
//DNP3Serializer_for_AnalogOutputInt16  Inst_in_Group41Var2_static(void);
//void TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16(TypedCommandHeader_for_AnalogOutputInt16 *pTypedCommandHeader_for_AnalogOutputInt16,
//    DNP3Serializer_for_AnalogOutputInt16* serializer);
////    const auto header = std::make_shared<TypedCommandHeader<AnalogOutputInt16>>(Group41Var2::Inst());
  DNP3Serializer_for_AnalogOutputInt16 tmp = Inst_in_Group41Var2_static();
  TypedCommandHeader_for_AnalogOutputInt16 header;
  TypedCommandHeader_for_AnalogOutputInt16_in_TypedCommandHeader_for_AnalogOutputInt16(&header, &tmp);

////    this->m_headers.push_back(header);
  pCommandSet->m_headers.push_back(header.iICommandHeader);

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}StartHeaderAOInt16_in_CommandSet_"<<'\n';
  decrement_stack_info();
#endif
////    return *header;
  return header.iICommandCollection_for_AnalogOutputInt16;
}

////ICommandCollection<AnalogOutputFloat32>& CommandSet::StartHeaderAOFloat32()
////{
////    const auto header = std::make_shared<TypedCommandHeader<AnalogOutputFloat32>>(Group41Var3::Inst());
////    this->m_headers.push_back(header);
////    return *header;
////}

////ICommandCollection<AnalogOutputDouble64>& CommandSet::StartHeaderAODouble64()
////{
////    const auto header = std::make_shared<TypedCommandHeader<AnalogOutputDouble64>>(Group41Var4::Inst());
////    this->m_headers.push_back(header);
////    return *header;
////}

////} // namespace opendnp3
void Add_Indexed_for_AnalogOutputInt16_in_CommandSet(CommandSet *pCommandSet, Indexed_for_AnalogOutputInt16* command)
// std::initializer_list<Indexed_for_AnalogOutputInt16> items)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Add_Indexed_for_AnalogOutputInt16_in_CommandSet1"<<'\n';
#endif
//  if (items.size() != 0)
//  {
//   ICommandCollection_for_AnalogOutputInt16* StartHeader_for_AnalogOutputInt16_in_CommandSet(CommandSet *pCommandSet);
////            auto& header = this->StartHeader<T>();
    ICommandCollection_for_AnalogOutputInt16 header = StartHeader_for_AnalogOutputInt16_in_CommandSet(pCommandSet);
//    for (auto& command : items)
//    {
//void* Add_in_ICommandCollection_for_AnalogOutputInt16(ICommandCollection_for_AnalogOutputInt16* pICommandCollection_for_AnalogOutputInt16,
//    AnalogOutputInt16* command, uint16_t index);
////                header.Add(command.value, command.index);
      AnalogOutputInt16 cmd = command->value;
      Add_in_ICommandCollection_for_AnalogOutputInt16(&header, &cmd, command->index);
//    }
//  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Add_Indexed_for_AnalogOutputInt16_in_CommandSet_"<<'\n';
  decrement_stack_info();
#endif
}
