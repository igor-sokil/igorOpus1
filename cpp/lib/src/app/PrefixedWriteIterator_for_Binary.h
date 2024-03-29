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
#ifndef OPENDNP3_PREFIXEDWRITEITERATOR_for_Binary_H
#define OPENDNP3_PREFIXEDWRITEITERATOR_for_Binary_H

////#include "app/Serializer.h"
#include "Serializer.h"
#include "MeasurementTypes.h"

////namespace opendnp3
////{
//-------------------Uint8---------------------------------------------------
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

  Serializer_for_Binary serializer;
  uint16_t sizeOfTypePlusIndex;

////    typename PrefixType::type_t count;
  uint8_t count;

  boolean isValid;

  WSeq_for_Uint16_t countPosition; // make a copy to record where we write the count
  WSeq_for_Uint16_t* pPosition;
} PrefixedWriteIterator_for_UInt8_Binary;

////} // namespace opendnp3
boolean IsValid_in_PrefixedWriteIterator_for_UInt8_Binary(PrefixedWriteIterator_for_UInt8_Binary *pPrefixedWriteIterator_for_UInt8_Binary);
boolean Write_in_PrefixedWriteIterator_for_UInt8_Binary(PrefixedWriteIterator_for_UInt8_Binary *pPrefixedWriteIterator_for_UInt8_Binary,
    Binary* value, uint16_t index);
void PrefixedWriteIterator_for_UInt8_Binary_destr_PrefixedWriteIterator_for_UInt8_Binary(PrefixedWriteIterator_for_UInt8_Binary *pPrefixedWriteIterator_for_UInt8_Binary);
void PrefixedWriteIterator_for_UInt8_Binary_in_PrefixedWriteIterator_for_UInt8_BinaryOver2(PrefixedWriteIterator_for_UInt8_Binary *pPrefixedWriteIterator_for_UInt8_Binary,
    Serializer_for_Binary* serializer, WSeq_for_Uint16_t* position);
void PrefixedWriteIterator_for_UInt8_Binary_in_PrefixedWriteIterator_for_UInt8_BinaryOver1(PrefixedWriteIterator_for_UInt8_Binary *pPrefixedWriteIterator_for_UInt8_Binary);
PrefixedWriteIterator_for_UInt8_Binary Null_in_PrefixedWriteIterator_for_UInt8_Binary_static(void);
//-------------------Uint8---------------------------------------------------
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

  Serializer_for_Binary serializer;
  uint16_t sizeOfTypePlusIndex;

////    typename PrefixType::type_t count;
  uint16_t count;

  boolean isValid;

  WSeq_for_Uint16_t countPosition; // make a copy to record where we write the count
  WSeq_for_Uint16_t* pPosition;
} PrefixedWriteIterator_for_UInt16_Binary;

////} // namespace opendnp3
boolean IsValid_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
boolean Write_in_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary,
    Binary* value, uint16_t index);
void PrefixedWriteIterator_for_UInt16_Binary_destr_PrefixedWriteIterator_for_UInt16_Binary(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
void PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver2(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary,
    Serializer_for_Binary* serializer, WSeq_for_Uint16_t* position);
void PrefixedWriteIterator_for_UInt16_Binary_in_PrefixedWriteIterator_for_UInt16_BinaryOver1(PrefixedWriteIterator_for_UInt16_Binary *pPrefixedWriteIterator_for_UInt16_Binary);
PrefixedWriteIterator_for_UInt16_Binary Null_in_PrefixedWriteIterator_for_UInt16_Binary_static(void);
//-------------------Uint16---------------------------------------------------

#endif
