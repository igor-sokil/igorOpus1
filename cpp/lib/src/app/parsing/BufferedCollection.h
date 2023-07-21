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
#include "NumParser.h"
#include "Indexed.h"
#include "RSeq.h"

////namespace opendnp3
////{
//-----------------------------------BufferedCollection_for_Int16----------------------------------
////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
ICollection_Indexed_Group2Var1  iICollection_Indexed_Group2Var1;
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
////
////        for (uint32_t pos = 0; pos < COUNT; ++pos)
////        {
////            visitor.OnValue(readFunc(copy, pos));
////        }
////    }

////private:
    RSeq_for_Uint16_t buffer;
    uint16_t COUNT;
    ReadFunc_in_BufferedCollection_for_UInt16 readFunc;
   /* NumParser* numparser;*/
} BufferedCollection_for_UInt16;

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
////{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
////}

//-----------------------------------BufferedCollection_for_Int16----------------------------------

//-----------------------------------Indexed_Group2Var1_in_CountIndexParser----------------------------------
    typedef Indexed_for_Group2Var1 (*ReadFunc_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser)
                                                            (/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t c);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
ICollection_Indexed_Group2Var1  iICollection_Indexed_Group2Var1;
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
////
////        for (uint32_t pos = 0; pos < COUNT; ++pos)
////        {
////            visitor.OnValue(readFunc(copy, pos));
////        }
////    }

////private:
    RSeq_for_Uint16_t buffer;
    uint16_t COUNT;
    ReadFunc_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser readFunc;
   /* NumParser* numparser;*/
} BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser;

//    uint16_t Count_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_override(void* pICollection_Indexed_Group2Var1);

//costructor BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser
void BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser(
           BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser *pBufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser,
           NumParser* pNumParser, RSeq_for_Uint16_t* buffer, uint16_t count,
           Indexed_for_Group2Var1 (*read)(/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t c));

////template<class T, class ReadFunc>
////BufferedCollection<T, ReadFunc> CreateBufferedCollection(const ser4cpp::rseq_t& buffer,
////                                                         size_t count,
////                                                         const ReadFunc& readFunc)
////{
////    return BufferedCollection<T, ReadFunc>(buffer, count, readFunc);
////}
//function CreateBufferedCollection_Indexed_Group2Var1
    BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser 
   CreateBufferedCollection_Indexed_Group2Var1(
           /*NumParser*,*/ RSeq_for_Uint16_t*, uint16_t c,
           Indexed_for_Group2Var1 (*read)((/*NumParser* numparser,*/ RSeq_for_Uint16_t* buffer, uint32_t c)));

   void Foreach_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_override(void* pICollection_Indexed_Group2Var1,
                                       IVisitor_Indexed_for_Group2Var1* visitor);
    uint16_t Count_in_BufferedCollection_for_Indexed_Group2Var1_in_CountIndexParser_override(void* pICollection_Indexed_Group2Var1);


////    virtual void Foreach(IVisitor<T>& visitor) const final
////    {
////        ser4cpp::rseq_t copy(buffer);
////
////        for (uint32_t pos = 0; pos < COUNT; ++pos)
////        {
////            visitor.OnValue(readFunc(copy, pos));
////        }
////    }

//-----------------------------------Indexed_Group2Var1_in_CountIndexParser----------------------------------

////} // namespace opendnp3

#endif
