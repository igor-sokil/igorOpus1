
#include "header.h"
#include "List_TypedEventRecord_for_AnalogSpec.h"
#include <string.h>

void List_TypedEventRecord_for_AnalogSpec_in_List_TypedEventRecord_for_AnalogSpecOver1(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
  (pList_TypedEventRecord_for_AnalogSpec->iIterator_in_List_TypedEventRecord_for_AnalogSpec).current = NULL;

  pList_TypedEventRecord_for_AnalogSpec->head = NULL;
  pList_TypedEventRecord_for_AnalogSpec->tail = NULL;
  pList_TypedEventRecord_for_AnalogSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_AnalogSpec From__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec_static(Node_TypedEventRecord_for_AnalogSpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_AnalogSpec iIterator_in_List_TypedEventRecord_for_AnalogSpec;
  Iterator_in_List_TypedEventRecord_for_AnalogSpec__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(&iIterator_in_List_TypedEventRecord_for_AnalogSpec, start);
  return iIterator_in_List_TypedEventRecord_for_AnalogSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_AnalogSpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_AnalogSpec* Next__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_AnalogSpec->current) return NULL;
  Node_TypedEventRecord_for_AnalogSpec* ret = pIterator_in_List_TypedEventRecord_for_AnalogSpec->current;
  pIterator_in_List_TypedEventRecord_for_AnalogSpec->current = (Node_TypedEventRecord_for_AnalogSpec*)pIterator_in_List_TypedEventRecord_for_AnalogSpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_AnalogSpec* Current__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec)
{
  return pIterator_in_List_TypedEventRecord_for_AnalogSpec->current;
}

TypedEventRecord_for_AnalogSpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_AnalogSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_AnalogSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_AnalogSpec__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec,
    Node_TypedEventRecord_for_AnalogSpec* start)
{
  pIterator_in_List_TypedEventRecord_for_AnalogSpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_AnalogSpec Iterate_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec_static(pList_TypedEventRecord_for_AnalogSpec->head);
}

void Remove_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec, Node_TypedEventRecord_for_AnalogSpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_AnalogSpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_AnalogSpec->head = (Node_TypedEventRecord_for_AnalogSpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_AnalogSpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_AnalogSpec->tail = (Node_TypedEventRecord_for_AnalogSpec *)pList_TypedEventRecord_for_AnalogSpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_AnalogSpec* first, Node_TypedEventRecord_for_AnalogSpec* second)
  Link_in_List_TypedEventRecord_for_AnalogSpec_static((Node_TypedEventRecord_for_AnalogSpec*)node->prev, (Node_TypedEventRecord_for_AnalogSpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_AnalogSpec_static(node, pList_TypedEventRecord_for_AnalogSpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_AnalogSpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_AnalogSpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_AnalogSpec_static(Node_TypedEventRecord_for_AnalogSpec* first, Node_TypedEventRecord_for_AnalogSpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_AnalogSpec_in_List_TypedEventRecord_for_AnalogSpecOver2(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec, uint32_t maxSize)
{
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_AnalogSpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_AnalogSpec_in_Array__for__Node_TypedEventRecord_for_AnalogSpecOver2(Array__for__Node_TypedEventRecord_for_AnalogSpec *pArray__for__Node_TypedEventRecord_for_AnalogSpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_AnalogSpec_in_Array__for__Node_TypedEventRecord_for_AnalogSpecOver2(&(pList_TypedEventRecord_for_AnalogSpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_AnalogSpec(pList_TypedEventRecord_for_AnalogSpec);
}

void Initialize_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_AnalogSpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_AnalogSpec->free = &((pList_TypedEventRecord_for_AnalogSpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_AnalogSpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_AnalogSpec_static(&((pList_TypedEventRecord_for_AnalogSpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_AnalogSpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_AnalogSpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
  return !(pList_TypedEventRecord_for_AnalogSpec->free) && Capacity_in_List_TypedEventRecord_for_AnalogSpec(pList_TypedEventRecord_for_AnalogSpec) > 0;
}

Node_TypedEventRecord_for_AnalogSpec* Head_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
  return pList_TypedEventRecord_for_AnalogSpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_AnalogSpec* Add_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    TypedEventRecord_for_AnalogSpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_AnalogSpec(pList_TypedEventRecord_for_AnalogSpec,
         value, pList_TypedEventRecord_for_AnalogSpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_AnalogSpec* Insert_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    TypedEventRecord_for_AnalogSpec* value,
    Node_TypedEventRecord_for_AnalogSpec* left,
    Node_TypedEventRecord_for_AnalogSpec* right
                                                                                    )
{
  if (!pList_TypedEventRecord_for_AnalogSpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_AnalogSpec* new_node = pList_TypedEventRecord_for_AnalogSpec->free;
  pList_TypedEventRecord_for_AnalogSpec->free = (Node_TypedEventRecord_for_AnalogSpec*) pList_TypedEventRecord_for_AnalogSpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_AnalogSpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_AnalogSpec_static(Node_TypedEventRecord_for_AnalogSpec* first, Node_TypedEventRecord_for_AnalogSpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_AnalogSpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_AnalogSpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_AnalogSpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_AnalogSpec->tail = new_node;
  }

  return new_node;
}
