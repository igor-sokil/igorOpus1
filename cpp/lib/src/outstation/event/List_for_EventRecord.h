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
#ifndef OPENDNP3_LIST_for_EventRecord_H
#define OPENDNP3_LIST_for_EventRecord_H

#include <string.h>
#include "HasLength.h"
#include "EventRecord.h"
////#include <ser4cpp/container/Array.h>
#include "Node_for_EventRecord.h"

////#include <cstdint>

//#include "EventStorage.h"
////namespace opendnp3
////{

////using list_size_type_t = uint32_t;
/*
////template<class T> class Node
typedef struct
{
////public:
////    Node() = default;

////    T value;
  EventRecord value;

////private:
////    Node* prev = nullptr;
////    Node_for_EventRecord * prev;
  void * prev;
////    Node_for_EventRecord * next;
  void * next;
////    Node* next = nullptr;

////    template<class U> friend class List;
} Node_for_EventRecord;

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord);
*/
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
  Node_for_EventRecord * current;
} Iterator_in_List_for_EventRecord;

Iterator_in_List_for_EventRecord From__in__Iterator_in_List_for_EventRecord_static(Node_for_EventRecord* start);

EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
Node_for_EventRecord* Current__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);
boolean HasNext__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);

void  Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord,
    Node_for_EventRecord* start);

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
////MYTODO
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
  Iterator_in_List_for_EventRecord iIterator_in_List_for_EventRecord;
  HasLength_for_Uint32_t hHasLength_for_Uint32_t;

  Node_for_EventRecord* head;// = nullptr;
  Node_for_EventRecord* tail;// = nullptr;
  Node_for_EventRecord* free;// = nullptr;

////    ser4cpp::Array<Node<T>, list_size_type_t> underlying;MYTODO

////    Node<T>* Insert(const T& value, Node<T>* left, Node<T>* right);

////    inline static void Link(Node<T>* prev, Node<T>* next);

////    void Initialize();
} List_for_EventRecord;

////    List(list_size_type_t maxSize) : ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)
////    {
////        Initialize();
////    }

void List_for_EventRecord_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord);
//Iterator_in_List_for_EventRecord From__in__Iterator_in_List_for_EventRecord_static(Node_for_EventRecord* start);
    Iterator_in_List_for_EventRecord Iterate_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord);

////  uint32_t RemoveAll_in_List_for_EventRecord(EventStorage *pEventStorage, List_for_EventRecord *pList_for_EventRecord, boolean (*match)(EventStorage *pEventStorage, EventRecord* record));//const U& match);

   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
   void Link_in_List_for_EventRecord_static(Node_for_EventRecord* first, Node_for_EventRecord* second);

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

////
////template<class T> bool List<T>::IsFullAndCapacityNotZero() const
////{
////    return !(this->free) && Capacity() > 0;
////}
////
//    inline static void Link(Node<T>* prev, Node<T>* next);
////template<class T> void List<T>::Link(Node<T>* first, Node<T>* second)
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
