
#include "header.h"
#include "List_TypedEventRecord_for_CounterSpec.h"
#include <string.h>

void List_TypedEventRecord_for_CounterSpec_in_List_TypedEventRecord_for_CounterSpecOver1(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
{
  (pList_TypedEventRecord_for_CounterSpec->iIterator_in_List_TypedEventRecord_for_CounterSpec).current = NULL;

  pList_TypedEventRecord_for_CounterSpec->head = NULL;
  pList_TypedEventRecord_for_CounterSpec->tail = NULL;
  pList_TypedEventRecord_for_CounterSpec->free = NULL;
  for(int i=0; i<SIZE_TypedEventRecord_for_CounterSpec; i++)
  {
    Node_TypedEventRecord_for_CounterSpec_in_Node_TypedEventRecord_for_CounterSpec(&((pList_TypedEventRecord_for_CounterSpec->underlying).buffer[i]));
  }
}

Iterator_in_List_TypedEventRecord_for_CounterSpec From__in__Iterator_in_List_TypedEventRecord_for_CounterSpec_static(Node_TypedEventRecord_for_CounterSpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_CounterSpec iIterator_in_List_TypedEventRecord_for_CounterSpec;
  Iterator_in_List_TypedEventRecord_for_CounterSpec__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(&iIterator_in_List_TypedEventRecord_for_CounterSpec, start);
  return iIterator_in_List_TypedEventRecord_for_CounterSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_CounterSpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_CounterSpec* Next__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_CounterSpec->current) return NULL;
  Node_TypedEventRecord_for_CounterSpec* ret = pIterator_in_List_TypedEventRecord_for_CounterSpec->current;
  pIterator_in_List_TypedEventRecord_for_CounterSpec->current = (Node_TypedEventRecord_for_CounterSpec*)pIterator_in_List_TypedEventRecord_for_CounterSpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_CounterSpec* Current__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec)
{
  return pIterator_in_List_TypedEventRecord_for_CounterSpec->current;
}

TypedEventRecord_for_CounterSpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_CounterSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_CounterSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_CounterSpec__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec,
    Node_TypedEventRecord_for_CounterSpec* start)
{
  pIterator_in_List_TypedEventRecord_for_CounterSpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_CounterSpec Iterate_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_CounterSpec_static(pList_TypedEventRecord_for_CounterSpec->head);
}

void Remove_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec, Node_TypedEventRecord_for_CounterSpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_CounterSpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_CounterSpec->head = (Node_TypedEventRecord_for_CounterSpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_CounterSpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_CounterSpec->tail = (Node_TypedEventRecord_for_CounterSpec *)pList_TypedEventRecord_for_CounterSpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_CounterSpec* first, Node_TypedEventRecord_for_CounterSpec* second)
  Link_in_List_TypedEventRecord_for_CounterSpec_static((Node_TypedEventRecord_for_CounterSpec*)node->prev, (Node_TypedEventRecord_for_CounterSpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_CounterSpec_static(node, pList_TypedEventRecord_for_CounterSpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_CounterSpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_CounterSpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_CounterSpec_static(Node_TypedEventRecord_for_CounterSpec* first, Node_TypedEventRecord_for_CounterSpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_CounterSpec_in_List_TypedEventRecord_for_CounterSpecOver2(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec, uint32_t maxSize)
{
  List_TypedEventRecord_for_CounterSpec_in_List_TypedEventRecord_for_CounterSpecOver1(pList_TypedEventRecord_for_CounterSpec);
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_CounterSpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_CounterSpec_in_Array__for__Node_TypedEventRecord_for_CounterSpecOver2(Array__for__Node_TypedEventRecord_for_CounterSpec *pArray__for__Node_TypedEventRecord_for_CounterSpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_CounterSpec_in_Array__for__Node_TypedEventRecord_for_CounterSpecOver2(&(pList_TypedEventRecord_for_CounterSpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_CounterSpec(pList_TypedEventRecord_for_CounterSpec);
}

void Initialize_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_CounterSpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_CounterSpec->free = &((pList_TypedEventRecord_for_CounterSpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_CounterSpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_CounterSpec_static(&((pList_TypedEventRecord_for_CounterSpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_CounterSpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_CounterSpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
{
  return !(pList_TypedEventRecord_for_CounterSpec->free) && Capacity_in_List_TypedEventRecord_for_CounterSpec(pList_TypedEventRecord_for_CounterSpec) > 0;
}

Node_TypedEventRecord_for_CounterSpec* Head_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
{
  return pList_TypedEventRecord_for_CounterSpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_CounterSpec* Add_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec,
    TypedEventRecord_for_CounterSpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_CounterSpec(pList_TypedEventRecord_for_CounterSpec,
         value, pList_TypedEventRecord_for_CounterSpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_CounterSpec* Insert_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec,
    TypedEventRecord_for_CounterSpec* value,
    Node_TypedEventRecord_for_CounterSpec* left,
    Node_TypedEventRecord_for_CounterSpec* right
                                                                                      )
{
  if (!pList_TypedEventRecord_for_CounterSpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_CounterSpec* new_node = pList_TypedEventRecord_for_CounterSpec->free;
  pList_TypedEventRecord_for_CounterSpec->free = (Node_TypedEventRecord_for_CounterSpec*) pList_TypedEventRecord_for_CounterSpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_CounterSpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_CounterSpec_static(Node_TypedEventRecord_for_CounterSpec* first, Node_TypedEventRecord_for_CounterSpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_CounterSpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_CounterSpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_CounterSpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_CounterSpec->tail = new_node;
  }

  return new_node;
}
