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
#ifndef OPENDNP3_LIST_for_UserRecord_H
#define OPENDNP3_LIST_for_UserRecord_H

#include "HasLength.h"
//#include "int.h"
////#include <ser4cpp/container/Array.h>
#include "Array__for__Node_for_UserRecord.h"
#include "Node_for_UserRecord.h"

////#include <cstdint>

//#include "EventStorage.h"
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
  Node_for_UserRecord * current;
} Iterator_in_List_for_UserRecord;

Iterator_in_List_for_UserRecord From__in__Iterator_in_List_for_UserRecord_static(Node_for_UserRecord* start);

UserRecord* CurrentValue__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord);
Node_for_UserRecord* Current__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord);
Node_for_UserRecord* Next__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord);
boolean HasNext__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord);

void  Iterator_in_List_for_UserRecord__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
    Node_for_UserRecord* start);
UserRecord *Find__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
    boolean (*matches)(UserRecord* pUserRecord));

////template<class T> template<class U> T* List<T>::Iterator::Find(const U& matches)
// A container adapter for a -linked list
////template<class T> class List : public ser4cpp::HasLength<list_size_type_t>
typedef struct
{
  Iterator_in_List_for_UserRecord iIterator_in_List_for_UserRecord;
  HasLength_for_Uint32_t hHasLength_for_Uint32_t;

  Node_for_UserRecord* head;// = nullptr;
  Node_for_UserRecord* tail;// = nullptr;
  Node_for_UserRecord* free;// = nullptr;

////    ser4cpp::Array<Node<T>, list_size_type_t> underlying;
  Array__for__Node_for_UserRecord  underlying;

} List_for_UserRecord;

////    List(list_size_type_t maxSize) : ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)

void List_for_UserRecord_in_List_for_UserRecordOver2(List_for_UserRecord *pList_for_UserRecord, uint32_t maxSize);
void List_for_UserRecord_in_List_for_UserRecordOver1(List_for_UserRecord *pList_for_UserRecord);
Iterator_in_List_for_UserRecord Iterate_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord);

void Initialize_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord);

void Remove_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord, Node_for_UserRecord* node);
void Link_in_List_for_UserRecord_static(Node_for_UserRecord* first, Node_for_UserRecord* second);

uint32_t Capacity_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord);
boolean IsFullAndCapacityNotZero_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord);
Node_for_UserRecord* Head_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord);
Node_for_UserRecord* Add_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord, UserRecord* value);
Node_for_UserRecord*  Insert_in_List_for_UserRecord(List_for_UserRecord* pList_for_UserRecord,
    UserRecord* value, Node_for_UserRecord* left,
    Node_for_UserRecord* right);
void    Foreach_in_List_for_UserRecord(
  List_for_UserRecord *pList_for_UserRecord,
  void (*action)(UserRecord* record)
);
uint16_t RemoveAll_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord, boolean (*match)(UserRecord));



#endif
