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
#ifndef SER4CPP_RSEQ_H
#define SER4CPP_RSEQ_H

////#include "ser4cpp/container/HasLength.h"
////#include "ser4cpp/util/Comparisons.h"
#include "HasLength.h"
#include "Comparisons.h"

////#include <limits>
////#include <cstdint>
////#include <cstring>

/**
* @brief ser4cpp header-only library namespace
*/
////namespace ser4cpp
////{

/**
*	Represents a readonly sequence of bytes with a parameterized length type (L)
*/
////template <class L>
////class RSeq : public HasLength<L>
typedef struct
{
////    static_assert(std::numeric_limits<L>::is_integer&& !std::numeric_limits<L>::is_signed, "Must be an unsigned integer");

////public:
////    static RSeq empty()
////    {
////        return RSeq(nullptr, 0);
////    }
////
////    RSeq() : HasLength<L>(0)
////    {}
////
////    RSeq(uint8_t const* buffer, L length) :
////        HasLength<L>(length),
////        buffer_(buffer)
////    {}
////
////    void make_empty()
////    {
////        this->buffer_ = nullptr;
////        this->m_length = 0;
////    }
////
////    RSeq take(L count) const
////    {
////        return RSeq(this->buffer_, (count < this->length()) ? count : this->length());
////    }
////
////    RSeq skip(L count) const
////    {
////        auto num = ser4cpp::min(this->length(), count);
////        return RSeq(this->buffer_ + num, this->length() - num);
////    }
////
////    void advance(L count)
////    {
////        auto num = ser4cpp::min(this->length(), count);
////        this->buffer_ += num;
////        this->m_length -= num;
////    }
////
////    operator uint8_t const* () const
////    {
////        return this->buffer_;
////    };
////
////    bool equals(const RSeq& rhs) const
////    {
////        if (this->m_length == rhs.m_length)
////        {
////            return memcmp(this->buffer_, rhs.buffer_, this->m_length) == 0;
////        }
////        else
////        {
////            return false;
////        }
////    }

  HasLength_for_Uint16_t hHasLength;
////protected:
  uint8_t * buffer_;//// = nullptr;
} RSeq_for_Uint16_t;

RSeq_for_Uint16_t empty_in_RSeq_for_Uint16_t_static(void);
void RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver1(RSeq_for_Uint16_t *pRSeq);
void RSeq_for_Uint16_t_in_RSeq_for_Uint16_tOver2(RSeq_for_Uint16_t *pRSeq, uint8_t * buffer, uint16_t length);
void make_empty_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq);
RSeq_for_Uint16_t take_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
RSeq_for_Uint16_t skip_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
void advance_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq, uint16_t count);
boolean equals_in_RSeq_for_Uint16_t(RSeq_for_Uint16_t *pRSeq_for_Uint16_t, RSeq_for_Uint16_t *rhs);


////    operator uint8_t const* () const
////    {
////        return this->buffer_;
////    };
////
////    bool equals(const RSeq& rhs) const
////    {
////        if (this->m_length == rhs.m_length)
////        {
////            return memcmp(this->buffer_, rhs.buffer_, this->m_length) == 0;
////        }
////        else
////        {
////            return false;
////        }
////    }

////}
//------------------------------------------------------------------------------------
/*
typedef struct
{
////    static_assert(std::numeric_limits<L>::is_integer&& !std::numeric_limits<L>::is_signed, "Must be an unsigned integer");

////public:
////    static RSeq empty()
////    {
////        return RSeq(nullptr, 0);
////    }
////
////    RSeq() : HasLength<L>(0)
////    {}
////
////    RSeq(uint8_t const* buffer, L length) :
////        HasLength<L>(length),
////        buffer_(buffer)
////    {}
////
////    void make_empty()
////    {
////        this->buffer_ = nullptr;
////        this->m_length = 0;
////    }
////
////    RSeq take(L count) const
////    {
////        return RSeq(this->buffer_, (count < this->length()) ? count : this->length());
////    }
////
////    RSeq skip(L count) const
////    {
////        auto num = ser4cpp::min(this->length(), count);
////        return RSeq(this->buffer_ + num, this->length() - num);
////    }
////
////    void advance(L count)
////    {
////        auto num = ser4cpp::min(this->length(), count);
////        this->buffer_ += num;
////        this->m_length -= num;
////    }
////
////    operator uint8_t const* () const
////    {
////        return this->buffer_;
////    };
////
////    bool equals(const RSeq& rhs) const
////    {
////        if (this->m_length == rhs.m_length)
////        {
////            return memcmp(this->buffer_, rhs.buffer_, this->m_length) == 0;
////        }
////        else
////        {
////            return false;
////        }
////    }

    HasLengthTemplateUint8_t hHasLength;
////protected:
    uint8_t * buffer_;//// = nullptr;
} RSeqTemplateUint8_t;

     RSeqTemplateUint8_t empty_in_RSeqTemplateUint8_t_static(void);
    void RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver1(RSeqTemplateUint8_t *pRSeq);
    void RSeqTemplateUint8_t_in_RSeqTemplateUint8_tOver2(RSeqTemplateUint8_t *pRSeq, uint8_t * buffer, uint8_t length);
    void make_empty_in_RSeqTemplateUint8_t(RSeqTemplateUint8_t *pRSeq);
    RSeqTemplateUint8_t take_in_RSeqTemplateUint8_t(RSeqTemplateUint8_t *pRSeq, uint8_t count);
    RSeqTemplateUint8_t skip_in_RSeqTemplateUint8_t(RSeqTemplateUint8_t *pRSeq, uint8_t count);
    void advance_in_RSeqTemplateUint8_tRSeq(RSeqTemplateUint8_t *pRSeq, uint8_t count);
*/
#endif
