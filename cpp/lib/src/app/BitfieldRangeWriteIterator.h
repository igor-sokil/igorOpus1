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
#ifndef OPENDNP3_BITFIELDRANGEWRITEITERATOR_UINT8_H
#define OPENDNP3_BITFIELDRANGEWRITEITERATOR_UINT8_H

#include "RSeq.h"
#include "WSeq.h"

////#include <ser4cpp/serialization/LittleEndian.h>

////namespace opendnp3
////{

//----------------------------------UInt8------------------------------------
// A facade for writing APDUs to an external buffer
////template<class IndexType> class BitfieldRangeWriteIterator
typedef struct
{
////public:
////    static BitfieldRangeWriteIterator Null()
////    {
////        auto buffer = ser4cpp::wseq_t::empty();
////        return BitfieldRangeWriteIterator(0, buffer);
////    }
////
////    BitfieldRangeWriteIterator(typename IndexType::type_t start_, ser4cpp::wseq_t& position_)
////        : start(start_),
////          count(0),
////          maxCount(0),
////          isValid(position_.length() >= (2 * IndexType::size)),
////          range(position_),
////          pPosition(&position_)
////    {
////        if (isValid)
////        {
////            IndexType::write_to(range, start_);
////            pPosition->advance(2 * IndexType::size);
////            maxCount = pPosition->length() * 8;
////        }
////    }
////
////    ~BitfieldRangeWriteIterator()
////    {
////        if (isValid && count > 0)
////        {
////            typename IndexType::type_t stop = start + count - 1;
////            IndexType::write_to(range, stop);
////
////            auto num = count / 8;
////
////            if ((count % 8) > 0)
////            {
////                ++num;
////            }
////
////            pPosition->advance(num);
////        }
////    }
////
////    bool Write(bool value)
////    {
////        if (isValid && count < maxCount)
////        {
////            auto byte = count / 8;
////            auto bit = count % 8;
////
////            if (bit == 0)
////            {
////                (*pPosition)[byte] = 0; // initialize byte to 0
////            }
////
////            if (value)
////            {
////                (*pPosition)[byte] = ((*pPosition)[byte] | (1 << bit));
////            }
////
////            ++count;
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }

////    bool IsValid() const
////    {
////        return isValid;
////    }

///private:
////    typename IndexType::type_t start;
////    typename IndexType::type_t count;
  uint8_t start;
  uint8_t count;

  uint16_t maxCount;

  boolean isValid;

  WSeq_for_Uint16_t range; // make a copy to record where we write the range
  WSeq_for_Uint16_t* pPosition;
} BitfieldRangeWriteIterator_for_UInt8;

////} // namespace opendnp3

boolean IsValid_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8);
boolean Write_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8, boolean value);
void BitfieldRangeWriteIterator_for_UInt8_destr_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8);
void  BitfieldRangeWriteIterator_for_UInt8_in_BitfieldRangeWriteIterator_for_UInt8(BitfieldRangeWriteIterator_for_UInt8 *pBitfieldRangeWriteIterator_for_UInt8,
    uint8_t start_, WSeq_for_Uint16_t* position_);
BitfieldRangeWriteIterator_for_UInt8 Null_in_BitfieldRangeWriteIterator_for_UInt8_static(void);
//----------------------------------UInt8------------------------------------
//----------------------------------UInt16------------------------------------
// A facade for writing APDUs to an external buffer
////template<class IndexType> class BitfieldRangeWriteIterator
typedef struct
{
////public:
////    static BitfieldRangeWriteIterator Null()
////    {
////        auto buffer = ser4cpp::wseq_t::empty();
////        return BitfieldRangeWriteIterator(0, buffer);
////    }
////
////    BitfieldRangeWriteIterator(typename IndexType::type_t start_, ser4cpp::wseq_t& position_)
////        : start(start_),
////          count(0),
////          maxCount(0),
////          isValid(position_.length() >= (2 * IndexType::size)),
////          range(position_),
////          pPosition(&position_)
////    {
////        if (isValid)
////        {
////            IndexType::write_to(range, start_);
////            pPosition->advance(2 * IndexType::size);
////            maxCount = pPosition->length() * 8;
////        }
////    }
////
////    ~BitfieldRangeWriteIterator()
////    {
////        if (isValid && count > 0)
////        {
////            typename IndexType::type_t stop = start + count - 1;
////            IndexType::write_to(range, stop);
////
////            auto num = count / 8;
////
////            if ((count % 8) > 0)
////            {
////                ++num;
////            }
////
////            pPosition->advance(num);
////        }
////    }
////
////    bool Write(bool value)
////    {
////        if (isValid && count < maxCount)
////        {
////            auto byte = count / 8;
////            auto bit = count % 8;
////
////            if (bit == 0)
////            {
////                (*pPosition)[byte] = 0; // initialize byte to 0
////            }
////
////            if (value)
////            {
////                (*pPosition)[byte] = ((*pPosition)[byte] | (1 << bit));
////            }
////
////            ++count;
////            return true;
////        }
////        else
////        {
////            return false;
////        }
////    }

////    bool IsValid() const
////    {
////        return isValid;
////    }

///private:
////    typename IndexType::type_t start;
////    typename IndexType::type_t count;
  uint16_t start;
  uint16_t count;

  uint16_t maxCount;

  boolean isValid;

  WSeq_for_Uint16_t range; // make a copy to record where we write the range
  WSeq_for_Uint16_t* pPosition;
} BitfieldRangeWriteIterator_for_UInt16;

////} // namespace opendnp3

boolean IsValid_in_BitfieldRangeWriteIterator_for_UInt16(BitfieldRangeWriteIterator_for_UInt16 *pBitfieldRangeWriteIterator_for_UInt16);
boolean Write_in_BitfieldRangeWriteIterator_for_UInt16(BitfieldRangeWriteIterator_for_UInt16 *pBitfieldRangeWriteIterator_for_UInt16, boolean value);
void BitfieldRangeWriteIterator_for_UInt16_destr_BitfieldRangeWriteIterator_for_UInt16(BitfieldRangeWriteIterator_for_UInt16 *pBitfieldRangeWriteIterator_for_UInt16);
void  BitfieldRangeWriteIterator_for_UInt16_in_BitfieldRangeWriteIterator_for_UInt16(BitfieldRangeWriteIterator_for_UInt16 *pBitfieldRangeWriteIterator_for_UInt16,
    uint16_t start_, WSeq_for_Uint16_t* position_);
BitfieldRangeWriteIterator_for_UInt16 Null_in_BitfieldRangeWriteIterator_for_UInt16_static(void);
//----------------------------------UInt16------------------------------------


#endif
