#include "header.h"
#include "List_TypedEventRecord_for_AnalogSpec.h"
#include <string.h>
Node_TypedEventRecord_for_AnalogSpec* __Add_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    TypedEventRecord_for_AnalogSpec* value);

Node_TypedEventRecord_for_AnalogSpec* __Insert_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    TypedEventRecord_for_AnalogSpec* value,
    Node_TypedEventRecord_for_AnalogSpec* left,
    Node_TypedEventRecord_for_AnalogSpec* right );

void __Link_in_List_TypedEventRecord_for_AnalogSpec_static(Node_TypedEventRecord_for_AnalogSpec* first, Node_TypedEventRecord_for_AnalogSpec* second);
uint32_t __Capacity_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec);

boolean __IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec);
//boolean __IsAnyTypeFull_in_EventLists(EventLists *pEventLists);

boolean __IsFullAndCapacityNotZero_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
  return !(pList_TypedEventRecord_for_AnalogSpec->free) && __Capacity_in_List_TypedEventRecord_for_AnalogSpec(pList_TypedEventRecord_for_AnalogSpec) > 0;
}

uint32_t __Capacity_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
//        return underlying.length();
  return length_in_HasLength_for_Uint32_t(&((pList_TypedEventRecord_for_AnalogSpec->underlying).hHasLength_for_Uint32_t));
}

Node_TypedEventRecord_for_AnalogSpec* __Add_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    TypedEventRecord_for_AnalogSpec* value)
{
////    return this->Insert(value, this->tail, nullptr);
  return __Insert_in_List_TypedEventRecord_for_AnalogSpec(pList_TypedEventRecord_for_AnalogSpec,
         value, pList_TypedEventRecord_for_AnalogSpec->tail, NULL);
}

Node_TypedEventRecord_for_AnalogSpec* __Insert_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec,
    TypedEventRecord_for_AnalogSpec* value,
    Node_TypedEventRecord_for_AnalogSpec* left,
    Node_TypedEventRecord_for_AnalogSpec* right )
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
/*
void __Link_in_List_TypedEventRecord_for_AnalogSpec_static(Node_TypedEventRecord_for_AnalogSpec* first, Node_TypedEventRecord_for_AnalogSpec* second)
{
  if (first)
    first->next = (void *)second;
  if (second)
    second->prev = (void *)first;
}
*/
