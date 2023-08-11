/*
 * Copyright (c) 2018, Automatak LLC
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
 * following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
 * disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
 * disclaimer in the documentation and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef SER4CPP_BufferSer4_H
#define SER4CPP_BufferSer4_H

////#include "ser4cpp/container/SequenceTypes.h"
////#include "ser4cpp/util/Uncopyable.h"

////#include <memory>
#include "RSeq.h"
#include "WSeq.h"

////namespace ser4cpp
////{

////class BufferSer4 : public HasLength<size_t>, private Uncopyable
typedef struct
{
  HasLength_for_Uint16_t hHasLength_for_Uint16_t;
////public:
////    BufferSer4() : HasLength(0)
////    {}

////    ~BufferSer4() = default;

////    explicit BufferSer4(size_t length) :
////        HasLength(length),
////        bytes(std::make_unique<uint8_t[]>(length))
////    {}

////    BufferSer4(BufferSer4&&) = default;
////    BufferSer4& operator=(BufferSer4&&) = default;

  // initialize with the exact length and contents
////    explicit BufferSer4(const rseq_t& input) : BufferSer4(input.length())
////    {
////        this->as_wslice().copy_from(input);
////    }

////    inline rseq_t as_rslice() const
////    {
////        return rseq_t(this->bytes.get(), this->length());
////    }

////    inline wseq_t as_wslice()
////    {
////        return wseq_t(this->bytes.get(), this->length());
////    }

////private:
////    std::unique_ptr<uint8_t[]> bytes;
  uint8_t bytes[MAX_BufferSer4];
} BufferSer4;

////}

void  BufferSer4_in_BufferSer4Over1(BufferSer4 *pBufferSer4);
void BufferSer4_in_BufferSer4Over2(BufferSer4 *pBufferSer4, uint16_t length);
void BufferSer4_in_BufferSer4Over3(BufferSer4 *pBufferSer4,  RSeq_for_Uint16_t *input);
RSeq_for_Uint16_t as_rslice_in_BufferSer4(BufferSer4 *pBufferSer4);
WSeq_for_Uint16_t as_wslice_in_BufferSer4(BufferSer4 *pBufferSer4);


#endif // SER4CPP_BufferSer4_H
