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

#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "ICollection.h"

///#include <cstdint>

////namespace opendnp3
////{

/**
 * A simple collection derived from an underlying array
 */
template<class T> class ArrayCollection : public ICollection<T>
{
public:
    ArrayCollection(const T* pArray_, size_t count) : pArray(pArray_), COUNT(count) {}

    virtual size_t Count() const override final
    {
        return COUNT;
    }

    virtual void Foreach(IVisitor<T>& visitor) const override final
    {
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Foreach_in_ArrayCollection1"<<'\n';
#endif
        for (uint32_t i = 0; i < COUNT; ++i)
        {

#ifdef  LOG_INFO
            std::cout<<getString_stack_info();
            std::cout<<"{for (uint32_t i = 0; i < COUNT; ++i)1"<<'\n';
#endif
            visitor.OnValue(pArray[i]);
#ifdef  LOG_INFO
            std::cout<<getString_stack_info();
            std::cout<<"}for (uint32_t i = 0; i < COUNT; ++i)_"<<'\n';
#endif
        }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Foreach_in_ArrayCollection_"<<'\n';
  decrement_stack_info();
#endif
    }

private:
    const T* pArray;
    const size_t COUNT;
};

template<class T, class U, class Transform> class TransformedCollection : public ICollection<U>
{
public:
    TransformedCollection(const ICollection<T>& input, Transform transform) : input(&input), transform(transform) {}

    virtual size_t Count() const override final
    {
        return input->Count();
    }

    virtual void Foreach(IVisitor<U>& visitor) const override final
    {
#ifdef  LOG_INFO
        std::cout<<'\n';
        increment_stack_info();
        std::cout<<getString_stack_info();
        std::cout<<"{Foreach_in_TransformedCollection1"<<'\n';
#endif
        auto process = [this, &visitor](const T& elem)
        { 
#ifdef  LOG_INFO
        std::cout<<'\n';
        increment_stack_info();
        std::cout<<getString_stack_info();
        std::cout<<"{process_in_TransformedCollection1"<<'\n';
#endif
              visitor.OnValue(transform(elem));
#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"}process_in_TransformedCollection1"<<'\n';
        decrement_stack_info();
#endif
        };
        input->ForeachItem(process);
#ifdef  LOG_INFO
        std::cout<<getString_stack_info();
        std::cout<<"}Foreach_in_TransformedCollection_"<<'\n';
        decrement_stack_info();
#endif
    }

private:
    const ICollection<T>* input;
    Transform transform;
};

template<class T, class U, class Transform>
TransformedCollection<T, U, Transform> Map(const ICollection<T>& input, Transform transform)
{
    return TransformedCollection<T, U, Transform>(input, transform);
}

////} // namespace opendnp3

#endif
