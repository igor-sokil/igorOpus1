#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "List_for_UserRecord.h"
#include <string.h>

void List_for_UserRecord_in_List_for_UserRecordOver1(List_for_UserRecord *pList_for_UserRecord)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"List_for_UserRecord_in_List_for_UserRecordOver1_1"<<'\n';
  decrement_stack_info();
#endif
  Array__for__Node_for_UserRecord_in_Array__for__Node_for_UserRecordOver1(&(pList_for_UserRecord->underlying));
  (pList_for_UserRecord->iIterator_in_List_for_UserRecord).current = NULL;

  pList_for_UserRecord->head = NULL;
  pList_for_UserRecord->tail = NULL;
  pList_for_UserRecord->free = NULL;
}

void List_for_UserRecord_in_List_for_UserRecordOver2(List_for_UserRecord *pList_for_UserRecord, uint32_t maxSize)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"List_for_UserRecord_in_List_for_UserRecordOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maxSize= "<<maxSize<<'\n';
  decrement_stack_info();
#endif
  List_for_UserRecord_in_List_for_UserRecordOver1(pList_for_UserRecord);
// ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_for_UserRecord->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_for_UserRecord_in_Array__for__Node_for_UserRecordOver2(Array__for__Node_for_UserRecord *pArray__for__Node_for_UserRecord, uint32_t size);
  Array__for__Node_for_UserRecord_in_Array__for__Node_for_UserRecordOver2(&(pList_for_UserRecord->underlying), maxSize);
  Initialize_in_List_for_UserRecord(pList_for_UserRecord);
}

Iterator_in_List_for_UserRecord From__in__Iterator_in_List_for_UserRecord_static(Node_for_UserRecord* start)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"From__in__Iterator_in_List_for_UserRecord_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_UserRecord* start= "<<(uint32_t)start<<'\n';
  decrement_stack_info();
#endif
////            return Iterator(start);
  Iterator_in_List_for_UserRecord iIterator_in_List_for_UserRecord;
  Iterator_in_List_for_UserRecord__in__Iterator_in_List_for_UserRecord(&iIterator_in_List_for_UserRecord, start);
  return iIterator_in_List_for_UserRecord;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord)
{
  if(pIterator_in_List_for_UserRecord->current) return true;
  return false;
}

Node_for_UserRecord* Next__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord)
{
  if (!pIterator_in_List_for_UserRecord->current) return NULL;
  Node_for_UserRecord* ret = pIterator_in_List_for_UserRecord->current;
  pIterator_in_List_for_UserRecord->current = (Node_for_UserRecord*)pIterator_in_List_for_UserRecord->current->next;
  return ret;
}

Node_for_UserRecord* Current__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord)
{
  return pIterator_in_List_for_UserRecord->current;
}

UserRecord* CurrentValue__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord)
{
  return (pIterator_in_List_for_UserRecord->current) ? &(pIterator_in_List_for_UserRecord->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void Iterator_in_List_for_UserRecord__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
    Node_for_UserRecord* start)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Iterator_in_List_for_UserRecord__in__Iterator_in_List_for_UserRecord1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_UserRecord* start= "<<(uint32_t)start<<'\n';
  decrement_stack_info();
#endif
  pIterator_in_List_for_UserRecord->current = start;
}

Iterator_in_List_for_UserRecord Iterate_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Iterate_in_List_for_UserRecord1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pList_for_UserRecord->head= "<<(uint32_t)pList_for_UserRecord->head<<'\n';
#endif
//        return Iterator::From(pList_for_UserRecord->head);
  Iterator_in_List_for_UserRecord tmp = From__in__Iterator_in_List_for_UserRecord_static(pList_for_UserRecord->head);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}

void Remove_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord, Node_for_UserRecord* node)
{
////    if (node == this->head) // change of head
  if (node == pList_for_UserRecord->head) // change of head
  {
////        this->head = node->next;
    pList_for_UserRecord->head = (Node_for_UserRecord*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_for_UserRecord->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_for_UserRecord->tail = (Node_for_UserRecord *)pList_for_UserRecord->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_UserRecord_static(Node_for_UserRecord* first, Node_for_UserRecord* second)
  Link_in_List_for_UserRecord_static((Node_for_UserRecord*)node->prev, (Node_for_UserRecord*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_for_UserRecord_static(node, pList_for_UserRecord->free);
////    this->free = node;
  pList_for_UserRecord->free = node;

////    --(this->m_length);
  --((pList_for_UserRecord->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_for_UserRecord_static(Node_for_UserRecord* first, Node_for_UserRecord* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void Initialize_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_for_UserRecord -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_for_UserRecord->free = &((pList_for_UserRecord->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_for_UserRecord -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_for_UserRecord_static(&((pList_for_UserRecord->underlying).buffer[i - 1]),
                                        &((pList_for_UserRecord->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_for_UserRecord->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord)
{
  return !(pList_for_UserRecord->free) && Capacity_in_List_for_UserRecord(pList_for_UserRecord) > 0;
}

Node_for_UserRecord* Head_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord)
{
  return pList_for_UserRecord->head;
}

Node_for_UserRecord* Add_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord, UserRecord* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return  Insert_in_List_for_UserRecord(pList_for_UserRecord, value, pList_for_UserRecord->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_for_UserRecord*  Insert_in_List_for_UserRecord(List_for_UserRecord* pList_for_UserRecord,
    UserRecord* value, Node_for_UserRecord* left,
    Node_for_UserRecord* right)
{
  if (!pList_for_UserRecord->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_for_UserRecord* new_node = pList_for_UserRecord->free;
  pList_for_UserRecord->free = (Node_for_UserRecord*)pList_for_UserRecord->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_for_UserRecord->hHasLength_for_Uint32_t).m_length);

//   void Link_in_List_for_UserRecord_static(Node_for_UserRecord* first, Node_for_UserRecord* second);
////    this->Link(left, new_node);
  Link_in_List_for_UserRecord_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_for_UserRecord_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_for_UserRecord->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_for_UserRecord->tail = new_node;
  }

  return new_node;
}

UserRecord *Find__in__Iterator_in_List_for_UserRecord(Iterator_in_List_for_UserRecord *pIterator_in_List_for_UserRecord,
    boolean (*matches)(UserRecord* pUserRecord))
{
////    while (this->current)
  while (pIterator_in_List_for_UserRecord->current)
  {
    if (matches(&(pIterator_in_List_for_UserRecord->current->value)))
    {
      return &(pIterator_in_List_for_UserRecord->current->value);
    }

    pIterator_in_List_for_UserRecord->current = (Node_for_UserRecord*)pIterator_in_List_for_UserRecord->current->next;
  }

  return NULL;
}
