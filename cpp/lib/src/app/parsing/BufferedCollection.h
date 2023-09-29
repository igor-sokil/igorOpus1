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
#ifndef OPENDNP3_BUFFEREDCOLLECTION_H
#define OPENDNP3_BUFFEREDCOLLECTION_H

////#include "opendnp3/app/parsing/ICollection.h"

////#include <ser4cpp/container/SequenceTypes.h>

#include "ICollection.h"
//#include "NumParser.h"
//#include "Indexed.h"
#include "RSeq.h"

////namespace opendnp3
///{

//-----------------------------------Indexed_for_Binary---------------------------------------------------
typedef Indexed_for_Binary (*ReadFunc_Indexed_for_Binary)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_Binary iICollection_Indexed_for_Binary;
////public:
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
////    {
////    }

////    virtual size_t Count() const override final
////    {
////        return COUNT;
////    }

////    virtual void Foreach(IVisitor<T>& visitor) const final
////    {
////        ser4cpp::rseq_t copy(buffer);

////        for (uint32_t pos = 0; pos < COUNT; ++pos)
////        {
////            visitor.OnValue(readFunc(copy, pos));
////        }
////    }

////private:
  RSeq_for_Uint16_t buffer;
  uint32_t COUNT;

//Indexed_for_Binary WithIndex_in_Indexed_for_Binary(
//  Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_Binary readFunc;
} BufferedCollection_Indexed_for_Binary;

void  BufferedCollection_Indexed_for_Binary_in_BufferedCollection_Indexed_for_Binary(
  BufferedCollection_Indexed_for_Binary *pBufferedCollection_Indexed_for_Binary,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Binary readFunc);
BufferedCollection_Indexed_for_Binary CreateBufferedCollection_Indexed_for_Binary_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Binary readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_Binary(BufferedCollection_Indexed_for_Binary *pBufferedCollection_Indexed_for_Binary);
void Foreach_in_BufferedCollection_Indexed_for_Binary(BufferedCollection_Indexed_for_Binary *pBufferedCollection_Indexed_for_Binary,
    IVisitor__for__Indexed_for_Binary* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_Binary_override(void *pICollection_Indexed_for_Binary);
void Foreach_in_BufferedCollection_Indexed_for_Binary_override(void *pICollection_Indexed_for_Binary,
    IVisitor__for__Indexed_for_Binary* visitor);
//-----------------------------------Indexed_for_Binary---------------------------------------------------
//-----------------------------------Indexed_for_OctetString---------------------------------------------------
typedef Indexed_for_OctetString (*ReadFunc_Indexed_for_OctetString)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_OctetString iICollection_Indexed_for_OctetString;
////public:
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
////    {
////    }

////    virtual size_t Count() const override final
////    {
////        return COUNT;
////    }

////    virtual void Foreach(IVisitor<T>& visitor) const final
////    {
////        ser4cpp::rseq_t copy(buffer);

////        for (uint32_t pos = 0; pos < COUNT; ++pos)
////        {
////            visitor.OnValue(readFunc(copy, pos));
////        }
////    }

////private:
  RSeq_for_Uint16_t buffer;
  uint32_t COUNT;

//Indexed_for_OctetString WithIndex_in_Indexed_for_OctetString(
//  OctetString* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_OctetString readFunc;
} BufferedCollection_Indexed_for_OctetString;

void  BufferedCollection_Indexed_for_OctetString_in_BufferedCollection_Indexed_for_OctetString(
  BufferedCollection_Indexed_for_OctetString *pBufferedCollection_Indexed_for_OctetString,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_OctetString readFunc);
BufferedCollection_Indexed_for_OctetString CreateBufferedCollection_Indexed_for_OctetString_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_OctetString readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_OctetString(BufferedCollection_Indexed_for_OctetString *pBufferedCollection_Indexed_for_OctetString);
void Foreach_in_BufferedCollection_Indexed_for_OctetString(BufferedCollection_Indexed_for_OctetString *pBufferedCollection_Indexed_for_OctetString,
    IVisitor__for__Indexed_for_OctetString* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_OctetString_override(void *pICollection_Indexed_for_OctetString);
void Foreach_in_BufferedCollection_Indexed_for_OctetString_override(void *pICollection_Indexed_for_OctetString,
    IVisitor__for__Indexed_for_OctetString* visitor);
//-----------------------------------Indexed_for_OctetString---------------------------------------------------
//-----------------------------------Indexed_for_IINValue---------------------------------------------------
typedef Indexed_for_IINValue (*ReadFunc_Indexed_for_IINValue)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_IINValue iICollection_Indexed_for_IINValue;
////public:
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
////    {
////    }

////    virtual size_t Count() const override final
////    {
////        return COUNT;
////    }

////    virtual void Foreach(IVisitor<T>& visitor) const final
////    {
////        ser4cpp::rseq_t copy(buffer);

////        for (uint32_t pos = 0; pos < COUNT; ++pos)
////        {
////            visitor.OnValue(readFunc(copy, pos));
////        }
////    }

////private:
  RSeq_for_Uint16_t buffer;
  uint32_t COUNT;

//Indexed_for_IINValue WithIndex_in_Indexed_for_IINValue(
//  IINValue* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_IINValue readFunc;
} BufferedCollection_Indexed_for_IINValue;

void  BufferedCollection_Indexed_for_IINValue_in_BufferedCollection_Indexed_for_IINValue(
  BufferedCollection_Indexed_for_IINValue *pBufferedCollection_Indexed_for_IINValue,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_IINValue readFunc);
BufferedCollection_Indexed_for_IINValue CreateBufferedCollection_Indexed_for_IINValue_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_IINValue readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_IINValue(BufferedCollection_Indexed_for_IINValue *pBufferedCollection_Indexed_for_IINValue);
void Foreach_in_BufferedCollection_Indexed_for_IINValue(BufferedCollection_Indexed_for_IINValue *pBufferedCollection_Indexed_for_IINValue,
    IVisitor__for__Indexed_for_IINValue* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_IINValue_override(void *pICollection_Indexed_for_IINValue);
void Foreach_in_BufferedCollection_Indexed_for_IINValue_override(void *pICollection_Indexed_for_IINValue,
    IVisitor__for__Indexed_for_IINValue* visitor);
//-----------------------------------Indexed_for_IINValue---------------------------------------------------
//-----------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------
typedef Indexed_for_BinaryOutputStatus (*ReadFunc_Indexed_for_BinaryOutputStatus)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_BinaryOutputStatus iICollection_Indexed_for_BinaryOutputStatus;
////public:
////    BufferedCollection(const ser4cpp::rseq_t& buffer, size_t count, const ReadFunc& readFunc)
////        : buffer(buffer), COUNT(count), readFunc(readFunc)
////    {
////    }

////    virtual size_t Count() const override final
////    {
////        return COUNT;
////    }

////    virtual void Foreach(IVisitor<T>& visitor) const final
////    {
////        ser4cpp::rseq_t copy(buffer);

////        for (uint32_t pos = 0; pos < COUNT; ++pos)
////        {
////            visitor.OnValue(readFunc(copy, pos));
////        }
////    }

////private:
  RSeq_for_Uint16_t buffer;
  uint32_t COUNT;

//Indexed_for_BinaryOutputStatus WithIndex_in_Indexed_for_BinaryOutputStatus(
//  BinaryOutputStatus* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_BinaryOutputStatus readFunc;
} BufferedCollection_Indexed_for_BinaryOutputStatus;

void  BufferedCollection_Indexed_for_BinaryOutputStatus_in_BufferedCollection_Indexed_for_BinaryOutputStatus(
  BufferedCollection_Indexed_for_BinaryOutputStatus *pBufferedCollection_Indexed_for_BinaryOutputStatus,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);
BufferedCollection_Indexed_for_BinaryOutputStatus CreateBufferedCollection_Indexed_for_BinaryOutputStatus_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryOutputStatus readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_BinaryOutputStatus(BufferedCollection_Indexed_for_BinaryOutputStatus *pBufferedCollection_Indexed_for_BinaryOutputStatus);
void Foreach_in_BufferedCollection_Indexed_for_BinaryOutputStatus(BufferedCollection_Indexed_for_BinaryOutputStatus *pBufferedCollection_Indexed_for_BinaryOutputStatus,
    IVisitor__for__Indexed_for_BinaryOutputStatus* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_BinaryOutputStatus_override(void *pICollection_Indexed_for_BinaryOutputStatus);
void Foreach_in_BufferedCollection_Indexed_for_BinaryOutputStatus_override(void *pICollection_Indexed_for_BinaryOutputStatus,
    IVisitor__for__Indexed_for_BinaryOutputStatus* visitor);
//-----------------------------------Indexed_for_BinaryOutputStatus---------------------------------------------------

////} // namespace opendnp3

#endif
