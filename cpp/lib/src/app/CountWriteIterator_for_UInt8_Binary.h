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
#ifndef OPENDNP3_COUNTWRITEITERATOR_for_UInt8_Binary_H
#define OPENDNP3_COUNTWRITEITERATOR_for_UInt8_Binary_H

////#include "app/Serializer.h"
#include <string.h>
#include "Serializer.h"
#include "RSeq.h"
#include "WSeq.h"
#include "MeasurementTypes.h"

////namespace opendnp3
////{

// A facade for writing APDUs to an external buffer
////template<class CountType, class WriteType> class CountWriteIterator
typedef struct
{
////public:
////    static CountWriteIterator Null()
////    {
////        return CountWriteIterator();
////    }
////
////    CountWriteIterator() : count(0), isValid(false), pPosition(nullptr) {}
////
////    CountWriteIterator(const Serializer<WriteType>& serializer, ser4cpp::wseq_t& position)
////        : count(0),
////          serializer(serializer),
////          isValid(position.length() >= CountType::size),
////          countPosition(position),
////          pPosition(&position)
////    {
////        if (isValid)
////        {
////            position.advance(CountType::size);
////        }
////    }
////
////    ~CountWriteIterator()
////    {
////        if (isValid)
////        {
////            CountType::write_to(countPosition, count);
////        }
////    }
////
////    bool Write(const WriteType& value)
////    {
////        if (isValid && (serializer.get_size() <= pPosition->length()) && (count < CountType::max_value))
////        {
////            serializer.write(value, *this->pPosition);
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
////    typename CountType::type_t count;
////    Serializer<WriteType> serializer;

    uint8_t count;
    Serializer_for_Binary serializer;

    boolean isValid;

    WSeq_for_Uint16_t countPosition; // make a copy to record where we write the count
    WSeq_for_Uint16_t* pPosition;
} CountWriteIterator_for_UInt8_Binary;

////} // namespace opendnp3
    boolean IsValid_in_CountWriteIterator_for_UInt8_Binary(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary);
    boolean Write_in_CountWriteIterator_for_UInt8_Binary(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary, Binary *value);////const WriteType& value)
    void CountWriteIterator_for_UInt8_Binary_destr_CountWriteIterator_for_UInt8_Binary(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary);
    void CountWriteIterator_for_UInt8_Binary_in_CountWriteIterator_for_UInt8_BinaryOver2(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary,
                                            Serializer_for_Binary *serializer, WSeq_for_Uint16_t *position);
    void CountWriteIterator_for_UInt8_Binary_in_CountWriteIterator_for_UInt8_BinaryOver1(CountWriteIterator_for_UInt8_Binary *pCountWriteIterator_for_UInt8_Binary);
    CountWriteIterator_for_UInt8_Binary Null_in_CountWriteIterator_for_UInt8_Binary_static(void);



#endif
