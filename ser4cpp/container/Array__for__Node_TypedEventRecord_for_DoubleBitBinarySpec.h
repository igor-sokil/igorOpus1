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
#ifndef SER4CPP_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec_H
#define SER4CPP_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec_H

////#include "ser4cpp/container/ArrayView.h"
#include "ArrayView__for__Node_TypedEventRecord_for_DoubleBitBinarySpec.h"

////#include "ser4cpp/util/Uncopyable.h"

////#include <assert.h>

////namespace ser4cpp
///{

/**
 * Template type for a dynamically allocated array
 */
////template<class T, class W> class Array : public HasLength<W>
typedef struct
{

////public:
////    Array(W size) : HasLength<W>(size), buffer(new T[size]()) {}

////    Array() : HasLength<W>(0), buffer(nullptr) {}

////    Array(const Array& copy) : HasLength<W>(copy.length()), buffer(new T[copy.length()])
////    {
////        for (W i = 0; i < copy.length(); ++i)
////            buffer[i] = copy.buffer[i];
////    }
////
////    virtual ~Array()
////    {
////        delete[] buffer;
////    }
////
////    ArrayView<T, W> to_view() const
////    {
////        return ArrayView<T, W>(buffer, this->m_length);
////    }
////
////    inline bool contains(W index) const
////    {
////        return index < this->m_length;
////    }

////    inline T& operator[](W index)
////    {
////        assert(index < this->m_length);
////        return buffer[index];
////    }
////
////    const T& operator[](W index) const
////    {
////        assert(index < this->m_length);
////        return buffer[index];
////    }
////
  HasLength_for_Uint32_t hHasLength_for_Uint32_t;
////protected:
////    T* buffer;
  Node_TypedEventRecord_for_DoubleBitBinarySpec buffer[SIZE_TypedEventRecord_for_DoubleBitBinarySpec];

////private:
////    Array& operator=(const Array&) = delete;
} Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec;

boolean contains_in_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec(Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec *pArray__for__Node_TypedEventRecord_for_DoubleBitBinarySpec, uint32_t index);
ArrayView__for__Node_TypedEventRecord_for_DoubleBitBinarySpec to_view_in_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec(Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec *pArray__for__Node_TypedEventRecord_for_DoubleBitBinarySpec);
void Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec_in_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpecOver3(Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec *pArray__for__Node_TypedEventRecord_for_DoubleBitBinarySpec,
    Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec* copyEv);
void Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec_in_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpecOver1(Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec *pArray__for__Node_TypedEventRecord_for_DoubleBitBinarySpec);
void Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec_in_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpecOver2(Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec *pArray__for__Node_TypedEventRecord_for_DoubleBitBinarySpec, uint32_t size);


////} // namespace ser4cpp

#endif
