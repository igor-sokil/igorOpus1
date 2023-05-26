
#include "header.h"
#include "List_TypedEventRecord_for_AnalogSpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_AnalogSpec_in_List_TypedEventRecord_for_AnalogSpec(List_TypedEventRecord_for_AnalogSpec *pList_TypedEventRecord_for_AnalogSpec)
{
  (pList_TypedEventRecord_for_AnalogSpec->iIterator_in_List_TypedEventRecord_for_AnalogSpec).current = NULL;

  pList_TypedEventRecord_for_AnalogSpec->head = NULL;
  pList_TypedEventRecord_for_AnalogSpec->tail = NULL;
  pList_TypedEventRecord_for_AnalogSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_AnalogSpec From__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec_static(Node_for_EventRecord* start)
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

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_AnalogSpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_AnalogSpec->current;
  pIterator_in_List_TypedEventRecord_for_AnalogSpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_AnalogSpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec)
{
  return pIterator_in_List_TypedEventRecord_for_AnalogSpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_AnalogSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_AnalogSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_AnalogSpec__in__Iterator_in_List_TypedEventRecord_for_AnalogSpec(Iterator_in_List_TypedEventRecord_for_AnalogSpec *pIterator_in_List_TypedEventRecord_for_AnalogSpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_AnalogSpec->current = start;
}
