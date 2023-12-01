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
#include "header.h"
#include "APDUWrapper.h"

#include "AppControlField.h"

////#include <cassert>

////namespace opendnp3
////{

////APDUWrapper::APDUWrapper(const ser4cpp::wseq_t& buffer) : valid(true), buffer(buffer), remaining(buffer)
void APDUWrapper_in_APDUWrapperOver2(APDUWrapper *pAPDUWrapper, WSeq_for_Uint16_t *buffer)
{
  pAPDUWrapper->valid = true;
  pAPDUWrapper->buffer = *buffer;
  pAPDUWrapper->remaining = *buffer;
//    assert(buffer.length() >= 2); // need a control & function at a minimum
//    (pAPDUWrapper->remaining).advance(2);
  advance_in_WSeq_for_Uint16_t(&(pAPDUWrapper->remaining), 2);
}

boolean IsValid_in_APDUWrapper(APDUWrapper *pAPDUWrapper)
{
  return pAPDUWrapper->valid;
}

HeaderWriter GetWriter_in_APDUWrapper(APDUWrapper *pAPDUWrapper)
{
////    return HeaderWriter(&remaining);
  HeaderWriter hHeaderWriter;
  HeaderWriter_in_HeaderWriter(&hHeaderWriter, &(pAPDUWrapper->remaining));
  return hHeaderWriter;
}

uint16_t Remaining_in_APDUWrapper(APDUWrapper *pAPDUWrapper)
{
  return length_in_HasLength_for_Uint16_t(&((pAPDUWrapper->remaining).hHasLength));//(&(pAPDUWrapper->remaining))->hHasLength);
////    return remaining.length();
}

void SetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper, FunctionCode_uint8_t code)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{SetFunction_in_APDUWrapper1"<<'\n';
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*write_uint8="<<(uint32_t)((pAPDUWrapper->buffer).buffer_+1)<<"->"<<(uint16_t)code<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}SetFunction_in_APDUWrapper_"<<'\n';
  decrement_stack_info();
#endif
//    assert(buffer.is_not_empty());
//    pAPDUWrapper->buffer[1] = code;////FunctionCodeSpec::to_type(code);
  (pAPDUWrapper->buffer).buffer_[1] = code;////FunctionCodeSpec::to_type(code);
}

FunctionCode_uint8_t GetFunction_in_APDUWrapper(APDUWrapper *pAPDUWrapper)
{
//    assert(buffer.is_not_empty());
  return from_type_in_FunctionCodeSpec((pAPDUWrapper->buffer).buffer_[1]);////(buffer[1]);
}

AppControlField GetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper)
{
////    assert(buffer.is_not_empty());
////    return AppControlField(buffer[0]);
  AppControlField aAppControlField;
  AppControlField_in_AppControlFieldOver2(&aAppControlField, (pAPDUWrapper->buffer).buffer_[0]);
  return aAppControlField;
}

void SetControl_in_APDUWrapper(APDUWrapper *pAPDUWrapper, AppControlField control)
{
////    buffer[0] = control.ToByte();
  (pAPDUWrapper->buffer).buffer_[0] = ToByte_in_AppControlField(&control);
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"{SetControl_in_APDUWrapper1"<<'\n';
  std::cout<<"@@@@"<<getString_stack_info();
  std::cout<<"*write_uint8="<<(uint32_t)((pAPDUWrapper->buffer).buffer_+0)<<"->"<<(uint16_t)(pAPDUWrapper->buffer).buffer_[0]<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"}SetControl_in_APDUWrapper_"<<'\n';
  decrement_stack_info();
#endif
}

uint16_t Size_in_APDUWrapper(APDUWrapper *pAPDUWrapper)
{
////    return buffer.length() - remaining.length();
  uint16_t temp1 = length_in_HasLength_for_Uint16_t(&(pAPDUWrapper->buffer).hHasLength);
  uint16_t temp2 = length_in_HasLength_for_Uint16_t(&(pAPDUWrapper->remaining).hHasLength);
  return temp1-temp2;
}

////ser4cpp::rseq_t APDUWrapper::ToRSeq() const
RSeq_for_Uint16_t  ToRSeq_in_APDUWrapper(APDUWrapper *pAPDUWrapper)
{
////    return buffer.readonly().take(this->Size());
  RSeq_for_Uint16_t temp1 = readonly_in_WSeq_for_Uint16_t(&(pAPDUWrapper->buffer));

//  RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(&temp1, uint16_t count);
  uint16_t temp3 = Size_in_APDUWrapper(pAPDUWrapper);
  //RSeq_for_Uint16_t temp2 =
  return take_in_RSeq_for_Uint16_t(&temp1, temp3);
}

////} // namespace opendnp3
////APDUWrapper::APDUWrapper() : valid(false) {}
void APDUWrapper_in_APDUWrapperOver1(APDUWrapper *pAPDUWrapper)
{
  pAPDUWrapper->valid = false;
}

////APDUWrapper::APDUWrapper(const ser4cpp::wseq_t& buffer) : valid(true), buffer(buffer), remaining(buffer)
//void APDUWrapper_in_APDUWrapperOver2(APDUWrapper *pAPDUWrapper, WSeq_for_Uint16_t *buffer);
//{
////    assert(buffer.length() >= 2); // need a control & function at a minimum
////    remaining.advance(2);
//  pAPDUWrapper->valid = true;
//  pAPDUWrapper->buffer_uint32_t = buffer_uint32_t;
//}


