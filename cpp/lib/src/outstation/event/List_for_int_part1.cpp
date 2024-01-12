#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "List_for_int.h"
#include <string.h>

void List_for_int_in_List_for_intOver1(List_for_int *pList_for_int)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"List_for_int_in_List_for_intOver1_1"<<'\n';
  decrement_stack_info();
#endif
  Array__for__Node_for_int_in_Array__for__Node_for_intOver1(&(pList_for_int->underlying));
  (pList_for_int->iIterator_in_List_for_int).current = NULL;

  pList_for_int->head = NULL;
  pList_for_int->tail = NULL;
  pList_for_int->free = NULL;
}

void List_for_int_in_List_for_intOver2(List_for_int *pList_for_int, uint32_t maxSize)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"List_for_int_in_List_for_intOver2_1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*uint32_t maxSize= "<<maxSize<<'\n';
  decrement_stack_info();
#endif
  List_for_int_in_List_for_intOver1(pList_for_int);
// ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_for_int->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_for_int_in_Array__for__Node_for_intOver2(Array__for__Node_for_int *pArray__for__Node_for_int, uint32_t size);
  Array__for__Node_for_int_in_Array__for__Node_for_intOver2(&(pList_for_int->underlying), maxSize);
  Initialize_in_List_for_int(pList_for_int);
}

Iterator_in_List_for_int From__in__Iterator_in_List_for_int_static(Node_for_int* start)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"From__in__Iterator_in_List_for_int_static1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_int* start= "<<(uint32_t)start<<'\n';
  decrement_stack_info();
#endif
////            return Iterator(start);
  Iterator_in_List_for_int iIterator_in_List_for_int;
  Iterator_in_List_for_int__in__Iterator_in_List_for_int(&iIterator_in_List_for_int, start);
  return iIterator_in_List_for_int;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int)
{
  if(pIterator_in_List_for_int->current) return true;
  return false;
}

Node_for_int* Next__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int)
{
  if (!pIterator_in_List_for_int->current) return NULL;
  Node_for_int* ret = pIterator_in_List_for_int->current;
  pIterator_in_List_for_int->current = (Node_for_int*)pIterator_in_List_for_int->current->next;
  return ret;
}

Node_for_int* Current__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int)
{
  return pIterator_in_List_for_int->current;
}

int* CurrentValue__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int)
{
  return (pIterator_in_List_for_int->current) ? &(pIterator_in_List_for_int->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void Iterator_in_List_for_int__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int,
    Node_for_int* start)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Iterator_in_List_for_int__in__Iterator_in_List_for_int1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Node_for_int* start= "<<(uint32_t)start<<'\n';
  decrement_stack_info();
#endif
  pIterator_in_List_for_int->current = start;
}

Iterator_in_List_for_int Iterate_in_List_for_int(List_for_int *pList_for_int)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Iterate_in_List_for_int1"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pList_for_int->head= "<<(uint32_t)pList_for_int->head<<'\n';
#endif
//        return Iterator::From(pList_for_int->head);
  Iterator_in_List_for_int tmp = From__in__Iterator_in_List_for_int_static(pList_for_int->head);
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return tmp;
}

void Remove_in_List_for_int(List_for_int *pList_for_int, Node_for_int* node)
{
////    if (node == this->head) // change of head
  if (node == pList_for_int->head) // change of head
  {
////        this->head = node->next;
    pList_for_int->head = (Node_for_int*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_for_int->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_for_int->tail = (Node_for_int *)pList_for_int->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
// прикрепляем соседние узлы друг к другу, если они существуют
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_int_static(Node_for_int* first, Node_for_int* second)
  Link_in_List_for_int_static((Node_for_int*)node->prev, (Node_for_int*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_for_int_static(node, pList_for_int->free);
////    this->free = node;
  pList_for_int->free = node;

////    --(this->m_length);
  --((pList_for_int->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_for_int_static(Node_for_int* first, Node_for_int* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void Initialize_in_List_for_int(List_for_int *pList_for_int)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Initialize_in_List_for_int1"<<'\n';
#endif
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_for_int -> underlying).hHasLength_for_Uint32_t)) return;

  pList_for_int->free = &((pList_for_int->underlying).buffer[0]);////&underlying[0];
#ifdef  LOG_INFO
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*Initialize_in_List_for_int2"<<'\n';
  std::cout<<"*"<<getString_stack_info();
  std::cout<<"*pList_for_int->free= "<<(uint32_t)pList_for_int->free<<'\n';
#endif

////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_for_int -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_for_int_static(&((pList_for_int->underlying).buffer[i - 1]),
                                &((pList_for_int->underlying).buffer[i]));
  }
#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Initialize_in_List_for_int_"<<'\n';
  decrement_stack_info();
#endif
}

uint32_t Capacity_in_List_for_int(List_for_int *pList_for_int)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_for_int->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_for_int(List_for_int *pList_for_int)
{
  return !(pList_for_int->free) && Capacity_in_List_for_int(pList_for_int) > 0;
}

Node_for_int* Head_in_List_for_int(List_for_int *pList_for_int)
{
  return pList_for_int->head;
}

Node_for_int* Add_in_List_for_int(List_for_int *pList_for_int, int* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return  Insert_in_List_for_int(pList_for_int, value, pList_for_int->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_for_int*  Insert_in_List_for_int(List_for_int* pList_for_int,
                                      int* value, Node_for_int* left,
                                      Node_for_int* right)
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"{Insert_in_List_for_int1"<<'\n';
#endif

  if (!pList_for_int->free)
  {
#ifdef  LOG_INFO
    std::cout<<getString_stack_info();
    std::cout<<"}Insert_in_List_for_int1_"<<'\n';
    decrement_stack_info();
#endif
    return NULL;
  }

  // initialize the new node, and increment the size
  Node_for_int* new_node = pList_for_int->free;

  pList_for_int->free = (Node_for_int*)pList_for_int->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_for_int->hHasLength_for_Uint32_t).m_length);

//   void Link_in_List_for_int_static(Node_for_int* first, Node_for_int* second);
////    this->Link(left, new_node);
  Link_in_List_for_int_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_for_int_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_for_int->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_for_int->tail = new_node;
  }

#ifdef  LOG_INFO
  std::cout<<getString_stack_info();
  std::cout<<"}Insert_in_List_for_int2_"<<'\n';
  decrement_stack_info();
#endif
  return new_node;
}

int *Find__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int,
                                        boolean (*matches)(int* pint))
{
////    while (this->current)
  while (pIterator_in_List_for_int->current)
  {
    if (matches(&(pIterator_in_List_for_int->current->value)))
    {
      return &(pIterator_in_List_for_int->current->value);
    }

    pIterator_in_List_for_int->current = (Node_for_int*)pIterator_in_List_for_int->current->next;
  }

  return NULL;
}

////template<class T> template<class U> list_size_type_t List<T>::RemoveAll(const U& match)
uint16_t RemoveAll_in_List_for_int(List_for_int *pList_for_int, boolean (*match)(int))
{
  int16_t count = 0;

//Iterator_in_List_for_int Iterate_in_List_for_int(List_for_int *pList_for_int);
////    auto iter = this->Iterate();
  Iterator_in_List_for_int iter = Iterate_in_List_for_int(pList_for_int);

//Node_for_int* Next__in__Iterator_in_List_for_int(Iterator_in_List_for_int *pIterator_in_List_for_int);
////    auto current = iter.Next();
  Node_for_int* current = Next__in__Iterator_in_List_for_int(&iter);

  while (current)
  {
    if (match(current->value))
    {
////            auto removed = current;
      Node_for_int* removed = current;

////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_int(&iter);

//void Remove_in_List_for_int(List_for_int *pList_for_int, Node_for_int* node);
////            this->Remove(removed);
      Remove_in_List_for_int(pList_for_int, removed);

      ++count;
    }
    else
    {
////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_int(&iter);
    }
  }

  return count;
}

