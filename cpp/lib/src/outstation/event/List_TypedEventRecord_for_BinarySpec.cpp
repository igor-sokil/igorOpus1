
#include "header.h"
#include "List_TypedEventRecord_for_BinarySpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_BinarySpec_in_List_TypedEventRecord_for_BinarySpec(List_TypedEventRecord_for_BinarySpec *pList_TypedEventRecord_for_BinarySpec)
{
  (pList_TypedEventRecord_for_BinarySpec->iIterator_in_List_TypedEventRecord_for_BinarySpec).current = NULL;

  pList_TypedEventRecord_for_BinarySpec->head = NULL;
  pList_TypedEventRecord_for_BinarySpec->tail = NULL;
  pList_TypedEventRecord_for_BinarySpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_BinarySpec From__in__Iterator_in_List_TypedEventRecord_for_BinarySpec_static(Node_for_EventRecord* start)
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

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_BinarySpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_BinarySpec->current;
  pIterator_in_List_TypedEventRecord_for_BinarySpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_BinarySpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec)
{
  return pIterator_in_List_TypedEventRecord_for_BinarySpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec)
{
  return (pIterator_in_List_TypedEventRecord_for_BinarySpec->current) ? &(pIterator_in_List_TypedEventRecord_for_BinarySpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_BinarySpec__in__Iterator_in_List_TypedEventRecord_for_BinarySpec(Iterator_in_List_TypedEventRecord_for_BinarySpec *pIterator_in_List_TypedEventRecord_for_BinarySpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_BinarySpec->current = start;
}
