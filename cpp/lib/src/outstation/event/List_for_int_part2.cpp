#include "log_info.h"
#ifdef  LOG_INFO
#include <iostream>
#endif
#include "header.h"
#include "EventStorage.h"

//void clear_in_EventStorage(int* record)
//      Foreach_in_List_for_int(&((pEventStorage->state).events), clear_in_EventStorage);
////template<class T> template<class U> void List<T>::Foreach(const U& action)
void    Foreach_in_List_for_int(List_for_int *pList_for_int, void (*action)(int* record))
//&((pEventStorage->state).events), clear_in_EventStorage);
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"Foreach_in_List_for_int1"<<'\n';
#endif
////    auto iter = this->Iterate();
  Iterator_in_List_for_int iter = Iterate_in_List_for_int(pList_for_int);
////    while (iter.HasNext())
  while (HasNext__in__Iterator_in_List_for_int(&iter))
  {
////        action(iter.Next()->value);
    Node_for_int* current = Next__in__Iterator_in_List_for_int(&iter);
    action(&(current->value));
  }
#ifdef  LOG_INFO
  decrement_stack_info();
#endif
}

uint32_t RemoveAll_in_List_for_int(EventStorage *pEventStorage,
    List_for_int *pList_for_int,
    boolean (*match)(EventStorage *pEventStorage, int* record))
{
#ifdef  LOG_INFO
  std::cout<<'\n';
  increment_stack_info();
  std::cout<<getString_stack_info();
  std::cout<<"RemoveAll_in_List_for_int1"<<'\n';
#endif

  uint32_t count = 0;

////    auto iter = this->Iterate();
////    auto current = iter.Next();
  Iterator_in_List_for_int iter = Iterate_in_List_for_int(pList_for_int);
//        auto node = iter.Next();
  Node_for_int* current = Next__in__Iterator_in_List_for_int(&iter);

  while (current)
  {
////        if (match(current->value))
    if (match(pEventStorage, &(current->value)))
    {
////            auto removed = current;
      Node_for_int* removed = current;
////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_int(&iter);
////            this->Remove(removed);
//   void Remove_in_List_for_int(List_for_int *pList_for_int, Node_for_int* node);
      Remove_in_List_for_int(pList_for_int, removed);
      ++count;
    }
    else
    {
////            current = iter.Next();
      current = Next__in__Iterator_in_List_for_int(&iter);
    }
  }

#ifdef  LOG_INFO
  decrement_stack_info();
#endif
  return count;
}
