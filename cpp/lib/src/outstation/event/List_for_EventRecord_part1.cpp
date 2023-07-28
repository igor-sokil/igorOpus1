//#include <QtWidgets>
#include "header.h"
#include "List_for_EventRecord.h"
#include <string.h>

void List_for_EventRecord_in_List_for_EventRecordOver1(List_for_EventRecord *pList_for_EventRecord)
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

void List_for_EventRecord_in_List_for_EventRecordOver2(List_for_EventRecord *pList_for_EventRecord, uint32_t maxSize)
    {
//qDebug()<<"List_for_EventRecord_in_List_for_EventRecordOver2 1"<<"  maxSize="<<maxSize;
       List_for_EventRecord_in_List_for_EventRecordOver1(pList_for_EventRecord);
// ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
        HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_for_EventRecord->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_for_EventRecord_in_Array__for__Node_for_EventRecordOver2(Array__for__Node_for_EventRecord *pArray__for__Node_for_EventRecord, uint32_t size);
        Array__for__Node_for_EventRecord_in_Array__for__Node_for_EventRecordOver2(&(pList_for_EventRecord->underlying), maxSize);
        Initialize_in_List_for_EventRecord(pList_for_EventRecord);
    }

void Initialize_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
    if(is_empty_in_HasLength_for_Uint32_t(&(pList_for_EventRecord -> underlying).hHasLength_for_Uint32_t))
        return;

    pList_for_EventRecord->free = &((pList_for_EventRecord->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)
    for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_for_EventRecord -> underlying).hHasLength_for_Uint32_t); ++i)
    {
////        Link(&underlying[i - 1], &underlying[i]);
    Link_in_List_for_EventRecord_static(&((pList_for_EventRecord->underlying).buffer[i - 1]),
                                        &((pList_for_EventRecord->underlying).buffer[i]));
    }
}

     uint32_t Capacity_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord) 
    {
//        return underlying.length();
     return length_in_HasLength_for_Uint32_t(&((pList_for_EventRecord->underlying).hHasLength_for_Uint32_t));
    }

boolean IsFullAndCapacityNotZero_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord)
{
    return !(pList_for_EventRecord->free) && Capacity_in_List_for_EventRecord(pList_for_EventRecord) > 0;
}

Node_for_EventRecord* Head_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord)
    {
        return pList_for_EventRecord->head;
    }

Node_for_EventRecord* Add_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, EventRecord* value)
{
////    return this->Insert(value, this->tail, nullptr);
    return  Insert_in_List_for_EventRecord(pList_for_EventRecord, value, pList_for_EventRecord->tail, NULL);
}

////template<class T> Node<T>* List<T>::Insert(const T& value, Node<T>* left, Node<T>* right)
Node_for_EventRecord*  Insert_in_List_for_EventRecord(List_for_EventRecord* pList_for_EventRecord, 
                                                      EventRecord* value, Node_for_EventRecord* left, 
                                                                          Node_for_EventRecord* right)
{
    if (!pList_for_EventRecord->free)
        return NULL;

    // initialize the new node, and increment the size
    Node_for_EventRecord* new_node = pList_for_EventRecord->free;
    pList_for_EventRecord->free = (Node_for_EventRecord*)pList_for_EventRecord->free->next;

    new_node->value = *value;
////    ++(this->m_length);
    ++((pList_for_EventRecord->hHasLength_for_Uint32_t).m_length);

//   void Link_in_List_for_EventRecord_static(Node_for_EventRecord* first, Node_for_EventRecord* second);
////    this->Link(left, new_node);
     Link_in_List_for_EventRecord_static(left, new_node);

////    this->Link(new_node, right);
     Link_in_List_for_EventRecord_static(new_node, right);

    // change of head
    if (!left)
    {
        pList_for_EventRecord->head = new_node;
    }

    // change of tail
    if (!right)
    {
        pList_for_EventRecord->tail = new_node;
    }

    return new_node;
}

EventRecord *Find__in__Iterator_in_List_for_EventRecord(Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord,
                                                        boolean (*matches)(EventRecord* pEventRecord))
{
////    while (this->current)
    while (pIterator_in_List_for_EventRecord->current)
    {
        if (matches(&(pIterator_in_List_for_EventRecord->current->value)))
        {
            return &(pIterator_in_List_for_EventRecord->current->value);
       }

        pIterator_in_List_for_EventRecord->current = (Node_for_EventRecord*)pIterator_in_List_for_EventRecord->current->next;
    }

    return NULL;
}
