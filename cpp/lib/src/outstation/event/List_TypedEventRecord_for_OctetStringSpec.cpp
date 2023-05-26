
#include "header.h"
#include "List_TypedEventRecord_for_OctetStringSpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_OctetStringSpec_in_List_TypedEventRecord_for_OctetStringSpec(List_TypedEventRecord_for_OctetStringSpec *pList_TypedEventRecord_for_OctetStringSpec)
{
  (pList_TypedEventRecord_for_OctetStringSpec->iIterator_in_List_TypedEventRecord_for_OctetStringSpec).current = NULL;

  pList_TypedEventRecord_for_OctetStringSpec->head = NULL;
  pList_TypedEventRecord_for_OctetStringSpec->tail = NULL;
  pList_TypedEventRecord_for_OctetStringSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_OctetStringSpec From__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec_static(Node_for_EventRecord* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_OctetStringSpec iIterator_in_List_TypedEventRecord_for_OctetStringSpec;
  Iterator_in_List_TypedEventRecord_for_OctetStringSpec__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(&iIterator_in_List_TypedEventRecord_for_OctetStringSpec, start);
  return iIterator_in_List_TypedEventRecord_for_OctetStringSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current) return true;
  return false;
}

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current;
  pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  return pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_OctetStringSpec__in__Iterator_in_List_TypedEventRecord_for_OctetStringSpec(Iterator_in_List_TypedEventRecord_for_OctetStringSpec *pIterator_in_List_TypedEventRecord_for_OctetStringSpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_OctetStringSpec->current = start;
}
