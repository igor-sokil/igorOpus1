
#include "header.h"
#include "List_TypedEventRecord_for_OctetStringSpec.h"
#include <string.h>

void List_TypedEventRecord_for_OctetStringSpec_in_List_TypedEventRecord_for_OctetStringSpecOver1(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
{
  (pList_TypedEventRecord_for_OctetStringSpec->iIterator_in_List_TypedEventRecord_for_OctetStringSpec).current = NULL;

  pList_TypedEventRecord_for_OctetStringSpec->head = NULL;
  pList_TypedEventRecord_for_OctetStringSpec->tail = NULL;
  pList_TypedEventRecord_for_OctetStringSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_OctetStringSpec From__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec_static(Node_TypedEventRecord_for_OctetStringSpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_OctetStringSpec iIterator_in_List_TypedEventRecord_for_OctetStringSpec;
  Iterator_in_List_TypedEventRecord_for_OctetStringSpec__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(&iIterator_in_List_TypedEventRecord_for_OctetStringSpec, start);
  return iIterator_in_List_TypedEventRecord_for_OctetStringSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_OctetStringSpec* Next__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current) return NULL;
  Node_TypedEventRecord_for_OctetStringSpec* ret = pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current;
  pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current = (Node_TypedEventRecord_for_OctetStringSpec*)pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_OctetStringSpec* Current__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  return pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current;
}

TypedEventRecord_for_OctetStringSpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_OctetStringSpec__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec,
    Node_TypedEventRecord_for_OctetStringSpec* start)
{
  pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_OctetStringSpec Iterate_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec_static(pList_TypedEventRecord_for_OctetStringSpec->head);
}

void Remove_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec, Node_TypedEventRecord_for_OctetStringSpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_OctetStringSpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_OctetStringSpec->head = (Node_TypedEventRecord_for_OctetStringSpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_OctetStringSpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_OctetStringSpec->tail = (Node_TypedEventRecord_for_OctetStringSpec *)pList_TypedEventRecord_for_OctetStringSpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_OctetStringSpec* first, Node_TypedEventRecord_for_OctetStringSpec* second)
  Link_in_List_TypedEventRecord_for_OctetStringSpec_static((Node_TypedEventRecord_for_OctetStringSpec*)node->prev, (Node_TypedEventRecord_for_OctetStringSpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_OctetStringSpec_static(node, pList_TypedEventRecord_for_OctetStringSpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_OctetStringSpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_OctetStringSpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_OctetStringSpec_static(Node_TypedEventRecord_for_OctetStringSpec* first, Node_TypedEventRecord_for_OctetStringSpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_OctetStringSpec_in_List_TypedEventRecord_for_OctetStringSpecOver2(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec, uint32_t maxSize)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_OctetStringSpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_OctetStringSpec_in_Array__for__Node_TypedEventRecord_for_OctetStringSpecOver2(Array__for__Node_TypedEventRecord_for_OctetStringSpec *pArray__for__Node_TypedEventRecord_for_OctetStringSpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_OctetStringSpec_in_Array__for__Node_TypedEventRecord_for_OctetStringSpecOver2(&(pList_TypedEventRecord_for_OctetStringSpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_OctetStringSpec(pList_TypedEventRecord_for_OctetStringSpec);
}

void Initialize_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_OctetStringSpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_OctetStringSpec->free = &((pList_TypedEventRecord_for_OctetStringSpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_OctetStringSpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_OctetStringSpec_static(&((pList_TypedEventRecord_for_OctetStringSpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_OctetStringSpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_OctetStringSpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
{
  return !(pList_TypedEventRecord_for_OctetStringSpec->free) && Capacity_in_List_TypedEventRecord_for_OctetStringSpec(pList_TypedEventRecord_for_OctetStringSpec) > 0;
}

Node_TypedEventRecord_for_OctetStringSpec* Head_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
{
  return pList_TypedEventRecord_for_OctetStringSpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_OctetStringSpec* Add_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec,
    TypedEventRecord_for_OctetStringSpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_OctetStringSpec(pList_TypedEventRecord_for_OctetStringSpec,
         value, pList_TypedEventRecord_for_OctetStringSpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_OctetStringSpec* Insert_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec,
    TypedEventRecord_for_OctetStringSpec* value,
    Node_TypedEventRecord_for_OctetStringSpec* left,
    Node_TypedEventRecord_for_OctetStringSpec* right
                                                                                              )
{
  if (!pList_TypedEventRecord_for_OctetStringSpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_OctetStringSpec* new_node = pList_TypedEventRecord_for_OctetStringSpec->free;
  pList_TypedEventRecord_for_OctetStringSpec->free = (Node_TypedEventRecord_for_OctetStringSpec*) pList_TypedEventRecord_for_OctetStringSpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_OctetStringSpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_OctetStringSpec_static(Node_TypedEventRecord_for_OctetStringSpec* first, Node_TypedEventRecord_for_OctetStringSpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_OctetStringSpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_OctetStringSpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_OctetStringSpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_OctetStringSpec->tail = new_node;
  }

  return new_node;
}
