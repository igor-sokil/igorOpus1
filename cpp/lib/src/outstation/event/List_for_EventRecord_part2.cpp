#include "header.h"
#include "EventStorage.h"

  uint32_t RemoveAll_in_List_for_EventRecord(EventStorage *pEventStorage, List_for_EventRecord *pList_for_EventRecord, boolean (*match)(EventStorage *pEventStorage, EventRecord* record))//const U& match);
{
    uint32_t count = 0;

////    auto iter = this->Iterate();
////    auto current = iter.Next();
  Iterator_in_List_for_EventRecord iter = Iterate_in_List_for_EventRecord(pList_for_EventRecord);//List_for_EventRecord *pList_for_EventRecord)
//        auto node = iter.Next();
    Node_for_EventRecord* current = Next__in__Iterator_in_List_for_EventRecord(&iter);//Iterator_in_List_for_EventRecord *pIterator_in_List_for_EventRecord);

    while (current)
    {
////        if (match(current->value))
        if (match(pEventStorage, &(current->value)))
        {
////            auto removed = current;
            Node_for_EventRecord* removed = current;
////            current = iter.Next();
            current = Next__in__Iterator_in_List_for_EventRecord(&iter);
////            this->Remove(removed);
//   void Remove_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, Node_for_EventRecord* node);
            Remove_in_List_for_EventRecord(pList_for_EventRecord, removed);
            ++count;
       }
       else
       {
////            current = iter.Next();
            current = Next__in__Iterator_in_List_for_EventRecord(&iter);
       }
    }

   return count;
}
