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

//-----------------------------------Indexed_for_Group1Var2---------------------------------------------------
typedef Indexed_for_Group1Var2 (*ReadFunc_Indexed_for_Group1Var2)(
  RSeq_for_Uint16_t* buffer,
  uint32_t pos);

////template<class T, class ReadFunc> class BufferedCollection : public ICollection<T>
typedef struct
{
  ICollection_Indexed_for_Group1Var2 iICollection_Indexed_for_Group1Var2;
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
  uint16_t COUNT;

//Indexed_for_Group1Var2 WithIndex_in_Indexed_for_Group1Var2(
//  Group1Var2* value, uint16_t index);
////    auto read = [range](ser4cpp::rseq_t& buffer, uint32_t pos) {
////    ReadFunc readFunc;
  ReadFunc_Indexed_for_Group1Var2 readFunc;
} BufferedCollection_Indexed_for_Group1Var2;

void  BufferedCollection_Indexed_for_Group1Var2_in_BufferedCollection_Indexed_for_Group1Var2(
  BufferedCollection_Indexed_for_Group1Var2 *pBufferedCollection_Indexed_for_Group1Var2,
  RSeq_for_Uint16_t* buffer,
  uint16_t count,
  ReadFunc_Indexed_for_Group1Var2 readFunc);
BufferedCollection_Indexed_for_Group1Var2 CreateBufferedCollection_Indexed_for_Group1Var2_static(
  RSeq_for_Uint16_t* buffer,
  uint16_t count,
  ReadFunc_Indexed_for_Group1Var2 readFunc);

uint16_t Count_in_BufferedCollection_Indexed_for_Group1Var2(BufferedCollection_Indexed_for_Group1Var2 *pBufferedCollection_Indexed_for_Group1Var2);
void Foreach_in_BufferedCollection_Indexed_for_Group1Var2(BufferedCollection_Indexed_for_Group1Var2 *pBufferedCollection_Indexed_for_Group1Var2,
    IVisitor__for__Indexed_for_Group1Var2* visitor);


uint16_t Count_in_BufferedCollection_Indexed_for_Group1Var2_override(void *pICollection_Indexed_for_Group1Var2);
void Foreach_in_BufferedCollection_Indexed_for_Group1Var2_override(void *pICollection_Indexed_for_Group1Var2,
    IVisitor__for__Indexed_for_Group1Var2* visitor);


//-----------------------------------Indexed_for_Group1Var2---------------------------------------------------
////} // namespace opendnp3

#endif
