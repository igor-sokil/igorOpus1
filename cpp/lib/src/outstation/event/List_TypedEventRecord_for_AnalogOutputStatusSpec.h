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
#ifndef OPENDNP3_List_TypedEventRecord_for_AnalogOutputStatusSpec_H
#define OPENDNP3_List_TypedEventRecord_for_AnalogOutputStatusSpec_H

#include "HasLength.h"
//#include "EventRecord.h"
////#include <ser4cpp/container/Array.h>
#include "Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec.h"
#include "Node_TypedEventRecord_for_AnalogOutputStatusSpec.h"

////#include <cstdint>

////namespace opendnp3
////{

////using list_size_type_t = uint32_t;
////    class Iterator
typedef struct
{
////    public:
////        static Iterator From(Node<T>* start)
////        {
////            return Iterator(start);
////        }
////
////        template<class U> T* Find(const U& matches);

////        bool HasNext() const
////        {
////            return this->current;
////        }

////        Node<T>* Next()
////        {
////            if (!this->current)
////                return nullptr;
////            auto ret = this->current;
////            this->current = this->current->next;
////            return ret;
////        }

////        inline Node<T>* Current()
////        {
////            return this->current;
////        }

////        inline T* CurrentValue()
////        {
////            return (this->current) ? &(this->current->value) : nullptr;
////        }

////    private:
////        Iterator(Node<T>* start) : current(start) {}
////
////        Node<T>* current;
  Node_TypedEventRecord_for_AnalogOutputStatusSpec * current;
} Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec;

Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec From__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(Node_TypedEventRecord_for_AnalogOutputStatusSpec* start);

TypedEventRecord_for_AnalogOutputStatusSpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec);
Node_TypedEventRecord_for_AnalogOutputStatusSpec* Current__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec);
Node_TypedEventRecord_for_AnalogOutputStatusSpec* Next__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec);
boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec);

void  Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec,
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* start);

// A container adapter for a -linked list
////template<class T> class List : public ser4cpp::HasLength<list_size_type_t>
typedef struct
{
////public:
////    class Iterator
////    {
////    public:
////        static Iterator From(Node<T>* start)
////        {
////            return Iterator(start);
////        }
////
////        template<class U> T* Find(const U& matches);

////        bool HasNext() const
////        {
////            return this->current;
////        }

////        Node<T>* Next()
////        {
////            if (!this->current)
////                return nullptr;
////            auto ret = this->current;
////            this->current = this->current->next;
////            return ret;
////        }

////        inline Node<T>* Current()
////        {
////            return this->current;
////        }

////        inline T* CurrentValue()
////        {
////            return (this->current) ? &(this->current->value) : nullptr;
////        }

////    private:
////        Iterator(Node<T>* start) : current(start) {}
////
////        Node<T>* current;
////    };
////
////    List(list_size_type_t maxSize) : ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)
////    {
////        Initialize();
////    }
////
////    inline list_size_type_t Capacity() const
////    {
////        return underlying.length();
////    }
////
////    inline Node<T>* Head()
////    {
////        return this->head;
////    }

////    inline Iterator Iterate() const
////    {
////        return Iterator::From(this->head);
////    }

////    Node<T>* Add(const T& value);
////
////    template<class U> void ForeachWhile(const U& select);
////
////    template<class U> void Foreach(const U& action);
////
////    template<class U> list_size_type_t RemoveAll(const U& match);
////
////    void Remove(Node<T>* node);
////
////    inline bool IsFullAndCapacityNotZero() const;
////
////private:
////    Node<T>* head = nullptr;
////    Node<T>* tail = nullptr;
////    Node<T>* free = nullptr;
  Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec iIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec;
  HasLength_for_Uint32_t hHasLength_for_Uint32_t;

  Node_TypedEventRecord_for_AnalogOutputStatusSpec* head;// = nullptr;
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* tail;// = nullptr;
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* free;// = nullptr;

////    ser4cpp::Array<Node<T>, list_size_type_t> underlying;
  Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec  underlying;

////    Node<T>* Insert(const T& value, Node<T>* left, Node<T>* right);

////    inline static void Link(Node<T>* prev, Node<T>* next);

////    void Initialize();
} List_TypedEventRecord_for_AnalogOutputStatusSpec;

void List_TypedEventRecord_for_AnalogOutputStatusSpec_in_List_TypedEventRecord_for_AnalogOutputStatusSpecOver1(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec);
void List_TypedEventRecord_for_AnalogOutputStatusSpec_in_List_TypedEventRecord_for_AnalogOutputStatusSpecOver2(
  List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
  uint32_t maxSize);
Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec Iterate_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec);

void Initialize_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec);
//  uint32_t RemoveAll_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(EventStorage *pEventStorage,
//                            List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
//                            boolean (*match)(EventStorage *pEventStorage,
//                            EventRecord* record));//const U& match);

void Remove_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec, Node_TypedEventRecord_for_AnalogOutputStatusSpec* node);
void Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(Node_TypedEventRecord_for_AnalogOutputStatusSpec* first, Node_TypedEventRecord_for_AnalogOutputStatusSpec* second);

uint32_t Capacity_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec);
boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec);
Node_TypedEventRecord_for_AnalogOutputStatusSpec* Head_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec);

Node_TypedEventRecord_for_AnalogOutputStatusSpec* Add_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
    TypedEventRecord_for_AnalogOutputStatusSpec* value);
Node_TypedEventRecord_for_AnalogOutputStatusSpec* Insert_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
    TypedEventRecord_for_AnalogOutputStatusSpec* value,
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* left,
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* right
                                                                                                            );

////template<class T> Node<T>* List<T>::Add(const T& value)
////{
////    return this->Insert(value, this->tail, nullptr);
////}
////
////template<class T> template<class U> void List<T>::ForeachWhile(const U& select)
////{
////    auto iter = this->Iterate();
////    bool result = true;
////    while (result && iter.HasNext())
////    {
////        result = select(iter.Next()->value);
////    }
////}
////
////template<class T> template<class U> void List<T>::Foreach(const U& action)
////{
////    auto iter = this->Iterate();
////    while (iter.HasNext())
////    {
////        action(iter.Next()->value);
////    }
////}
////
////template<class T> template<class U> list_size_type_t List<T>::RemoveAll(const U& match)
////{
////    list_size_type_t count = 0;
////
////    auto iter = this->Iterate();
////    auto current = iter.Next();
////    while (current)
////    {
////        if (match(current->value))
////        {
////            auto removed = current;
////            current = iter.Next();
////            this->Remove(removed);
////            ++count;
////        }
////        else
////        {
////            current = iter.Next();
////        }
////    }
////
////    return count;
////}
////
////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
////{
////    if (!this->free)
////        return nullptr;
////
////    // initialize the new node, and increment the size
////    auto new_node = this->free;
////    this->free = this->free->next;
////
////    new_node->value = value;
////    ++(this->m_length);
////
////    this->Link(left, new_node);
////    this->Link(new_node, right);
////
////    // change of head
////    if (!left)
////    {
////        this->head = new_node;
////    }
////
////    // change of tail
////    if (!right)
////    {
////        this->tail = new_node;
////    }
////
////    return new_node;
////}
////
////template<class T> void List<T>::Remove(Node<T>* node)
////{
////    if (node == this->head) // change of head
////    {
////        this->head = node->next;
////    }
////
////    if (node == this->tail) // change of tail
////    {
////        this->tail = this->tail->prev;
////    }
////
// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
////
////    // node becomes the head of the free list
////    node->prev = nullptr;
////    this->Link(node, this->free);
////    this->free = node;
////
////    --(this->m_length);
////}
////
////template<class T> bool List<T>::IsFullAndCapacityNotZero() const
////{
////    return !(this->free) && Capacity() > 0;
////}
////
////template<class T> void List<T>::Link(Node<T>* first, Node<T>* second)
////{
////    if (first)
////        first->next = second;
////    if (second)
////        second->prev = first;
////}
////
////template<class T> void List<T>::Initialize()
////{
////    if (underlying.is_empty())
////        return;
////
////    this->free = &underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
////    {
////        Link(&underlying[i - 1], &underlying[i]);
////    }
////}
////
////template<class T> template<class U> T* List<T>::Iterator::Find(const U& matches)
////{
////    while (this->current)
////    {
////        if (matches(this->current->value))
////        {
////            return &(this->current->value);
////        }
////
////        this->current = this->current->next;
////    }
////
////    return nullptr;
////}
////
////} // namespace opendnp3

#endif
