
#include "header.h"
#include "List_TypedEventRecord_for_FrozenCounterSpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_FrozenCounterSpec_in_List_TypedEventRecord_for_FrozenCounterSpec(List_TypedEventRecord_for_FrozenCounterSpec *pList_TypedEventRecord_for_FrozenCounterSpec)
{
  (pList_TypedEventRecord_for_FrozenCounterSpec->iIterator_in_List_TypedEventRecord_for_FrozenCounterSpec).current = NULL;

  pList_TypedEventRecord_for_FrozenCounterSpec->head = NULL;
  pList_TypedEventRecord_for_FrozenCounterSpec->tail = NULL;
  pList_TypedEventRecord_for_FrozenCounterSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec From__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec_static(Node_for_EventRecord* start)
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

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current;
  pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec)
{
  return pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec__in__Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec(Iterator_in_List_TypedEventRecord_for_FrozenCounterSpec *pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_FrozenCounterSpec->current = start;
}
