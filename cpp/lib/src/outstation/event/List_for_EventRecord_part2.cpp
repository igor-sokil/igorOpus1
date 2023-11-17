#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventStorage.h"

//void clear_in_EventStorage(EventRecord* record)
//      Foreach_in_List_for_EventRecord(&((pEventStorage->state).events), clear_in_EventStorage);
////template<class T> template<class U> void List<T>::Foreach(const U& action)
void    Foreach_in_List_for_EventRecord(List_for_EventRecord *pList_for_EventRecord, void (*action)(EventRecord* record))
//&((pEventStorage->state).events), clear_in_EventStorage);
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Foreach_in_List_for_EventRecord1"<<'\n';
#endif
////    auto iter = this->Iterate();
  Iterator_in_List_for_EventRecord iter = Iterate_in_List_for_EventRecord(pList_for_EventRecord);
////    while (iter.HasNext())
  while (HasNext__in__Iterator_in_List_for_EventRecord(&iter))
  {
////        action(iter.Next()->value);
    Node_for_EventRecord* current = Next__in__Iterator_in_List_for_EventRecord(&iter);
    action(&(current->value));
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

uint32_t RemoveAll_in_List_for_EventRecord(EventStorage *pEventStorage,
    List_for_EventRecord *pList_for_EventRecord,
    boolean (*match)(EventStorage *pEventStorage, EventRecord* record))
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RemoveAll_in_List_for_EventRecord1"<<'\n';
#endif

  uint32_t count = 0;

////    auto iter = this->Iterate();
////    auto current = iter.Next();
  Iterator_in_List_for_EventRecord iter = Iterate_in_List_for_EventRecord(pList_for_EventRecord);
//        auto node = iter.Next();
  Node_for_EventRecord* current = Next__in__Iterator_in_List_for_EventRecord(&iter);

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

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return count;
}
