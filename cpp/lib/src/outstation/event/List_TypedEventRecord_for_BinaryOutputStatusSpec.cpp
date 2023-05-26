
#include "header.h"
#include "List_TypedEventRecord_for_BinaryOutputStatusSpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_BinaryOutputStatusSpec_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(List_TypedEventRecord_for_BinaryOutputStatusSpec *pList_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  (pList_TypedEventRecord_for_BinaryOutputStatusSpec->iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec).current = NULL;

  pList_TypedEventRecord_for_BinaryOutputStatusSpec->head = NULL;
  pList_TypedEventRecord_for_BinaryOutputStatusSpec->tail = NULL;
  pList_TypedEventRecord_for_BinaryOutputStatusSpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec From__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec_static(Node_for_EventRecord* start)
{
////            return Iterator(start);
  Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec;
  Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(&iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec, start);
  return iIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  if(pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current) return true;
  return false;
}

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current;
  pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  return pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec)
{
  return (pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current) ? &(pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec__in__Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec(Iterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec *pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_BinaryOutputStatusSpec->current = start;
}
