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
#ifndef OPENDNP3_PREFIXEDWRITEITERATOR_for_FrozenCounter_H
#define OPENDNP3_PREFIXEDWRITEITERATOR_for_FrozenCounter_H

////#include "app/Serializer.h"
#include "Serializer.h"
#include "MeasurementTypes.h"

////namespace opendnp3
////{
//-------------------Uint16---------------------------------------------------

// A facade for writing APDUs to an external buffer
////template<class PrefixType, class WriteType> class PrefixedWriteIterator
typedef struct
{
////public:
////    static PrefixedWriteIterator Null()
////    {
////        return PrefixedWriteIterator();
////    }

////    PrefixedWriteIterator() : sizeOfTypePlusIndex(0), count(0), isValid(false), pPosition(nullptr) {}
////
////    PrefixedWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
////        : serializer(serializer),
////          sizeOfTypePlusIndex(serializer.get_size() + PrefixType::size),
////          count(0),
////          isValid(position.length() >= PrefixType::size),
////          countPosition(position),
////          pPosition(&position)
////    {
////        if (isValid)
////        {
////            pPosition->advance(PrefixType::size);
////        }
////    }

////    ~PrefixedWriteIterator()
////    {
////        if (isValid)
////        {
////            PrefixType::write_to(countPosition, count);
////        }
////    }
////
////    bool Write(const WriteType& value, typename PrefixType::type_t index)
////    {
////        if (isValid && (pPosition->length() >= sizeOfTypePlusIndex))
////        {
////            PrefixType::write_to(*pPosition, index);
////            serializer.write(value, *pPosition);
////            ++count;
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }
////
////    bool IsValid() const
////    {
////        return isValid;
////    }
////
////private:

    Serializer_for_FrozenCounter serializer;
    uint16_t sizeOfTypePlusIndex;

////    typename PrefixType::type_t count;
    uint16_t count;

    boolean isValid;

    WSeq_for_Uint16_t countPosition; // make a copy to record where we write the count
    WSeq_for_Uint16_t* pPosition;
} PrefixedWriteIterator_for_UInt16_FrozenCounter;

////} // namespace opendnp3
    boolean IsValid_in_PrefixedWriteIterator_for_UInt16_FrozenCounter(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter);
    boolean Write_in_PrefixedWriteIterator_for_UInt16_FrozenCounter(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter,
                                                                  FrozenCounter* value, uint16_t index);
   void PrefixedWriteIterator_for_UInt16_FrozenCounter_destr_PrefixedWriteIterator_for_UInt16_FrozenCounter(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter);
   void PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver2(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter,
                                                 Serializer_for_FrozenCounter* serializer, WSeq_for_Uint16_t* position);
   void PrefixedWriteIterator_for_UInt16_FrozenCounter_in_PrefixedWriteIterator_for_UInt16_FrozenCounterOver1(PrefixedWriteIterator_for_UInt16_FrozenCounter *pPrefixedWriteIterator_for_UInt16_FrozenCounter);
   PrefixedWriteIterator_for_UInt16_FrozenCounter Null_in_PrefixedWriteIterator_for_UInt16_FrozenCounter_static(void);
//-------------------Uint16---------------------------------------------------


#endif
