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
#include "RSeq.h"

////namespace opendnp3
///{

//-----------------------------------uint16---------------------------------------------------
typedef uint16_t (*ReadFunc_uint16)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_for_uint16 iICollection_for_uint16;
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

//uint16 WithIndex_in_uint16(
//  Binary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_uint16 readFunc;
} BufferedCollection_uint16;

void  BufferedCollection_uint16_in_BufferedCollection_uint16(
  BufferedCollection_uint16 *pBufferedCollection_uint16,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_uint16 readFunc);
BufferedCollection_uint16 CreateBufferedCollection_uint16_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_uint16 readFunc);

uint16_t Count_in_BufferedCollection_uint16(BufferedCollection_uint16 *pBufferedCollection_uint16);
void Foreach_in_BufferedCollection_uint16(BufferedCollection_uint16 *pBufferedCollection_uint16,
    IVisitor__for__uint16* visitor);


uint16_t Count_in_BufferedCollection_uint16_override(void *pICollection_for_uint16);
void Foreach_in_BufferedCollection_uint16_override(void *pICollection_for_uint16,
    IVisitor__for__uint16* visitor);
//-----------------------------------uint16---------------------------------------------------
//-----------------------------------Group50Var1---------------------------------------------------
typedef Group50Var1 (*ReadFunc_Group50Var1)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_for_Group50Var1 iICollection_for_Group50Var1;
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

//Group50Var1 WithIndex_in_Group50Var1(
//  Binary* value, Group50Var1_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Group50Var1 readFunc;
} BufferedCollection_Group50Var1;

void  BufferedCollection_Group50Var1_in_BufferedCollection_Group50Var1(
  BufferedCollection_Group50Var1 *pBufferedCollection_Group50Var1,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var1 readFunc);
BufferedCollection_Group50Var1 CreateBufferedCollection_Group50Var1_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var1 readFunc);

uint16_t Count_in_BufferedCollection_Group50Var1(BufferedCollection_Group50Var1 *pBufferedCollection_Group50Var1);
void Foreach_in_BufferedCollection_Group50Var1(BufferedCollection_Group50Var1 *pBufferedCollection_Group50Var1,
    IVisitor__for__Group50Var1* visitor);


uint16_t Count_in_BufferedCollection_Group50Var1_override(void *pICollection_for_Group50Var1);
void Foreach_in_BufferedCollection_Group50Var1_override(void *pICollection_for_Group50Var1,
    IVisitor__for__Group50Var1* visitor);
//-----------------------------------Group50Var1---------------------------------------------------
//-----------------------------------Group50Var3---------------------------------------------------
typedef Group50Var3 (*ReadFunc_Group50Var3)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_for_Group50Var3 iICollection_for_Group50Var3;
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

//Group50Var3 WithIndex_in_Group50Var3(
//  Binary* value, Group50Var3_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Group50Var3 readFunc;
} BufferedCollection_Group50Var3;

void  BufferedCollection_Group50Var3_in_BufferedCollection_Group50Var3(
  BufferedCollection_Group50Var3 *pBufferedCollection_Group50Var3,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var3 readFunc);
BufferedCollection_Group50Var3 CreateBufferedCollection_Group50Var3_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group50Var3 readFunc);

uint16_t Count_in_BufferedCollection_Group50Var3(BufferedCollection_Group50Var3 *pBufferedCollection_Group50Var3);
void Foreach_in_BufferedCollection_Group50Var3(BufferedCollection_Group50Var3 *pBufferedCollection_Group50Var3,
    IVisitor__for__Group50Var3* visitor);


uint16_t Count_in_BufferedCollection_Group50Var3_override(void *pICollection_for_Group50Var3);
void Foreach_in_BufferedCollection_Group50Var3_override(void *pICollection_for_Group50Var3,
    IVisitor__for__Group50Var3* visitor);
//-----------------------------------Group50Var3---------------------------------------------------
//-----------------------------------Group51Var1---------------------------------------------------
typedef Group51Var1 (*ReadFunc_Group51Var1)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_for_Group51Var1 iICollection_for_Group51Var1;
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

//Group51Var1 WithIndex_in_Group51Var1(
//  Binary* value, Group51Var1_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Group51Var1 readFunc;
} BufferedCollection_Group51Var1;

void  BufferedCollection_Group51Var1_in_BufferedCollection_Group51Var1(
  BufferedCollection_Group51Var1 *pBufferedCollection_Group51Var1,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group51Var1 readFunc);
BufferedCollection_Group51Var1 CreateBufferedCollection_Group51Var1_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group51Var1 readFunc);

uint16_t Count_in_BufferedCollection_Group51Var1(BufferedCollection_Group51Var1 *pBufferedCollection_Group51Var1);
void Foreach_in_BufferedCollection_Group51Var1(BufferedCollection_Group51Var1 *pBufferedCollection_Group51Var1,
    IVisitor__for__Group51Var1* visitor);


uint16_t Count_in_BufferedCollection_Group51Var1_override(void *pICollection_for_Group51Var1);
void Foreach_in_BufferedCollection_Group51Var1_override(void *pICollection_for_Group51Var1,
    IVisitor__for__Group51Var1* visitor);
//-----------------------------------Group51Var1---------------------------------------------------
//-----------------------------------Group51Var2---------------------------------------------------
typedef Group51Var2 (*ReadFunc_Group51Var2)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_for_Group51Var2 iICollection_for_Group51Var2;
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

//Group51Var2 WithIndex_in_Group51Var2(
//  Binary* value, Group51Var2_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Group51Var2 readFunc;
} BufferedCollection_Group51Var2;

void  BufferedCollection_Group51Var2_in_BufferedCollection_Group51Var2(
  BufferedCollection_Group51Var2 *pBufferedCollection_Group51Var2,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group51Var2 readFunc);
BufferedCollection_Group51Var2 CreateBufferedCollection_Group51Var2_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group51Var2 readFunc);

uint16_t Count_in_BufferedCollection_Group51Var2(BufferedCollection_Group51Var2 *pBufferedCollection_Group51Var2);
void Foreach_in_BufferedCollection_Group51Var2(BufferedCollection_Group51Var2 *pBufferedCollection_Group51Var2,
    IVisitor__for__Group51Var2* visitor);


uint16_t Count_in_BufferedCollection_Group51Var2_override(void *pICollection_for_Group51Var2);
void Foreach_in_BufferedCollection_Group51Var2_override(void *pICollection_for_Group51Var2,
    IVisitor__for__Group51Var2* visitor);
//-----------------------------------Group51Var2---------------------------------------------------
//-----------------------------------Group52Var1---------------------------------------------------
typedef Group52Var1 (*ReadFunc_Group52Var1)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_for_Group52Var1 iICollection_for_Group52Var1;
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

//Group52Var1 WithIndex_in_Group52Var1(
//  Binary* value, Group52Var1_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Group52Var1 readFunc;
} BufferedCollection_Group52Var1;

void  BufferedCollection_Group52Var1_in_BufferedCollection_Group52Var1(
  BufferedCollection_Group52Var1 *pBufferedCollection_Group52Var1,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group52Var1 readFunc);
BufferedCollection_Group52Var1 CreateBufferedCollection_Group52Var1_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group52Var1 readFunc);

uint16_t Count_in_BufferedCollection_Group52Var1(BufferedCollection_Group52Var1 *pBufferedCollection_Group52Var1);
void Foreach_in_BufferedCollection_Group52Var1(BufferedCollection_Group52Var1 *pBufferedCollection_Group52Var1,
    IVisitor__for__Group52Var1* visitor);


uint16_t Count_in_BufferedCollection_Group52Var1_override(void *pICollection_for_Group52Var1);
void Foreach_in_BufferedCollection_Group52Var1_override(void *pICollection_for_Group52Var1,
    IVisitor__for__Group52Var1* visitor);
//-----------------------------------Group52Var1---------------------------------------------------
//-----------------------------------Group52Var2---------------------------------------------------
typedef Group52Var2 (*ReadFunc_Group52Var2)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_for_Group52Var2 iICollection_for_Group52Var2;
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

//Group52Var2 WithIndex_in_Group52Var2(
//  Binary* value, Group52Var2_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Group52Var2 readFunc;
} BufferedCollection_Group52Var2;

void  BufferedCollection_Group52Var2_in_BufferedCollection_Group52Var2(
  BufferedCollection_Group52Var2 *pBufferedCollection_Group52Var2,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group52Var2 readFunc);
BufferedCollection_Group52Var2 CreateBufferedCollection_Group52Var2_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Group52Var2 readFunc);

uint16_t Count_in_BufferedCollection_Group52Var2(BufferedCollection_Group52Var2 *pBufferedCollection_Group52Var2);
void Foreach_in_BufferedCollection_Group52Var2(BufferedCollection_Group52Var2 *pBufferedCollection_Group52Var2,
    IVisitor__for__Group52Var2* visitor);


uint16_t Count_in_BufferedCollection_Group52Var2_override(void *pICollection_for_Group52Var2);
void Foreach_in_BufferedCollection_Group52Var2_override(void *pICollection_for_Group52Var2,
    IVisitor__for__Group52Var2* visitor);
//-----------------------------------Group52Var2---------------------------------------------------
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
//-----------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------
typedef Indexed_for_ControlRelayOutputBlock (*ReadFunc_Indexed_for_ControlRelayOutputBlock)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_ControlRelayOutputBlock iICollection_Indexed_for_ControlRelayOutputBlock;
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

//Indexed_for_ControlRelayOutputBlock WithIndex_in_Indexed_for_ControlRelayOutputBlock(
//  ControlRelayOutputBlock* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_ControlRelayOutputBlock readFunc;
} BufferedCollection_Indexed_for_ControlRelayOutputBlock;

void  BufferedCollection_Indexed_for_ControlRelayOutputBlock_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(
  BufferedCollection_Indexed_for_ControlRelayOutputBlock *pBufferedCollection_Indexed_for_ControlRelayOutputBlock,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_ControlRelayOutputBlock readFunc);
BufferedCollection_Indexed_for_ControlRelayOutputBlock CreateBufferedCollection_Indexed_for_ControlRelayOutputBlock_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_ControlRelayOutputBlock readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(BufferedCollection_Indexed_for_ControlRelayOutputBlock *pBufferedCollection_Indexed_for_ControlRelayOutputBlock);
void Foreach_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock(BufferedCollection_Indexed_for_ControlRelayOutputBlock *pBufferedCollection_Indexed_for_ControlRelayOutputBlock,
    IVisitor__for__Indexed_for_ControlRelayOutputBlock* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock_override(void *pICollection_Indexed_for_ControlRelayOutputBlock);
void Foreach_in_BufferedCollection_Indexed_for_ControlRelayOutputBlock_override(void *pICollection_Indexed_for_ControlRelayOutputBlock,
    IVisitor__for__Indexed_for_ControlRelayOutputBlock* visitor);
//-----------------------------------Indexed_for_ControlRelayOutputBlock---------------------------------------------------
//-----------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------
typedef Indexed_for_DoubleBitBinary (*ReadFunc_Indexed_for_DoubleBitBinary)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_DoubleBitBinary iICollection_Indexed_for_DoubleBitBinary;
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

//Indexed_for_DoubleBitBinary WithIndex_in_Indexed_for_DoubleBitBinary(
//  DoubleBitBinary* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_DoubleBitBinary readFunc;
} BufferedCollection_Indexed_for_DoubleBitBinary;

void  BufferedCollection_Indexed_for_DoubleBitBinary_in_BufferedCollection_Indexed_for_DoubleBitBinary(
  BufferedCollection_Indexed_for_DoubleBitBinary *pBufferedCollection_Indexed_for_DoubleBitBinary,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_DoubleBitBinary readFunc);
BufferedCollection_Indexed_for_DoubleBitBinary CreateBufferedCollection_Indexed_for_DoubleBitBinary_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_DoubleBitBinary readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_DoubleBitBinary(BufferedCollection_Indexed_for_DoubleBitBinary *pBufferedCollection_Indexed_for_DoubleBitBinary);
void Foreach_in_BufferedCollection_Indexed_for_DoubleBitBinary(BufferedCollection_Indexed_for_DoubleBitBinary *pBufferedCollection_Indexed_for_DoubleBitBinary,
    IVisitor__for__Indexed_for_DoubleBitBinary* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_DoubleBitBinary_override(void *pICollection_Indexed_for_DoubleBitBinary);
void Foreach_in_BufferedCollection_Indexed_for_DoubleBitBinary_override(void *pICollection_Indexed_for_DoubleBitBinary,
    IVisitor__for__Indexed_for_DoubleBitBinary* visitor);
//-----------------------------------Indexed_for_DoubleBitBinary---------------------------------------------------
//-----------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------
typedef Indexed_for_BinaryCommandEvent (*ReadFunc_Indexed_for_BinaryCommandEvent)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_BinaryCommandEvent iICollection_Indexed_for_BinaryCommandEvent;
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

//Indexed_for_BinaryCommandEvent WithIndex_in_Indexed_for_BinaryCommandEvent(
//  BinaryCommandEvent* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_BinaryCommandEvent readFunc;
} BufferedCollection_Indexed_for_BinaryCommandEvent;

void  BufferedCollection_Indexed_for_BinaryCommandEvent_in_BufferedCollection_Indexed_for_BinaryCommandEvent(
  BufferedCollection_Indexed_for_BinaryCommandEvent *pBufferedCollection_Indexed_for_BinaryCommandEvent,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryCommandEvent readFunc);
BufferedCollection_Indexed_for_BinaryCommandEvent CreateBufferedCollection_Indexed_for_BinaryCommandEvent_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_BinaryCommandEvent readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_BinaryCommandEvent(BufferedCollection_Indexed_for_BinaryCommandEvent *pBufferedCollection_Indexed_for_BinaryCommandEvent);
void Foreach_in_BufferedCollection_Indexed_for_BinaryCommandEvent(BufferedCollection_Indexed_for_BinaryCommandEvent *pBufferedCollection_Indexed_for_BinaryCommandEvent,
    IVisitor__for__Indexed_for_BinaryCommandEvent* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_BinaryCommandEvent_override(void *pICollection_Indexed_for_BinaryCommandEvent);
void Foreach_in_BufferedCollection_Indexed_for_BinaryCommandEvent_override(void *pICollection_Indexed_for_BinaryCommandEvent,
    IVisitor__for__Indexed_for_BinaryCommandEvent* visitor);
//-----------------------------------Indexed_for_BinaryCommandEvent---------------------------------------------------
//-----------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------
typedef Indexed_for_AnalogCommandEvent (*ReadFunc_Indexed_for_AnalogCommandEvent)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_AnalogCommandEvent iICollection_Indexed_for_AnalogCommandEvent;
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

//Indexed_for_AnalogCommandEvent WithIndex_in_Indexed_for_AnalogCommandEvent(
//  AnalogCommandEvent* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_AnalogCommandEvent readFunc;
} BufferedCollection_Indexed_for_AnalogCommandEvent;

void  BufferedCollection_Indexed_for_AnalogCommandEvent_in_BufferedCollection_Indexed_for_AnalogCommandEvent(
  BufferedCollection_Indexed_for_AnalogCommandEvent *pBufferedCollection_Indexed_for_AnalogCommandEvent,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogCommandEvent readFunc);
BufferedCollection_Indexed_for_AnalogCommandEvent CreateBufferedCollection_Indexed_for_AnalogCommandEvent_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogCommandEvent readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogCommandEvent(BufferedCollection_Indexed_for_AnalogCommandEvent *pBufferedCollection_Indexed_for_AnalogCommandEvent);
void Foreach_in_BufferedCollection_Indexed_for_AnalogCommandEvent(BufferedCollection_Indexed_for_AnalogCommandEvent *pBufferedCollection_Indexed_for_AnalogCommandEvent,
    IVisitor__for__Indexed_for_AnalogCommandEvent* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_AnalogCommandEvent_override(void *pICollection_Indexed_for_AnalogCommandEvent);
void Foreach_in_BufferedCollection_Indexed_for_AnalogCommandEvent_override(void *pICollection_Indexed_for_AnalogCommandEvent,
    IVisitor__for__Indexed_for_AnalogCommandEvent* visitor);
//-----------------------------------Indexed_for_AnalogCommandEvent---------------------------------------------------
//-----------------------------------Indexed_for_TimeAndInterval---------------------------------------------------
typedef Indexed_for_TimeAndInterval (*ReadFunc_Indexed_for_TimeAndInterval)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_TimeAndInterval iICollection_Indexed_for_TimeAndInterval;
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

//Indexed_for_TimeAndInterval WithIndex_in_Indexed_for_TimeAndInterval(
//  TimeAndInterval* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_TimeAndInterval readFunc;
} BufferedCollection_Indexed_for_TimeAndInterval;

void  BufferedCollection_Indexed_for_TimeAndInterval_in_BufferedCollection_Indexed_for_TimeAndInterval(
  BufferedCollection_Indexed_for_TimeAndInterval *pBufferedCollection_Indexed_for_TimeAndInterval,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_TimeAndInterval readFunc);
BufferedCollection_Indexed_for_TimeAndInterval CreateBufferedCollection_Indexed_for_TimeAndInterval_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_TimeAndInterval readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_TimeAndInterval(BufferedCollection_Indexed_for_TimeAndInterval *pBufferedCollection_Indexed_for_TimeAndInterval);
void Foreach_in_BufferedCollection_Indexed_for_TimeAndInterval(BufferedCollection_Indexed_for_TimeAndInterval *pBufferedCollection_Indexed_for_TimeAndInterval,
    IVisitor__for__Indexed_for_TimeAndInterval* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_TimeAndInterval_override(void *pICollection_Indexed_for_TimeAndInterval);
void Foreach_in_BufferedCollection_Indexed_for_TimeAndInterval_override(void *pICollection_Indexed_for_TimeAndInterval,
    IVisitor__for__Indexed_for_TimeAndInterval* visitor);
//-----------------------------------Indexed_for_TimeAndInterval---------------------------------------------------
//-----------------------------------Indexed_for_Counter---------------------------------------------------
typedef Indexed_for_Counter (*ReadFunc_Indexed_for_Counter)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_Counter iICollection_Indexed_for_Counter;
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

//Indexed_for_Counter WithIndex_in_Indexed_for_Counter(
//  Counter* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_Counter readFunc;
} BufferedCollection_Indexed_for_Counter;

void  BufferedCollection_Indexed_for_Counter_in_BufferedCollection_Indexed_for_Counter(
  BufferedCollection_Indexed_for_Counter *pBufferedCollection_Indexed_for_Counter,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Counter readFunc);
BufferedCollection_Indexed_for_Counter CreateBufferedCollection_Indexed_for_Counter_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Counter readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_Counter(BufferedCollection_Indexed_for_Counter *pBufferedCollection_Indexed_for_Counter);
void Foreach_in_BufferedCollection_Indexed_for_Counter(BufferedCollection_Indexed_for_Counter *pBufferedCollection_Indexed_for_Counter,
    IVisitor__for__Indexed_for_Counter* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_Counter_override(void *pICollection_Indexed_for_Counter);
void Foreach_in_BufferedCollection_Indexed_for_Counter_override(void *pICollection_Indexed_for_Counter,
    IVisitor__for__Indexed_for_Counter* visitor);
//-----------------------------------Indexed_for_Counter---------------------------------------------------
//-----------------------------------Indexed_for_FrozenCounter---------------------------------------------------
typedef Indexed_for_FrozenCounter (*ReadFunc_Indexed_for_FrozenCounter)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_FrozenCounter iICollection_Indexed_for_FrozenCounter;
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

//Indexed_for_FrozenCounter WithIndex_in_Indexed_for_FrozenCounter(
//  FrozenCounter* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_FrozenCounter readFunc;
} BufferedCollection_Indexed_for_FrozenCounter;

void  BufferedCollection_Indexed_for_FrozenCounter_in_BufferedCollection_Indexed_for_FrozenCounter(
  BufferedCollection_Indexed_for_FrozenCounter *pBufferedCollection_Indexed_for_FrozenCounter,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_FrozenCounter readFunc);
BufferedCollection_Indexed_for_FrozenCounter CreateBufferedCollection_Indexed_for_FrozenCounter_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_FrozenCounter readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_FrozenCounter(BufferedCollection_Indexed_for_FrozenCounter *pBufferedCollection_Indexed_for_FrozenCounter);
void Foreach_in_BufferedCollection_Indexed_for_FrozenCounter(BufferedCollection_Indexed_for_FrozenCounter *pBufferedCollection_Indexed_for_FrozenCounter,
    IVisitor__for__Indexed_for_FrozenCounter* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_FrozenCounter_override(void *pICollection_Indexed_for_FrozenCounter);
void Foreach_in_BufferedCollection_Indexed_for_FrozenCounter_override(void *pICollection_Indexed_for_FrozenCounter,
    IVisitor__for__Indexed_for_FrozenCounter* visitor);
//-----------------------------------Indexed_for_FrozenCounter---------------------------------------------------
//-----------------------------------Indexed_for_Analog---------------------------------------------------
typedef Indexed_for_Analog (*ReadFunc_Indexed_for_Analog)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_Analog iICollection_Indexed_for_Analog;
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

//Indexed_for_Analog WithIndex_in_Indexed_for_Analog(
//  Analog* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_Analog readFunc;
} BufferedCollection_Indexed_for_Analog;

void  BufferedCollection_Indexed_for_Analog_in_BufferedCollection_Indexed_for_Analog(
  BufferedCollection_Indexed_for_Analog *pBufferedCollection_Indexed_for_Analog,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Analog readFunc);
BufferedCollection_Indexed_for_Analog CreateBufferedCollection_Indexed_for_Analog_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_Analog readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_Analog(BufferedCollection_Indexed_for_Analog *pBufferedCollection_Indexed_for_Analog);
void Foreach_in_BufferedCollection_Indexed_for_Analog(BufferedCollection_Indexed_for_Analog *pBufferedCollection_Indexed_for_Analog,
    IVisitor__for__Indexed_for_Analog* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_Analog_override(void *pICollection_Indexed_for_Analog);
void Foreach_in_BufferedCollection_Indexed_for_Analog_override(void *pICollection_Indexed_for_Analog,
    IVisitor__for__Indexed_for_Analog* visitor);
//-----------------------------------Indexed_for_Analog---------------------------------------------------
//-----------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------
typedef Indexed_for_AnalogOutputStatus (*ReadFunc_Indexed_for_AnalogOutputStatus)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_AnalogOutputStatus iICollection_Indexed_for_AnalogOutputStatus;
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

//Indexed_for_AnalogOutputStatus WithIndex_in_Indexed_for_AnalogOutputStatus(
//  AnalogOutputStatus* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_AnalogOutputStatus readFunc;
} BufferedCollection_Indexed_for_AnalogOutputStatus;

void  BufferedCollection_Indexed_for_AnalogOutputStatus_in_BufferedCollection_Indexed_for_AnalogOutputStatus(
  BufferedCollection_Indexed_for_AnalogOutputStatus *pBufferedCollection_Indexed_for_AnalogOutputStatus,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputStatus readFunc);
BufferedCollection_Indexed_for_AnalogOutputStatus CreateBufferedCollection_Indexed_for_AnalogOutputStatus_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputStatus readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputStatus(BufferedCollection_Indexed_for_AnalogOutputStatus *pBufferedCollection_Indexed_for_AnalogOutputStatus);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputStatus(BufferedCollection_Indexed_for_AnalogOutputStatus *pBufferedCollection_Indexed_for_AnalogOutputStatus,
    IVisitor__for__Indexed_for_AnalogOutputStatus* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputStatus_override(void *pICollection_Indexed_for_AnalogOutputStatus);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputStatus_override(void *pICollection_Indexed_for_AnalogOutputStatus,
    IVisitor__for__Indexed_for_AnalogOutputStatus* visitor);
//-----------------------------------Indexed_for_AnalogOutputStatus---------------------------------------------------
//-----------------------------------Indexed_for_AnalogOutputInt32---------------------------------------------------
typedef Indexed_for_AnalogOutputInt32 (*ReadFunc_Indexed_for_AnalogOutputInt32)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_AnalogOutputInt32 iICollection_Indexed_for_AnalogOutputInt32;
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

//Indexed_for_AnalogOutputInt32 WithIndex_in_Indexed_for_AnalogOutputInt32(
//  AnalogOutputInt32* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_AnalogOutputInt32 readFunc;
} BufferedCollection_Indexed_for_AnalogOutputInt32;

void  BufferedCollection_Indexed_for_AnalogOutputInt32_in_BufferedCollection_Indexed_for_AnalogOutputInt32(
  BufferedCollection_Indexed_for_AnalogOutputInt32 *pBufferedCollection_Indexed_for_AnalogOutputInt32,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputInt32 readFunc);
BufferedCollection_Indexed_for_AnalogOutputInt32 CreateBufferedCollection_Indexed_for_AnalogOutputInt32_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputInt32 readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputInt32(BufferedCollection_Indexed_for_AnalogOutputInt32 *pBufferedCollection_Indexed_for_AnalogOutputInt32);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputInt32(BufferedCollection_Indexed_for_AnalogOutputInt32 *pBufferedCollection_Indexed_for_AnalogOutputInt32,
    IVisitor__for__Indexed_for_AnalogOutputInt32* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputInt32_override(void *pICollection_Indexed_for_AnalogOutputInt32);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputInt32_override(void *pICollection_Indexed_for_AnalogOutputInt32,
    IVisitor__for__Indexed_for_AnalogOutputInt32* visitor);
//-----------------------------------Indexed_for_AnalogOutputInt32---------------------------------------------------
//-----------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------
typedef Indexed_for_AnalogOutputInt16 (*ReadFunc_Indexed_for_AnalogOutputInt16)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_AnalogOutputInt16 iICollection_Indexed_for_AnalogOutputInt16;
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

//Indexed_for_AnalogOutputInt16 WithIndex_in_Indexed_for_AnalogOutputInt16(
//  AnalogOutputInt32* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_AnalogOutputInt16 readFunc;
} BufferedCollection_Indexed_for_AnalogOutputInt16;

void  BufferedCollection_Indexed_for_AnalogOutputInt16_in_BufferedCollection_Indexed_for_AnalogOutputInt16(
  BufferedCollection_Indexed_for_AnalogOutputInt16 *pBufferedCollection_Indexed_for_AnalogOutputInt16,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputInt16 readFunc);
BufferedCollection_Indexed_for_AnalogOutputInt16 CreateBufferedCollection_Indexed_for_AnalogOutputInt16_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputInt16 readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputInt16(BufferedCollection_Indexed_for_AnalogOutputInt16 *pBufferedCollection_Indexed_for_AnalogOutputInt16);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputInt16(BufferedCollection_Indexed_for_AnalogOutputInt16 *pBufferedCollection_Indexed_for_AnalogOutputInt16,
    IVisitor__for__Indexed_for_AnalogOutputInt16* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputInt16_override(void *pICollection_Indexed_for_AnalogOutputInt16);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputInt16_override(void *pICollection_Indexed_for_AnalogOutputInt16,
    IVisitor__for__Indexed_for_AnalogOutputInt16* visitor);
//-----------------------------------Indexed_for_AnalogOutputInt16---------------------------------------------------
//-----------------------------------Indexed_for_AnalogOutputFloat32---------------------------------------------------
typedef Indexed_for_AnalogOutputFloat32 (*ReadFunc_Indexed_for_AnalogOutputFloat32)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_AnalogOutputFloat32 iICollection_Indexed_for_AnalogOutputFloat32;
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

//Indexed_for_AnalogOutputFloat32 WithIndex_in_Indexed_for_AnalogOutputFloat32(
//  AnalogOutputInt32* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_AnalogOutputFloat32 readFunc;
} BufferedCollection_Indexed_for_AnalogOutputFloat32;

void  BufferedCollection_Indexed_for_AnalogOutputFloat32_in_BufferedCollection_Indexed_for_AnalogOutputFloat32(
  BufferedCollection_Indexed_for_AnalogOutputFloat32 *pBufferedCollection_Indexed_for_AnalogOutputFloat32,
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputFloat32 readFunc);
BufferedCollection_Indexed_for_AnalogOutputFloat32 CreateBufferedCollection_Indexed_for_AnalogOutputFloat32_static(
  RSeq_for_Uint16_t* buffer,
  uint32_t count,
  ReadFunc_Indexed_for_AnalogOutputFloat32 readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputFloat32(BufferedCollection_Indexed_for_AnalogOutputFloat32 *pBufferedCollection_Indexed_for_AnalogOutputFloat32);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputFloat32(BufferedCollection_Indexed_for_AnalogOutputFloat32 *pBufferedCollection_Indexed_for_AnalogOutputFloat32,
    IVisitor__for__Indexed_for_AnalogOutputFloat32* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_AnalogOutputFloat32_override(void *pICollection_Indexed_for_AnalogOutputFloat32);
void Foreach_in_BufferedCollection_Indexed_for_AnalogOutputFloat32_override(void *pICollection_Indexed_for_AnalogOutputFloat32,
    IVisitor__for__Indexed_for_AnalogOutputFloat32* visitor);
//-----------------------------------Indexed_for_AnalogOutputFloat32---------------------------------------------------

////} // namespace opendnp3

#endif
