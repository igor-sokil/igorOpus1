#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "List_for_UserRecord.h"

//void clear_in_EventStorage(UserRecord* record)
//      Foreach_in_List_for_UserRecord(&((pEventStorage->state).events), clear_in_EventStorage);
////template<class T> template<class U> void List<T>::Foreach(const U& action)
void    Foreach_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord, void (*action)(UserRecord* record))
//&((pEventStorage->state).events), clear_in_EventStorage);
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Foreach_in_List_for_UserRecord1"<<'\n';
#endif
////    auto iter = this->Iterate();
  Iterator_in_List_for_UserRecord iter = Iterate_in_List_for_UserRecord(pList_for_UserRecord);
////    while (iter.HasNext())
  while (HasNext__in__Iterator_in_List_for_UserRecord(&iter))
  {
////        action(iter.Next()->value);
    Node_for_UserRecord* current = Next__in__Iterator_in_List_for_UserRecord(&iter);
    action(&(current->value));
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

/*
uint32_t RemoveAll_in_List_for_UserRecord(EventStorage *pEventStorage,
    List_for_UserRecord *pList_for_UserRecord,
    boolean (*match)(EventStorage *pEventStorage, UserRecord* record))
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RemoveAll_in_List_for_UserRecord1"<<'\n';
#endif

  uint32_t count = 0;

////    auto iter = this->Iterate();
////    auto current = iter.Next();
  Iterator_in_List_for_UserRecord iter = Iterate_in_List_for_UserRecord(pList_for_UserRecord);
//        auto node = iter.Next();
  Node_for_UserRecord* current = Next__in__Iterator_in_List_for_UserRecord(&iter);

  while (current)
  {
////        if (match(current->value))
    if (match(pEventStorage, &(current->value)))
    {
////            auto removed = current;
      Node_for_UserRecord* removed = current;
////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_UserRecord(&iter);
////            this->Remove(removed);
//   void Remove_in_List_for_UserRecord(List_for_UserRecord *pList_for_UserRecord, Node_for_UserRecord* node);
      Remove_in_List_for_UserRecord(pList_for_UserRecord, removed);
      ++count;
    }
    else
    {
////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_UserRecord(&iter);
    }
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return count;
}
*/
