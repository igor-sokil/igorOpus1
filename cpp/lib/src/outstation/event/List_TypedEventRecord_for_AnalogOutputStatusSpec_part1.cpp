
#include "header.h"
#include "List_TypedEventRecord_for_AnalogOutputStatusSpec.h"
#include <string.h>

void List_TypedEventRecord_for_AnalogOutputStatusSpec_in_List_TypedEventRecord_for_AnalogOutputStatusSpecOver1(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  (pList_TypedEventRecord_for_AnalogOutputStatusSpec->iIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec).current = NULL;

  pList_TypedEventRecord_for_AnalogOutputStatusSpec->head = NULL;
  pList_TypedEventRecord_for_AnalogOutputStatusSpec->tail = NULL;
  pList_TypedEventRecord_for_AnalogOutputStatusSpec->free = NULL;
  for(int i=0; i<SIZE_TypedEventRecord_for_AnalogOutputStatusSpec; i++)
  {
//void Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Node_TypedEventRecord_for_AnalogOutputStatusSpec(Node_TypedEventRecord_for_AnalogOutputStatusSpec *pNode_TypedEventRecord_for_AnalogOutputStatusSpec)
    Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Node_TypedEventRecord_for_AnalogOutputStatusSpec(&((pList_TypedEventRecord_for_AnalogOutputStatusSpec->underlying).buffer[i]));
  }
}

Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec From__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(Node_TypedEventRecord_for_AnalogOutputStatusSpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec iIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec;
  Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(&iIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec, start);
  return iIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_AnalogOutputStatusSpec* Next__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current) return NULL;
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* ret = pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current;
  pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current = (Node_TypedEventRecord_for_AnalogOutputStatusSpec*)pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_AnalogOutputStatusSpec* Current__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  return pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current;
}

TypedEventRecord_for_AnalogOutputStatusSpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec,
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* start)
{
  pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec Iterate_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(pList_TypedEventRecord_for_AnalogOutputStatusSpec->head);
}

void Remove_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec, Node_TypedEventRecord_for_AnalogOutputStatusSpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_AnalogOutputStatusSpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_AnalogOutputStatusSpec->head = (Node_TypedEventRecord_for_AnalogOutputStatusSpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_AnalogOutputStatusSpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_AnalogOutputStatusSpec->tail = (Node_TypedEventRecord_for_AnalogOutputStatusSpec *)pList_TypedEventRecord_for_AnalogOutputStatusSpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_AnalogOutputStatusSpec* first, Node_TypedEventRecord_for_AnalogOutputStatusSpec* second)
  Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static((Node_TypedEventRecord_for_AnalogOutputStatusSpec*)node->prev, (Node_TypedEventRecord_for_AnalogOutputStatusSpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(node, pList_TypedEventRecord_for_AnalogOutputStatusSpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_AnalogOutputStatusSpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(Node_TypedEventRecord_for_AnalogOutputStatusSpec* first, Node_TypedEventRecord_for_AnalogOutputStatusSpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_AnalogOutputStatusSpec_in_List_TypedEventRecord_for_AnalogOutputStatusSpecOver2(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec, uint32_t maxSize)
{
  List_TypedEventRecord_for_AnalogOutputStatusSpec_in_List_TypedEventRecord_for_AnalogOutputStatusSpecOver1(pList_TypedEventRecord_for_AnalogOutputStatusSpec);
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpecOver2(Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec *pArray__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpec_in_Array__for__Node_TypedEventRecord_for_AnalogOutputStatusSpecOver2(&(pList_TypedEventRecord_for_AnalogOutputStatusSpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(pList_TypedEventRecord_for_AnalogOutputStatusSpec);
}

void Initialize_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_AnalogOutputStatusSpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_AnalogOutputStatusSpec->free = &((pList_TypedEventRecord_for_AnalogOutputStatusSpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_AnalogOutputStatusSpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(&((pList_TypedEventRecord_for_AnalogOutputStatusSpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_AnalogOutputStatusSpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_AnalogOutputStatusSpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  return !(pList_TypedEventRecord_for_AnalogOutputStatusSpec->free) && Capacity_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(pList_TypedEventRecord_for_AnalogOutputStatusSpec) > 0;
}

Node_TypedEventRecord_for_AnalogOutputStatusSpec* Head_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  return pList_TypedEventRecord_for_AnalogOutputStatusSpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_AnalogOutputStatusSpec* Add_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
    TypedEventRecord_for_AnalogOutputStatusSpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(pList_TypedEventRecord_for_AnalogOutputStatusSpec,
         value, pList_TypedEventRecord_for_AnalogOutputStatusSpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_AnalogOutputStatusSpec* Insert_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec,
    TypedEventRecord_for_AnalogOutputStatusSpec* value,
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* left,
    Node_TypedEventRecord_for_AnalogOutputStatusSpec* right
                                                                                                            )
{
  if (!pList_TypedEventRecord_for_AnalogOutputStatusSpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_AnalogOutputStatusSpec* new_node = pList_TypedEventRecord_for_AnalogOutputStatusSpec->free;
  pList_TypedEventRecord_for_AnalogOutputStatusSpec->free = (Node_TypedEventRecord_for_AnalogOutputStatusSpec*) pList_TypedEventRecord_for_AnalogOutputStatusSpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_AnalogOutputStatusSpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(Node_TypedEventRecord_for_AnalogOutputStatusSpec* first, Node_TypedEventRecord_for_AnalogOutputStatusSpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_AnalogOutputStatusSpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_AnalogOutputStatusSpec->tail = new_node;
  }

  return new_node;
}
