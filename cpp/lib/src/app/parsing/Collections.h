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
#ifndef OPENDNP3_COLLECTIONS_H
#define OPENDNP3_COLLECTIONS_H

#include "ICollection.h"

////#include <cstdint>

////namespace opendnp3
////{

/**
 * A simple collection derived from an underlying array
 */
////template<class T> class ArrayCollection : public ICollection<T>
////{
////public:
////  ArrayCollection(const T* pArray_, size_t count) : pArray(pArray_), COUNT(count) {}

////  virtual size_t Count() const override final
////  {
////    return COUNT;
////  }

////  virtual void Foreach(IVisitor<T>& visitor) const override final
////  {
////    for (uint32_t i = 0; i < COUNT; ++i)
////    {
////      visitor.OnValue(pArray[i]);
////    }
////  }

////private:
////  const T* pArray;
////  const size_t COUNT;
////};

//------------------------------Group50Var1_for_DNPTime-----------------------------------
typedef DNPTime (*Transform_Group50Var1_for_DNPTime)(Group50Var1*);
//Map<Group50Var1, DNPTime>
////template<class T, class U, class Transform> class TransformedCollection : public ICollection<U>
typedef struct
{
  ICollection_for_DNPTime iICollection_for_DNPTime;
////public:
////  TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}

////  virtual size_t Count() const override final
////  {
////    return input->Count();
////  }

////  virtual void Foreach(IVisitor<U>& visitor) const override final
////  {
////    auto process = [this, &visitor](const T& elem) {
////      visitor.OnValue(transform(elem));
////    };
////    input->ForeachItem(process);
////  }

////private:
////  ICollection<T>* input;
  ICollection_for_Group50Var1* input;
////  Transform transform;
  Transform_Group50Var1_for_DNPTime transform;
} TransformedCollection_Group50Var1_for_DNPTime;

void TransformedCollection_Group50Var1_for_DNPTime_in_TransformedCollection_Group50Var1_for_DNPTime(TransformedCollection_Group50Var1_for_DNPTime *pTransformedCollection_Group50Var1_for_DNPTime,
    ICollection_for_Group50Var1* input, Transform_Group50Var1_for_DNPTime transform);
TransformedCollection_Group50Var1_for_DNPTime Map_in_TransformedCollection_Group50Var1_for_DNPTime(ICollection_for_Group50Var1* input, Transform_Group50Var1_for_DNPTime transform);

uint16_t Count_in_TransformedCollection_Group50Var1_for_DNPTime(TransformedCollection_Group50Var1_for_DNPTime *pTransformedCollection_Group50Var1_for_DNPTime);
void Foreach_in_TransformedCollection_Group50Var1_for_DNPTime(TransformedCollection_Group50Var1_for_DNPTime *pTransformedCollection_Group50Var1_for_DNPTime, IVisitor__for__DNPTime* visitor);

uint16_t Count_in_TransformedCollection_Group50Var1_for_DNPTime_override(void*);
void Foreach_in_TransformedCollection_Group50Var1_for_DNPTime_override(void*, IVisitor__for__DNPTime* visitor);
//------------------------------Group50Var1_for_DNPTime-----------------------------------
//------------------------------Indexed_for_Binary-----------------------------------
typedef Indexed_for_Binary (*Transform_Indexed_for_Binary)(Indexed_for_Binary*);
//Map<Group50Var1, DNPTime>
////template<class T, class U, class Transform> class TransformedCollection : public ICollection<U>
typedef struct
{
  ICollection_Indexed_for_Binary iICollection_Indexed_for_Binary;
////public:
////  TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}

////  virtual size_t Count() const override final
////  {
////    return input->Count();
////  }

////  virtual void Foreach(IVisitor<U>& visitor) const override final
////  {
////    auto process = [this, &visitor](const T& elem) {
////      visitor.OnValue(transform(elem));
////    };
////    input->ForeachItem(process);
////  }

////private:
////  ICollection<T>* input;
  ICollection_Indexed_for_Binary* input;
////  Transform transform;
  Transform_Indexed_for_Binary transform;
} TransformedCollection_Indexed_for_Binary;

void TransformedCollection_Indexed_for_Binary_in_TransformedCollection_Indexed_for_Binary(TransformedCollection_Indexed_for_Binary *pTransformedCollection_Indexed_for_Binary,
    ICollection_Indexed_for_Binary* input, Transform_Indexed_for_Binary transform);
TransformedCollection_Indexed_for_Binary Map_in_TransformedCollection_Indexed_for_Binary(ICollection_Indexed_for_Binary* input, Transform_Indexed_for_Binary transform);

uint16_t Count_in_TransformedCollection_Indexed_for_Binary(TransformedCollection_Indexed_for_Binary *pTransformedCollection_Indexed_for_Binary);
void Foreach_in_TransformedCollection_Indexed_for_Binary(TransformedCollection_Indexed_for_Binary *pTransformedCollection_Indexed_for_Binary, IVisitor__for__Indexed_for_Binary* visitor);

uint16_t Count_in_TransformedCollection_Indexed_for_Binary_override(void*);
void Foreach_in_TransformedCollection_Indexed_for_Binary_override(void*, IVisitor__for__Indexed_for_Binary* visitor);
//------------------------------Indexed_for_Binary-----------------------------------
//------------------------------Indexed_for_DoubleBitBinary-----------------------------------
typedef Indexed_for_DoubleBitBinary (*Transform_Indexed_for_DoubleBitBinary)(Indexed_for_DoubleBitBinary*);
//Map<Group50Var1, DNPTime>
////template<class T, class U, class Transform> class TransformedCollection : public ICollection<U>
typedef struct
{
  ICollection_Indexed_for_DoubleBitBinary iICollection_Indexed_for_DoubleBitBinary;
////public:
////  TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}

////  virtual size_t Count() const override final
////  {
////    return input->Count();
////  }

////  virtual void Foreach(IVisitor<U>& visitor) const override final
////  {
////    auto process = [this, &visitor](const T& elem) {
////      visitor.OnValue(transform(elem));
////    };
////    input->ForeachItem(process);
////  }

////private:
////  ICollection<T>* input;
  ICollection_Indexed_for_DoubleBitBinary* input;
////  Transform transform;
  Transform_Indexed_for_DoubleBitBinary transform;
} TransformedCollection_Indexed_for_DoubleBitBinary;

void TransformedCollection_Indexed_for_DoubleBitBinary_in_TransformedCollection_Indexed_for_DoubleBitBinary(TransformedCollection_Indexed_for_DoubleBitBinary *pTransformedCollection_Indexed_for_DoubleBitBinary,
    ICollection_Indexed_for_DoubleBitBinary* input, Transform_Indexed_for_DoubleBitBinary transform);
TransformedCollection_Indexed_for_DoubleBitBinary Map_in_TransformedCollection_Indexed_for_DoubleBitBinary(ICollection_Indexed_for_DoubleBitBinary* input, Transform_Indexed_for_DoubleBitBinary transform);

uint16_t Count_in_TransformedCollection_Indexed_for_DoubleBitBinary(TransformedCollection_Indexed_for_DoubleBitBinary *pTransformedCollection_Indexed_for_DoubleBitBinary);
void Foreach_in_TransformedCollection_Indexed_for_DoubleBitBinary(TransformedCollection_Indexed_for_DoubleBitBinary *pTransformedCollection_Indexed_for_DoubleBitBinary, IVisitor__for__Indexed_for_DoubleBitBinary* visitor);

uint16_t Count_in_TransformedCollection_Indexed_for_DoubleBitBinary_override(void*);
void Foreach_in_TransformedCollection_Indexed_for_DoubleBitBinary_override(void*, IVisitor__for__Indexed_for_DoubleBitBinary* visitor);
//------------------------------Indexed_for_DoubleBitBinary-----------------------------------

////} // namespace opendnp3

#endif
