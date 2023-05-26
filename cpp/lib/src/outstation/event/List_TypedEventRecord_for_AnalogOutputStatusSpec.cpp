
#include "header.h"
#include "List_TypedEventRecord_for_AnalogOutputStatusSpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_AnalogOutputStatusSpec_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(List_TypedEventRecord_for_AnalogOutputStatusSpec *pList_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  (pList_TypedEventRecord_for_AnalogOutputStatusSpec->iIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec).current = NULL;

  pList_TypedEventRecord_for_AnalogOutputStatusSpec->head = NULL;
  pList_TypedEventRecord_for_AnalogOutputStatusSpec->tail = NULL;
  pList_TypedEventRecord_for_AnalogOutputStatusSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec From__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec_static(Node_for_EventRecord* start)
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

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current;
  pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  return pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_AnalogOutputStatusSpec->current = start;
}
