#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "List_for_CellAnalogRecord.h"
#include <string.h>

void List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver1(List_for_CellAnalogRecord *pList_for_CellAnalogRecord)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver1_1"<<'\n';
  decrement_stack_info();
#endif
  Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver1(&(pList_for_CellAnalogRecord->underlying));
  (pList_for_CellAnalogRecord->iIterator_in_List_for_CellAnalogRecord).current = NULL;

  pList_for_CellAnalogRecord->head = NULL;
  pList_for_CellAnalogRecord->tail = NULL;
  pList_for_CellAnalogRecord->free = NULL;
}

void List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver2(List_for_CellAnalogRecord *pList_for_CellAnalogRecord, uint32_t maxSize)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maxSize= "<<maxSize<<'\n';
  decrement_stack_info();
#endif
  List_for_CellAnalogRecord_in_List_for_CellAnalogRecordOver1(pList_for_CellAnalogRecord);
// ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_for_CellAnalogRecord->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver2(Array__for__Node_for_CellAnalogRecord *pArray__for__Node_for_CellAnalogRecord, uint32_t size);
  Array__for__Node_for_CellAnalogRecord_in_Array__for__Node_for_CellAnalogRecordOver2(&(pList_for_CellAnalogRecord->underlying), maxSize);
  Initialize_in_List_for_CellAnalogRecord(pList_for_CellAnalogRecord);
}

Iterator_in_List_for_CellAnalogRecord From__in__Iterator_in_List_for_CellAnalogRecord_static(Node_for_CellAnalogRecord* start)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"From__in__Iterator_in_List_for_CellAnalogRecord_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_CellAnalogRecord* start= "<<(uint32_t)start<<'\n';
  decrement_stack_info();
#endif
////            return Iterator(start);
  Iterator_in_List_for_CellAnalogRecord iIterator_in_List_for_CellAnalogRecord;
  Iterator_in_List_for_CellAnalogRecord__in__Iterator_in_List_for_CellAnalogRecord(&iIterator_in_List_for_CellAnalogRecord, start);
  return iIterator_in_List_for_CellAnalogRecord;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_for_CellAnalogRecord(Iterator_in_List_for_CellAnalogRecord *pIterator_in_List_for_CellAnalogRecord)
{
  if(pIterator_in_List_for_CellAnalogRecord->current) return true;
  return false;
}

Node_for_CellAnalogRecord* Next__in__Iterator_in_List_for_CellAnalogRecord(Iterator_in_List_for_CellAnalogRecord *pIterator_in_List_for_CellAnalogRecord)
{
  if (!pIterator_in_List_for_CellAnalogRecord->current) return NULL;
  Node_for_CellAnalogRecord* ret = pIterator_in_List_for_CellAnalogRecord->current;
  pIterator_in_List_for_CellAnalogRecord->current = (Node_for_CellAnalogRecord*)pIterator_in_List_for_CellAnalogRecord->current->next;
  return ret;
}

Node_for_CellAnalogRecord* Current__in__Iterator_in_List_for_CellAnalogRecord(Iterator_in_List_for_CellAnalogRecord *pIterator_in_List_for_CellAnalogRecord)
{
  return pIterator_in_List_for_CellAnalogRecord->current;
}

CellAnalogRecord* CurrentValue__in__Iterator_in_List_for_CellAnalogRecord(Iterator_in_List_for_CellAnalogRecord *pIterator_in_List_for_CellAnalogRecord)
{
  return (pIterator_in_List_for_CellAnalogRecord->current) ? &(pIterator_in_List_for_CellAnalogRecord->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void Iterator_in_List_for_CellAnalogRecord__in__Iterator_in_List_for_CellAnalogRecord(Iterator_in_List_for_CellAnalogRecord *pIterator_in_List_for_CellAnalogRecord,
    Node_for_CellAnalogRecord* start)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Iterator_in_List_for_CellAnalogRecord__in__Iterator_in_List_for_CellAnalogRecord1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_CellAnalogRecord* start= "<<(uint32_t)start<<'\n';
  decrement_stack_info();
#endif
  pIterator_in_List_for_CellAnalogRecord->current = start;
}

Iterator_in_List_for_CellAnalogRecord Iterate_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Iterate_in_List_for_CellAnalogRecord1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pList_for_CellAnalogRecord->head= "<<(uint32_t)pList_for_CellAnalogRecord->head<<'\n';
#endif
//        return Iterator::From(pList_for_CellAnalogRecord->head);
  Iterator_in_List_for_CellAnalogRecord tmp = From__in__Iterator_in_List_for_CellAnalogRecord_static(pList_for_CellAnalogRecord->head);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}

void Remove_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord, Node_for_CellAnalogRecord* node)
{
////    if (node == this->head) // change of head
  if (node == pList_for_CellAnalogRecord->head) // change of head
  {
////        this->head = node->next;
    pList_for_CellAnalogRecord->head = (Node_for_CellAnalogRecord*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_for_CellAnalogRecord->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_for_CellAnalogRecord->tail = (Node_for_CellAnalogRecord *)pList_for_CellAnalogRecord->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_CellAnalogRecord_static(Node_for_CellAnalogRecord* first, Node_for_CellAnalogRecord* second)
  Link_in_List_for_CellAnalogRecord_static((Node_for_CellAnalogRecord*)node->prev, (Node_for_CellAnalogRecord*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_for_CellAnalogRecord_static(node, pList_for_CellAnalogRecord->free);
////    this->free = node;
  pList_for_CellAnalogRecord->free = node;

////    --(this->m_length);
  --((pList_for_CellAnalogRecord->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_for_CellAnalogRecord_static(Node_for_CellAnalogRecord* first, Node_for_CellAnalogRecord* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void Initialize_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_for_CellAnalogRecord -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_for_CellAnalogRecord->free = &((pList_for_CellAnalogRecord->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_for_CellAnalogRecord -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_for_CellAnalogRecord_static(&((pList_for_CellAnalogRecord->underlying).buffer[i - 1]),
                                        &((pList_for_CellAnalogRecord->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_for_CellAnalogRecord->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord)
{
  return !(pList_for_CellAnalogRecord->free) && Capacity_in_List_for_CellAnalogRecord(pList_for_CellAnalogRecord) > 0;
}

Node_for_CellAnalogRecord* Head_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord)
{
  return pList_for_CellAnalogRecord->head;
}

Node_for_CellAnalogRecord* Add_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord *pList_for_CellAnalogRecord, CellAnalogRecord* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return  Insert_in_List_for_CellAnalogRecord(pList_for_CellAnalogRecord, value, pList_for_CellAnalogRecord->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_for_CellAnalogRecord*  Insert_in_List_for_CellAnalogRecord(List_for_CellAnalogRecord* pList_for_CellAnalogRecord,
    CellAnalogRecord* value, Node_for_CellAnalogRecord* left,
    Node_for_CellAnalogRecord* right)
{
  if (!pList_for_CellAnalogRecord->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_for_CellAnalogRecord* new_node = pList_for_CellAnalogRecord->free;
  pList_for_CellAnalogRecord->free = (Node_for_CellAnalogRecord*)pList_for_CellAnalogRecord->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_for_CellAnalogRecord->hHasLength_for_Uint32_t).m_length);

//   void Link_in_List_for_CellAnalogRecord_static(Node_for_CellAnalogRecord* first, Node_for_CellAnalogRecord* second);
////    this->Link(left, new_node);
  Link_in_List_for_CellAnalogRecord_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_for_CellAnalogRecord_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_for_CellAnalogRecord->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_for_CellAnalogRecord->tail = new_node;
  }

  return new_node;
}

CellAnalogRecord *Find__in__Iterator_in_List_for_CellAnalogRecord(Iterator_in_List_for_CellAnalogRecord *pIterator_in_List_for_CellAnalogRecord,
    uint16_t index,
    boolean (*matches)(CellAnalogRecord* pCellAnalogRecord, uint16_t index))
{
////    while (this->current)
  while (pIterator_in_List_for_CellAnalogRecord->current)
  {
    if (matches(&(pIterator_in_List_for_CellAnalogRecord->current->value), index))
    {
      return &(pIterator_in_List_for_CellAnalogRecord->current->value);
    }

    pIterator_in_List_for_CellAnalogRecord->current = (Node_for_CellAnalogRecord*)pIterator_in_List_for_CellAnalogRecord->current->next;
  }

  return NULL;
}
