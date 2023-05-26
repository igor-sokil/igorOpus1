
#include "header.h"
#include "List_for_EventRecord.h"
#include <string.h>

void Node_for_EventRecord_in_Node_for_EventRecord(Node_for_EventRecord *pNode_for_EventRecord)
{
  EventRecord_in_EventRecordOver1(&(pNode_for_EventRecord->value));
  pNode_for_EventRecord->prev = NULL;
  pNode_for_EventRecord->next = NULL;
}

void List_for_EventRecord_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord)
{
  (pList_for_EventRecord->iIterator_in_List_for_EventRecord).current = NULL;

  pList_for_EventRecord->head = NULL;
  pList_for_EventRecord->tail = NULL;
  pList_for_EventRecord->free = NULL;
}

Iterator_in_List_for_EventRecord From__in__Iterator_in_List_for_EventRecord_static(Node_for_EventRecord* start)
{
////            return Iterator(start);
  Iterator_in_List_for_EventRecord iIterator_in_List_for_EventRecord;
  Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord(&iIterator_in_List_for_EventRecord, start);
  return iIterator_in_List_for_EventRecord;
}

////        template<class U> T* Find(const U& matches);

boolean HasNext__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord)
{
  if(pIterator_in_List_for_EventRecord->current) return true;
  return false;
}

Node_for_EventRecord* Next__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord)
{
  if (!pIterator_in_List_for_EventRecord->current) return NULL;
  Node_for_EventRecord* ret = pIterator_in_List_for_EventRecord->current;
  pIterator_in_List_for_EventRecord->current = (Node_for_EventRecord*)pIterator_in_List_for_EventRecord->current->next;
  return ret;
}

Node_for_EventRecord* Current__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord)
{
  return pIterator_in_List_for_EventRecord->current;
}

EventRecord* CurrentValue__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord)
{
  return (pIterator_in_List_for_EventRecord->current) ? &(pIterator_in_List_for_EventRecord->current->value) : NULL;
}

////        Iterator(Node<T>* start) : current(start) {}
void   Iterator_in_List_for_EventRecord__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord,
    Node_for_EventRecord* start)
{
  pIterator_in_List_for_EventRecord->current = start;
}

    Iterator_in_List_for_EventRecord Iterate_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord) 
    {
//        return Iterator::From(pList_for_EventRecord->head);
        return From__in__Iterator_in_List_for_EventRecord_static(pList_for_EventRecord->head);
    }

   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node)
{
////    if (node == this->head) // change of head
    if (node == pList_for_EventRecord->head) // change of head
    {
////        this->head = node->next;
        pList_for_EventRecord->head = (Node_for_EventRecord*)node->next;
    }

////    if (node == this->tail) // change of tail
    if (node == pList_for_EventRecord->tail) // change of tail
    {
////        this->tail = this->tail->prev;
        pList_for_EventRecord->tail = (Node_for_EventRecord *)pList_for_EventRecord->tail->prev;
    }

// attach the adjacent nodes to eachother if they exist
////    this->Link(node->prev, node->next);
//   void Link_in_List_for_EventRecord_static(Node_for_EventRecord* first, Node_for_EventRecord* second)
        Link_in_List_for_EventRecord_static((Node_for_EventRecord*)node->prev, (Node_for_EventRecord*)node->next);

    // node becomes the head of the free list
////    node->prev = nullptr;
        node->prev = NULL;
////    this->Link(node, this->free);
        Link_in_List_for_EventRecord_static(node, pList_for_EventRecord->free);
////    this->free = node;
        pList_for_EventRecord->free = node;

////    --(this->m_length);
        --((pList_for_EventRecord->hHasLength_for_Uint32_t).m_length);
}

   void Link_in_List_for_EventRecord_static(Node_for_EventRecord* first, Node_for_EventRecord* second)
{
    if (first)
        first->next = (void *)second;
    if (second)
        second->prev = (void *)first;
}

