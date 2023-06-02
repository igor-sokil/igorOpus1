
#include "header.h"
#include "List_TypedEventRecord_for_BinaryOutputStatusSpec.h"
#include <string.h>

void List_TypedEventRecord_for_BinaryOutputStatusSpec_in_List_TypedEventRecord_for_BinaryOutputStatusSpecOver1(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  (pList_TypedEventRecord_for_BinaryOutputStatusSpec->iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec).current = NULL;

  pList_TypedEventRecord_for_BinaryOutputStatusSpec->head = NULL;
  pList_TypedEventRecord_for_BinaryOutputStatusSpec->tail = NULL;
  pList_TypedEventRecord_for_BinaryOutputStatusSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec From__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(Node_TypedEventRecord_for_BinaryOutputStatusSpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec;
  Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(&iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec, start);
  return iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_BinaryOutputStatusSpec* Next__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current) return NULL;
  Node_TypedEventRecord_for_BinaryOutputStatusSpec* ret = pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current;
  pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current = (Node_TypedEventRecord_for_BinaryOutputStatusSpec*)pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_BinaryOutputStatusSpec* Current__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  return pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current;
}

TypedEventRecord_for_BinaryOutputStatusSpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec,
    Node_TypedEventRecord_for_BinaryOutputStatusSpec* start)
{
  pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec Iterate_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(pList_TypedEventRecord_for_BinaryOutputStatusSpec->head);
}

void Remove_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec, Node_TypedEventRecord_for_BinaryOutputStatusSpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_BinaryOutputStatusSpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_BinaryOutputStatusSpec->head = (Node_TypedEventRecord_for_BinaryOutputStatusSpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_BinaryOutputStatusSpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_BinaryOutputStatusSpec->tail = (Node_TypedEventRecord_for_BinaryOutputStatusSpec *)pList_TypedEventRecord_for_BinaryOutputStatusSpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_BinaryOutputStatusSpec* first, Node_TypedEventRecord_for_BinaryOutputStatusSpec* second)
  Link_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static((Node_TypedEventRecord_for_BinaryOutputStatusSpec*)node->prev, (Node_TypedEventRecord_for_BinaryOutputStatusSpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(node, pList_TypedEventRecord_for_BinaryOutputStatusSpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_BinaryOutputStatusSpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(Node_TypedEventRecord_for_BinaryOutputStatusSpec* first, Node_TypedEventRecord_for_BinaryOutputStatusSpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_BinaryOutputStatusSpec_in_List_TypedEventRecord_for_BinaryOutputStatusSpecOver2(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec, uint32_t maxSize)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpecOver2(Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_BinaryOutputStatusSpecOver2(&(pList_TypedEventRecord_for_BinaryOutputStatusSpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(pList_TypedEventRecord_for_BinaryOutputStatusSpec);
}

void Initialize_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_BinaryOutputStatusSpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_BinaryOutputStatusSpec->free = &((pList_TypedEventRecord_for_BinaryOutputStatusSpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_BinaryOutputStatusSpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(&((pList_TypedEventRecord_for_BinaryOutputStatusSpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_BinaryOutputStatusSpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_BinaryOutputStatusSpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  return !(pList_TypedEventRecord_for_BinaryOutputStatusSpec->free) && Capacity_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(pList_TypedEventRecord_for_BinaryOutputStatusSpec) > 0;
}

Node_TypedEventRecord_for_BinaryOutputStatusSpec* Head_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  return pList_TypedEventRecord_for_BinaryOutputStatusSpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_BinaryOutputStatusSpec* Add_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec,
    TypedEventRecord_for_BinaryOutputStatusSpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(pList_TypedEventRecord_for_BinaryOutputStatusSpec,
         value, pList_TypedEventRecord_for_BinaryOutputStatusSpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_BinaryOutputStatusSpec* Insert_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec,
    TypedEventRecord_for_BinaryOutputStatusSpec* value,
    Node_TypedEventRecord_for_BinaryOutputStatusSpec* left,
    Node_TypedEventRecord_for_BinaryOutputStatusSpec* right
                                                                                                            )
{
  if (!pList_TypedEventRecord_for_BinaryOutputStatusSpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_BinaryOutputStatusSpec* new_node = pList_TypedEventRecord_for_BinaryOutputStatusSpec->free;
  pList_TypedEventRecord_for_BinaryOutputStatusSpec->free = (Node_TypedEventRecord_for_BinaryOutputStatusSpec*) pList_TypedEventRecord_for_BinaryOutputStatusSpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_BinaryOutputStatusSpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(Node_TypedEventRecord_for_BinaryOutputStatusSpec* first, Node_TypedEventRecord_for_BinaryOutputStatusSpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_BinaryOutputStatusSpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_BinaryOutputStatusSpec->tail = new_node;
  }

  return new_node;
}
