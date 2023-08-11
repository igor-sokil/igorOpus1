
#include "header.h"
#include "List_TypedEventRecord_for_BinarySpec.h"
#include <string.h>

void List_TypedEventRecord_for_BinarySpec_in_List_TypedEventRecord_for_BinarySpecOver1(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
{
  (pList_TypedEventRecord_for_BinarySpec->iIterator_in_List_TypedEventRecord_for_BinarySpec).current = NULL;

  pList_TypedEventRecord_for_BinarySpec->head = NULL;
  pList_TypedEventRecord_for_BinarySpec->tail = NULL;
  pList_TypedEventRecord_for_BinarySpec->free = NULL;
  for(int i=0; i<SIZE_TypedEventRecord_for_BinarySpec; i++)
  {
    Node_TypedEventRecord_for_BinarySpec_in_Node_TypedEventRecord_for_BinarySpec(&((pList_TypedEventRecord_for_BinarySpec->underlying).buffer[i]));
  }
}

Iterator_in_List_TypedEventRecord_for_BinarySpec From__in__Iterator_in_List_TypedEventRecord_for_BinarySpec_static(Node_TypedEventRecord_for_BinarySpec* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_BinarySpec iIterator_in_List_TypedEventRecord_for_BinarySpec;
  Iterator_in_List_TypedEventRecord_for_BinarySpec__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(&iIterator_in_List_TypedEventRecord_for_BinarySpec, start);
  return iIterator_in_List_TypedEventRecord_for_BinarySpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec)
{
  if(pIterator_in_List_TypedEventRecord_for_BinarySpec->current) return true;
  return false;
}

Node_TypedEventRecord_for_BinarySpec* Next__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_BinarySpec->current) return NULL;
  Node_TypedEventRecord_for_BinarySpec* ret = pIterator_in_List_TypedEventRecord_for_BinarySpec->current;
  pIterator_in_List_TypedEventRecord_for_BinarySpec->current = (Node_TypedEventRecord_for_BinarySpec*)pIterator_in_List_TypedEventRecord_for_BinarySpec->current->next;
  return ret;
}

Node_TypedEventRecord_for_BinarySpec* Current__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec)
{
  return pIterator_in_List_TypedEventRecord_for_BinarySpec->current;
}

TypedEventRecord_for_BinarySpec* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec)
{
  return (pIterator_in_List_TypedEventRecord_for_BinarySpec->current) ? &(pIterator_in_List_TypedEventRecord_for_BinarySpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_BinarySpec__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec,
    Node_TypedEventRecord_for_BinarySpec* start)
{
  pIterator_in_List_TypedEventRecord_for_BinarySpec->current = start;
}

Iterator_in_List_TypedEventRecord_for_BinarySpec Iterate_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
{
//        return Iterator::From(pList_for_EventRecord->head);
  return From__in__Iterator_in_List_TypedEventRecord_for_BinarySpec_static(pList_TypedEventRecord_for_BinarySpec->head);
}

void Remove_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec, Node_TypedEventRecord_for_BinarySpec* node)
{
////    if (node == this->head) // change of head
  if (node == pList_TypedEventRecord_for_BinarySpec->head) // change of head
  {
////        this->head = node->next;
    pList_TypedEventRecord_for_BinarySpec->head = (Node_TypedEventRecord_for_BinarySpec*)node->next;
  }

////    if (node == this->tail) // change of tail
  if (node == pList_TypedEventRecord_for_BinarySpec->tail) // change of tail
  {
////        this->tail = this->tail->prev;
    pList_TypedEventRecord_for_BinarySpec->tail = (Node_TypedEventRecord_for_BinarySpec *)pList_TypedEventRecord_for_BinarySpec->tail->prev;
  }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_TypedEventRecord_for_BinarySpec* first, Node_TypedEventRecord_for_BinarySpec* second)
  Link_in_List_TypedEventRecord_for_BinarySpec_static((Node_TypedEventRecord_for_BinarySpec*)node->prev, (Node_TypedEventRecord_for_BinarySpec*)node->next);

  // node becomes the head of the free list
////    node->prev = nullptr;
  node->prev = NULL;
////    this->Link(node, this->free);
  Link_in_List_TypedEventRecord_for_BinarySpec_static(node, pList_TypedEventRecord_for_BinarySpec->free);
////    this->free = node;
  pList_TypedEventRecord_for_BinarySpec->free = node;

////    --(this->m_length);
  --((pList_TypedEventRecord_for_BinarySpec->hHasLength_for_Uint32_t).m_length);
}

void Link_in_List_TypedEventRecord_for_BinarySpec_static(Node_TypedEventRecord_for_BinarySpec* first, Node_TypedEventRecord_for_BinarySpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}

void List_TypedEventRecord_for_BinarySpec_in_List_TypedEventRecord_for_BinarySpecOver2(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec, uint32_t maxSize)
{
  List_TypedEventRecord_for_BinarySpec_in_List_TypedEventRecord_for_BinarySpecOver1(pList_TypedEventRecord_for_BinarySpec);
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
  HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_TypedEventRecord_for_BinarySpec->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_TypedEventRecord_for_BinarySpec_in_Array__for__Node_TypedEventRecord_for_BinarySpecOver2(Array__for__Node_TypedEventRecord_for_BinarySpec *pArray__for__Node_TypedEventRecord_for_BinarySpec, uint32_t size);
  Array__for__Node_TypedEventRecord_for_BinarySpec_in_Array__for__Node_TypedEventRecord_for_BinarySpecOver2(&(pList_TypedEventRecord_for_BinarySpec->underlying), maxSize);
  Initialize_in_List_TypedEventRecord_for_BinarySpec(pList_TypedEventRecord_for_BinarySpec);
}

void Initialize_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
  if(is_empty_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_BinarySpec -> underlying).hHasLength_for_Uint32_t))
    return;

  pList_TypedEventRecord_for_BinarySpec->free = &((pList_TypedEventRecord_for_BinarySpec->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
  for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_TypedEventRecord_for_BinarySpec -> underlying).hHasLength_for_Uint32_t); ++i)
  {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_TypedEventRecord_for_BinarySpec_static(&((pList_TypedEventRecord_for_BinarySpec->underlying).buffer[i - 1]),
        &((pList_TypedEventRecord_for_BinarySpec->underlying).buffer[i]));
  }
}

uint32_t Capacity_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_BinarySpec->underlying).hHasLength_for_Uint32_t));
}

boolean IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
{
  return !(pList_TypedEventRecord_for_BinarySpec->free) && Capacity_in_List_TypedEventRecord_for_BinarySpec(pList_TypedEventRecord_for_BinarySpec) > 0;
}

Node_TypedEventRecord_for_BinarySpec* Head_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
{
  return pList_TypedEventRecord_for_BinarySpec->head;
}

////template<class T> Node<T>* List<T>::Add(const T& value)
Node_TypedEventRecord_for_BinarySpec* Add_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec,
    TypedEventRecord_for_BinarySpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return Insert_in_List_TypedEventRecord_for_BinarySpec(pList_TypedEventRecord_for_BinarySpec,
         value, pList_TypedEventRecord_for_BinarySpec->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_TypedEventRecord_for_BinarySpec* Insert_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec,
    TypedEventRecord_for_BinarySpec* value,
    Node_TypedEventRecord_for_BinarySpec* left,
    Node_TypedEventRecord_for_BinarySpec* right
                                                                                    )
{
  if (!pList_TypedEventRecord_for_BinarySpec->free)
    return NULL;

  // initialize the new node, and increment the size
  Node_TypedEventRecord_for_BinarySpec* new_node = pList_TypedEventRecord_for_BinarySpec->free;
  pList_TypedEventRecord_for_BinarySpec->free = (Node_TypedEventRecord_for_BinarySpec*) pList_TypedEventRecord_for_BinarySpec->free->next;

  new_node->value = *value;
////    ++(this->m_length);
  ++((pList_TypedEventRecord_for_BinarySpec->hHasLength_for_Uint32_t).m_length);

//void Link_in_List_TypedEventRecord_for_BinarySpec_static(Node_TypedEventRecord_for_BinarySpec* first, Node_TypedEventRecord_for_BinarySpec* second);
////    this->Link(left, new_node);
  Link_in_List_TypedEventRecord_for_BinarySpec_static(left, new_node);

////    this->Link(new_node, right);
  Link_in_List_TypedEventRecord_for_BinarySpec_static(new_node, right);

  // change of head
  if (!left)
  {
    pList_TypedEventRecord_for_BinarySpec->head = new_node;
  }

  // change of tail
  if (!right)
  {
    pList_TypedEventRecord_for_BinarySpec->tail = new_node;
  }

  return new_node;
}
