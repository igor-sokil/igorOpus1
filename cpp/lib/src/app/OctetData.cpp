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
////#include "opendnp3/app/OctetData.h"

////#include <ser4cpp/container/SequenceTypes.h>
////#include <ser4cpp/util/Comparisons.h>

////#include <cstring>

#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include <string.h>

#include "header.h"
#include "OctetData.h"
#include "Comparisons.h"

#include "RSeq.h"
#include "WSeq.h"
//#include <ser4cpp/util/Comparisons.h>

////namespace opendnp3
////{

void OctetData_in_OctetDataOver1(OctetData *pOctetData)
{
  pOctetData->size = 1;
}

void OctetData_in_OctetDataOver2(OctetData *pOctetData, char* input)
{
//// : OctetData(ToSlice(input)) {}
  Buffer buffer = ToSlice_in_OctetData_static(input);
  OctetData_in_OctetDataOver3(pOctetData, &buffer);
}

void OctetData_in_OctetDataOver3(OctetData *pOctetData,  Buffer *input)
{
////    : size(input.length == 0 ? 1 : ser4cpp::min<uint8_t>(MAX_SIZE, static_cast<uint8_t>(input.length)))
  pOctetData->size = (input->length == 0) ? 1 : min_for_Uint16_t(MAX_SIZE_in_OctetData, (uint16_t)(input->length));
////    ser4cpp::rseq_t input_slice(input.data, input.length);
  RSeq_for_Uint16_t  input_slice;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&input_slice, input->data, input->length);
////    if (input_slice.is_not_empty())
  if(is_not_empty_in_HasLength_for_Uint16_t(&(input_slice.hHasLength)))
  {
////        ser4cpp::wseq_t dest(buffer.data(), buffer.size());
    WSeq_for_Uint16_t  dest;
    WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&dest, pOctetData->buffer, MAX_SIZE_in_OctetData);
////        dest.copy_from(input_slice.take(size));
    RSeq_for_Uint16_t temp = take_in_RSeq_for_Uint16_t(&input_slice, pOctetData->size);
    copy_from_in_WSeq_for_Uint16_t(&dest, &temp);
  }
}

boolean Set_in_OctetDataOver1(OctetData *pOctetData, Buffer *input)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Set_in_OctetDataOver1_1"<<'\n';
//  std::cout<<"*"<<getString_stack_info();
//  std::cout<<"*strlen(input)= "<<(uint16_t)strlen(input)<<'\n';
  decrement_stack_info();
#endif
////    ser4cpp::rseq_t input_slice(input.data, input.length);
  RSeq_for_Uint16_t  input_slice;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&input_slice, input->data, input->length);
////    if (input_slice.is_empty())
  if(is_empty_in_HasLength_for_Uint16_t(&(input_slice.hHasLength)))
  {
    pOctetData->size = 0;
    pOctetData->buffer[0] = 0x00;
    return false;
  }

////    boolean is_oversized = input_slice.length() > MAX_SIZE;
  uint16_t temp1 = length_in_HasLength_for_Uint16_t(&(input_slice.hHasLength));
  uint16_t temp2 = (uint16_t)MAX_SIZE_in_OctetData;
  boolean is_oversized = temp1 > temp2;
  uint16_t usable_size  = is_oversized ? MAX_SIZE_in_OctetData : (uint16_t)length_in_HasLength_for_Uint16_t(&(input_slice.hHasLength));

////    ser4cpp::wseq_t dest(buffer.data(), buffer.size());
  WSeq_for_Uint16_t  dest;
  WSeq_for_Uint16_t_in_WSeq_for_Uint16_tOver2(&dest, pOctetData->buffer, MAX_SIZE_in_OctetData);
////    dest.copy_from(input_slice.take(usable_size));
  RSeq_for_Uint16_t temp = take_in_RSeq_for_Uint16_t(&input_slice, usable_size);
  copy_from_in_WSeq_for_Uint16_t(&dest, &temp);
  pOctetData->size = usable_size;
  return !is_oversized;
}

boolean Set_in_OctetDataOver2(OctetData *pOctetData, char* input)
{
#ifdef  LOG_INFO
  increment_stack_info();
  std::cout<<""<<'\n';
  std::cout<<getString_stack_info();
  std::cout<<"Set_in_OctetDataOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*strlen(input)= "<<(uint16_t)strlen(input)<<'\n';
  decrement_stack_info();
#endif
  uint16_t length = strlen(input);
  Buffer bBuffer;
  Buffer_in_BufferOver2(&bBuffer, (uint8_t*)input, length > MAX_SIZE_in_OctetData ? MAX_SIZE_in_OctetData : length);
////    return pOctetData->Set(Buffer(reinterpret_cast<const uint8_t*>(input), length > MAX_SIZE ? MAX_SIZE : length));
  return Set_in_OctetDataOver1(pOctetData, &bBuffer);
}

Buffer ToBuffer_in_OctetData(OctetData *pOctetData)
{
  Buffer bBuffer;
  Buffer_in_BufferOver2(&bBuffer, pOctetData->buffer, pOctetData->size);
////    return Buffer(buffer.data(), size);
  return bBuffer;
}

Buffer ToSlice_in_OctetData_static(char* input)
{
  uint16_t length = strlen(input);
  Buffer bBuffer;
  Buffer_in_BufferOver1(&bBuffer);
  if (length == 0)
    return bBuffer;////Buffer();
////    return Buffer(reinterpret_cast<const uint8_t*>(input), length > MAX_SIZE_in_OctetData ? MAX_SIZE_in_OctetData : length);
  Buffer_in_BufferOver2(&bBuffer, (uint8_t*)input, length > MAX_SIZE_in_OctetData ? MAX_SIZE_in_OctetData : length);
  return bBuffer;
}

////} // namespace opendnp3

uint16_t Size_in_OctetData(OctetData *pOctetData)
{
  return pOctetData->size;
}

