
#include "header.h"
#include "List_TypedEventRecord_for_DoubleBitBinarySpec.h"
#include <string.h>

void List_TypedEventRecord_for_DoubleBitBinarySpec_in_List_TypedEventRecord_for_DoubleBitBinarySpecOver1(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
{
  (pList_TypedEventRecord_for_DoubleBitBinarySpec->iIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec).current = NULL;

  pList_TypedEventRecord_for_DoubleBitBinarySpec->head = NULL;
  pList_TypedEventRecord_for_DoubleBitBinarySpec->tail = NULL;
  pList_TypedEventRecord_for_DoubleBitBinarySpec->free = NULL;
  for(int i=0; i<SIZE_TypedEventRecord_for_DoubleBitBinarySpec; i++)
  {
   Node_TypedEventRecord_for_DoubleBitBinarySpec_in_Node_TypedEventRecord_for_DoubleBitBinarySpec(&((pList_TypedEventRecord_for_DoubleBitBinarySpec->underlying).buffer[i]));
  }
}

Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec From__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(Node_TypedEventRecord_for_DoubleBitBinarySpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec iIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec;
  Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(&iIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec, start);
  return iIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec)
{
  if(pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_DoubleBitBinarySpec* Next__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current) return NULL;
  Node_TypedEventRecord_for_DoubleBitBinarySpec* ret = pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current;
  pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current = (Node_TypedEventRecord_for_DoubleBitBinarySpec*)pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_DoubleBitBinarySpec* Current__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec)
{
  return pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current;
}

TypedEventRecord_for_DoubleBitBinarySpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec)
{
  return (pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current) ? &(pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec,
    Node_TypedEventRecord_for_DoubleBitBinarySpec* start)
{
  pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec Iterate_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(pList_TypedEventRecord_for_DoubleBitBinarySpec->head);
}

void Remove_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec, Node_TypedEventRecord_for_DoubleBitBinarySpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_DoubleBitBinarySpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_DoubleBitBinarySpec->head = (Node_TypedEventRecord_for_DoubleBitBinarySpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_DoubleBitBinarySpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_DoubleBitBinarySpec->tail = (Node_TypedEventRecord_for_DoubleBitBinarySpec *)pList_TypedEventRecord_for_DoubleBitBinarySpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_DoubleBitBinarySpec* first, Node_TypedEventRecord_for_DoubleBitBinarySpec* second)
  Link_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static((Node_TypedEventRecord_for_DoubleBitBinarySpec*)node->prev, (Node_TypedEventRecord_for_DoubleBitBinarySpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(node, pList_TypedEventRecord_for_DoubleBitBinarySpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_DoubleBitBinarySpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_DoubleBitBinarySpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(Node_TypedEventRecord_for_DoubleBitBinarySpec* first, Node_TypedEventRecord_for_DoubleBitBinarySpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_DoubleBitBinarySpec_in_List_TypedEventRecord_for_DoubleBitBinarySpecOver2(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec, uint32_t maxSize)
{
  List_TypedEventRecord_for_DoubleBitBinarySpec_in_List_TypedEventRecord_for_DoubleBitBinarySpecOver1(pList_TypedEventRecord_for_DoubleBitBinarySpec);
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_DoubleBitBinarySpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec_in_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpecOver2(Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec *pArray__for__Node_TypedEventRecord_for_DoubleBitBinarySpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpec_in_Array__for__Node_TypedEventRecord_for_DoubleBitBinarySpecOver2(&(pList_TypedEventRecord_for_DoubleBitBinarySpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_DoubleBitBinarySpec(pList_TypedEventRecord_for_DoubleBitBinarySpec);
}

void Initialize_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_DoubleBitBinarySpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_DoubleBitBinarySpec->free = &((pList_TypedEventRecord_for_DoubleBitBinarySpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_DoubleBitBinarySpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(&((pList_TypedEventRecord_for_DoubleBitBinarySpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_DoubleBitBinarySpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_DoubleBitBinarySpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
{
  return !(pList_TypedEventRecord_for_DoubleBitBinarySpec->free) && Capacity_in_List_TypedEventRecord_for_DoubleBitBinarySpec(pList_TypedEventRecord_for_DoubleBitBinarySpec) > 0;
}

Node_TypedEventRecord_for_DoubleBitBinarySpec* Head_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
{
  return pList_TypedEventRecord_for_DoubleBitBinarySpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_DoubleBitBinarySpec* Add_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec,
    TypedEventRecord_for_DoubleBitBinarySpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_DoubleBitBinarySpec(pList_TypedEventRecord_for_DoubleBitBinarySpec,
         value, pList_TypedEventRecord_for_DoubleBitBinarySpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_DoubleBitBinarySpec* Insert_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec,
    TypedEventRecord_for_DoubleBitBinarySpec* value,
    Node_TypedEventRecord_for_DoubleBitBinarySpec* left,
    Node_TypedEventRecord_for_DoubleBitBinarySpec* right
                                                                                                      )
{
  if (!pList_TypedEventRecord_for_DoubleBitBinarySpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_DoubleBitBinarySpec* new_node = pList_TypedEventRecord_for_DoubleBitBinarySpec->free;
  pList_TypedEventRecord_for_DoubleBitBinarySpec->free = (Node_TypedEventRecord_for_DoubleBitBinarySpec*) pList_TypedEventRecord_for_DoubleBitBinarySpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_DoubleBitBinarySpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(Node_TypedEventRecord_for_DoubleBitBinarySpec* first, Node_TypedEventRecord_for_DoubleBitBinarySpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_DoubleBitBinarySpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_DoubleBitBinarySpec->tail = new_node;
  }

  return new_node;
}
