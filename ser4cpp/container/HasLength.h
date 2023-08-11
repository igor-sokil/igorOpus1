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
#ifndef SER4CPP_HASLENGTH_H
#define SER4CPP_HASLENGTH_H

////namespace ser4cpp
////{

//--------------------------------------HasLength_for_Uint16_t------------------------------------------------
////template <class L>
////class HasLength
typedef struct
{
////public:
////    inline L length() const
////    {
////        return m_length;
////    }
////
////    inline bool is_empty() const
////    {
////        return m_length == 0;
////    }
////
////    inline bool is_not_empty() const
////    {
////        return m_length != 0;
////    }
////
////protected:
////    HasLength() {}
////
////    explicit HasLength(L length) : m_length(length)
////    {}

  uint16_t m_length;//// = 0;
} HasLength_for_Uint16_t;
uint16_t length_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
boolean is_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
boolean is_not_empty_in_HasLength_for_Uint16_t(HasLength_for_Uint16_t *pHasLength);
void HasLength_for_Uint16_t_in_HasLength_for_Uint16_tOver1(HasLength_for_Uint16_t *pHasLength);
void HasLength_for_Uint16_t_in_HasLength_for_Uint16_tOver2(HasLength_for_Uint16_t *pHasLength, uint16_t length);
//--------------------------------------HasLength_for_Uint16_t------------------------------------------------
//--------------------------------------HasLength_for_Uint32_t------------------------------------------------
typedef struct
{
////public:
////    inline L length() const
////    {
////        return m_length;
////    }
////
////    inline bool is_empty() const
////    {
////        return m_length == 0;
////    }
////
////    inline bool is_not_empty() const
////    {
////        return m_length != 0;
////    }
////
////protected:
////    HasLength() {}
////
////    explicit HasLength(L length) : m_length(length)
////    {}

  uint32_t m_length;//// = 0;
} HasLength_for_Uint32_t;
uint32_t length_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
boolean is_not_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver1(HasLength_for_Uint32_t *pHasLength);
void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
//--------------------------------------HasLength_for_Uint32_t------------------------------------------------

////}

#endif
