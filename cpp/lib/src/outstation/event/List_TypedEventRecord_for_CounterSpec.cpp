
#include "header.h"
#include "List_TypedEventRecord_for_CounterSpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_CounterSpec_in_List_TypedEventRecord_for_CounterSpec(List_TypedEventRecord_for_CounterSpec *pList_TypedEventRecord_for_CounterSpec)
{
  (pList_TypedEventRecord_for_CounterSpec->iIterator_in_List_TypedEventRecord_for_CounterSpec).current = NULL;

  pList_TypedEventRecord_for_CounterSpec->head = NULL;
  pList_TypedEventRecord_for_CounterSpec->tail = NULL;
  pList_TypedEventRecord_for_CounterSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_CounterSpec From__in__Iterator_in_List_TypedEventRecord_for_CounterSpec_static(Node_for_EventRecord* start)
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

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_CounterSpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_CounterSpec->current;
  pIterator_in_List_TypedEventRecord_for_CounterSpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_CounterSpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec)
{
  return pIterator_in_List_TypedEventRecord_for_CounterSpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_CounterSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_CounterSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_CounterSpec__in__Iterator_in_List_TypedEventRecord_for_CounterSpec(Iterator_in_List_TypedEventRecord_for_CounterSpec *pIterator_in_List_TypedEventRecord_for_CounterSpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_CounterSpec->current = start;
}
