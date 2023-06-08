#include <QtWidgets>

#include "header.h"
#include "List_for_EventRecord.h"
#include <string.h>

void __List_for_EventRecord_in_List_for_EventRecordOver2(List_for_EventRecord *pList_for_EventRecord, uint32_t maxSize);
void __HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
void __Array__for__Node_for_EventRecord_in_Array__for__Node_for_EventRecordOver2(Array__for__Node_for_EventRecord *pArray__for__Node_for_EventRecord, uint32_t size);
void __Initialize_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord);
boolean __is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
void __Link_in_List_for_EventRecord_static(Node_for_EventRecord* first, Node_for_EventRecord* second);

void __List_for_EventRecord_in_List_for_EventRecordOver2(List_for_EventRecord *pList_for_EventRecord, uint32_t maxSize)
    {
//    List(list_size_type_t maxSize) : ser4cpp::HasLength<list_size_type_t>(0), underlying(maxSize)
//    void HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(HasLength_for_Uint32_t *pHasLength, uint32_t length);
        __HasLength_for_Uint32_t_in_HasLength_for_Uint32_tOver2(&(pList_for_EventRecord->hHasLength_for_Uint32_t), 0);
//void Array__for__Node_for_EventRecord_in_Array__for__Node_for_EventRecordOver2(Array__for__Node_for_EventRecord *pArray__for__Node_for_EventRecord, uint32_t size);
qDebug()<<"maxSize= "<<maxSize;
        __Array__for__Node_for_EventRecord_in_Array__for__Node_for_EventRecordOver2(&(pList_for_EventRecord->underlying), maxSize);
        __Initialize_in_List_for_EventRecord(pList_for_EventRecord);
    }

void __Initialize_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord)
{
////    if (underlying.is_empty())
//    boolean is_empty_in_HasLength_for_Uint32_t(HasLength_for_Uint32_t *pHasLength);
    if(__is_empty_in_HasLength_for_Uint32_t(&(pList_for_EventRecord -> underlying).hHasLength_for_Uint32_t))
        return;

    pList_for_EventRecord->free = &((pList_for_EventRecord->underlying).buffer[0]);////&underlying[0];
////    for (list_size_type_t i = 1; i < underlying.length(); ++i)

qDebug()<<"length_in_HasLength_for_Uint32_t="<<length_in_HasLength_for_Uint32_t(&(pList_for_EventRecord -> underlying).hHasLength_for_Uint32_t);

    for (uint32_t i = 1; i < length_in_HasLength_for_Uint32_t(&(pList_for_EventRecord -> underlying).hHasLength_for_Uint32_t); ++i)
    {
////        Link(&underlying[i - 1], &underlying[i]);
    __Link_in_List_for_EventRecord_static(&((pList_for_EventRecord->underlying).buffer[i - 1]),
                                        &((pList_for_EventRecord->underlying).buffer[i]));
    }
}

void __Link_in_List_for_EventRecord_static(Node_for_EventRecord* first, Node_for_EventRecord* second)
{
    if (first)
        first->next = (void *)second;
    if (second)
        second->prev = (void *)first;
}
