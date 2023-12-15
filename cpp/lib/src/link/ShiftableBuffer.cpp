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
#include "ShiftableBuffer.h"
#include <string.h>

////#include <cassert>
////#include <cstring>
////#include <iostream>

////namespace opendnp3
////{

////ShiftableBuffer::ShiftableBuffer(uint8_t* pBuffer_, size_t size)
////    : pBuffer(pBuffer_), M_SIZE(size), writePos(0), readPos(0)
void ShiftableBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint8_t* pBuffer_, uint16_t size)
{
  pShiftableBuffer->pBuffer = pBuffer_;
  pShiftableBuffer->M_SIZE = size;
  pShiftableBuffer->writePos = 0;
  pShiftableBuffer->readPos = 0;
}

void Shift_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer)
{
//  uint16_t NumBytesRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    auto numRead = this->NumBytesRead();
  uint16_t numRead = NumBytesRead_in_ShiftableBuffer(pShiftableBuffer);

  // copy all unread data to the front of the buffer
  memmove(pShiftableBuffer->pBuffer, pShiftableBuffer->pBuffer + pShiftableBuffer->readPos, numRead);

  pShiftableBuffer->readPos = 0;
  pShiftableBuffer->writePos = numRead;
}

void Reset_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer)
{
  pShiftableBuffer->writePos = 0;
  pShiftableBuffer->readPos = 0;
}

void AdvanceRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t numBytes)
{
////    assert(numBytes <= this->NumBytesRead());
  pShiftableBuffer->readPos += numBytes;
}

void AdvanceWrite_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t aNumBytes)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{AdvanceWrite_in_ShiftableBuffer1"<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint16_t aNumBytes= "<<aNumBytes<<std::endl;
  if(!(aNumBytes <= NumWriteBytes_in_ShiftableBuffer(pShiftableBuffer)))
  {
     std::cout<<"*"<<getString_stack_info();
     std::cout<<"*assert(aNumBytes <= this->NumWriteBytes())"<<std::endl;
  }//if
#endif
//uint16_t NumWriteBytes_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer)
////    assert(aNumBytes <= this->NumWriteBytes());
  pShiftableBuffer->writePos += aNumBytes;

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}AdvanceWrite_in_ShiftableBuffer_"<<std::endl;
  decrement_stack_info();
#endif
}

boolean Sync_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t* skipCount)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Sync_in_ShiftableBuffer1"<<std::endl;
#endif
//  uint16_t NumBytesRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////    while (this->NumBytesRead() > 1) // at least 2 bytes
  while (NumBytesRead_in_ShiftableBuffer(pShiftableBuffer) > 1) // at least 2 bytes
  {
//  RSeq_for_Uint16_t ReadBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer);
////        if (this->ReadBuffer()[0] == 0x05 && this->ReadBuffer()[1] == 0x64)
    RSeq_for_Uint16_t temp = ReadBuffer_in_ShiftableBuffer(pShiftableBuffer);
    if (temp.buffer_[0] == 0x05 && temp.buffer_[1] == 0x64)
    {
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Sync_in_ShiftableBuffer1_"<<std::endl;
  decrement_stack_info();
#endif
      return true;
    }

//    void AdvanceRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer, uint16_t aNumBytes);
////        this->AdvanceRead(1); // skip the first byte
    AdvanceRead_in_ShiftableBuffer(pShiftableBuffer, 1);
    ++skipCount;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Sync_in_ShiftableBuffer2_"<<std::endl;
  decrement_stack_info();
#endif
  return false;
}

////} // namespace opendnp3
uint8_t* WriteBuff_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer)
{
  return pShiftableBuffer->pBuffer + pShiftableBuffer->writePos;
}

uint16_t NumWriteBytes_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer)
{
  return pShiftableBuffer->M_SIZE - pShiftableBuffer->writePos;
}

uint16_t NumBytesRead_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{NumBytesRead_in_ShiftableBuffer1"<<std::endl;

  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pShiftableBuffer->writePos= "<<(uint16_t)pShiftableBuffer->writePos<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pShiftableBuffer->readPos= "<<(uint16_t)pShiftableBuffer->readPos<<std::endl;
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*return pShiftableBuffer->writePos - pShiftableBuffer->readPos= "<<(uint16_t)(pShiftableBuffer->writePos - pShiftableBuffer->readPos)<<std::endl;

  std::cout<<getString_stack_info();
  std::cout<<"}NumBytesRead_in_ShiftableBuffer_"<<std::endl;
  decrement_stack_info();
#endif
  return pShiftableBuffer->writePos - pShiftableBuffer->readPos;
}

/// @return Pointer to the next byte to be read in the buffer
RSeq_for_Uint16_t ReadBuffer_in_ShiftableBuffer(ShiftableBuffer *pShiftableBuffer)
{
////        return ser4cpp::rseq_t(pBuffer + readPos, NumBytesRead());
  RSeq_for_Uint16_t rRSeq_for_Uint16_t;
  RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rRSeq_for_Uint16_t,
      pShiftableBuffer->pBuffer + pShiftableBuffer->readPos,
      NumBytesRead_in_ShiftableBuffer(pShiftableBuffer));
  return rRSeq_for_Uint16_t;
}
