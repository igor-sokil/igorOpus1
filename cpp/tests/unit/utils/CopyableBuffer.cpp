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
#include "header.h"
#include "CopyableBuffer.h"
#include <string.h>

//#include "HexConversions.h"

////#include <memory>

////std::ostream& operator<<(std::ostream& output, const CopyableBuffer& arBuff)
////{
////    output << "[" << ser4cpp::HexConversions::to_hex(arBuff.ToRSeq(), true) << "]";
////    return output;
////}

void CopyableBuffer_in_CopyableBufferOver1(CopyableBuffer *pCopyableBuffer)
{
//  pCopyableBuffer->buffer = NULL;
  pCopyableBuffer->size = 0;
}

void CopyableBuffer_in_CopyableBufferOver2(CopyableBuffer *pCopyableBuffer, uint16_t size)
{
//// : buffer(new uint8_t[size]), size(size)

   pCopyableBuffer->size = size;
    Zero_in_CopyableBuffer(pCopyableBuffer);
}

void CopyableBuffer_in_CopyableBufferOver3(CopyableBuffer *pCopyableBuffer, RSeq_for_Uint16_t* data) 
{
//  void CopyableBuffer_in_CopyableBufferOver4(CopyableBuffer *pCopyableBuffer, uint8_t* data, uint16_t size);
////: CopyableBuffer(data, data.length()) {}
   CopyableBuffer_in_CopyableBufferOver4(pCopyableBuffer, data->buffer_, length_in_HasLength_for_Uint16_t(&(data->hHasLength)));
}

void CopyableBuffer_in_CopyableBufferOver4(CopyableBuffer *pCopyableBuffer, uint8_t* data, uint16_t size)
{
//// : buffer(new uint8_t[size]), size(size)
   pCopyableBuffer->size = size;
   memcpy(pCopyableBuffer->buffer, data, size);
}

////CopyableBuffer::CopyableBuffer(const CopyableBuffer& other) : CopyableBuffer(other.buffer, other.size) {}

void Zero_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer)
{
    memset(pCopyableBuffer->buffer, 0, pCopyableBuffer->size);
}

////CopyableBuffer& CopyableBuffer::operator=(const CopyableBuffer& other)
////{
    // check for assignment to self
////    if (this == &other)
////        return *this;
////
////    if (other.Size() != this->size)
////    {
////        this->size = other.Size();
////        delete[] this->buffer;
////        this->buffer = new uint8_t[this->size];
////    }
////
////    memcpy(this->buffer, other.buffer, this->size);
////
////    return *this;
////}

////CopyableBuffer::~CopyableBuffer()
////{
////    delete[] buffer;
////}

////bool CopyableBuffer::operator==(const CopyableBuffer& other) const
////{
////    if (other.Size() != this->Size())
////        return false;

////    for (size_t i = 0; i < this->Size(); ++i)
////    {
////        if (this->buffer[i] != other.buffer[i])
////            return false;
////    }
////
////    return true;
////}

RSeq_for_Uint16_t ToRSeq_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer)
    {
        RSeq_for_Uint16_t rseq_t;
//    void RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(RSeq_for_Uint16_t *pRSeq, uint8_t * buffer, uint16_t length);
////        return ser4cpp::rseq_t(buffer, size);
     RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(&rseq_t, pCopyableBuffer->buffer, pCopyableBuffer->size);
        return rseq_t;
    }

  uint16_t Size_in_CopyableBuffer(CopyableBuffer *pCopyableBuffer)
    {
        return pCopyableBuffer->size;
    }
