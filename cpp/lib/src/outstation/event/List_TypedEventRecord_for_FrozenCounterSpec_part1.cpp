
#include "header.h"
#include "List_TypedEventRecord_for_FrozenCounterSpec.h"
#include <string.h>

void List_TypedEventRecord_for_FrozenCounterSpec_in_List_TypedEventRecord_for_FrozenCounterSpecOver1(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
{
  (pList_TypedEventRecord_for_FrozenCounterSpec->iIterator_in_List_TypedEventRecord_for_FrozenCounterSpec).current = NULL;

  pList_TypedEventRecord_for_FrozenCounterSpec->head = NULL;
  pList_TypedEventRecord_for_FrozenCounterSpec->tail = NULL;
  pList_TypedEventRecord_for_FrozenCounterSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec From__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec_static(Node_TypedEventRecord_for_FrozenCounterSpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec iIterator_in_List_TypedEventRecord_for_FrozenCounterSpec;
  Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(&iIterator_in_List_TypedEventRecord_for_FrozenCounterSpec, start);
  return iIterator_in_List_TypedEventRecord_for_FrozenCounterSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_FrozenCounterSpec* Next__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current) return NULL;
  Node_TypedEventRecord_for_FrozenCounterSpec* ret = pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current;
  pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current = (Node_TypedEventRecord_for_FrozenCounterSpec*)pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_FrozenCounterSpec* Current__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec)
{
  return pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current;
}

TypedEventRecord_for_FrozenCounterSpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec,
    Node_TypedEventRecord_for_FrozenCounterSpec* start)
{
  pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec Iterate_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec_static(pList_TypedEventRecord_for_FrozenCounterSpec->head);
}

void Remove_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec, Node_TypedEventRecord_for_FrozenCounterSpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_FrozenCounterSpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_FrozenCounterSpec->head = (Node_TypedEventRecord_for_FrozenCounterSpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_FrozenCounterSpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_FrozenCounterSpec->tail = (Node_TypedEventRecord_for_FrozenCounterSpec *)pList_TypedEventRecord_for_FrozenCounterSpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_FrozenCounterSpec* first, Node_TypedEventRecord_for_FrozenCounterSpec* second)
  Link_in_List_TypedEventRecord_for_FrozenCounterSpec_static((Node_TypedEventRecord_for_FrozenCounterSpec*)node->prev, (Node_TypedEventRecord_for_FrozenCounterSpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_FrozenCounterSpec_static(node, pList_TypedEventRecord_for_FrozenCounterSpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_FrozenCounterSpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_FrozenCounterSpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_FrozenCounterSpec_static(Node_TypedEventRecord_for_FrozenCounterSpec* first, Node_TypedEventRecord_for_FrozenCounterSpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_FrozenCounterSpec_in_List_TypedEventRecord_for_FrozenCounterSpecOver2(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec, uint32_t maxSize)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_FrozenCounterSpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_FrozenCounterSpec_in_Array__for__Node_TypedEventRecord_for_FrozenCounterSpecOver2(Array__for__Node_TypedEventRecord_for_FrozenCounterSpec *pArray__for__Node_TypedEventRecord_for_FrozenCounterSpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_FrozenCounterSpec_in_Array__for__Node_TypedEventRecord_for_FrozenCounterSpecOver2(&(pList_TypedEventRecord_for_FrozenCounterSpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_FrozenCounterSpec(pList_TypedEventRecord_for_FrozenCounterSpec);
}

void Initialize_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_FrozenCounterSpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_FrozenCounterSpec->free = &((pList_TypedEventRecord_for_FrozenCounterSpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_FrozenCounterSpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_FrozenCounterSpec_static(&((pList_TypedEventRecord_for_FrozenCounterSpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_FrozenCounterSpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_FrozenCounterSpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
{
  return !(pList_TypedEventRecord_for_FrozenCounterSpec->free) && Capacity_in_List_TypedEventRecord_for_FrozenCounterSpec(pList_TypedEventRecord_for_FrozenCounterSpec) > 0;
}

Node_TypedEventRecord_for_FrozenCounterSpec* Head_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
{
  return pList_TypedEventRecord_for_FrozenCounterSpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_FrozenCounterSpec* Add_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec,
    TypedEventRecord_for_FrozenCounterSpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_FrozenCounterSpec(pList_TypedEventRecord_for_FrozenCounterSpec,
         value, pList_TypedEventRecord_for_FrozenCounterSpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_FrozenCounterSpec* Insert_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec,
    TypedEventRecord_for_FrozenCounterSpec* value,
    Node_TypedEventRecord_for_FrozenCounterSpec* left,
    Node_TypedEventRecord_for_FrozenCounterSpec* right
                                                                                                  )
{
  if (!pList_TypedEventRecord_for_FrozenCounterSpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_FrozenCounterSpec* new_node = pList_TypedEventRecord_for_FrozenCounterSpec->free;
  pList_TypedEventRecord_for_FrozenCounterSpec->free = (Node_TypedEventRecord_for_FrozenCounterSpec*) pList_TypedEventRecord_for_FrozenCounterSpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_FrozenCounterSpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_FrozenCounterSpec_static(Node_TypedEventRecord_for_FrozenCounterSpec* first, Node_TypedEventRecord_for_FrozenCounterSpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_FrozenCounterSpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_FrozenCounterSpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_FrozenCounterSpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_FrozenCounterSpec->tail = new_node;
  }

  return new_node;
}
