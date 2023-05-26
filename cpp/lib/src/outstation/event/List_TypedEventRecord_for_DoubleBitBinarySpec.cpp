
#include "header.h"
#include "List_TypedEventRecord_for_DoubleBitBinarySpec.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_TypedEventRecord_for_DoubleBitBinarySpec_in_List_TypedEventRecord_for_DoubleBitBinarySpec(List_TypedEventRecord_for_DoubleBitBinarySpec *pList_TypedEventRecord_for_DoubleBitBinarySpec)
{
  (pList_TypedEventRecord_for_DoubleBitBinarySpec->iIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec).current = NULL;

  pList_TypedEventRecord_for_DoubleBitBinarySpec->head = NULL;
  pList_TypedEventRecord_for_DoubleBitBinarySpec->tail = NULL;
  pList_TypedEventRecord_for_DoubleBitBinarySpec->free = NULL;
}

Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec From__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec_static(Node_for_EventRecord* start)
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

Node_for_EventRecord* Next__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec)
{
  if (!pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current;
  pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current = (Node_for_EventRecord*)pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec)
{
  return pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec)
{
  return (pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current) ? &(pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec__in__Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec(Iterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec *pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec,
    Node_for_EventRecord* start)
{
  pIterator_in_List_TypedEventRecord_for_DoubleBitBinarySpec->current = start;
}
